// CameraController.cpp
// Camera + third-person player movement, isolated from Main.cpp.

#include "CameraController.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../app/InputActionMap.hpp"
#include "../logger/Logger.hpp"
#include "physics/CollisionWorld.hpp"

#include <cmath>
#include <algorithm>
#include <DirectXMath.h>

using namespace DirectX;

void CameraController::BeginDodge(float dirX, float dirZ)
{
    constexpr float kDodgeDuration = 0.35f;
    constexpr float kDodgeDistance = 4.0f;
    constexpr float kMinDirLenSq = 1e-6f;

    float useDirX = dirX;
    float useDirZ = dirZ;
    const float dirLenSq = (useDirX * useDirX) + (useDirZ * useDirZ);
    if (dirLenSq <= kMinDirLenSq)
    {
        useDirX = sinf(m_yaw);
        useDirZ = cosf(m_yaw);
    }
    else
    {
        const float invLen = 1.0f / sqrtf(dirLenSq);
        useDirX *= invLen;
        useDirZ *= invLen;
    }

    const float dodgeSpeed = kDodgeDistance / kDodgeDuration;
    m_dodgeVelX = useDirX * dodgeSpeed;
    m_dodgeVelZ = useDirZ * dodgeSpeed;
    m_dodgeTimer = kDodgeDuration;
    m_dodgeActive = true;
    LOG_INFO("CameraController: Dodge burst started.");
}

// ---------------------------------------------------------------------------
// Init
// ---------------------------------------------------------------------------
void CameraController::Init(float startX, float startY, float startZ,
                             float startYaw, float startPitch)
{
    m_playerX    = startX;
    m_playerY    = startY;
    m_playerZ    = startZ;
    m_yaw        = startYaw;
    m_pitch      = startPitch;
    m_velocityY  = 0.0f;
    m_isGrounded = true;
    ComputeCamFromPlayer();
}

// ---------------------------------------------------------------------------
// SetCenterPoint
// ---------------------------------------------------------------------------
void CameraController::SetCenterPoint(POINT center)
{
    m_centerPoint = center;
}

// ---------------------------------------------------------------------------
// ComputeCamFromPlayer  (private helper)
// ---------------------------------------------------------------------------
void CameraController::ComputeCamFromPlayer()
{
    float camOffsetX = -sinf(m_yaw) * cameraDistance;
    float camOffsetZ = -cosf(m_yaw) * cameraDistance;
    m_camX = m_playerX + camOffsetX;
    m_camZ = m_playerZ + camOffsetZ;
    m_camY = m_playerY + cameraHeight;
}

// ---------------------------------------------------------------------------
// Update
// ---------------------------------------------------------------------------
void CameraController::Update(float dt, bool allowMovement, bool allowMouseLook,
                               bool& inOutFirstFrame, D3D11Renderer& renderer)
{
    // --- Mouse look ---
    POINT mouse;
    GetCursorPos(&mouse);

    if (allowMouseLook && !inOutFirstFrame)
    {
        int dx = mouse.x - m_centerPoint.x;
        int dy = mouse.y - m_centerPoint.y;
        m_yaw   += static_cast<float>(dx) * mouseSensitivity;
        m_pitch -= static_cast<float>(dy) * mouseSensitivity;
        if (m_pitch >  maxPitch) m_pitch =  maxPitch;
        if (m_pitch < -maxPitch) m_pitch = -maxPitch;
    }
    // Re-centre the cursor only when mouse-look is active so the next frame's
    // delta is always relative to centre. When placement mode is on we leave
    // the cursor wherever ImGui puts it (free cursor for clicking).
    if (allowMouseLook)
        SetCursorPos(m_centerPoint.x, m_centerPoint.y);

    inOutFirstFrame = false;

    // Sync rotation to renderer so all draw calls use the latest values.
    renderer.SetCameraRotation(m_yaw, m_pitch);

    // --- Movement + gravity (skip only when movement is explicitly blocked) ---
    if (allowMovement)
    {
        const auto isHeld = [this](InputAction action, int fallbackKeyCode) -> bool
        {
            if (m_inputActionMap)
                return m_inputActionMap->IsHeld(action);
            return (GetAsyncKeyState(fallbackKeyCode) & 0x8000) != 0;
        };

        float forwardX =  sinf(m_yaw);
        float forwardZ =  cosf(m_yaw);
        float rightX   =  cosf(m_yaw);
        float rightZ   = -sinf(m_yaw);

        if (m_dodgeActive)
        {
            // TODO Track 12.6: apply invincibility window (~0.2s) during dodge burst
            const float dodgeStepDt = std::min(dt, std::max(0.0f, m_dodgeTimer));
            m_playerX += m_dodgeVelX * dodgeStepDt;
            m_playerZ += m_dodgeVelZ * dodgeStepDt;
            m_dodgeTimer -= dodgeStepDt;
            if (m_dodgeTimer <= 0.0f)
            {
                m_dodgeActive = false;
                m_dodgeVelX = 0.0f;
                m_dodgeVelZ = 0.0f;
                LOG_INFO("CameraController: Dodge burst ended.");
            }
        }
        else
        {
            float step = moveSpeed * dt;
            if (isHeld(InputAction::MoveForward, 'W')) { m_playerX += forwardX * step; m_playerZ += forwardZ * step; }
            if (isHeld(InputAction::MoveBack, 'S'))    { m_playerX -= forwardX * step; m_playerZ -= forwardZ * step; }
            if (isHeld(InputAction::MoveLeft, 'A'))    { m_playerX -= rightX * step;   m_playerZ -= rightZ * step;   }
            if (isHeld(InputAction::MoveRight, 'D'))   { m_playerX += rightX * step;   m_playerZ += rightZ * step;   }
        }

        // Gravity + jumping
        if (!m_isGrounded)
        {
            m_velocityY += gravity * dt;
        }
        else if (isHeld(InputAction::Jump, VK_SPACE))
        {
            m_velocityY  = jumpVelocity;
            m_isGrounded = false;
        }
        if (m_velocityY < terminalVelocity) m_velocityY = terminalVelocity;

        m_playerY += m_velocityY * dt;

        if (m_collisionWorld)
        {
            m_collisionWorld->ResolveMovement(
                m_playerX, m_playerY, m_playerZ,
                PLAYER_COLLISION_HALF_WIDTH_X,
                PLAYER_COLLISION_HALF_HEIGHT,
                PLAYER_COLLISION_HALF_WIDTH_Z);
        }

        // Ground snap / terrain collision
        float groundY = eyeOffset;
        if (renderer.IsTerrainAvailable())
            groundY = renderer.SampleTerrainHeight(m_playerX, m_playerZ) + eyeOffset;

        if (m_playerY <= groundY)
        {
            m_playerY    = groundY;
            m_velocityY  = 0.0f;
            m_isGrounded = true;
        }
        else if (m_isGrounded)
        {
            // Keep snapped while walking on slopes.
            m_playerY   = groundY;
            m_velocityY = 0.0f;
        }

        ComputeCamFromPlayer();
    }

    // Apply camera position to renderer so all draw calls use the correct view.
    renderer.SetCameraPosition(m_camX, m_camY, m_camZ);
}

// ---------------------------------------------------------------------------
// ScreenPointToRay
// ---------------------------------------------------------------------------
void CameraController::ScreenPointToRay(float mouseX, float mouseY,
                                         float vpW, float vpH,
                                         float& outOriginX, float& outOriginY, float& outOriginZ,
                                         float& outDirX,    float& outDirY,    float& outDirZ) const
{
    // Build the same view + projection used by the renderer draw calls.
    float lookDirX = cosf(m_pitch) * sinf(m_yaw);
    float lookDirY = sinf(m_pitch);
    float lookDirZ = cosf(m_pitch) * cosf(m_yaw);

    XMVECTOR camPos    = XMVectorSet(m_camX, m_camY, m_camZ, 1.0f);
    XMVECTOR camTarget = XMVectorSet(m_camX + lookDirX,
                                      m_camY + lookDirY,
                                      m_camZ + lookDirZ, 1.0f);
    XMVECTOR camUp     = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtLH(camPos, camTarget, camUp);
    XMMATRIX proj = XMMatrixPerspectiveFovLH(
        XM_PIDIV4,          // 45-degree vertical FOV (matches DrawTerrainPatch)
        vpW / vpH,
        0.1f, 2000.0f);

    // Unproject near and far screen points into world space.
    // XMVector3Unproject arguments: screenPoint, vpX, vpY, vpW, vpH, minZ, maxZ, proj, view, world
    XMVECTOR nearPt = XMVector3Unproject(
        XMVectorSet(mouseX, mouseY, 0.0f, 0.0f),
        0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
        proj, view, XMMatrixIdentity());

    XMVECTOR farPt = XMVector3Unproject(
        XMVectorSet(mouseX, mouseY, 1.0f, 0.0f),
        0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
        proj, view, XMMatrixIdentity());

    XMVECTOR dir = XMVector3Normalize(farPt - nearPt);

    outOriginX = XMVectorGetX(nearPt);
    outOriginY = XMVectorGetY(nearPt);
    outOriginZ = XMVectorGetZ(nearPt);
    outDirX    = XMVectorGetX(dir);
    outDirY    = XMVectorGetY(dir);
    outDirZ    = XMVectorGetZ(dir);
}

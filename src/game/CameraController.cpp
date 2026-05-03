// CameraController.cpp
// Camera + third-person player movement, isolated from Main.cpp.

#include "CameraController.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"

#include <cmath>
#include <algorithm>
#include <DirectXMath.h>

using namespace DirectX;

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
        float forwardX =  sinf(m_yaw);
        float forwardZ =  cosf(m_yaw);
        float rightX   =  cosf(m_yaw);
        float rightZ   = -sinf(m_yaw);

        float step = moveSpeed * dt;

        if (GetAsyncKeyState('W') & 0x8000) { m_playerX += forwardX * step; m_playerZ += forwardZ * step; }
        if (GetAsyncKeyState('S') & 0x8000) { m_playerX -= forwardX * step; m_playerZ -= forwardZ * step; }
        if (GetAsyncKeyState('A') & 0x8000) { m_playerX -= rightX * step;   m_playerZ -= rightZ * step;   }
        if (GetAsyncKeyState('D') & 0x8000) { m_playerX += rightX * step;   m_playerZ += rightZ * step;   }

        // Gravity + jumping
        if (!m_isGrounded)
        {
            m_velocityY += gravity * dt;
        }
        else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            m_velocityY  = jumpVelocity;
            m_isGrounded = false;
        }
        if (m_velocityY < terminalVelocity) m_velocityY = terminalVelocity;

        m_playerY += m_velocityY * dt;

        // Ground snap / terrain collision
        float groundY = 0.0f;
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

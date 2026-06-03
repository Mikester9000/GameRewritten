// ============================================================
// FILE: src/game/CameraController.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: CameraController module behavior and local implementation details.
// ============================================================

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

namespace
{
constexpr float kLockOnYawBiasSpeed = 8.0f;
constexpr float kCombatCameraBlendSpeed = 6.5f;
constexpr float kCombatCameraPitchBlendSpeed = 4.5f;
constexpr float kCombatMinDistance = 2.6f;
constexpr float kCombatMaxDistance = 3.6f;
constexpr float kCameraCollisionClearance = 0.35f;
constexpr float kCameraShakeFrequencyHz = 18.0f;

float WrapAngle(float angle)
{
    constexpr float kPi = DirectX::XM_PI;
    constexpr float kTwoPi = DirectX::XM_2PI;

    while (angle > kPi)  angle -= kTwoPi;
    while (angle < -kPi) angle += kTwoPi;
    return angle;
}
}

void CameraController::SetCombatCameraFocus(bool enabled, float targetX, float targetY, float targetZ)
{
    m_hasCombatFocus = enabled;
    if (!enabled)
        return;

    m_focusTargetX = targetX;
    m_focusTargetY = targetY;
    m_focusTargetZ = targetZ;
}

void CameraController::AddCameraShake(float amplitude, float duration)
{
    if (amplitude <= 0.0f || duration <= 0.0f)
        return;

    LOG_INFO("CameraController: Camera shake triggered (amplitude=%.2f, duration=%.2fs).", amplitude, duration);

    if (amplitude > m_shakeAmplitude)
        m_shakeAmplitude = amplitude;
    if (duration > m_shakeTimer)
    {
        m_shakeTimer = duration;
        m_shakeDuration = duration;
    }
}

void CameraController::BiasYawTowardTarget(float targetX, float targetZ, float dt)
{
    if (dt <= 0.0f)
        return;

    const float toTargetX = targetX - m_playerX;
    const float toTargetZ = targetZ - m_playerZ;
    const float targetYaw = atan2f(toTargetX, toTargetZ);
    const float yawDelta = WrapAngle(targetYaw - m_yaw);
    // Large dt values intentionally clamp to a direct snap so lock-on can recover
    // quickly after long frame stalls or pauses.
    const float blend = std::clamp(kLockOnYawBiasSpeed * dt, 0.0f, 1.0f);
    m_yaw = WrapAngle(m_yaw + (yawDelta * blend));
}

// ---------------------------------------------------------------------------
// ResetToSpawn
// ---------------------------------------------------------------------------
void CameraController::ResetToSpawn(float x, float y, float z, float yaw, float pitch)
{
    m_playerX    = x;
    m_playerY    = y;
    m_playerZ    = z;
    m_yaw        = yaw;
    m_pitch      = pitch;
    m_velocityY  = 0.0f;
    m_isGrounded = true;
    m_dodgeVelX  = 0.0f;
    m_dodgeVelZ  = 0.0f;
    m_dodgeTimer = 0.0f;
    m_dodgeActive = false;
    m_hasCombatFocus = false;
    m_currentCameraDistance = cameraDistance;
    m_currentCameraHeight = cameraHeight;
    m_shakeTimer = 0.0f;
    m_shakeDuration = 0.0f;
    m_shakeAmplitude = 0.0f;
    m_shakePhase = 0.0f;
    ComputeCamFromPlayer();
}

// ---------------------------------------------------------------------------
// BeginDodge
// ---------------------------------------------------------------------------
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
    m_currentCameraDistance = cameraDistance;
    m_currentCameraHeight = cameraHeight;
    m_hasCombatFocus = false;
    m_shakeTimer = 0.0f;
    m_shakeDuration = 0.0f;
    m_shakeAmplitude = 0.0f;
    m_shakePhase = 0.0f;
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
    float camOffsetX = -sinf(m_yaw) * m_currentCameraDistance;
    float camOffsetZ = -cosf(m_yaw) * m_currentCameraDistance;
    m_camX = m_playerX + camOffsetX;
    m_camZ = m_playerZ + camOffsetZ;
    m_camY = m_playerY + m_currentCameraHeight;
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
            // Dodge burst movement overrides regular WASD movement until the burst ends.
            const float dodgeStepDt = std::min(dt, m_dodgeTimer);
            m_playerX += m_dodgeVelX * dodgeStepDt;
            m_playerZ += m_dodgeVelZ * dodgeStepDt;
            m_dodgeTimer -= dt;
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

    }

    const float defaultBlend = std::clamp(kCombatCameraBlendSpeed * dt, 0.0f, 1.0f);
    const float defaultPitchBlend = std::clamp(kCombatCameraPitchBlendSpeed * dt, 0.0f, 1.0f);
    float desiredCameraDistance = cameraDistance;
    float desiredCameraHeight = cameraHeight;

    if (m_hasCombatFocus)
    {
        const float toTargetX = m_focusTargetX - m_playerX;
        const float toTargetZ = m_focusTargetZ - m_playerZ;
        const float targetDistance = sqrtf((toTargetX * toTargetX) + (toTargetZ * toTargetZ));

        desiredCameraDistance = std::clamp(2.7f + targetDistance * 0.12f, kCombatMinDistance, kCombatMaxDistance);
        desiredCameraHeight = cameraHeight + std::clamp(targetDistance * 0.05f, 0.15f, 0.85f);

        const float focusMidY = ((m_playerY - (eyeOffset * 0.35f)) + m_focusTargetY) * 0.5f;
        const float horizontalDistance = std::max(targetDistance, 0.25f);
        const float desiredPitch = std::clamp(
            atan2f(focusMidY - (m_playerY + desiredCameraHeight), horizontalDistance) - 0.08f,
            -maxPitch, maxPitch);
        m_pitch += (desiredPitch - m_pitch) * defaultPitchBlend;
    }

    m_currentCameraDistance += (desiredCameraDistance - m_currentCameraDistance) * defaultBlend;
    m_currentCameraHeight += (desiredCameraHeight - m_currentCameraHeight) * defaultBlend;

    float desiredCamX = m_playerX - sinf(m_yaw) * m_currentCameraDistance;
    float desiredCamZ = m_playerZ - cosf(m_yaw) * m_currentCameraDistance;
    float desiredCamY = m_playerY + m_currentCameraHeight;

    float finalCamX = desiredCamX;
    float finalCamY = desiredCamY;
    float finalCamZ = desiredCamZ;

    if (renderer.IsTerrainAvailable())
    {
        const float deltaCamX = desiredCamX - m_playerX;
        const float deltaCamY = desiredCamY - m_playerY;
        const float deltaCamZ = desiredCamZ - m_playerZ;
        float safeT = 1.0f;

        for (int sampleIndex = 1; sampleIndex <= 6; ++sampleIndex)
        {
            const float t = static_cast<float>(sampleIndex) / 6.0f;
            const float sampleX = m_playerX + deltaCamX * t;
            const float sampleY = m_playerY + deltaCamY * t;
            const float sampleZ = m_playerZ + deltaCamZ * t;
            const float terrainY = renderer.SampleTerrainHeight(sampleX, sampleZ) + kCameraCollisionClearance;
            if (sampleY < terrainY)
            {
                safeT = std::max(0.25f, static_cast<float>(sampleIndex - 1) / 6.0f);
                break;
            }
        }

        finalCamX = m_playerX + deltaCamX * safeT;
        finalCamY = m_playerY + deltaCamY * safeT;
        finalCamZ = m_playerZ + deltaCamZ * safeT;
    }

    if (m_shakeTimer > 0.0f)
    {
        m_shakeTimer -= dt;
        if (m_shakeTimer < 0.0f)
            m_shakeTimer = 0.0f;

        const float shakeFade = (m_shakeDuration > 0.0f)
            ? (m_shakeTimer / m_shakeDuration)
            : 0.0f;
        m_shakePhase += dt * kCameraShakeFrequencyHz;

        const float rightX = cosf(m_yaw);
        const float rightZ = -sinf(m_yaw);
        const float lateralShake = sinf(m_shakePhase * DirectX::XM_2PI) * m_shakeAmplitude * shakeFade;
        finalCamX += rightX * lateralShake;
        finalCamZ += rightZ * lateralShake;
        finalCamY += cosf(m_shakePhase * DirectX::XM_PI) * (m_shakeAmplitude * 0.55f) * shakeFade;

        if (m_shakeTimer <= 0.0f)
        {
            m_shakeDuration = 0.0f;
            m_shakeAmplitude = 0.0f;
        }
    }

    m_camX = finalCamX;
    m_camY = finalCamY;
    m_camZ = finalCamZ;

    // Sync final camera transform to the renderer after combat framing/shake.
    renderer.SetCameraRotation(m_yaw, m_pitch);
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

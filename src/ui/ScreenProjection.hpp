#pragma once
// ScreenProjection.hpp
// Shared world-to-screen projection helper used by DamageNumbers
// and ImGuiLayer debug overlays.
// Uses DirectXMath to match the renderer view/projection exactly.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <DirectXMath.h>
#include <cmath>

namespace ScreenProjection
{
inline bool WorldToScreen(
    float wx, float wy, float wz,
    float camX, float camY, float camZ,
    float yaw, float pitch,
    float vpW, float vpH,
    float& outSx, float& outSy)
{
    if (vpW <= 0.0f || vpH <= 0.0f)
        return false;

    // Build the same look direction the renderer uses.
    float lookDirX = cosf(pitch) * sinf(yaw);
    float lookDirY = sinf(pitch);
    float lookDirZ = cosf(pitch) * cosf(yaw);

    DirectX::XMVECTOR camPos    = DirectX::XMVectorSet(camX, camY, camZ, 1.0f);
    DirectX::XMVECTOR camTarget = DirectX::XMVectorSet(
        camX + lookDirX, camY + lookDirY, camZ + lookDirZ, 1.0f);
    DirectX::XMVECTOR camUp     = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    // Match renderer exactly: LookAtLH, 45-degree FOV, near 0.1, far 2000.
    DirectX::XMMATRIX view    = DirectX::XMMatrixLookAtLH(camPos, camTarget, camUp);
    DirectX::XMMATRIX proj    = DirectX::XMMatrixPerspectiveFovLH(
        DirectX::XM_PIDIV4, vpW / vpH, 0.1f, 2000.0f);
    DirectX::XMMATRIX viewProj = DirectX::XMMatrixMultiply(view, proj);

    // DirectXMath row-vector convention: clip = worldPos * viewProj
    DirectX::XMVECTOR worldPos = DirectX::XMVectorSet(wx, wy, wz, 1.0f);
    DirectX::XMVECTOR clip     = DirectX::XMVector4Transform(worldPos, viewProj);

    // W check — point is behind the camera.
    float w = DirectX::XMVectorGetW(clip);
    if (w <= 0.0f)
        return false;

    // Perspective divide to NDC, then to screen pixels.
    float ndcX = DirectX::XMVectorGetX(clip) / w;
    float ndcY = DirectX::XMVectorGetY(clip) / w;

    outSx = (ndcX + 1.0f) * 0.5f * vpW;
    outSy = (1.0f - ndcY) * 0.5f * vpH;

    // Cull if too far off screen.
    if (outSx < -50.0f || outSx > vpW + 50.0f) return false;
    if (outSy < -50.0f || outSy > vpH + 50.0f) return false;

    return true;
}
} // namespace ScreenProjection

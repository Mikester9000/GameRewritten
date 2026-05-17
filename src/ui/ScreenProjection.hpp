// ============================================================
// FILE: src/ui/ScreenProjection.hpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: ScreenProjection module behavior and local implementation details.
// ============================================================

#pragma once
// ScreenProjection.hpp
// Shared world-to-screen projection helper used by DamageNumbers
// and ImGuiLayer debug overlays.
// Uses DirectXMath to match the renderer view/projection exactly.
//
// For batching: call BuildViewProj() once per frame, then call
// WorldToScreenVP() for each point.  The convenience overload
// WorldToScreen() rebuilds the matrix every call and is only suitable
// for infrequent/single-point projections.

// WIN32_LEAN_AND_MEAN must be defined before the DirectXMath header
// pulls in <windows.h> transitively.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <DirectXMath.h>
#include <cmath>

namespace ScreenProjection
{
// Build the combined view*projection matrix for the given camera state.
// Match renderer exactly: LookAtLH, 45-degree FOV, near 0.1, far 2000.
// vpW and vpH must both be > 0.  Returns false and leaves outViewProj
// unchanged when either dimension is zero.
inline bool BuildViewProj(
    float camX, float camY, float camZ,
    float yaw, float pitch,
    float vpW, float vpH,
    DirectX::XMMATRIX& outViewProj)
{
    if (vpW <= 0.0f || vpH <= 0.0f)
        return false;

    float lookDirX = cosf(pitch) * sinf(yaw);
    float lookDirY = sinf(pitch);
    float lookDirZ = cosf(pitch) * cosf(yaw);

    DirectX::XMVECTOR camPos    = DirectX::XMVectorSet(camX, camY, camZ, 1.0f);
    DirectX::XMVECTOR camTarget = DirectX::XMVectorSet(
        camX + lookDirX, camY + lookDirY, camZ + lookDirZ, 1.0f);
    DirectX::XMVECTOR camUp     = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    DirectX::XMMATRIX view = DirectX::XMMatrixLookAtLH(camPos, camTarget, camUp);
    DirectX::XMMATRIX proj = DirectX::XMMatrixPerspectiveFovLH(
        DirectX::XM_PIDIV4, vpW / vpH, 0.1f, 2000.0f);
    outViewProj = DirectX::XMMatrixMultiply(view, proj);
    return true;
}

// Fast path: project a single world point using a precomputed viewProj matrix.
// Call BuildViewProj() once per frame, then call this for each point.
// Returns false when the point is behind the camera or outside the viewport margin.
inline bool WorldToScreenVP(
    float wx, float wy, float wz,
    const DirectX::XMMATRIX& viewProj,
    float vpW, float vpH,
    float& outSx, float& outSy)
{
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

// Convenience overload for single-point projection.
// Rebuilds view and projection matrices on every call — suitable for
// infrequent/single-point projections only.  For batches (e.g. 64 damage
// numbers per frame) call BuildViewProj() once then use WorldToScreenVP().
inline bool WorldToScreen(
    float wx, float wy, float wz,
    float camX, float camY, float camZ,
    float yaw, float pitch,
    float vpW, float vpH,
    float& outSx, float& outSy)
{
    DirectX::XMMATRIX viewProj;
    if (!BuildViewProj(camX, camY, camZ, yaw, pitch, vpW, vpH, viewProj))
        return false;
    return WorldToScreenVP(wx, wy, wz, viewProj, vpW, vpH, outSx, outSy);
}
} // namespace ScreenProjection

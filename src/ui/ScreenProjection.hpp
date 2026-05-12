#pragma once

#include <DirectXMath.h>
#include <cmath>

inline bool WorldToScreen(
    float wx, float wy, float wz,
    float camX, float camY, float camZ,
    float yaw, float pitch,
    float vpW, float vpH,
    float& outSx, float& outSy)
{
    float dx = wx - camX;
    float dy = wy - camY;
    float dz = wz - camZ;

    float cosY = std::cos(-yaw);
    float sinY = std::sin(-yaw);
    float rx = dx * cosY + dz * sinY;
    float ry = dy;
    float rz = -dx * sinY + dz * cosY;

    float cosP = std::cos(-pitch);
    float sinP = std::sin(-pitch);
    float fx = rx;
    float fy = ry * cosP - rz * sinP;
    float fz = ry * sinP + rz * cosP;

    if (fz <= 0.1f)
        return false;

    if (vpW <= 0.0f || vpH <= 0.0f)
        return false;

    float aspect = vpW / vpH;
    if (aspect <= 0.0f)
        return false;

    static const float kFovScale = 1.0f / std::tan(DirectX::XM_PIDIV4 * 0.5f);
    outSx = (vpW * 0.5f) + (fx / fz) / aspect * kFovScale * (vpW * 0.5f);
    outSy = (vpH * 0.5f) - (fy / fz) * kFovScale * (vpH * 0.5f);
    return true;
}

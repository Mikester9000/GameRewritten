#pragma once

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
    float dx = wx - camX;
    float dy = wy - camY;
    float dz = wz - camZ;

    float cosY = cosf(-yaw);
    float sinY = sinf(-yaw);
    float rx = dx * cosY + dz * sinY;
    float ry = dy;
    float rz = -dx * sinY + dz * cosY;

    float cosP = cosf(-pitch);
    float sinP = sinf(-pitch);
    float fx = rx;
    float fy = ry * cosP - rz * sinP;
    float fz = ry * sinP + rz * cosP;

    if (fz <= 0.1f)
        return false;

    if (vpW <= 0.0f || vpH <= 0.0f)
        return false;

    float aspect = vpW / vpH;
    static constexpr float kFovScale = 2.41421356f; // 1 / tan(fovY/2), fovY = 45° (1 / tan(22.5°))
    outSx = (vpW * 0.5f) + (fx / fz) / aspect * kFovScale * (vpW * 0.5f);
    outSy = (vpH * 0.5f) - (fy / fz) * kFovScale * (vpH * 0.5f);
    return true;
}
} // namespace ScreenProjection

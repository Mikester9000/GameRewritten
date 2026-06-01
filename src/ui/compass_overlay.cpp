#include "compass_overlay.h"

#include <cmath>

namespace gr
{
void CompassOverlay::SetYawRadians(float yawRadians)
{
    m_yawRadians = yawRadians;
}

std::string CompassOverlay::GetCardinalDirection() const
{
    constexpr float kPi = 3.14159265f;
    constexpr float kTwoPi = 6.28318530f;
    float normalized = std::fmod(m_yawRadians, kTwoPi);
    if (normalized < 0.0f)
    {
        normalized += kTwoPi;
    }

    const float octant = normalized / (kPi * 0.25f);
    const int index = static_cast<int>(std::round(octant)) & 7;
    static const char* kDirections[8] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
    return kDirections[index];
}
} // namespace gr

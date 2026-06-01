#pragma once

#include <string>

namespace gr
{
class CompassOverlay
{
public:
    void SetYawRadians(float yawRadians);
    float GetYawRadians() const { return m_yawRadians; }
    std::string GetCardinalDirection() const;

private:
    float m_yawRadians = 0.0f;
};
} // namespace gr

#include "WorldOriginRebase.hpp"

#include <cmath>

void WorldOriginRebase::SetThreshold(float thresholdWorldUnits)
{
    if (thresholdWorldUnits > 10.0f)
        m_threshold = thresholdWorldUnits;
}

bool WorldOriginRebase::TryComputeShift(float playerX, float playerZ, float& outShiftX, float& outShiftZ)
{
    outShiftX = 0.0f;
    outShiftZ = 0.0f;

    if (std::fabs(playerX) < m_threshold && std::fabs(playerZ) < m_threshold)
        return false;

    outShiftX = std::round(playerX / m_threshold) * m_threshold;
    outShiftZ = std::round(playerZ / m_threshold) * m_threshold;

    m_worldOffsetX += outShiftX;
    m_worldOffsetZ += outShiftZ;
    return true;
}

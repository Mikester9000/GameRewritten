#pragma once

class WorldOriginRebase
{
public:
    void SetThreshold(float thresholdWorldUnits);

    bool TryComputeShift(float playerX, float playerZ, float& outShiftX, float& outShiftZ);

    float GetWorldOffsetX() const { return m_worldOffsetX; }
    float GetWorldOffsetZ() const { return m_worldOffsetZ; }

private:
    float m_threshold = 4000.0f;
    float m_worldOffsetX = 0.0f;
    float m_worldOffsetZ = 0.0f;
};

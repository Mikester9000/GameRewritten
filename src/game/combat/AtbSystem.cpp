// AtbSystem.cpp
// ATB charge lane update.

#include "AtbSystem.hpp"

#include <algorithm>

void AtbSystem::SetLaneCount(int count)
{
    m_laneCount = std::max(1, std::min(count, kMaxLanes));
}

void AtbSystem::SetChargeRate(int laneIndex, float rate)
{
    if (laneIndex >= 0 && laneIndex < kMaxLanes)
        m_lanes[laneIndex].chargeRate = rate;
}

void AtbSystem::Update(float dt)
{
    for (int i = 0; i < m_laneCount; ++i)
    {
        AtbLane& lane = m_lanes[i];
        if (lane.paused || lane.IsReady()) continue;
        lane.charge = std::min(1.0f, lane.charge + lane.chargeRate * dt);
    }
}

void AtbSystem::SetGlobalPause(bool pause)
{
    for (int i = 0; i < m_laneCount; ++i)
        m_lanes[i].paused = pause;
}

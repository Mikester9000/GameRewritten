#pragma once
// AtbSystem.hpp
// ATB-style (Active Time Battle) charge lanes — one gauge per party slot.
// Each lane fills at a configurable rate; when full the slot is "ready"
// and the player or AI can spend the charge to queue an action.

#include <array>

struct AtbLane
{
    float charge     = 0.0f; // 0.0 – 1.0
    float chargeRate = 1.0f; // 1.0 = fills in 1 second
    bool  paused     = false;

    bool IsReady() const { return charge >= 1.0f; }

    void Spend()         { charge = 0.0f; }
};

class AtbSystem
{
public:
    static constexpr int kMaxLanes = 4;

    void SetLaneCount(int count);
    void SetChargeRate(int laneIndex, float rate);

    // Advance all un-paused, un-ready lanes by dt seconds.
    void Update(float dt);

    AtbLane&       GetLane(int idx)       { return m_lanes[idx]; }
    const AtbLane& GetLane(int idx) const { return m_lanes[idx]; }

    int  LaneCount() const { return m_laneCount; }

    // Pause / resume all lanes (e.g. during cinematic).
    void SetGlobalPause(bool pause);

private:
    std::array<AtbLane, kMaxLanes> m_lanes{};
    int                            m_laneCount = 1;
};

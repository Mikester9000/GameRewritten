#pragma once

namespace gr
{
struct Vec3Distance
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

class QuestWaypointDistance
{
public:
    void SetPlayerPosition(const Vec3Distance& position) { m_player = position; }
    void SetWaypointPosition(const Vec3Distance& position) { m_waypoint = position; }
    float GetDistanceMeters() const;

private:
    Vec3Distance m_player;
    Vec3Distance m_waypoint;
};
} // namespace gr

#pragma once

namespace gr
{
struct Vec3Position
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

class QuestWaypointDistance
{
public:
    void SetPlayerPosition(const Vec3Position& position) { m_player = position; }
    void SetWaypointPosition(const Vec3Position& position) { m_waypoint = position; }
    float GetDistanceMeters() const;

private:
    Vec3Position m_player;
    Vec3Position m_waypoint;
};
} // namespace gr

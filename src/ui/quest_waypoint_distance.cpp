#include "quest_waypoint_distance.h"

#include <cmath>

namespace gr
{
float QuestWaypointDistance::GetDistanceMeters() const
{
    const float dx = m_waypoint.x - m_player.x;
    const float dy = m_waypoint.y - m_player.y;
    const float dz = m_waypoint.z - m_player.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
} // namespace gr

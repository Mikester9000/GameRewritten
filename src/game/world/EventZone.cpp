#include "EventZone.hpp"

#include <cmath>

namespace
{
bool IsInsideAabb(const EventZone& zone, const DirectX::XMFLOAT3& point)
{
    return std::fabs(point.x - zone.pos.x) <= zone.halfExtents.x &&
           std::fabs(point.y - zone.pos.y) <= zone.halfExtents.y &&
           std::fabs(point.z - zone.pos.z) <= zone.halfExtents.z;
}
}

void EventZoneRegistry::AddZone(const EventZone& zone)
{
    m_zones.push_back(zone);
}

void EventZoneRegistry::Clear()
{
    m_zones.clear();
}

void EventZoneRegistry::Update(const DirectX::XMFLOAT3& playerPos, const std::function<void(int)>& onEnter)
{
    for (EventZone& zone : m_zones)
    {
        const bool isInside = IsInsideAabb(zone, playerPos);
        if (zone.oneShot)
        {
            if (isInside && !zone.triggered)
            {
                onEnter(zone.eventID);
                zone.triggered = true;
            }
            continue;
        }

        if (isInside && !zone.triggered)
        {
            onEnter(zone.eventID);
            zone.triggered = true;
        }
        else if (!isInside && zone.triggered)
        {
            zone.triggered = false;
        }
    }
}

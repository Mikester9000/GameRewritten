// InteractionRegistry.cpp
// Nearest-hotspot query for player interaction prompts.

#include "InteractionRegistry.hpp"

#include <cmath>
#include <limits>

int InteractionRegistry::Add(const Hotspot& hs)
{
    Hotspot entry  = hs;
    entry.id       = m_nextId++;
    m_hotspots.push_back(entry);
    return entry.id;
}

void InteractionRegistry::SetActive(int id, bool active)
{
    for (Hotspot& h : m_hotspots)
        if (h.id == id) { h.active = active; return; }
}

void InteractionRegistry::Clear()
{
    m_hotspots.clear();
    m_nextId = 1;
}

const Hotspot* InteractionRegistry::Query(const DirectX::XMFLOAT3& playerPos) const
{
    const Hotspot* best     = nullptr;
    float          bestDist = std::numeric_limits<float>::max();

    for (const Hotspot& h : m_hotspots)
    {
        if (!h.active) continue;

        const float dx = playerPos.x - h.pos.x;
        const float dz = playerPos.z - h.pos.z;
        const float d2 = dx * dx + dz * dz;

        if (d2 <= h.radius * h.radius && d2 < bestDist)
        {
            best     = &h;
            bestDist = d2;
        }
    }
    return best;
}

void InteractionRegistry::ForEach(const std::function<void(const Hotspot&)>& fn) const
{
    if (!fn) return;
    for (const Hotspot& h : m_hotspots)
        if (h.active) fn(h);
}

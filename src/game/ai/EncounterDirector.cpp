// EncounterDirector.cpp
// Open-world encounter activation + clear tracking.

#include "EncounterDirector.hpp"

#include <algorithm>

int EncounterDirector::AddSlot(float x, float z, float radius, int enemyCount)
{
    EncounterSlot s;
    s.id         = m_nextId++;
    s.spawnX     = x;
    s.spawnZ     = z;
    s.radius     = radius;
    s.enemyCount = enemyCount;
    m_slots.push_back(s);
    return s.id;
}

int EncounterDirector::ActiveCount() const
{
    int n = 0;
    for (const EncounterSlot& s : m_slots)
        if (s.active) ++n;
    return n;
}

void EncounterDirector::Update(
    const DirectX::XMFLOAT3& playerPos,
    const std::function<void(const EncounterSlot&)>& onActivate,
    const std::function<void(int)>&                  /*onClear*/)
{
    for (EncounterSlot& s : m_slots)
    {
        if (s.active) continue;
        if (ActiveCount() >= kMaxActiveEncounters) break;

        const float dx = playerPos.x - s.spawnX;
        const float dz = playerPos.z - s.spawnZ;
        if (dx * dx + dz * dz <= s.radius * s.radius)
        {
            s.active = true;
            if (onActivate) onActivate(s);
        }
    }
}

void EncounterDirector::NotifyClear(int slotId)
{
    for (EncounterSlot& s : m_slots)
        if (s.id == slotId) { s.active = false; return; }
}

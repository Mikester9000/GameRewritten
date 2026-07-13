// CellPortal.cpp
// Interior/exterior cell portal trigger system.

#include "CellPortal.hpp"

#include <cmath>

int CellPortalSystem::AddPortal(const CellPortal& portal)
{
    CellPortal entry = portal;
    entry.id         = m_nextId++;
    m_portals.push_back(entry);
    return entry.id;
}

void CellPortalSystem::Clear()
{
    m_portals.clear();
    m_nextId = 1;
}

void CellPortalSystem::Update(
    const DirectX::XMFLOAT3& playerPos,
    const std::string& currentCell,
    const std::function<void(const CellPortal&)>& onEnter)
{
    for (const CellPortal& p : m_portals)
    {
        if (p.fromCell != currentCell) continue;

        const float dx = playerPos.x - p.triggerPos.x;
        const float dz = playerPos.z - p.triggerPos.z;
        if (dx * dx + dz * dz <= p.triggerRadius * p.triggerRadius)
        {
            if (onEnter) onEnter(p);
            return; // handle one portal per frame
        }
    }
}

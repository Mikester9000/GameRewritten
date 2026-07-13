// CellPortal.cpp
// Interior/exterior cell portal trigger system.

#include "CellPortal.hpp"

#include <algorithm>
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
    m_insidePortalIds.clear();
    m_nextId = 1;
}

void CellPortalSystem::Update(
    const DirectX::XMFLOAT3& playerPos,
    const std::string& currentCell,
    const std::function<void(const CellPortal&)>& onEnter)
{
    const CellPortal* enteredPortal = nullptr;

    for (const CellPortal& p : m_portals)
    {
        const bool sameCell = p.fromCell == currentCell;
        float distSq = 0.0f;
        if (sameCell)
        {
            const float dx = playerPos.x - p.triggerPos.x;
            const float dz = playerPos.z - p.triggerPos.z;
            distSq = dx * dx + dz * dz;
        }
        const bool inside = sameCell && distSq <= p.triggerRadius * p.triggerRadius;

        auto it = std::find(m_insidePortalIds.begin(), m_insidePortalIds.end(), p.id);
        const bool wasInside = it != m_insidePortalIds.end();

        if (inside)
        {
            if (!wasInside)
            {
                m_insidePortalIds.push_back(p.id);
                if (!enteredPortal) enteredPortal = &p;
            }
        }
        else if (wasInside)
        {
            m_insidePortalIds.erase(it);
        }
    }

    if (enteredPortal && onEnter) onEnter(*enteredPortal);
}

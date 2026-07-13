// LandmarkTrigger.cpp
// One-shot landmark discovery on player proximity.

#include "LandmarkTrigger.hpp"

#include <cmath>

int LandmarkTriggerSystem::Add(const Landmark& lm)
{
    Landmark entry = lm;
    entry.id       = m_nextId++;
    m_landmarks.push_back(entry);
    return entry.id;
}

void LandmarkTriggerSystem::Clear()
{
    m_landmarks.clear();
    m_nextId = 1;
}

void LandmarkTriggerSystem::Update(const DirectX::XMFLOAT3& playerPos,
                                   const std::function<void(const Landmark&)>& onDiscover)
{
    for (Landmark& lm : m_landmarks)
    {
        if (lm.discovered) continue;

        const float dx = playerPos.x - lm.pos.x;
        const float dz = playerPos.z - lm.pos.z;

        if (dx * dx + dz * dz <= lm.radius * lm.radius)
        {
            lm.discovered = true;
            if (onDiscover) onDiscover(lm);
        }
    }
}

bool LandmarkTriggerSystem::SetDiscovered(const std::string& name, bool discovered)
{
    for (Landmark& lm : m_landmarks)
    {
        if (lm.name == name)
        {
            lm.discovered = discovered;
            return true;
        }
    }
    return false;
}

void LandmarkTriggerSystem::SetAllDiscovered(bool discovered)
{
    for (Landmark& lm : m_landmarks)
        lm.discovered = discovered;
}

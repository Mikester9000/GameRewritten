#include "WorldLodManager.hpp"

#include <algorithm>

void WorldLodManager::SetDistanceScale(float distanceScale)
{
    m_distanceScale = std::clamp(distanceScale, 0.5f, 3.0f);
}

WorldLodManager::Tier WorldLodManager::ResolveTier(float distanceFromCamera) const
{
    const float d = std::max(0.0f, distanceFromCamera);
    const float scaled = d / m_distanceScale;

    if (scaled < 120.0f)
        return Tier::Near;
    if (scaled < 320.0f)
        return Tier::Mid;
    if (scaled < 800.0f)
        return Tier::Far;
    return Tier::Impostor;
}

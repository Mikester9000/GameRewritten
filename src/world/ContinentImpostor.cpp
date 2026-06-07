#include "ContinentImpostor.hpp"

#include <cmath>

void ContinentImpostorSystem::SetImpostors(const std::vector<ContinentImpostor>& impostors)
{
    m_impostors = impostors;
}

std::vector<float> ContinentImpostorSystem::ComputeVisibility(float playerX, float playerZ) const
{
    std::vector<float> alpha;
    alpha.reserve(m_impostors.size());

    for (const ContinentImpostor& impostor : m_impostors)
    {
        const float dx = playerX - impostor.centerX;
        const float dz = playerZ - impostor.centerZ;
        const float dist = std::sqrt((dx * dx) + (dz * dz));

        const float fadeStart = impostor.visibleDistance - impostor.fadeDistance;
        if (dist <= fadeStart)
        {
            alpha.push_back(1.0f);
            continue;
        }
        if (dist >= impostor.visibleDistance)
        {
            alpha.push_back(0.0f);
            continue;
        }

        const float t = (impostor.visibleDistance - dist) / impostor.fadeDistance;
        alpha.push_back(t < 0.0f ? 0.0f : (t > 1.0f ? 1.0f : t));
    }

    return alpha;
}

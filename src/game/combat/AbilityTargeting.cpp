// AbilityTargeting.cpp
// Single / cone / AoE targeting shape hit-list builders.

#include "AbilityTargeting.hpp"
#include "../actors/EnemyActor.hpp"

#include <cmath>
#include <limits>

TargetingResult AbilityTargeting::Single(const DirectX::XMFLOAT3& originPos,
                                          float maxRange,
                                          const std::vector<EnemyActor>& enemies)
{
    TargetingResult result;
    int   bestIdx  = -1;
    float bestDist = std::numeric_limits<float>::max();

    for (int i = 0; i < static_cast<int>(enemies.size()); ++i)
    {
        const EnemyActor& e = enemies[i];
        const float dx = e.x - originPos.x;
        const float dz = e.z - originPos.z;
        const float d2 = dx * dx + dz * dz;
        if (d2 <= maxRange * maxRange && d2 < bestDist)
        {
            bestDist = d2;
            bestIdx  = i;
        }
    }
    if (bestIdx >= 0) result.hitIndices.push_back(bestIdx);
    return result;
}

TargetingResult AbilityTargeting::Cone(const DirectX::XMFLOAT3& originPos,
                                        const DirectX::XMFLOAT3& forwardDir,
                                        float halfAngle,
                                        float maxRange,
                                        const std::vector<EnemyActor>& enemies)
{
    TargetingResult result;
    const float cosHA = std::cos(halfAngle);

    for (int i = 0; i < static_cast<int>(enemies.size()); ++i)
    {
        const EnemyActor& e = enemies[i];
        const float dx = e.x - originPos.x;
        const float dz = e.z - originPos.z;
        const float dist = std::sqrt(dx * dx + dz * dz);
        if (dist > maxRange || dist < 0.001f) continue;

        const float dot = (dx / dist) * forwardDir.x + (dz / dist) * forwardDir.z;
        if (dot >= cosHA) result.hitIndices.push_back(i);
    }
    return result;
}

TargetingResult AbilityTargeting::AoE(const DirectX::XMFLOAT3& originPos,
                                       float radius,
                                       const std::vector<EnemyActor>& enemies)
{
    TargetingResult result;
    for (int i = 0; i < static_cast<int>(enemies.size()); ++i)
    {
        const EnemyActor& e = enemies[i];
        const float dx = e.x - originPos.x;
        const float dz = e.z - originPos.z;
        if (dx * dx + dz * dz <= radius * radius)
            result.hitIndices.push_back(i);
    }
    return result;
}

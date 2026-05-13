#pragma once

#include "../actors/EnemyActor.hpp"

class Targeting
{
public:
    static constexpr float kLockRadius = 25.0f;

    bool isLocked = false;
    EnemyActor* target = nullptr;

    void ToggleLock(EnemyActor* enemies, int count, float playerX, float playerZ)
    {
        if (isLocked)
        {
            ClearLock();
            return;
        }

        target = FindNearestAliveEnemyInRange(enemies, count, playerX, playerZ);
        isLocked = (target != nullptr);
    }

    void RefreshLock(float playerX, float playerZ)
    {
        if (!IsTargetValid(target, playerX, playerZ))
            ClearLock();
    }

    const EnemyActor* GetTarget() const
    {
        if (!isLocked || !target || target->isDead)
            return nullptr;
        return target;
    }

private:
    static constexpr float kLockRadiusSq = kLockRadius * kLockRadius;

    void ClearLock()
    {
        isLocked = false;
        target = nullptr;
    }

    static bool IsTargetValid(const EnemyActor* candidate, float playerX, float playerZ)
    {
        if (!candidate || candidate->isDead)
            return false;

        const float deltaX = candidate->x - playerX;
        const float deltaZ = candidate->z - playerZ;
        const float distanceSq = (deltaX * deltaX) + (deltaZ * deltaZ);
        return distanceSq <= kLockRadiusSq;
    }

    static EnemyActor* FindNearestAliveEnemyInRange(
        EnemyActor* enemies, int count, float playerX, float playerZ)
    {
        EnemyActor* bestTarget = nullptr;
        float bestDistanceSq = kLockRadiusSq;

        for (int i = 0; i < count; ++i)
        {
            EnemyActor& candidate = enemies[i];
            if (candidate.isDead)
                continue;

            const float deltaX = candidate.x - playerX;
            const float deltaZ = candidate.z - playerZ;
            const float distanceSq = (deltaX * deltaX) + (deltaZ * deltaZ);

            if (distanceSq <= bestDistanceSq)
            {
                bestDistanceSq = distanceSq;
                bestTarget = &candidate;
            }
        }

        return bestTarget;
    }
};

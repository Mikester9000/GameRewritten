#pragma once

#include "../actors/EnemyActor.hpp"

class Targeting
{
public:
    // Lock range in world units. Keep this comfortably beyond enemy detect radius.
    static constexpr float kLockRadius = 25.0f;

    void ToggleLockOn(EnemyActor* enemies, int count, float playerX, float playerZ)
    {
        if (IsLocked())
        {
            ClearLock();
            return;
        }

        m_target = FindNearestAliveEnemyInRange(enemies, count, playerX, playerZ);
    }

    void RefreshLock(float playerX, float playerZ)
    {
        if (!IsTargetValid(m_target, playerX, playerZ))
            ClearLock();
    }

    bool IsLocked() const
    {
        // Lock state is implicit: locked only while target pointer exists and target is alive.
        // RuntimeScene calls RefreshLock() each frame right after combat resolution so dead
        // targets are cleared immediately.
        return (m_target != nullptr) && !m_target->isDead;
    }

    const EnemyActor* GetTarget() const
    {
        if (!IsLocked())
            return nullptr;
        return m_target;
    }

private:
    static constexpr float kLockRadiusSq = kLockRadius * kLockRadius;
    EnemyActor* m_target = nullptr;

    void ClearLock()
    {
        m_target = nullptr;
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

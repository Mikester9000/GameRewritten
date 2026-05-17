// ============================================================
// FILE: src/game/combat/Targeting.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: Targeting module behavior and local implementation details.
// ============================================================

#pragma once

#include "../actors/EnemyActor.hpp"

class Targeting
{
public:
    // Lock range in world units. Keep this comfortably beyond enemy detect radius.
    static constexpr float kLockRadius = 25.0f;

    void ToggleLockOn(EnemyActor* enemies, int count, float playerX, float playerZ)
    {
        if (!IsLocked())
        {
            m_target = FindNearestAliveEnemyInRange(enemies, count, playerX, playerZ, nullptr);
            return;
        }

        // Cycling is deterministic nearest-selection each press.
        // If the current lock is invalid, reacquire using normal nearest-target rules.
        // If the current lock is valid, pick the nearest other valid target.
        const bool hasValidCurrentTarget = IsTargetValid(m_target, playerX, playerZ);
        const EnemyActor* excludedTarget = hasValidCurrentTarget ? m_target : nullptr;

        EnemyActor* nextTarget = FindNearestAliveEnemyInRange(
            enemies, count, playerX, playerZ, excludedTarget);
        if (nextTarget)
        {
            m_target = nextTarget;
            return;
        }

        // No alternate target in range, so unlock cleanly.
        ClearLock();
    }

    // Legacy compatibility overload; RuntimeScene now refreshes lock with enemy context.
    void RefreshLock(float playerX, float playerZ)
    {
        (void)playerX;
        (void)playerZ;
    }

    void RefreshLock(EnemyActor* enemies, int count, float playerX, float playerZ)
    {
        if (!IsLocked())
            return;

        if (IsTargetValid(m_target, playerX, playerZ))
            return;

        EnemyActor* replacementTarget = FindNearestAliveEnemyInRange(
            enemies, count, playerX, playerZ, m_target);
        if (replacementTarget)
        {
            m_target = replacementTarget;
            return;
        }

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
        EnemyActor* enemies, int count, float playerX, float playerZ, const EnemyActor* excludeTarget)
    {
        if (!enemies || count <= 0)
            return nullptr;

        EnemyActor* bestTarget = nullptr;
        float bestDistanceSq = kLockRadiusSq;

        for (int i = 0; i < count; ++i)
        {
            EnemyActor& candidate = enemies[i];
            if (&candidate == excludeTarget)
                continue;
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

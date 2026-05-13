// EnemyActor.cpp
// Implements the enemy combat state machine (Patrol/Chase/Attack/Hit/Dead),
// terrain-snap, and visual submission.

#include "EnemyActor.hpp"

#include "../PrefabLibrary.hpp"
#include "../PrimitiveRenderer.hpp"
#include "../../rendering/d3d11/D3D11Renderer.hpp"

#include <logger/Logger.hpp>
#include <cmath>
#include <string>

void EnemyActor::Init(float startX, float startZ,
                      float wpAx, float wpAz,
                      float wpBx, float wpBz,
                      int   startHp)
{
    x = startX;
    y = 0.0f;
    z = startZ;
    yaw = 0.0f;
    hp    = startHp;
    maxHp = startHp;
    isDead = false;
    moveSpeed = 3.0f;
    currentWaypoint = 0;
    waypointX[0] = wpAx;  waypointZ[0] = wpAz;
    waypointX[1] = wpBx;  waypointZ[1] = wpBz;
    state        = EnemyState::Patrol;
    stateTimer   = 0.0f;
    pendingAttack = false;
    pendingAttackHitBox = HitBox{};
}

void EnemyActor::TransitionTo(EnemyState next, float duration)
{
    state      = next;
    stateTimer = duration;
    if (next == EnemyState::Dead)
        isDead = true;
}

void EnemyActor::OnHit(int damage)
{
    hp -= damage;
    if (hp <= 0)
    {
        hp     = 0;
        isDead = true;
        TransitionTo(EnemyState::Dead, 0.0f);
    }
    else
    {
        TransitionTo(EnemyState::Hit, kHitStaggerDuration);
    }
    LOG_INFO("EnemyActor: Took " + std::to_string(damage) +
             " damage. HP remaining: " + std::to_string(hp));
}

void EnemyActor::Update(float dt, D3D11Renderer& renderer,
                        float playerX, float playerZ)
{
    // Dead guard — nothing to update.
    if (isDead)
        return;

    // Tick state timer, clamp to zero.
    if (stateTimer > 0.0f)
    {
        stateTimer -= dt;
        if (stateTimer < 0.0f)
            stateTimer = 0.0f;
    }

    // Distance to player (XZ plane only).
    const float distXToPlayer = playerX - x;
    const float distZToPlayer = playerZ - z;
    const float distanceToPlayer = sqrtf(distXToPlayer * distXToPlayer + distZToPlayer * distZToPlayer);

    if (state == EnemyState::Patrol)
    {
        // Walk between the two waypoints.
        const float targetX = waypointX[currentWaypoint];
        const float targetZ = waypointZ[currentWaypoint];
        const float distXToWaypoint = targetX - x;
        const float distZToWaypoint = targetZ - z;
        const float distanceToWaypoint = sqrtf(distXToWaypoint * distXToWaypoint + distZToWaypoint * distZToWaypoint);

        if (distanceToWaypoint < 0.5f)
        {
            // Snap to waypoint and switch target.
            x = targetX;
            z = targetZ;
            currentWaypoint = (currentWaypoint + 1) % 2;
        }
        else
        {
            const float step    = moveSpeed * dt;
            const float inverseDistance = 1.0f / distanceToWaypoint;
            const float move = (step < distanceToWaypoint) ? step : distanceToWaypoint;
            x += distXToWaypoint * inverseDistance * move;
            z += distZToWaypoint * inverseDistance * move;
            yaw = atan2f(distXToWaypoint, distZToWaypoint);
        }

        if (distanceToPlayer < kDetectRadius)
        {
            TransitionTo(EnemyState::Chase, 0.0f);
            LOG_INFO("EnemyActor: Detected player — entering Chase.");
        }
    }
    else if (state == EnemyState::Chase)
    {
        // Move toward the player.
        if (distanceToPlayer > 0.01f)
        {
            const float inverseDistance = 1.0f / distanceToPlayer;
            const float step    = moveSpeed * dt;
            const float move = (step < distanceToPlayer) ? step : distanceToPlayer;
            x += distXToPlayer * inverseDistance * move;
            z += distZToPlayer * inverseDistance * move;
            yaw = atan2f(distXToPlayer, distZToPlayer);
        }

        if (distanceToPlayer < kAttackRadius)
        {
            TransitionTo(EnemyState::Attack, kAttackWindUpDuration);
            LOG_INFO("EnemyActor: In attack range — winding up.");
        }
        else if (distanceToPlayer > kLeashRadius)
        {
            TransitionTo(EnemyState::Patrol, 0.0f);
            LOG_INFO("EnemyActor: Player out of range — returning to Patrol.");
        }
    }
    else if (state == EnemyState::Attack)
    {
        // Stand still during wind-up; fire when timer expires.
        if (stateTimer <= 0.0f)
        {
            pendingAttack = true;
            pendingAttackHitBox = HitBox{};
            TransitionTo(EnemyState::Chase, 0.0f);
            LOG_INFO("EnemyActor: Attack released.");
        }
    }
    else if (state == EnemyState::Hit)
    {
        // Stand still during stagger; resume chasing when timer expires.
        if (stateTimer <= 0.0f)
        {
            if (hp > 0)
                TransitionTo(EnemyState::Chase, 0.0f);
            else
                TransitionTo(EnemyState::Dead, 0.0f);
        }
    }
    // Dead is handled by the guard at the top of this function.

    // Snap Y to terrain so the enemy sits on the ground.
    if (renderer.IsTerrainAvailable())
        y = renderer.SampleTerrainHeight(x, z);
}

void EnemyActor::SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
                                     PrimitiveRenderer&   primitiveRenderer) const
{
    if (isDead)
        return;

    static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
    const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);
    if (!visualPrefab)
        return;

    primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, 1.0f);
}

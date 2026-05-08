// EnemyActor.cpp
// Implements patrol movement, terrain-snap, and visual submission for a basic enemy.

#include "EnemyActor.hpp"

#include "../PrefabLibrary.hpp"
#include "../PrimitiveRenderer.hpp"
#include "../../rendering/d3d11/D3D11Renderer.hpp"

#include <cmath>

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
}

void EnemyActor::Update(float dt, D3D11Renderer& renderer)
{
    if (isDead)
        return;

    const float targetX = waypointX[currentWaypoint];
    const float targetZ = waypointZ[currentWaypoint];

    const float dx   = targetX - x;
    const float dz   = targetZ - z;
    const float dist = sqrtf(dx * dx + dz * dz);

    if (dist < 0.5f)
    {
        // Reached current waypoint — switch to the other one.
        currentWaypoint = (currentWaypoint + 1) % 2;
    }
    else
    {
        // Advance toward the waypoint at constant speed.
        const float invDist = 1.0f / dist;
        x += dx * invDist * moveSpeed * dt;
        z += dz * invDist * moveSpeed * dt;

        // Face the direction of travel (yaw = 0 means facing +Z).
        yaw = atan2f(dx, dz);
    }

    // Snap Y to terrain so the enemy sits on the ground.
    if (renderer.IsTerrainAvailable())
        y = renderer.SampleTerrainHeight(x, z);
}

void EnemyActor::SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
                                     PrimitiveRenderer&   primitiveRenderer) const
{
    if (isDead)
        return;

    const PrimitivePrefab* visualPrefab =
        prefabLibrary.GetPrefab(ActorCommon::PLAYER_VISUAL_PREFAB_ID);
    if (!visualPrefab)
        return;

    primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, 1.0f);
}

#pragma once
// EnemyActor.hpp
// A basic patrol enemy that walks between two waypoints and renders using
// the existing primitive/prefab system.  No combat logic yet.

#include "ActorCommon.hpp"

class D3D11Renderer;
class PrefabLibrary;
class PrimitiveRenderer;

class EnemyActor
{
public:
    // World-space position.
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    // Y-axis rotation in radians (0 = facing +Z).
    float yaw = 0.0f;

    // Health.
    int  hp    = 10;
    int  maxHp = 10;
    bool isDead = false;

    // Movement speed in world units per second.
    float moveSpeed = 3.0f;

    // Patrol waypoints: the enemy shuttles between index 0 and 1.
    float waypointX[2] = {};
    float waypointZ[2] = {};
    int   currentWaypoint = 0;

    // Set starting position and patrol waypoints.
    // y is terrain-snapped on the first Update call.
    void Init(float startX, float startZ,
              float wpAx, float wpAz,
              float wpBx, float wpBz,
              int   startHp = 10);

    // Move toward the current waypoint, snap Y to terrain, face direction of travel.
    // Skips all logic when isDead is true.
    void Update(float dt, D3D11Renderer& renderer);

    // Expand the enemy visual into the runtime primitive bucket.
    // Reuses the player blockout prefab as a temporary enemy blockout.
    // Does nothing when isDead is true.
    void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
                             PrimitiveRenderer&   primitiveRenderer) const;
};

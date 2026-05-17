// ============================================================
// FILE: src/game/actors/EnemyActor.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: EnemyActor module behavior and local implementation details.
// ============================================================

#pragma once
// EnemyActor.hpp
// A patrol enemy with a combat state machine (Patrol/Chase/Attack/Hit/Dead).
// Terrain-snaps Y each frame via the renderer.

#include "ActorCommon.hpp"
#include "EnemyState.hpp"
#include "../combat/HitBox.hpp"

class D3D11Renderer;
class PrefabLibrary;
class PrimitiveRenderer;

class EnemyActor
{
public:
    // Detection and engagement radius constants.
    static constexpr float kDetectRadius = 18.0f;  // begin chasing
    static constexpr float kAttackRadius =  2.5f;  // begin attack wind-up
    static constexpr float kLeashRadius  = 27.0f;  // return to patrol

    // State duration constants (seconds).
    static constexpr float kAttackWindUpDuration = 0.60f;  // wind-up before dealing damage
    static constexpr float kHitStaggerDuration   = 0.30f;  // stagger after taking a hit
    static constexpr float kHitFlashDuration     = 0.14f;  // short readability flash on hit
    static constexpr float kHitFlashBlinkPeriod  = 0.04f;  // blink cadence during flash
    static constexpr float kHitFlashScale        = 1.05f;  // slight pop while flashing

    // World-space position.
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    // Y-axis rotation in radians (0 = facing +Z).
    float yaw = 0.0f;

    // Display name shown in the target HUD when this enemy is locked on.
    const char* name = "Goblin";

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

    // Combat state machine.
    EnemyState state       = EnemyState::Patrol;
    float      stateTimer  = 0.0f;
    bool       pendingAttack = false;
    HitBox     pendingAttackHitBox{};
    float      hitFlashTimer = 0.0f;

    // Set starting position and patrol waypoints.
    // y is terrain-snapped on the first Update call.
    void Init(float startX, float startZ,
              float wpAx, float wpAz,
              float wpBx, float wpBz,
              int   startHp = 10);

    // Advance state machine, move, snap Y to terrain.
    // playerX/playerZ are the current player world-space XZ position.
    void Update(float dt, D3D11Renderer& renderer,
                float playerX, float playerZ);

    // Apply incoming damage; triggers Hit stagger or Dead transition.
    void OnHit(int damage);

    // Expand the enemy visual into the runtime primitive bucket.
    // Reuses the player blockout prefab for enemy visuals.
    // Does nothing when isDead is true.
    void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
                             PrimitiveRenderer&   primitiveRenderer) const;

private:
    // Change state immediately and set the state-duration timer.
    void TransitionTo(EnemyState next, float duration);

    // Returns whether the visual should be drawn this frame during hit flash.
    bool IsHitFlashVisible() const;
};

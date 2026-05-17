// ============================================================
// FILE: src/game/combat/HitBox.hpp
// SYSTEM: HitBox.hpp
// SYSTEM: gameplay systems, actors, combat, and runtime state

#pragma once
// HitBox.hpp
// A short-lived world-space AABB that deals damage to any overlapping actor.
// Spawn one via CombatSystem::SpawnHitBox and it expires after framesToLive frames.

struct HitBox
{
    // Center position in world space.
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    // Half-extents of the AABB on each axis.
    float halfX = 0.5f;
    float halfY = 1.0f;
    float halfZ = 0.5f;

    // Damage dealt to each actor hit per frame while this hitbox is alive.
    int damage = 1;

    // Remaining frames this hitbox should exist. Decremented each Update call.
    int framesToLive = 2;

    // True after this hitbox has hit the player once.
    // Prevents the same hitbox dealing damage on consecutive frames.
    bool hasHitPlayer = false;
};

// ============================================================
// FILE: src/game/combat/HitBox.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: HitBox module behavior and local implementation details.
// ============================================================

#pragma once
// HitBox.hpp
// A short-lived world-space AABB that deals damage to any overlapping actor.
// Spawn one via CombatSystem::SpawnHitBox and it expires after framesToLive frames.

#include "ElementSystem.hpp"

struct HitBox
{
    enum class HitAilment : int
    {
        None = 0,
        Poison,
        Burn,
        Shock
    };

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

    // Y-axis yaw (radians) of the attacker when this hitbox was spawned.
    // Used by CombatSystem to detect weak-point (backstab) hits.
    float attackerYaw = 0.0f;

    // Element and status payload for elemental/ailment combat systems.
    Element attackElement = Element::Physical;
    HitAilment statusAilment = HitAilment::None;
    float statusBuildUp = 0.0f;

    // Bitmask of enemies already hit by this hitbox to avoid repeated per-frame hits.
    unsigned int hitEnemyMask = 0u;
};

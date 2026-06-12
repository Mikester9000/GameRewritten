// ============================================================
// FILE: src/game/ai/EnemyArchetypeProfile.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: EnemyArchetypeProfile module behavior and local implementation details.
// ============================================================

#pragma once
// EnemyArchetypeProfile.hpp
// Header-only archetype definitions for enemy behavior tuning.
// Each archetype is a preset bundle of AI parameters applied to an EnemyActor
// at construction time.  No virtual dispatch — just a constexpr data table.

// Three distinct behavior archetypes visible to the player:
//   Patrol      — lazy; only detects the player at close range; does not react to damage.
//   Aggressive  — bold; detects from far away; immediately aggros when hit.
//   Skirmisher  — fast; medium range; attacks from a larger radius (hit-and-run feel).
enum class EnemyArchetype
{
    Patrol,
    Aggressive,
    Skirmisher
};

struct EnemyArchetypeProfile
{
    float chaseRadius;    // distance at which the enemy starts chasing the player
    float attackRadius;   // distance at which the enemy begins its attack wind-up
    float attackCooldown; // wind-up duration in seconds before the hit fires
    float moveSpeed;      // world-units per second
    bool  aggroOnDamage;  // if true and in Patrol, skip hit-stagger and go straight to Chase
};

// Constexpr lookup — no runtime cost.
inline constexpr EnemyArchetypeProfile GetProfile(EnemyArchetype archetype)
{
    switch (archetype)
    {
    case EnemyArchetype::Patrol:
        return { 8.0f, 1.8f, 1.4f, 3.0f, false };
    case EnemyArchetype::Aggressive:
        return { 14.0f, 2.2f, 0.9f, 4.5f, true };
    case EnemyArchetype::Skirmisher:
        return { 10.0f, 3.5f, 0.7f, 5.0f, true };
    default:
        return { 8.0f, 1.8f, 1.4f, 3.0f, false };
    }
}

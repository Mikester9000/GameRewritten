// ============================================================
// FILE: src/game/actors/EnemyState.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: EnemyState module behavior and local implementation details.
// ============================================================

#pragma once
enum class EnemyState
{
    Patrol,   // walking between waypoints
    Chase,    // moving toward player
    Attack,   // wind-up before dealing damage
    Hit,      // brief stagger after taking damage
    Dead      // waiting to despawn
};

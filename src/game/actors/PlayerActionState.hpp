// ============================================================
// FILE: src/game/actors/PlayerActionState.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PlayerActionState module behavior and local implementation details.
// ============================================================

#pragma once

enum class PlayerActionState
{
    Idle,
    Move,
    Jump,
    Fall,
    Attack1,
    Attack2,
    Dodge,
    Stunned,
    Dead
};

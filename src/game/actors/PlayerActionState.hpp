// ============================================================
// FILE: src/game/actors/PlayerActionState.hpp
// SYSTEM: PlayerActionState.hpp
// SYSTEM: gameplay systems, actors, combat, and runtime state

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

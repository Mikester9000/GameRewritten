// ============================================================
// FILE: src/game/animation/PlayerAnimBridge.cpp
// SYSTEM: Game
// ROLE: maps PlayerActionState to animation clip names and calls TransitionTo
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PlayerAnimBridge module behavior and local implementation details.
// ============================================================

#include "PlayerAnimBridge.hpp"
#include "../../logger/Logger.hpp"

// ---------------------------------------------------------------------------
// Map a PlayerActionState to the corresponding clip name in the hero_pack.
// Returns "idle" as safe fallback for unmapped states.
static const char* ClipNameForState(PlayerActionState state)
{
    switch (state)
    {
    case PlayerActionState::Idle:     return "idle";
    case PlayerActionState::Move:     return "walk";
    case PlayerActionState::Jump:     return "jump_start";
    case PlayerActionState::Fall:     return "jump_loop";
    case PlayerActionState::Attack1:  return "attack";
    case PlayerActionState::Attack2:  return "attack_combo_1";
    case PlayerActionState::Dodge:    return "dodge";
    case PlayerActionState::Stunned:  return "hit_react";
    case PlayerActionState::Dead:     return "death";
    default:                          return "idle";
    }
}

// ---------------------------------------------------------------------------
// Crossfade durations (seconds).
// Locomotion states get a longer blend; action states get a short snap blend.
static float CrossfadeDuration(PlayerActionState state)
{
    switch (state)
    {
    case PlayerActionState::Idle:
    case PlayerActionState::Move:
        return 0.30f;
    default:
        return 0.20f;
    }
}

// ---------------------------------------------------------------------------
void PlayerAnimBridge::Update(PlayerActionState state,
                              AnimationComponent& animComp,
                              const std::unordered_map<std::string, LoadedAnimClip>& clipLibrary)
{
    static PlayerActionState s_lastState = static_cast<PlayerActionState>(-1);

    if (state == s_lastState)
        return;
    s_lastState = state;

    const char* clipName = ClipNameForState(state);
    auto it = clipLibrary.find(clipName);
    if (it == clipLibrary.end())
    {
        LOG_WARN("PlayerAnimBridge: clip '" + std::string(clipName) + "' not found in library");
        return;
    }

    animComp.TransitionTo(&it->second, CrossfadeDuration(state));
}

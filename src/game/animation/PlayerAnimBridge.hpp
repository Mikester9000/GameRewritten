// ============================================================
// FILE: src/game/animation/PlayerAnimBridge.hpp
// SYSTEM: Game
// ROLE: maps PlayerActionState to animation clip names and calls TransitionTo
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PlayerAnimBridge module behavior and local implementation details.
// ============================================================

#pragma once

#include "AnimationComponent.hpp"
#include "AnimClipLoader.hpp"
#include "../actors/PlayerActionState.hpp"

#include <string>
#include <unordered_map>

// Maps PlayerActionState enum values to named clips and calls TransitionTo.
class PlayerAnimBridge
{
public:
    // Check state; on state change, look up the clip in clipLibrary and crossfade.
    // clipLibrary: map of clip name → LoadedAnimClip (built at startup from hero_pack).
    static void Update(PlayerActionState state,
                       AnimationComponent& animComp,
                       const std::unordered_map<std::string, LoadedAnimClip>& clipLibrary);
};

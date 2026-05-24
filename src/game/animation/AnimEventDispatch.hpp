// ============================================================
// FILE: src/game/animation/AnimEventDispatch.hpp
// SYSTEM: Game
// ROLE: polls animation events from AnimationComponent and routes them to audio/combat
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimEventDispatch module behavior and local implementation details.
// ============================================================

#pragma once

#include "AnimationComponent.hpp"
#include "../combat/CombatSystem.hpp"

// Polls fired animation events for the current frame and routes them
// to tp::Audio one-shots and CombatSystem hooks.
class AnimEventDispatch
{
public:
    // Dispatch events fired between prevTime and animComp.playbackTime.
    // audio events → tp::Audio::PlayOneShot
    // "hit"         → CombatSystem::SpawnHitBox (via TriggerAttack if needed)
    // "cancel"      → CombatSystem cancel window (TODO: wire when API exists)
    // "cast_release"→ CombatSystem cast release (TODO: wire when API exists)
    static void Dispatch(AnimationComponent& animComp,
                         float prevTime,
                         CombatSystem& combat,
                         float dt);
};

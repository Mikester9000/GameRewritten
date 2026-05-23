// ============================================================
// FILE: src/game/actors/PlayerActor.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PlayerActor module behavior and local implementation details.
// ============================================================

#pragma once

#include "ActorCommon.hpp"
#include "PlayerActionState.hpp"
#include "PlayerStats.hpp"

class CameraController;
struct InputActionMap;
class PrefabLibrary;
class PrimitiveRenderer;

class PlayerActor
{
public:
    PlayerStats stats;
    PlayerActionState state = PlayerActionState::Idle;
    float stateTimer = 0.0f;

    // Parry window: set to kParryWindowSec when a Dodge starts.
    // While > 0, incoming enemy hits are parried instead of dealt.
    float parryWindowTimer = 0.0f;

    // Set true when a parry succeeds; the next player attack gets a bonus multiplier.
    // Cleared by RuntimeScene after consuming via CombatSystem::SetNextHitMultiplier.
    bool counterBonusActive = false;

    // Returns true during the tight parry window at the start of a dodge.
    bool IsParryActive() const { return parryWindowTimer > 0.0f; }

    void Update(float dt, const InputActionMap& input, bool isGrounded, bool attackPressed);

    void SubmitRuntimeVisual(const CameraController& cameraController,
                             const PrefabLibrary& prefabLibrary,
                             PrimitiveRenderer& primitiveRenderer) const;

private:
    void TransitionTo(PlayerActionState next, float duration);
    ActorCommon::RuntimeActorPose BuildRuntimePose(const CameraController& cameraController) const;
};

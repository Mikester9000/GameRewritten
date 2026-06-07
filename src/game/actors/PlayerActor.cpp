// ============================================================
// FILE: src/game/actors/PlayerActor.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PlayerActor module behavior and local implementation details.
// ============================================================

#include "PlayerActor.hpp"

#include "../../app/InputActionMap.hpp"
#include "../CameraController.hpp"
#include "../PrefabLibrary.hpp"
#include "../PrimitiveRenderer.hpp"

#include <algorithm>
#include <string>

namespace
{
constexpr float kParryWindowSec = 0.12f;
constexpr float kDodgeIFrameSec = 0.16f;
constexpr float kPerfectDodgeWindowSec = 0.08f;
}

ActorCommon::RuntimeActorPose PlayerActor::BuildRuntimePose(const CameraController& cameraController) const
{
    ActorCommon::RuntimeActorPose pose;
    pose.x = cameraController.GetPlayerX();
    pose.y = cameraController.GetPlayerGroundY();
    pose.z = cameraController.GetPlayerZ();
    pose.yaw = cameraController.GetYaw();
    pose.scale = 1.0f;
    return pose;
}

void PlayerActor::Update(float dt, const InputActionMap& input, bool isGrounded, bool attackPressed)
{
    stateTimer = (std::max)(0.0f, stateTimer - dt);
    parryWindowTimer = (std::max)(0.0f, parryWindowTimer - dt);
    dodgeIFrameTimer = (std::max)(0.0f, dodgeIFrameTimer - dt);
    perfectDodgeTimer = (std::max)(0.0f, perfectDodgeTimer - dt);

    if (!isGrounded)
    {
        if (state == PlayerActionState::Idle || state == PlayerActionState::Move)
            TransitionTo(PlayerActionState::Fall, 0.0f);
    }
    else if (state == PlayerActionState::Fall)
    {
        TransitionTo(PlayerActionState::Idle, 0.0f);
    }

    switch (state)
    {
    case PlayerActionState::Idle:
    case PlayerActionState::Move:
        // If Shift+F is pressed together, the combat system handles it as a Limit Break.
        // Only start a dodge when Shift is held without an attack input.
        if (input.IsHeld(InputAction::Dodge) && !attackPressed)
        {
            TransitionTo(PlayerActionState::Dodge, 0.35f);
        }
        else if (attackPressed)
        {
            // Attack start is handled by RuntimeScene::TriggerPlayerAttack().
        }
        break;

    case PlayerActionState::Attack1:
        if (stateTimer <= 0.0f)
            TransitionTo(PlayerActionState::Idle, 0.0f);
        break;

    case PlayerActionState::Attack2:
        if (stateTimer <= 0.0f)
            TransitionTo(PlayerActionState::Idle, 0.0f);
        break;

    case PlayerActionState::Dodge:
        if (stateTimer <= 0.0f)
            TransitionTo(PlayerActionState::Idle, 0.0f);
        break;

    case PlayerActionState::Stunned:
        if (stateTimer <= 0.0f)
            TransitionTo(stats.hp > 0.0f ? PlayerActionState::Idle
                                         : PlayerActionState::Dead, 0.0f);
        break;

    case PlayerActionState::Dead:
        break;

    default:
        break;
    }
}

void PlayerActor::TransitionTo(PlayerActionState next, float duration)
{
    state = next;
    stateTimer = duration;
    if (next == PlayerActionState::Dodge)
    {
        parryWindowTimer = kParryWindowSec;
        dodgeIFrameTimer = kDodgeIFrameSec;
        perfectDodgeTimer = kPerfectDodgeWindowSec;
        perfectDodgeTriggered = false;
    }
}

bool PlayerActor::ConsumePerfectDodgeTriggered()
{
    if (perfectDodgeTriggered || perfectDodgeTimer <= 0.0f)
        return false;

    perfectDodgeTriggered = true;
    return true;
}

void PlayerActor::SubmitRuntimeVisual(const CameraController& cameraController,
                                      const PrefabLibrary& prefabLibrary,
                                      PrimitiveRenderer& primitiveRenderer) const
{
    static const std::string kPlayerVisualPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
    const PrimitivePrefab* visualPrefab =
        prefabLibrary.GetPrefab(kPlayerVisualPrefabId);
    if (!visualPrefab)
        return;

    const ActorCommon::RuntimeActorPose pose = BuildRuntimePose(cameraController);
    primitiveRenderer.AddRuntimeInstance(*visualPrefab,
                                         pose.x, pose.y, pose.z,
                                         pose.yaw, pose.scale);
}

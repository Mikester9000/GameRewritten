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

    void Update(float dt, const InputActionMap& input, bool isGrounded, bool attackPressed);

    void SubmitRuntimeVisual(const CameraController& cameraController,
                             const PrefabLibrary& prefabLibrary,
                             PrimitiveRenderer& primitiveRenderer) const;

private:
    void TransitionTo(PlayerActionState next, float duration);
    ActorCommon::RuntimeActorPose BuildRuntimePose(const CameraController& cameraController) const;
};

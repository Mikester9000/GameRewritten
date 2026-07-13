// ============================================================
// FILE: src/game/actors/VehicleActor.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: VehicleActor module behavior and local implementation details.
// ============================================================

#pragma once

#include "ActorCommon.hpp"

class D3D11Renderer;
class PrefabLibrary;
class PrimitiveRenderer;

// A vehicle actor that can be driven or moved by the player.
// It handles its own movement physics (acceleration/deceleration) and state.
class VehicleActor
{
public:
    // World-space transform.
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float yaw = 0.0f;

    // Movement properties.
    float maxSpeed = 15.0f;
    float acceleration = 20.0f;
    float deceleration = 15.0f;
    float currentSpeed = 0.0f;

    // Vehicle states.
    enum class VehicleState
    {
        Idle,
        Moving,
        Driving, // Could be used for specific behaviors like "on road"
        Stalled
    };

    VehicleState state = VehicleState::Idle;
    float stateTimer = 0.0f;

    // Vehicle specific data.
    const char* name = "Vehicle";
    bool isOccupied = false;

    // Initialization.
    void Init(float startX, float startZ, float startYaw = 0.0f, float startSpeed = 0.0f);

    // Advance state machine and update movement.
    // playerInputX/Y represent the steering/throttle inputs.
    void Update(float dt, D3D11Renderer& renderer,
                float playerInputX, float playerInputY,
                float playerX, float playerZ);

    // Submit visual to the runtime renderer.
    // Reuses the player blockout prefab or a dedicated vehicle prefab if available.
    void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
                             PrimitiveRenderer&   primitiveRenderer) const;

private:
    void TransitionTo(VehicleState next, float duration);

    // Internal helper for movement.
    void ApplyMovement(float dt, float inputX, float inputY);
};

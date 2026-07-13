// ============================================================
// FILE: src/game/actors/VehicleActor.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: VehicleActor module behavior and local implementation details.
// ============================================================

// VehicleActor.cpp
// Implements vehicle movement physics, state machine, and visual submission.

#include "VehicleActor.hpp"

#include "../PrefabLibrary.hpp"
#include "../PrimitiveRenderer.hpp"
#include "../../rendering/d3d11/D3D11Renderer.hpp"

#include <logger/Logger.hpp>
#include <cmath>
#include <string>

void VehicleActor::Init(float startX, float startZ, float startYaw, float startSpeed)
{
    x = startX;
    y = 0.0f;
    z = startZ;
    yaw = startYaw;
    currentSpeed = startSpeed;
    name = "Vehicle";
    state = VehicleState::Idle;
    stateTimer = 0.0f;
    isOccupied = false;
}

void VehicleActor::TransitionTo(VehicleState next, float duration)
{
    state = next;
    stateTimer = duration;
}

void VehicleActor::ApplyMovement(float dt, float inputX, float inputY)
{
    // inputX: steering (-1.0 to 1.0)
    // inputY: throttle (0.0 to 1.0)

    // Basic acceleration/deceleration
    if (inputY > 0.1f)
    {
        if (currentSpeed < maxSpeed)
            currentSpeed += acceleration * dt;
    }
    else if (inputY < -0.1f)
    {
        if (currentSpeed > -maxSpeed)
            currentSpeed -= acceleration * dt;
    }
    else
    {
        if (currentSpeed > 0.0f)
            currentSpeed -= deceleration * dt;
        else if (currentSpeed < 0.0f)
            currentSpeed += deceleration * dt;
    }

    // Clamp speed
    if (currentSpeed > maxSpeed) currentSpeed = maxSpeed;
    if (currentSpeed < -maxSpeed) currentSpeed = -maxSpeed;

    // Apply velocity to position
    // Forward vector is (sin(yaw), 0, cos(yaw))
    float forwardX = sinf(yaw);
    float forwardZ = cosf(yaw);

    x += forwardX * currentSpeed * dt;
    z += forwardZ * currentSpeed * dt;

    // Apply steering
    if (fabsf(currentSpeed) > 0.1f)
    {
        // Steering is more effective at speed
        float steerFactor = (currentSpeed > 0.0f) ? 1.0f : -1.0f;
        yaw += inputX * steerFactor * (currentSpeed / maxSpeed) * 2.0f * dt;
    }
}

void VehicleActor::Update(float dt, D3D11Renderer& renderer,
                        float playerInputX, float playerInputY,
                        float playerX, float playerZ)
{
    // State machine logic
    if (stateTimer > 0.0f)
    {
        stateTimer -= dt;
        if (stateTimer <= 0.0f)
        {
            // Handle transitions based on state
            if (state == VehicleState::Idle && (playerInputX != 0.0f || playerInputY != 0.0f))
            {
                TransitionTo(VehicleState::Moving, 0.0f);
            }
            else if (state == VehicleState::Moving && (playerInputX == 0.0f && playerInputY == 0.0f))
            {
                TransitionTo(VehicleState::Idle, 0.0f);
            }
        }
    }

    // Apply movement inputs
    ApplyMovement(dt, playerInputX, playerInputY);

    // Terrain snap
    if (renderer.IsTerrainAvailable())
    {
        y = renderer.SampleTerrainHeight(x, z);
    }
}

void VehicleActor::SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
                                      PrimitiveRenderer&   primitiveRenderer) const
{
    // Reuses the player blockout prefab for vehicle visuals for now.
    static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
    const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);

    if (!visualPrefab)
        return;

    // We can scale the vehicle slightly to distinguish it from the player if needed.
    float scale = 1.5f;

    // For a vehicle, we might want a different yaw behavior or scaling,
    // but for now, we follow the same pattern.
    primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, scale, true);
}

#pragma once
// RuntimeScene.hpp
// Coordinates per-frame runtime actor update and visual submission.
//
// Responsibility:
//   Update runtime actor state, clear the runtime instance bucket at the start
//   of each frame, then submit all registered actor visuals so the primitive
//   renderer has fresh data.
//
// Add new actor types (enemies, NPCs) by storing them here and calling their
// Update() in BeginFrame() and SubmitRuntimeVisual() in SubmitActors().
//
// Usage:
//   RuntimeScene scene(playerActor, primRenderer);
//   scene.InitEnemies(spawnCenterX, spawnCenterZ);
//   // each frame:
//   scene.BeginPlayerFrame(deltaTime, actionMap, camController.IsGrounded(), attackPressed, camController);
//   scene.BeginFrame(deltaTime, renderer);
//   scene.SubmitActors(camController, prefabLibrary);

#include "actors/PlayerActor.hpp"
#include "actors/EnemyActor.hpp"
#include "PrimitiveRenderer.hpp"
#include "combat/CombatSystem.hpp"
#include "CameraController.hpp"
#include "../app/InputActionMap.hpp"
#include <cmath>
#include <logger/Logger.hpp>

// Forward-declared to avoid pulling their full headers into every file that
// includes RuntimeScene.
class D3D11Renderer;
class PrefabLibrary;

class RuntimeScene
{
public:
    RuntimeScene(PlayerActor& player, PrimitiveRenderer& primRenderer)
        : m_player(player), m_primRenderer(primRenderer) {}

    // Place two patrol enemies near the player's spawn center.
    // Call once after camController.Init().
    void InitEnemies(float centerX, float centerZ)
    {
        // Enemy 0 patrols east-west; starts at the midpoint of the route.
        m_enemies[0].Init(centerX + 20.0f, centerZ + 10.0f,
                          centerX + 10.0f, centerZ + 10.0f,
                          centerX + 30.0f, centerZ + 10.0f);

        // Enemy 1 patrols north-south; starts at the midpoint of the route.
        m_enemies[1].Init(centerX + 10.0f, centerZ + 40.0f,
                          centerX + 10.0f, centerZ + 30.0f,
                          centerX + 10.0f, centerZ + 50.0f);
    }
    float m_lastMoveDirX = 0.0f;
    float m_lastMoveDirZ = 1.0f; // default facing forward

    // Update player state and trigger one-shot dodge bursts before camera movement.
    // This ordering avoids a one-frame latency before dodge movement starts.
    void BeginPlayerFrame(float dt,
        const InputActionMap& actionMap,
        bool isGrounded,
        bool attackPressed,
        CameraController& camController)
    {
        m_player.stats.Update(dt);
        m_player.Update(dt, actionMap, isGrounded, attackPressed);

        // Track last known movement direction so dodge can use it as fallback
        const float yaw = camController.GetYaw();
        const float forwardX = sinf(yaw);
        const float forwardZ = cosf(yaw);
        const float rightX = cosf(yaw);
        const float rightZ = -sinf(yaw);

        float moveDirX = 0.0f;
        float moveDirZ = 0.0f;
        if (actionMap.IsHeld(InputAction::MoveForward)) { moveDirX += forwardX; moveDirZ += forwardZ; }
        if (actionMap.IsHeld(InputAction::MoveBack)) { moveDirX -= forwardX; moveDirZ -= forwardZ; }
        if (actionMap.IsHeld(InputAction::MoveLeft)) { moveDirX -= rightX;   moveDirZ -= rightZ; }
        if (actionMap.IsHeld(InputAction::MoveRight)) { moveDirX += rightX;   moveDirZ += rightZ; }

        // Only update last move dir when the player is actually moving
        const float moveLenSq = (moveDirX * moveDirX) + (moveDirZ * moveDirZ);
        if (moveLenSq > 1e-6f)
        {
            m_lastMoveDirX = moveDirX;
            m_lastMoveDirZ = moveDirZ;
        }

        // Trigger the burst once when Dodge starts
        if (m_player.state == PlayerActionState::Dodge &&
            m_player.stateTimer > 0.0f &&
            !camController.IsDodgeActive())
        {
            // Use current input dir if held, otherwise use last known movement direction
            float dodgeDirX = (moveLenSq > 1e-6f) ? moveDirX : m_lastMoveDirX;
            float dodgeDirZ = (moveLenSq > 1e-6f) ? moveDirZ : m_lastMoveDirZ;

            camController.BeginDodge(dodgeDirX, dodgeDirZ);
        }
    }

    // Update runtime actor state and clear all dynamic/runtime instance buckets.
    // Call once each frame after BeginPlayerFrame(), before submitting actor visuals.
    void BeginFrame(float dt, D3D11Renderer& renderer)
    {

        m_primRenderer.ClearRuntimeInstances();

        for (EnemyActor& enemy : m_enemies)
            enemy.Update(dt, renderer);

        m_combatSystem.Update(dt, m_enemies, kEnemyCount);
    }

    // Submit visual representations for all registered runtime actors.
    // Call after BeginFrame(), before drawing.
    void SubmitActors(const CameraController& camController,
                      const PrefabLibrary& prefabLibrary)
    {
        m_player.SubmitRuntimeVisual(camController, prefabLibrary, m_primRenderer);

        for (const EnemyActor& enemy : m_enemies)
            enemy.SubmitRuntimeVisual(prefabLibrary, m_primRenderer);
    }

    // Spawn a hitbox for the current combo step.
    // Step 1 requires ATB; step 2 chains within the combo window, ATB not required.
    // Returns true if an attack was triggered.
    bool TriggerPlayerAttack(const CameraController& camController)
    {
        const float yaw = camController.GetYaw();
        const float px  = camController.GetPlayerX();
        const float py  = camController.GetPlayerGroundY() + 1.0f; // mid-body height
        const float pz  = camController.GetPlayerZ();

        if (m_combatSystem.comboStep == 0)
        {
            // Step 1 — requires ATB.
            if (!m_player.stats.IsAtbReady())
                return false;

            m_player.stats.atbCharge = 0.0f;
            m_combatSystem.TriggerAttack(px, py, pz, yaw, 1);
            m_player.state      = PlayerActionState::Attack1;
            m_player.stateTimer = 0.40f;
            LOG_INFO("RuntimeScene: Player attack step 1 triggered.");
            return true;
        }
        else if (m_combatSystem.comboStep == 1 && m_combatSystem.comboTimer > 0.0f)
        {
            // Step 2 — ATB not required; chains within the combo window.
            m_player.stats.atbCharge = 0.0f;
            m_combatSystem.TriggerAttack(px, py, pz, yaw, 2);
            m_player.state      = PlayerActionState::Attack2;
            m_player.stateTimer = 0.40f;
            LOG_INFO("RuntimeScene: Player attack step 2 triggered.");
            return true;
        }

        return false;
    }

private:
    static constexpr int kEnemyCount = 2;

    PlayerActor&       m_player;
    PrimitiveRenderer& m_primRenderer;
    EnemyActor         m_enemies[kEnemyCount];
    CombatSystem       m_combatSystem;
};

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
//   scene.BeginFrame(deltaTime, renderer, playerX, playerY, playerZ);
//   scene.damageNumbers.Update(deltaTime);
//   scene.SubmitActors(camController, prefabLibrary);

#include "actors/PlayerActor.hpp"
#include "actors/EnemyActor.hpp"
#include "PrimitiveRenderer.hpp"
#include "combat/CombatSystem.hpp"
#include "combat/Targeting.hpp"
#include "CameraController.hpp"
#include "../ui/DamageNumbers.hpp"
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
    // Stores the spawn center for later player respawns.
    // Call once after camController.Init().
    void InitEnemies(float centerX, float centerZ)
    {
        m_spawnCenterX = centerX;
        m_spawnCenterZ = centerZ;

        // Enemy 0 patrols east-west; starts at the midpoint of the route.
        m_enemies[0].Init(centerX + 20.0f, centerZ + 10.0f,
                          centerX + 10.0f, centerZ + 10.0f,
                          centerX + 30.0f, centerZ + 10.0f);

        // Enemy 1 patrols north-south; starts at the midpoint of the route.
        m_enemies[1].Init(centerX + 10.0f, centerZ + 40.0f,
                          centerX + 10.0f, centerZ + 30.0f,
                          centerX + 10.0f, centerZ + 50.0f);
    }

    DamageNumbers damageNumbers;

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
    // playerX/Y/Z must be the player's current position AFTER camController.Update()
    // has run this frame, so enemy AI sees an up-to-date position.
    // playerY is the eye-level Y (CameraController::GetPlayerY()).
    // Call once each frame after camController.Update(), before submitting actor visuals.
    // Implementation lives in RuntimeScene.cpp.
    void BeginFrame(float dt, D3D11Renderer& renderer,
                    float playerX, float playerY, float playerZ);

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
    // Both combo steps are always free — no Surge required.
    // Returns true if an attack was triggered.
    bool TriggerPlayerAttack(const CameraController& camController)
    {
        const float px  = camController.GetPlayerX();
        const float py  = camController.GetPlayerGroundY() + 1.0f; // mid-body height
        const float pz  = camController.GetPlayerZ();
        const float yaw = GetAttackYaw(camController);

        if (m_combatSystem.comboStep == 0)
        {
            // Step 1 — only allowed from Idle or Move while grounded.
            const PlayerActionState s = m_player.state;
            if (s != PlayerActionState::Idle && s != PlayerActionState::Move)
                return false;
            if (!camController.IsGrounded())
                return false;

            m_combatSystem.TriggerAttack(px, py, pz, yaw, 1);
            m_player.state      = PlayerActionState::Attack1;
            m_player.stateTimer = 0.40f;
            LOG_INFO("RuntimeScene: Player attack step 1 triggered.");
            return true;
        }
        else if (m_combatSystem.comboStep == 1 && m_combatSystem.comboTimer > 0.0f)
        {
            // Step 2 — allowed from Attack1, Idle, or Move during the combo window.
            const PlayerActionState s = m_player.state;
            if (s != PlayerActionState::Attack1 &&
                s != PlayerActionState::Idle    &&
                s != PlayerActionState::Move)
                return false;

            m_combatSystem.TriggerAttack(px, py, pz, yaw, 2);
            m_player.state      = PlayerActionState::Attack2;
            m_player.stateTimer = 0.40f;
            LOG_INFO("RuntimeScene: Player attack step 2 triggered.");
            return true;
        }

        return false;
    }

    // Fire a Surge Strike — a powerful single hit that spends the full Surge bar.
    // Requires Idle or Move state, grounded, and full Surge.
    // Returns true if fired.
    bool TriggerSurgeStrike(const CameraController& camController)
    {
        const PlayerActionState s = m_player.state;
        if (s != PlayerActionState::Idle && s != PlayerActionState::Move)
            return false;
        if (!camController.IsGrounded())
            return false;
        if (!m_player.stats.IsSurgeReady())
            return false;

        const float px  = camController.GetPlayerX();
        const float py  = camController.GetPlayerGroundY() + 1.0f;
        const float pz  = camController.GetPlayerZ();
        const float yaw = GetAttackYaw(camController);

        m_player.stats.SpendSurge();
        m_combatSystem.TriggerAttack(px, py, pz, yaw, 3);
        m_player.state      = PlayerActionState::Attack2;
        m_player.stateTimer = 0.50f;
        LOG_INFO("RuntimeScene: Surge Strike triggered.");
        return true;
    }

    // Fire a Limit Break — the strongest hit; spends the full Limit bar and grants bonus Surge.
    // Requires Idle or Move state, grounded, and full Limit charge.
    // Returns true if fired.
    bool TriggerLimitBreak(const CameraController& camController)
    {
        const PlayerActionState s = m_player.state;
        if (s != PlayerActionState::Idle && s != PlayerActionState::Move)
            return false;
        if (!camController.IsGrounded())
            return false;
        if (!m_player.stats.IsLimitReady())
            return false;

        const float px  = camController.GetPlayerX();
        const float py  = camController.GetPlayerGroundY() + 1.0f;
        const float pz  = camController.GetPlayerZ();
        const float yaw = GetAttackYaw(camController);

        m_player.stats.SpendLimit();
        m_player.stats.AddSurge(0.50f); // half a Surge bar as bonus for landing Limit Break
        m_combatSystem.TriggerAttack(px, py, pz, yaw, 4);
        m_player.state      = PlayerActionState::Attack2;
        m_player.stateTimer = 0.60f;
        LOG_INFO("RuntimeScene: Limit Break triggered.");
        return true;
    }

    // Returns true when the player was defeated this frame and needs to be
    // teleported back to spawn. Call once per frame after BeginFrame().
    bool WantsRespawn() const { return m_wantsRespawn; }

    // Spawn X/Z coordinates for player respawn (set from InitEnemies center).
    float GetRespawnX() const { return m_spawnCenterX; }
    float GetRespawnZ() const { return m_spawnCenterZ; }

    // Clear the respawn flag after Main.cpp has handled the teleport.
    void ClearRespawnFlag() { m_wantsRespawn = false; }

    // Read-only accessors for debug visualization and future systems.
    const CombatSystem& GetCombatSystem() const { return m_combatSystem; }
    const EnemyActor*   GetEnemies()      const { return m_enemies; }
    int                 GetEnemyCount()   const { return kEnemyCount; }
    const EnemyActor*   GetLockedTarget() const { return m_targeting.GetTarget(); }

    void ToggleLockOn(float playerX, float playerZ)
    {
        m_targeting.ToggleLockOn(m_enemies, kEnemyCount, playerX, playerZ);
    }

private:
    static constexpr int kEnemyCount = 2;

    // Enemy attack hitbox parameters.
    static constexpr float kEnemyAttackHalfX  = 1.2f;
    static constexpr float kEnemyAttackHalfY  = 1.0f;
    static constexpr float kEnemyAttackHalfZ  = 1.2f;
    static constexpr int   kEnemyAttackDamage = 2;

    // Player body AABB half-extents used for incoming damage checks.
    // Slightly larger than the movement collision box for fair hit detection.
    static constexpr float kPlayerHitHalfX = 0.5f;
    static constexpr float kPlayerHitHalfY = 1.0f;
    static constexpr float kPlayerHitHalfZ = 0.5f;
    // Eye-to-body-center offset: body center sits this many units below the
    // eye-level Y stored in m_playerY.
    static constexpr float kPlayerBodyCenterOffset = 0.5f;

    PlayerActor&       m_player;
    PrimitiveRenderer& m_primRenderer;
    EnemyActor         m_enemies[kEnemyCount];
    CombatSystem       m_combatSystem;
    Targeting          m_targeting;

    // Player position updated each frame in BeginFrame (after camController.Update()).
    float m_playerX = 0.0f;
    float m_playerY = 0.0f; // eye-level Y from CameraController::GetPlayerY()
    float m_playerZ = 0.0f;

    // Spawn center stored from InitEnemies() for player respawn.
    float m_spawnCenterX = 0.0f;
    float m_spawnCenterZ = 0.0f;

    // Set true when the player dies; cleared by Main.cpp after the camera teleport.
    bool m_wantsRespawn = false;

    // Accumulated damage from enemy attacks this frame (AABB-tested).
    int m_pendingEnemyDamage = 0;

    float m_lastMoveDirX = 0.0f;
    float m_lastMoveDirZ = 1.0f; // default facing forward

    // Returns true if the given hitbox overlaps the player's body AABB.
    // m_playerY is the camera eye level; body center is shifted down by kPlayerBodyCenterOffset.
    bool HitBoxOverlapsPlayer(const HitBox& hitBox) const
    {
        float bodyCenterY = m_playerY - kPlayerBodyCenterOffset;
        float distX = fabsf(m_playerX - hitBox.x);
        float distY = fabsf(bodyCenterY - hitBox.y);
        float distZ = fabsf(m_playerZ - hitBox.z);
        return (distX < kPlayerHitHalfX + hitBox.halfX) &&
               (distY < kPlayerHitHalfY + hitBox.halfY) &&
               (distZ < kPlayerHitHalfZ + hitBox.halfZ);
    }

    float GetAttackYaw(const CameraController& camController) const
    {
        const EnemyActor* lockedTarget = m_targeting.GetTarget();
        if (!lockedTarget)
            return camController.GetYaw();

        const float playerX = camController.GetPlayerX();
        const float playerZ = camController.GetPlayerZ();
        const float deltaX = lockedTarget->x - playerX;
        const float deltaZ = lockedTarget->z - playerZ;
        return atan2f(deltaX, deltaZ);
    }
};

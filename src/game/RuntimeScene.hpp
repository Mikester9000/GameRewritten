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
//   scene.SetDamageNumbers(&damageNumbers);   // optional: enables floating numbers
//   // each frame:
//   scene.BeginPlayerFrame(deltaTime, actionMap, camController.IsGrounded(), attackPressed, camController);
//   scene.BeginFrame(deltaTime, renderer, playerX, playerY, playerZ);
//   scene.SubmitActors(camController, prefabLibrary);

#include "actors/PlayerActor.hpp"
#include "actors/EnemyActor.hpp"
#include "PrimitiveRenderer.hpp"
#include "combat/CombatSystem.hpp"
#include "CameraController.hpp"
#include "../app/InputActionMap.hpp"
#include "../ui/DamageNumbers.hpp"
#include <cmath>
#include <string>
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

    // Provide a DamageNumbers instance so RuntimeScene can spawn floating
    // hit numbers directly. Call once after construction, before the loop.
    void SetDamageNumbers(DamageNumbers* dn) { m_damageNumbers = dn; }

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
    // playerX/Y/Z must be the player's current position AFTER camController.Update()
    // has run this frame, so enemy AI sees an up-to-date position.
    // playerY is the eye-level Y (CameraController::GetPlayerY()).
    // Call once each frame after camController.Update(), before submitting actor visuals.
    void BeginFrame(float dt, D3D11Renderer& renderer,
                    float playerX, float playerY, float playerZ)
    {
        // Cache the up-to-date player position for enemy AI and AABB checks.
        m_playerX = playerX;
        m_playerY = playerY;
        m_playerZ = playerZ;

        m_primRenderer.ClearRuntimeInstances();

        for (EnemyActor& enemy : m_enemies)
            enemy.Update(dt, renderer, m_playerX, m_playerZ);

        m_combatSystem.Update(dt, m_enemies, kEnemyCount);

        // Spawn floating damage numbers for player hits on enemies this frame.
        // This was previously done in Main.cpp; now RuntimeScene owns the wiring.
        if (m_damageNumbers)
        {
            const CombatSystem::EnemyHitRecord* hits = m_combatSystem.GetRecentEnemyHits();
            int hitCount = m_combatSystem.GetRecentEnemyHitCount();
            for (int i = 0; i < hitCount; ++i)
                m_damageNumbers->Spawn(hits[i].damage, hits[i].x, hits[i].y, hits[i].z);
        }

        // Check for enemy attack hitboxes spawned this frame.
        // Fix 2: Test the hitbox against the player AABB before accumulating damage.
        // Fix 3: Damage is consumed and applied here instead of being left for Main.cpp.
        for (EnemyActor& enemy : m_enemies)
        {
            if (!enemy.pendingAttack)
                continue;

            enemy.pendingAttack = false;

            HitBox hb;
            hb.x           = enemy.x;
            hb.y           = enemy.y + 1.0f;
            hb.z           = enemy.z;
            hb.halfX       = kEnemyAttackHalfX;
            hb.halfY       = kEnemyAttackHalfY;
            hb.halfZ       = kEnemyAttackHalfZ;
            hb.damage      = kEnemyAttackDamage;
            hb.framesToLive = kEnemyAttackFrameLifetime;

            // Only deal damage if the attack hitbox overlaps the player's body.
            if (HitBoxOverlapsPlayer(hb))
                m_pendingEnemyDamage += hb.damage;
        }

        // Apply accumulated enemy damage to the player.
        int totalDamage = m_pendingEnemyDamage;
        m_pendingEnemyDamage = 0;

        if (totalDamage > 0 &&
            m_player.state != PlayerActionState::Dead &&
            m_player.state != PlayerActionState::Dodge) // dodge grants invincibility
        {
            m_player.stats.TakeDamage(totalDamage);

            if (m_player.stats.IsDead())
            {
                // Restore stats and signal Main.cpp to teleport the camera.
                m_player.stats.hp         = m_player.stats.maxHp;
                m_player.stats.mp         = m_player.stats.maxMp;
                m_player.stats.atbCharge  = 0.0f;
                m_player.state            = PlayerActionState::Idle;
                m_player.stateTimer       = 0.0f;
                m_wantsRespawn            = true;
                LOG_INFO("RuntimeScene: Player defeated — respawning.");
            }
            else
            {
                m_player.state      = PlayerActionState::Stunned;
                m_player.stateTimer = 0.30f;
                std::string msg = "RuntimeScene: Player hit for ";
                msg += std::to_string(totalDamage);
                msg += " damage (HP ";
                msg += std::to_string(static_cast<int>(m_player.stats.hp));
                msg += " / ";
                msg += std::to_string(static_cast<int>(m_player.stats.maxHp));
                msg += ").";
                LOG_INFO(msg);
            }
        }
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
            // Step 1 — only allowed from Idle or Move while grounded; requires ATB.
            const PlayerActionState s = m_player.state;
            if (s != PlayerActionState::Idle && s != PlayerActionState::Move)
                return false;
            if (!camController.IsGrounded())
                return false;
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
            // Step 2 — allowed from Attack1, Idle, or Move during the combo window; ATB not required.
            const PlayerActionState s = m_player.state;
            if (s != PlayerActionState::Attack1 &&
                s != PlayerActionState::Idle    &&
                s != PlayerActionState::Move)
                return false;

            m_player.stats.atbCharge = 0.0f;
            m_combatSystem.TriggerAttack(px, py, pz, yaw, 2);
            m_player.state      = PlayerActionState::Attack2;
            m_player.stateTimer = 0.40f;
            LOG_INFO("RuntimeScene: Player attack step 2 triggered.");
            return true;
        }

        return false;
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

private:
    static constexpr int kEnemyCount = 2;

    // Enemy attack hitbox parameters.
    static constexpr float kEnemyAttackHalfX        = 1.2f;
    static constexpr float kEnemyAttackHalfY        = 1.0f;
    static constexpr float kEnemyAttackHalfZ        = 1.2f;
    static constexpr int   kEnemyAttackDamage       = 2;
    static constexpr int   kEnemyAttackFrameLifetime = 3;

    // Player body AABB half-extents used for incoming damage checks.
    // Slightly larger than the movement collision box for fair hit detection.
    static constexpr float kPlayerHitHalfX = 0.5f;
    static constexpr float kPlayerHitHalfY = 1.0f;
    static constexpr float kPlayerHitHalfZ = 0.5f;

    PlayerActor&       m_player;
    PrimitiveRenderer& m_primRenderer;
    EnemyActor         m_enemies[kEnemyCount];
    CombatSystem       m_combatSystem;
    DamageNumbers*     m_damageNumbers = nullptr;

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

    // Returns true if the given hitbox overlaps the player's body AABB.
    // m_playerY is the camera eye level; body center is shifted down by 0.5 units.
    bool HitBoxOverlapsPlayer(const HitBox& hb) const
    {
        float bodyY = m_playerY - 0.5f;
        float dx = fabsf(m_playerX - hb.x);
        float dy = fabsf(bodyY     - hb.y);
        float dz = fabsf(m_playerZ - hb.z);
        return (dx < kPlayerHitHalfX + hb.halfX) &&
               (dy < kPlayerHitHalfY + hb.halfY) &&
               (dz < kPlayerHitHalfZ + hb.halfZ);
    }
};

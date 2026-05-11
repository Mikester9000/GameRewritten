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
//   scene.BeginFrame(deltaTime, actionMap, true, renderer);
//   scene.SubmitActors(camController, prefabLibrary);

#include "actors/PlayerActor.hpp"
#include "actors/EnemyActor.hpp"
#include "PrimitiveRenderer.hpp"
#include "../app/InputActionMap.hpp"
#include "combat/CombatSystem.hpp"
#include "CameraController.hpp"
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

    // Update runtime actor state and clear all dynamic/runtime instance buckets.
    // Call once at the start of each frame before submitting actor visuals.
    void BeginFrame(float dt, const InputActionMap& actionMap, bool isGrounded, D3D11Renderer& renderer)
    {
        m_player.stats.Update(dt);
        m_player.Update(dt, actionMap, isGrounded);
        m_primRenderer.ClearRuntimeInstances();

        for (EnemyActor& enemy : m_enemies)
            enemy.Update(dt, renderer);

        m_combatSystem.Update(m_enemies, kEnemyCount);
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

    // Spawn a short-lived hitbox 1.5 units in front of the player using camera yaw.
    // Only triggers if ATB is full; resets ATB to 0 after spawning.
    bool TriggerPlayerAttack(const CameraController& camController)
    {
        if (!m_player.stats.IsAtbReady())
            return false;

        const float yaw = camController.GetYaw();
        const float px  = camController.GetPlayerX();
        const float py  = camController.GetPlayerGroundY() + 1.0f; // mid-body height
        const float pz  = camController.GetPlayerZ();

        HitBox hb;
        hb.x = px + 1.5f * sinf(yaw);
        hb.y = py;
        hb.z = pz + 1.5f * cosf(yaw);
        hb.halfX = 0.75f;
        hb.halfY = 1.0f;
        hb.halfZ = 0.75f;
        hb.damage = 3;
        hb.framesToLive = 2;

        m_combatSystem.SpawnHitBox(hb);
        m_player.stats.atbCharge = 0.0f;

        LOG_INFO("RuntimeScene: Player attack triggered.");
        return true;
    }

private:
    static constexpr int kEnemyCount = 2;

    PlayerActor&       m_player;
    PrimitiveRenderer& m_primRenderer;
    EnemyActor         m_enemies[kEnemyCount];
    CombatSystem       m_combatSystem;
};

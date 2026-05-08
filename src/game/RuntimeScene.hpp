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
//   scene.BeginFrame(deltaTime, renderer);
//   scene.SubmitActors(camController, prefabLibrary);

#include "actors/PlayerActor.hpp"
#include "actors/EnemyActor.hpp"
#include "PrimitiveRenderer.hpp"

// Forward-declared to avoid pulling their full headers (and <windows.h> / d3d11.h)
// into every file that includes RuntimeScene.
class CameraController;
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
    void BeginFrame(float dt, D3D11Renderer& renderer)
    {
        m_player.stats.Update(dt);
        m_primRenderer.ClearRuntimeInstances();

        for (EnemyActor& enemy : m_enemies)
            enemy.Update(dt, renderer);
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

private:
    PlayerActor&       m_player;
    PrimitiveRenderer& m_primRenderer;
    EnemyActor         m_enemies[2];
};

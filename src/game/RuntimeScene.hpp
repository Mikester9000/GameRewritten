#pragma once
// RuntimeScene.hpp
// Coordinates per-frame runtime actor visual submission.
//
// Responsibility:
//   Clear the runtime instance bucket at the start of each frame, then submit
//   all registered actor visuals so the primitive renderer has fresh data.
//
// Add new actor types (enemies, NPCs) by storing a reference and calling their
// SubmitRuntimeVisual() inside SubmitActors().  Main.cpp stays untouched.
//
// Usage:
//   RuntimeScene scene(playerActor, primRenderer);
//   // each frame:
//   scene.BeginFrame();
//   scene.SubmitActors(camController, prefabLibrary);

#include "actors/PlayerActor.hpp"
#include "PrimitiveRenderer.hpp"

// Forward-declared to avoid pulling CameraController's <windows.h> dependency
// and PrefabLibrary's full definition into every file that includes RuntimeScene.
// Both are used only in SubmitActors() parameters.
class CameraController;
class PrefabLibrary;

class RuntimeScene
{
public:
    RuntimeScene(PlayerActor& player, PrimitiveRenderer& primRenderer)
        : m_player(player), m_primRenderer(primRenderer) {}

    // Clear all dynamic/runtime instance buckets.
    // Call once at the start of each frame before submitting actor visuals.
    void BeginFrame()
    {
        m_primRenderer.ClearRuntimeInstances();
    }

    // Submit visual representations for all registered runtime actors.
    // Call after BeginFrame(), before drawing.
    void SubmitActors(const CameraController& camController,
                      const PrefabLibrary& prefabLibrary)
    {
        m_player.SubmitRuntimeVisual(camController, prefabLibrary, m_primRenderer);
    }

private:
    PlayerActor&       m_player;
    PrimitiveRenderer& m_primRenderer;
};

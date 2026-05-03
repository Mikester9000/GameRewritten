#pragma once
// WorldEditor.hpp
// ImGui "World Editor" panel — lets you click to place prefab instances on the ground.
//
// How to use:
//   1. Call SetReferences() once after all systems are initialised.
//   2. Call DrawPanel() inside an ImGui frame (between BeginFrame and EndFrame).
//   3. Call HandlePlacement() each frame (before BeginFrame is fine) to process clicks.
//   4. Call SpawnCellInstances() after loading or reloading a cell to show persisted instances.

// Use an include guard for WIN32_LEAN_AND_MEAN rather than unconditionally
// redefining it here, to avoid macro-redefinition warnings when other
// translation units (or build settings) have already defined it.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <string>
#include <vector>

class AssetRegistry;
class WorldGrid;
class Forest;
class D3D11Renderer;
class CameraController;

class WorldEditor
{
public:
    // Bind external systems.  Must be called before DrawPanel() / HandlePlacement().
    void SetReferences(AssetRegistry* registry, WorldGrid* grid, Forest* forest);

    // Draw the "World Editor" ImGui panel.  Call this inside an ImGui frame.
    // playerCX/playerCZ = current grid cell the player is in (shown in the panel).
    void DrawPanel(int playerCX, int playerCZ, D3D11Renderer& renderer);

    // Try to place an instance at the mouse click position.
    // screenPos = client-space pixel coords of the click.
    // vpW/vpH   = viewport width/height (== render resolution).
    // activeCX/activeCZ = grid cell to add the instance to.
    // Returns true if placement succeeded.
    bool HandlePlacement(POINT screenPos,
                         float vpW, float vpH,
                         const CameraController& cam,
                         D3D11Renderer& renderer,
                         int activeCX, int activeCZ);

    // Spawn all authored instances from the given cell into the forest so they appear
    // in the world.  Call after Populate() so persisted objects are always visible.
    void SpawnCellInstances(int cx, int cz, D3D11Renderer& renderer);

    // Returns true while Placement Mode is active.
    bool IsPlacementModeActive() const { return m_placementMode; }

    // Re-read the prefab list from the AssetRegistry (call after reload).
    void RefreshPrefabList();

private:
    bool m_placementMode = false;

    std::vector<std::string> m_prefabIds;   // IDs beginning with "prefabs." (sorted)
    std::string m_selectedPrefabId;         // the currently-selected prefab ID (stable across reloads)

    AssetRegistry* m_registry = nullptr;
    WorldGrid*     m_grid     = nullptr;
    Forest*        m_forest   = nullptr;
};

// ============================================================
// FILE: src/app/WorldEditorFrameOps.hpp
// SYSTEM: WorldEditorFrameOps.hpp
// SYSTEM: app startup/shutdown wiring and frame orchestration

#pragma once
// WorldEditorFrameOps.hpp
// App-layer helpers for per-frame World Editor interactions.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include "../game/CameraController.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../ui/WorldEditor.hpp"
#include "../world/WorldGrid.hpp"

#include "../../third_party/imgui/imgui.h"

namespace WorldEditorFrameOps
{
struct PlacementResult
{
    // True when a click actually placed or deleted a cell instance.
    bool editedCellInstances = false;
    // Active cell coordinates used for that click attempt.
    int activeCellX = 0;
    int activeCellZ = 0;
};

inline void GetActiveCellFromPlayer(const WorldGrid& worldGrid,
                                    const CameraController& camController,
                                    int& outCellX,
                                    int& outCellZ)
{
    worldGrid.WorldToCell(camController.GetPlayerX(), camController.GetPlayerZ(), outCellX, outCellZ);
}

inline PlacementResult HandlePlacementClick(HWND windowHandle,
                                            bool leftButtonClicked,
                                            bool editorActive,
                                            WorldEditor& worldEditor,
                                            const WorldGrid& worldGrid,
                                            const CameraController& camController,
                                            D3D11Renderer& renderer)
{
    PlacementResult result{};

    // Use ImGui::GetIO().WantCaptureMouse as input-capture state for this click-processing phase.
    if (!leftButtonClicked || !editorActive || ImGui::GetIO().WantCaptureMouse)
        return result;

    // Get cursor position in window client coordinates.
    POINT clickPos{};
    GetCursorPos(&clickPos);
    ScreenToClient(windowHandle, &clickPos);

    // Determine active grid coordinates from player position.
    GetActiveCellFromPlayer(worldGrid, camController, result.activeCellX, result.activeCellZ);

    result.editedCellInstances = worldEditor.HandlePlacement(
        clickPos,
        static_cast<float>(renderer.GetRenderWidth()),
        static_cast<float>(renderer.GetRenderHeight()),
        camController, renderer,
        result.activeCellX, result.activeCellZ);
    return result;
}

inline void DrawEditorPanelForActiveCell(WorldEditor& worldEditor,
                                         const WorldGrid& worldGrid,
                                         const CameraController& camController,
                                         D3D11Renderer& renderer)
{
    int activeCX = 0, activeCZ = 0;
    GetActiveCellFromPlayer(worldGrid, camController, activeCX, activeCZ);
    worldEditor.DrawPanel(activeCX, activeCZ, renderer);
}
}

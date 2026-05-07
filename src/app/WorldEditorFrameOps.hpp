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
inline void GetActiveCellFromPlayer(const WorldGrid& worldGrid,
                                    const CameraController& camController,
                                    int& outCX,
                                    int& outCZ)
{
    worldGrid.WorldToCell(camController.GetPlayerX(), camController.GetPlayerZ(), outCX, outCZ);
}

inline void HandlePlacementClick(HWND windowHandle,
                                 bool leftButtonClicked,
                                 bool editorActive,
                                 WorldEditor& worldEditor,
                                 const WorldGrid& worldGrid,
                                 const CameraController& camController,
                                 D3D11Renderer& renderer)
{
    // Check ImGui::GetIO().WantCaptureMouse for input capture from previous frame.
    if (!leftButtonClicked || !editorActive || ImGui::GetIO().WantCaptureMouse)
        return;

    // Get cursor position in window client coordinates.
    POINT clickPos{};
    GetCursorPos(&clickPos);
    ScreenToClient(windowHandle, &clickPos);

    // Determine active grid coordinates from player position.
    int activeCX = 0, activeCZ = 0;
    GetActiveCellFromPlayer(worldGrid, camController, activeCX, activeCZ);

    worldEditor.HandlePlacement(
        clickPos,
        static_cast<float>(renderer.GetRenderWidth()),
        static_cast<float>(renderer.GetRenderHeight()),
        camController, renderer,
        activeCX, activeCZ);
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

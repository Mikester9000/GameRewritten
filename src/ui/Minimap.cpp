// ============================================================
// FILE: src/ui/Minimap.cpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: Minimap module behavior and local implementation details.
// ============================================================

// Minimap.cpp
// ImGui draw-list minimap showing nearby world cells, player position, and facing direction.

#include "Minimap.hpp"
#include "../world/WorldGrid.hpp"

#include <imgui.h>
#include <cstdint>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

namespace
{
// Layout constants.
constexpr float kMapSize    = 160.0f;   // minimap window width and height
constexpr float kMapPadding = 10.0f;    // gap from screen top-right edge
constexpr int   kGridRadius = 2;        // 5x5 cell grid (radius 2 from player cell)
constexpr int   kGridDim    = kGridRadius * 2 + 1; // 5
constexpr float kCellPx     = kMapSize / static_cast<float>(kGridDim); // pixels per cell
constexpr ImU32 kFogFillColor = IM_COL32(18, 18, 22, 235);
constexpr ImU32 kFogBorderColor = IM_COL32(0, 0, 0, 180);

// Return a fill color for a given biome name.
ImU32 BiomeColor(const std::string& biome)
{
    static const std::unordered_map<std::string, ImU32> kBiomeColors = {
        { "grassland", IM_COL32( 30,  90,  30, 220) },
        { "forest",    IM_COL32( 50,  80,  20, 220) },
        { "desert",    IM_COL32(210, 180, 100, 220) },
        { "rocky",     IM_COL32(120, 110, 100, 220) },
        { "snow",      IM_COL32(220, 230, 240, 220) },
    };
    const auto it = kBiomeColors.find(biome);
    if (it != kBiomeColors.end())
        return it->second;
    // Truly unknown biome name — not the same as an unloaded cell.
    return IM_COL32(100, 100, 110, 200);
}

// Find a cell matching (cx, cz) in a pre-fetched list, or nullptr if absent.
const WorldCell* FindInList(const std::vector<WorldCell>& cells, int cx, int cz)
{
    for (const auto& c : cells)
        if (c.cx == cx && c.cz == cz)
            return &c;
    return nullptr;
}

unsigned long long PackCellKey(int cx, int cz)
{
    return (static_cast<unsigned long long>(static_cast<std::uint32_t>(cx)) << 32ull) |
           static_cast<unsigned long long>(static_cast<std::uint32_t>(cz));
}
} // namespace

void Minimap::Draw(const WorldGrid& grid,
                   float playerX, float playerZ, float playerYaw,
                   const ImGuiIO& io)
{
    // Determine the player's current cell.
    int playerCX = 0, playerCZ = 0;
    grid.WorldToCell(playerX, playerZ, playerCX, playerCZ);
    m_visitedCells.insert(PackCellKey(playerCX, playerCZ));

    // Fetch the 5x5 region of loaded cells around the player.
    const std::vector<WorldCell> nearby = grid.GetActiveCells(playerCX, playerCZ, kGridRadius);

    // Pin the window to the top-right corner.
    const float winX = io.DisplaySize.x - kMapSize - kMapPadding;
    const float winY = kMapPadding;

    ImGui::SetNextWindowPos(ImVec2(winX, winY), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(kMapSize, kMapSize), ImGuiCond_Always);
    ImGui::SetNextWindowBgAlpha(0.65f);
    // Zero out window padding so the draw-list grid fills the full 160x160 area
    // without clipping or misalignment caused by the default inner padding.
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    const ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration         |
        ImGuiWindowFlags_NoInputs             |
        ImGuiWindowFlags_NoNav                |
        ImGuiWindowFlags_NoMove               |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    const bool visible = ImGui::Begin("##Minimap", nullptr, flags);
    // Always pop immediately after Begin so the stack stays balanced
    // regardless of whether the window is visible or collapsed.
    ImGui::PopStyleVar();

    if (!visible)
    {
        ImGui::End();
        return;
    }

    ImDrawList* draw   = ImGui::GetWindowDrawList();
    const ImVec2 origin = ImGui::GetWindowPos();

    // Draw each cell in the 5x5 grid as a filled, bordered rectangle.
    for (int row = 0; row < kGridDim; ++row)
    {
        for (int col = 0; col < kGridDim; ++col)
        {
            const int cx = playerCX + (col - kGridRadius);
            const int cz = playerCZ + (row - kGridRadius);

            const float x0 = origin.x + static_cast<float>(col) * kCellPx;
            const float y0 = origin.y + static_cast<float>(row) * kCellPx;
            const float x1 = x0 + kCellPx;
            const float y1 = y0 + kCellPx;

            const WorldCell* cell      = FindInList(nearby, cx, cz);
            const bool       isVisited = m_visitedCells.find(PackCellKey(cx, cz)) != m_visitedCells.end();
            const ImU32      fillColor = (cell && isVisited)
                ? BiomeColor(cell->terrainBiome)
                : kFogFillColor;

            draw->AddRectFilled(ImVec2(x0, y0), ImVec2(x1, y1), fillColor);
            draw->AddRect(ImVec2(x0, y0), ImVec2(x1, y1),
                          isVisited ? IM_COL32(0, 0, 0, 140) : kFogBorderColor);
        }
    }

    // Compute the player's fractional position within their current cell (0..1).
    const float cellSize = grid.GetCellSize();
    const float fracX = (playerX - static_cast<float>(playerCX) * cellSize) / cellSize;
    const float fracZ = (playerZ - static_cast<float>(playerCZ) * cellSize) / cellSize;

    // Map to pixel coordinates. The player's cell occupies column/row kGridRadius.
    const float playerPxX = origin.x + (static_cast<float>(kGridRadius) + fracX) * kCellPx;
    const float playerPxY = origin.y + (static_cast<float>(kGridRadius) + fracZ) * kCellPx;

    // Facing direction: forward = (sin(yaw), cos(yaw)) in world XZ.
    // On the minimap X maps to screen-right, Z maps to screen-down.
    const float arrowLen = kCellPx * 0.45f;
    const float arrowDX  = sinf(playerYaw) * arrowLen;
    const float arrowDY  = cosf(playerYaw) * arrowLen;

    // Direction line from player dot toward facing direction.
    draw->AddLine(
        ImVec2(playerPxX, playerPxY),
        ImVec2(playerPxX + arrowDX, playerPxY + arrowDY),
        IM_COL32(255, 255, 255, 255), 2.0f);

    // Player position dot drawn on top of the direction line.
    draw->AddCircleFilled(ImVec2(playerPxX, playerPxY), 4.0f, IM_COL32(255, 255, 255, 255));

    ImGui::End();
}

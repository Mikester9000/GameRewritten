// ============================================================
// FILE: src/world/WorldMapOverlay.cpp
// SYSTEM: World / UI / Navigation
// ROLE: Implements WorldMapOverlay — world map UI with zoom and icons.
//
// FOR QWEN: Implement each TODO in order:
//   1. Open/Close/Toggle   — simple state changes
//   2. Initialize()        — register static icons, set world size
//   3. Update()            — track player position, animate cursor
//   4. WorldToMap()        — coordinate conversion (critical for accuracy)
//   5. MarkCellVisited()   — fog of war tracking
//   6. AddIcon/RemoveIcon  — icon registry management
//   7. RenderFogOfWar()    — draw grey rects over unexplored cells
//   8. RenderIcons()       — draw all icon circles and labels
//   9. Render()            — full map draw using ImGui draw list
//   10. ToggleZoom()       — cycle zoom levels
// ============================================================

#include "WorldMapOverlay.hpp"
#include "../game/world/DiscoveryJournal.hpp"
#include <algorithm>

// ImGui include (same path as the rest of the project)
#include "../../third_party/imgui/imgui.h"


// ============================================================
// ZOOM LEVEL CONFIGURATION
// World-space sizes visible at each zoom level.
// Level 0 shows the entire world; Level 2 shows a local area.
// ============================================================
static constexpr float kZoomSizes[3][2] = {
    { 1600.0f, 1600.0f }, // Level 0: full world view
    {  500.0f,  500.0f }, // Level 1: regional view (~5 cells)
    {  100.0f,  100.0f }, // Level 2: local detail view
};


// ============================================================
// CONSTRUCTOR
// ============================================================
WorldMapOverlay::WorldMapOverlay()
{
    m_icons.reserve(64);
    m_visitedCells.reserve(256);
}


// ============================================================
// Initialize
// ============================================================
void WorldMapOverlay::Initialize(float worldSizeX, float worldSizeZ, DiscoveryJournal* journal)
{
    m_worldSizeX = worldSizeX;
    m_worldSizeZ = worldSizeZ;
    m_journal    = journal;

    // Initialize visible area to full world (zoom level 0)
    m_visibleOriginX = 0.0f;
    m_visibleOriginZ = 0.0f;
    m_visibleSizeX   = worldSizeX;
    m_visibleSizeZ   = worldSizeZ;

    // TODO (Qwen): Register static fast travel icons from world data.
    // Example:
    //   MapIcon ftIcon;
    //   ftIcon.worldX = ...; ftIcon.worldZ = ...;
    //   ftIcon.type = MapIcon::Type::FastTravel;
    //   ftIcon.label = "Village of Ashford";
    //   ftIcon.discovered = false; // Unlocked when player visits
    //   AddIcon(ftIcon);
}


// ============================================================
// Open / Close / Toggle
// ============================================================
void WorldMapOverlay::Open()
{
    m_isOpen = true;
    // TODO (Qwen): Pause game time when map opens (or use separate UI timescale).
}

void WorldMapOverlay::Close()
{
    m_isOpen = false;
}

void WorldMapOverlay::Toggle()
{
    if (m_isOpen) Close(); else Open();
}


// ============================================================
// Update
// Track player position and sync discovered landmarks from journal.
// ============================================================
void WorldMapOverlay::Update(float playerX, float playerZ, float dt)
{
    m_playerX = playerX;
    m_playerZ = playerZ;

    // Update player icon position in icon list
    // TODO (Qwen): If player icon exists in m_icons, update its worldX/Z.
    //   Otherwise: always draw player separately in Render() since it always shows.

    // Sync discovered landmarks from journal
    if (m_journal)
    {
        // TODO (Qwen): For each entry in m_journal->GetAll() where visited=true,
        //   find or add a MapIcon::Landmark with matching label.
        //   Set discovered=true on existing icon.
    }

    (void)dt; // Used for future: animated pulsing icons
}


// ============================================================
// WorldToMap
// Converts world (X, Z) to map screen coordinates.
// Returns true if the position is within the visible map area.
//
// TODO (Qwen): Replace stub with proper coordinate mapping.
// ============================================================
bool WorldMapOverlay::WorldToMap(float worldX, float worldZ,
                                  float& outScreenX, float& outScreenY) const
{
    // Check visible area bounds
    if (worldX < m_visibleOriginX || worldX > m_visibleOriginX + m_visibleSizeX) return false;
    if (worldZ < m_visibleOriginZ || worldZ > m_visibleOriginZ + m_visibleSizeZ) return false;

    // Map world position to screen pixel within the map panel
    float nx = (worldX - m_visibleOriginX) / m_visibleSizeX; // [0,1]
    float nz = (worldZ - m_visibleOriginZ) / m_visibleSizeZ; // [0,1]

    outScreenX = m_mapOriginX + nx * m_mapWidthPx;
    outScreenY = m_mapOriginY + nz * m_mapHeightPx; // Z maps to screen Y

    return true;
}


// ============================================================
// ToggleZoom
// Cycles through zoom levels. Re-centers on player when zooming in.
// ============================================================
void WorldMapOverlay::ToggleZoom()
{
    m_zoomLevel = (m_zoomLevel + 1) % 3;

    float sizeX = kZoomSizes[m_zoomLevel][0];
    float sizeZ = kZoomSizes[m_zoomLevel][1];

    // Center the visible area on the player
    m_visibleOriginX = std::max(0.0f, m_playerX - sizeX * 0.5f);
    m_visibleOriginZ = std::max(0.0f, m_playerZ - sizeZ * 0.5f);

    // Clamp to world bounds
    m_visibleOriginX = std::min(m_visibleOriginX, m_worldSizeX - sizeX);
    m_visibleOriginZ = std::min(m_visibleOriginZ, m_worldSizeZ - sizeZ);
    m_visibleOriginX = std::max(0.0f, m_visibleOriginX);
    m_visibleOriginZ = std::max(0.0f, m_visibleOriginZ);

    m_visibleSizeX = sizeX;
    m_visibleSizeZ = sizeZ;
}


// ============================================================
// MarkCellVisited
// Registers a cell as visited (clears fog of war for that cell).
// ============================================================
void WorldMapOverlay::MarkCellVisited(int cellX, int cellZ)
{
    int key = cellX * 10000 + cellZ;
    // Only add if not already visited
    for (int existing : m_visitedCells)
        if (existing == key) return;
    m_visitedCells.push_back(key);
}


// ============================================================
// AddIcon / RemoveIcon
// ============================================================
void WorldMapOverlay::AddIcon(const MapIcon& icon)
{
    m_icons.push_back(icon);
}

void WorldMapOverlay::RemoveIcon(const std::string& label)
{
    m_icons.erase(
        std::remove_if(m_icons.begin(), m_icons.end(),
            [&](const MapIcon& i) { return i.label == label; }),
        m_icons.end());
}


// ============================================================
// RenderFogOfWar
// Draws grey rectangles over unexplored cells in the visible map area.
//
// TODO (Qwen): Implement cell iteration:
//   For each cell (cx, cz) in the visible map area:
//     key = cx * 10000 + cz
//     if key not in m_visitedCells:
//       draw grey rect at WorldToMap(cx*cellSize, cz*cellSize)
//   Use dl->AddRectFilled() with ImColor(0, 0, 0, 180) for fog.
// ============================================================
void WorldMapOverlay::RenderFogOfWar()
{
    // STUB: fog of war not yet rendered
    // TODO (Qwen): Implement grid iteration over visible cells.
}


// ============================================================
// RenderIcons
// Draws all registered map icons.
//
// TODO (Qwen): Implement for each icon in m_icons:
//   1. Skip if !icon.discovered && type != Player.
//   2. Call WorldToMap(icon.worldX, icon.worldZ, sx, sy).
//   3. Pick color by type:
//      Player: ImColor(255, 255,  50, 255) — bright yellow
//      Landmark: ImColor(100, 200, 255, 220) — light blue
//      FastTravel: ImColor(50, 255, 50, 220) — green
//      QuestMarker: ImColor(255, 180, 0, 255) — gold
//      Dungeon: ImColor(200, 50, 255, 220) — purple
//   4. dl->AddCircleFilled(ImVec2(sx, sy), 5.0f, color);
//   5. dl->AddText(ImVec2(sx+7, sy-6), IM_COL32(255,255,255,200), label.c_str());
// ============================================================
void WorldMapOverlay::RenderIcons()
{
    ImDrawList* dl = ImGui::GetWindowDrawList();
    if (!dl) return;

    // Draw player icon (always visible, no discovery check)
    float px, py;
    if (WorldToMap(m_playerX, m_playerZ, px, py))
    {
        // Bright pulsing yellow circle for player
        dl->AddCircleFilled(ImVec2(px, py), 7.0f, IM_COL32(255, 240, 40, 255));
        dl->AddCircle(ImVec2(px, py), 9.0f, IM_COL32(255, 255, 255, 180), 12, 1.5f);
    }

    // Draw registered icons
    for (const auto& icon : m_icons)
    {
        if (!icon.discovered && icon.type != MapIcon::Type::Player) continue;

        float sx, sy;
        if (!WorldToMap(icon.worldX, icon.worldZ, sx, sy)) continue;

        ImU32 color = IM_COL32(100, 200, 255, 220); // Default: landmark blue
        float radius = 5.0f;

        switch (icon.type)
        {
        case MapIcon::Type::FastTravel:
            color = IM_COL32(50, 255, 80, 220); radius = 5.0f; break;
        case MapIcon::Type::QuestMarker:
            color = IM_COL32(255, 180, 0, 255);  radius = 6.0f; break;
        case MapIcon::Type::Dungeon:
            color = IM_COL32(200, 50, 255, 220); radius = 5.0f; break;
        default: break;
        }

        dl->AddCircleFilled(ImVec2(sx, sy), radius, color);
        if (!icon.label.empty())
            dl->AddText(ImVec2(sx + 8.0f, sy - 7.0f),
                        IM_COL32(255, 255, 255, 200), icon.label.c_str());
    }
}


// ============================================================
// Render
// Full map overlay draw. Call inside ImGui frame each tick.
// ============================================================
void WorldMapOverlay::Render()
{
    if (!m_isOpen) return;

    // Fullscreen window
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::SetNextWindowBgAlpha(0.88f);
    ImGui::Begin("WorldMap", nullptr,
        ImGuiWindowFlags_NoDecoration  |
        ImGuiWindowFlags_NoMove        |
        ImGuiWindowFlags_NoSavedSettings);

    // Determine map panel position (centered)
    float mapSize = std::min(io.DisplaySize.x, io.DisplaySize.y) * 0.82f;
    m_mapWidthPx  = mapSize;
    m_mapHeightPx = mapSize;
    m_mapOriginX  = (io.DisplaySize.x - mapSize) * 0.5f;
    m_mapOriginY  = (io.DisplaySize.y - mapSize) * 0.5f;

    ImDrawList* dl = ImGui::GetWindowDrawList();

    // Map background (dark grey box as placeholder until texture is loaded)
    // TODO (Qwen): Replace AddRectFilled with AddImage(m_mapTextureSRV, ...) once
    //   the world map PNG is loaded by TextureCache.
    dl->AddRectFilled(
        ImVec2(m_mapOriginX, m_mapOriginY),
        ImVec2(m_mapOriginX + m_mapWidthPx, m_mapOriginY + m_mapHeightPx),
        IM_COL32(30, 35, 50, 255));

    // Map border
    dl->AddRect(
        ImVec2(m_mapOriginX, m_mapOriginY),
        ImVec2(m_mapOriginX + m_mapWidthPx, m_mapOriginY + m_mapHeightPx),
        IM_COL32(160, 160, 200, 200), 0.0f, 0, 2.0f);

    // Fog of war
    RenderFogOfWar();

    // Icons (landmarks, player, quests, etc.)
    RenderIcons();

    // Zoom level label (top-left of map)
    const char* zoomLabels[] = { "CONTINENT", "REGION", "LOCAL" };
    ImGui::SetCursorPos(ImVec2(m_mapOriginX + 8, m_mapOriginY + 6));
    ImGui::TextColored(ImVec4(0.8f, 0.85f, 1.0f, 1.0f), "[ %s ]", zoomLabels[m_zoomLevel]);

    // Close hint (bottom-center)
    const char* closeHint = "Press M to close  |  Scroll to zoom";
    ImGui::SetCursorPos(ImVec2(io.DisplaySize.x * 0.5f - 120.0f,
                                m_mapOriginY + m_mapHeightPx + 8.0f));
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.8f, 0.8f), "%s", closeHint);

    ImGui::End();
}

// ============================================================
// FILE: src/world/WorldMapOverlay.hpp
// SYSTEM: World / UI / Navigation
// ROLE: Manages the world map overlay UI — a full-screen or pause-menu
//   map that displays the known world at continent scale, supports zoom
//   levels (continent → region → local), and marks discovered landmarks,
//   quest markers, and fast travel points.
//
// INTEGRATION:
//   - Input system: pause button opens/closes the map overlay.
//   - DiscoveryJournal: feeds discovered landmark icons to the map.
//   - WorldGrid: provides cell/biome data for regional map drawing.
//   - ContinentTransition: provides continent boundaries for zoom-out view.
//   - QuestSystem: provides active quest waypoints (future).
//   - ImGui: renders map UI elements (icons, labels, zoom controls).
//
// MAP ZOOM LEVELS:
//   Level 0 (Continent): Shows full world map, all continents as labeled areas.
//   Level 1 (Region):    Shows a ~5x5 km region centered on player, with terrain.
//   Level 2 (Local):     Shows a ~1x1 km local area with detailed topology.
//   Player zooms in/out using scroll wheel or shoulder buttons.
//
// MAP CONTENT:
//   Fog of war: areas not yet visited are shown as grey/dark.
//     FogOfWar system (WorldGrid-adjacent) tracks visited cells.
//   Icons drawn on the map:
//     ■ Player position: bright icon at current world position.
//     ◆ Landmark: discovered landmarks from DiscoveryJournal.
//     ✦ Fast travel: unlocked fast travel points.
//     ◉ Active quest: quest waypoint (if quest is active).
//     ▲ Dungeon entrance / cave portal.
//
// RENDERING APPROACH (ImGui-based):
//   The map is drawn using ImGui::GetWindowDrawList() primitives:
//   - Background texture: pre-baked 512×512 world map PNG (Content/UI/world_map.png)
//   - Icons: ImGui::AddImage() or ImGui::AddCircleFilled() at mapped positions
//   - Fog: semi-transparent grey rectangles over unexplored cells
//   - Labels: ImGui::AddText() at landmark positions
//   World → screen mapping:
//     screenX = mapOriginX + (worldX / worldSizeX) * mapWidthPx
//     screenY = mapOriginY + (worldZ / worldSizeZ) * mapHeightPx
//
// FOR QWEN: Implement Open(), Close(), Render(), ToggleZoom() in WorldMapOverlay.cpp.
// ============================================================

#pragma once
#include <string>
#include <vector>

// Forward declarations
class DiscoveryJournal;
struct JournalEntry;

// ============================================================
// MapIcon
// Describes a single icon drawn on the world map.
// ============================================================
struct MapIcon
{
    enum class Type { Player, Landmark, FastTravel, QuestMarker, Dungeon };

    float   worldX    = 0.0f;
    float   worldZ    = 0.0f;
    Type    type      = Type::Landmark;
    std::string label;            // Text shown on hover
    bool    discovered = false;   // Only discovered icons are shown (except Player)
};


// ============================================================
// WorldMapOverlay
// ============================================================
class WorldMapOverlay
{
public:
    WorldMapOverlay();
    ~WorldMapOverlay() = default;

    // --------------------------------------------------------
    // Initialize
    //   worldSizeX, worldSizeZ: total world dimensions in world units.
    //     Determines the world→screen coordinate mapping.
    //   journal: pointer to DiscoveryJournal for landmark icons.
    //
    // TODO (Qwen): In Initialize(), register fast travel points and other
    //   static icons that don't change at runtime.
    // --------------------------------------------------------
    void Initialize(float worldSizeX, float worldSizeZ, DiscoveryJournal* journal);

    // --------------------------------------------------------
    // Open / Close / Toggle
    // Called by input system on pause/map button press.
    // --------------------------------------------------------
    void Open();
    void Close();
    void Toggle();
    bool IsOpen() const { return m_isOpen; }

    // --------------------------------------------------------
    // Update
    // Call every frame (even when closed) to animate icons, update
    // player position, etc.
    //   playerX, playerZ: current player world position.
    //   dt: frame delta time.
    // --------------------------------------------------------
    void Update(float playerX, float playerZ, float dt);

    // --------------------------------------------------------
    // Render
    // Draws the map overlay using ImGui.
    // Call inside the ImGui frame (after ImGui::NewFrame(), before ImGui::Render()).
    // Only draws when m_isOpen == true.
    //
    // Layout:
    //   - Full-screen transparent dark panel (semi-transparent 0.85 alpha).
    //   - Centered map image (512×512 or scaled to window).
    //   - Icons overlaid at mapped positions.
    //   - Zoom level indicator (top left): "CONTINENT / REGION / LOCAL".
    //   - Close button or press M to close instruction.
    //
    // TODO (Qwen): Implement using ImGui draw list:
    //   ImDrawList* dl = ImGui::GetWindowDrawList();
    //   dl->AddRectFilled(mapMin, mapMax, IM_COL32(0,0,0,220)); // dark bg
    //   dl->AddImage(m_mapTextureSRV, mapMin, mapMax);           // map texture
    //   for each icon: dl->AddCircleFilled(iconPos, 5.0f, iconColor);
    //   dl->AddText(labelPos, IM_COL32(255,255,255,200), icon.label.c_str());
    // --------------------------------------------------------
    void Render();

    // --------------------------------------------------------
    // ToggleZoom
    // Cycles through zoom levels: 0 → 1 → 2 → 0.
    // Changes the world-space area visible on the map.
    // Called by scroll wheel or shoulder button input.
    // --------------------------------------------------------
    void ToggleZoom();
    int GetZoomLevel() const { return m_zoomLevel; }

    // --------------------------------------------------------
    // AddIcon
    // Registers a custom map icon (e.g. from QuestSystem).
    // --------------------------------------------------------
    void AddIcon(const MapIcon& icon);

    // --------------------------------------------------------
    // RemoveIcon
    // Removes icon by label match (for quest completion etc.).
    // --------------------------------------------------------
    void RemoveIcon(const std::string& label);

    // --------------------------------------------------------
    // MarkCellVisited
    // Called by the exploration system when the player enters a new cell.
    // Clears fog of war for that cell.
    // --------------------------------------------------------
    void MarkCellVisited(int cellX, int cellZ);

private:
    // --------------------------------------------------------
    // WorldToMap
    // Converts a world (X, Z) position to map screen pixel coordinates.
    //   Returns false if the position is outside the visible map area.
    //
    // TODO (Qwen): Implement using current zoom level and pan offset.
    //   mapX = m_mapOriginX + ((worldX - m_visibleOriginX) / m_visibleSizeX) * m_mapWidthPx
    //   mapY = m_mapOriginY + ((worldZ - m_visibleOriginZ) / m_visibleSizeZ) * m_mapHeightPx
    // --------------------------------------------------------
    bool WorldToMap(float worldX, float worldZ,
                    float& outScreenX, float& outScreenY) const;

    // --------------------------------------------------------
    // RenderFogOfWar
    // Draws grey rectangles over unexplored cells.
    // TODO (Qwen): Iterate m_visitedCells; for each unvisited cell in map area,
    //   add a semi-transparent grey rectangle.
    // --------------------------------------------------------
    void RenderFogOfWar();

    // --------------------------------------------------------
    // RenderIcons
    // Draws all m_icons onto the map draw list.
    // TODO (Qwen): for each icon, call WorldToMap(), then add circle + label.
    // --------------------------------------------------------
    void RenderIcons();

    // State
    bool         m_isOpen     = false;
    int          m_zoomLevel  = 0;     // 0=continent, 1=region, 2=local
    float        m_playerX    = 0.0f;
    float        m_playerZ    = 0.0f;

    // World dimensions (for coordinate mapping)
    float        m_worldSizeX = 1600.0f;
    float        m_worldSizeZ = 1600.0f;

    // Visible area in world space at each zoom level
    //   Level 0: entire world
    //   Level 1: 500 × 500 world units
    //   Level 2: 100 × 100 world units
    float        m_visibleOriginX = 0.0f;
    float        m_visibleOriginZ = 0.0f;
    float        m_visibleSizeX   = 1600.0f;
    float        m_visibleSizeZ   = 1600.0f;

    // Map panel screen coordinates (set in Render() each frame)
    float        m_mapOriginX  = 0.0f;
    float        m_mapOriginY  = 0.0f;
    float        m_mapWidthPx  = 512.0f;
    float        m_mapHeightPx = 512.0f;

    // Icon registry
    std::vector<MapIcon> m_icons;

    // Fog of war — set of visited cell coords (packed: cellX*10000 + cellZ)
    std::vector<int>     m_visitedCells;

    // References (non-owning)
    DiscoveryJournal* m_journal = nullptr;

    // Map background texture (loaded from Content/UI/world_map.png)
    // TODO (Qwen): load via TextureCache and store SRV here.
    // void* m_mapTextureSRV = nullptr;
};

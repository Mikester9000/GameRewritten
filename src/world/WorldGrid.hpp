// ============================================================
// FILE: src/world/WorldGrid.hpp
// SYSTEM: World
// ROLE: world cells, biome data, and streaming structure
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: WorldGrid module behavior and local implementation details.
// ============================================================

#pragma once
// WorldGrid.hpp
// Loads Content/World/world.json and individual cell JSON files.
// Provides a minimal synchronous "stream cells around player" helper.
//
// A "cell" (WorldCell) is one chunk of the open world grid.
// cx, cz are integer grid coordinates; multiply by cellSize to get world-space origin.
//
// To add more cells later: add entries to world.json + add cell_X_Z.json files.

#include <string>
#include <vector>

// ---------------------------------------------------------------------------
// CellInstance
// ---------------------------------------------------------------------------
// One authored object placed inside a WorldCell via the World Editor.
struct CellInstance
{
    std::string prefab;    // scoped asset ID, e.g. "prefabs.tree"
    float x     = 0.0f;   // world-space position
    float y     = 0.0f;   // world-space position
    float z     = 0.0f;   // world-space position
    float yaw   = 0.0f;   // rotation around Y axis (radians)
    float scale = 1.0f;   // uniform scale
};

// ---------------------------------------------------------------------------
// WorldCell
// ---------------------------------------------------------------------------
// Describes one tile of the world grid.
struct WorldCell
{
    int   cx = 0;              // grid X index
    int   cz = 0;              // grid Z index
    float cellSize = 200.0f;   // world-space size of this cell (set from world.json)

    // Terrain settings for this cell
    bool        terrainEnabled    = true;
    std::string terrainBiome      = "grassland"; // grassland, desert, rocky, snow
    int         terrainSeed       = 12345;
    float       terrainHeightScale = 8.0f;
    float       terrainNoiseFreq  = 0.08f;
    float       terrainNoiseFreq2 = 0.03f;

    // Forest settings for this cell
    bool  forestEnabled   = true;
    int   forestTreeCount = 80;
    float forestRadius    = 50.0f;

    // Authored instances placed by the World Editor.
    std::vector<CellInstance> instances;

    // File path this cell was loaded from (used by WorldGrid::SaveCell).
    std::string filePath;

    // Convenience: world-space origin (bottom-left corner) of this cell.
    float OriginX() const { return cx * cellSize; }
    float OriginZ() const { return cz * cellSize; }
    float CenterX() const { return OriginX() + cellSize * 0.5f; }
    float CenterZ() const { return OriginZ() + cellSize * 0.5f; }
};

// ---------------------------------------------------------------------------
// WorldGrid
// ---------------------------------------------------------------------------
class WorldGrid
{
public:
    // Load the world manifest (e.g. "Content/World/world.json").
    // Returns true on success.
    bool Load(const std::string& worldJsonPath = "Content/World/world.json");

    // Reload from the same path used in Load().
    // Keeps the old grid if loading fails — no crash.
    bool Reload();

    // Returns cells that are within 'radius' cells of the player cell (cx, cz).
    // radius=1 gives a 3x3 block of cells (9 max), radius=0 gives only the player cell.
    std::vector<WorldCell> GetActiveCells(int playerCX, int playerCZ, int radius = 1) const;

    // Convert a world-space (X, Z) position into a cell grid coordinate.
    void WorldToCell(float worldX, float worldZ, int& outCX, int& outCZ) const;

    // --- Biome transition ---
    // Call when the player crosses into a new biome (e.g. on cell change).
    // Starts a smooth blend from the previous biome to the new one.
    void NotifyBiomeChange(const std::string& newBiome);

    // Advance the transition timer by dt real seconds.
    void UpdateBiomeTransition(float dt);

    // Alpha [0, 1] of the current biome — 0 = fully previous, 1 = fully arrived.
    float GetBiomeTransitionAlpha() const { return m_biomeBlendAlpha; }

    const std::string& GetCurrentBiome()  const { return m_currentBiome;  }
    const std::string& GetPreviousBiome() const { return m_previousBiome; }

    float       GetCellSize() const  { return m_cellSize; }
    const std::string& GetName() const { return m_name; }
    int         CellCount()  const  { return static_cast<int>(m_cells.size()); }

    // Returns a mutable pointer to the cell at (cx,cz), or nullptr if not found.
    WorldCell* FindCell(int cx, int cz);

    // Write the cell at (cx,cz) back to its JSON file (preserving terrain/forest settings).
    // Returns true on success; logs an error and keeps in-memory data on failure.
    bool SaveCell(int cx, int cz);

private:
    bool LoadCellFile(const std::string& path, WorldCell& out);

    std::string           m_worldJsonPath;
    std::string           m_name;
    float                 m_cellSize = 200.0f;
    std::vector<WorldCell> m_cells;

    // --- Biome transition state ---
    std::string m_currentBiome  = "grassland";
    std::string m_previousBiome = "grassland";
    float       m_biomeBlendAlpha    = 1.0f;  // 1.0 = fully at currentBiome
    float       m_biomeBlendDuration = 2.5f;  // seconds for a full biome fade
};

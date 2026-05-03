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
// WorldCell
// ---------------------------------------------------------------------------
// Describes one tile of the world grid.
struct WorldCell
{
    int   cx = 0;              // grid X index
    int   cz = 0;              // grid Z index
    float cellSize = 200.0f;   // world-space size of this cell (set from world.json)

    // Terrain settings for this cell
    bool  terrainEnabled    = true;
    float terrainHeightScale = 8.0f;

    // Forest settings for this cell
    bool  forestEnabled   = true;
    int   forestTreeCount = 80;
    float forestRadius    = 50.0f;

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

    float       GetCellSize() const  { return m_cellSize; }
    const std::string& GetName() const { return m_name; }
    int         CellCount()  const  { return static_cast<int>(m_cells.size()); }

private:
    bool LoadCellFile(const std::string& path, WorldCell& out);

    std::string           m_worldJsonPath;
    std::string           m_name;
    float                 m_cellSize = 200.0f;
    std::vector<WorldCell> m_cells;
};

// WorldGrid.cpp
// Loads Content/World/world.json and individual cell JSON files.
// Provides minimal synchronous cell streaming around a player position.

#include "WorldGrid.hpp"
#include "../../third_party/nlohmann/json.hpp"
#include "logger/Logger.hpp"

#include <fstream>
#include <sstream>
#include <cmath>

using json = nlohmann::json;

// ---------------------------------------------------------------------------
// Internal helper
// ---------------------------------------------------------------------------
static bool ReadJsonFile(const std::string& path, json& out)
{
    std::ifstream f(path);
    if (!f.is_open())
    {
        LOG_ERROR("WorldGrid: cannot open '" + path + "'");
        return false;
    }
    try
    {
        f >> out;
    }
    catch (const json::parse_error& e)
    {
        LOG_ERROR("WorldGrid: JSON parse error in '" + path + "': " + e.what());
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// WorldGrid::Load
// ---------------------------------------------------------------------------
bool WorldGrid::Load(const std::string& worldJsonPath)
{
    m_worldJsonPath = worldJsonPath;

    json j;
    if (!ReadJsonFile(worldJsonPath, j))
        return false;

    m_name     = j.value("name",      "world");
    m_cellSize = j.value("cell_size", 200.0f);

    if (!j.contains("cells") || !j["cells"].is_array())
    {
        LOG_ERROR("WorldGrid: missing 'cells' array in '" + worldJsonPath + "'");
        return false;
    }

    std::vector<WorldCell> cells;
    for (auto& entry : j["cells"])
    {
        WorldCell cell;
        cell.cx       = entry.value("cx", 0);
        cell.cz       = entry.value("cz", 0);
        cell.cellSize = m_cellSize;

        std::string cellFile = entry.value("file", "");
        if (!cellFile.empty())
        {
            if (!LoadCellFile(cellFile, cell))
            {
                std::ostringstream warn;
                warn << "WorldGrid: failed to load cell file '" << cellFile
                     << "', using defaults for cell ("
                     << cell.cx << "," << cell.cz << ")";
                LOG_WARN(warn.str());
            }
        }

        cells.push_back(cell);
    }

    m_cells = std::move(cells);

    std::ostringstream ss;
    ss << "WorldGrid: loaded world '" << m_name
       << "' cellSize=" << m_cellSize
       << " cells=" << m_cells.size();
    LOG_INFO(ss.str());
    return true;
}

// ---------------------------------------------------------------------------
// WorldGrid::Reload
// ---------------------------------------------------------------------------
bool WorldGrid::Reload()
{
    // Save old state so we can restore it if Load() fails.
    std::string           oldName     = m_name;
    float                 oldCellSize = m_cellSize;
    std::vector<WorldCell> oldCells   = m_cells;

    if (!Load(m_worldJsonPath))
    {
        // Restore previous good state — no crash, no empty world.
        m_name     = std::move(oldName);
        m_cellSize = oldCellSize;
        m_cells    = std::move(oldCells);
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// WorldGrid::LoadCellFile
// ---------------------------------------------------------------------------
bool WorldGrid::LoadCellFile(const std::string& path, WorldCell& out)
{
    json j;
    if (!ReadJsonFile(path, j))
        return false;

    out.cx = j.value("cx", out.cx);
    out.cz = j.value("cz", out.cz);

    if (j.contains("terrain"))
    {
        const auto& t     = j["terrain"];
        out.terrainEnabled    = t.value("enabled",      true);
        out.terrainHeightScale = t.value("height_scale", 8.0f);
    }

    if (j.contains("forest"))
    {
        const auto& f    = j["forest"];
        out.forestEnabled   = f.value("enabled",    true);
        out.forestTreeCount = f.value("tree_count", 80);
        out.forestRadius    = f.value("radius",     50.0f);
    }

    std::ostringstream ss;
    ss << "WorldGrid: loaded cell (" << out.cx << "," << out.cz << ")";
    LOG_INFO(ss.str());
    return true;
}

// ---------------------------------------------------------------------------
// WorldGrid::WorldToCell
// ---------------------------------------------------------------------------
void WorldGrid::WorldToCell(float worldX, float worldZ, int& outCX, int& outCZ) const
{
    // floor() is used so negative coordinates map correctly:
    //   worldX=-1   → floor(-1/200)   = floor(-0.005) = -1  → cell -1
    //   worldX=199  → floor(199/200)  = floor(0.995)  =  0  → cell  0
    //   worldX=200  → floor(200/200)  = floor(1.0)    =  1  → cell  1
    // This means grids extending into negative territory work naturally.
    // GetActiveCells() will simply return no matches for cells not in m_cells.
    outCX = static_cast<int>(std::floor(worldX / m_cellSize));
    outCZ = static_cast<int>(std::floor(worldZ / m_cellSize));
}

// ---------------------------------------------------------------------------
// WorldGrid::GetActiveCells
// ---------------------------------------------------------------------------
std::vector<WorldCell> WorldGrid::GetActiveCells(int playerCX, int playerCZ, int radius) const
{
    std::vector<WorldCell> active;
    for (const auto& cell : m_cells)
    {
        int dx = cell.cx - playerCX;
        int dz = cell.cz - playerCZ;
        if (std::abs(dx) <= radius && std::abs(dz) <= radius)
            active.push_back(cell);
    }
    return active;
}

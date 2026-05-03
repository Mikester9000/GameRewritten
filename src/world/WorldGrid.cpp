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

    // Validate cell_size: must be > 0 or WorldToCell() will divide by zero.
    float rawCellSize = j.value("cell_size", 200.0f);
    if (rawCellSize <= 0.0f)
    {
        std::ostringstream err;
        err << "WorldGrid: 'cell_size' must be > 0, got " << rawCellSize
            << " in '" << worldJsonPath << "'";
        LOG_ERROR(err.str());
        return false;
    }
    m_cellSize = rawCellSize;

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
            cell.filePath = cellFile;
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

    // Treat cx/cz in the cell file as validation only — the manifest is the
    // authoritative source of a cell's grid coordinates.  Warn and continue
    // if there is a mismatch; do NOT overwrite out.cx/out.cz.
    if (j.contains("cx") && j["cx"].is_number_integer())
    {
        int fileCX = j["cx"].get<int>();
        if (fileCX != out.cx)
        {
            std::ostringstream w;
            w << "WorldGrid: cell file '" << path
              << "' has cx=" << fileCX
              << " but manifest says cx=" << out.cx
              << ". Using manifest value.";
            LOG_WARN(w.str());
        }
    }
    if (j.contains("cz") && j["cz"].is_number_integer())
    {
        int fileCZ = j["cz"].get<int>();
        if (fileCZ != out.cz)
        {
            std::ostringstream w;
            w << "WorldGrid: cell file '" << path
              << "' has cz=" << fileCZ
              << " but manifest says cz=" << out.cz
              << ". Using manifest value.";
            LOG_WARN(w.str());
        }
    }

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

    // Parse authored instances placed by the World Editor (optional field).
    out.instances.clear();
    if (j.contains("instances") && j["instances"].is_array())
    {
        for (const auto& inst : j["instances"])
        {
            CellInstance ci;
            ci.prefab = inst.value("prefab", "");
            ci.x      = inst.value("x",     0.0f);
            ci.y      = inst.value("y",     0.0f);
            ci.z      = inst.value("z",     0.0f);
            ci.yaw    = inst.value("yaw",   0.0f);
            ci.scale  = inst.value("scale", 1.0f);
            if (!ci.prefab.empty())
                out.instances.push_back(ci);
        }
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

// ---------------------------------------------------------------------------
// WorldGrid::FindCell
// ---------------------------------------------------------------------------
WorldCell* WorldGrid::FindCell(int cx, int cz)
{
    for (auto& cell : m_cells)
    {
        if (cell.cx == cx && cell.cz == cz)
            return &cell;
    }
    return nullptr;
}

// ---------------------------------------------------------------------------
// WorldGrid::SaveCell
// ---------------------------------------------------------------------------
bool WorldGrid::SaveCell(int cx, int cz)
{
    WorldCell* cell = FindCell(cx, cz);
    if (!cell)
    {
        std::ostringstream err;
        err << "WorldGrid::SaveCell: no cell (" << cx << "," << cz << ") in grid";
        LOG_ERROR(err.str());
        return false;
    }

    if (cell->filePath.empty())
    {
        std::ostringstream err;
        err << "WorldGrid::SaveCell: cell (" << cx << "," << cz << ") has no file path; cannot save.";
        LOG_ERROR(err.str());
        return false;
    }

    // Build JSON preserving terrain + forest settings, then write instances.
    json j;
    j["cx"]  = cell->cx;
    j["cz"]  = cell->cz;

    j["terrain"]["enabled"]      = cell->terrainEnabled;
    j["terrain"]["height_scale"] = cell->terrainHeightScale;

    j["forest"]["enabled"]    = cell->forestEnabled;
    j["forest"]["tree_count"] = cell->forestTreeCount;
    j["forest"]["radius"]     = cell->forestRadius;

    j["instances"] = json::array();
    for (const auto& inst : cell->instances)
    {
        json entry;
        entry["prefab"] = inst.prefab;
        entry["x"]      = inst.x;
        entry["y"]      = inst.y;
        entry["z"]      = inst.z;
        entry["yaw"]    = inst.yaw;
        entry["scale"]  = inst.scale;
        j["instances"].push_back(entry);
    }

    std::ofstream out(cell->filePath);
    if (!out.is_open())
    {
        LOG_ERROR("WorldGrid::SaveCell: cannot open '" + cell->filePath + "' for writing.");
        return false;
    }

    try
    {
        out << j.dump(4);
    }
    catch (const std::exception& e)
    {
        LOG_ERROR(std::string("WorldGrid::SaveCell: write error: ") + e.what());
        return false;
    }

    // std::ofstream write failures typically set failbit/badbit rather than throwing.
    // Always check the stream state after writing, regardless of exceptions.
    if (!out.good())
    {
        std::ostringstream streamErr;
        streamErr << "WorldGrid::SaveCell: stream error after write to '"
                  << cell->filePath
                  << "' (disk full, permission denied, or IO error).";
        LOG_ERROR(streamErr.str());
        return false;
    }

    std::ostringstream ss;
    ss << "WorldGrid::SaveCell: saved cell (" << cx << "," << cz << ") to '"
       << cell->filePath << "' with " << cell->instances.size() << " instance(s).";
    LOG_INFO(ss.str());
    return true;
}

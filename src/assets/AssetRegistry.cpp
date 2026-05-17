// ============================================================
// FILE: src/assets/AssetRegistry.cpp
// SYSTEM: AssetRegistry.cpp
// SYSTEM: asset registry lookups and content loading helpers

// AssetRegistry.cpp
// Loads Content/AssetRegistry.json and answers GetPath() queries.
// Safe reload: on parse error the old registry stays intact.

#include "AssetRegistry.hpp"
#include "../../third_party/nlohmann/json.hpp"
#include "logger/Logger.hpp"

#include <fstream>
#include <sstream>
#include <algorithm>

using json = nlohmann::json;

// ---------------------------------------------------------------------------
// Load / Reload
// ---------------------------------------------------------------------------
bool AssetRegistry::Load(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        LOG_ERROR("AssetRegistry: cannot open '" + path + "'");
        return false;
    }

    json j;
    try
    {
        file >> j;
    }
    catch (const json::parse_error& e)
    {
        LOG_ERROR("AssetRegistry: JSON parse error in '" + path + "': " + e.what());
        return false;  // keep old registry intact
    }

    if (!j.contains("assets") || !j["assets"].is_object())
    {
        LOG_ERROR("AssetRegistry: missing 'assets' object in '" + path + "'");
        return false;
    }

    // Build into a temp map first; only replace m_assets on full success.
    std::unordered_map<std::string, std::string> newAssets;
    for (auto& [id, pathVal] : j["assets"].items())
    {
        if (!pathVal.is_string())
        {
            LOG_WARN("AssetRegistry: skipping non-string value for id '" + id + "'");
            continue;
        }
        std::string assetPath = pathVal.get<std::string>();

        // Skip empty paths — GetPath() returns "" for "not found", so storing
        // an empty path would make it impossible to tell the two cases apart.
        if (assetPath.empty())
        {
            LOG_WARN("AssetRegistry: skipping empty path for id '" + id + "'");
            continue;
        }

        // Warn if the file doesn't exist so the developer notices quickly.
        {
            std::ifstream check(assetPath);
            if (!check.is_open())
                LOG_WARN("AssetRegistry: path not found on disk: '" + assetPath + "' (id='" + id + "')");
        }

        newAssets[id] = std::move(assetPath);
    }

    m_assets = std::move(newAssets);

    // Only record the path after a fully successful load so that Reload()
    // doesn't keep retrying a previously bad path.
    m_registryPath = path;

    std::ostringstream ss;
    ss << "AssetRegistry: loaded " << m_assets.size()
       << " asset(s) from '" << path << "'";
    LOG_INFO(ss.str());
    return true;
}

bool AssetRegistry::Reload()
{
    // Save old state so we can restore it if Load() fails.
    auto oldAssets = m_assets;

    if (!Load(m_registryPath))
    {
        m_assets = std::move(oldAssets);
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// GetPath
// ---------------------------------------------------------------------------
std::string AssetRegistry::GetPath(const std::string& assetId) const
{
    auto it = m_assets.find(assetId);
    if (it == m_assets.end())
    {
        LOG_ERROR("AssetRegistry: unknown asset id '" + assetId + "'");
        return {};
    }
    return it->second;
}

// ---------------------------------------------------------------------------
// GetIdsByPrefix
// ---------------------------------------------------------------------------
std::vector<std::string> AssetRegistry::GetIdsByPrefix(const std::string& prefix) const
{
    std::vector<std::string> result;
    for (const auto& [id, path] : m_assets)
    {
        if (id.size() >= prefix.size() &&
            id.compare(0, prefix.size(), prefix) == 0)
        {
            result.push_back(id);
        }
    }
    // Sort so the caller always receives a deterministic order regardless of
    // the unordered_map's internal iteration sequence.
    std::sort(result.begin(), result.end());
    return result;
}

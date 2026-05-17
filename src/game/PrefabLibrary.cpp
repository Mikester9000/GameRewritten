// ============================================================
// FILE: src/game/PrefabLibrary.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PrefabLibrary module behavior and local implementation details.
// ============================================================

// PrefabLibrary.cpp
// Loads and caches PrimitivePrefab definitions from JSON files.

#include "PrefabLibrary.hpp"
#include "../assets/AssetRegistry.hpp"
#include "../logger/Logger.hpp"

#include "../../third_party/nlohmann/json.hpp"

#include <fstream>
#include <sstream>

using json = nlohmann::json;

// ---------------------------------------------------------------------------
// Load
// ---------------------------------------------------------------------------
void PrefabLibrary::Load(const AssetRegistry& registry)
{
    m_prefabs.clear();

    // Collect all asset IDs that start with "prefabs."
    auto ids = registry.GetIdsByPrefix("prefabs.");

    for (const auto& id : ids)
    {
        std::string path = registry.GetPath(id);
        if (path.empty()) continue;

        std::ifstream file(path);
        if (!file.is_open())
        {
            LOG_WARN("PrefabLibrary: cannot open '" + path + "' for id '" + id + "'");
            continue;
        }

        json j;
        try { file >> j; }
        catch (const json::parse_error& e)
        {
            LOG_WARN("PrefabLibrary: JSON parse error in '" + path + "': " + e.what());
            continue;
        }

        // Only parse files that have a "parts" array (the new primitive format).
        if (!j.contains("parts") || !j["parts"].is_array())
        {
            // Not a primitive prefab — silently skip (may be old mesh/lod format).
            continue;
        }

        PrimitivePrefab prefab;
        prefab.name     = j.value("name",     id);
        prefab.category = j.value("category", "prop");

        for (const auto& partJson : j["parts"])
        {
            PrimitivePart part;
            try
            {
                part.shape = partJson.value("shape", "box");

                if (partJson.contains("offset") && partJson["offset"].is_array()
                    && partJson["offset"].size() >= 3)
                {
                    part.offsetX = partJson["offset"][0].get<float>();
                    part.offsetY = partJson["offset"][1].get<float>();
                    part.offsetZ = partJson["offset"][2].get<float>();
                }

                if (partJson.contains("scale") && partJson["scale"].is_array()
                    && partJson["scale"].size() >= 3)
                {
                    part.scaleX = partJson["scale"][0].get<float>();
                    part.scaleY = partJson["scale"][1].get<float>();
                    part.scaleZ = partJson["scale"][2].get<float>();
                }

                if (partJson.contains("color") && partJson["color"].is_array())
                {
                    auto& col = partJson["color"];
                    part.r = col.size() > 0 ? col[0].get<float>() : 1.0f;
                    part.g = col.size() > 1 ? col[1].get<float>() : 1.0f;
                    part.b = col.size() > 2 ? col[2].get<float>() : 1.0f;
                    part.a = col.size() > 3 ? col[3].get<float>() : 1.0f;
                }
            }
            catch (const json::exception& e)
            {
                LOG_WARN("PrefabLibrary: bad field value in prefab '" + id
                         + "' — skipping prefab. Error: " + e.what());
                prefab.parts.clear(); // discard any parts already parsed for this prefab
                break;
            }

            prefab.parts.push_back(part);
        }

        if (prefab.parts.empty()) continue; // skip prefabs with bad data

        m_prefabs[id] = std::move(prefab);
    }

    std::ostringstream ss;
    ss << "PrefabLibrary: loaded " << m_prefabs.size()
       << " primitive prefab(s) from " << ids.size() << " registry entries.";
    LOG_INFO(ss.str());
}

// ---------------------------------------------------------------------------
// GetPrefab
// ---------------------------------------------------------------------------
const PrimitivePrefab* PrefabLibrary::GetPrefab(const std::string& assetId) const
{
    auto it = m_prefabs.find(assetId);
    return (it != m_prefabs.end()) ? &it->second : nullptr;
}

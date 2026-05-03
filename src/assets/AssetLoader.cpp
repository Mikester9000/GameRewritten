// AssetLoader.cpp
// Parses Content/ JSON files and logs what was loaded.
// Replace the LOG_INFO bodies with real resource creation as the engine grows.

#include "AssetLoader.hpp"
#include "../../third_party/nlohmann/json.hpp"
#include "logger/Logger.hpp"

#include <fstream>
#include <sstream>

using json = nlohmann::json;

// ---------------------------------------------------------------------------
// Internal helper
// ---------------------------------------------------------------------------
static bool ReadJsonFile(const std::string& path, json& out)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        LOG_ERROR("AssetLoader: cannot open file: " + path);
        return false;
    }

    try
    {
        file >> out;
    }
    catch (const json::parse_error& e)
    {
        LOG_ERROR("AssetLoader: JSON parse error in " + path + " — " + e.what());
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// Material
// ---------------------------------------------------------------------------
bool AssetLoader::LoadMaterial(const std::string& path, MaterialAsset& out)
{
    json j;
    if (!ReadJsonFile(path, j))
        return false;

    out.name   = j.value("name",   "unknown");
    out.shader = j.value("shader", "");

    if (j.contains("textures"))
    {
        out.albedoTexture = j["textures"].value("albedo", "");
        out.normalTexture = j["textures"].value("normal", "");
    }

    if (j.contains("params"))
    {
        out.roughness = j["params"].value("roughness", 0.5f);
        out.metallic  = j["params"].value("metallic",  0.0f);
    }

    std::ostringstream ss;
    ss << "Loaded material '" << out.name << "' shader='" << out.shader
       << "' albedo='" << out.albedoTexture << "'";
    LOG_INFO(ss.str());
    return true;
}

// ---------------------------------------------------------------------------
// Prefab
// ---------------------------------------------------------------------------
bool AssetLoader::LoadPrefab(const std::string& path, PrefabAsset& out)
{
    json j;
    if (!ReadJsonFile(path, j))
        return false;

    out.name     = j.value("name",     "unknown");
    out.mesh     = j.value("mesh",     "");
    out.material = j.value("material", "");

    if (j.contains("defaults"))
    {
        auto& def = j["defaults"];
        if (def.contains("scale") && def["scale"].is_array() && def["scale"].size() == 3)
            for (int i = 0; i < 3; ++i) out.scale[i] = def["scale"][i].get<float>();
        if (def.contains("rotation") && def["rotation"].is_array() && def["rotation"].size() == 3)
            for (int i = 0; i < 3; ++i) out.rotation[i] = def["rotation"][i].get<float>();
    }

    if (j.contains("lod") && j["lod"].is_array())
    {
        for (auto& entry : j["lod"])
        {
            PrefabLOD lod;
            lod.distance = entry.value("distance", 0.0f);
            lod.mesh     = entry.value("mesh",     "");
            out.lods.push_back(lod);
        }
    }

    std::ostringstream ss;
    ss << "Loaded prefab '" << out.name << "' mesh='" << out.mesh
       << "' lods=" << out.lods.size();
    LOG_INFO(ss.str());
    return true;
}

// ---------------------------------------------------------------------------
// Scene
// ---------------------------------------------------------------------------
bool AssetLoader::LoadScene(const std::string& path, SceneAsset& out)
{
    json j;
    if (!ReadJsonFile(path, j))
        return false;

    out.name    = j.value("name",    "unknown");
    out.version = j.value("version", 0);

    if (j.contains("instances") && j["instances"].is_array())
    {
        for (auto& inst : j["instances"])
        {
            SceneInstance si;
            si.prefab = inst.value("prefab", "");
            si.yaw    = inst.value("yaw",    0.0f);

            if (inst.contains("pos") && inst["pos"].is_array() && inst["pos"].size() == 3)
                for (int i = 0; i < 3; ++i) si.pos[i] = inst["pos"][i].get<float>();
            if (inst.contains("scale") && inst["scale"].is_array() && inst["scale"].size() == 3)
                for (int i = 0; i < 3; ++i) si.scale[i] = inst["scale"][i].get<float>();

            out.instances.push_back(si);
        }
    }

    std::ostringstream ss;
    ss << "Loaded scene '" << out.name << "' v" << out.version
       << " instances=" << out.instances.size();
    LOG_INFO(ss.str());
    return true;
}

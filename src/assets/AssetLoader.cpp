// ============================================================
// FILE: src/assets/AssetLoader.cpp
// SYSTEM: Assets
// ROLE: asset registry lookups and content loading helpers
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AssetLoader module behavior and local implementation details.
// ============================================================

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
    if (j.contains("params"))
    {
        const auto& params_json = j["params"];
        out.roughness = params_json.value("roughness", 0.5f);
        out.metallic = params_json.value("metallic", 0.0f);

        // Cel Shading Parameters (Task 030D - Reading all necessary values)
        out.celBandCount = params_json.value("cel_bands", 5.0f);
        out.celRimAmount = params_json.value("rim_amount", 0.1f);

        // Shadow Tint is an RGB color, read components separately for clarity
        const auto& shadowJson = params_json["shadow_tint"];
        out.shadowTintR = shadowJson.value("r", 0.8f);
        out.shadowTintG = shadowJson.value("g", 0.8f);
        out.shadowTintB = shadowJson.value("b", 1.0f); // Defaulting B to 1.0 if not specified

        out.specThreshold = params_json.value("specular_threshold", 0.9f);
    }

    std::ostringstream ss;
    ss << "Loaded material '" << out.name << "' shader='" << out.shader << "'";
    // Log the loaded cel values to confirm plumbing was successful
    ss << ", CelBands=" << out.celBandCount
        << ", Rim=" << out.celRimAmount
        << ", ShadowTint=(" << out.shadowTintR << "," << out.shadowTintG << "," << out.shadowTintB << ") ";
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

// ---------------------------------------------------------------------------
// Animation
// ---------------------------------------------------------------------------
bool AssetLoader::LoadAnimation(const std::string& path, AnimationAsset& out)
{
    json j;
    if (!ReadJsonFile(path, j))
        return false;

    out.format = j.value("format", "");
    out.version = j.value("version", "");
    out.clips.clear();

    if (out.format != "AnimEngine")
        LOG_WARN("AssetLoader: animation format is not 'AnimEngine' for '" + path + "'");
    if (out.version != "1.0")
        LOG_WARN("AssetLoader: animation version is not '1.0' for '" + path + "'");

    if (j.contains("clips") && j["clips"].is_array())
    {
        for (const auto& clipJson : j["clips"])
        {
            AnimationClipAsset clip;
            clip.name = clipJson.value("name", "unnamed");
            clip.fps = clipJson.value("fps", 0.0f);
            clip.loop = clipJson.value("loop", false);
            clip.durationSec = clipJson.value("duration_sec", 0.0f);

            if (clipJson.contains("channels") && clipJson["channels"].is_array())
                clip.channelCount = static_cast<int>(clipJson["channels"].size());

            if (clipJson.contains("events") && clipJson["events"].is_array())
                clip.eventCount = static_cast<int>(clipJson["events"].size());
            else if (j.contains("events") && j["events"].is_array())
                clip.eventCount = static_cast<int>(j["events"].size());

            if (clipJson.contains("root_motion") && clipJson["root_motion"].is_object())
            {
                const auto& rootMotion = clipJson["root_motion"];
                clip.rootMotionEnabled = rootMotion.value("enabled", false);
                clip.rootMotionChannelIndex = rootMotion.value("channel_index", -1);
            }
            else if (j.contains("root_motion") && j["root_motion"].is_object())
            {
                const auto& rootMotion = j["root_motion"];
                clip.rootMotionEnabled = rootMotion.value("enabled", false);
                clip.rootMotionChannelIndex = rootMotion.value("channel_index", -1);
            }

            out.clips.push_back(clip);
        }
    }

    std::ostringstream ss;
    ss << "Loaded animation '" << path << "' format='" << out.format
       << "' version='" << out.version << "' clips=" << out.clips.size();
    LOG_INFO(ss.str());
    return true;
}

// ============================================================
// FILE: src/assets/CreationMaterialLoader.cpp
// SYSTEM: Assets
// ROLE: loads and caches Creation-Engine material JSON v1.1 files
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: CreationMaterialLoader module behavior and local implementation details.
// ============================================================

#include "CreationMaterialLoader.hpp"
#include "../../third_party/nlohmann/json.hpp"
#include "../logger/Logger.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <unordered_map>

using json = nlohmann::json;
namespace fs = std::filesystem;

// Static material cache keyed by material name.
static std::unordered_map<std::string, CreationMaterial> s_materialCache;

// ---------------------------------------------------------------------------
// Load
// ---------------------------------------------------------------------------
CreationMaterial CreationMaterialLoader::Load(const std::string& jsonPath)
{
    CreationMaterial out;

    std::ifstream f(jsonPath);
    if (!f.is_open())
    {
        LOG_WARN("CreationMaterialLoader: cannot open '" + jsonPath + "'");
        return out;
    }

    json j;
    try { f >> j; }
    catch (const std::exception& e)
    {
        LOG_WARN("CreationMaterialLoader: JSON parse error in '" + jsonPath + "': " + e.what());
        return out;
    }

    // Version check — warn on mismatch but continue with best-effort parsing.
    const std::string version = j.value("version", "");
    if (!version.empty() && version != "1.1")
        LOG_WARN("CreationMaterialLoader: unexpected version '" + version + "' in '" + jsonPath + "'");

    out.name   = j.value("name",   "");
    out.shader = j.value("shader", "");

    if (out.shader != "Shaders/basic3d" && out.shader != "Shaders/pbr_3d" && !out.shader.empty())
        LOG_WARN("CreationMaterialLoader: shader '" + out.shader + "' may cause rendering artifacts in '" + jsonPath + "'");

    // params
    if (j.contains("params"))
    {
        const auto& p = j["params"];

        // color (v1.1) — fall back to baseColor (legacy)
        if (p.contains("color") && p["color"].is_array() && p["color"].size() >= 4)
        {
            out.color[0] = p["color"][0].get<float>();
            out.color[1] = p["color"][1].get<float>();
            out.color[2] = p["color"][2].get<float>();
            out.color[3] = p["color"][3].get<float>();
        }
        else if (p.contains("baseColor") && p["baseColor"].is_array() && p["baseColor"].size() >= 4)
        {
            out.color[0] = p["baseColor"][0].get<float>();
            out.color[1] = p["baseColor"][1].get<float>();
            out.color[2] = p["baseColor"][2].get<float>();
            out.color[3] = p["baseColor"][3].get<float>();
        }

        out.roughness = p.value("roughness", 0.5f);
        out.metallic  = p.value("metallic",  0.0f);
        out.ao        = p.value("ao",         1.0f);

        if (p.contains("emissive") && p["emissive"].is_array() && p["emissive"].size() >= 3)
        {
            out.emissive[0] = p["emissive"][0].get<float>();
            out.emissive[1] = p["emissive"][1].get<float>();
            out.emissive[2] = p["emissive"][2].get<float>();
        }
    }

    // textures
    if (j.contains("textures"))
    {
        const auto& t = j["textures"];
        out.texAlbedo    = t.value("albedo",    "");
        out.texNormal    = t.value("normal",    "");
        out.texRoughness = t.value("roughness", "");
        out.texMetallic  = t.value("metallic",  "");
        out.texAO        = t.value("ao",         "");
        out.texEmissive  = t.value("emissive",  "");
    }
    // v1.1 also stores texture filenames under "files" — merge if textures map is incomplete.
    if (j.contains("files"))
    {
        const auto& fi = j["files"];
        if (out.texAlbedo.empty())    out.texAlbedo    = fi.value("albedo",    "");
        if (out.texNormal.empty())    out.texNormal    = fi.value("normal",    "");
        if (out.texRoughness.empty()) out.texRoughness = fi.value("roughness", "");
        if (out.texMetallic.empty())  out.texMetallic  = fi.value("metallic",  "");
        if (out.texAO.empty())        out.texAO        = fi.value("ao",         "");
        if (out.texEmissive.empty())  out.texEmissive  = fi.value("emissive",  "");
    }

    out.valid = !out.name.empty();

    if (out.valid)
    {
        s_materialCache[out.name] = out;
        std::ostringstream ss;
        ss << "CreationMaterialLoader: loaded '" << out.name
           << "' shader='" << out.shader << "'";
        LOG_INFO(ss.str());
    }
    else
    {
        LOG_WARN("CreationMaterialLoader: material in '" + jsonPath + "' has no name — skipped");
    }

    return out;
}

// ---------------------------------------------------------------------------
// LoadDir
// ---------------------------------------------------------------------------
void CreationMaterialLoader::LoadDir(const std::string& dirPath)
{
    if (!fs::exists(dirPath))
    {
        LOG_WARN("CreationMaterialLoader::LoadDir: directory not found '" + dirPath + "'");
        return;
    }

    int loaded = 0;
    for (const auto& entry : fs::recursive_directory_iterator(dirPath))
    {
        if (!entry.is_regular_file())
            continue;

        const std::string ext = entry.path().extension().string();
        // Accept both *.material.json (composite) and plain *.json
        const std::string stem = entry.path().stem().string();
        if (ext != ".json")
            continue;

        Load(entry.path().string());
        ++loaded;
    }

    std::ostringstream ss;
    ss << "CreationMaterialLoader::LoadDir: scanned " << loaded << " JSON file(s) in '" << dirPath << "'";
    LOG_INFO(ss.str());
}

// ---------------------------------------------------------------------------
// Get
// ---------------------------------------------------------------------------
const CreationMaterial* CreationMaterialLoader::Get(const std::string& name)
{
    auto it = s_materialCache.find(name);
    if (it == s_materialCache.end())
        return nullptr;
    return &it->second;
}

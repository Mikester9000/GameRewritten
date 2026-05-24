// ============================================================
// FILE: src/game/animation/AnimPackManifestLoader.cpp
// SYSTEM: Game
// ROLE: reads hero_pack/pack_manifest.json and validates required clip inventory
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimPackManifestLoader module behavior and local implementation details.
// ============================================================

#include "AnimPackManifestLoader.hpp"
#include "../../../third_party/nlohmann/json.hpp"
#include "../../logger/Logger.hpp"

#include <fstream>
#include <sstream>
#include <unordered_map>

using json = nlohmann::json;

// Required clip names — every pack must contain these as a substring of an ordered_files entry.
static const char* kRequiredClips[] = {
    "idle", "walk", "run", "attack", "defend", "cast",
    "hit_react", "dodge", "jump_start", "jump_loop", "jump_land", "victory"
};
static const int kRequiredClipCount = 12;

// Static cache of manifest info keyed by character name.
static std::unordered_map<std::string, AnimPackManifestInfo> s_manifestCache;

// ---------------------------------------------------------------------------
std::vector<std::string> AnimPackManifestLoader::Load(const std::string& characterName)
{
    std::vector<std::string> result;

    const std::string manifestPath =
        "Content/Animations/" + characterName + "/pack_manifest.json";

    std::ifstream f(manifestPath);
    if (!f.is_open())
    {
        LOG_WARN("AnimPackManifestLoader: cannot open '" + manifestPath + "'");
        return result;
    }

    json j;
    try { f >> j; }
    catch (const std::exception& e)
    {
        LOG_WARN("AnimPackManifestLoader: parse error in '" + manifestPath + "': " + e.what());
        return result;
    }

    const std::string fmt     = j.value("format",  "");
    const std::string version = j.value("version", "");
    if (fmt != "AnimEngine")
    {
        LOG_WARN("AnimPackManifestLoader: unexpected format '" + fmt + "' in '" + manifestPath + "'");
        return result;
    }
    if (version != "1.0")
    {
        LOG_WARN("AnimPackManifestLoader: unexpected version '" + version + "' in '" + manifestPath + "'");
        return result;
    }

    // Store manifest metadata.
    AnimPackManifestInfo info;
    info.styleProfile    = j.value("style_profile",   "");
    info.visualTarget    = j.value("visual_target",   "");
    info.gameplayTarget  = j.value("gameplay_target", "");
    s_manifestCache[characterName] = info;

    // Build ordered file path list.
    const std::string prefix = "Content/Animations/" + characterName + "/";
    if (!j.contains("ordered_files") || !j["ordered_files"].is_array())
    {
        LOG_WARN("AnimPackManifestLoader: 'ordered_files' missing in '" + manifestPath + "'");
        return result;
    }

    for (const auto& entry : j["ordered_files"])
    {
        if (entry.is_string())
            result.push_back(prefix + entry.get<std::string>());
    }

    // Validate required clips.
    for (int i = 0; i < kRequiredClipCount; ++i)
    {
        bool found = false;
        for (const auto& path : result)
        {
            if (path.find(kRequiredClips[i]) != std::string::npos)
            {
                found = true;
                break;
            }
        }
        if (!found)
            LOG_WARN("AnimPackManifestLoader: required clip '" + std::string(kRequiredClips[i])
                     + "' not found in '" + manifestPath + "'");
    }

    std::ostringstream ss;
    ss << "AnimPackManifestLoader: loaded '" << characterName
       << "' — " << result.size() << " ordered file(s)";
    LOG_INFO(ss.str());
    return result;
}

// ---------------------------------------------------------------------------
AnimPackManifestInfo AnimPackManifestLoader::GetManifestInfo(const std::string& characterName)
{
    auto it = s_manifestCache.find(characterName);
    if (it == s_manifestCache.end())
        return AnimPackManifestInfo{};
    return it->second;
}

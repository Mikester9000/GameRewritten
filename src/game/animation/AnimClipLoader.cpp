// ============================================================
// FILE: src/game/animation/AnimClipLoader.cpp
// SYSTEM: Game
// ROLE: loads a single .anim JSON file into a LoadedAnimClip struct
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimClipLoader module behavior and local implementation details.
// ============================================================

#include "AnimClipLoader.hpp"
#include "../../../third_party/nlohmann/json.hpp"
#include "../../logger/Logger.hpp"

#include <fstream>
#include <sstream>

using json = nlohmann::json;

// ---------------------------------------------------------------------------
// Helper: parse one keyframe array entry into an AnimKeyframe.
static AnimKeyframe ParseKeyframe(const json& kfJson)
{
    AnimKeyframe kf;
    kf.time = kfJson.value("time", 0.0f);

    // value is a JSON array; up to 4 elements.
    if (kfJson.contains("value") && kfJson["value"].is_array())
    {
        const auto& v = kfJson["value"];
        for (size_t i = 0; i < v.size() && i < 4; ++i)
            kf.value[i] = v[i].get<float>();
        // Default w=1 for quaternions when only xyz present.
        if (v.size() == 3)
            kf.value[3] = 1.0f;
    }
    return kf;
}

// ---------------------------------------------------------------------------
LoadedAnimClip AnimClipLoader::Load(const std::string& path)
{
    LoadedAnimClip out;

    std::ifstream f(path);
    if (!f.is_open())
    {
        LOG_WARN("AnimClipLoader: cannot open '" + path + "'");
        return out;
    }

    json j;
    try { f >> j; }
    catch (const std::exception& e)
    {
        LOG_WARN("AnimClipLoader: parse error in '" + path + "': " + e.what());
        return out;
    }

    // Parse top-level clips array — each .anim file typically has one clip.
    if (!j.contains("clips") || !j["clips"].is_array() || j["clips"].empty())
    {
        LOG_WARN("AnimClipLoader: no clips array in '" + path + "'");
        return out;
    }

    // Use first clip entry.
    const json& clipJson = j["clips"][0];
    out.name       = clipJson.value("name",         "");
    out.fps        = clipJson.value("fps",           30.0f);
    out.loop       = clipJson.value("loop",          false);
    out.durationSec = clipJson.value("duration_sec", 0.0f);

    // Channels.
    if (clipJson.contains("channels") && clipJson["channels"].is_array())
    {
        for (const auto& chJson : clipJson["channels"])
        {
            AnimChannel ch;
            ch.boneName      = chJson.value("bone_name",     "");
            ch.target        = chJson.value("target",        "");
            ch.interpolation = chJson.value("interpolation", "LINEAR");

            if (chJson.contains("keyframes") && chJson["keyframes"].is_array())
            {
                for (const auto& kfJson : chJson["keyframes"])
                    ch.keyframes.push_back(ParseKeyframe(kfJson));
            }
            out.channels.push_back(std::move(ch));
        }
    }

    // Events — try clip-level first, then top-level fallback.
    const json* evtSource = nullptr;
    if (clipJson.contains("events") && clipJson["events"].is_array())
        evtSource = &clipJson["events"];
    else if (j.contains("events") && j["events"].is_array())
        evtSource = &j["events"];

    if (evtSource)
    {
        for (const auto& evJson : *evtSource)
        {
            AnimEvent ev;
            ev.time = evJson.value("time", 0.0f);
            ev.type = evJson.value("type", "");
            ev.bone = evJson.value("bone", "");
            out.events.push_back(ev);
        }
    }

    // Root motion — try clip-level then top-level.
    const json* rmSource = nullptr;
    if (clipJson.contains("root_motion") && clipJson["root_motion"].is_object())
        rmSource = &clipJson["root_motion"];
    else if (j.contains("root_motion") && j["root_motion"].is_object())
        rmSource = &j["root_motion"];

    if (rmSource)
    {
        out.rootMotionEnabled      = rmSource->value("enabled",       false);
        out.rootMotionChannelIndex = rmSource->value("channel_index", -1);
    }

    if (out.name.empty())
        out.name = path; // fallback: use path as identifier

    std::ostringstream ss;
    ss << "AnimClipLoader: loaded '" << out.name << "' from '" << path
       << "' fps=" << out.fps << " channels=" << out.channels.size()
       << " events=" << out.events.size();
    LOG_INFO(ss.str());
    return out;
}

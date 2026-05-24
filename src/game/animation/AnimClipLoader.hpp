// ============================================================
// FILE: src/game/animation/AnimClipLoader.hpp
// SYSTEM: Game
// ROLE: loads a single .anim JSON file into a LoadedAnimClip struct
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimClipLoader module behavior and local implementation details.
// ============================================================

#pragma once

#include <string>
#include <vector>

// A single keyframe value: float[4] covers both float3 (xyz) and quaternion (xyzw).
struct AnimKeyframe
{
    float time      = 0.0f;
    float value[4]  = {0.0f, 0.0f, 0.0f, 1.0f};
};

// A single bone animation channel (translation, rotation, or scale).
struct AnimChannel
{
    std::string             boneName;
    std::string             target;        // "translation" | "rotation" | "scale"
    std::string             interpolation; // "STEP" | "LINEAR" | "CUBIC"
    std::vector<AnimKeyframe> keyframes;
};

// An animation event fired at a given time in the clip.
struct AnimEvent
{
    float       time = 0.0f;
    std::string type; // "footstep" | "contact" | "hit" | "cancel" | "cast_release"
    std::string bone;
};

// All data for one animation clip loaded from a .anim file.
struct LoadedAnimClip
{
    std::string             name;
    float                   fps            = 30.0f;
    bool                    loop           = false;
    float                   durationSec    = 0.0f;
    std::vector<AnimChannel> channels;
    std::vector<AnimEvent>   events;
    bool                    rootMotionEnabled      = false;
    int                     rootMotionChannelIndex = -1;
};

// Loads a single .anim JSON file and returns a LoadedAnimClip.
// Returns an empty (name == "") clip on error.
class AnimClipLoader
{
public:
    static LoadedAnimClip Load(const std::string& path);
};

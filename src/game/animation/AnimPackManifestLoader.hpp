// ============================================================
// FILE: src/game/animation/AnimPackManifestLoader.hpp
// SYSTEM: Game
// ROLE: reads hero_pack/pack_manifest.json and validates required clip inventory
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimPackManifestLoader module behavior and local implementation details.
// ============================================================

#pragma once

#include <string>
#include <vector>

// Metadata stored from a successfully parsed pack_manifest.json.
struct AnimPackManifestInfo
{
    std::string styleProfile;
    std::string visualTarget;
    std::string gameplayTarget;
};

// Reads Content/Animations/<characterName>/pack_manifest.json,
// validates required clips, and returns ordered .anim file paths.
class AnimPackManifestLoader
{
public:
    // Load the manifest for <characterName>.
    // Returns a vector of absolute .anim file paths (with Content/ prefix).
    // Returns an empty vector on format mismatch or file-not-found.
    // Logs a warning for each missing required clip.
    static std::vector<std::string> Load(const std::string& characterName);

    // Returns manifest metadata for the last successfully loaded character pack.
    // Returns a zeroed struct if characterName has not been loaded.
    static AnimPackManifestInfo GetManifestInfo(const std::string& characterName);
};

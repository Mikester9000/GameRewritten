// ============================================================
// FILE: src/assets/AssetLoader.hpp
// SYSTEM: Assets
// ROLE: asset registry lookups and content loading helpers
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AssetLoader module behavior and local implementation details.
// ============================================================

#pragma once
// AssetLoader.hpp
// Stub loaders for data-driven Content/ assets (materials, prefabs, scenes).
// Uses nlohmann/json to parse JSON files and logs the results via Logger.
// Future: these stubs will create real GPU resources / entity instances.

#include <string>
#include <vector>

// Simple POD structs — one per JSON type.

struct MaterialAsset
{
    std::string name;
    std::string shader;
    std::string albedoTexture;
    std::string normalTexture;
    float       roughness = 0.5f;
    float       metallic = 0.0f;

    // Cel Shading Parameters (Task 030D)
    float       celBandCount = 5.0f;   // Default: 5 bands
    float       celRimAmount = 0.1f;   // Default rim strength (was celRimAmount in C6)
    float       shadowTintR = 1.0f;    // R component of shadow color
    float       shadowTintG = 1.0f;    // G component of shadow color
    float       shadowTintB = 1.0f;    // B component of shadow color
    float       specThreshold = 0.9f;  // Default Specular threshold

    // Other required parameters that might come from assets:
    float       celDiffuseMin = 0.2f; // Added minimum diffuse value default
};


struct PrefabLOD
{
    float       distance = 0.0f;
    std::string mesh;
};

struct PrefabAsset
{
    std::string            name;
    std::string            mesh;
    std::string            material;
    float                  scale[3]    = {1.0f, 1.0f, 1.0f};
    float                  rotation[3] = {0.0f, 0.0f, 0.0f};
    std::vector<PrefabLOD> lods;
};

struct SceneInstance
{
    std::string prefab;
    float       pos[3]   = {0.0f, 0.0f, 0.0f};
    float       yaw      = 0.0f;
    float       scale[3] = {1.0f, 1.0f, 1.0f};
};

struct SceneAsset
{
    std::string                name;
    int                        version = 0;
    std::vector<SceneInstance> instances;
};

struct AnimationClipAsset
{
    std::string name;
    float       fps = 0.0f;
    bool        loop = false;
    float       durationSec = 0.0f;
    int         channelCount = 0;
    int         eventCount = 0;
    bool        rootMotionEnabled = false;
    int         rootMotionChannelIndex = -1;
};

struct AnimationAsset
{
    std::string                    format;
    std::string                    version;
    std::vector<AnimationClipAsset> clips;
};

class AssetLoader
{
public:
    // Load a *.material.json file.  Returns false on parse error.
    static bool LoadMaterial(const std::string& path, MaterialAsset& out);

    // Load a *.prefab.json file.  Returns false on parse error.
    static bool LoadPrefab(const std::string& path, PrefabAsset& out);

    // Load a *.scene.json file.  Returns false on parse error.
    static bool LoadScene(const std::string& path, SceneAsset& out);

    // Load an Animation Engine *.anim file. Returns false on parse error.
    static bool LoadAnimation(const std::string& path, AnimationAsset& out);
};

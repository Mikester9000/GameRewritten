// ============================================================
// FILE: src/assets/AssetLoader.hpp
// SYSTEM: AssetLoader.hpp
// SYSTEM: asset registry lookups and content loading helpers

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
    float       metallic  = 0.0f;
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

class AssetLoader
{
public:
    // Load a *.material.json file.  Returns false on parse error.
    static bool LoadMaterial(const std::string& path, MaterialAsset& out);

    // Load a *.prefab.json file.  Returns false on parse error.
    static bool LoadPrefab(const std::string& path, PrefabAsset& out);

    // Load a *.scene.json file.  Returns false on parse error.
    static bool LoadScene(const std::string& path, SceneAsset& out);
};

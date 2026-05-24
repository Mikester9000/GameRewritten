// ============================================================
// FILE: src/assets/CreationMaterialLoader.hpp
// SYSTEM: Assets
// ROLE: loads and caches Creation-Engine material JSON v1.1 files
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: CreationMaterialLoader module behavior and local implementation details.
// ============================================================

#pragma once

#include <string>
#include <vector>

// PBR material data loaded from a Creation-Engine material JSON v1.1 file.
struct CreationMaterial
{
    bool        valid       = false;
    std::string name;
    std::string shader;
    float       color[4]    = {1.0f, 1.0f, 1.0f, 1.0f};
    float       roughness   = 0.5f;
    float       metallic    = 0.0f;
    float       ao          = 1.0f;
    float       emissive[3] = {0.0f, 0.0f, 0.0f};
    std::string texAlbedo;
    std::string texNormal;
    std::string texRoughness;
    std::string texMetallic;
    std::string texAO;
    std::string texEmissive;
};

// Loads Creation-Engine material JSON v1.1 files into a static cache.
// Supports both v1.1 and legacy (no version field) formats.
class CreationMaterialLoader
{
public:
    // Load a single *.material.json file and cache it by material name.
    // Returns an invalid CreationMaterial on error.
    static CreationMaterial Load(const std::string& jsonPath);

    // Iterate dirPath for all *.json files and call Load on each.
    // Uses std::filesystem::recursive_directory_iterator (C++17).
    static void LoadDir(const std::string& dirPath);

    // Retrieve a cached material by name. Returns nullptr if not found.
    static const CreationMaterial* Get(const std::string& name);
};

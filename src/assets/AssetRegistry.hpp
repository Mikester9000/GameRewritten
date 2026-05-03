#pragma once
// AssetRegistry.hpp
// Maps scoped asset IDs (e.g. "textures.placeholder") to file paths.
// Load once at startup via Load(), reload safely on F5 via Load() again.
// If a reload fails the old registry stays intact — no crash.

#include <string>
#include <unordered_map>

class AssetRegistry
{
public:
    // Load (or reload) the registry from disk.
    // Returns true on success.  On failure the existing data is kept.
    bool Load(const std::string& path = "Content/AssetRegistry.json");

    // Look up a scoped ID such as "textures.placeholder".
    // Returns the file path string, or empty string + logs an error if not found.
    std::string GetPath(const std::string& assetId) const;

    // How many assets are currently registered.
    int Count() const { return static_cast<int>(m_assets.size()); }

private:
    std::unordered_map<std::string, std::string> m_assets;
    std::string m_registryPath;
};

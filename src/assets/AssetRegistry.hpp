#pragma once
// AssetRegistry.hpp
// Maps scoped asset IDs (e.g. "textures.placeholder") to file paths.
// Load once at startup via Load(), reload safely on F5 via Reload().
// If a reload fails the old registry stays intact — no crash.

#include <string>
#include <unordered_map>
#include <vector>

class AssetRegistry
{
public:
    // Load (or reload) the registry from the given path.
    // Returns true on success.  On failure the existing data is kept.
    bool Load(const std::string& path = "Content/AssetRegistry.json");

    // Reload from the same path used in the last Load() call.
    // Keeps old data if parsing fails — matches WorldGrid::Reload() semantics.
    bool Reload();

    // Look up a scoped ID such as "textures.placeholder".
    // Returns the file path string, or empty string + logs an error if not found.
    std::string GetPath(const std::string& assetId) const;

    // Returns all registered asset IDs that start with 'prefix'.
    // Example: GetIdsByPrefix("prefabs.") returns {"prefabs.tree", ...}.
    std::vector<std::string> GetIdsByPrefix(const std::string& prefix) const;

    // How many assets are currently registered.
    int Count() const { return static_cast<int>(m_assets.size()); }

private:
    std::unordered_map<std::string, std::string> m_assets;
    std::string m_registryPath;
};

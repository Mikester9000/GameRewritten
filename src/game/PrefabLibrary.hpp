// ============================================================
// FILE: src/game/PrefabLibrary.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PrefabLibrary module behavior and local implementation details.
// ============================================================

#pragma once
// PrefabLibrary.hpp
// Loads and caches PrimitivePrefab definitions from JSON files.
//
// Usage:
//   PrefabLibrary lib;
//   lib.Load(registry);                      // call at startup or after F5 reload
//   const PrimitivePrefab* p = lib.GetPrefab("prefabs.tree_oak");
//   if (p) { /* expand parts into renderer */ }

#include "PrefabDef.hpp"
#include <string>
#include <unordered_map>

class AssetRegistry;

class PrefabLibrary
{
public:
    // Load all "prefabs.*" entries from the registry.
    // Each entry's path is opened and parsed as a PrimitivePrefab JSON file.
    // If a file is missing or unparseable a warning is logged and it is skipped.
    // Safe to call repeatedly — existing cache is rebuilt from scratch each time.
    void Load(const AssetRegistry& registry);

    // Convenience alias used on F5 reload.
    void Reload(const AssetRegistry& registry) { Load(registry); }

    // Look up a prefab by its asset registry ID (e.g. "prefabs.tree_oak").
    // Returns nullptr if the ID was not loaded (missing file, parse error, etc.).
    const PrimitivePrefab* GetPrefab(const std::string& assetId) const;

    // How many prefabs are currently cached.
    int Count() const { return static_cast<int>(m_prefabs.size()); }

private:
    std::unordered_map<std::string, PrimitivePrefab> m_prefabs;
};

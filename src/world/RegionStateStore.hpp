#pragma once
// RegionStateStore.hpp
// Persists per-region mutable state (cleared enemies, opened chests, visited
// flags) so streamed-out regions remember their state on reload.

#include <string>
#include <unordered_map>
#include <unordered_set>

struct RegionState
{
    std::unordered_set<int> openedChestIds;
    std::unordered_set<int> killedEnemyIds;
    bool                    playerVisited = false;
};

class RegionStateStore
{
public:
    // Returns (creating if absent) the mutable state for a region key.
    RegionState& Get(const std::string& regionKey);
    const RegionState* Find(const std::string& regionKey) const;

    bool HasRegion(const std::string& regionKey) const;
    void Clear();

private:
    std::unordered_map<std::string, RegionState> m_store;
};

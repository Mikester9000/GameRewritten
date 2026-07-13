// RegionStateStore.cpp
// Per-region mutable state persistence for streaming worlds.

#include "RegionStateStore.hpp"

RegionState& RegionStateStore::Get(const std::string& regionKey)
{
    return m_store[regionKey];
}

const RegionState* RegionStateStore::Find(const std::string& regionKey) const
{
    auto it = m_store.find(regionKey);
    return it != m_store.end() ? &it->second : nullptr;
}

bool RegionStateStore::HasRegion(const std::string& regionKey) const
{
    return m_store.count(regionKey) > 0;
}

void RegionStateStore::Clear()
{
    m_store.clear();
}

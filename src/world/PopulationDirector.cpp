// PopulationDirector.cpp
// Biome-aware spawn table director.

#include "PopulationDirector.hpp"

void PopulationDirector::RegisterTable(const std::string& biomeId, SpawnTable table)
{
    m_tables[biomeId] = std::move(table);
}

bool PopulationDirector::HasTable(const std::string& biomeId) const
{
    return m_tables.count(biomeId) > 0;
}

const SpawnEntry* PopulationDirector::Roll(const std::string& biomeId, int randomSeed) const
{
    auto it = m_tables.find(biomeId);
    if (it == m_tables.end()) return nullptr;

    const SpawnTable& table = it->second;
    const int total = table.TotalWeight();
    if (total <= 0) return nullptr;

    return table.Roll(randomSeed % total);
}

#pragma once
// PopulationDirector.hpp
// Decides spawn type and composition for each world cell based on biome.
// Consults the SpawnTable registry; results are handed to WorldGrid refresh.

#include <string>
#include <unordered_map>
#include <vector>
#include "SpawnTable.hpp"

class PopulationDirector
{
public:
    // Register a spawn table for a biome id.
    void RegisterTable(const std::string& biomeId, SpawnTable table);

    // Returns a recommended spawn entry for a cell in biomeId, using rand seed.
    // Returns nullptr if no table is registered for this biome.
    const SpawnEntry* Roll(const std::string& biomeId, int randomSeed) const;

    bool HasTable(const std::string& biomeId) const;

private:
    std::unordered_map<std::string, SpawnTable> m_tables;
};

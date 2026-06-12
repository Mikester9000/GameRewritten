// ============================================================
// FILE: src/game/loot/LootTable.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: LootTable module behavior and local implementation details.
// ============================================================

// LootTable.cpp
// Implements singleton loot table registration and weighted random roll.

#include "LootTable.hpp"

#include <cstdlib>   // rand / RAND_MAX
#include <numeric>   // std::accumulate

LootTable& LootTable::Get()
{
    static LootTable instance;
    return instance;
}

void LootTable::Register(int enemyType, std::vector<LootEntry> entries)
{
    m_table[enemyType] = std::move(entries);
}

int LootTable::Roll(int enemyType)
{
    // --- Guard: unknown enemy type ---
    const auto it = m_table.find(enemyType);
    if (it == m_table.end() || it->second.empty())
        return -1;

    const std::vector<LootEntry>& entries = it->second;

    // --- Sum weights ---
    float totalWeight = 0.0f;
    for (const LootEntry& entry : entries)
        totalWeight += entry.weight;

    if (totalWeight <= 0.0f)
        return -1;

    // --- Weighted pick using a uniform random float in [0, totalWeight) ---
    const float roll = totalWeight * (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) + 1.0f));

    float accumulated = 0.0f;
    for (const LootEntry& entry : entries)
    {
        accumulated += entry.weight;
        if (roll < accumulated)
            return entry.itemID;
    }

    // Fallback: return the last entry (handles floating-point edge cases).
    return entries.back().itemID;
}

const char* LootTable::ItemName(int itemID)
{
    switch (itemID)
    {
    case 1: return "Health Herb";
    case 2: return "Ore Shard";
    default: return "Unknown Item";
    }
}

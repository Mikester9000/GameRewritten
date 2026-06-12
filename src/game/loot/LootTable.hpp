// ============================================================
// FILE: src/game/loot/LootTable.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: LootTable module behavior and local implementation details.
// ============================================================

#pragma once
// LootTable.hpp
// Singleton loot registry.  Enemy types register their drop entries at scene
// init time; on death, the enemy type is used to roll a weighted random item.

#include <string>
#include <unordered_map>
#include <vector>

// One entry in a drop table for a specific enemy type.
struct LootEntry
{
    int   itemID; // matches an ItemName() key
    float weight; // relative probability (not required to sum to 1.0)
    int   qty;    // quantity dropped (informational; not yet consumed by inventory)
};

class LootTable
{
public:
    // Singleton accessor.
    static LootTable& Get();

    // Register a drop list for a given enemy type.  Replaces any prior entry.
    void Register(int enemyType, std::vector<LootEntry> entries);

    // Weighted random pick from the registered entries for enemyType.
    // Returns itemID on a hit, or -1 when nothing drops or the type is unknown.
    int Roll(int enemyType);

    // Human-readable item name for a given item ID.
    // Returns "Unknown Item" for unrecognised IDs.
    static const char* ItemName(int itemID);

private:
    LootTable() = default;

    std::unordered_map<int, std::vector<LootEntry>> m_table;
};

#pragma once
// SpawnTable.hpp
// Data-driven spawn composition: solo / pair / pack presets per enemy type.
// Used by the Population Director and WorldGrid refresh to decide how many
// enemies to spawn at a given encounter point.

#include <string>
#include <vector>

enum class SpawnComposition { Solo, Pair, Pack };

struct SpawnEntry
{
    std::string      archetypeId; // must match EnemyArchetypeProfile::id
    SpawnComposition composition = SpawnComposition::Solo;
    int              weight      = 10; // higher = more likely to be selected
    int              minCount    = 1;
    int              maxCount    = 1;  // set by composition preset below
};

// Returns a count range for a composition preset.
inline void ApplyCompositionPreset(SpawnEntry& e)
{
    switch (e.composition)
    {
    case SpawnComposition::Solo: e.minCount = 1; e.maxCount = 1; break;
    case SpawnComposition::Pair: e.minCount = 2; e.maxCount = 2; break;
    case SpawnComposition::Pack: e.minCount = 3; e.maxCount = 5; break;
    }
}

// A weighted collection of spawn entries for a biome / encounter slot.
struct SpawnTable
{
    std::string            tableId;
    std::vector<SpawnEntry> entries;

    // Weighted random roll: caller provides a value in [0, totalWeight).
    const SpawnEntry* Roll(int randomValue) const
    {
        int accum = 0;
        for (const SpawnEntry& e : entries)
        {
            accum += e.weight;
            if (randomValue < accum) return &e;
        }
        return entries.empty() ? nullptr : &entries.back();
    }

    int TotalWeight() const
    {
        int t = 0;
        for (const SpawnEntry& e : entries) t += e.weight;
        return t;
    }
};

#pragma once
// AbilityProgression.hpp — Task 054 (ORDER 50): Ability unlock / progression hook
// Defines Ability entries and AbilityProgression: level-gated unlock table,
// query helpers, and a simple unlock callback hook for runtime integration.

#include <functional>
#include <string>
#include <utility>
#include <vector>

namespace gr {

// ── Ability definition ────────────────────────────────────────────────────────
struct Ability
{
    std::string id;           // unique key, e.g. "surge_strike"
    std::string displayName;  // shown in menus
    int         unlockLevel = 1; // player level required to unlock
    int         mpCost      = 0; // MP cost to use
    float       cooldown    = 0.0f; // seconds between uses (0 = no cooldown)
    bool        isPassive   = false; // passive abilities activate automatically

    bool IsUnlocked(int playerLevel) const { return playerLevel >= unlockLevel; }
};

// ── Progression table ─────────────────────────────────────────────────────────
class AbilityProgression
{
public:
    // Optional callback invoked when a new ability unlocks (level-up event).
    // Signature: void(const Ability&)
    using UnlockCallback = std::function<void(const Ability&)>;

    AbilityProgression();

    // Register a callback fired on every new unlock.
    void SetUnlockCallback(UnlockCallback cb) { m_onUnlock = std::move(cb); }

    // Call after each level-up: checks for newly unlocked abilities and fires
    // the callback once per newly unlocked entry.
    void NotifyLevelUp(int newLevel);

    // True if the given ability ID is unlocked at this player level.
    bool IsUnlocked(const std::string& id, int playerLevel) const;

    // Returns all abilities unlocked at or below playerLevel.
    std::vector<const Ability*> GetUnlocked(int playerLevel) const;

    // Read-only access to the full table for UI display.
    const std::vector<Ability>& GetAll() const { return m_abilities; }

    // Add a custom ability entry (allows data-driven extension).
    void Register(Ability ability) { m_abilities.push_back(std::move(ability)); }

private:
    std::vector<Ability> m_abilities;
    UnlockCallback       m_onUnlock;
    int                  m_lastNotifiedLevel = 0;

    // Populate the default ability table.
    void BuildDefaultTable();
};

} // namespace gr

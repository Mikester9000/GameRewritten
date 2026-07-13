// ============================================================
// FILE: src/equipment/ability_unlock.h
// SYSTEM: Equipment
// ROLE: tracks per-weapon ability unlock progress by use count
// DO NOT: store weapon stats here; see upgrade_tree.h.
// OWNS: ability use-count and unlock-threshold state.
// ============================================================
//
// [LEGO BLOCK: WEAPON ABILITY UNLOCK]
// -----------------------------------------------------------------
// What it does: unlocks abilities when a weapon has been used
//   enough times (e.g. "Firebolt: unlocked after 50 casts").
//
// EXTEND: add XP-based unlocks or multi-tier thresholds by
//   expanding AbilityProgress with a tierCount field.
//
// EXAMPLE — call on every weapon swing:
//   #include "equipment/ability_unlock.h"
//   gr::WeaponAbilityUnlock m_abilityUnlock;
//   m_abilityUnlock.SetRequirement("sword_spin", 30);
//   m_abilityUnlock.RegisterUse("sword_spin");
//   if (m_abilityUnlock.IsUnlocked("sword_spin"))
//       hud.ShowAbilityUnlocked("Spinning Slash");
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>

namespace gr
{
struct AbilityProgress
{
    int useCount = 0;
    int unlockAtUses = 1;
};

class WeaponAbilityUnlock
{
public:
    void SetRequirement(const std::string& abilityId, int requiredUses);
    void RegisterUse(const std::string& abilityId);
    bool IsUnlocked(const std::string& abilityId) const;
    int GetUseCount(const std::string& abilityId) const;

private:
    std::unordered_map<std::string, AbilityProgress> m_progress;
};
} // namespace gr

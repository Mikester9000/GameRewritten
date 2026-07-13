// ============================================================
// FILE: src/equipment/transmog_system.h
// SYSTEM: Equipment
// ROLE: cosmetic appearance overrides per equipment slot
// DO NOT: affect item stats; appearance is purely visual.
// OWNS: set of unlocked appearances and active slot overrides.
// ============================================================
//
// [LEGO BLOCK: TRANSMOG SYSTEM]
// -----------------------------------------------------------------
// What it does: lets the player change the visual of any equipment
//   slot to any appearance they have previously unlocked, without
//   changing the item's stats. Classic FF-style glamour system.
//
// EXTEND: add per-dye-colour overrides by extending the data stored
//   per slot, e.g. change m_slotOverrides value from string to a
//   struct { string appearanceId; string dyeId; }.
//
// EXAMPLE — apply glamour from an equipment screen:
//   #include "equipment/transmog_system.h"
//   gr::TransmogSystem m_transmog;
//   m_transmog.UnlockAppearance("knight_helm_gold");
//   m_transmog.SetAppearanceForSlot("head", "knight_helm_gold");
//   std::string visual = m_transmog.GetAppearanceForSlot("head");
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace gr
{
class TransmogSystem
{
public:
    bool UnlockAppearance(const std::string& appearanceId);
    bool IsAppearanceUnlocked(const std::string& appearanceId) const;
    bool SetAppearanceForSlot(const std::string& slotId, const std::string& appearanceId);
    std::string GetAppearanceForSlot(const std::string& slotId) const;

private:
    std::unordered_set<std::string> m_unlockedAppearances;
    std::unordered_map<std::string, std::string> m_slotOverrides;
};
} // namespace gr

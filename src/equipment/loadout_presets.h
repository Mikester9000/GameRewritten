// ============================================================
// FILE: src/equipment/loadout_presets.h
// SYSTEM: Equipment
// ROLE: save and recall named equipment slot configurations
// DO NOT: apply stats or validate items here.
// OWNS: preset storage keyed by preset name.
// ============================================================
//
// [LEGO BLOCK: LOADOUT PRESETS]
// -----------------------------------------------------------------
// What it does: stores named snapshots of equipment slot
//   assignments so the player can quickly swap builds.
//   EquipmentSlots is a map from slot-name to item-ID string.
//
// EXTEND: add a "rename preset" method or persist to save data
//   by serialising m_presets through SaveLoadSystem.
//
// EXAMPLE — bind to a UI preset button:
//   #include "equipment/loadout_presets.h"
//   gr::LoadoutPresets m_loadoutPresets;
//   m_loadoutPresets.SavePreset("tank", currentSlots);
//   EquipmentSlots slots = m_loadoutPresets.GetPreset("tank");
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>

namespace gr
{
using EquipmentSlots = std::unordered_map<std::string, std::string>;

class LoadoutPresets
{
public:
    void SavePreset(const std::string& presetId, const EquipmentSlots& slots);
    bool HasPreset(const std::string& presetId) const;
    EquipmentSlots GetPreset(const std::string& presetId) const;

private:
    std::unordered_map<std::string, EquipmentSlots> m_presets;
};
} // namespace gr

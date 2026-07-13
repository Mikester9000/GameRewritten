// ============================================================
// FILE: src/equipment/visual_change.h
// SYSTEM: Equipment
// ROLE: runtime visual asset overrides per equipment slot
// DO NOT: modify transmog unlock state; see transmog_system.h.
// OWNS: slot-to-visual-asset mapping for the current session.
// ============================================================
//
// [LEGO BLOCK: EQUIPMENT VISUAL CHANGE]
// -----------------------------------------------------------------
// What it does: maps slot names (e.g. "weapon", "armor") to visual
//   asset IDs that the renderer will use instead of the base model.
//   Complements TransmogSystem — this is the runtime "what to draw"
//   layer; TransmogSystem is the "what is unlocked" layer.
//
// EXTEND: add a secondary "particle effect" field per slot to
//   drive aura/glow effects without additional render passes.
//
// EXAMPLE — apply a weapon skin after equipping:
//   #include "equipment/visual_change.h"
//   gr::EquipmentVisualChange m_equipVisuals;
//   m_equipVisuals.SetVisualForSlot("weapon", "sword_flame_skin");
//   renderer.SetMeshOverride("weapon", m_equipVisuals.GetVisualForSlot("weapon"));
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>

namespace gr
{
class EquipmentVisualChange
{
public:
    void SetVisualForSlot(const std::string& slotId, const std::string& visualAssetId);
    std::string GetVisualForSlot(const std::string& slotId) const;
    void Clear();

private:
    std::unordered_map<std::string, std::string> m_slotToVisual;
};
} // namespace gr

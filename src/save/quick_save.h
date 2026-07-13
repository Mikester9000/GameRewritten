// ============================================================
// FILE: src/save/quick_save.h
// SYSTEM: Save
// ROLE: quick-save controller with cooldown gating
// DO NOT: perform file I/O here; delegate to SaveLoadSystem.
// OWNS: quick-save slot index and cooldown timer.
// ============================================================
//
// [LEGO BLOCK: QUICK SAVE CONTROLLER]
// -----------------------------------------------------------------
// What it does: guards quick-save triggers with a configurable
//   cooldown so the player cannot spam-save and corrupt state.
//   Call CanTrigger() before writing; call MarkTriggered() after.
//
// EXTEND: add a "saving in progress" flag to prevent concurrent
//   saves, or integrate with an auto-save interval timer.
//
// EXAMPLE — trigger a quick save on F9:
//   #include "save/quick_save.h"
//   gr::QuickSaveController m_quickSave;
//   m_quickSave.SetQuickSlot(0);
//   if (f9Pressed && m_quickSave.CanTrigger(gameTimeSec))
//   {
//       saveSystem.Save("slot0.json", ...);
//       m_quickSave.MarkTriggered(gameTimeSec);
//       hud.ShowSavingIndicator(1.5f);
//   }
// -----------------------------------------------------------------

#pragma once

namespace gr
{
class QuickSaveController
{
public:
    void SetQuickSlot(int slotIndex);
    int GetQuickSlot() const { return m_slotIndex; }
    bool CanTrigger(float currentTimeSeconds) const;
    void MarkTriggered(float currentTimeSeconds);

private:
    int m_slotIndex = 0;
    float m_lastTriggerTime = -9999.0f;
    float m_cooldownSeconds = 0.35f;
};
} // namespace gr

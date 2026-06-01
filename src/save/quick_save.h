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

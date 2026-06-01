#include "quick_save.h"

#include <algorithm>

namespace gr
{
void QuickSaveController::SetQuickSlot(int slotIndex)
{
    m_slotIndex = std::max(slotIndex, 0);
}

bool QuickSaveController::CanTrigger(float currentTimeSeconds) const
{
    return (currentTimeSeconds - m_lastTriggerTime) >= m_cooldownSeconds;
}

void QuickSaveController::MarkTriggered(float currentTimeSeconds)
{
    m_lastTriggerTime = currentTimeSeconds;
}
} // namespace gr

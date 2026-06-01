#include "visual_change.h"

namespace gr
{
void EquipmentVisualChange::SetVisualForSlot(const std::string& slotId, const std::string& visualAssetId)
{
    if (slotId.empty())
    {
        return;
    }
    if (visualAssetId.empty())
    {
        m_slotToVisual.erase(slotId);
        return;
    }
    m_slotToVisual[slotId] = visualAssetId;
}

std::string EquipmentVisualChange::GetVisualForSlot(const std::string& slotId) const
{
    const auto it = m_slotToVisual.find(slotId);
    return it == m_slotToVisual.end() ? std::string() : it->second;
}

void EquipmentVisualChange::Clear()
{
    m_slotToVisual.clear();
}
} // namespace gr

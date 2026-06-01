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

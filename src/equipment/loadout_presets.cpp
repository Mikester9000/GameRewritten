#include "loadout_presets.h"

namespace gr
{
void LoadoutPresets::SavePreset(const std::string& presetId, const EquipmentSlots& slots)
{
    if (presetId.empty())
    {
        return;
    }
    m_presets[presetId] = slots;
}

bool LoadoutPresets::HasPreset(const std::string& presetId) const
{
    return m_presets.find(presetId) != m_presets.end();
}

EquipmentSlots LoadoutPresets::GetPreset(const std::string& presetId) const
{
    const auto it = m_presets.find(presetId);
    return it == m_presets.end() ? EquipmentSlots() : it->second;
}
} // namespace gr

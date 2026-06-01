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

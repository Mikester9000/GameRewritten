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

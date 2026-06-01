#include "transmog_system.h"

namespace gr
{
bool TransmogSystem::UnlockAppearance(const std::string& appearanceId)
{
    if (appearanceId.empty())
    {
        return false;
    }
    return m_unlockedAppearances.insert(appearanceId).second;
}

bool TransmogSystem::IsAppearanceUnlocked(const std::string& appearanceId) const
{
    return m_unlockedAppearances.find(appearanceId) != m_unlockedAppearances.end();
}

bool TransmogSystem::SetAppearanceForSlot(const std::string& slotId, const std::string& appearanceId)
{
    if (slotId.empty() || !IsAppearanceUnlocked(appearanceId))
    {
        return false;
    }
    m_slotOverrides[slotId] = appearanceId;
    return true;
}

std::string TransmogSystem::GetAppearanceForSlot(const std::string& slotId) const
{
    const auto it = m_slotOverrides.find(slotId);
    return it == m_slotOverrides.end() ? std::string() : it->second;
}
} // namespace gr

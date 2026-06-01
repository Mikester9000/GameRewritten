#include "ability_unlock.h"

#include <algorithm>

namespace gr
{
void WeaponAbilityUnlock::SetRequirement(const std::string& abilityId, int requiredUses)
{
    if (abilityId.empty())
    {
        return;
    }
    AbilityProgress& progress = m_progress[abilityId];
    progress.unlockAtUses = std::max(requiredUses, 1);
}

void WeaponAbilityUnlock::RegisterUse(const std::string& abilityId)
{
    if (abilityId.empty())
    {
        return;
    }
    AbilityProgress& progress = m_progress[abilityId];
    ++progress.useCount;
    if (progress.unlockAtUses <= 0)
    {
        progress.unlockAtUses = 1;
    }
}

bool WeaponAbilityUnlock::IsUnlocked(const std::string& abilityId) const
{
    auto it = m_progress.find(abilityId);
    if (it == m_progress.end())
    {
        return false;
    }
    return it->second.useCount >= it->second.unlockAtUses;
}

int WeaponAbilityUnlock::GetUseCount(const std::string& abilityId) const
{
    auto it = m_progress.find(abilityId);
    return it == m_progress.end() ? 0 : it->second.useCount;
}
} // namespace gr

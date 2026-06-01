#pragma once

#include <string>
#include <unordered_map>

namespace gr
{
struct AbilityProgress
{
    int useCount = 0;
    int unlockAtUses = 1;
};

class WeaponAbilityUnlock
{
public:
    void SetRequirement(const std::string& abilityId, int requiredUses);
    void RegisterUse(const std::string& abilityId);
    bool IsUnlocked(const std::string& abilityId) const;
    int GetUseCount(const std::string& abilityId) const;

private:
    std::unordered_map<std::string, AbilityProgress> m_progress;
};
} // namespace gr

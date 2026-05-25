// AbilityProgression.cpp — Task 054 (ORDER 50): Ability unlock / progression hook
#include "AbilityProgression.hpp"
#include "../../logger/Logger.hpp"

namespace gr {

AbilityProgression::AbilityProgression()
{
    BuildDefaultTable();
}

void AbilityProgression::BuildDefaultTable()
{
    // Core combat abilities — unlock at increasing player levels.
    m_abilities = {
        { "basic_attack",   "Basic Attack",      1,  0, 0.0f, false },
        { "surge_strike",   "Surge Strike",      1, 15, 0.0f, false },
        { "limit_break",    "Limit Break",       1,  0, 0.0f, false },
        { "power_strike",   "Power Strike",      5, 20, 2.0f, false },
        { "aura_pulse",     "Aura Pulse",        8, 30, 3.0f, false },
        { "defensive_dash", "Defensive Dash",   10, 10, 1.5f, false },
        { "counter_edge",   "Counter Edge",     12, 25, 2.5f, false },
        { "blade_storm",    "Blade Storm",      15, 40, 5.0f, false },
        // Passive abilities — always active once unlocked.
        { "regen_passive",  "HP Regen",          3,  0, 0.0f, true  },
        { "atk_passive",    "Attack Up I",       6,  0, 0.0f, true  },
        { "def_passive",    "Defense Up I",      9,  0, 0.0f, true  },
        { "mp_regen",       "MP Regen Up",      11,  0, 0.0f, true  },
    };
}

void AbilityProgression::NotifyLevelUp(int newLevel)
{
    if (newLevel <= m_lastNotifiedLevel) return;

    for (const auto& ab : m_abilities)
    {
        if (ab.unlockLevel > m_lastNotifiedLevel && ab.unlockLevel <= newLevel)
        {
            GR_LOG("[AbilityProgression] Unlocked: " + ab.displayName
                   + " (level " + std::to_string(ab.unlockLevel) + ")");
            if (m_onUnlock) m_onUnlock(ab);
        }
    }
    m_lastNotifiedLevel = newLevel;
}

bool AbilityProgression::IsUnlocked(const std::string& id, int playerLevel) const
{
    for (const auto& ab : m_abilities)
        if (ab.id == id) return ab.IsUnlocked(playerLevel);
    return false;
}

std::vector<const Ability*> AbilityProgression::GetUnlocked(int playerLevel) const
{
    std::vector<const Ability*> result;
    for (const auto& ab : m_abilities)
        if (ab.IsUnlocked(playerLevel))
            result.push_back(&ab);
    return result;
}

} // namespace gr

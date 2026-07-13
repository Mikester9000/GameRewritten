// SquadCoordinator.cpp
// Role assignment to prevent zerg-rush patterns.

#include "SquadCoordinator.hpp"

#include <algorithm>

void SquadCoordinator::BuildSquad(int count)
{
    m_members.clear();
    for (int i = 0; i < count; ++i)
    {
        SquadMember m;
        m.enemyIndex = i;
        m.role       = (i < kMaxSimultaneousAttackers) ? SquadRole::Attacker
                                                        : SquadRole::Reserve;
        m_members.push_back(m);
    }
}

void SquadCoordinator::Update(const std::vector<bool>& aliveFlags)
{
    // Remove dead members.
    m_members.erase(
        std::remove_if(m_members.begin(), m_members.end(),
            [&](const SquadMember& sm) {
                return sm.enemyIndex >= static_cast<int>(aliveFlags.size())
                    || !aliveFlags[sm.enemyIndex];
            }),
        m_members.end());

    // Ensure attacker slots are filled from the reserve queue.
    int attackers = 0;
    for (SquadMember& sm : m_members)
        if (sm.role == SquadRole::Attacker) ++attackers;

    for (SquadMember& sm : m_members)
    {
        if (attackers >= kMaxSimultaneousAttackers) break;
        if (sm.role == SquadRole::Reserve)
        {
            sm.role = SquadRole::Attacker;
            ++attackers;
        }
    }
}

SquadRole SquadCoordinator::RoleOf(int enemyIndex) const
{
    for (const SquadMember& sm : m_members)
        if (sm.enemyIndex == enemyIndex) return sm.role;
    return SquadRole::Reserve;
}

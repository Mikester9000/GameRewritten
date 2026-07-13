#pragma once
// SquadCoordinator.hpp
// Coordinates groups of enemies (squads) so they don't all rush the player
// simultaneously.  Assigns roles (attacker/flanker/reserve) and enforces
// a maximum simultaneous aggressor count.

#include <vector>

class EnemyActor; // forward

enum class SquadRole { Attacker, Flanker, Reserve };

struct SquadMember
{
    int       enemyIndex = 0; // index into RuntimeScene enemy array
    SquadRole role       = SquadRole::Reserve;
};

class SquadCoordinator
{
public:
    static constexpr int kMaxSimultaneousAttackers = 2;

    // Register all visible enemies as a squad.
    void BuildSquad(int count);

    // Call each frame.  Reassigns roles so at most kMaxSimultaneousAttackers
    // are in the Attacker role at any time.  Dead/invalid entries are removed.
    // Caller passes a lambda returning true if the enemy at that index is alive.
    void Update(const std::vector<bool>& aliveFlags);

    const std::vector<SquadMember>& GetMembers() const { return m_members; }

    SquadRole RoleOf(int enemyIndex) const;

private:
    std::vector<SquadMember> m_members;
};

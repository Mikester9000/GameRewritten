#pragma once
// PartyRuntime.hpp
// Runtime party slots: up to 3 party members following the player with
// simple offset-based follow AI.  Each member inherits player-facing direction.

#include <DirectXMath.h>
#include <string>
#include <vector>

struct PartyMember
{
    int               id    = 0;
    std::string       name;
    float             x     = 0.0f;
    float             y     = 0.0f;
    float             z     = 0.0f;
    float             followOffset = 2.0f; // distance behind player
    bool              active = false;
};

class PartyRuntime
{
public:
    static constexpr int kMaxMembers = 3;

    // Add a member to the active party; returns false if party is full.
    bool AddMember(const std::string& name);
    void RemoveMember(int id);

    // Call each frame; members chase the player's position with a trailing offset.
    void Update(float dt, float leaderX, float leaderZ, float leaderYaw);

    const std::vector<PartyMember>& GetMembers() const { return m_members; }
    int ActiveCount() const;

private:
    std::vector<PartyMember> m_members;
    int                      m_nextId = 1;
};

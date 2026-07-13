// PartyRuntime.cpp
// Party member follow AI — simple offset chase behind the leader.

#include "PartyRuntime.hpp"

#include <cmath>

bool PartyRuntime::AddMember(const std::string& name)
{
    if (ActiveCount() >= kMaxMembers) return false;
    PartyMember m;
    m.id     = m_nextId++;
    m.name   = name;
    m.active = true;
    m_members.push_back(m);
    return true;
}

void PartyRuntime::RemoveMember(int id)
{
    for (PartyMember& m : m_members)
        if (m.id == id) { m.active = false; return; }
}

int PartyRuntime::ActiveCount() const
{
    int n = 0;
    for (const PartyMember& m : m_members)
        if (m.active) ++n;
    return n;
}

void PartyRuntime::Update(float dt, float leaderX, float leaderZ, float leaderYaw)
{
    int slot = 1;
    for (PartyMember& m : m_members)
    {
        if (!m.active) continue;

        // Target position: offset behind and to the side of the leader.
        const float side   = (slot % 2 == 0) ? 1.5f : -1.5f;
        const float back   = static_cast<float>(slot) * m.followOffset;
        const float tx     = leaderX - std::sin(leaderYaw) * back + std::cos(leaderYaw) * side;
        const float tz     = leaderZ - std::cos(leaderYaw) * back - std::sin(leaderYaw) * side;

        // Lerp toward target.
        const float speed  = 6.0f;
        const float dx     = tx - m.x;
        const float dz     = tz - m.z;
        const float dist   = std::sqrt(dx * dx + dz * dz);
        if (dist > 0.01f)
        {
            const float step = std::fmin(speed * dt, dist);
            m.x += dx / dist * step;
            m.z += dz / dist * step;
        }
        ++slot;
    }
}

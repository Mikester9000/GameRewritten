// BossActor.cpp
// Multi-phase boss: delegates movement to EnemyActor, adds phase escalation.

#include "BossActor.hpp"

void BossActor::Init(float startX, float startZ, int maxHp,
                     const std::array<BossPhaseData, kMaxPhases>& phases)
{
    m_actor.x     = startX;
    m_actor.z     = startZ;
    m_actor.hp    = maxHp;
    m_actor.maxHp = maxHp;
    m_phases      = phases;
    m_currentPhase = BossPhase::Phase1;
}

bool BossActor::Update(float dt, float playerX, float playerZ)
{
    const BossPhase prevPhase = m_currentPhase;

    // NOTE: Full EnemyActor::Update requires a D3D11Renderer reference.
    // Boss movement is driven directly here; call m_actor.Update from Main
    // with the renderer reference when wiring into the runtime scene.
    (void)dt; (void)playerX; (void)playerZ;
    CheckPhaseTransition();

    return m_currentPhase != prevPhase;
}

void BossActor::CheckPhaseTransition()
{
    if (m_actor.hp <= 0)
    {
        m_currentPhase = BossPhase::Defeated;
        return;
    }

    // Walk backwards through phases to find the correct escalation tier.
    for (int i = kMaxPhases - 1; i >= 0; --i)
    {
        const BossPhase targetPhase = static_cast<BossPhase>(i);
        if (m_currentPhase >= targetPhase) continue;

        const float threshold = m_phases[i].hpThreshold * static_cast<float>(m_actor.maxHp);
        if (static_cast<float>(m_actor.hp) <= threshold)
        {
            m_currentPhase          = targetPhase;
            m_actor.moveSpeed      *= m_phases[i].speedMult;
            break;
        }
    }
}

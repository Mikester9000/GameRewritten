#pragma once
// BossActor.hpp
// A multi-phase boss that escalates speed/damage as HP drops through
// configurable thresholds.  Shares the EnemyActor movement/visual base.

#include "../actors/EnemyActor.hpp"
#include "../ai/BossPhaseState.hpp"

#include <array>

class BossActor
{
public:
    // Up to 3 escalating phases (Phase1 → Phase2 → Phase3 → Defeated).
    static constexpr int kMaxPhases = 3;

    // Initialise with a maximum HP and optional custom phase data.
    void Init(float startX, float startZ, int maxHp,
              const std::array<BossPhaseData, kMaxPhases>& phases);

    // Update boss logic; call instead of EnemyActor::Update for boss entities.
    // Returns true when a phase transition fires (caller can show dialog/VFX).
    bool Update(float dt, float playerX, float playerZ);

    BossPhase     GetPhase()  const { return m_currentPhase; }
    const EnemyActor& Actor() const { return m_actor; }
          EnemyActor& Actor()       { return m_actor; }

private:
    EnemyActor                             m_actor;
    std::array<BossPhaseData, kMaxPhases>  m_phases{};
    BossPhase                              m_currentPhase = BossPhase::Phase1;

    void CheckPhaseTransition();
};

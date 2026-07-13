#pragma once
// BossPhaseState.hpp
// Phase state enumeration and data used by BossActor.
// A boss moves to the next phase when HP crosses a threshold.

#include <string>

enum class BossPhase { Phase1, Phase2, Phase3, Defeated };

struct BossPhaseData
{
    BossPhase phase        = BossPhase::Phase1;
    float     hpThreshold  = 1.0f;  // enter this phase when HP <= threshold * maxHP
    float     speedMult    = 1.0f;  // movement speed multiplier in this phase
    float     damageMult   = 1.0f;  // outgoing damage multiplier
    std::string entranceDialog;     // optional dialog line on phase entry
};

// Returns the name string for a phase (for debug / HUD display).
inline const char* BossPhaseToString(BossPhase phase)
{
    switch (phase)
    {
    case BossPhase::Phase1:   return "Phase 1";
    case BossPhase::Phase2:   return "Phase 2";
    case BossPhase::Phase3:   return "Phase 3";
    case BossPhase::Defeated: return "Defeated";
    }
    return "Unknown";
}

// ============================================================
// FILE: src/game/animation/AnimEventDispatch.cpp
// SYSTEM: Game
// ROLE: polls animation events from AnimationComponent and routes them to audio/combat
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimEventDispatch module behavior and local implementation details.
// ============================================================

#include "AnimEventDispatch.hpp"
#include "../../logger/Logger.hpp"
#include "../../../ThirdParty/src/tp_audio.hpp"

// ---------------------------------------------------------------------------
void AnimEventDispatch::Dispatch(AnimationComponent& animComp,
                                 float prevTime,
                                 CombatSystem& /*combat*/,
                                 float /*dt*/)
{
    const std::vector<AnimEvent> fired =
        animComp.GetFiredEvents(prevTime, animComp.playbackTime);

    for (const AnimEvent& ev : fired)
    {
        if (ev.type == "footstep")
        {
            tp::Audio::PlayOneShot("sfx_footstep"); // placeholder path — replaced by Task 402
        }
        else if (ev.type == "contact")
        {
            tp::Audio::PlayOneShot("sfx_impact");   // placeholder path
        }
        else if (ev.type == "hit")
        {
            // TODO: wire to CombatSystem::RegisterHitFrame when API exists.
            // CombatSystem does not currently expose RegisterHitFrame.
            LOG_INFO("AnimEventDispatch: hit event at t=" + std::to_string(ev.time));
        }
        else if (ev.type == "cancel")
        {
            // TODO: wire to CombatSystem::RegisterCancelWindow when API exists.
            LOG_INFO("AnimEventDispatch: cancel window event at t=" + std::to_string(ev.time));
        }
        else if (ev.type == "cast_release")
        {
            // TODO: wire to CombatSystem::RegisterCastRelease when API exists.
            LOG_INFO("AnimEventDispatch: cast_release event at t=" + std::to_string(ev.time));
        }
        // Unknown types are silently ignored.
    }
}

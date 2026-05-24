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
#include <filesystem>

namespace
{
constexpr const char* kFootstepSfxPath = "Content/Audio/sfx_attack_light.wav";
constexpr const char* kImpactSfxPath   = "Content/Audio/sfx_combat_parry.wav";
}

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
            if (std::filesystem::exists(kFootstepSfxPath))
                tp::Audio::PlayOneShot(kFootstepSfxPath);
        }
        else if (ev.type == "contact")
        {
            if (std::filesystem::exists(kImpactSfxPath))
                tp::Audio::PlayOneShot(kImpactSfxPath);
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

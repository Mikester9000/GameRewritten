// ============================================================
// FILE: src/game/animation/AnimationComponent.cpp
// SYSTEM: Game
// ROLE: per-actor animation state — active clip, playback time, crossfade
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimationComponent module behavior and local implementation details.
// ============================================================

#include "AnimationComponent.hpp"
#include <cmath>

// ---------------------------------------------------------------------------
void AnimationComponent::Update(float dt)
{
    if (!activeClip || !playing)
        return;

    const float dur = activeClip->durationSec;

    // Advance playback time.
    playbackTime += dt;

    if (dur > 0.0f)
    {
        if (activeClip->loop)
        {
            // Wrap looping clips.
            playbackTime = std::fmod(playbackTime, dur);
        }
        else if (playbackTime >= dur)
        {
            // Clamp one-shot clips and stop.
            playbackTime = dur;
            playing = false;
        }
    }

    // Advance blend transition.
    if (nextClip != nullptr)
    {
        if (blendDuration > 0.0f)
            blendAlpha += dt / blendDuration;
        else
            blendAlpha = 1.0f;

        if (blendAlpha >= 1.0f)
        {
            // Complete transition.
            activeClip   = nextClip;
            nextClip     = nullptr;
            blendAlpha   = 0.0f;
            playbackTime = 0.0f;
            playing      = true;
        }
    }
}

// ---------------------------------------------------------------------------
void AnimationComponent::TransitionTo(const LoadedAnimClip* clip, float crossfadeSec)
{
    if (!clip || clip == activeClip)
        return;

    nextClip      = clip;
    blendDuration = crossfadeSec > 0.0f ? crossfadeSec : 0.0f;
    blendAlpha    = 0.0f;
}

// ---------------------------------------------------------------------------
std::vector<AnimEvent> AnimationComponent::GetFiredEvents(float prevTime, float curTime) const
{
    std::vector<AnimEvent> fired;
    if (!activeClip)
        return fired;

    const bool wrappedLoop =
        activeClip->loop &&
        activeClip->durationSec > 0.0f &&
        curTime < prevTime;

    for (const AnimEvent& ev : activeClip->events)
    {
        if (!wrappedLoop)
        {
            if (ev.time > prevTime && ev.time <= curTime)
                fired.push_back(ev);
        }
        else if ((ev.time > prevTime && ev.time <= activeClip->durationSec) ||
                 (ev.time >= 0.0f && ev.time <= curTime))
        {
            fired.push_back(ev);
        }
    }
    return fired;
}

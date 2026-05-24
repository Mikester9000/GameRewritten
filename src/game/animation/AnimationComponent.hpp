// ============================================================
// FILE: src/game/animation/AnimationComponent.hpp
// SYSTEM: Game
// ROLE: per-actor animation state — active clip, playback time, crossfade
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimationComponent module behavior and local implementation details.
// ============================================================

#pragma once

#include "AnimClipLoader.hpp"
#include <vector>

// Stores active clip reference and playback state for one actor.
// Owned by the actor (player, enemy, NPC). Updated each frame by calling Update(dt).
struct AnimationComponent
{
    const LoadedAnimClip* activeClip    = nullptr; // current playing clip (not owned)
    const LoadedAnimClip* nextClip      = nullptr; // crossfade target (not owned)
    float playbackTime  = 0.0f;
    float blendAlpha    = 0.0f; // 0..1 blend progress toward nextClip
    float blendDuration = 0.2f; // seconds for crossfade
    bool  playing       = false;

    // Advance playback time and blend state by dt seconds.
    void Update(float dt);

    // Begin crossfading to a new clip over crossfadeSec seconds.
    void TransitionTo(const LoadedAnimClip* clip, float crossfadeSec);

    // Return all events whose time falls within (prevTime, curTime].
    std::vector<AnimEvent> GetFiredEvents(float prevTime, float curTime) const;
};

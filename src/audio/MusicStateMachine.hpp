#pragma once
// MusicStateMachine.hpp
// Manages adaptive BGM transitions between gameplay states (Explore, Combat,
// Boss, Cinematic, Menu).  Delegates track playback to AudioManager.

#include <string>

enum class MusicState { Menu, Explore, Combat, Boss, Cinematic };

class AudioManager; // forward

class MusicStateMachine
{
public:
    void Init(AudioManager* mgr);

    // Request a transition to a new music state.  Actual track change is
    // deferred by m_crossfadeTime seconds to avoid rapid switching.
    void RequestState(MusicState state);

    // Call each frame to advance crossfade timer and trigger pending changes.
    void Update(float dt);

    MusicState CurrentState() const { return m_current; }

private:
    AudioManager* m_mgr   = nullptr;
    MusicState    m_current  = MusicState::Menu;
    MusicState    m_pending  = MusicState::Menu;
    float         m_timer    = 0.0f;
    float         m_crossfadeTime = 1.5f; // seconds before applying pending state

    void ApplyState(MusicState state);
    static const char* TrackForState(MusicState s);
};

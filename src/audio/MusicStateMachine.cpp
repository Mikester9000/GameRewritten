// MusicStateMachine.cpp
// Adaptive BGM state transitions with crossfade delay.

#include "MusicStateMachine.hpp"
#include "AudioManager.hpp"

void MusicStateMachine::Init(AudioManager* mgr)
{
    m_mgr    = mgr;
    m_current = MusicState::Menu;
}

const char* MusicStateMachine::TrackForState(MusicState s)
{
    switch (s)
    {
    case MusicState::Menu:      return "Audio/bgm_menu.wav";
    case MusicState::Explore:   return "Audio/bgm_explore.wav";
    case MusicState::Combat:    return "Audio/bgm_combat.wav";
    case MusicState::Boss:      return "Audio/bgm_boss.wav";
    case MusicState::Cinematic: return "Audio/bgm_cinematic.wav";
    }
    return "";
}

void MusicStateMachine::RequestState(MusicState state)
{
    if (state == m_pending) return;
    m_pending = state;
    m_timer   = 0.0f;
}

void MusicStateMachine::Update(float dt)
{
    if (m_pending == m_current) return;

    m_timer += dt;
    if (m_timer >= m_crossfadeTime)
    {
        ApplyState(m_pending);
        m_current = m_pending;
    }
}

void MusicStateMachine::ApplyState(MusicState state)
{
    if (!m_mgr) return;
    m_mgr->PlayBGM(TrackForState(state));
}

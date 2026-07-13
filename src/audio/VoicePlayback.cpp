// VoicePlayback.cpp
// Voiced dialogue playback with subtitle timing.

#include "VoicePlayback.hpp"
#include "AudioManager.hpp"

#include <algorithm>

void VoicePlayback::Play(const std::string& voicePath, float durationSec)
{
    if (m_mgr) m_mgr->PlaySFX(voicePath);
    m_duration = durationSec;
    m_elapsed  = 0.0f;
    m_playing  = true;
}

void VoicePlayback::Stop()
{
    m_playing = false;
    m_elapsed = 0.0f;
}

float VoicePlayback::Progress() const
{
    if (!m_playing || m_duration <= 0.0f) return 0.0f;
    return std::min(1.0f, m_elapsed / m_duration);
}

void VoicePlayback::Update(float dt)
{
    if (!m_playing) return;
    m_elapsed += dt;
    if (m_elapsed >= m_duration) m_playing = false;
}

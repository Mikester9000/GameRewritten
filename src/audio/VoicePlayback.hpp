#pragma once
// VoicePlayback.hpp
// Plays voiced dialogue lines and exposes timing for subtitle synchronisation.

#include <string>

class AudioManager; // forward

class VoicePlayback
{
public:
    void Init(AudioManager* mgr) { m_mgr = mgr; }

    // Begin playback of voicePath; durationSec is used to time subtitle display.
    void Play(const std::string& voicePath, float durationSec);

    // Stop current line immediately.
    void Stop();

    bool IsPlaying() const { return m_playing; }

    // Returns a normalised progress [0,1] for subtitle timing.
    float Progress() const;

    // Advance playback timer each frame.
    void Update(float dt);

private:
    AudioManager* m_mgr     = nullptr;
    bool          m_playing  = false;
    float         m_elapsed  = 0.0f;
    float         m_duration = 0.0f;
};

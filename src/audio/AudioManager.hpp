// ============================================================
// FILE: src/audio/AudioManager.hpp
// SYSTEM: AudioManager.hpp
// SYSTEM: audio playback and runtime audio control

#pragma once

#include <string>

class AudioManager
{
public:
    // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
    bool PlayBGM(const std::string& path);
    // Clears AudioManager's tracked BGM state.
    // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
    void StopBGM();
    bool PlaySFX(const std::string& path);

    void SetBGMVolume(float v);
    void SetSFXVolume(float v);
    float GetBGMVolume() const { return m_bgmVolume; }
    float GetSFXVolume() const { return m_sfxVolume; }

    void Shutdown();

private:
    static float Clamp01(float v);

    float m_bgmVolume = 1.0f;
    float m_sfxVolume = 1.0f;
    bool m_loggedBgmVolumeLimit = false;
    bool m_loggedSfxVolumeLimit = false;
    bool m_bgmRequested = false;
};

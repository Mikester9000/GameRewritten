// ============================================================
// FILE: src/audio/volume_controller.h
// SYSTEM: Audio
// ROLE: per-channel and master volume control
// DO NOT: store audio device handles or drive playback here.
// OWNS: volume state and effective-volume calculation.
// ============================================================
//
// [LEGO BLOCK: AUDIO VOLUME CONTROLLER]
// -----------------------------------------------------------------
// What it does: tracks master + per-named-channel volume levels.
//
// EXTEND: add a new channel at any time by calling:
//   SetChannelVolume("yourChannel", 0.8f);
//   No code changes to this class are needed.
//
// EXAMPLE — wire into a new AudioManager:
//   #include "audio/volume_controller.h"
//   gr::AudioVolumeController m_volumeCtrl;
//   m_volumeCtrl.SetMasterVolume(settings.masterVol);
//   float vol = m_volumeCtrl.GetEffectiveVolume("sfx");
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>

namespace gr
{
class AudioVolumeController
{
public:
    void SetMasterVolume(float volume01);
    float GetMasterVolume() const { return m_masterVolume; }
    void SetChannelVolume(const std::string& channelId, float volume01);
    float GetChannelVolume(const std::string& channelId) const;
    float GetEffectiveVolume(const std::string& channelId) const;

private:
    static float Clamp01(float value);

    float m_masterVolume = 1.0f;
    std::unordered_map<std::string, float> m_channelVolume;
};
} // namespace gr

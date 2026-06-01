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

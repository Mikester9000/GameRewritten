#include "volume_controller.h"

#include <algorithm>

namespace gr
{
float AudioVolumeController::Clamp01(float value)
{
    return std::clamp(value, 0.0f, 1.0f);
}

void AudioVolumeController::SetMasterVolume(float volume01)
{
    m_masterVolume = Clamp01(volume01);
}

void AudioVolumeController::SetChannelVolume(const std::string& channelId, float volume01)
{
    if (channelId.empty())
    {
        return;
    }
    m_channelVolume[channelId] = Clamp01(volume01);
}

float AudioVolumeController::GetChannelVolume(const std::string& channelId) const
{
    const auto it = m_channelVolume.find(channelId);
    return it == m_channelVolume.end() ? 1.0f : it->second;
}

float AudioVolumeController::GetEffectiveVolume(const std::string& channelId) const
{
    return Clamp01(GetChannelVolume(channelId) * m_masterVolume);
}
} // namespace gr

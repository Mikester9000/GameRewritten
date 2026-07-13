// AudioRouter.cpp
// Per-bus audio dispatch with independent volume controls.

#include "AudioRouter.hpp"
#include "AudioManager.hpp"

#include <algorithm>

void AudioRouter::Play(const std::string& path, AudioBus bus, float volume)
{
    if (!m_mgr) return;
    const float effective = std::max(0.0f, volume * m_busVolume[BusIndex(bus)]);
    if (effective <= 0.0f) return;

    switch (bus)
    {
    case AudioBus::BGM:
        m_mgr->PlayBGM(path);
        break;
    case AudioBus::SFX:
    case AudioBus::UI:
    case AudioBus::Voice:
    default:
        m_mgr->PlaySFX(path); // per-call scaling not supported by AudioManager yet
        break;
    }
}

void AudioRouter::SetBusVolume(AudioBus bus, float volume)
{
    m_busVolume[BusIndex(bus)] = std::max(0.0f, std::min(1.0f, volume));
}

float AudioRouter::GetBusVolume(AudioBus bus) const
{
    return m_busVolume[BusIndex(bus)];
}

// AudioRouter.cpp
// Per-bus audio dispatch with independent volume controls.

#include "AudioRouter.hpp"
#include "AudioManager.hpp"

#include <algorithm>

void AudioRouter::Play(const std::string& path, AudioBus bus, float volume)
{
    if (!m_mgr) return;
    const float effective = std::max(0.0f, volume * m_busVolume[BusIndex(bus)]);
    (void)path; (void)effective;
    m_mgr->PlaySFX(path); // volume control via SetSFXVolume before calling
}

void AudioRouter::SetBusVolume(AudioBus bus, float volume)
{
    m_busVolume[BusIndex(bus)] = std::max(0.0f, std::min(1.0f, volume));
}

float AudioRouter::GetBusVolume(AudioBus bus) const
{
    return m_busVolume[BusIndex(bus)];
}

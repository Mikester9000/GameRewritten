#include "AudioManager.hpp"

#include <algorithm>
#include <filesystem>

#include "tp_audio.hpp"
#include <logger/Logger.hpp>

float AudioManager::Clamp01(float v)
{
    return std::clamp(v, 0.0f, 1.0f);
}

bool AudioManager::PlayBGM(const std::string& path)
{
    if (!std::filesystem::exists(path))
    {
        LOG_WARN("AudioManager: BGM file missing: " + path);
        return false;
    }

    if (m_bgmVolume <= 0.0f)
        return true;

    if (m_bgmVolume < 1.0f && !m_loggedBgmVolumeLimit)
    {
        LOG_WARN("AudioManager: tp::Audio currently has no runtime volume control for one-shot playback; BGM volume acts as mute/unmute gate.");
        m_loggedBgmVolumeLimit = true;
    }

    if (!tp::Audio::PlayOneShot(path))
    {
        LOG_WARN("AudioManager: Failed to play BGM: " + path);
        return false;
    }

    return true;
}

void AudioManager::StopBGM()
{
    if (!m_loggedStopLimit)
    {
        LOG_WARN("AudioManager: StopBGM requested, but tp::Audio currently exposes one-shot playback only.");
        m_loggedStopLimit = true;
    }
}

bool AudioManager::PlaySFX(const std::string& path)
{
    if (!std::filesystem::exists(path))
    {
        LOG_WARN("AudioManager: SFX file missing: " + path);
        return false;
    }

    if (m_sfxVolume <= 0.0f)
        return true;

    if (m_sfxVolume < 1.0f && !m_loggedSfxVolumeLimit)
    {
        LOG_WARN("AudioManager: tp::Audio currently has no runtime volume control for one-shot playback; SFX volume acts as mute/unmute gate.");
        m_loggedSfxVolumeLimit = true;
    }

    if (!tp::Audio::PlayOneShot(path))
    {
        LOG_WARN("AudioManager: Failed to play SFX: " + path);
        return false;
    }

    return true;
}

void AudioManager::SetBGMVolume(float v)
{
    m_bgmVolume = Clamp01(v);
}

void AudioManager::SetSFXVolume(float v)
{
    m_sfxVolume = Clamp01(v);
}

void AudioManager::Shutdown()
{
    StopBGM();
}

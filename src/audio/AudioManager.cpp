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

    if (!tp::Audio::PlayOneShot(path))
    {
        LOG_WARN("AudioManager: Failed to play BGM: " + path);
        return false;
    }

    return true;
}

void AudioManager::StopBGM()
{
    // tp::Audio currently exposes one-shot playback only.
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

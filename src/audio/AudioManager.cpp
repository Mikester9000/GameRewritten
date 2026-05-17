// ============================================================
// FILE: src/audio/AudioManager.cpp
// SYSTEM: Audio
// ROLE: audio playback and runtime audio control
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AudioManager module behavior and local implementation details.
// ============================================================

#include "AudioManager.hpp"

#include <algorithm>
#include <filesystem>
#include <system_error>

#include "tp_audio.hpp"
#include <logger/Logger.hpp>

float AudioManager::Clamp01(float v)
{
    return std::clamp(v, 0.0f, 1.0f);
}

static void LogPlayFailure(const char* kind, const std::string& path)
{
    std::error_code ec;
    const bool exists = std::filesystem::exists(path, ec);
    if (ec)
    {
        LOG_WARN(std::string("AudioManager: ") + kind + " play failed: " + path +
                 " (could not verify file: " + ec.message() + ")");
        return;
    }

    if (!exists)
    {
        LOG_WARN(std::string("AudioManager: ") + kind + " file missing: " + path);
        return;
    }

    LOG_WARN(std::string("AudioManager: Failed to play ") + kind + ": " + path);
}

bool AudioManager::PlayBGM(const std::string& path)
{
    if (m_bgmVolume <= 0.0f)
        return true;

    if (m_bgmVolume < 1.0f && !m_loggedBgmVolumeLimit)
    {
        LOG_WARN("AudioManager: tp::Audio has no runtime volume control for one-shot playback; BGM volume currently works as mute/unmute for future plays.");
        m_loggedBgmVolumeLimit = true;
    }

    if (!tp::Audio::PlayOneShot(path))
    {
        LogPlayFailure("BGM", path);
        return false;
    }

    m_bgmRequested = true;
    return true;
}

void AudioManager::StopBGM()
{
    m_bgmRequested = false;
}

bool AudioManager::PlaySFX(const std::string& path)
{
    if (m_sfxVolume <= 0.0f)
        return true;

    if (m_sfxVolume < 1.0f && !m_loggedSfxVolumeLimit)
    {
        LOG_WARN("AudioManager: tp::Audio has no runtime volume control for one-shot playback; SFX volume currently works as mute/unmute for future plays.");
        m_loggedSfxVolumeLimit = true;
    }

    if (!tp::Audio::PlayOneShot(path))
    {
        LogPlayFailure("SFX", path);
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
    if (m_bgmRequested)
        StopBGM();
}

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

// Audio asset paths (keyed from Content/AssetRegistry.json audio.* entries).
// BGM
static constexpr const char* kBgmFieldDay           = "Content/Audio/bgm_field_day.ogg";
static constexpr const char* kBgmBattleStandard     = "Content/Audio/bgm_battle_standard.ogg";
// Ambient
static constexpr const char* kAmbForestDay          = "Content/Audio/amb_forest_day_loop.wav";
// Stingers / fanfares
static constexpr const char* kStingerVictory        = "Content/Audio/stinger_victory_short.wav";
// SFX
static constexpr const char* kSfxAttackLight        = "Content/Audio/sfx_attack_light.wav";
static constexpr const char* kSfxCombatParry        = "Content/Audio/sfx_combat_parry.wav";
static constexpr const char* kSfxUiConfirm          = "Content/Audio/sfx_ui_confirm.wav";
static constexpr const char* kSfxUiCancel           = "Content/Audio/sfx_ui_cancel.wav";
static constexpr const char* kSfxUiError            = "Content/Audio/sfx_ui_error.wav";

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

// --- BGM (looping) ---

bool AudioManager::PlayBGM(const std::string& path)
{
    if (m_bgmVolume <= 0.0f)
        return true;

    if (!tp::Audio::PlayBGM(path))
    {
        LogPlayFailure("BGM", path);
        return false;
    }

    m_bgmActive = true;
    LOG_INFO("AudioManager: BGM started: " + path);
    return true;
}

void AudioManager::StopBGM()
{
    tp::Audio::StopBGM();
    m_bgmActive = false;
}

// --- Ambient (looping) ---

bool AudioManager::PlayAmbient(const std::string& path)
{
    if (m_sfxVolume <= 0.0f)
        return true;

    if (!tp::Audio::PlayAmbient(path))
    {
        LogPlayFailure("Ambient", path);
        return false;
    }

    m_ambActive = true;
    LOG_INFO("AudioManager: Ambient started: " + path);
    return true;
}

void AudioManager::StopAmbient()
{
    tp::Audio::StopAmbient();
    m_ambActive = false;
}

// --- One-shot SFX ---

bool AudioManager::PlaySFXInternal(const std::string& path)
{
    if (!tp::Audio::PlayOneShot(path))
    {
        LogPlayFailure("SFX", path);
        return false;
    }
    return true;
}

bool AudioManager::PlaySFX(const std::string& path)
{
    if (m_sfxVolume <= 0.0f)
        return true;
    return PlaySFXInternal(path);
}

// --- Named gameplay audio hooks ---

void AudioManager::PlayVictoryFanfare()
{
    if (m_sfxVolume <= 0.0f)
        return;
    // Pause BGM briefly while fanfare plays (leave BGM running underneath for now).
    PlaySFXInternal(kStingerVictory);
    LOG_INFO("AudioManager: Victory fanfare triggered.");
}

void AudioManager::PlayTacticalPauseEnter()
{
    if (m_sfxVolume <= 0.0f)
        return;
    PlaySFXInternal(kSfxUiConfirm);
}

void AudioManager::PlayTacticalPauseExit()
{
    if (m_sfxVolume <= 0.0f)
        return;
    PlaySFXInternal(kSfxUiCancel);
}

void AudioManager::PlayLockOnAcquire()
{
    if (m_sfxVolume <= 0.0f)
        return;
    PlaySFXInternal(kSfxUiConfirm);
}

void AudioManager::PlayLockOnBreak()
{
    if (m_sfxVolume <= 0.0f)
        return;
    PlaySFXInternal(kSfxUiCancel);
}

void AudioManager::PlayEnemyAlertBark()
{
    if (m_sfxVolume <= 0.0f)
        return;
    PlaySFXInternal(kSfxUiError);
    LOG_INFO("AudioManager: Enemy alert bark.");
}

void AudioManager::PlayParrySFX()
{
    if (m_sfxVolume <= 0.0f)
        return;
    PlaySFXInternal(kSfxCombatParry);
}

void AudioManager::SetCombatState(bool inCombat)
{
    if (m_inCombat == inCombat)
        return;

    m_inCombat = inCombat;
    const std::string trackPath = inCombat ? kBgmBattleStandard : kBgmFieldDay;
    if (!PlayBGM(trackPath))
    {
        LOG_WARN("AudioManager: combat state switched, but requested BGM failed to play.");
        return;
    }

    LOG_INFO(std::string("AudioManager: combat BGM state -> ") + (inCombat ? "battle" : "explore"));
}

// --- Volume ---

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
    StopAmbient();
}

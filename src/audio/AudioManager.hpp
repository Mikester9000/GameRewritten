// ============================================================
// FILE: src/audio/AudioManager.hpp
// SYSTEM: Audio
// ROLE: audio playback and runtime audio control
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AudioManager module behavior and local implementation details.
// ============================================================

#pragma once

#include <string>

class AudioManager
{
public:
    // --- BGM (looping background music) ---
    // Starts a looping BGM track. Replaces any currently-playing BGM.
    bool PlayBGM(const std::string& path);
    // Stops the currently-playing looping BGM.
    void StopBGM();

    // --- Ambient audio (looping environment sounds) ---
    // Starts a looping ambient track. Replaces any currently-playing ambient.
    bool PlayAmbient(const std::string& path);
    // Stops the currently-playing ambient track.
    void StopAmbient();

    // --- One-shot SFX ---
    bool PlaySFX(const std::string& path);

    // --- Named gameplay audio hooks ---
    // Plays the short victory stinger after an enemy is defeated.
    void PlayVictoryFanfare();
    // Plays the tactical-pause enter chime.
    void PlayTacticalPauseEnter();
    // Plays the tactical-pause exit chime.
    void PlayTacticalPauseExit();
    // Plays the lock-on acquire click.
    void PlayLockOnAcquire();
    // Plays the lock-on break/release sound.
    void PlayLockOnBreak();
    // Plays the enemy alert bark (enemy spots player).
    void PlayEnemyAlertBark();
    // Plays the parry / counter SFX.
    void PlayParrySFX();
    // Switches between exploration and combat BGM tracks.
    void SetCombatState(bool inCombat);

    // --- Volume control ---
    void SetBGMVolume(float v);
    void SetSFXVolume(float v);
    float GetBGMVolume() const { return m_bgmVolume; }
    float GetSFXVolume() const { return m_sfxVolume; }

    void Shutdown();

private:
    static float Clamp01(float v);
    bool PlaySFXInternal(const std::string& path);

    float m_bgmVolume = 1.0f;
    float m_sfxVolume = 1.0f;
    bool m_loggedBgmVolumeLimit = false;
    bool m_loggedSfxVolumeLimit = false;
    bool m_bgmActive = false;
    bool m_ambActive = false;
    bool m_inCombat = false;
};

#pragma once

#include <string>

class AudioManager
{
public:
    bool PlayBGM(const std::string& path);
    void StopBGM();
    bool PlaySFX(const std::string& path);

    void SetBGMVolume(float v);
    void SetSFXVolume(float v);
    float GetBGMVolume() const { return m_bgmVolume; }
    float GetSFXVolume() const { return m_sfxVolume; }

    void Shutdown();

private:
    static float Clamp01(float v);

    float m_bgmVolume = 1.0f;
    float m_sfxVolume = 1.0f;
};

#pragma once
// AudioRouter.hpp
// Routes audio events to the correct AudioManager bus (SFX, BGM, UI, Voice)
// so volume controls and muting can target specific channels independently.

#include <string>

enum class AudioBus { SFX, BGM, UI, Voice };

class AudioManager; // forward

class AudioRouter
{
public:
    void Init(AudioManager* mgr) { m_mgr = mgr; }

    // Play a one-shot sound on the specified bus.
    void Play(const std::string& path, AudioBus bus, float volume = 1.0f);

    // Set a per-bus volume multiplier [0,1].
    void SetBusVolume(AudioBus bus, float volume);
    float GetBusVolume(AudioBus bus) const;

private:
    AudioManager* m_mgr = nullptr;

    float m_busVolume[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // SFX BGM UI Voice

    static int BusIndex(AudioBus bus) { return static_cast<int>(bus); }
};

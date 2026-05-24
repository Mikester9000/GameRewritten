#pragma once
// tp_audio.hpp — Audio system wrapper using miniaudio (public domain / MIT-0).
// Provides init/shutdown, one-shot playback, and two looping channels (BGM + Ambient).
//
// Usage:
//   tp::Audio::Init();
//   tp::Audio::PlayOneShot("Content/Audio/sfx.wav");
//   tp::Audio::PlayBGM("Content/Audio/bgm_field_day.ogg");   // looping BGM channel
//   tp::Audio::PlayAmbient("Content/Audio/amb_forest_day_loop.wav"); // looping ambient
//   tp::Audio::StopBGM();
//   tp::Audio::StopAmbient();
//   tp::Audio::Shutdown();

#include <string>

namespace tp
{

class Audio
{
public:
    // Initialize the audio engine (opens the default output device).
    // Returns true on success; logs via OutputDebugString on failure.
    static bool Init();

    // Play a WAV, MP3, FLAC, or OGG file once (fire-and-forget).
    // Returns false if the engine isn't initialized or the file can't load.
    static bool PlayOneShot(const std::string& path);

    // Start a looping BGM track. Replaces any currently playing BGM.
    // Returns false if the engine isn't initialized or the file can't load.
    static bool PlayBGM(const std::string& path);

    // Stop the currently looping BGM (if any).
    static void StopBGM();

    // Returns true if a BGM track is currently playing.
    static bool IsBGMPlaying();

    // Start a looping ambient sound. Replaces any currently playing ambient.
    // Returns false if the engine isn't initialized or the file can't load.
    static bool PlayAmbient(const std::string& path);

    // Stop the currently looping ambient sound (if any).
    static void StopAmbient();

    // Release all audio resources.  Call before program exit.
    static void Shutdown();

    // Returns true if the engine was successfully initialized.
    static bool IsInitialized();

private:
    Audio() = delete;
};

} // namespace tp

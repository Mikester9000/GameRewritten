#pragma once
// tp_audio.hpp — Audio system wrapper using miniaudio (public domain / MIT-0).
// Provides simple init/shutdown and one-shot sound playback.
// Streaming music and mixer channels can be layered on top later.
//
// Usage:
//   tp::Audio::Init();                          // call once at startup
//   tp::Audio::PlayOneShot("Content/Audio/sfx.wav");
//   tp::Audio::Shutdown();                      // call before exit

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

    // Release all audio resources.  Call before program exit.
    static void Shutdown();

    // Returns true if the engine was successfully initialized.
    static bool IsInitialized();

private:
    Audio() = delete;
};

} // namespace tp

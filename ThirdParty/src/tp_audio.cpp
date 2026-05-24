// tp_audio.cpp — Audio system wrapper (miniaudio).

// Tell miniaudio to compile its implementation here.
// Note: miniaudio internally includes <windows.h> on Windows; do NOT define
// WIN32_LEAN_AND_MEAN before this include or some WinMM symbols may be missing.
#define MINIAUDIO_IMPLEMENTATION
#include "../../third_party/miniaudio/miniaudio.h"

#include "tp_audio.hpp"
// OutputDebugStringA is provided by <windows.h> pulled in by miniaudio above.

namespace tp
{

// Internal state (static storage so no heap allocation needed at init).
static ma_engine g_engine;
static bool      g_initialized = false;

// Looping BGM slot — one active streaming track at a time.
static ma_sound  g_bgmSound;
static bool      g_bgmActive   = false;

// Looping ambient slot — one active ambient loop at a time.
static ma_sound  g_ambSound;
static bool      g_ambActive   = false;

bool Audio::Init()
{
    if (g_initialized)
        return true;

    ma_result result = ma_engine_init(nullptr, &g_engine);
    if (result != MA_SUCCESS)
    {
        OutputDebugStringA("[ThirdParty][Audio] ma_engine_init failed.\n");
        return false;
    }
    g_initialized = true;
    OutputDebugStringA("[ThirdParty][Audio] Initialized.\n");
    return true;
}

bool Audio::PlayOneShot(const std::string& path)
{
    if (!g_initialized)
    {
        OutputDebugStringA("[ThirdParty][Audio] PlayOneShot called before Init().\n");
        return false;
    }
    ma_result result = ma_engine_play_sound(&g_engine, path.c_str(), nullptr);
    if (result != MA_SUCCESS)
    {
        std::string msg = "[ThirdParty][Audio] PlayOneShot failed: " + path + "\n";
        OutputDebugStringA(msg.c_str());
        return false;
    }
    return true;
}

bool Audio::PlayBGM(const std::string& path)
{
    if (!g_initialized)
    {
        OutputDebugStringA("[ThirdParty][Audio] PlayBGM called before Init().\n");
        return false;
    }

    // Stop existing BGM before starting a new one.
    StopBGM();

    // MA_SOUND_FLAG_STREAM avoids loading the whole file into memory.
    ma_result r = ma_sound_init_from_file(&g_engine, path.c_str(),
                                          MA_SOUND_FLAG_STREAM,
                                          nullptr, nullptr, &g_bgmSound);
    if (r != MA_SUCCESS)
    {
        std::string msg = "[ThirdParty][Audio] PlayBGM failed: " + path + "\n";
        OutputDebugStringA(msg.c_str());
        return false;
    }

    ma_sound_set_looping(&g_bgmSound, MA_TRUE);
    ma_sound_start(&g_bgmSound);
    g_bgmActive = true;
    return true;
}

void Audio::StopBGM()
{
    if (g_bgmActive)
    {
        ma_sound_stop(&g_bgmSound);
        ma_sound_uninit(&g_bgmSound);
        g_bgmActive = false;
    }
}

bool Audio::IsBGMPlaying()
{
    return g_bgmActive && ma_sound_is_playing(&g_bgmSound);
}

bool Audio::PlayAmbient(const std::string& path)
{
    if (!g_initialized)
    {
        OutputDebugStringA("[ThirdParty][Audio] PlayAmbient called before Init().\n");
        return false;
    }

    StopAmbient();

    ma_result r = ma_sound_init_from_file(&g_engine, path.c_str(),
                                          MA_SOUND_FLAG_STREAM,
                                          nullptr, nullptr, &g_ambSound);
    if (r != MA_SUCCESS)
    {
        std::string msg = "[ThirdParty][Audio] PlayAmbient failed: " + path + "\n";
        OutputDebugStringA(msg.c_str());
        return false;
    }

    ma_sound_set_looping(&g_ambSound, MA_TRUE);
    ma_sound_start(&g_ambSound);
    g_ambActive = true;
    return true;
}

void Audio::StopAmbient()
{
    if (g_ambActive)
    {
        ma_sound_stop(&g_ambSound);
        ma_sound_uninit(&g_ambSound);
        g_ambActive = false;
    }
}

void Audio::Shutdown()
{
    if (g_initialized)
    {
        StopBGM();
        StopAmbient();
        ma_engine_uninit(&g_engine);
        g_initialized = false;
        OutputDebugStringA("[ThirdParty][Audio] Shutdown.\n");
    }
}

bool Audio::IsInitialized()
{
    return g_initialized;
}

} // namespace tp

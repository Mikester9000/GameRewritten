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

void Audio::Shutdown()
{
    if (g_initialized)
    {
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

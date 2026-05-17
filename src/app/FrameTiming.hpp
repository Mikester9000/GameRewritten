// ============================================================
// FILE: src/app/FrameTiming.hpp
// SYSTEM: FrameTiming.hpp
// SYSTEM: app startup/shutdown wiring and frame orchestration

#pragma once
// FrameTiming.hpp
// Small helper for frame delta timing and smoothed FPS display values.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <algorithm>

namespace FrameTiming
{
struct State
{
    LARGE_INTEGER perfFreq{};
    LARGE_INTEGER prevCounter{};
    float fpsAccum  = 0.0f;
    int   fpsFrames = 0;
    float displayFPS = 0.0f;
};

inline void Initialize(State& state)
{
    QueryPerformanceFrequency(&state.perfFreq);
    QueryPerformanceCounter(&state.prevCounter);
}

inline float BeginFrame(State& state)
{
    LARGE_INTEGER currCounter{};
    QueryPerformanceCounter(&currCounter);

    float deltaTime = static_cast<float>(currCounter.QuadPart - state.prevCounter.QuadPart) /
                      static_cast<float>(state.perfFreq.QuadPart);
    state.prevCounter = currCounter;

    // Clamp to avoid huge spikes when app loses focus.
    deltaTime = std::clamp(deltaTime, 0.0f, 0.05f);

    // FPS calculation (smooth over ~0.5 s).
    state.fpsAccum += deltaTime;
    state.fpsFrames++;
    if (state.fpsAccum >= 0.5f)
    {
        state.displayFPS = static_cast<float>(state.fpsFrames) / state.fpsAccum;
        state.fpsAccum = 0.0f;
        state.fpsFrames = 0;
    }

    return deltaTime;
}
}

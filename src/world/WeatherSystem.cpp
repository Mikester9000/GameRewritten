// ============================================================
// FILE: src/world/WeatherSystem.cpp
// SYSTEM: World
// ROLE: world cells, biome data, and streaming structure
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: WeatherSystem module behavior and local implementation details.
// ============================================================

// WeatherSystem.cpp
// Probabilistic weather state machine: drives ambient, wind, and rain
// modifiers that Main.cpp applies to the renderer and particle system.

#include "WeatherSystem.hpp"

#include <cmath>
#include <algorithm>

// ---------------------------------------------------------------------------
// Per-state tuning tables (indexed by WeatherState cast to int).
// ---------------------------------------------------------------------------
namespace
{
// Ambient multipliers for each state (applied to base ambient strength).
constexpr float kAmbientMod[4] = { 1.00f, 0.85f, 0.70f, 0.55f };

// Wind strength [0,1] per state.
constexpr float kWind[4] = { 0.05f, 0.20f, 0.55f, 1.00f };

// Rain intensity [0,1] per state.
constexpr float kRain[4] = { 0.00f, 0.00f, 0.50f, 1.00f };

// Sky tints (R,G,B) per state — blended toward these in Main.
constexpr float kSkyR[4] = { 0.10f, 0.14f, 0.08f, 0.04f };
constexpr float kSkyG[4] = { 0.10f, 0.13f, 0.09f, 0.05f };
constexpr float kSkyB[4] = { 0.15f, 0.16f, 0.12f, 0.07f };

// Simple LCG used as a cheap deterministic pseudo-random seed per call.
unsigned int g_seed = 1;
float RandFloat()
{
    g_seed = g_seed * 1664525u + 1013904223u;
    return static_cast<float>(g_seed & 0xFFFFu) / 65535.0f;
}
}

// ---------------------------------------------------------------------------
// WeatherSystem::WeatherSystem
// ---------------------------------------------------------------------------
WeatherSystem::WeatherSystem()
{
    m_stateTimer = NextStateDuration();
}

// ---------------------------------------------------------------------------
// WeatherSystem::NextStateDuration
// ---------------------------------------------------------------------------
float WeatherSystem::NextStateDuration() const
{
    return kMinStateDuration + RandFloat() * (kMaxStateDuration - kMinStateDuration);
}

// ---------------------------------------------------------------------------
// WeatherSystem::NextState — one-step circular progression
// ---------------------------------------------------------------------------
WeatherState WeatherSystem::NextState(WeatherState current)
{
    // Typical progression: Clear → Cloudy → Rain → Storm → Clear.
    // Small chance to skip Rain or stay the same (via RandFloat already called
    // in the duration calc, so this keeps a separate coin flip simple).
    return static_cast<WeatherState>((static_cast<int>(current) + 1) % 4);
}

// ---------------------------------------------------------------------------
// WeatherSystem::Update
// ---------------------------------------------------------------------------
void WeatherSystem::Update(float dt)
{
    if (dt <= 0.0f)
        return;

    // Blend alpha ramps up quickly (3 seconds) to smoothly crossfade state values.
    constexpr float kBlendSpeed = 1.0f / 3.0f;
    if (m_blendAlpha < 1.0f)
    {
        m_blendAlpha = std::min(1.0f, m_blendAlpha + dt * kBlendSpeed);
    }

    m_stateTimer -= dt;
    if (m_stateTimer <= 0.0f)
    {
        m_prevState  = m_state;
        m_state      = NextState(m_state);
        m_stateTimer = NextStateDuration();
        m_blendAlpha = 0.0f;
    }
}

// ---------------------------------------------------------------------------
// Accessors — linearly blend from previous to current state.
// ---------------------------------------------------------------------------
float WeatherSystem::GetAmbientModifier() const
{
    const float from = kAmbientMod[static_cast<int>(m_prevState)];
    const float to   = kAmbientMod[static_cast<int>(m_state)];
    return from + (to - from) * m_blendAlpha;
}

float WeatherSystem::GetWindStrength() const
{
    const float from = kWind[static_cast<int>(m_prevState)];
    const float to   = kWind[static_cast<int>(m_state)];
    return from + (to - from) * m_blendAlpha;
}

float WeatherSystem::GetRainIntensity() const
{
    const float from = kRain[static_cast<int>(m_prevState)];
    const float to   = kRain[static_cast<int>(m_state)];
    return from + (to - from) * m_blendAlpha;
}

void WeatherSystem::GetSkyColor(float& r, float& g, float& b) const
{
    const int pi = static_cast<int>(m_prevState);
    const int ci = static_cast<int>(m_state);
    r = kSkyR[pi] + (kSkyR[ci] - kSkyR[pi]) * m_blendAlpha;
    g = kSkyG[pi] + (kSkyG[ci] - kSkyG[pi]) * m_blendAlpha;
    b = kSkyB[pi] + (kSkyB[ci] - kSkyB[pi]) * m_blendAlpha;
}

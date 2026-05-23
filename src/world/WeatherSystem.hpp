// ============================================================
// FILE: src/world/WeatherSystem.hpp
// SYSTEM: World
// ROLE: world cells, biome data, and streaming structure
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: WeatherSystem module behavior and local implementation details.
// ============================================================

#pragma once
// WeatherSystem.hpp
// Lightweight weather state machine: Clear → Cloudy → Rain → Storm → Clear.
// Drives ambient modifiers and wind strength that other systems can query.
//
// Usage:
//   WeatherSystem weather;
//   // each frame:
//   weather.Update(dt);
//   renderer.SetAmbientStrength(ambientBase * weather.GetAmbientModifier());
//   primRenderer.SetWindStrength(weather.GetWindStrength());

enum class WeatherState
{
    Clear  = 0,
    Cloudy = 1,
    Rain   = 2,
    Storm  = 3,
};

class WeatherSystem
{
public:
    // Duration bounds for each weather state (real seconds).
    static constexpr float kMinStateDuration = 30.0f;
    static constexpr float kMaxStateDuration = 120.0f;

    WeatherSystem();

    // Advance weather timers and blend state.
    void Update(float dt);

    WeatherState GetState() const { return m_state; }

    // Multiplier applied to the base ambient strength (1.0 = unchanged, 0.55 = stormy dark).
    float GetAmbientModifier() const;

    // Rainfall intensity [0, 1].  0 = no rain, 1 = heavy storm.
    float GetRainIntensity() const;

    // Wind strength [0, 1] for tree sway and particle drift.
    float GetWindStrength() const;

    // Sky tint color — blended by Main into ClearScreen / sky color.
    void GetSkyColor(float& r, float& g, float& b) const;

private:
    WeatherState m_state      = WeatherState::Clear;
    float        m_stateTimer = 0.0f;   // seconds remaining in this state
    float        m_blendAlpha = 1.0f;   // 0=prev, 1=current (linear blend)
    WeatherState m_prevState  = WeatherState::Clear;
    unsigned int m_seed       = 1u;

    float NextStateDuration();
    static WeatherState NextState(WeatherState current);
};

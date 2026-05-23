// ============================================================
// FILE: src/world/DayNightCycle.hpp
// SYSTEM: World
// ROLE: world cells, biome data, and streaming structure
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: DayNightCycle module behavior and local implementation details.
// ============================================================

#pragma once
// DayNightCycle.hpp
// Tracks an accelerated time-of-day (0-24 hours) and derives sun direction,
// sun color, and ambient strength so the renderer can be updated each frame.
//
// Usage:
//   DayNightCycle dayNight;
//   dayNight.Init(6.0f); // start at 6 AM
//   // each frame:
//   dayNight.Advance(dt);
//   float sx, sy, sz;
//   dayNight.GetSunDirection(sx, sy, sz);
//   renderer.SetSunDirection(sx, sy, sz);
//   renderer.SetAmbientStrength(dayNight.GetAmbientStrength());

class DayNightCycle
{
public:
    // How many in-game seconds pass per real second.
    // Default: 1 real minute = 1 game hour  →  full day = 24 real minutes.
    static constexpr float kTimeScale = 60.0f;

    // Minimum and maximum ambient values (GT610 safe — no HDR pipeline).
    static constexpr float kAmbientDay    = 0.55f;
    static constexpr float kAmbientSunset = 0.30f;
    static constexpr float kAmbientNight  = 0.10f;

    // Initialise with a starting hour (0-24).  Default = 6:00 AM.
    void Init(float startHour = 6.0f);

    // Advance the time-of-day clock by dt real seconds.
    void Advance(float dt);

    // Current time of day in hours [0, 24).
    float GetTimeOfDay() const { return m_timeOfDay; }

    // Returns true when the hour is between 20:00 and 6:00 (night).
    bool IsNight() const;

    // Sun direction in world space (normalised).
    // At noon the sun is directly overhead; at midnight it is below the horizon.
    void GetSunDirection(float& x, float& y, float& z) const;

    // Sun/sky color that shifts warm-white at noon → orange-red at sunset → deep blue at night.
    void GetSunColor(float& r, float& g, float& b) const;

    // Ambient fill light strength derived from time of day.
    float GetAmbientStrength() const;

private:
    float m_timeOfDay = 6.0f; // hours
};

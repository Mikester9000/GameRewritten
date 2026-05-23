// ============================================================
// FILE: src/world/DayNightCycle.cpp
// SYSTEM: World
// ROLE: world cells, biome data, and streaming structure
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: DayNightCycle module behavior and local implementation details.
// ============================================================

// DayNightCycle.cpp
// Advances an accelerated 24-hour clock and derives sun direction, color,
// and ambient strength so Main.cpp can push these to the renderer each frame.

#include "DayNightCycle.hpp"

#include <cmath>
#include <algorithm>

// ---------------------------------------------------------------------------
// Init
// ---------------------------------------------------------------------------
void DayNightCycle::Init(float startHour)
{
    // Clamp to [0, 24) so downstream math is well-defined.
    m_timeOfDay = startHour - (24.0f * std::floor(startHour / 24.0f));
}

// ---------------------------------------------------------------------------
// Advance
// ---------------------------------------------------------------------------
void DayNightCycle::Advance(float dt)
{
    if (dt <= 0.0f)
        return;

    // Convert real seconds to in-game hours.
    m_timeOfDay += dt * (kTimeScale / 3600.0f);

    // Wrap at midnight.
    if (m_timeOfDay >= 24.0f)
        m_timeOfDay -= 24.0f;
}

// ---------------------------------------------------------------------------
// IsNight
// ---------------------------------------------------------------------------
bool DayNightCycle::IsNight() const
{
    return m_timeOfDay >= 20.0f || m_timeOfDay < 6.0f;
}

// ---------------------------------------------------------------------------
// GetSunDirection
// ---------------------------------------------------------------------------
void DayNightCycle::GetSunDirection(float& x, float& y, float& z) const
{
    // Map 0-24 hours to a full circle (6 AM = sun rising from east).
    // At noon (12h) the sun is almost directly overhead at (0, -1, 0) in
    // the convention where negative Y points "down toward the scene".
    constexpr float kPi = 3.14159265f;

    // Solar angle: 0 at noon, ±π at midnight.
    const float hourAngle = (m_timeOfDay - 12.0f) * (kPi / 12.0f);
    const float elevation = -cosf(hourAngle); // -1 at noon, +1 at midnight
    const float horizontal = sinf(hourAngle); // east-west sweep

    x = horizontal * 0.6f;
    y = elevation;
    z = 0.4f; // slight south tilt for visual variety

    // Normalise.
    const float len = sqrtf(x * x + y * y + z * z);
    if (len > 0.001f) { x /= len; y /= len; z /= len; }
}

// ---------------------------------------------------------------------------
// GetSunColor
// ---------------------------------------------------------------------------
void DayNightCycle::GetSunColor(float& r, float& g, float& b) const
{
    // Colour key points (hour, R, G, B):
    //   6h  sunrise → warm orange  (1.0, 0.55, 0.20)
    //   12h noon    → bright white (1.0, 0.95, 0.85)
    //   18h sunset  → deep orange  (1.0, 0.40, 0.10)
    //   21h twilight→ dark violet  (0.30, 0.20, 0.45)
    //   24h/0h night→ deep blue    (0.08, 0.10, 0.22)

    const float t = m_timeOfDay;

    // Lerp helper (avoids a dependency on std::lerp across older MSVC targets).
    auto lerp = [](float a, float b, float f) { return a + (b - a) * std::clamp(f, 0.0f, 1.0f); };

    auto setColor = [&](float cr, float cg, float cb) { r = cr; g = cg; b = cb; };

    if (t < 6.0f)
    {
        const float f = t / 6.0f;
        r = lerp(0.08f, 1.00f, f);
        g = lerp(0.10f, 0.55f, f);
        b = lerp(0.22f, 0.20f, f);
    }
    else if (t < 12.0f)
    {
        const float f = (t - 6.0f) / 6.0f;
        r = lerp(1.00f, 1.00f, f);
        g = lerp(0.55f, 0.95f, f);
        b = lerp(0.20f, 0.85f, f);
    }
    else if (t < 18.0f)
    {
        const float f = (t - 12.0f) / 6.0f;
        r = lerp(1.00f, 1.00f, f);
        g = lerp(0.95f, 0.40f, f);
        b = lerp(0.85f, 0.10f, f);
    }
    else if (t < 21.0f)
    {
        const float f = (t - 18.0f) / 3.0f;
        r = lerp(1.00f, 0.30f, f);
        g = lerp(0.40f, 0.20f, f);
        b = lerp(0.10f, 0.45f, f);
    }
    else
    {
        const float f = (t - 21.0f) / 3.0f;
        r = lerp(0.30f, 0.08f, f);
        g = lerp(0.20f, 0.10f, f);
        b = lerp(0.45f, 0.22f, f);
    }
    (void)setColor; // suppress unused-lambda warning
}

// ---------------------------------------------------------------------------
// GetAmbientStrength
// ---------------------------------------------------------------------------
float DayNightCycle::GetAmbientStrength() const
{
    // Use same time buckets to produce a smooth ambient curve.
    const float t = m_timeOfDay;

    auto lerp = [](float a, float b, float f) { return a + (b - a) * std::clamp(f, 0.0f, 1.0f); };

    if (t < 6.0f)
        return lerp(kAmbientNight, kAmbientSunset, t / 6.0f);
    if (t < 12.0f)
        return lerp(kAmbientSunset, kAmbientDay, (t - 6.0f) / 6.0f);
    if (t < 18.0f)
        return kAmbientDay;
    if (t < 21.0f)
        return lerp(kAmbientDay, kAmbientSunset, (t - 18.0f) / 3.0f);
    return lerp(kAmbientSunset, kAmbientNight, (t - 21.0f) / 3.0f);
}

// ============================================================
// FILE: src/world/AtmosphericFog.cpp
// SYSTEM: World / Atmosphere
// ROLE: Implements AtmosphericFog — biome/weather/time-of-day fog parameters.
//
// FOR QWEN: Implement these functions in order:
//   1. GetBiomeFogBase()       — per-biome color + density table
//   2. GetTimeOfDayModifier()  — time-of-day density scale
//   3. GetTimeOfDayColorTint() — time-of-day fog color shift
//   4. Initialize()            — set initial state from biome
//   5. Update()                — compute target + smooth blend toward it
// ============================================================

#include "AtmosphericFog.hpp"
#include <algorithm>
#include <cmath>
#include <string>

// ============================================================
// CONSTRUCTOR
// ============================================================
AtmosphericFog::AtmosphericFog()
{
    // Default: disabled until initialized
    m_enabled = false;
}


// ============================================================
// GetBiomeFogBase (static)
// Returns the base FogSettings for a biome (before modifiers).
//
// TODO (Qwen): Tune these values in playtesting.
//   The density values below are starting points — adjust until
//   the player can see ~400u in grassland at noon clear weather.
// ============================================================
FogSettings AtmosphericFog::GetBiomeFogBase(const std::string& biome)
{
    FogSettings s{};
    s.fogNearPlane = 0.1f;
    s.fogFarPlane  = 1000.0f;
    s.fogHeightFalloff = 0.5f;
    s.fogMaxHeight = 50.0f;

    if (biome == "grassland")
    {
        s.fogColor[0] = 0.70f; s.fogColor[1] = 0.75f; s.fogColor[2] = 0.80f;
        s.fogDensity  = 0.0025f;
    }
    else if (biome == "desert")
    {
        // Warm sandy/dusty haze
        s.fogColor[0] = 0.85f; s.fogColor[1] = 0.78f; s.fogColor[2] = 0.60f;
        s.fogDensity  = 0.004f;
    }
    else if (biome == "rocky")
    {
        // Cool grey mountain mist
        s.fogColor[0] = 0.60f; s.fogColor[1] = 0.62f; s.fogColor[2] = 0.65f;
        s.fogDensity  = 0.0030f;
    }
    else if (biome == "snow")
    {
        // White/pale blue blizzard mist
        s.fogColor[0] = 0.85f; s.fogColor[1] = 0.88f; s.fogColor[2] = 0.95f;
        s.fogDensity  = 0.005f;
    }
    else
    {
        // Default: same as grassland
        s.fogColor[0] = 0.70f; s.fogColor[1] = 0.75f; s.fogColor[2] = 0.80f;
        s.fogDensity  = 0.0025f;
    }

    return s;
}


// ============================================================
// GetTimeOfDayModifier (static)
// Returns a density multiplier for a normalized time-of-day.
// 0.0=midnight, 0.25=dawn, 0.5=noon, 0.75=dusk, 1.0=midnight.
//
// TODO (Qwen): Improve using smoothstep between bands for soft edges.
//   Current: simple linear bands. Smoothstep adds a 4-line improvement.
// ============================================================
float AtmosphericFog::GetTimeOfDayModifier(float t)
{
    // Dawn band: 0.2 → 0.3 normalized time → peak density × 1.5
    if (t >= 0.20f && t <= 0.30f)
    {
        float p = (t - 0.20f) / 0.10f; // [0,1] within band
        // Peak at center of band (p=0.5)
        float peak = (p < 0.5f) ? (p * 2.0f) : ((1.0f - p) * 2.0f);
        return 1.0f + peak * 0.5f; // max 1.5×
    }
    // Noon: 0.45 → 0.55 → reduced density (clear weather / heat)
    if (t >= 0.45f && t <= 0.55f)
        return 0.7f;
    // Dusk: 0.70 → 0.80 → dense haze
    if (t >= 0.70f && t <= 0.80f)
    {
        float p = (t - 0.70f) / 0.10f;
        float peak = (p < 0.5f) ? (p * 2.0f) : ((1.0f - p) * 2.0f);
        return 1.0f + peak * 0.3f; // max 1.3×
    }
    // Night: 0.90 → 1.0, 0.0 → 0.10 → darkest, densest
    if (t >= 0.90f || t <= 0.10f)
        return 1.8f;
    // Transitions between bands: linear interpolation (stub: return 1.0)
    // TODO (Qwen): add smooth ramp between all bands.
    return 1.0f;
}


// ============================================================
// GetTimeOfDayColorTint (static)
// Writes additive fog color deltas for the current time of day.
//
// TODO (Qwen): Add smooth interpolation between tint bands.
// ============================================================
void AtmosphericFog::GetTimeOfDayColorTint(float t, float& dr, float& dg, float& db)
{
    dr = dg = db = 0.0f;

    if (t >= 0.20f && t <= 0.35f)
    {
        // Dawn: slightly warm-cool blue
        dr = 0.04f; dg = 0.02f; db = -0.03f;
    }
    else if (t >= 0.45f && t <= 0.55f)
    {
        // Noon: warm haze (slight yellow warmth)
        dr = 0.05f; dg = 0.03f; db = -0.02f;
    }
    else if (t >= 0.70f && t <= 0.85f)
    {
        // Dusk: orange-pink
        dr = 0.12f; dg = 0.02f; db = -0.10f;
    }
    else if (t >= 0.90f || t <= 0.10f)
    {
        // Night: dark purple-grey
        dr = -0.20f; dg = -0.18f; db = -0.10f;
    }
}


// ============================================================
// Initialize
// ============================================================
void AtmosphericFog::Initialize(const std::string& startBiome, float nearPlane, float farPlane)
{
    m_currentSettings = GetBiomeFogBase(startBiome);
    m_currentSettings.fogNearPlane = nearPlane;
    m_currentSettings.fogFarPlane  = farPlane;
    m_targetSettings  = m_currentSettings;
    m_initialized = true;
}


// ============================================================
// SetFarPlane
// ============================================================
void AtmosphericFog::SetFarPlane(float nearPlane, float farPlane)
{
    m_currentSettings.fogNearPlane = nearPlane;
    m_currentSettings.fogFarPlane  = farPlane;
    m_targetSettings.fogNearPlane  = nearPlane;
    m_targetSettings.fogFarPlane   = farPlane;
}


// ============================================================
// Update
// Computes target fog state and smoothly blends toward it.
//
// TODO (Qwen): The STUB below applies target directly (no smoothing).
//   Replace with lerp for smooth biome/weather/time transitions:
//     float blendSpeed = 0.5f * dt;
//     m_currentSettings.fogColor[0] += (m_targetSettings.fogColor[0] - m_currentSettings.fogColor[0]) * blendSpeed;
//     (same for [1], [2], fogDensity, fogWeatherIntensity)
// ============================================================
void AtmosphericFog::Update(const std::string& biome,
                             float weatherIntensity,
                             float timeOfDay,
                             float dt)
{
    if (!m_enabled || !m_initialized) return;

    // Step 1: Get biome base
    FogSettings base = GetBiomeFogBase(biome);

    // Step 2: Apply time-of-day density modifier
    float todMod = GetTimeOfDayModifier(timeOfDay);
    base.fogDensity *= todMod;

    // Step 3: Apply time-of-day color tint
    float dr, dg, db;
    GetTimeOfDayColorTint(timeOfDay, dr, dg, db);
    base.fogColor[0] = std::clamp(base.fogColor[0] + dr, 0.0f, 1.0f);
    base.fogColor[1] = std::clamp(base.fogColor[1] + dg, 0.0f, 1.0f);
    base.fogColor[2] = std::clamp(base.fogColor[2] + db, 0.0f, 1.0f);

    // Step 4: Set weather intensity
    base.fogWeatherIntensity = std::clamp(weatherIntensity, 0.0f, 1.0f);

    // Keep near/far planes stable
    base.fogNearPlane = m_currentSettings.fogNearPlane;
    base.fogFarPlane  = m_currentSettings.fogFarPlane;

    // Store as target
    m_targetSettings = base;

    // TODO (Qwen): Replace direct assignment below with lerp-based smoothing:
    m_currentSettings = m_targetSettings; // STUB: no smooth blending yet

    (void)dt; // suppress warning until lerp is added
}

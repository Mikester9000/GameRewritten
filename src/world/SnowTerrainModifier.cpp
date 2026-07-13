// ============================================================
// FILE: src/world/SnowTerrainModifier.cpp
// SYSTEM: World / Weather
// ROLE: Implements SnowTerrainModifier — snow/ice terrain effects.
//
// FOR QWEN: Implement Update(), GetIceFriction(), GetSnowFriction(),
//   GetCombinedFriction(), GetSurfaceShineBoost() using the formulas
//   documented in SnowTerrainModifier.hpp.
// ============================================================

#include "SnowTerrainModifier.hpp"
#include <algorithm>
#include <cmath>

// ============================================================
// CONSTRUCTOR
// ============================================================
SnowTerrainModifier::SnowTerrainModifier()
{
    // Zero-initialize (all defaults from header)
}


// ============================================================
// Initialize
// ============================================================
void SnowTerrainModifier::Initialize(const std::string& biome, float snowLineY, bool isIceBiome)
{
    m_biome       = biome;
    m_snowLineY   = snowLineY;
    m_isIceBiome  = isIceBiome;

    // Snow biome starts with significant pre-existing coverage
    // Rocky high-altitude: some coverage, Rocky low: none
    if (biome == "snow")
        m_snowAccumulation = 1.0f;
    else
        m_snowAccumulation = 0.0f;

    // Ice biome: starts fully glazed
    m_iceLevel = isIceBiome ? 1.0f : 0.0f;
}


// ============================================================
// Update
// Advances snow/ice accumulation each frame.
//
// TODO (Qwen): Implement the full snow model described in the header.
// Key formulas:
//   Accumulate:  m_snowAccumulation += snowIntensity * kSnowBuildRate * dt
//   Melt:        m_snowAccumulation -= max(0, dayTemperature) * kMeltRate * dt
//   Ice build:   if dayTemperature < kIceThreshold && m_snowAccumulation > 0.3:
//                    m_iceLevel += abs(dayTemperature) * kIceBuildRate * dt
//   Ice melt:    else if dayTemperature > 0.3:
//                    m_iceLevel -= dayTemperature * kMeltRate * 0.5f * dt
//   Always clamp both values to [0,1].
// ============================================================
void SnowTerrainModifier::Update(float snowIntensity, float dayTemperature, float dt)
{
    // Do not affect permanently icy biomes with dynamic weather
    if (m_isIceBiome) return;

    // Snow accumulation
    // TODO (Qwen): add elevation check — only accumulate above m_snowLineY
    m_snowAccumulation += snowIntensity * kSnowBuildRate * dt;

    // Snow melt (requires warm day temperature)
    if (dayTemperature > 0.0f)
        m_snowAccumulation -= dayTemperature * kMeltRate * dt;

    m_snowAccumulation = std::clamp(m_snowAccumulation, 0.0f, 1.0f);

    // Ice formation: requires cold temperature AND existing snow
    if (dayTemperature < kIceThreshold && m_snowAccumulation > 0.3f)
    {
        m_iceLevel += std::abs(dayTemperature) * kIceBuildRate * dt;
    }
    else if (dayTemperature > 0.3f)
    {
        // Ice melts slower than snow
        m_iceLevel -= dayTemperature * kMeltRate * 0.5f * dt;
    }

    m_iceLevel = std::clamp(m_iceLevel, 0.0f, 1.0f);
}


// ============================================================
// GetIceFriction
// Nearly frictionless at full ice.
//
// TODO (Qwen): verify lerp formula matches header documentation.
// ============================================================
float SnowTerrainModifier::GetIceFriction() const
{
    // lerp from 1.0 (no ice) to 0.15 (full ice)
    return 0.15f + (1.0f - 0.15f) * (1.0f - m_iceLevel);
}


// ============================================================
// GetSnowFriction
// Deep snow slows movement (wading effect).
//
// TODO (Qwen): verify formula.
// ============================================================
float SnowTerrainModifier::GetSnowFriction() const
{
    // lerp from 1.0 (no snow) to 0.65 (full snow cover)
    return 0.65f + (1.0f - 0.65f) * (1.0f - m_snowAccumulation);
}


// ============================================================
// GetCombinedFriction
// Returns the minimum (worst) of snow and ice friction.
// ============================================================
float SnowTerrainModifier::GetCombinedFriction() const
{
    return std::min(GetSnowFriction(), GetIceFriction());
}


// ============================================================
// GetSurfaceShineBoost
// Ice is mirror-like. Scale specular 1.0 → 8.0 with ice level.
//
// TODO (Qwen): implement lerp.
// ============================================================
float SnowTerrainModifier::GetSurfaceShineBoost() const
{
    // lerp from 1.0 (no ice) to 8.0 (fully glazed)
    return 1.0f + m_iceLevel * 7.0f;
}


// ============================================================
// SetBiome
// ============================================================
void SnowTerrainModifier::SetBiome(const std::string& biome)
{
    m_biome = biome;
    // Certain biomes start with pre-existing coverage
    if (biome == "snow" && m_snowAccumulation < 0.8f)
        m_snowAccumulation = 1.0f; // Snow biome is always max-covered
}


// ============================================================
// Reset
// Called on cell unload to return terrain to bare state.
// Permanently icy biomes are not reset.
// ============================================================
void SnowTerrainModifier::Reset()
{
    if (m_isIceBiome) return;
    m_snowAccumulation = (m_biome == "snow") ? 1.0f : 0.0f;
    m_iceLevel = 0.0f;
}

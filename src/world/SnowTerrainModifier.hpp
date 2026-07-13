// ============================================================
// FILE: src/world/SnowTerrainModifier.hpp
// SYSTEM: World / Weather
// ROLE: Applies runtime terrain appearance modifications for snow and ice conditions.
//   Drives visual and gameplay effects caused by snow/ice:
//     1. Snow accumulation: whitens terrain surface over time (shader factor)
//     2. Ice terrain: extremely slippery (lower friction than rain)
//     3. Snow depth visual: blends in snow-cap texture on elevated terrain
//     4. Footprint persistence: player movement leaves visible tracks (future)
//
// DIFFERENCE FROM RainTerrainModifier:
//   - Snow accumulates (doesn't drain away immediately) — slow build, very slow melt
//   - Ice forms when temp drops below zero — tracked separately from snow cover
//   - Snow is visually white-out on terrain; rain just darkens/shines
//   - Snow affects higher terrain first (elevation-based accumulation)
//
// INTEGRATION POINTS:
//   - WeatherSystem provides snow intensity (currently via Rain state at cold elevation)
//   - D3D11Renderer::SetSnowFactor() passes whiteness to ground_ps.hlsl
//   - CharacterController reads GetIceFriction() for near-zero traction
//   - DayNightCycle drives temperature (night = colder = ice builds faster)
//
// SNOW ACCUMULATION MODEL:
//   m_snowAccumulation: 0.0 (bare) → 1.0 (fully snow-covered)
//   Accumulates slowly during storm at altitude.
//   Melts during Clear or when "day temperature" > 0.
//   Accumulation rate: ~0.02 per second at full storm intensity
//   Melt rate: ~0.005 per second during Clear (sunny day)
//
// ELEVATION-BASED SNOW:
//   High terrain (Y > snowLineY) accumulates snow faster.
//   Low terrain (Y < snowLineY - 5) does not accumulate at all.
//   Use TerrainManager::SampleTerrainHeight() for spot checks.
//   For simplicity: biome="snow" is always fully snow-covered from start.
//
// FOR QWEN: Implement Update(), GetSnowFactor(), GetIceFriction() in .cpp.
// ============================================================

#pragma once
#include <string>

class RainTerrainModifier; // Forward — snow does not depend on rain directly

// ============================================================
// SnowTerrainModifier
// ============================================================
class SnowTerrainModifier
{
public:
    SnowTerrainModifier();
    ~SnowTerrainModifier() = default;

    // --------------------------------------------------------
    // Initialize
    //   biome: "snow", "rocky", "grassland" etc.
    //   snowLineY: world Y above which snow accumulates. Typical: 20.0–40.0.
    //   isIceBiome: if true, terrain is always icy (ice caves, glaciers).
    // --------------------------------------------------------
    void Initialize(const std::string& biome, float snowLineY, bool isIceBiome = false);

    // --------------------------------------------------------
    // Update
    // Advances snow/ice accumulation simulation.
    //   snowIntensity: [0,1] — 0=no snow, 1=blizzard. From WeatherSystem.
    //   dayTemperature: [-1,1] — negative=cold (builds ice), positive=warm (melts).
    //     Drive from DayNightCycle: midnight=-0.8, noon=1.0 in temperate biomes.
    //   dt: frame delta time in seconds.
    //
    // TODO (Qwen): Implement:
    //   accumulate: m_snowAccumulation += snowIntensity * kSnowBuildRate * dt
    //   melt: if dayTemperature > 0: m_snowAccumulation -= dayTemperature * kMeltRate * dt
    //   clamp to [0,1]
    //   ice: if dayTemperature < kIceThreshold and m_snowAccumulation > 0.3:
    //           m_iceLevel += abs(dayTemperature) * kIceBuildRate * dt
    //        else if dayTemperature > 0.3:
    //           m_iceLevel -= dayTemperature * kMeltRate * 0.5 * dt
    //   clamp ice to [0,1]
    // --------------------------------------------------------
    void Update(float snowIntensity, float dayTemperature, float dt);

    // --------------------------------------------------------
    // GetSnowFactor
    // Returns terrain whiteness factor for ground_ps.hlsl [0,1].
    // 0 = no snow visible, 1 = fully white terrain.
    // Pass as 'snowAmount' to ground shader cbuffer.
    //
    // In ground_ps: finalColor = lerp(terrainColor, snowColor, snowAmount)
    //   where snowColor = float3(0.92, 0.95, 1.0) (slightly blue-white)
    // --------------------------------------------------------
    float GetSnowFactor() const { return m_snowAccumulation; }

    // --------------------------------------------------------
    // GetIceLevel
    // Returns ice formation level [0,1].
    // 0 = no ice, 1 = fully glazed (glass-like).
    // --------------------------------------------------------
    float GetIceLevel() const { return m_iceLevel; }

    // --------------------------------------------------------
    // GetIceFriction
    // Returns movement friction for ice terrain [0.15, 1.0].
    // 0.15 = nearly frictionless (full ice), 1.0 = no ice effect.
    //
    // Formula: lerp(0.15, 1.0, 1.0 - m_iceLevel)
    //   At iceLevel=0: friction=1.0 (normal)
    //   At iceLevel=1: friction=0.15 (nearly frictionless)
    //
    // TODO (Qwen): implement lerp formula.
    // --------------------------------------------------------
    float GetIceFriction() const;

    // --------------------------------------------------------
    // GetSnowFriction
    // Returns movement friction for snow terrain [0.65, 1.0].
    // Snow is less slippery than ice but slows movement (wading effect).
    // Formula: lerp(0.65, 1.0, 1.0 - m_snowAccumulation)
    // --------------------------------------------------------
    float GetSnowFriction() const;

    // --------------------------------------------------------
    // GetCombinedFriction
    // Returns the worse of snow and ice friction.
    // The character controller should use this single value.
    // --------------------------------------------------------
    float GetCombinedFriction() const;

    // --------------------------------------------------------
    // GetSurfaceShineBoost
    // Ice surface is extremely shiny. Returns specular multiplier [1.0, 8.0].
    // Use in ground_ps to scale specular when ice > 0.
    // --------------------------------------------------------
    float GetSurfaceShineBoost() const;

    // --------------------------------------------------------
    // IsFullyCovered
    // Returns true when snow is so deep the biome changes visually (all-white).
    // Used to trigger biome transition effects from adjacent biome colors.
    // --------------------------------------------------------
    bool IsFullyCovered() const { return m_snowAccumulation >= 0.9f; }

    // --------------------------------------------------------
    // SetBiome
    // Updates biome-dependent parameters (e.g. mountain biome starts at 0.8 coverage).
    // --------------------------------------------------------
    void SetBiome(const std::string& biome);

    // --------------------------------------------------------
    // Reset
    // Resets to bare terrain (called on cell unload / player teleport).
    // --------------------------------------------------------
    void Reset();

private:
    // Simulation state
    float       m_snowAccumulation = 0.0f; // [0,1] — current snow cover
    float       m_iceLevel         = 0.0f; // [0,1] — current ice glazing
    float       m_snowLineY        = 20.0f;// World Y threshold for snow
    bool        m_isIceBiome       = false;// Always icy regardless of temperature
    std::string m_biome            = "grassland";

    // Rate constants (seconds-based)
    static constexpr float kSnowBuildRate  = 0.015f; // Per second at full intensity
    static constexpr float kMeltRate       = 0.004f; // Per second per degree of warmth
    static constexpr float kIceBuildRate   = 0.008f; // Per second per degree of cold
    static constexpr float kIceThreshold   = -0.2f;  // Day temp below this triggers ice
};

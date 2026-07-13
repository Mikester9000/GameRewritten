// ============================================================
// FILE: src/world/AtmosphericFog.hpp
// SYSTEM: World / Atmosphere
// ROLE: Manages the per-biome, per-weather atmospheric fog parameters
//   that are passed to the rendering post-process fog pass (fog_ps.hlsl).
//   This is the C++ state manager — it does NOT own GPU resources.
//   PostProcessPass owns the GPU resources; this class provides values.
//
// INTEGRATION:
//   - D3D11Renderer::Update() calls AtmosphericFog::Update() each frame.
//   - PostProcessPass::ApplyFog() reads GetFogParams() to upload cbuffer.
//   - WeatherSystem drives weather intensity.
//   - DayNightCycle drives time-of-day density changes.
//   - WorldGrid drives biome-specific fog color.
//
// FOG BEHAVIOR PER BIOME:
//   Grassland:  Light grey-blue haze. Medium density. Horizon visibility ~400u.
//   Desert:     Warm sandy haze. High density at midday (heat shimmer). ~250u.
//   Rocky/Mountain: Cool grey. Dense fog in valleys at dawn/dusk. ~300u.
//   Snow:       White mist. High density in storm. ~200u.
//
// FOG BEHAVIOR BY TIME OF DAY:
//   Dawn (0.2–0.3 normalized time): density × 1.5, cool blue tint
//   Noon (0.45–0.55):               density × 0.7, warm haze color
//   Dusk (0.7–0.8):                 density × 1.3, orange-pink tint
//   Night (0.9–1.0, 0.0–0.1):      density × 1.8, dark purple/grey
//
// FOG BEHAVIOR BY WEATHER:
//   Clear:  weatherIntensity = 0.3
//   Cloudy: weatherIntensity = 0.6
//   Rain:   weatherIntensity = 0.85
//   Storm:  weatherIntensity = 1.0
//
// FOR QWEN: Implement Update() and GetFogParams() in AtmosphericFog.cpp.
// ============================================================

#pragma once
#include <string>

// ============================================================
// FogSettings
// Passed to PostProcessPass::ApplyFog() each frame.
// Must match fog_ps.hlsl FogParams cbuffer layout.
// ============================================================
struct FogSettings
{
    float fogColor[3]        = { 0.7f, 0.75f, 0.8f }; // Default: cool grey-blue
    float fogDensity         = 0.003f;
    float fogNearPlane       = 0.1f;
    float fogFarPlane        = 1000.0f;
    float fogHeightFalloff   = 0.5f;
    float fogMaxHeight       = 50.0f;
    float fogWeatherIntensity = 0.3f;
};


// ============================================================
// AtmosphericFog
// ============================================================
class AtmosphericFog
{
public:
    AtmosphericFog();
    ~AtmosphericFog() = default;

    // --------------------------------------------------------
    // Initialize
    // Sets up fog based on the starting biome.
    //   startBiome: "grassland", "desert", "rocky", "snow"
    //   nearPlane, farPlane: match D3D11 projection parameters.
    // --------------------------------------------------------
    void Initialize(const std::string& startBiome,
                    float nearPlane = 0.1f,
                    float farPlane  = 1000.0f);

    // --------------------------------------------------------
    // Update
    // Recalculates fog parameters based on current state.
    //   biome: current biome (from WorldGrid active cell).
    //   weatherIntensity: from WeatherSystem (0=clear, 1=storm).
    //   timeOfDay: normalized time [0,1] from DayNightCycle.
    //   dt: frame delta time for smooth transitions.
    //
    // TODO (Qwen): Implement smooth transitions between fog states:
    //   1. Look up base fog color and density for biome (GetBiomeFogBase).
    //   2. Apply time-of-day density modifier (GetTimeOfDayModifier).
    //   3. Apply weather intensity multiplier.
    //   4. Lerp m_currentSettings toward target values at blend speed 0.5*dt.
    //      This prevents sudden pop when biome or weather changes.
    // --------------------------------------------------------
    void Update(const std::string& biome,
                float weatherIntensity,
                float timeOfDay,
                float dt);

    // --------------------------------------------------------
    // GetFogParams
    // Returns current fog settings for PostProcessPass to upload.
    // Call once per frame just before ApplyFog().
    // --------------------------------------------------------
    const FogSettings& GetFogParams() const { return m_currentSettings; }

    // --------------------------------------------------------
    // SetEnabled / IsEnabled
    // Disabled = PostProcessPass skips fog pass entirely (Low preset).
    // --------------------------------------------------------
    void SetEnabled(bool enabled) { m_enabled = enabled; }
    bool IsEnabled()         const { return m_enabled; }

    // --------------------------------------------------------
    // SetFarPlane
    // Matches near/far when D3D11Renderer projection changes.
    // --------------------------------------------------------
    void SetFarPlane(float nearPlane, float farPlane);

private:
    FogSettings m_currentSettings; // Active fog state (smoothly blended)
    FogSettings m_targetSettings;  // What we're blending toward
    bool        m_enabled = false;
    bool        m_initialized = false;

    // --------------------------------------------------------
    // GetBiomeFogBase
    // Returns the fog color and base density for a biome.
    // Used as the starting point before time-of-day/weather modifiers.
    //
    // TODO (Qwen): Implement per-biome tuning table:
    //   Grassland: color=(0.70,0.75,0.80), density=0.0025
    //   Desert:    color=(0.85,0.78,0.60), density=0.004
    //   Rocky:     color=(0.60,0.62,0.65), density=0.003
    //   Snow:      color=(0.85,0.88,0.95), density=0.005
    // --------------------------------------------------------
    static FogSettings GetBiomeFogBase(const std::string& biome);

    // --------------------------------------------------------
    // GetTimeOfDayModifier
    // Returns a density multiplier based on time of day.
    //   0.2–0.3 (dawn):   1.5×
    //   0.45–0.55 (noon): 0.7×
    //   0.7–0.8 (dusk):   1.3×
    //   night:             1.8×
    //
    // TODO (Qwen): Implement using piecewise linear interpolation
    // between the time bands listed above. Use smoothstep for soft edges.
    // --------------------------------------------------------
    static float GetTimeOfDayModifier(float normalizedTime);

    // --------------------------------------------------------
    // GetTimeOfDayColorTint
    // Returns an additive fog color tint for time of day.
    //   Dawn: (+0.05, +0.02, -0.03) — slightly warm blue
    //   Noon: (+0.05, +0.03, -0.02) — warm haze
    //   Dusk: (+0.10, +0.02, -0.08) — orange-pink
    //   Night: (-0.20, -0.18, -0.10) — dark, purple-grey shift
    //
    // TODO (Qwen): return a float3 shift to add to fogColor for each band.
    // --------------------------------------------------------
    static void GetTimeOfDayColorTint(float normalizedTime,
                                      float& dr, float& dg, float& db);
};

// ============================================================
// FILE: src/world/VolumetricCloud.hpp
// SYSTEM: World / Atmosphere
// ROLE: Manages the per-frame cloud parameters passed to cloud_ps.hlsl.
//   This is a C++ state manager — it does NOT own GPU resources.
//   The renderer (future CloudRenderer or PostProcessPass) owns the GPU side.
//   This class drives the cloud visual state based on weather and time.
//
// INTEGRATION:
//   - WeatherSystem::GetState() / GetWindStrength() drives cloud coverage.
//   - DayNightCycle::GetNormalizedTime() drives cloud lighting color.
//   - D3D11Renderer (future): calls VolumetricCloud::GetCloudParams() and
//     uploads to cloud_ps.hlsl cbuffer.
//   - cloud_ps.hlsl produces the final cloud visual.
//
// CLOUD COVERAGE PER WEATHER STATE:
//   WeatherState::Clear:  coverage = 0.05–0.15 (sparse wispy clouds)
//   WeatherState::Cloudy: coverage = 0.55–0.70 (overcast)
//   WeatherState::Rain:   coverage = 0.80–0.90 (heavy cloud cover)
//   WeatherState::Storm:  coverage = 0.95–1.00 (near total coverage)
//
// CLOUD COLOR BY TIME OF DAY:
//   Dawn: pinkish-orange base, warm sun tint
//   Noon: bright white, strong sun highlight
//   Dusk: orange-red base, flame-colored sun tint
//   Night: dark grey-blue, no sun tint
//
// WIND SCROLLING:
//   cloudScrollX and cloudScrollZ are derived from WeatherSystem::GetWindStrength()
//   and a wind direction (for now, fixed from world config or random).
//   Higher wind = faster cloud scroll. Storm = most turbulent scroll speed.
//
// FOR QWEN: Implement Update() and GetCloudParams() in VolumetricCloud.cpp.
// ============================================================

#pragma once
#include <string>

// ============================================================
// CloudParams
// Passed to cloud_ps.hlsl cbuffer CloudParams each frame.
// Must match the shader cbuffer layout EXACTLY.
// ============================================================
struct CloudParams
{
    float cloudTime        = 0.0f;
    float cloudCoverage    = 0.1f;  // [0,1]
    float cloudScrollX     = 0.01f; // Horizontal wind scroll speed
    float cloudScrollZ     = 0.005f;// Z wind scroll speed

    float cloudBaseColor[3]   = { 0.95f, 0.95f, 0.95f }; // Near-white default
    float cloudShadowStr      = 0.25f; // How dark the undersides are [0,0.6]

    float cloudSunTint[3]     = { 1.0f, 0.97f, 0.88f }; // Warm white sun highlight
    float cloudEdgeSoftness   = 0.08f; // Cloud edge sharpness [0.01=sharp, 0.15=fluffy]

    float _pad[4]; // 16-byte alignment
};


// ============================================================
// VolumetricCloud
// ============================================================
class VolumetricCloud
{
public:
    VolumetricCloud();
    ~VolumetricCloud() = default;

    // --------------------------------------------------------
    // Initialize
    //   windDirectionX, windDirectionZ: normalized 2D wind direction vector.
    //     Drives cloudScrollX/Z from weather wind strength.
    //   baseScrollSpeed: base scroll speed at wind strength 1.0.
    //     Typical: 0.008f for gentle drift.
    // --------------------------------------------------------
    void Initialize(float windDirectionX = 1.0f, float windDirectionZ = 0.3f,
                    float baseScrollSpeed = 0.008f);

    // --------------------------------------------------------
    // Update
    // Recalculates cloud parameters based on current state.
    //   weatherCoverage:  target cloud coverage from weather state [0,1].
    //   windStrength:     WeatherSystem::GetWindStrength() [0,1].
    //   timeOfDay:        DayNightCycle::GetNormalizedTime() [0,1].
    //   dt:               frame delta time in seconds.
    //
    // TODO (Qwen): Implement:
    //   1. Accumulate m_time += dt.
    //   2. Smooth m_coverage toward weatherCoverage (blend speed 0.15*dt).
    //      Clouds build slowly (coverage takes ~30 sec to fully change).
    //   3. Compute scroll speed = windStrength * m_baseScrollSpeed.
    //   4. Compute sun tint from timeOfDay (see header color table).
    //   5. Compute shadow strength: more coverage = darker undersides.
    //      shadowStr = lerp(0.10, 0.50, m_coverage)
    //   6. Store results into m_params.
    // --------------------------------------------------------
    void Update(float weatherCoverage, float windStrength, float timeOfDay, float dt);

    // --------------------------------------------------------
    // GetCloudParams
    // Returns current cloud parameters for shader cbuffer upload.
    // Call once per frame before drawing clouds.
    // --------------------------------------------------------
    const CloudParams& GetCloudParams() const { return m_params; }

    // --------------------------------------------------------
    // SetEnabled / IsEnabled
    // Disabled = cloud draw call is skipped entirely (Low preset).
    // --------------------------------------------------------
    void SetEnabled(bool enabled) { m_enabled = enabled; }
    bool IsEnabled()         const { return m_enabled; }

    // --------------------------------------------------------
    // GetCoverageForSkyTint
    // Returns the current cloud coverage fraction for sky color blending.
    // Overcast sky should be greyer: sky color = lerp(clearSky, overcastGrey, coverage).
    // --------------------------------------------------------
    float GetCoverageForSkyTint() const { return m_params.cloudCoverage; }

private:
    CloudParams m_params;
    bool        m_enabled         = false;
    float       m_time            = 0.0f;
    float       m_windDirX        = 1.0f;
    float       m_windDirZ        = 0.3f;
    float       m_baseScrollSpeed = 0.008f;

    // --------------------------------------------------------
    // GetTimeOfDayCloudColor
    // Returns base cloud color (not sun tint) for time of day.
    //   Dawn: slightly pink    (0.95, 0.85, 0.82)
    //   Noon: bright white     (0.96, 0.96, 0.96)
    //   Dusk: orange-purple    (0.90, 0.72, 0.65)
    //   Night: dark grey-blue  (0.35, 0.38, 0.45)
    //
    // TODO (Qwen): Implement with piecewise lerp between time bands.
    // --------------------------------------------------------
    static void GetTimeOfDayCloudColor(float t,
                                       float& r, float& g, float& b);

    // --------------------------------------------------------
    // GetTimeOfDaySunTint
    // Returns cloud sun tint (edge highlight) for time of day.
    //   Dawn: warm pink    (1.0, 0.80, 0.70)
    //   Noon: warm white   (1.0, 0.97, 0.88)
    //   Dusk: flame orange (1.0, 0.65, 0.35)
    //   Night: no tint     (0.3, 0.33, 0.40)
    //
    // TODO (Qwen): Implement.
    // --------------------------------------------------------
    static void GetTimeOfDaySunTint(float t,
                                    float& r, float& g, float& b);
};

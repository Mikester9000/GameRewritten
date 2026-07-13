// ============================================================
// FILE: Shaders/sky_ps.hlsl
// SYSTEM: Rendering / Sky
// ROLE: Gradient sky dome pixel shader.
//   Renders a fullscreen sky gradient from horizon to zenith.
//   Supports day/night cycle tinting and weather-driven color shifts.
//   Drawn first each frame (no depth write), before any scene geometry.
//
// PIPELINE POSITION: First draw call each frame.
//   D3D11Renderer::DrawSky() binds this shader and draws 3 procedural
//   vertices (SV_VertexID trick — no vertex buffer needed).
//
// DAY/NIGHT DIRECTION:
//   DayNightCycle provides a normalized [0,1] time-of-day value.
//   0.0=midnight, 0.25=dawn, 0.5=noon, 0.75=dusk, 1.0=midnight again.
//   Use this to lerp between night/dawn/noon/dusk sky palettes.
//   Currently the renderer does NOT pass time-of-day to the shader —
//   that wiring must be added to D3D11Renderer.cpp and SkyConstantBuffer.
//
// WEATHER TINT:
//   WeatherSystem::GetSkyColor() returns an RGB tint multiplier.
//   Storm: (0.4, 0.4, 0.5), Clear: (1,1,1). Blend toward this tint
//   using weather blend alpha from WeatherSystem::m_blendAlpha.
//
// HARDWARE TARGET: GT610-safe. Zero texture reads. Pure math only.
//
// FOR QWEN: The TODO sections show what to add for full day/night support.
// ============================================================

// ============================================================
// CONSTANT BUFFER (b2 — per-sky-pass)
// Populated by D3D11Renderer::DrawSky() before draw.
//
// For Qwen: Create this cbuffer in D3D11Renderer.hpp as SkyConstantBuffer.
// Add a matching ID3D11Buffer* m_skyCBuffer member.
// Upload values every frame based on DayNightCycle and WeatherSystem output.
// ============================================================
cbuffer SkyConstantBuffer : register(b2)
{
    // Time of day [0,1]: 0=midnight, 0.5=noon. Drive from DayNightCycle::GetNormalizedTime().
    float skyTimeOfDay;
    // Weather tint RGB. Drive from WeatherSystem::GetSkyColor().
    float3 skyWeatherTint;
    // Weather blend alpha [0,1]. 0=fully previous weather, 1=fully current.
    float skyWeatherAlpha;
    float3 _skyPad; // 16-byte alignment padding
};


// ============================================================
// PALETTE HELPERS
// Each returns a (topColor, bottomColor) pair for a sky band.
// Lerp between them based on skyTimeOfDay to produce smooth transitions.
//
// TODO (Qwen): Implement DawnSky(), DuskSky(), NightSky() as shown,
// then blend between them in main() using skyTimeOfDay bands.
// ============================================================

// Noon sky: clear blue gradient
float3 NoonTopColor()    { return float3(0.13f, 0.35f, 0.80f); }  // deep blue zenith
float3 NoonBottomColor() { return float3(0.65f, 0.82f, 0.95f); }  // pale horizon haze

// TODO (Qwen): Dawn palette (warm orange/pink horizon)
// float3 DawnTopColor()    { return float3(0.15f, 0.20f, 0.60f); }
// float3 DawnBottomColor() { return float3(0.95f, 0.55f, 0.25f); }

// TODO (Qwen): Dusk palette (orange/purple)
// float3 DuskTopColor()    { return float3(0.20f, 0.12f, 0.45f); }
// float3 DuskBottomColor() { return float3(0.90f, 0.45f, 0.20f); }

// TODO (Qwen): Night palette (dark navy, stars implied by solid color)
// float3 NightTopColor()    { return float3(0.02f, 0.03f, 0.12f); }
// float3 NightBottomColor() { return float3(0.08f, 0.10f, 0.18f); }


// ============================================================
// MAIN ENTRY POINT
//
// Input: uv.y from sky_vs.hlsl ranges 0 (horizon) to 1 (zenith).
//
// Current implementation: Static noon sky (no day/night yet).
// TODO (Qwen): Replace static palette with time-of-day blending:
//   1. Classify skyTimeOfDay into bands: night/dawn/noon/dusk/night.
//   2. Compute lerp t within band (0=entering, 1=leaving).
//   3. Lerp top and bottom colors from band A → band B.
//   4. Lerp sky gradient from bottom to top using uv.y.
//   5. Multiply by skyWeatherTint (lerped by skyWeatherAlpha).
// ============================================================
float4 main(float4 pos : SV_POSITION, float2 uv : TEXCOORD0) : SV_TARGET
{
    // Current: static noon palette
    float3 topColor    = NoonTopColor();
    float3 bottomColor = NoonBottomColor();

    // uv.y = 0 at horizon, 1 at zenith
    float t = saturate(uv.y);
    float3 color = lerp(bottomColor, topColor, t);

    // TODO (Qwen): Replace above with time-of-day blended palette.
    // Then apply weather tint:
    // color = lerp(color, color * skyWeatherTint, skyWeatherAlpha);

    return float4(color, 1.0f);
}
// ============================================================
// FILE: Shaders/cloud_ps.hlsl
// SYSTEM: Rendering / Atmosphere
// ROLE: Volumetric cloud layer pixel shader — a VERY cheap approximation
//   suitable for a GT610 with no compute shaders and no 3D noise textures.
//
// APPROACH: Layered 2D noise clouds drawn on a high-altitude billboard quad
//   (not true volumetric raymarching). Two scrolling noise textures (or
//   procedural FBM) sample cloud density at the billboard UV, then composite
//   onto the sky behind terrain geometry.
//
// WHY NOT TRUE VOLUMETRIC:
//   True volumetric cloud raymarching requires 64–128 steps per pixel, which
//   is ~100× too expensive for a GT610. The billboard approach gives acceptable
//   visual results for a JRPG open world at 1/10th the cost.
//
// PIPELINE POSITION: Drawn AFTER the sky quad, BEFORE terrain geometry.
//   Uses depth test disabled + alpha blending to composite clouds over sky.
//   Called by CloudRenderer::Draw() (to be implemented in WaterRenderer sibling class).
//
// CLOUD RENDERING APPROACH:
//   1. UV from a flat billboard quad covering sky region.
//   2. Sample noise texture at two different scales (large + small features).
//   3. FBM-style sum: density = noise1 * 0.6 + noise2 * 0.4
//   4. Remap density through a soft step to control cloudiness.
//   5. Tint cloud by sun color (brighter at edges, dark inside).
//   6. Add weather-driven cloud coverage multiplier.
//   7. Alpha blend result over existing sky color.
//
// PROCEDURAL ALTERNATIVE (no textures — GT610 safe):
//   If cloud texture is not loaded, fall back to a simple analytical function:
//     float hash(float2 p) { ... sin-based hash ... }
//     float fbm(float2 p)  { 4 octaves of smoothed hash }
//     float density = smoothstep(0.45, 0.55, fbm(uv + scrollOffset));
//
// FOR QWEN: Implement the procedural path first (no texture dependency).
//   The texture path can be added later once assets are ready.
// ============================================================

// ============================================================
// CONSTANT BUFFERS
// ============================================================

// Cloud visual parameters (slot b5, or b6 if fog is also active — agree on layout)
cbuffer CloudParams : register(b5)
{
    float cloudTime;         // Accumulated time (drives scrolling). Same as waterTime.
    float cloudCoverage;     // [0,1]: 0=clear sky, 1=full overcast. From WeatherSystem.
    float cloudScrollX;      // Horizontal scroll speed (world wind direction).
    float cloudScrollZ;      // Vertical (Z-axis) scroll speed.
    float3 cloudBaseColor;   // Base cloud color (typically white or pale grey).
    float  cloudShadowStr;   // Shadow darkening on the bottom of clouds [0,0.6].
    float3 cloudSunTint;     // Sun-facing edge tint (warm white, e.g. (1,0.97,0.88)).
    float  cloudEdgeSoftness;// Controls cloud edge sharpness. 0.01=sharp, 0.15=fluffy.
    float3 _cloudPad;        // 16-byte alignment
};

// Light direction (shared with main scene — slot b1)
cbuffer LightCBuffer : register(b1)
{
    float3 lightDir;
    float  pad0;
    float3 lightColor;
    float  ambientStrength;
};


// ============================================================
// RESOURCES (all optional — procedural fallback if not bound)
// ============================================================

// Large-scale cloud shape noise (t0, optional)
// If not bound: fall back to procedural FBM in main().
Texture2D    cloudNoiseA : register(t0);
SamplerState cloudSamplerA : register(s0); // Linear wrap

// Small-scale detail noise (t1, optional)
Texture2D    cloudNoiseB : register(t1);
SamplerState cloudSamplerB : register(s1); // Linear wrap


// ============================================================
// HELPER: SimpleHash
// A fast, cheap 2D hash for procedural noise generation.
// Input: 2D coordinate. Output: pseudo-random float in [0,1].
//
// TODO (Qwen): Implement:
//   return frac(sin(dot(p, float2(127.1f, 311.7f))) * 43758.5453f);
// ============================================================
float SimpleHash(float2 p)
{
    // STUB
    return frac(sin(dot(p, float2(127.1f, 311.7f))) * 43758.5453f);
}


// ============================================================
// HELPER: SmoothNoise
// Value noise with bilinear interpolation. One octave.
// Input: continuous 2D position. Output: smooth float [0,1].
//
// TODO (Qwen): Implement standard value noise:
//   float2 i = floor(p);
//   float2 f = frac(p);
//   f = f*f*(3.0f-2.0f*f);  // Hermite smoothstep
//   float a = SimpleHash(i);
//   float b = SimpleHash(i + float2(1,0));
//   float c = SimpleHash(i + float2(0,1));
//   float d = SimpleHash(i + float2(1,1));
//   return lerp(lerp(a,b,f.x), lerp(c,d,f.x), f.y);
// ============================================================
float SmoothNoise(float2 p)
{
    float2 i = floor(p);
    float2 f = frac(p);
    f = f * f * (3.0f - 2.0f * f);
    float a = SimpleHash(i);
    float b = SimpleHash(i + float2(1.0f, 0.0f));
    float c = SimpleHash(i + float2(0.0f, 1.0f));
    float d = SimpleHash(i + float2(1.0f, 1.0f));
    return lerp(lerp(a, b, f.x), lerp(c, d, f.x), f.y);
}


// ============================================================
// HELPER: CloudFBM
// Fractal Brownian Motion — 4 octaves of SmoothNoise layered together.
// More octaves = more detail; 4 is the GT610 sweet spot.
//
// TODO (Qwen): Implement:
//   float v = 0; float amp = 0.5; float freq = 1.0;
//   for (int i=0; i<4; i++) { v += SmoothNoise(p*freq)*amp; freq*=2; amp*=0.5; }
//   return v;
// ============================================================
float CloudFBM(float2 p)
{
    float v   = 0.0f;
    float amp = 0.5f;
    float freq = 1.0f;
    // Unrolled loop (GT610-safe — no dynamic loops in PS 4.0)
    v += SmoothNoise(p * freq) * amp; freq *= 2.0f; amp *= 0.5f;
    v += SmoothNoise(p * freq) * amp; freq *= 2.0f; amp *= 0.5f;
    v += SmoothNoise(p * freq) * amp; freq *= 2.0f; amp *= 0.5f;
    v += SmoothNoise(p * freq) * amp;
    return v;
}


// ============================================================
// MAIN ENTRY POINT
//
// Cloud rendering pipeline:
//   1. Scroll UV by time and wind direction.
//   2. Sample/compute cloud density (procedural FBM or texture).
//   3. Apply coverage: density = saturate((density - (1-coverage)) / cloudEdgeSoftness).
//      This shifts the density threshold so coverage=0 = no clouds, coverage=1 = full.
//   4. Compute sun-facing tint: top edge (NdotL analog) gets sunTint, bottom gets shadow.
//   5. Compose cloud color: lerp(cloudBaseColor * shadowFactor, cloudSunTint, facing).
//   6. Output: float4(cloudColor, density). Alpha = density drives blending.
//      At alpha=0 → sky shows through. At alpha=1 → cloud fully opaque.
//
// For Qwen: fill in each step. 
// ============================================================
float4 main(float2 uv : TEXCOORD0) : SV_TARGET
{
    // Step 1: Scroll UVs by wind
    float2 scrolledUV = uv + float2(cloudScrollX, cloudScrollZ) * cloudTime * 0.01f;

    // Step 2: Sample cloud density
    // Procedural path (no texture dependency):
    float density = CloudFBM(scrolledUV * 3.5f);
    // TODO (Qwen): optionally blend with texture samples for more varied shapes:
    // if (cloudNoiseA is bound) density = lerp(density, cloudNoiseA.Sample(cloudSamplerA, scrolledUV).r, 0.5f);

    // Step 3: Apply cloud coverage threshold
    // coverage=0 → threshold near 1 → very little shows. coverage=1 → threshold at 0 → all clouds show.
    float threshold = 1.0f - cloudCoverage;
    float cloudAlpha = saturate((density - threshold) / max(cloudEdgeSoftness, 0.001f));

    // Step 4: Sun-facing tint
    // Approximate: clouds facing up (toward sky) are brighter; undersides are darker.
    // In a billboard approach: use a fixed fake "up-facing" factor since we have no normal.
    float sunFacing = 0.7f; // top portion of cloud; bottom is ~0.3
    // TODO (Qwen): could use uv.y to distinguish top vs bottom of cloud mass.

    // Step 5: Cloud color
    float3 cloudColor = lerp(cloudBaseColor * (1.0f - cloudShadowStr),
                             cloudBaseColor * cloudSunTint,
                             sunFacing);

    // Optionally modulate by sun color from light cbuffer
    cloudColor *= lerp(float3(1,1,1), lightColor, 0.3f);

    // Step 6: Output with alpha for blending over sky
    return float4(cloudColor, cloudAlpha);
}

// ============================================================
// FILE: Shaders/water_vs.hlsl
// SYSTEM: Rendering / Water
// ROLE: Vertex shader for water plane rendering.
//   Animates a flat horizontal quad with sine-wave vertex displacement
//   to simulate gentle water waves. Outputs position and UVs for the
//   pixel shader's reflection/refraction/caustics sampling.
//
// PIPELINE POSITION: Called by WaterRenderer::Draw() after terrain pass.
//   Draws a flat grid mesh (e.g. 32x32 quads) centered at the water body.
//
// WAVE SIMULATION:
//   Use two overlapping sine waves (different frequency + direction) to
//   avoid obvious repeating patterns. Cheap and GT610-safe.
//   Wave 1: primary swell — large amplitude, low frequency, diagonal.
//   Wave 2: chop — small amplitude, high frequency, perpendicular.
//
//   Displacement formula (Qwen to implement):
//     float wave1 = waterWave1Amp * sin(worldPos.x * waterWave1Freq
//                                      + worldPos.z * 0.4f
//                                      + waterTime * waterWave1Speed);
//     float wave2 = waterWave2Amp * sin(worldPos.z * waterWave2Freq
//                                      + worldPos.x * 0.3f
//                                      + waterTime * waterWave2Speed * 1.3f);
//     float waveY = wave1 + wave2;
//     // Displace vertex upward by waveY
//
// NORMAL ESTIMATION:
//   Compute a rough analytic normal from the wave derivative.
//   Or pass UV to PS and let it sample a normal map (if available).
//   For GT610 stub: use a fixed upward normal (0,1,0) — correct for flat water.
//
// FOR QWEN: Implement the cbuffer and the wave math in the main() function.
// ============================================================

// ============================================================
// CONSTANT BUFFERS
// ============================================================

// Per-object transform (matches ground_vs.hlsl pattern, slot b0)
cbuffer PerDraw : register(b0)
{
    float4x4 mvp;   // Model-View-Projection matrix
    float4x4 world; // World matrix (for normal transform)
    float4   tintColor; // Water tint RGBA (e.g. (0.1, 0.4, 0.7, 0.85) for blue, semi-transparent)
    float4   windParams; // x=windX, y=windZ, z=windStrength, w=unused
};

// Per-frame water parameters (slot b3 — after LightCBuffer at b1, CelParams at b2)
cbuffer WaterParams : register(b3)
{
    float waterTime;       // Accumulated time in seconds (drives wave animation)
    float waterWave1Amp;   // Wave 1 amplitude (world units). Typical: 0.05–0.15
    float waterWave1Freq;  // Wave 1 spatial frequency. Typical: 0.8–1.5
    float waterWave1Speed; // Wave 1 time speed. Typical: 0.5–1.0
    float waterWave2Amp;   // Wave 2 amplitude. Typical: 0.02–0.06
    float waterWave2Freq;  // Wave 2 frequency. Typical: 2.0–4.0
    float waterWave2Speed; // Wave 2 time speed. Typical: 1.5–2.5
    float waterLevel;      // Global Y position of the water plane (world space)
    // Reflection/refraction UVs are derived in PS — not needed here
    float3 _waterPad;      // 16-byte alignment
};


// ============================================================
// VERTEX INPUT / OUTPUT
// ============================================================

struct VSIn
{
    float3 pos    : POSITION; // Vertex position in object space (y=0 for flat grid)
    float3 normal : NORMAL;   // Should be (0,1,0) for water plane input
    float4 col    : COLOR;    // Vertex color (pass-through tint)
    float2 uv     : TEXCOORD0;// Texture coordinates for normal map / refraction
};

struct VSOut
{
    float4 svPos    : SV_POSITION; // Clip-space position for rasterizer
    float3 worldPos : TEXCOORD0;   // World-space position for PS lighting calc
    float3 worldNorm: NORMAL;      // World-space normal (perturbed by waves)
    float2 uv       : TEXCOORD1;   // UVs for normal/refraction texture sampling
    float4 col      : COLOR;       // Passed-through tint color
};


// ============================================================
// MAIN VERTEX SHADER
//
// TODO (Qwen): Implement in the following order:
//   1. Compute world-space XZ position from input vertex.
//   2. Apply waterLevel offset to set base Y height.
//   3. Calculate wave1 and wave2 displacement using sin() math above.
//   4. Add waveY displacement to world-space Y.
//   5. Transform displaced world position through MVP matrix.
//   6. Compute approximate normal from wave derivative (or use (0,1,0)).
//   7. Pass through UV and color.
// ============================================================
VSOut main(VSIn input)
{
    VSOut output;

    // Step 1-2: Base world position at waterLevel
    float4 worldPos4 = mul(float4(input.pos, 1.0f), world);
    worldPos4.y = waterLevel; // Lock to water height before wave displacement

    // TODO (Qwen): Step 3-4 — add wave displacement to worldPos4.y
    // float wave1 = waterWave1Amp * sin(worldPos4.x * waterWave1Freq
    //                                   + worldPos4.z * 0.4f
    //                                   + waterTime * waterWave1Speed);
    // float wave2 = waterWave2Amp * sin(worldPos4.z * waterWave2Freq
    //                                   + worldPos4.x * 0.3f
    //                                   + waterTime * waterWave2Speed * 1.3f);
    // worldPos4.y += wave1 + wave2;

    // Step 5: Transform to clip space
    output.svPos    = mul(worldPos4, mvp);

    // Step 6: Normal (stub: flat up — replace with wave-derivative normal)
    // TODO (Qwen): compute analytic normal from wave partial derivatives:
    //   dY/dX and dY/dZ -> normal = normalize(float3(-dYdX, 1, -dYdZ))
    output.worldNorm = float3(0.0f, 1.0f, 0.0f);

    // Step 7: Pass through
    output.worldPos = worldPos4.xyz;
    output.uv       = input.uv;
    output.col      = tintColor; // Water color from cbuffer, not vertex

    return output;
}

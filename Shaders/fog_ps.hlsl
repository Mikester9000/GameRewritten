// ============================================================
// FILE: Shaders/fog_ps.hlsl
// SYSTEM: Rendering / Atmosphere
// ROLE: Atmospheric depth fog fullscreen post-process pixel shader.
//   Reads the scene color and depth, then blends toward a fog color
//   based on scene depth (exponential squared fog). Produces the
//   moody, biome-appropriate atmosphere visible across large open
//   world distances — e.g. misty mountains, dusty desert haze.
//
// PIPELINE POSITION: Post-process pass after main scene render but
//   before LUT. Applied by D3D11Renderer::ApplyAtmosphericFog() (to add).
//   Only run on Medium/High presets; on Low use per-vertex fog in ground_ps.
//
// DEPTH-BASED FOG MATH:
//   Exponential squared fog provides smooth, physically plausible falloff:
//     fogFactor = exp(-(fogDensity * viewDepth)^2)
//     fogFactor = saturate(fogFactor)
//     result = lerp(fogColor, sceneColor, fogFactor)
//   fogFactor = 1.0 → fully visible, 0.0 → fully fogged.
//
// DEPTH RECONSTRUCTION:
//   D3D11 stores depth in [0,1] NDC range in the depth buffer.
//   To recover view-space depth (linearized):
//     float ndcZ = depthSample * 2.0f - 1.0f;              // [-1, 1]
//     float viewDepth = (2.0f * nearPlane * farPlane) /
//                       (farPlane + nearPlane - ndcZ * (farPlane - nearPlane));
//   Then use viewDepth in the fog formula.
//
// HARDWARE TARGET: GT610-safe. One depth texture read + one scene read.
//   Total: 2 texture samples per pixel — within budget.
//
// FOR QWEN: Implement each TODO section. Do not add new textures beyond t0/t1.
// ============================================================

// ============================================================
// CONSTANT BUFFERS
// ============================================================

// Fog parameters driven by AtmosphericFog C++ system (slot b5)
cbuffer FogParams : register(b5)
{
    // Fog color (lerp target). Changes per biome:
    //   Grassland: light grey-blue (0.7, 0.75, 0.8)
    //   Desert: warm sandy haze (0.85, 0.78, 0.60)
    //   Rocky: cool grey (0.6, 0.62, 0.65)
    //   Snow: white-blue (0.85, 0.88, 0.95)
    float3 fogColor;
    float  fogDensity;    // Controls fog falloff speed [0.001–0.01]. Higher = thicker.

    float  fogNearPlane;  // Camera near plane distance (match D3D11 projection setup)
    float  fogFarPlane;   // Camera far plane distance
    float  fogHeightFalloff; // [0,1] how much height reduces fog. 0=uniform, 1=hugs ground.
    float  fogMaxHeight;  // World Y above which fog density goes to 0.

    // Weather-driven intensity multiplier [0,1].
    //   Clear=0.3, Cloudy=0.6, Rain=0.8, Storm=1.0
    float  fogWeatherIntensity;
    float3 _fogPad;       // 16-byte alignment
};


// ============================================================
// RESOURCES
// ============================================================

// The rendered scene color (before fog application)
Texture2D    sceneTexture : register(t0);
SamplerState sceneSampler : register(s0);

// The scene depth buffer (DXGI_FORMAT_R24_UNORM_X8_TYPELESS or R32_FLOAT)
// Must be bound as a shader resource view by the calling pass.
// NOTE: Cannot bind a depth buffer as both DSV and SRV simultaneously.
// Copy depth to a secondary R32_FLOAT render target, or use SRV-friendly format.
// TODO (Qwen/engineer): In WaterRenderer or PostProcessPass, resolve depth to texture.
Texture2D    depthTexture : register(t1);
SamplerState depthSampler : register(s1);


// ============================================================
// HELPER: LinearizeDepth
// Converts an NDC depth value [0,1] to view-space linear depth.
//   ndcDepth: value read from depth buffer (0=near, 1=far in D3D11)
//   near, far: projection near/far planes
//
// Returns: linear depth in view space (camera units, ~= world units)
//
// TODO (Qwen): Implement formula:
//   float z = ndcDepth;
//   return (2.0f * near * far) / (far + near - z * (far - near));
// ============================================================
float LinearizeDepth(float ndcDepth, float near, float far)
{
    // STUB: return raw depth until formula is implemented
    return ndcDepth * far;
}


// ============================================================
// HELPER: ComputeFogFactor
// Computes exponential-squared fog factor.
//   depth: view-space linear depth in world units
//   density: fog density coefficient
//
// Returns: fog factor [0,1]. 1=fully visible, 0=fully fogged.
//
// TODO (Qwen): Implement:
//   float d = density * depth;
//   return saturate(exp(-d * d));
// ============================================================
float ComputeFogFactor(float depth, float density)
{
    // STUB
    return 1.0f; // No fog until implemented
}


// ============================================================
// HELPER: ApplyHeightFog
// Reduces fog density for pixels that are above fogMaxHeight.
// High-altitude pixels (mountain peaks) should not be fogged.
//
// This requires worldPos.y which is NOT available in a post-process pass
// without a world-position reconstruction pass. For simplicity on GT610:
//   OPTION A: Skip height fog entirely (use fog as pure depth fog).
//   OPTION B: Encode world Y into an extra render target channel.
//   OPTION C: Approximate from depth + camera height (rough but fast).
//
// Stub: returns unmodified fogFactor (Option A default).
// TODO (Qwen): decide which option to implement and wire accordingly.
// ============================================================
float ApplyHeightFog(float fogFactor, float approxWorldY)
{
    // STUB: no height adjustment
    return fogFactor;
}


// ============================================================
// MAIN ENTRY POINT
//
// Fog application pipeline:
//   1. Sample scene color at uv.
//   2. Sample depth at uv.
//   3. Linearize depth to view space.
//   4. Compute fog factor.
//   5. Modulate by fogWeatherIntensity.
//   6. Lerp scene color toward fogColor using fog factor.
//   7. Output.
//
// For Qwen: fill in each step by replacing STUB calls.
// ============================================================
float4 main(float2 uv : TEXCOORD0) : SV_TARGET
{
    // Step 1: Scene color
    float3 sceneColor = sceneTexture.Sample(sceneSampler, uv).rgb;

    // Step 2: Depth sample
    float rawDepth = depthTexture.Sample(depthSampler, uv).r;

    // Step 3: Linearize depth
    float viewDepth = LinearizeDepth(rawDepth, fogNearPlane, fogFarPlane);

    // Step 4: Fog factor
    // Scale density by weather intensity before computing
    float effectiveDensity = fogDensity * fogWeatherIntensity;
    float fogFactor = ComputeFogFactor(viewDepth, effectiveDensity);

    // Step 5: Height adjustment (stub pass-through for now)
    fogFactor = ApplyHeightFog(fogFactor, 0.0f);

    // Step 6: Blend
    // fogFactor=1 → scene visible, fogFactor=0 → fully fogged
    float3 finalColor = lerp(fogColor, sceneColor, fogFactor);

    return float4(saturate(finalColor), 1.0f);
}

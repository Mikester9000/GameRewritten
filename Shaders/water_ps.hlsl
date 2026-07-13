// ============================================================
// FILE: Shaders/water_ps.hlsl
// SYSTEM: Rendering / Water
// ROLE: Pixel shader for water plane rendering.
//   Produces the visual appearance of water: semi-transparent,
//   reflective surface with depth-based color, Fresnel edge glow,
//   and optional simple caustic overlay when underwater light is needed.
//
// PIPELINE POSITION: Paired with water_vs.hlsl. Drawn after terrain,
//   before transparent actors. Uses alpha blending (SrcAlpha / InvSrcAlpha).
//   The D3D11 blend state must be set by WaterRenderer before calling Draw().
//
// VISUAL GOALS (GT610 budget — NO deferred rendering):
//   1. Depth-based color: deeper = darker, more saturated blue.
//   2. Fresnel: glancing angles = more reflection, normal incidence = transparent.
//   3. Reflection: use a static sky color or a pre-rendered environment cube.
//      For stub: use the sky top-color as a constant reflection color.
//   4. Specular: simple Phong highlight from sun direction.
//   5. Caustics (optional, Medium+): animated UV pattern sampled from a caustic texture.
//
// FRESNEL APPROXIMATION (Schlick):
//   F = F0 + (1 - F0) * (1 - dot(N, V))^5
//   Where F0 ≈ 0.02 for water (2% reflectance at normal incidence).
//   Result: edges look mirror-like, center looks transparent/deep.
//
// HARDWARE TARGET: GT610-safe. Max 2 texture samples per pixel.
//   No real-time planar reflections (too expensive). Use sky color constant.
//
// FOR QWEN: Implement each TODO section below in order.
// ============================================================

// ============================================================
// CONSTANT BUFFERS (match water_vs.hlsl layout exactly)
// ============================================================

cbuffer LightCBuffer : register(b1)
{
    float3 lightDir;       // Normalized direction FROM surface TO sun
    float  pad0;
    float3 lightColor;     // Sun color (RGB)
    float  ambientStrength;
};

cbuffer WaterParams : register(b3)
{
    float waterTime;
    float waterWave1Amp;
    float waterWave1Freq;
    float waterWave1Speed;
    float waterWave2Amp;
    float waterWave2Freq;
    float waterWave2Speed;
    float waterLevel;
    float3 _waterPad;
};

// Water-specific visual parameters (slot b4)
cbuffer WaterVisualParams : register(b4)
{
    // Depth color: color of deep water (e.g. dark teal)
    float3 waterDeepColor;    // e.g. (0.02, 0.15, 0.30)
    float  waterDepthScale;   // How fast color shifts to deep color. Typical: 0.15

    // Shallow color: color at surface / shallow edge
    float3 waterShallowColor; // e.g. (0.10, 0.45, 0.65)
    float  waterTransparency; // Base alpha at normal incidence [0.3–0.7]

    // Reflection sky color (used as constant reflection — no RTT needed)
    float3 waterReflectColor; // Usually driven from sky_ps NoonBottomColor()
    float  waterFresnelPower; // Fresnel power. Typical: 3–5.

    // Specular
    float waterSpecPower;     // Shininess. Typical: 32–128. Higher = tighter highlight.
    float waterSpecStrength;  // Multiplier [0.2–1.0]
    float2 _vispad;
};


// ============================================================
// RESOURCES (textures — optional, bound only on Medium+)
// ============================================================

// Normal map for fine surface ripple detail (t0, optional)
// If not bound, use the interpolated normal from VS.
// TODO (Qwen): wire normal map loading in WaterRenderer::Initialize().
Texture2D    waterNormalMap : register(t0);
SamplerState normalSampler  : register(s0);

// Caustic pattern texture (t1, optional, only on Medium+ preset)
// Animated by offsetting UV with waterTime. Multiply onto underwater lit surfaces.
Texture2D    causticTexture : register(t1);
SamplerState causticSampler : register(s1);


// ============================================================
// VERTEX INPUT (from water_vs.hlsl VSOut)
// ============================================================
struct PSIn
{
    float4 svPos    : SV_POSITION;
    float3 worldPos : TEXCOORD0;
    float3 worldNorm: NORMAL;
    float2 uv       : TEXCOORD1;
    float4 col      : COLOR;
};


// ============================================================
// HELPER: SchlickFresnel
// Approximates the Fresnel reflectance using the Schlick formula.
//   N = surface normal (normalized)
//   V = view direction toward camera (normalized)
//   F0 = reflectance at normal incidence (0.02 for water)
//
// TODO (Qwen): Replace stub with full Schlick formula:
//   float cosTheta = saturate(dot(N, V));
//   return F0 + (1.0f - F0) * pow(1.0f - cosTheta, 5.0f);
// ============================================================
float SchlickFresnel(float3 N, float3 V, float F0)
{
    // STUB: return constant mid-Fresnel value until implemented
    // TODO (Qwen): implement: return F0 + (1-F0)*pow(1-saturate(dot(N,V)), waterFresnelPower);
    return 0.3f;
}


// ============================================================
// HELPER: WaterSpecular
// Computes a simple Phong specular highlight from sun direction.
//   N = surface normal
//   V = view direction
//   L = light direction (toward sun, = -lightDir)
//
// TODO (Qwen): Implement:
//   float3 R = reflect(-L, N);
//   float spec = pow(saturate(dot(R, V)), waterSpecPower);
//   return lightColor * spec * waterSpecStrength;
// ============================================================
float3 WaterSpecular(float3 N, float3 V, float3 L)
{
    // STUB: no specular yet
    return float3(0.0f, 0.0f, 0.0f);
}


// ============================================================
// MAIN ENTRY POINT
//
// Full water shading pipeline:
//   1. Reconstruct normal (from normal map or interpolated VS normal).
//   2. Compute view direction V = normalize(cameraPos - worldPos).
//      NOTE: camera position must be passed via constant buffer!
//      Add float3 cameraWorldPos to WaterVisualParams or a shared cbuffer.
//   3. Fresnel factor f = SchlickFresnel(N, V, 0.02).
//   4. Base water color: lerp(waterShallowColor, waterDeepColor, depth factor).
//      Depth factor: use worldPos.y below waterLevel — clamp to [0,1].
//      depthT = saturate((waterLevel - worldPos.y) * waterDepthScale);
//      Since water plane IS at waterLevel, depthT is typically 0 here.
//      Real depth shading requires a depth buffer read (skip on Low).
//   5. Reflection contribution: waterReflectColor * f.
//   6. Specular highlight: WaterSpecular().
//   7. Compose: finalColor = lerp(waterColor, reflectColor, f) + specular.
//   8. Alpha: lerp(waterTransparency, 1.0, f) — edges are more opaque.
//   9. Output float4(finalColor, alpha).
//
// For Qwen: implement steps 1-9. Remove all STUB comments when done.
// ============================================================
float4 main(PSIn input) : SV_TARGET
{
    // Step 1: Surface normal
    // TODO (Qwen): sample waterNormalMap using scrolled UV for ripple detail:
    //   float2 scrolledUV = input.uv + float2(waterTime * 0.02f, waterTime * 0.015f);
    //   float3 normalSample = waterNormalMap.Sample(normalSampler, scrolledUV).rgb * 2.0f - 1.0f;
    //   Blend with interpolated normal: N = normalize(input.worldNorm + normalSample * 0.3f);
    float3 N = normalize(input.worldNorm); // STUB: use VS normal directly

    // Step 2: View direction
    // TODO (Qwen): replace with (cameraWorldPos - input.worldPos) once cbuffer has cameraWorldPos
    float3 V = float3(0.0f, 1.0f, 0.0f); // STUB: point straight up

    // Step 3: Fresnel
    float fresnel = SchlickFresnel(N, V, 0.02f);

    // Step 4: Water color (shallow for now; depth shading is a future enhancement)
    float3 waterColor = waterShallowColor; // STUB: no depth shading yet
    // TODO (Qwen): compute depthT and lerp: lerp(waterShallowColor, waterDeepColor, depthT)

    // Step 5: Reflection
    float3 reflection = waterReflectColor * fresnel;

    // Step 6: Specular
    float3 L = normalize(-lightDir); // Direction toward sun
    float3 specular = WaterSpecular(N, V, L);

    // Step 7: Compose
    float3 finalColor = lerp(waterColor, reflection, fresnel) + specular;

    // Optional caustic overlay (Medium+ only)
    // TODO (Qwen): if (graphicsPreset >= Medium) {
    //   float2 causticUV = input.uv * 3.0f + float2(waterTime * 0.05f, waterTime * 0.03f);
    //   float3 caustic = causticTexture.Sample(causticSampler, causticUV).rgb;
    //   finalColor += caustic * 0.15f; // subtle overlay
    // }

    // Step 8: Alpha
    float alpha = lerp(waterTransparency, 1.0f, fresnel);

    // Step 9: Output
    return float4(saturate(finalColor), saturate(alpha));
}

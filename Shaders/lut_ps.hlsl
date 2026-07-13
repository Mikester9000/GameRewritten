// ============================================================
// FILE: Shaders/lut_ps.hlsl
// SYSTEM: Rendering / Post-Process
// ROLE: Full-screen LUT (Look-Up Table) color grading pass.
//   Applied after the main scene is rendered to a render texture.
//   Reads the scene color and remaps it through a 3D LUT texture to
//   produce the final on-screen color. Controls mood, contrast, and
//   overall visual identity without changing scene geometry.
//
// PIPELINE POSITION: This is the LAST pixel shader pass before Present.
//   Order: Scene → Cel pass → Outline pass → LUT pass → SwapChain.
//
// HARDWARE TARGET: D3D11, GT610-safe. One fullscreen quad, no MRT.
//   Only run on Medium/High presets. On Low: skip this pass entirely.
//
// HOW A 3D LUT WORKS:
//   A 3D LUT is a 3D texture (e.g. 16x16x16 or 32x32x32 RGBA).
//   Each axis = one color channel (R, G, B). The value at (r,g,b) is
//   the *remapped* output color. To apply:
//     1. Read scene pixel color (r,g,b) in [0,1].
//     2. Use (r,g,b) as UVW coordinates into the 3D LUT texture.
//     3. The sampled RGBA is the output color. (Ignore alpha if unused.)
//   This lets artists bake any color transform into the LUT offline,
//   then apply it at runtime with a single texture sample — very cheap.
//
// FOR QWEN: Implement the steps below. Each TODO is one logical unit.
// ============================================================

#include "ColorGradingHeader.hlsl"

// --- RESOURCES ---
// The scene color render target (the rendered frame before post-process).
// Bound at t0 by D3D11Renderer::ApplyPostProcess() before drawing.
Texture2D    sceneTexture : register(t0);
SamplerState linearSampler : register(s0); // Linear clamp sampler

// The 3D LUT texture. Created once at startup, loaded from Content/LUTs/.
// Format: DXGI_FORMAT_R8G8B8A8_UNORM, dimensions 16x16x16 (2048-byte cost).
// On GT610: use 16^3 LUT max. 32^3 is too large for VRAM budget on Low.
Texture3D    lutTexture    : register(t1);
SamplerState lutSampler    : register(s1); // Linear clamp (no wrapping)


// ============================================================
// HELPER: ApplyLUT
// Remaps an input scene color through the 3D LUT texture.
//
// Steps for Qwen to implement:
//   1. Scale inColor from [0,1] to LUT UV space.
//      For a 16x16x16 LUT: uvw = inColor * (15.0/16.0) + (0.5/16.0)
//      This keeps samples at texel centers (avoids edge clamping errors).
//   2. Sample lutTexture at uvw using lutSampler.
//   3. Return the .rgb of the sampled value.
//
// Do NOT multiply by lutParams.x (intensity) here — do it in main().
// ============================================================
float3 ApplyLUT(float3 inColor)
{
    // TODO (Qwen): Implement LUT UV remapping and Texture3D sample.
    // The LUT is 16x16x16. Map inColor [0,1] -> texel center UVW.
    // float3 uvw = inColor * (15.0f / 16.0f) + (0.5f / 16.0f);
    // return lutTexture.Sample(lutSampler, uvw).rgb;
    return inColor; // STUB: pass-through until implemented
}


// ============================================================
// HELPER: AdjustBrightnessContrast
// Applies the lutParams.y (brightness) and lutParams.z (contrast)
// adjustments to the color BEFORE feeding into the LUT.
//
// Standard contrast formula:
//   color = (color - 0.5) * contrast + 0.5 + brightness
// Clamp result to [0,1] to prevent NaN in LUT sampling.
//
// Qwen: implement and replace the stub below.
// ============================================================
float3 AdjustBrightnessContrast(float3 color, float brightness, float contrast)
{
    // TODO (Qwen): Apply brightness offset then contrast scale around 0.5.
    // color = saturate((color - 0.5f) * contrast + 0.5f + brightness);
    return saturate(color); // STUB
}


// ============================================================
// HELPER: AdjustSaturation
// Adjusts color saturation using luminance-based desaturation.
// Uses ITU-R BT.601 luma weights (matches FF7-style warmth).
//
// Formula:
//   luma = dot(color, float3(0.299, 0.587, 0.114))
//   result = lerp(float3(luma,luma,luma), color, saturation)
//
// Qwen: implement below.
// ============================================================
float3 AdjustSaturation(float3 color, float saturation)
{
    // TODO (Qwen): Compute BT.601 luma and lerp toward gray.
    // float luma = dot(color, float3(0.299f, 0.587f, 0.114f));
    // return lerp(float3(luma, luma, luma), color, saturation);
    return color; // STUB
}


// ============================================================
// MAIN ENTRY POINT
// Full-screen post-process pixel shader.
// Input: uv from a screen-space fullscreen quad vertex shader
//   (see basic3d_vs.hlsl or a dedicated postprocess_vs.hlsl)
//
// Pipeline:
//   1. Sample the scene color from sceneTexture.
//   2. Apply brightness/contrast correction (uses lutParams.y, .z).
//   3. Apply saturation adjustment (uses lutParams.w).
//   4. Feed adjusted color into ApplyLUT() to remap through 3D LUT.
//   5. Blend between original and LUT result by lutParams.x (intensity).
//      intensity=0 → original, intensity=1 → full LUT output.
//   6. Output final clamped color.
//
// Guards:
//   - If lutParams.x <= 0.0 skip all work and return scene color.
//   - Always clamp final output to [0,1] range.
//
// Qwen: fill in each step. Replace all STUBs before marking done.
// ============================================================
float4 main(float2 uv : TEXCOORD0) : SV_TARGET
{
    // Step 1: Sample scene color
    float3 sceneColor = sceneTexture.Sample(linearSampler, uv).rgb;

    // Guard: if intensity is zero, skip all processing (Low preset path)
    // TODO (Qwen): add guard: if (lutParams.x <= 0.0f) return float4(sceneColor, 1.0f);

    // Step 2: Brightness + contrast
    // lutParams.y = brightness offset [-0.5, 0.5], lutParams.z = contrast scale [0.5, 2.0]
    float3 adjusted = AdjustBrightnessContrast(sceneColor, lutParams.y, lutParams.z);

    // Step 3: Saturation
    // lutParams.w = saturation [0.0=greyscale, 1.0=unchanged, 2.0=boost]
    adjusted = AdjustSaturation(adjusted, lutParams.w);

    // Step 4: LUT remap
    float3 gradedColor = ApplyLUT(adjusted);

    // Step 5: Blend original vs LUT output by intensity
    // lutParams.x = LUT blend intensity [0,1]
    // TODO (Qwen): float3 finalColor = lerp(sceneColor, gradedColor, lutParams.x);

    float3 finalColor = gradedColor; // STUB: replace with lerp above

    // Step 6: Output
    return float4(saturate(finalColor), 1.0f);
}

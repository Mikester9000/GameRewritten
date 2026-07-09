// basic3d_ps.hlsl 
// NOTE: Updated with Outline Pass support, structured Constant Buffer definitions, 
// Cel/Banded Shading, Rim Lighting, and full Phong-like calculation tailored for an Anime aesthetic.


// --- DEFINITION FIXES START HERE (Required for compilation) ---

struct LightData
{
    float4 Color; // The color of the light source (R, G, B, A)
    float3 Direction; // The direction vector from the surface to the light source
};

struct NormalData
{
    // Placeholder structure - Required if the cbuffer references it
};


cbuffer ConstantBuffer : register(b0)
{
    float4x4 WorldViewProj;
    LightData Light;
    NormalData NormalWS;
    Texture2D AlbedoMap;

    // Task Controls: Cel Diffuse (Indices 30, 31, 32 assumed)
    float CelBandCount;
    float CelDiffuseMin;
    float CelDiffuseMax;

    // Outline Pass Control (This factor is now only used for standard rendering detection)
    float OutlineColorFactor;

    // Task 030B: Shadow Tint & Rim Gate
    float4 ShadowColor; // Color multiplier for ambient/shadowed areas (R, G, B, A)
    float RimStrength; // Strength of the rim effect
    float RimThreshold; // Angle threshold to activate rim light

    // Task 030C: Specular Control
    float SpecBandCount; // Number of specular bands/steps
    float SpecularityPower; // Controls how quickly highlights drop off
};


struct PSInput
{
    float4 pos : SV_POSITION;
    float3 normalWS : NORMAL; // The interpolated Normal Vector (N)
    float4 col : COLOR; // Base Color/Albedo from Vertex Shader output
    float3 viewDirWS : TEXCOORD0; // Placeholder for interpolated View Direction (V)
};

// --- NEW: Outline Params CB Definition ---
struct OutlineStructure
{
    float OutlineThickness;
    float OutlineColorFactor2;
};


cbuffer OutlineParams : register(b1)
{
    OutlineStructure OutlineParams;
};


static const float AMBIENT_STRENGTH = 0.2f;


// Helper function to implement Cel/Banded Step Function
// Quantizes a value (like NdotL or NdotV) into discrete bands.
float stepValue(float value, float count, float minVal, float maxVal)
{
    if (count <= 0)
        return saturate(value);
    
    // Map the raw dot product range [minVal, maxVal] to [0, 1]
    float normalized = saturate((value - minVal) / (maxVal - minVal));
    
    // Determine the step size and apply the banding/stepping logic
    float stepSize = 1.0f / count;
    return floor(normalized / stepSize + 0.5) * stepSize; // Simple quantization
}


float4 main(PSInput input) : SV_TARGET
{
    // --- ROBUST OUTLINE PASS CHECK: Check the dedicated Outline Params buffer first. ---
    if (OutlineParams.OutlineThickness > 0.01)
    {
        // Return a solid dark color for the silhouette.
        return float4(0.05f, 0.1f, 1.0f, 1.0f); // Dark Blue/Black Outline Color
    }

    // ===============================================
    // --- STANDARD RENDERING PATH (Full Lighting Calculation) ---
    // ===============================================
    
    float3 N = normalize(input.normalWS); // Normal vector
    float3 V = normalize(input.viewDirWS); // View direction vector (Camera to surface)

    // Light Direction: We use the negative of the light's stored direction 
    // because the stored 'Direction' usually points FROM the object TO the light source.
    float3 L_raw = normalize(-Light.Direction);
    float NdotL = saturate(dot(N, L_raw));

    // 1. AMBIENT LIGHT (Base Illumination)
    // We use a slightly desaturated ambient contribution for that FF feel.
    float3 ambientColor = float3(0.2f, 0.2f * ShadowColor.r, 0.2f * ShadowColor.g);
    float3 finalColor = input.col.rgb * ambientColor;


    // --- 2. DIFFUSE LIGHTING (Cel/Banded Shading) ---
    
    // The raw dot product used for diffuse falloff
    float diffuseRaw = NdotL;

    // Apply Cel Banding: This steps the smooth gradient into discrete bands.
    // We use saturate to keep the input range correct, and assume min/max are based on light interaction (0 to 1).
    float steppedDiffuse = stepValue(diffuseRaw, CelBandCount, 0.0f, 1.0f);

    // Calculate Diffuse Contribution: Apply banding to the diffuse effect.
    float3 diffuseContribution = input.col.rgb * L_raw * steppedDiffuse;
    finalColor += diffuseContribution;


    // --- 3. RIM LIGHTING (Edge Glow) ---
    
    // Rim light strength is maximized when N and V are nearly perpendicular to the edge view direction.
    // We calculate how much the normal deviates from looking straight at the camera.
    float rimFactor = 1.0f - saturate(dot(N, normalize(V)));

    // Apply thresholding: Only activate if we pass the specified angle threshold.
    float rimIntensity = max(0.0f, rimFactor - RimThreshold);
    
    float3 rimContribution = float3(1.0f, 1.0f, 0.8f) * rimIntensity * RimStrength; // Example glow color (warm yellow/white)

    // Blend the rim contribution additively
    finalColor += rimContribution;


    // --- 4. SPECULAR LIGHTING (Banded Highlight) ---
    
    float3 R = normalize(reflect(-L_raw, N)); // Reflection vector of light source off the surface
    float specRaw = saturate(dot(V, R)); // Dot product between view and reflection vector

    // Apply Specular Banding: Steps the highlight into discrete bands.
    float steppedSpec = stepValue(specRaw, SpecBandCount, 0.0f, 1.0f);
    
    // Use a power curve (Phong-like) on the banded value for controlled falloff
    float specularContribution = pow(steppedSpec, SpecularityPower);

    // Calculate final specular color (using a slightly off-white/blueish highlight for that classic FF feel)
    float3 specularColor = float3(0.9f, 0.95f, 1.0f) * specularContribution;


    // --- 5. FINAL MIXING AND OUTPUT ---

    // The final color is the sum of Ambient + Diffuse (stepped) + Rim + Specular
    float3 totalLight = finalColor.rgb + specularColor;

    return float4(
        totalLight, // Final RGB color
        input.col.a); // Use original alpha
}

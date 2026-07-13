// prim_ps.hlsl
// Pixel shader for primitive (box) prefab parts.
// PS2-style: simple directional light + ambient, no textures, vertex-color tinted.

cbuffer PerDraw : register(b0)
{
    float4x4 mvp;        // not used in PS, kept for alignment
    float4x4 world;      // not used in PS, kept for alignment
    float4   tintColor;  // per-instance RGBA color
};

cbuffer LightCBuffer : register(b1)
{
    float3 lightDir;
    float  pad0;
    float3 lightColor;
    float  ambientStrength;
};

struct PSIn
{
    float4 svPos     : SV_POSITION;
    float3 worldNorm : NORMAL;
    float4 col       : COLOR; // white (1,1,1,1) from VS
};

float4 main(PSIn input) : SV_TARGET
{
    float3 nIn  = input.worldNorm;
    float3 n    = (dot(nIn, nIn) > 0.000001f) ? normalize(nIn) : float3(0.0f, 1.0f, 0.0f);
    float3 ld   = (dot(lightDir, lightDir) > 0.000001f) ? lightDir : float3(0.45f, -1.0f, 0.35f);
    float3 l    = normalize(-ld); // direction toward the light
    float  diff = saturate(dot(n, l));

    float ambient = max(ambientStrength, 0.08f);
    float3 safeLightColor = (dot(lightColor, lightColor) > 0.000001f) ? lightColor : float3(1.0f, 1.0f, 1.0f);
    float3 litColor = tintColor.rgb * (safeLightColor * diff + ambient.xxx);
    return float4(litColor, tintColor.a);
}

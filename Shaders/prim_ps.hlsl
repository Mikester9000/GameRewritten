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
    float3 n    = normalize(input.worldNorm);
    float3 l    = normalize(-lightDir); // direction toward the light
    float  diff = saturate(dot(n, l));

    float3 litColor = tintColor.rgb * (lightColor * diff + float3(ambientStrength, ambientStrength, ambientStrength));
    return float4(litColor, tintColor.a);
}

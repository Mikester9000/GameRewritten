// prim_ps.hlsl
// Pixel shader for primitive (box) prefab parts.
// PS2-style: simple directional light + ambient, no textures, vertex-color tinted.

cbuffer PerDraw : register(b0)
{
    float4x4 mvp;        // not used in PS, kept for alignment
    float4x4 world;      // not used in PS, kept for alignment
    float4   tintColor;  // per-instance RGBA color
    float4   lightDir;   // directional light direction (world space, toward light)
    float4   lightColor; // directional light RGB
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
    float3 l    = normalize(-lightDir.xyz); // direction toward the light
    float  diff = saturate(dot(n, l));

    // Ambient + diffuse directional light.
    float3 ambient  = tintColor.rgb * 0.25f;
    float3 diffuse  = tintColor.rgb * diff * lightColor.rgb * 0.75f;

    return float4(ambient + diffuse, tintColor.a);
}

// tree_ps.hlsl
// Pixel shader for tree-category prefab parts.
// PS2-style: directional light + ambient + vertical color gradient + cheap
// per-location variation so a forest of identical prefabs looks less uniform.

cbuffer PerDraw : register(b0)
{
    float4x4 mvp;        // alignment padding
    float4x4 world;      // alignment padding
    float4   tintColor;
    float4   lightDir;
    float4   lightColor;
};

struct PSIn
{
    float4 svPos     : SV_POSITION;
    float3 worldPos  : TEXCOORD0;
    float3 worldNorm : NORMAL;
    float4 col       : COLOR;
};

float4 main(PSIn input) : SV_TARGET
{
    float3 n    = normalize(input.worldNorm);
    float3 l    = normalize(-lightDir.xyz);
    float  diff = saturate(dot(n, l));

    // Vertical gradient: darkens parts near Y=0, brightens parts higher up.
    // Scale factor 0.18 tuned so a 2-unit-tall tree transitions from ~0.4 to ~0.8.
    float gradient = saturate(input.worldPos.y * 0.18f + 0.5f);

    // Cheap per-location variation using a hash on the XZ position.
    // This makes every tree look slightly different without any texture.
    float2 xz     = float2(input.worldPos.x, input.worldPos.z);
    float  hash   = frac(sin(dot(xz, float2(127.1f, 311.7f))) * 43758.5453f);
    float  vary   = 1.0f + hash * 0.12f - 0.06f; // +/- 6 % brightness variation

    // Combine: tintColor * gradient * variation * (ambient + diffuse).
    float3 baseColor = tintColor.rgb * gradient * vary;
    float3 ambient   = baseColor * 0.30f;
    float3 diffuse   = baseColor * diff * lightColor.rgb * 0.70f;

    return float4(ambient + diffuse, tintColor.a);
}

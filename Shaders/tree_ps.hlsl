// tree_ps.hlsl
// Pixel shader for tree-category prefab parts.
// PS2-style: directional light + ambient + vertical color gradient + cheap
// per-location variation so a forest of identical prefabs looks less uniform.

cbuffer PerDraw : register(b0)
{
    float4x4 mvp;        // alignment padding
    float4x4 world;      // alignment padding
    float4   tintColor;
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
    float3 worldPos  : TEXCOORD0;
    float3 worldNorm : NORMAL;
    float4 col       : COLOR;
};

float4 main(PSIn input) : SV_TARGET
{
    float3 normalIn = input.worldNorm;
    float3 n = (dot(normalIn, normalIn) > 0.000001f) ? normalize(normalIn) : float3(0.0f, 1.0f, 0.0f);
    float  diff = saturate(dot(n, -lightDir));

    // Vertical gradient: darkens parts near Y=0, brightens parts higher up.
    // Scale factor 0.18 tuned so a 2-unit-tall tree transitions from ~0.4 to ~0.8.
    float gradient = saturate(input.worldPos.y * 0.18f + 0.5f);

    // Cheap per-location variation using a hash on the XZ world position.
    // The constants (127.1, 311.7, 43758.5453) are arbitrary prime-like values
    // chosen to scatter the sine output into pseudo-random results — a common
    // GPU hash pattern. This makes every tree look slightly different without
    // any texture or extra memory.
    float2 xz     = float2(input.worldPos.x, input.worldPos.z);
    float  hash   = frac(sin(dot(xz, float2(127.1f, 311.7f))) * 43758.5453f);
    float  vary   = 1.0f + hash * 0.12f - 0.06f; // +/- 6 % brightness variation

    // Combine: tintColor * gradient * variation * (lightColor * diffuse + ambient).
    float3 baseColor = tintColor.rgb * gradient * vary;
    float3 litColor  = baseColor * (lightColor * diff + float3(ambientStrength, ambientStrength, ambientStrength));
    return float4(litColor, tintColor.a);
}

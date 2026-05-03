// tree_vs.hlsl
// Vertex shader for tree-category prefab parts.
// Same as prim_vs.hlsl but also outputs world position so the PS can compute
// a vertical color gradient (darker near the ground, lighter toward the canopy).

cbuffer PerDraw : register(b0)
{
    float4x4 mvp;
    float4x4 world;
    float4   tintColor;
    float4   lightDir;
    float4   lightColor;
};

struct VSIn
{
    float3 pos    : POSITION;
    float3 normal : NORMAL;
    float4 col    : COLOR;
};

struct VSOut
{
    float4 svPos     : SV_POSITION;
    float3 worldPos  : TEXCOORD0; // world-space position for gradient
    float3 worldNorm : NORMAL;
    float4 col       : COLOR;
};

VSOut main(VSIn input)
{
    VSOut o;
    float4 worldPos4 = mul(float4(input.pos, 1.0f), world);
    o.svPos     = mul(float4(input.pos, 1.0f), mvp);
    o.worldPos  = worldPos4.xyz;
    o.worldNorm = normalize(mul(float4(input.normal, 0.0f), world).xyz);
    o.col       = input.col;
    return o;
}

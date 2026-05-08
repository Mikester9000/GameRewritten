// prim_vs.hlsl
// Vertex shader for primitive (box) prefab parts.
// Outputs world position for the pixel shader's directional light calculation.

cbuffer PerDraw : register(b0)
{
    float4x4 mvp;        // model-view-projection (pre-transposed)
    float4x4 world;      // world matrix (pre-transposed)
    float4   tintColor;  // per-instance color override
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
    float3 worldNorm : NORMAL;
    float4 col       : COLOR;
};

VSOut main(VSIn input)
{
    VSOut o;
    o.svPos     = mul(float4(input.pos, 1.0f), mvp);
    o.worldNorm = normalize(mul(float4(input.normal, 0.0f), world).xyz);
    o.col       = input.col; // white vertex color — tint applied in PS
    return o;
}

cbuffer Transform : register(b0)
{
    float4x4 mvp;
    float4x4 world;
};

struct VSIn
{
    float3 pos : POSITION;
    float3 normal : NORMAL;
    float4 col : COLOR;
};

struct VSOut
{
    float4 pos : SV_POSITION;
    float3 normal : NORMAL;
    float4 col : COLOR;
};

VSOut main(VSIn input)
{
    VSOut o;
    o.pos = mul(float4(input.pos, 1.0f), mvp);
    o.normal = normalize(mul(float4(input.normal, 0.0f), world).xyz);
    o.col = input.col;
    return o;
}
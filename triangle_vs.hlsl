cbuffer Transform : register(b0)
{
    float xOffset;
    float3 _pad; // pad to 16 bytes (constant buffers are 16-byte aligned)
};

struct VSIn
{
    float3 pos : POSITION;
    float4 col : COLOR;
};

struct VSOut
{
    float4 pos : SV_POSITION;
    float4 col : COLOR;
};

VSOut main(VSIn input)
{
    VSOut o;
    o.pos = float4(input.pos.x + xOffset, input.pos.y, input.pos.z, 1.0f);
    o.col = input.col;
    return o;
}
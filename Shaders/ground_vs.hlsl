struct VSInput
{
    float3 pos : POSITION;
    float3 normal : NORMAL;
    float4 color : COLOR;
};

struct VSOutput
{
    float4 pos : SV_POSITION;
    float3 normal : NORMAL;
    float4 color : COLOR;
    float2 uv : TEXCOORD0;
};

cbuffer Transform : register(b0)
{
    float4x4 mvp;
};

VSOutput main(VSInput input)
{
    VSOutput output;
    output.pos = mul(float4(input.pos, 1.0f), mvp);
    output.normal = input.normal;
    output.color = input.color;

    // Tile the texture in world space across terrain and ground.
    output.uv = input.pos.xz * 0.05f;

    return output;
}

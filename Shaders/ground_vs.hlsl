struct VSInput
{
    float3 pos : POSITION;
    float3 normal : NORMAL; // Add this
    float4 color : COLOR;
};

struct VSOutput
{
    float4 pos : SV_POSITION;
    float3 normal : NORMAL; // Add this
    float4 color : COLOR;
};

cbuffer Transform : register(b0)
{
    float4x4 mvp;
};

VSOutput main(VSInput input)
{
    VSOutput output;
    output.pos = mul(float4(input.pos, 1.0f), mvp);
    output.normal = input.normal; // Pass normal through
    output.color = input.color;
    return output;
}
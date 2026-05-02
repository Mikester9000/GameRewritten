cbuffer Light : register(b1)
{
    float4 lightDirection;
    float4 lightColor;
};

struct PSInput
{
    float4 pos : SV_POSITION;
    float3 normal : NORMAL;
    float4 color : COLOR;
};

float4 main(PSInput input) : SV_TARGET
{
    float3 n = normalize(input.normal);
    float3 l = normalize(-lightDirection.xyz);
    float ndotl = saturate(dot(n, l));
    float3 litColor = input.color.rgb * (0.2f + 0.8f * ndotl) * lightColor.rgb;
    return float4(litColor, input.color.a);
}
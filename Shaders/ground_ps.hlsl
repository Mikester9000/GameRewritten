Texture2D diffuseTexture : register(t0);
SamplerState diffuseSampler : register(s0);

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
    float2 uv : TEXCOORD0;
};

float4 main(PSInput input) : SV_TARGET
{
    float3 n = normalize(input.normal);
    float3 l = normalize(-lightDirection.xyz);
    float ndotl = saturate(dot(n, l));

    float3 texColor = diffuseTexture.Sample(diffuseSampler, input.uv).rgb;
    float3 baseColor = texColor * input.color.rgb;
    float3 litColor = baseColor * (0.2f + 0.8f * ndotl) * lightColor.rgb;

    return float4(litColor, input.color.a);
}

Texture2D diffuseTexture : register(t0);
SamplerState diffuseSampler : register(s0);

cbuffer LightCBuffer : register(b1)
{
    float3 lightDir;
    float  pad0;
    float3 lightColor;
    float  ambientStrength;
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
    float3 normalIn = input.normal;
    float3 n = (dot(normalIn, normalIn) > 0.000001f) ? normalize(normalIn) : float3(0.0f, 1.0f, 0.0f);
    float diff = saturate(dot(n, -lightDir));
    float3 texColor = diffuseTexture.Sample(diffuseSampler, input.uv).rgb;
    float3 baseColor = texColor * input.color.rgb;
    float3 litColor = baseColor * (lightColor * diff + float3(ambientStrength, ambientStrength, ambientStrength));
    return float4(litColor, input.color.a);
}

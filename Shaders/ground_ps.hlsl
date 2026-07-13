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
    float3 ld = (dot(lightDir, lightDir) > 0.000001f) ? lightDir : float3(0.45f, -1.0f, 0.35f);
    float diff = saturate(dot(n, -normalize(ld)));
    float3 texColor = diffuseTexture.Sample(diffuseSampler, input.uv).rgb;
    float3 baseColor = input.color.rgb * lerp(float3(1.0f, 1.0f, 1.0f), texColor, 0.65f);
    float ambient = max(ambientStrength, 0.10f);
    float3 safeLightColor = (dot(lightColor, lightColor) > 0.000001f) ? lightColor : float3(1.0f, 1.0f, 1.0f);
    float3 litColor = baseColor * (safeLightColor * diff + ambient.xxx);
    return float4(litColor, input.color.a);
}

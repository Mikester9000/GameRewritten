#include "CelShaderHeader.hlsl"

float4 CelPS(VSOut input) : SV_TARGET
{
    float3 normal = normalize(input.worldNorm);
    float ndotL = saturate(dot(normal, normalize(-lightDir)));
    
    // 3-step quantization logic
    float quantized = ceil(ndotL * 3.0f) / 3.0f;
    float lighting = max(0.15f, quantized);
    
    float3 litColor = tintColor.rgb * lightColor * lighting;
    return float4(litColor, tintColor.a);
}

float4 main(VSOut input) : SV_TARGET
{
    return CelPS(input);
}

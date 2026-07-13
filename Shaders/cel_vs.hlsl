#include "CelShaderHeader.hlsl"

VSOut CelVS(VSIn input)
{
    VSOut output;
    output.svPos = mul(float4(input.pos, 1.0f), mvp);
    output.worldNorm = normalize(mul(float4(input.normal, 0.0f), world).xyz);
    return output;
}

float4 main(VSIn input) : SV_POSITION
{
    VSOut output;
    output.svPos = mul(float4(input.pos, 1.0f), mvp);
    output.worldNorm = normalize(mul(float4(input.normal, 0.0f), world).xyz);
    return output.svPos;
}

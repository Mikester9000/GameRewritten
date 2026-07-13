#include "CelShaderHeader.hlsl"
#include "SilhouetteHeader.hlsl"

VSOut OutlineVS(VSIn input)
{
    VSOut output;
    // Use outlineParams.x for the thickness of the expansion
    float3 expandedPosition = input.pos + normalize(input.normal) * outlineParams.x;
    output.svPos = mul(float4(expandedPosition, 1.0f), mvp);
    output.worldNorm = input.normal;
    return output;
}

float4 main(VSIn input) : SV_POSITION
{
    VSOut output;
    float3 expandedPosition = input.pos + normalize(input.normal) * outlineParams.x;
    output.svPos = mul(float4(expandedPosition, 1.0f), mvp);
    output.worldNorm = input.normal;
    return output.svPos;
}

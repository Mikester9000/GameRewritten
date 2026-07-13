#include "CelShaderHeader.hlsl"
#include "SilhouetteHeader.hlsl"

float4 OutlinePS(VSOut input) : SV_TARGET
{
    // Returns a solid color based on the tintColor's alpha
    return float4(0.0f, 0.0f, 0.0f, tintColor.a);
}

float4 main(VSOut input) : SV_TARGET
{
    return OutlinePS(input);
}

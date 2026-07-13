#include "ColorGradingHeader.hlsl"

// This will be expanded once we define the LUT texture sampling logic
float4 main(float2 uv : TEXCOORD0) : SV_TARGET
{
    // TODO: Implement LUT sampling using ColorGradingParams
    return float4(uv, 0, 1);
}

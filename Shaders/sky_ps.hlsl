// Pixel shader for vertical gradient sky
float4 main(float4 pos : SV_POSITION, float2 uv : TEXCOORD0) : SV_TARGET
{
    float3 topColor = float3(0.2, 0.4, 0.8); // Sky blue
    float3 bottomColor = float3(0.8, 0.9, 1.0); // Near horizon
    float t = saturate(uv.y);
    float3 color = lerp(bottomColor, topColor, t);
    return float4(color, 1.0);
}
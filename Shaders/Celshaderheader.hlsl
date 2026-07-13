// Shared constants for the Cel Shading System
cbuffer PerDraw : register(b0)
{
    float4x4 mvp;
    float4x4 world;
    float4 tintColor;
    float4 windParams;
};

cbuffer LightCBuffer : register(b1)
{
    float3 lightDir;
    float pad0;
    float3 lightColor;
    float ambientStrength;
};

cbuffer CelParams : register(b2)
{
    float4 outlineParams; // x = outline width
};

struct VSIn
{
    float3 pos : POSITION;
    float3 normal : NORMAL;
    float4 col : COLOR;
};

struct VSOut
{
    float4 svPos : SV_POSITION;
    float3 worldNorm : NORMAL;
};

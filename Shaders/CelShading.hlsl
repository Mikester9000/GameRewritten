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

VSOut CelVS(VSIn input)
{
    VSOut output;
    output.svPos = mul(float4(input.pos, 1.0f), mvp);
    output.worldNorm = normalize(mul(float4(input.normal, 0.0f), world).xyz);
    return output;
}

float4 CelPS(VSOut input) : SV_TARGET
{
    float3 normal = normalize(input.worldNorm);
    float ndotL = saturate(dot(normal, normalize(-lightDir)));
    float quantized = ceil(ndotL * 3.0f) / 3.0f;
    float lighting = max(0.15f, quantized);
    float3 litColor = tintColor.rgb * lightColor * lighting;
    return float4(litColor, tintColor.a);
}

VSOut OutlineVS(VSIn input)
{
    VSOut output;
    float3 expandedPosition = input.pos + normalize(input.normal) * outlineParams.x;
    output.svPos = mul(float4(expandedPosition, 1.0f), mvp);
    output.worldNorm = input.normal;
    return output;
}

float4 OutlinePS(VSOut input) : SV_TARGET
{
    return float4(0.0f, 0.0f, 0.0f, tintColor.a);
}

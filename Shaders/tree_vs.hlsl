// tree_vs.hlsl
// Vertex shader for tree-category prefab parts.
// Same as prim_vs.hlsl but also outputs world position so the PS can compute
// a vertical color gradient (darker near the ground, lighter toward the canopy).
// Wind sway is applied as a small sinusoidal offset on the upper portion of
// each part, scaled by windParams.y (strength) and driven by windParams.x (time).

cbuffer PerDraw : register(b0)
{
    float4x4 mvp;
    float4x4 world;
    float4   tintColor;
    float4   windParams; // x=time (seconds), y=windStrength [0,1], z=0, w=0
};

struct VSIn
{
    float3 pos    : POSITION;
    float3 normal : NORMAL;
    float4 col    : COLOR;
};

struct VSOut
{
    float4 svPos     : SV_POSITION;
    float3 worldPos  : TEXCOORD0; // world-space position for gradient
    float3 worldNorm : NORMAL;
    float4 col       : COLOR;
};

VSOut main(VSIn input)
{
    VSOut o;

    // Wind sway: only affect the upper portion of tree parts (positive local Y).
    // heightFactor ramps from 0 at Y=0 to 1 at Y=1+, so the base is anchored.
    float heightFactor = saturate(input.pos.y * 0.8f);

    // World-space X/Z position used to de-sync adjacent trees' sway phases.
    float4 worldPos4  = mul(float4(input.pos, 1.0f), world);
    float  phaseSeed  = worldPos4.x * 0.17f + worldPos4.z * 0.13f;

    // Primary sway (left-right on X) + secondary sway (depth on Z, slower).
    float  swayX = sin(windParams.x * 1.8f + phaseSeed)         * 0.06f * heightFactor * windParams.y;
    float  swayZ = cos(windParams.x * 1.1f + phaseSeed * 0.73f) * 0.03f * heightFactor * windParams.y;

    // Apply offset in local space before MVP transform.
    float3 swayedPos = input.pos + float3(swayX, 0.0f, swayZ);

    o.svPos     = mul(float4(swayedPos, 1.0f), mvp);
    o.worldPos  = worldPos4.xyz; // use pre-sway world pos for gradient / PS hash
    o.worldNorm = normalize(mul(float4(input.normal, 0.0f), world).xyz);
    o.col       = input.col;
    return o;
}

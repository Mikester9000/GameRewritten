// basic3d_vs.hlsl 
// NOTE: Updated to support character outline pass by calculating an expanded vertex position.

// --- Constant Buffer Definitions ---

// b0: ModelViewProjection matrix (WorldViewProj) and World matrix
cbuffer Transform : register(b0)
{
    float4x4 mvp; // ModelViewProjection matrix
    float4x4 world; // World matrix
};

// b1: Outline parameters
cbuffer OutlineParams : register(b1)
{
    float OutlineThickness;
};


struct VSIn
{
    float3 pos : POSITION;
    float3 normal : NORMAL;
    float4 col : COLOR;
};

struct VSOut
{
    float4 pos : SV_POSITION;
    float3 normal : NORMAL;
    float4 col : COLOR;
    // We need to pass the original world position for outline calculations in the PS
    float3 originalPosWS : TEXCOORD0;
};

// 1. Define the internal structure layout
struct OutlineData
{
    float OutlineThickness;
    float3 Padding; // Kept for 16-byte alignment rules
};

// 2. Put it in a constant buffer bound to a register slot
cbuffer cbOutline : register(b2) // Use an available slot like b1, b2, etc.
{
    OutlineData OutlineParams;
};

VSOut main(VSIn input)
{
    VSOut o;
    float3 finalPos = input.pos;
    
    // Check if rendering is in Outline Mode (using a simple thickness check for control flow).
    // If OutlineThickness > 0, we are drawing the outline.
    // We access OutlineParams here. This assumes b1 was successfully bound by the calling pipeline.
    if (OutlineParams.OutlineThickness > 0.01)
    {
        // Calculate expanded position: P_expanded = P + N * Thickness
        float3 normalWS = normalize(mul(float4(input.normal, 0.0f), world)).xyz;
        finalPos = input.pos + normalWS * OutlineParams.OutlineThickness;
    }

    // Standard MVP projection for the final position
    o.pos = mul(float4(finalPos, 1.0f), mvp);
    
    // Normal calculation remains the same (uses world space transform)
    o.normal = normalize(mul(float4(input.normal, 0.0f), world)).xyz;
    o.col = input.col;
    o.originalPosWS = mul(float4(input.pos, 1.0f), world).xyz; // Store original world position
    return o;
}

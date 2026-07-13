// Parameters specific to the Silhouette/Outline Pass
cbuffer SilhouetteParams : register(b3)
{
    float4 extraParams; // x = depth offset, y = thickness multiplier, etc.
};

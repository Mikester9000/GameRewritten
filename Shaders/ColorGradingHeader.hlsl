// Parameters for Color Grading and LUT Post-Processing
cbuffer ColorGradingParams : register(b4)
{
    float4 lutParams; // x = intensity, y = brightness, z = contrast, w = saturation
};

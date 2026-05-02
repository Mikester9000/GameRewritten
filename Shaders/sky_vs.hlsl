// Shaders/sky_vs.hlsl

struct VSOut
{
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
};

VSOut main(uint vertexID : SV_VertexID) // <-- must be uint or int
{
    float2 verts[3] = { float2(-1, -1), float2(-1, 3), float2(3, -1) };
    VSOut o;
    o.pos = float4(verts[vertexID], 0.99990f, 1.0f);
    o.uv = verts[vertexID] * 0.5 + 0.5;
    return o;
}
struct VSIn
{
    float3 pos : POSITION;
    float4 col : COLOR;
};

struct VSOut
{
    float4 pos : SV_Position;
    float4 col : COLOR;
};

VSOut main(VSIn v)
{
    VSOut o;
    o.pos = float4(v.pos, 1.0);
    o.col = v.col;
    return o;
}
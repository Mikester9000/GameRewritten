#pragma once

#include <DirectXMath.h>
#include <string>
#include <vector>

namespace D3D11RendererHelpers
{
    struct BiomeGradient
    {
        float lowR, lowG, lowB;
        float hiR, hiG, hiB;
    };

    struct TerrainTuning
    {
        float noiseFreq;
        float heightScale;
    };

    struct TerrainVertex
    {
        float x, y, z;
        float nx, ny, nz;
        float r, g, b, a;
    };
    static_assert(sizeof(TerrainVertex) == 40, "TerrainVertex layout must stay 40 bytes for POSITION/NORMAL/COLOR input layout.");

    struct SceneMatrices
    {
        DirectX::XMMATRIX world;
        DirectX::XMMATRIX view;
        DirectX::XMMATRIX projection;
    };

    BiomeGradient SelectBiomeGradient(const std::string& biome);
    TerrainTuning ApplyBiomeTerrainTuning(const std::string& biome, float noiseFreq, float heightScale);

    float HashNoise(int ix, int iz);
    float SmoothNoise(float fx, float fz);

    void BuildTerrainHeightGrid(
        const std::string& biome,
        int seed,
        float cellOriginX,
        float cellOriginZ,
        float cellWorldSize,
        float noiseFreq,
        float noiseFreq2,
        float heightScale,
        int vertsX,
        int vertsZ,
        float quadSize,
        std::vector<float>& outHeights);

    void HeightToColor(float hy, float halfRange, const BiomeGradient& gradient, float& r, float& g, float& b);

    void EmitTerrainTriangleA(
        float wx0, float wz0, float wx1, float wz1,
        float y00, float y10, float y01,
        float halfRange,
        const BiomeGradient& gradient,
        std::vector<TerrainVertex>& outVerts);

    void EmitTerrainTriangleB(
        float wx0, float wz0, float wx1, float wz1,
        float y10, float y01, float y11,
        float halfRange,
        const BiomeGradient& gradient,
        std::vector<TerrainVertex>& outVerts);

    SceneMatrices BuildSceneMatrices(
        float cameraX, float cameraY, float cameraZ,
        float cameraYaw, float cameraPitch,
        float aspect,
        float nearPlane,
        float farPlane);

    void BuildDefaultDirectionalLight(DirectX::XMFLOAT4& direction, DirectX::XMFLOAT4& color);
}

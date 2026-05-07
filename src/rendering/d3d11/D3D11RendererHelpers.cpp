#include "D3D11RendererHelpers.hpp"

#include <cmath>
#include <cstdint>

namespace D3D11RendererHelpers
{
    namespace
    {
        void NormalizeVector(float& nx, float& ny, float& nz)
        {
            float len = std::sqrt(nx * nx + ny * ny + nz * nz);
            if (len > 0.0001f)
            {
                nx /= len;
                ny /= len;
                nz /= len;
            }
        }

        float SampleRockyTerrainHeight(
            float wx, float wz,
            float cellOriginX, float cellOriginZ, float cellWorldSize,
            float noiseFreq, float noiseFreq2, float heightScale,
            float seedOX, float seedOZ)
        {
            const float cellCenterX = cellOriginX + cellWorldSize * 0.5f;
            const float cellCenterZ = cellOriginZ + cellWorldSize * 0.5f;
            const float invSqrt2 = 0.70710678f;

            float localX = wx - cellCenterX;
            float localZ = wz - cellCenterZ;

            float alongRange = (localX + localZ) * invSqrt2;
            float acrossRange = (localX - localZ) * invSqrt2;

            float halfRangeWidth = cellWorldSize * 0.30f;
            float across01 = 1.0f - (std::fabs(acrossRange) / halfRangeWidth);
            if (across01 < 0.0f) across01 = 0.0f;
            if (across01 > 1.0f) across01 = 1.0f;
            across01 = across01 * across01 * (3.0f - 2.0f * across01);

            float ridgeFreq = (noiseFreq > 0.0001f) ? noiseFreq : 0.0001f;
            float alongShape = 0.5f + 0.5f * SmoothNoise(
                alongRange * ridgeFreq + seedOX * 0.01f,
                seedOZ * 0.01f);
            alongShape = 0.55f + alongShape * 0.45f;

            float secondary = 0.5f + 0.5f * SmoothNoise(
                alongRange * (ridgeFreq * 2.2f) + seedOZ * 0.02f,
                seedOX * 0.02f);
            secondary *= 0.25f;

            float detailFreq = (noiseFreq2 > 0.0001f) ? noiseFreq2 : (ridgeFreq * 3.0f);
            float detail = 0.0f;
            float amp = heightScale * 0.12f;
            float freq = detailFreq;
            float sx = wx + seedOX;
            float sz = wz + seedOZ;
            for (int oct = 0; oct < 3; ++oct)
            {
                detail += SmoothNoise(sx * freq, sz * freq) * amp;
                amp *= 0.5f;
                freq *= 2.0f;
            }
            detail *= across01;

            float baseRange = across01 * heightScale * (alongShape + secondary);
            return baseRange + detail;
        }

        float SampleFbmHeight(float sampleX, float sampleZ, float noiseFreq, float heightScale)
        {
            float h = 0.0f;
            float amp = heightScale;
            float freq = noiseFreq;
            for (int oct = 0; oct < 4; ++oct)
            {
                h += SmoothNoise(sampleX * freq, sampleZ * freq) * amp;
                amp *= 0.5f;
                freq *= 2.0f;
            }
            return h;
        }
    }

    BiomeGradient SelectBiomeGradient(const std::string& biome)
    {
        if (biome == "desert")
            return { 0.78f, 0.65f, 0.35f, 0.90f, 0.85f, 0.72f };
        if (biome == "rocky")
            return { 0.38f, 0.36f, 0.34f, 0.58f, 0.56f, 0.52f };
        if (biome == "snow")
            return { 0.45f, 0.47f, 0.52f, 0.95f, 0.96f, 1.00f };
        return { 0.15f, 0.50f, 0.15f, 0.45f, 0.42f, 0.38f };
    }

    TerrainTuning ApplyBiomeTerrainTuning(const std::string& biome, float noiseFreq, float heightScale)
    {
        TerrainTuning tuning{ noiseFreq, heightScale };
        if (biome == "desert") { tuning.noiseFreq *= 0.6f; }
        if (biome == "rocky") { tuning.noiseFreq *= 1.3f; tuning.heightScale *= 1.1f; }
        if (biome == "snow") { tuning.noiseFreq *= 1.1f; }
        return tuning;
    }

    float HashNoise(int ix, int iz)
    {
        uint32_t n = static_cast<uint32_t>(ix) * 1619u + static_cast<uint32_t>(iz) * 31337u;
        n = (n << 13) ^ n;
        n = n * (n * n * 15731u + 789221u) + 1376312589u;
        return 1.0f - static_cast<float>(n & 0x7fffffffu) / 1073741824.0f;
    }

    float SmoothNoise(float fx, float fz)
    {
        int ix = static_cast<int>(std::floor(fx));
        int iz = static_cast<int>(std::floor(fz));
        float tx = fx - static_cast<float>(ix);
        float tz = fz - static_cast<float>(iz);
        tx = tx * tx * (3.0f - 2.0f * tx);
        tz = tz * tz * (3.0f - 2.0f * tz);
        float h00 = HashNoise(ix, iz);
        float h10 = HashNoise(ix + 1, iz);
        float h01 = HashNoise(ix, iz + 1);
        float h11 = HashNoise(ix + 1, iz + 1);
        return h00 + (h10 - h00) * tx
            + (h01 - h00) * tz
            + (h11 - h10 - h01 + h00) * tx * tz;
    }

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
        std::vector<float>& outHeights)
    {
        float seedOX = static_cast<float>(seed) * 0.12345f;
        float seedOZ = static_cast<float>(seed) * 0.09876f;

        outHeights.resize(static_cast<size_t>(vertsX * vertsZ));
        for (int z = 0; z < vertsZ; ++z)
        {
            for (int x = 0; x < vertsX; ++x)
            {
                float wx = cellOriginX + x * quadSize;
                float wz = cellOriginZ + z * quadSize;

                if (biome == "rocky")
                {
                    outHeights[static_cast<size_t>(z * vertsX + x)] = SampleRockyTerrainHeight(
                        wx, wz, cellOriginX, cellOriginZ, cellWorldSize, noiseFreq, noiseFreq2, heightScale, seedOX, seedOZ);
                    continue;
                }

                float sx = wx + seedOX;
                float sz = wz + seedOZ;
                outHeights[static_cast<size_t>(z * vertsX + x)] = SampleFbmHeight(sx, sz, noiseFreq, heightScale);
            }
        }
    }

    void HeightToColor(float hy, float halfRange, const BiomeGradient& gradient, float& r, float& g, float& b)
    {
        float h01 = (halfRange > 0.0001f) ? (hy + halfRange) / (halfRange * 2.0f) : 0.5f;
        if (h01 < 0.0f) h01 = 0.0f;
        if (h01 > 1.0f) h01 = 1.0f;
        r = gradient.lowR + (gradient.hiR - gradient.lowR) * h01;
        g = gradient.lowG + (gradient.hiG - gradient.lowG) * h01;
        b = gradient.lowB + (gradient.hiB - gradient.lowB) * h01;
    }

    void EmitTerrainTriangleA(
        float wx0, float wz0, float wx1, float wz1,
        float y00, float y10, float y01,
        float halfRange,
        const BiomeGradient& gradient,
        std::vector<TerrainVertex>& outVerts)
    {
        float ax = wx0 - wx0;
        float ay = y01 - y00;
        float az = wz1 - wz0;
        float bx = wx1 - wx0;
        float by = y10 - y00;
        float bz = wz0 - wz0;
        float nx = ay * bz - az * by;
        float ny = az * bx - ax * bz;
        float nz = ax * by - ay * bx;
        NormalizeVector(nx, ny, nz);

        float avgY = (y00 + y01 + y10) / 3.0f;
        float r, g, b;
        HeightToColor(avgY, halfRange, gradient, r, g, b);

        TerrainVertex v0{ wx0, y00, wz0, nx, ny, nz, r, g, b, 1.0f };
        TerrainVertex v1{ wx0, y01, wz1, nx, ny, nz, r, g, b, 1.0f };
        TerrainVertex v2{ wx1, y10, wz0, nx, ny, nz, r, g, b, 1.0f };
        outVerts.push_back(v0);
        outVerts.push_back(v1);
        outVerts.push_back(v2);
    }

    void EmitTerrainTriangleB(
        float wx0, float wz0, float wx1, float wz1,
        float y10, float y01, float y11,
        float halfRange,
        const BiomeGradient& gradient,
        std::vector<TerrainVertex>& outVerts)
    {
        float ax = wx0 - wx1;
        float ay = y01 - y10;
        float az = wz1 - wz0;
        float bx = wx1 - wx1;
        float by = y11 - y10;
        float bz = wz1 - wz0;
        float nx = ay * bz - az * by;
        float ny = az * bx - ax * bz;
        float nz = ax * by - ay * bx;
        NormalizeVector(nx, ny, nz);

        float avgY = (y10 + y01 + y11) / 3.0f;
        float r, g, b;
        HeightToColor(avgY, halfRange, gradient, r, g, b);

        TerrainVertex v0{ wx1, y10, wz0, nx, ny, nz, r, g, b, 1.0f };
        TerrainVertex v1{ wx0, y01, wz1, nx, ny, nz, r, g, b, 1.0f };
        TerrainVertex v2{ wx1, y11, wz1, nx, ny, nz, r, g, b, 1.0f };
        outVerts.push_back(v0);
        outVerts.push_back(v1);
        outVerts.push_back(v2);
    }

    SceneMatrices BuildSceneMatrices(
        float cameraX, float cameraY, float cameraZ,
        float cameraYaw, float cameraPitch,
        float aspect,
        float nearPlane,
        float farPlane)
    {
        float lookDirX = std::cos(cameraPitch) * std::sin(cameraYaw);
        float lookDirY = std::sin(cameraPitch);
        float lookDirZ = std::cos(cameraPitch) * std::cos(cameraYaw);

        DirectX::XMVECTOR cameraPosition = DirectX::XMVectorSet(cameraX, cameraY, cameraZ, 1.0f);
        DirectX::XMVECTOR cameraTarget = DirectX::XMVectorSet(cameraX + lookDirX, cameraY + lookDirY, cameraZ + lookDirZ, 1.0f);
        DirectX::XMVECTOR cameraUp = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

        SceneMatrices result{};
        result.world = DirectX::XMMatrixIdentity();
        result.view = DirectX::XMMatrixLookAtLH(cameraPosition, cameraTarget, cameraUp);
        result.projection = DirectX::XMMatrixPerspectiveFovLH(DirectX::XM_PIDIV4, aspect, nearPlane, farPlane);
        return result;
    }

    void BuildDefaultDirectionalLight(DirectX::XMFLOAT4& direction, DirectX::XMFLOAT4& color)
    {
        direction = DirectX::XMFLOAT4(0.5f, -1.0f, 0.5f, 0.0f);
        color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
    }
}

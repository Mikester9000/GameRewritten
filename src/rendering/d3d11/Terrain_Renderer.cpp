// ============================================================
// FILE: src/rendering/terrain/Terrain_renderer.cpp
// SYSTEM: Rendering / Geometry Generation
// ROLE: Implements all logic for terrain mesh generation and height calculation.
// DEPENDS ON: Terrain_renderer.hpp, D3D11RendererHelpers.hpp, DirectXMath.h
// ============================================================

// Must come before any Windows header to suppress min/max macros.
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include "Terrain_Renderer.hpp"
#include "../../logger/Logger.hpp" // Assume Logger is available
#include <algorithm>
#include <cmath>
#include <vector>
#include "D3D11Renderer.hpp"
using namespace DirectX;

TerrainManager::TerrainManager()
{
    // Constructor initializes state, nothing complex happens here.
}

TerrainManager::~TerrainManager()
{
    Shutdown();
}


bool TerrainManager::Initialize(ID3D11Device* device, ID3D11DeviceContext* context)
{
    m_device = device;
    m_context = context;
    // We don't build the mesh until we have concrete parameters (like cell size).
    return Validate();
}

void TerrainManager::Shutdown()
{
    // Release all resources owned by this manager.
    if (m_terrainPatchVertexBuffer)
    {
        m_terrainPatchVertexBuffer->Release();
        m_terrainPatchVertexBuffer = nullptr;
    }
    m_terrainHeights.clear();
    m_terrainAvailable = false;
}

void TerrainManager::Tick(float deltaTime)
{
    (void)deltaTime;
}

bool TerrainManager::Validate() const
{
    if (!m_device || !m_context)
    {
        LOG_ERROR("TerrainManager validation failed: D3D11 device/context unavailable.");
        return false;
    }
    return true;
}

void TerrainManager::DebugDraw()
{
    // TODO(next-ai): purpose=draw terrain chunk bounds and LOD/culling diagnostics
    // required inputs/outputs=terrain bounds + debug renderer; output diagnostic primitives
    // invariants=must be read-only and never mutate height/mesh data
    // acceptance checks=debug overlay renders bounds without affecting terrain draw calls
    // file ownership/expected edit scope=src/rendering/d3d11/Terrain_Renderer.cpp only
}

// Helper to set up internal state variables based on input parameters.
void TerrainManager::SetupInternal(const D3D11Renderer::TerrainParams& params)
{
    // Reset all state before calculating new geometry
    ClearResources();

    m_terrainVertsX = 0; // Will be overwritten below
    m_terrainVertsZ = 0; // Will be overwritten below
    m_terrainCellSize = 1.0f;
    m_terrainOriginX = params.cellOriginX;
    m_terrainOriginZ = params.cellOriginZ;
    m_terrainHalfSizeX = params.cellWorldSize * 0.5f;
    m_terrainHalfSizeZ = params.cellWorldSize * 0.5f;

    // The actual dimensions are derived from quadsX/quadsZ, but we use the full cell size for now.
}


bool TerrainManager::RebuildTerrainPatch(const D3D11Renderer::TerrainParams& params)
{
    if (!Validate())
        return BuildFallbackPlane(params.cellOriginX, params.cellOriginZ, params.cellWorldSize);

    // Step 1: Setup state based on input parameters
    SetupInternal(params);

    // For consistency with the original logic, we must hardcode the grid size definition.
    // Note: In a real open world implementation, this should dynamically calculate quads/verts.
    const int quadsX = 100;
    const int quadsZ = 100;
    const int vertsX = quadsX + 1;
    const int vertsZ = quadsZ + 1;
    const float quadSize = params.cellWorldSize / static_cast<float>(quadsX);

    m_terrainVertsX = vertsX;
    m_terrainVertsZ = vertsZ;
    m_terrainCellSize = quadSize;


    // --- Step 1: Build shared height grid for SampleTerrainHeight() ---

    const D3D11RendererHelpers::BiomeGradient gradient =
        D3D11RendererHelpers::SelectBiomeGradient(params.biome);
    const D3D11RendererHelpers::TerrainTuning tuning =
        D3D11RendererHelpers::ApplyBiomeTerrainTuning(params.biome, params.noiseFreq, params.heightScale);
    const float nFreq = tuning.noiseFreq;
    const float hScale = tuning.heightScale;

    // This call populates m_terrainHeights (row-major storage)
    D3D11RendererHelpers::BuildTerrainHeightGrid(
        params.biome,
        params.seed,
        params.cellOriginX,
        params.cellOriginZ,
        params.cellWorldSize,
        nFreq,
        params.noiseFreq2,
        hScale,
        vertsX,
        vertsZ,
        quadSize,
        m_terrainHeights);

    // Helper: fetch height from the grid by grid index.
    auto hAt = [&](int xi, int zi) -> float
        {
            return m_terrainHeights[static_cast<size_t>(zi * vertsX + xi)];
        };

    const float halfRange = hScale * 1.5f;

    // --- Step 2: Build unindexed flat-shaded triangle vertices ---
    std::vector<D3D11RendererHelpers::TerrainVertex> triVerts;
    triVerts.reserve(static_cast<size_t>(quadsX * quadsZ * 6));

    for (int z = 0; z < quadsZ; ++z)
    {
        for (int x = 0; x < quadsX; ++x)
        {
            // Corner world positions of this quad.
            float wx0 = params.cellOriginX + x * quadSize;
            float wx1 = params.cellOriginX + (x + 1) * quadSize;
            float wz0 = params.cellOriginZ + z * quadSize;
            float wz1 = params.cellOriginZ + (z + 1) * quadSize;

            // Get heights at corners
            float y00 = hAt(x, z);
            float y10 = hAt(x + 1, z);
            float y01 = hAt(x, z + 1);
            float y11 = hAt(x + 1, z + 1);

            // Emit two triangles forming the quad (Triangle A and B)
            D3D11RendererHelpers::EmitTerrainTriangleA(
                wx0, wz0, wx1, wz1,
                y00, y10, y01,
                halfRange,
                gradient,
                triVerts);

            D3D11RendererHelpers::EmitTerrainTriangleB(
                wx0, wz0, wx1, wz1,
                y10, y01, y11,
                halfRange,
                gradient,
                triVerts);
        }
    }

    m_terrainPatchVertexCount = static_cast<UINT>(triVerts.size());
    if (triVerts.empty())
    {
        LOG_ERROR("TerrainManager generated empty terrain mesh; switching to fallback plane.");
        return BuildFallbackPlane(params.cellOriginX, params.cellOriginZ, params.cellWorldSize);
    }

    if (!UploadVertices(triVerts))
    {
        LOG_ERROR("Failed to upload terrain mesh; switching to fallback plane.");
        return BuildFallbackPlane(params.cellOriginX, params.cellOriginZ, params.cellWorldSize);
    }

    // Success
    m_terrainAvailable = true;
    return true;
}


void TerrainManager::ClearResources()
{
    // Release GPU resources and internal height data.
    if (m_terrainPatchVertexBuffer)
    {
        m_terrainPatchVertexBuffer->Release();
        m_terrainPatchVertexBuffer = nullptr;
    }
    m_terrainHeights.clear();
    m_terrainAvailable = false;
    m_terrainPatchVertexCount = 0;
}


float TerrainManager::SampleTerrainHeight(float worldX, float worldZ) const
{
    if (!m_terrainAvailable || m_terrainVertsX <= 0 || m_terrainVertsZ <= 0)
        return 0.0f;

    // Convert world pos → local grid index using the cell origin.
    float localX = (worldX - m_terrainOriginX) / m_terrainCellSize;
    float localZ = (worldZ - m_terrainOriginZ) / m_terrainCellSize;

    // Clamping logic remains necessary for robust sampling at edges
    if (localX < 0.0f) localX = 0.0f;
    if (localZ < 0.0f) localZ = 0.0f;
    if (localX > static_cast<float>(m_terrainVertsX - 1)) localX = static_cast<float>(m_terrainVertsX - 1);
    if (localZ > static_cast<float>(m_terrainVertsZ - 1)) localZ = static_cast<float>(m_terrainVertsZ - 1);

    int x0 = static_cast<int>(floorf(localX));
    int z0 = static_cast<int>(floorf(localZ));
    // Use min/max to prevent index overflow when sampling exactly at the edge
    int x1 = std::min(x0 + 1, m_terrainVertsX - 1);
    int z1 = std::min(z0 + 1, m_terrainVertsZ - 1);

    float sx = localX - (float)x0;
    float sz = localZ - (float)z0;

    // Lambda captures 'this' to access the height data vector.
    auto hAt = [this](int xi, int zi) -> float {
        return m_terrainHeights[static_cast<size_t>(zi * m_terrainVertsX + xi)];
        };

    // Bilinear interp (Logic remains correct)
    float h00 = hAt(x0, z0);
    float h10 = hAt(x1, z0);
    float h01 = hAt(x0, z1);
    float h11 = hAt(x1, z1);

    float hx0 = h00 + (h10 - h00) * sx;
    float hx1 = h01 + (h11 - h01) * sx;
    float h = hx0 + (hx1 - hx0) * sz;
    return h;
}

bool TerrainManager::UploadVertices(const std::vector<D3D11RendererHelpers::TerrainVertex>& verts)
{
    if (!m_device || verts.empty())
        return false;

    D3D11_BUFFER_DESC vbd{};
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = static_cast<UINT>(verts.size() * sizeof(D3D11RendererHelpers::TerrainVertex));
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA vinit{};
    vinit.pSysMem = verts.data();
    return SUCCEEDED(m_device->CreateBuffer(&vbd, &vinit, &m_terrainPatchVertexBuffer));
}

bool TerrainManager::BuildFallbackPlane(float originX, float originZ, float worldSize)
{
    ClearResources();
    if (!m_device)
        return false;

    const float y = 0.0f;
    const float x0 = originX;
    const float z0 = originZ;
    const float x1 = originX + std::max(8.0f, worldSize);
    const float z1 = originZ + std::max(8.0f, worldSize);

    std::vector<D3D11RendererHelpers::TerrainVertex> verts;
    verts.reserve(6);
    const float nx = 0.0f, ny = 1.0f, nz = 0.0f;
    const float r = 0.35f, g = 0.45f, b = 0.35f, a = 1.0f;
    verts.push_back({ x0, y, z0, nx, ny, nz, r, g, b, a });
    verts.push_back({ x0, y, z1, nx, ny, nz, r, g, b, a });
    verts.push_back({ x1, y, z0, nx, ny, nz, r, g, b, a });
    verts.push_back({ x1, y, z0, nx, ny, nz, r, g, b, a });
    verts.push_back({ x0, y, z1, nx, ny, nz, r, g, b, a });
    verts.push_back({ x1, y, z1, nx, ny, nz, r, g, b, a });

    if (!UploadVertices(verts))
        return false;

    m_terrainPatchVertexCount = static_cast<UINT>(verts.size());
    m_terrainVertsX = 2;
    m_terrainVertsZ = 2;
    m_terrainCellSize = std::max(8.0f, worldSize);
    m_terrainOriginX = originX;
    m_terrainOriginZ = originZ;
    m_terrainHeights.assign(4, y);
    m_terrainAvailable = true;

    LOG_WARN("TerrainManager: using fallback terrain plane.");
    return true;
}

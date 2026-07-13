// ============================================================
// FILE: src/rendering/terrain/TerrainManager.h
// SYSTEM: Rendering / Geometry Generation
// ROLE: Manages world-scale geometry generation, height sampling, and vertex buffering for terrain patches.
// DEPENDS ON: D3D11RendererHelpers.hpp, DirectXMath.h
// ============================================================

#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <vector>
#include <string>
#include "D3D11RendererHelpers.hpp"
#include "D3D11Renderer.hpp"

class TerrainManager
{
public:
    TerrainManager();
    ~TerrainManager(); // Must implement cleanup!

    // Setup/Teardown
    bool Initialize(ID3D11Device* device, ID3D11DeviceContext* context);
    void Shutdown();
    void Tick(float deltaTime);
    bool Validate() const;
    void DebugDraw();

    // Core API Calls (The main interaction points)
    // Rebuilds the mesh for a specific area. Returns true on success.
    bool RebuildTerrainPatch(const D3D11Renderer::TerrainParams& params);

    // Sampling and Querying
    float SampleTerrainHeight(float worldX, float worldZ) const;
    bool IsTerrainAvailable() const { return m_terrainAvailable; }

    // GPU Resources Access
    ID3D11Buffer* GetVertexBuffer() const { return m_terrainPatchVertexBuffer; }
    UINT GetVertexCount() const { return m_terrainPatchVertexCount; }
    void ClearResources(); // Helper to release resources cleanly.
    bool BuildFallbackPlane(float originX, float originZ, float worldSize);


private:
    // --- Internal State (Moved from D3D11Renderer private section) ---

    // Height Grid Data (For fast CPU sampling)
    std::vector<float> m_terrainHeights;
    int m_terrainVertsX = 0;
    int m_terrainVertsZ = 0;
    float m_terrainCellSize = 1.0f;
    float m_terrainHalfSizeX = 0.0f;
    float m_terrainHalfSizeZ = 0.0f;
    float m_terrainOriginX = 0.0f;   // world-space X of terrain mesh start
    float m_terrainOriginZ = 0.0f;   // world-space Z of terrain mesh start
    bool m_terrainAvailable = false;

    // GPU Buffers
    ID3D11Device* m_device = nullptr;
    ID3D11DeviceContext* m_context = nullptr;
    ID3D11Buffer* m_terrainPatchVertexBuffer = nullptr;
    UINT m_terrainPatchVertexCount = 0;

    // Internal Helpers
    void SetupInternal(const D3D11Renderer::TerrainParams& params);
    bool UploadVertices(const std::vector<D3D11RendererHelpers::TerrainVertex>& verts);
};

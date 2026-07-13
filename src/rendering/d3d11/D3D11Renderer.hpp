// ============================================================
// FILE: src/rendering/d3d11/D3D11Renderer.hpp
// SYSTEM: Rendering
// ROLE: rendering GPU resources, shader flow, and draw submission
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: D3D11Renderer module behavior and local implementation details.
// ============================================================

#pragma once
// Suppress Windows min/max macros before including any Windows headers.
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <vector>
#include <string>
#include "D3D11RendererHelpers.hpp"
#include "RenderContracts.hpp"
#include "../../assets/TextureCache.hpp"

class TerrainManager; // Forward declaration for SetTerrainManager()

// A simple class for setting up and drawing with Direct3D 11.
class D3D11Renderer
{
public:
    enum class GraphicsPreset
    {
        Low,
        Medium,
        High,
        Ultra,
        Custom
    };

    enum class AntiAliasingMode
    {
        Off,
        FXAA,
        SMAA,
        TAA
    };

    // Parameters that drive biome-specific terrain generation.
    struct TerrainParams
    {
        std::string biome = "grassland"; // grassland | desert | rocky | snow
        int         seed = 12345;
        float       cellOriginX = 0.0f;  // world-space X of cell bottom-left corner
        float       cellOriginZ = 0.0f;  // world-space Z of cell bottom-left corner
        float       cellWorldSize = 400.0f; // cell side length in world units
        float       heightScale = 8.0f;
        float       noiseFreq = 0.08f;
        float       noiseFreq2 = 0.03f;
    };

    // Constructor / Destructor
    D3D11Renderer();
    ~D3D11Renderer();

    // Initialize & Shutdown
    bool Initialize(HWND windowHandle, int width, int height);
    void Shutdown();
    void Tick(float deltaTime);
    bool ValidateRenderState(const char* stage) const;
    void DebugDraw();

    // Screen Management
    void ClearScreen(float red, float green, float blue, float alpha);
    void PresentFrame();

    // Triangle Tests (for learning)
    void DrawRotatingTriangle(float deltaTime);

    // Sky Rendering
    void DrawSky();

    // Camera Control
    void SetCameraPosition(float x, float y, float z);
    void SetCameraRotation(float yaw, float pitch);
    void GetCameraPosition(float& x, float& y, float& z) const;
    void GetCameraRotation(float& yaw, float& pitch) const;

    // Lighting Control
    void SetSunDirection(float x, float y, float z);
    void GetSunDirection(float& x, float& y, float& z) const;
    float GetAmbientStrength() const;
    void SetAmbientStrength(float a);

    // Graphics Settings
    void SetVSyncEnabled(bool enabled);
    bool IsVSyncEnabled() const { return m_vsyncEnabled; }
    void SetFrameRateLimit(int fps);
    int GetFrameRateLimit() const { return m_frameRateLimit; }
    void ApplyGraphicsPreset(GraphicsPreset preset);
    GraphicsPreset GetGraphicsPreset() const { return m_graphicsPreset; }
    void SetAntiAliasingMode(AntiAliasingMode mode) { m_antiAliasingMode = mode; }
    AntiAliasingMode GetAntiAliasingMode() const { return m_antiAliasingMode; }

    // Terrain Rendering
    void DrawGroundPlane();
    void DrawTerrainPatch();
    void SetTerrainUnlitDebug(bool enabled) { m_debugTerrainUnlit = enabled; }
    void SetTerrainDisableCullingDebug(bool enabled) { m_debugTerrainDisableCulling = enabled; }
    void SetTerrainWireframeDebug(bool enabled) { m_debugTerrainWireframe = enabled; }
    bool IsTerrainUnlitDebugEnabled() const { return m_debugTerrainUnlit; }
    bool IsTerrainDisableCullingDebugEnabled() const { return m_debugTerrainDisableCulling; }
    bool IsTerrainWireframeDebugEnabled() const { return m_debugTerrainWireframe; }

    // Rebuild the terrain mesh from biome/seed parameters
    // (called on cell transition or F5).
    bool RebuildTerrainPatch(const TerrainParams& params);

    // Release the terrain mesh and mark terrain unavailable
    // (for cells with terrain.enabled=false).
    void ClearTerrainPatch();

    // Height Sampling (collision, raycasting)
    float SampleTerrainHeight(float worldX, float worldZ) const;
    bool IsTerrainAvailable() const;

    // Gravity & Jumping Control
    void SetCameraVelocityY(float velocity);
    float GetCameraVelocityY() const;
    void SetIsGrounded(bool grounded);
    bool GetIsGrounded() const;

    // GPU Access
    ID3D11Device* GetDevice() const { return device; }
    ID3D11DeviceContext* GetContext() const { return context; }
    ID3D11Buffer* GetLightConstantBuffer() const { return m_lightCBuffer; }
    int GetRenderWidth() const { return renderWidth; }
    int GetRenderHeight() const { return renderHeight; }

    // Texture Cache Attachment
    void SetTextureCache(TextureCache* cache) { m_textureCache = cache; }

    // Cel Shading
    bool IsCelShadingEnabled() const { return m_useCelShading; }
    float GetCelOutlineWidth() const { return m_celOutlineWidth; }
    bool SetCelShadingParameters(float count, float minVal, float maxVal,
        float rimAmount, float shadowR, float shadowG, float shadowB,
        float specThreshold);
    void DrawCharacterOutlinePass(float outlineThickness);

    // Terrain Manager Attachment
    void SetTerrainManager(TerrainManager* manager) { m_terrainManager = manager; }

private:
    // Resource creation helpers
    bool CreateTriangleResources();
    bool CreateRenderTarget();
    bool CreateTerrainPatch();
    bool CreateGroundPlaneGeometry();
    bool CreateSceneConstantBuffers();
    bool CreateFallbackResources();
    bool CreateTerrainRasterizerStates();
    void CreateGroundShaders();
    void CreateSkyShaders();
    void SetupGroundAndTerrainSceneConstants(float farPlane);
    void UploadLightConstants();

    // Simple vertex for the test triangle (POSITION + COLOR).
    // Matches triangle_vs.hlsl input signature.
    struct SimpleVertex
    {
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT4 color;
    };

    // Camera State
    float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 0.0f;
    float cameraYaw = 0.0f, cameraPitch = 0.0f;
    float cameraVelocityY = 0.0f; // Vertical velocity for jumping and gravity
    bool  isGrounded = false;     // Whether the camera is on the ground

    // Render Settings
    int   renderWidth  = 800;
    int   renderHeight = 600;
    int   m_shadowResolution   = 1024;
    float m_lodDistanceScale   = 1.0f;
    float m_particleDensity    = 0.65f;
    int   m_textureQualityLevel = 1;

    // Graphics Preset
    GraphicsPreset   m_graphicsPreset   = GraphicsPreset::Medium;
    AntiAliasingMode m_antiAliasingMode = AntiAliasingMode::FXAA;
    bool             m_vsyncEnabled     = true;
    int              m_frameRateLimit   = 60;

    // Terrain State (Renderer-owned for simplicity)
    std::vector<float> m_terrainHeights; // row-major [z * vertsX + x]
    int   m_terrainVertsX    = 0;
    int   m_terrainVertsZ    = 0;
    float m_terrainCellSize  = 1.0f;
    float m_terrainHalfSizeX = 0.0f;
    float m_terrainHalfSizeZ = 0.0f;
    float m_terrainOriginX   = 0.0f; // world-space X of terrain mesh start
    float m_terrainOriginZ   = 0.0f; // world-space Z of terrain mesh start
    bool  m_terrainAvailable = false;

    // Active Biome
    std::string m_activeTerrainBiome = "grassland";

    // Shader Resources (test triangle)
    ID3D11VertexShader* vertexShader = nullptr;
    ID3D11PixelShader*  pixelShader  = nullptr;
    ID3D11InputLayout*  inputLayout  = nullptr;
    ID3D11Buffer*       vertexBuffer = nullptr;
    UINT m_triangleVertexCount = 0;

    // Sky Shaders (vertex shader uses SV_VertexID — no input layout needed)
    ID3D11VertexShader* skyVertexShader = nullptr;
    ID3D11PixelShader*  skyPixelShader  = nullptr;
    ID3D11InputLayout*  skyInputLayout  = nullptr; // reserved, not used

    // Ground/Terrain Shaders
    ID3D11VertexShader* groundVertexShader = nullptr;
    ID3D11PixelShader*  groundPixelShader  = nullptr;
    ID3D11InputLayout*  groundInputLayout  = nullptr;

    // GPU Buffers
    ID3D11Buffer* m_groundVertexBuffer       = nullptr;
    ID3D11Buffer* m_groundIndexBuffer        = nullptr;
    UINT          m_groundIndexCount         = 0;
    ID3D11Buffer* m_lightCBuffer             = nullptr;
    ID3D11Buffer* m_constantBuffer           = nullptr;
    ID3D11Buffer* m_terrainPatchVertexBuffer = nullptr;
    UINT          m_terrainPatchVertexCount  = 0;

    // Light state (sun direction + ambient)
    RenderContracts::LightCBuffer m_lightData = RenderContracts::DefaultDirectionalLight();

    // Cel Shading state
    bool  m_useCelShading   = false;
    float m_celOutlineWidth = 1.0f;

    // Device & SwapChain
    ID3D11Device*           device           = nullptr;
    ID3D11DeviceContext*    context          = nullptr;
    IDXGISwapChain*         swapChain        = nullptr;
    ID3D11RenderTargetView* renderTargetView = nullptr;
    D3D_FEATURE_LEVEL       featureLevel     = D3D_FEATURE_LEVEL_9_1;
    ID3D11Texture2D*        depthTexture     = nullptr;
    ID3D11DepthStencilView* depthView        = nullptr;

    // Sampling & Texture Handling
    TextureCache*       m_textureCache   = nullptr;
    ID3D11SamplerState* m_textureSampler = nullptr;
    ID3D11ShaderResourceView* m_fallbackWhiteTexture = nullptr;

    ID3D11RasterizerState* m_terrainSolidRasterState = nullptr;
    ID3D11RasterizerState* m_terrainNoCullRasterState = nullptr;
    ID3D11RasterizerState* m_terrainWireRasterState = nullptr;
    bool m_debugTerrainUnlit = false;
    bool m_debugTerrainDisableCulling = false;
    bool m_debugTerrainWireframe = false;
    bool m_loggedMissingTerrainWarning = false;

    // Terrain Manager - Pointer to manager instance
    TerrainManager* m_terrainManager = nullptr;
};

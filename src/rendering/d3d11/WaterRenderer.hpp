// ============================================================
// FILE: src/rendering/d3d11/WaterRenderer.hpp
// SYSTEM: Rendering / Water
// ROLE: Renders all water bodies in the scene using water_vs.hlsl + water_ps.hlsl.
//   Manages a flat grid vertex buffer representing the water plane,
//   WaterParams constant buffer, and alpha-blended draw calls.
//
// INTEGRATION POINTS:
//   - D3D11Renderer calls WaterRenderer::Draw() after DrawTerrainPatch().
//   - WeatherSystem::GetWindStrength() drives waterWave1Speed scaling.
//   - DayNightCycle::GetNormalizedTime() can tint water reflection color.
//   - WorldGrid::GetActiveCells() provides waterLevel per biome/cell.
//
// WATER BODY AUTHORING:
//   Water bodies are defined per WorldCell in the cell JSON:
//     "water": { "enabled": true, "level": 2.5, "extentX": 200, "extentZ": 200 }
//   WaterRenderer reads these from the active WorldCell and creates/updates
//   the plane accordingly. One water plane per scene (for now).
//
// VISUAL APPROACH (see water_ps.hlsl for full details):
//   - Flat grid mesh with VS wave displacement.
//   - Fresnel-based reflection/transparency blend.
//   - Optional normal map for surface ripple detail.
//   - Alpha blending: objects below the water level show through.
//   - No real-time planar reflections on GT610 (too expensive).
//
// RENDER ORDER:
//   1. DrawSky()              (D3D11Renderer)
//   2. DrawTerrainPatch()     (D3D11Renderer)
//   3. WaterRenderer::Draw()  ← HERE (alpha blend, depth test ON, depth write OFF)
//   4. DrawActors()/DrawTrees()
//
// HARDWARE TARGET: GT610. Water mesh: 32x32 quads = 2048 tris = 6144 verts.
//   One draw call per frame. Alpha blend state + no depth write.
//
// FOR QWEN: Implement Initialize(), Rebuild(), Draw(), Shutdown() in WaterRenderer.cpp.
// ============================================================

#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <string>

// ============================================================
// WaterBodyParams
// Per-cell water body definition (parsed from cell JSON or set by code).
// ============================================================
struct WaterBodyParams
{
    bool   enabled     = false;
    float  level       = 0.0f;    // World Y position of the water surface
    float  extentX     = 200.0f;  // Size of the water plane in X (world units)
    float  extentZ     = 200.0f;  // Size of the water plane in Z (world units)
    float  originX     = 0.0f;    // World X of the water plane's bottom-left corner
    float  originZ     = 0.0f;    // World Z of the water plane's bottom-left corner
    int    gridResolution = 32;   // Quads per side. 32 is the GT610 budget sweet spot.

    // Visual overrides (if not set, defaults from WaterRenderer are used)
    float tintR = 0.10f, tintG = 0.45f, tintB = 0.65f, tintA = 0.80f;
};


// ============================================================
// WaterRenderer
// ============================================================
class WaterRenderer
{
public:
    WaterRenderer();
    ~WaterRenderer();

    // --------------------------------------------------------
    // Initialize
    // Compiles water shaders, creates blend state, creates default water plane.
    //   device, context: from D3D11Renderer.
    //
    // TODO (Qwen): Implement in WaterRenderer.cpp:
    //   1. Compile water_vs.hlsl → m_waterVS + create m_waterInputLayout.
    //      Input layout: POSITION (float3), NORMAL (float3), COLOR (float4), TEXCOORD0 (float2).
    //   2. Compile water_ps.hlsl → m_waterPS.
    //   3. Create m_waterParamsCB (WaterParamsCBLayout struct, 48 bytes, DYNAMIC).
    //   4. Create m_waterVisualCB (WaterVisualCBLayout struct, 48 bytes, DYNAMIC).
    //   5. Create m_alphaBlendState:
    //      D3D11_BLEND_DESC blendDesc = {};
    //      blendDesc.RenderTarget[0].BlendEnable = TRUE;
    //      blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    //      blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    //      blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    //      (set color write mask to D3D11_COLOR_WRITE_ENABLE_ALL)
    //   6. Create m_depthStencilNoWrite (depth test ON, depth write OFF for alpha blend).
    //   7. Create linear wrap sampler for normal map.
    // --------------------------------------------------------
    bool Initialize(ID3D11Device* device, ID3D11DeviceContext* context);

    // --------------------------------------------------------
    // Shutdown — release all owned GPU resources.
    // --------------------------------------------------------
    void Shutdown();

    // --------------------------------------------------------
    // Rebuild
    // Creates or recreates the water grid vertex buffer.
    // Call when the active cell changes or water params change.
    //
    // Vertex layout matches water_vs.hlsl VSIn:
    //   POSITION: flat grid XZ positions (Y=0 in object space, lifted to waterLevel in VS).
    //   NORMAL: (0,1,0) for all verts (VS computes wave normal analytically).
    //   COLOR: tint color from WaterBodyParams.
    //   TEXCOORD0: UV in [0,1] across the grid.
    //
    // Grid generation (for Qwen):
    //   for z = 0..gridRes, x = 0..gridRes:
    //     posX = originX + x * (extentX / gridRes)
    //     posZ = originZ + z * (extentZ / gridRes)
    //     uvX = x / gridRes, uvZ = z / gridRes
    //   Triangle winding: CCW for D3D11 default front-face.
    //   Use index buffer (UINT16, gridRes^2 * 6 indices) or unindexed quads.
    //
    // TODO (Qwen): implement index buffer generation and vertex buffer upload.
    // --------------------------------------------------------
    bool Rebuild(const WaterBodyParams& params);

    // --------------------------------------------------------
    // Draw
    // Draws the water plane for the current frame.
    //   dt: frame delta time (for wave animation accumulation)
    //   mvpMatrix, worldMatrix: passed from D3D11Renderer camera state
    //   windStrength: from WeatherSystem::GetWindStrength() [0,1]
    //   weatherRainIntensity: from WeatherSystem::GetRainIntensity() [0,1]
    //     (higher rain = choppier waves: scale wave amplitudes)
    //
    // Draw pipeline:
    //   1. Update m_waterTime += dt * timeScale.
    //   2. Upload WaterParamsCBLayout to m_waterParamsCB.
    //   3. Upload WaterVisualCBLayout to m_waterVisualCB.
    //   4. Set alpha blend state + depth no-write state.
    //   5. Bind VS + PS + cbuffers + vertex buffer + index buffer.
    //   6. DrawIndexed(m_indexCount, 0, 0).
    //   7. Restore depth write state after draw.
    //
    // TODO (Qwen): implement full draw sequence.
    // --------------------------------------------------------
    void Draw(float dt,
              const DirectX::XMFLOAT4X4& mvpMatrix,
              const DirectX::XMFLOAT4X4& worldMatrix,
              float windStrength,
              float weatherRainIntensity);

    // --------------------------------------------------------
    // SetEnabled / IsEnabled
    // Guards Draw() when no water body is in the active cell.
    // --------------------------------------------------------
    void SetEnabled(bool enabled) { m_enabled = enabled; }
    bool IsEnabled() const        { return m_enabled; }

    // --------------------------------------------------------
    // GetWaterLevel
    // Returns the Y position of the current water surface.
    // Used by character controller to check if player is submerged.
    // --------------------------------------------------------
    float GetWaterLevel() const { return m_params.level; }

    // --------------------------------------------------------
    // IsPointSubmerged
    // Returns true if worldPos.y < waterLevel. Used by swimming controller.
    // --------------------------------------------------------
    bool IsPointSubmerged(const DirectX::XMFLOAT3& worldPos) const
    {
        return m_enabled && worldPos.y < m_params.level;
    }

private:
    // --------------------------------------------------------
    // INTERNAL CBUFFER STRUCTS (must match shader layouts exactly)
    // --------------------------------------------------------

    // Matches WaterParams cbuffer in water_vs.hlsl (slot b3)
    struct WaterParamsCBLayout
    {
        float waterTime;
        float waterWave1Amp;
        float waterWave1Freq;
        float waterWave1Speed;
        float waterWave2Amp;
        float waterWave2Freq;
        float waterWave2Speed;
        float waterLevel;
        float _pad[4]; // 48 bytes total (multiple of 16)
    };
    static_assert(sizeof(WaterParamsCBLayout) % 16 == 0, "WaterParamsCBLayout must be 16-byte aligned");

    // Matches WaterVisualParams cbuffer in water_ps.hlsl (slot b4)
    struct WaterVisualCBLayout
    {
        float waterDeepColor[3];    float waterDepthScale;
        float waterShallowColor[3]; float waterTransparency;
        float waterReflectColor[3]; float waterFresnelPower;
        float waterSpecPower;       float waterSpecStrength;
        float _pad[2]; // 64 bytes total
    };
    static_assert(sizeof(WaterVisualCBLayout) % 16 == 0, "WaterVisualCBLayout must be 16-byte aligned");


    // --------------------------------------------------------
    // STATE
    // --------------------------------------------------------

    ID3D11Device*        m_device  = nullptr;
    ID3D11DeviceContext* m_context = nullptr;

    // Shaders
    ID3D11VertexShader* m_waterVS      = nullptr;
    ID3D11PixelShader*  m_waterPS      = nullptr;
    ID3D11InputLayout*  m_waterLayout  = nullptr;

    // Water grid geometry
    ID3D11Buffer* m_vertexBuffer = nullptr;
    ID3D11Buffer* m_indexBuffer  = nullptr;
    UINT          m_indexCount   = 0;

    // Constant buffers
    ID3D11Buffer* m_waterParamsCB  = nullptr; // Slot b3 — wave animation params
    ID3D11Buffer* m_waterVisualCB  = nullptr; // Slot b4 — visual appearance

    // Render states
    ID3D11BlendState*        m_alphaBlendState    = nullptr; // SrcAlpha / InvSrcAlpha
    ID3D11DepthStencilState* m_depthNoWrite        = nullptr; // Depth test ON, write OFF

    // Texture resources (optional — loaded on Medium+)
    ID3D11Texture2D*          m_normalMapTexture = nullptr;
    ID3D11ShaderResourceView* m_normalMapSRV     = nullptr;
    ID3D11SamplerState*       m_wrapSampler      = nullptr;

    // Animated state
    float            m_waterTime = 0.0f; // Accumulated time for wave animation
    bool             m_enabled   = false;
    WaterBodyParams  m_params;           // Current water body configuration
};

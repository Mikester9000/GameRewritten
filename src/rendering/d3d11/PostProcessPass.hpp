// ============================================================
// FILE: src/rendering/d3d11/PostProcessPass.hpp
// SYSTEM: Rendering / Post-Process
// ROLE: Manages all fullscreen post-process passes applied after the
//   main scene render but before SwapChain::Present().
//   Currently manages: LUT color grading, atmospheric fog.
//   Future: bloom (Medium+ only), chromatic aberration (High only).
//
// PIPELINE POSITION:
//   D3D11Renderer::PresentFrame() calls ApplyAll() before Present().
//   ApplyAll() runs only enabled passes in order:
//     1. Fog pass (fog_ps.hlsl)   — depth-aware fog
//     2. LUT pass (lut_ps.hlsl)   — color grading
//   (Bloom is deferred until a GT610 budget analysis is done.)
//
// RENDER TARGET SETUP (for Qwen to implement):
//   Post-process requires rendering the main scene to a texture (not the
//   backbuffer), then running fullscreen passes on that texture.
//   D3D11 resources needed:
//     ID3D11Texture2D*        m_sceneTexture     — intermediate RGBA render target
//     ID3D11RenderTargetView* m_sceneRTV          — RTV for drawing the main scene
//     ID3D11ShaderResourceView* m_sceneSRV        — SRV for reading in post-process PS
//     ID3D11Texture2D*        m_depthCopy         — R32_FLOAT copy of depth buffer
//     ID3D11ShaderResourceView* m_depthSRV        — SRV for fog pass
//   These must be created in Initialize() and freed in Shutdown().
//
// FULLSCREEN QUAD:
//   No vertex buffer needed — use SV_VertexID trick (same as sky_vs.hlsl):
//     Vertex 0: (-1,-1) UV(0,1)
//     Vertex 1: ( 3,-1) UV(2,1)
//     Vertex 2: (-1, 3) UV(0,-1)
//   This covers the entire screen with 3 vertices. Draw with DrawIndexed or Draw(3).
//
// HARDWARE TARGET: GT610. Intermediate RTs add VRAM cost.
//   At 800x600 RGBA8: 1.83 MB per texture. With depth copy: ~5.5 MB total.
//   Acceptable within 512 MB budget.
//
// FOR QWEN: Implement Initialize(), ApplyAll(), and per-pass Apply functions.
// ============================================================

#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <d3d11.h>
#include <string>

// Forward declarations
class D3D11Renderer;

// ============================================================
// PostProcessSettings
// Serializable settings controlling which passes are active.
// Driven by ApplyGraphicsPreset() in D3D11Renderer.
// ============================================================
struct PostProcessSettings
{
    // LUT color grading (Shaders/lut_ps.hlsl)
    bool  lutEnabled         = false; // Enabled on Medium and above
    float lutIntensity       = 1.0f;  // [0,1] blend from scene to LUT output
    float lutBrightness      = 0.0f;  // [-0.5, 0.5] brightness offset
    float lutContrast        = 1.0f;  // [0.5, 2.0] contrast scale
    float lutSaturation      = 1.0f;  // [0, 2] saturation (1=unchanged)
    std::string lutFilePath;          // Path to .png LUT strip or 3D LUT texture

    // Atmospheric fog (Shaders/fog_ps.hlsl)
    bool  fogEnabled         = false; // Enabled on Medium and above; Low uses per-vertex fog
    float fogDensity         = 0.003f;
    float fogNearPlane       = 0.1f;
    float fogFarPlane        = 1000.0f;
    float fogHeightFalloff   = 0.5f;
    float fogMaxHeight       = 50.0f;
};


// ============================================================
// PostProcessPass
// Owns GPU resources for the post-process pipeline and executes passes.
// ============================================================
class PostProcessPass
{
public:
    PostProcessPass();
    ~PostProcessPass();

    // --------------------------------------------------------
    // Initialize
    // Creates all intermediate render targets, shaders, and cbuffers.
    //   device, context: D3D11 device from D3D11Renderer::GetDevice().
    //   width, height: current render resolution.
    //
    // TODO (Qwen): Implement in PostProcessPass.cpp:
    //   1. Create m_sceneTexture (DXGI_FORMAT_R8G8B8A8_UNORM) + RTV + SRV.
    //   2. Create m_depthCopy (DXGI_FORMAT_R32_FLOAT) + RTV + SRV.
    //   3. Compile fog_ps.hlsl → m_fogPS.
    //   4. Compile lut_ps.hlsl → m_lutPS.
    //   5. Compile a shared fullscreen quad VS (postprocess_vs.hlsl or reuse sky_vs).
    //   6. Create m_fogCBuffer (FogParams struct — matches fog_ps.hlsl cbuffer).
    //   7. Create m_lutCBuffer (ColorGradingParams struct).
    //   8. Load LUT texture from settings.lutFilePath if specified.
    // --------------------------------------------------------
    bool Initialize(ID3D11Device* device, ID3D11DeviceContext* context,
                    int width, int height, const PostProcessSettings& settings);

    // --------------------------------------------------------
    // Shutdown — releases all owned GPU resources.
    // TODO (Qwen): Release all ID3D11* members using SafeRelease pattern.
    // --------------------------------------------------------
    void Shutdown();

    // --------------------------------------------------------
    // BeginScene
    // Call at the START of each frame before drawing anything.
    // Redirects rendering output from backbuffer to m_sceneRTV so the
    // main scene is captured for post-process.
    //
    // TODO (Qwen): Implement:
    //   context->OMSetRenderTargets(1, &m_sceneRTV, depthView);
    //   context->ClearRenderTargetView(m_sceneRTV, clearColor);
    // --------------------------------------------------------
    void BeginScene(ID3D11RenderTargetView* backbuffer,
                    ID3D11DepthStencilView* depthView);

    // --------------------------------------------------------
    // ApplyAll
    // Call AFTER the scene is drawn (just before Present()).
    // Restores output to backbuffer and runs all enabled passes in order.
    //
    // Pass order (must be this exact sequence):
    //   1. CopyDepth() — blit depth buffer to m_depthCopy for fog_ps.
    //   2. ApplyFog()  — reads m_sceneSRV + m_depthSRV, writes intermediate.
    //   3. ApplyLUT()  — reads fog output, writes to backbuffer.
    //
    // TODO (Qwen): Implement in PostProcessPass.cpp.
    //   For each pass: bind SRVs, upload cbuffer, set VS/PS, Draw(3).
    //   Between passes: swap intermediate RTs if needed.
    // --------------------------------------------------------
    void ApplyAll(ID3D11RenderTargetView* backbuffer,
                  ID3D11DepthStencilView* depthView);

    // --------------------------------------------------------
    // UpdateSettings
    // Hot-reload settings without reinitializing GPU resources.
    // Called by D3D11Renderer::ApplyGraphicsPreset().
    // --------------------------------------------------------
    void UpdateSettings(const PostProcessSettings& settings);

    // --------------------------------------------------------
    // GetSceneRTV / GetSceneSRV
    // Expose the scene render target for D3D11Renderer to bind.
    // --------------------------------------------------------
    ID3D11RenderTargetView*   GetSceneRTV() const { return m_sceneRTV; }
    ID3D11ShaderResourceView* GetSceneSRV() const { return m_sceneSRV; }

private:
    // --------------------------------------------------------
    // Per-pass helpers (each runs one fullscreen draw call)
    // --------------------------------------------------------

    // ApplyFog: binds fog cbuffer + scene/depth SRVs, runs fog_ps.hlsl
    // TODO (Qwen): Upload FogParams cbuffer from m_settings.fog*.
    void ApplyFog(ID3D11ShaderResourceView* inputSRV,
                  ID3D11RenderTargetView* outputRTV);

    // ApplyLUT: binds lut cbuffer + input SRV, runs lut_ps.hlsl
    // TODO (Qwen): Upload ColorGradingParams from m_settings.lut*.
    void ApplyLUT(ID3D11ShaderResourceView* inputSRV,
                  ID3D11RenderTargetView* outputRTV);

    // CopyDepth: copies depth buffer to m_depthCopy texture via CopyResource or draw call
    // NOTE: D3D11 does not allow CopyResource between DSV and SRV-format textures directly.
    //   Use a minimal depth-resolve PS or ResolveSubresource if formats match.
    // TODO (Qwen): implement simplest working copy approach.
    void CopyDepth(ID3D11DepthStencilView* depthView);

    // DrawFullscreenQuad: Draw(3) with SV_VertexID fullscreen triangle trick
    void DrawFullscreenQuad();

    // D3D11 device references (non-owning — owned by D3D11Renderer)
    ID3D11Device*        m_device  = nullptr;
    ID3D11DeviceContext* m_context = nullptr;

    // Intermediate render targets
    // m_sceneTexture: main scene captured here each frame
    ID3D11Texture2D*          m_sceneTexture = nullptr;
    ID3D11RenderTargetView*   m_sceneRTV     = nullptr;
    ID3D11ShaderResourceView* m_sceneSRV     = nullptr;

    // m_pingPong: used as intermediate between fog and LUT passes
    ID3D11Texture2D*          m_pingPong     = nullptr;
    ID3D11RenderTargetView*   m_pingPongRTV  = nullptr;
    ID3D11ShaderResourceView* m_pingPongSRV  = nullptr;

    // m_depthCopy: R32_FLOAT copy of scene depth for fog_ps
    ID3D11Texture2D*          m_depthCopy    = nullptr;
    ID3D11RenderTargetView*   m_depthCopyRTV = nullptr;
    ID3D11ShaderResourceView* m_depthSRV     = nullptr;

    // Shaders
    ID3D11VertexShader* m_fullscreenVS = nullptr; // SV_VertexID fullscreen quad VS
    ID3D11PixelShader*  m_fogPS        = nullptr; // fog_ps.hlsl
    ID3D11PixelShader*  m_lutPS        = nullptr; // lut_ps.hlsl

    // Constant buffers
    ID3D11Buffer* m_fogCBuffer = nullptr; // FogParams (matches fog_ps cbuffer b5)
    ID3D11Buffer* m_lutCBuffer = nullptr; // ColorGradingParams (matches lut_ps cbuffer b4)

    // LUT texture (3D, 16x16x16, loaded once)
    ID3D11Texture3D*          m_lutTexture3D = nullptr;
    ID3D11ShaderResourceView* m_lutSRV       = nullptr;

    // Sampler states
    ID3D11SamplerState* m_linearSampler = nullptr; // Linear clamp
    ID3D11SamplerState* m_lutSampler    = nullptr; // Linear clamp for LUT

    // Render resolution (for RT creation)
    int m_width  = 800;
    int m_height = 600;

    // Current settings
    PostProcessSettings m_settings;

    // Stored backbuffer RTV so BeginScene can restore it in ApplyAll
    ID3D11RenderTargetView* m_backbufferRTV = nullptr;
};

// ============================================================
// FILE: src/rendering/d3d11/PostProcessPass.cpp
// SYSTEM: Rendering / Post-Process
// ROLE: Implements PostProcessPass — fullscreen LUT color grading and
//   atmospheric fog passes applied after main scene render.
//
// IMPLEMENTATION GUIDE FOR QWEN:
//   Read PostProcessPass.hpp first for full architecture documentation.
//   Implement each TODO in the order listed below:
//     1. Initialize()     — create all GPU resources
//     2. BeginScene()     — redirect render output to scene RT
//     3. CopyDepth()      — copy depth buffer to SRV-readable texture
//     4. ApplyFog()       — run fog_ps.hlsl fullscreen pass
//     5. ApplyLUT()       — run lut_ps.hlsl fullscreen pass
//     6. ApplyAll()       — orchestrate the sequence
//     7. Shutdown()       — release all GPU resources
//
// KEY D3D11 PATTERNS USED HERE:
//   - CreateTexture2D + CreateRenderTargetView + CreateShaderResourceView
//     (every intermediate RT needs all three objects)
//   - D3D11ShaderCompiler::CompileFromFile() to load HLSL from disk
//   - Draw(3) with a fullscreen VS that uses SV_VertexID (no vertex buffer)
//   - OMSetRenderTargets() to switch between RTs between passes
//   - PSSetShaderResources() to bind SRVs for reading in PS
//   - UpdateSubresource() or Map/Unmap for cbuffer uploads
//
// CBUFFER LAYOUT RULE: Every cbuffer must be a multiple of 16 bytes.
//   Add padding floats or float4 as needed. Use static_assert to verify.
// ============================================================

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "PostProcessPass.hpp"
#include "D3D11ShaderCompiler.hpp"
#include "../../logger/Logger.hpp"
#include <algorithm>

// Safe release helper (matches D3D11Renderer.cpp pattern)
template<typename T>
static void SafeRelease(T*& ptr) { if (ptr) { ptr->Release(); ptr = nullptr; } }


// ============================================================
// FogParamsCB — must match fog_ps.hlsl cbuffer FogParams layout EXACTLY.
// Any change to fog_ps.hlsl cbuffer requires matching change here.
// ============================================================
struct FogParamsCB
{
    float fogColor[3];         // RGB fog color
    float fogDensity;          // Exponential squared density coefficient
    float fogNearPlane;        // Camera near clip plane
    float fogFarPlane;         // Camera far clip plane
    float fogHeightFalloff;    // Height falloff factor [0,1]
    float fogMaxHeight;        // Y above which fog = 0
    float fogWeatherIntensity; // Weather-driven scale [0,1]
    float _pad[3];             // 16-byte alignment — fog cbuffer = 48 bytes
};
static_assert(sizeof(FogParamsCB) % 16 == 0, "FogParamsCB must be 16-byte aligned");


// ============================================================
// LutParamsCB — must match fog_ps.hlsl (ColorGradingParams at b4).
// ============================================================
struct LutParamsCB
{
    float intensity;   // LUT blend [0,1]
    float brightness;  // Brightness offset [-0.5, 0.5]
    float contrast;    // Contrast scale [0.5, 2.0]
    float saturation;  // Saturation [0, 2]
    // Total: 16 bytes — matches ColorGradingHeader.hlsl lutParams float4
};
static_assert(sizeof(LutParamsCB) % 16 == 0, "LutParamsCB must be 16-byte aligned");


// ============================================================
// CONSTRUCTOR / DESTRUCTOR
// ============================================================

PostProcessPass::PostProcessPass() = default;

PostProcessPass::~PostProcessPass()
{
    Shutdown();
}


// ============================================================
// Initialize
// Creates all GPU resources for the post-process pipeline.
//
// TODO (Qwen): Implement each step below. The struct definitions and
//   D3D11 API calls follow the exact same pattern as D3D11Renderer::Initialize().
//   Reference: D3D11Renderer.cpp CreateTerrainPatch() for buffer patterns.
// ============================================================
bool PostProcessPass::Initialize(ID3D11Device* device, ID3D11DeviceContext* context,
                                  int width, int height, const PostProcessSettings& settings)
{
    m_device  = device;
    m_context = context;
    m_width   = width;
    m_height  = height;
    m_settings = settings;

    // --------------------------------------------------------
    // Step 1: Create intermediate scene render target
    // Used as the render destination during main scene draw.
    // After scene is drawn here, it becomes the input SRV for post passes.
    //
    // TODO (Qwen): Create m_sceneTexture:
    //   D3D11_TEXTURE2D_DESC desc = {};
    //   desc.Width = width; desc.Height = height;
    //   desc.MipLevels = 1; desc.ArraySize = 1;
    //   desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    //   desc.SampleDesc = { 1, 0 };
    //   desc.Usage = D3D11_USAGE_DEFAULT;
    //   desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    //   device->CreateTexture2D(&desc, nullptr, &m_sceneTexture);
    //   device->CreateRenderTargetView(m_sceneTexture, nullptr, &m_sceneRTV);
    //   device->CreateShaderResourceView(m_sceneTexture, nullptr, &m_sceneSRV);
    // --------------------------------------------------------

    // --------------------------------------------------------
    // Step 2: Create ping-pong intermediate RT (same desc as scene texture)
    // Used to pass output of one pass into the next pass as SRV input.
    // Fog writes to ping-pong, LUT reads ping-pong and writes to backbuffer.
    //
    // TODO (Qwen): Create m_pingPong / m_pingPongRTV / m_pingPongSRV.
    //   Same code as Step 1 but for m_pingPong members.
    // --------------------------------------------------------

    // --------------------------------------------------------
    // Step 3: Create depth copy texture (R32_FLOAT) for fog_ps depth reading
    // The depth buffer (DSV) cannot be bound as SRV simultaneously.
    // We copy depth to this R32_FLOAT texture each frame before fog pass.
    //
    // TODO (Qwen): Create m_depthCopy:
    //   desc.Format = DXGI_FORMAT_R32_FLOAT;
    //   desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    //   device->CreateTexture2D(&desc, nullptr, &m_depthCopy);
    //   device->CreateRenderTargetView(m_depthCopy, nullptr, &m_depthCopyRTV);
    //   device->CreateShaderResourceView(m_depthCopy, nullptr, &m_depthSRV);
    // --------------------------------------------------------

    // --------------------------------------------------------
    // Step 4: Compile shaders
    //
    // TODO (Qwen): compile fog_ps.hlsl and lut_ps.hlsl using D3D11ShaderCompiler.
    //   D3D11ShaderCompiler compiler;
    //   compiler.CompileFromFile(L"Shaders/fog_ps.hlsl",  "main", "ps_4_0", &psBlob);
    //   device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_fogPS);
    //   (same for lut_ps.hlsl → m_lutPS)
    //
    // Also compile a fullscreen vertex shader (SV_VertexID trick).
    // You can reuse sky_vs.hlsl if its entry point outputs SV_POSITION + TEXCOORD0.
    // Or create a minimal dedicated postprocess_vs.hlsl with 3 hardcoded vertices.
    // --------------------------------------------------------

    // --------------------------------------------------------
    // Step 5: Create constant buffers
    //
    // TODO (Qwen): Create m_fogCBuffer and m_lutCBuffer:
    //   D3D11_BUFFER_DESC cbd = {};
    //   cbd.ByteWidth = sizeof(FogParamsCB);
    //   cbd.Usage = D3D11_USAGE_DYNAMIC;
    //   cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    //   cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    //   device->CreateBuffer(&cbd, nullptr, &m_fogCBuffer);
    //   (same for LutParamsCB → m_lutCBuffer)
    // --------------------------------------------------------

    // --------------------------------------------------------
    // Step 6: Create samplers
    //
    // TODO (Qwen): Create linear clamp sampler for scene and LUT:
    //   D3D11_SAMPLER_DESC sd = {};
    //   sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    //   sd.AddressU = sd.AddressV = sd.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    //   device->CreateSamplerState(&sd, &m_linearSampler);
    //   (same for m_lutSampler)
    // --------------------------------------------------------

    LOG_INFO("PostProcessPass: initialized (STUB — GPU resources not yet created)");
    return true; // TODO: return false if any D3D11 call fails
}


// ============================================================
// Shutdown — release all GPU resources in reverse creation order
// ============================================================
void PostProcessPass::Shutdown()
{
    // TODO (Qwen): SafeRelease all members in creation-reverse order:
    SafeRelease(m_lutSampler);
    SafeRelease(m_linearSampler);
    SafeRelease(m_lutCBuffer);
    SafeRelease(m_fogCBuffer);
    SafeRelease(m_lutPS);
    SafeRelease(m_fogPS);
    SafeRelease(m_fullscreenVS);
    SafeRelease(m_depthSRV);
    SafeRelease(m_depthCopyRTV);
    SafeRelease(m_depthCopy);
    SafeRelease(m_pingPongSRV);
    SafeRelease(m_pingPongRTV);
    SafeRelease(m_pingPong);
    SafeRelease(m_sceneSRV);
    SafeRelease(m_sceneRTV);
    SafeRelease(m_sceneTexture);
    SafeRelease(m_lutSRV);
    SafeRelease(m_lutTexture3D);
}


// ============================================================
// BeginScene
// Redirects rendering from backbuffer to the intermediate scene texture.
// Call this at the START of each frame (before ClearScreen).
// ============================================================
void PostProcessPass::BeginScene(ID3D11RenderTargetView* backbuffer,
                                  ID3D11DepthStencilView* depthView)
{
    m_backbufferRTV = backbuffer;

    // TODO (Qwen): if post-process is enabled, redirect to m_sceneRTV:
    // if (m_settings.lutEnabled || m_settings.fogEnabled)
    //     m_context->OMSetRenderTargets(1, &m_sceneRTV, depthView);
    // else
    //     m_context->OMSetRenderTargets(1, &backbuffer, depthView);
    (void)backbuffer; // suppress unused warning in stub
    (void)depthView;
}


// ============================================================
// CopyDepth
// Copies the scene depth buffer into m_depthCopy (R32_FLOAT SRV).
// This must run before ApplyFog() so fog_ps can read depth.
//
// TODO (Qwen): Implement one of these approaches:
//   A) If depth texture was created with matching compatible format:
//      m_context->CopyResource(m_depthCopy, depthTexture);
//   B) Draw a fullscreen quad with a depth-encode PS that reads the DSV
//      via a specially formatted SRV created from the depth texture.
//   Approach B is more flexible but requires an extra compile step.
//   Start with approach A if formats are compatible.
// ============================================================
void PostProcessPass::CopyDepth(ID3D11DepthStencilView* depthView)
{
    // STUB: depth copy not yet implemented
    (void)depthView;
}


// ============================================================
// ApplyFog
// Runs a single fullscreen pass using fog_ps.hlsl.
//   inputSRV: the scene (or previous pass output) texture to read
//   outputRTV: where to write fog result (ping-pong or backbuffer)
//
// TODO (Qwen): Implement:
//   1. Restore render target to outputRTV (no depth write).
//   2. Unbind any DSV (set to nullptr).
//   3. Upload FogParamsCB to m_fogCBuffer.
//   4. Bind: m_context->PSSetConstantBuffers(5, 1, &m_fogCBuffer);
//   5. Bind inputSRV at t0, m_depthSRV at t1.
//   6. Set shaders: fullscreenVS + fogPS.
//   7. Set null input layout (SV_VertexID needs none).
//   8. Call DrawFullscreenQuad().
//   9. Unbind SRVs to avoid hazard on next frame.
// ============================================================
void PostProcessPass::ApplyFog(ID3D11ShaderResourceView* inputSRV,
                                ID3D11RenderTargetView* outputRTV)
{
    // STUB
    (void)inputSRV;
    (void)outputRTV;
}


// ============================================================
// ApplyLUT
// Runs a single fullscreen pass using lut_ps.hlsl.
// Same pattern as ApplyFog but:
//   - Binds m_lutCBuffer at b4.
//   - Binds inputSRV at t0, m_lutSRV at t1.
//   - Uses m_lutPS.
//
// TODO (Qwen): mirror ApplyFog implementation with LUT bindings.
// ============================================================
void PostProcessPass::ApplyLUT(ID3D11ShaderResourceView* inputSRV,
                                ID3D11RenderTargetView* outputRTV)
{
    // STUB
    (void)inputSRV;
    (void)outputRTV;
}


// ============================================================
// ApplyAll
// Master orchestrator — runs all enabled passes then presents.
// Call at the END of each frame just before SwapChain::Present().
//
// Pass sequence:
//   1. CopyDepth(depthView)           — capture depth for fog
//   2. if fogEnabled:
//      ApplyFog(m_sceneSRV, m_pingPongRTV)
//      inputForNext = m_pingPongSRV
//   else:
//      inputForNext = m_sceneSRV
//   3. if lutEnabled:
//      ApplyLUT(inputForNext, backbuffer)
//   else:
//      copy inputForNext → backbuffer (or skip if same RT)
//
// TODO (Qwen): Implement this sequence.
// ============================================================
void PostProcessPass::ApplyAll(ID3D11RenderTargetView* backbuffer,
                                ID3D11DepthStencilView* depthView)
{
    // STUB: no passes active yet — scene already renders to backbuffer directly
    (void)backbuffer;
    (void)depthView;
}


// ============================================================
// DrawFullscreenQuad
// Draws 3 vertices using SV_VertexID trick (no vertex buffer).
// The fullscreen VS generates a triangle that covers [-1,1]^2 NDC.
//
// Required state before call:
//   - Input layout: nullptr
//   - Primitive topology: TRIANGLELIST
//   - VS: m_fullscreenVS
//   - PS: the pass-specific shader
// ============================================================
void PostProcessPass::DrawFullscreenQuad()
{
    // TODO (Qwen): implement:
    // m_context->IASetInputLayout(nullptr);
    // m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    // m_context->VSSetShader(m_fullscreenVS, nullptr, 0);
    // m_context->Draw(3, 0);
}


// ============================================================
// UpdateSettings
// Hot-reloads settings without recreating GPU resources.
// Safe to call each frame or on preset change.
// ============================================================
void PostProcessPass::UpdateSettings(const PostProcessSettings& settings)
{
    m_settings = settings;
}

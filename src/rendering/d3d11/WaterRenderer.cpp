// ============================================================
// FILE: src/rendering/d3d11/WaterRenderer.cpp
// SYSTEM: Rendering / Water
// ROLE: Implements WaterRenderer — water plane rendering via
//   water_vs.hlsl + water_ps.hlsl with alpha blending.
//
// IMPLEMENTATION ORDER FOR QWEN:
//   1. Initialize()  — compile shaders, create states, create cbuffers
//   2. Rebuild()     — generate grid mesh and upload to GPU
//   3. Draw()        — per-frame: update cbuffers, set state, draw
//   4. Shutdown()    — SafeRelease all owned resources
//
// VERTEX STRUCT (must match water_vs.hlsl VSIn layout):
//   struct WaterVertex { XMFLOAT3 pos; XMFLOAT3 normal; XMFLOAT4 color; XMFLOAT2 uv; };
//   Total: 48 bytes. Stride = 48.
//
// D3D11 INPUT ELEMENT DESC for water_vs.hlsl:
//   { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//   { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//   { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//   { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,       0, 40, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//
// GRID GENERATION ALGORITHM:
//   For a gridResolution x gridResolution grid (e.g. 32x32 quads):
//   Vertices: (gridRes+1)^2 = 33x33 = 1089 verts for 32x32
//   Indices:  gridRes^2 * 6 = 6144 indices (uint16)
//   Per quad (x,z): two triangles, CCW winding
//     tri0: (x,z), (x,z+1), (x+1,z+1)   → indices: v00, v01, v11
//     tri1: (x,z), (x+1,z+1), (x+1,z)   → indices: v00, v11, v10
//   Index offset: v(x,z) = z*(gridRes+1) + x
//
// ALPHA BLEND STATE (for Qwen, exact D3D11 setup):
//   See WaterRenderer.hpp for the blend desc fields.
//   Key: BlendEnable=TRUE, SrcBlend=SRC_ALPHA, DestBlend=INV_SRC_ALPHA.
// ============================================================

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "WaterRenderer.hpp"
#include "D3D11ShaderCompiler.hpp"
#include "../../logger/Logger.hpp"
#include <DirectXMath.h>
#include <vector>

using namespace DirectX;

template<typename T>
static void SafeRelease(T*& ptr) { if (ptr) { ptr->Release(); ptr = nullptr; } }


// ============================================================
// VERTEX DEFINITION (internal to this .cpp)
// Must match water_vs.hlsl VSIn exactly.
// ============================================================
struct WaterVertex
{
    XMFLOAT3 pos;     // Object-space XZ position (Y=0; VS sets Y=waterLevel + wave)
    XMFLOAT3 normal;  // Surface normal (0,1,0 for flat; VS computes wave normal)
    XMFLOAT4 color;   // Tint color (RGBA) from WaterBodyParams
    XMFLOAT2 uv;      // Texture UV in [0,1] across the grid
};


// ============================================================
// CONSTRUCTOR / DESTRUCTOR
// ============================================================
WaterRenderer::WaterRenderer()  = default;
WaterRenderer::~WaterRenderer() { Shutdown(); }


// ============================================================
// Initialize
// ============================================================
bool WaterRenderer::Initialize(ID3D11Device* device, ID3D11DeviceContext* context)
{
    m_device  = device;
    m_context = context;

    // TODO (Qwen): Step 1 — compile water_vs.hlsl
    // Use D3D11ShaderCompiler pattern from D3D11Renderer.cpp.
    // You need the compiled VS blob to create the input layout BEFORE releasing it.
    // Example (pseudocode):
    //   ID3DBlob* vsBlob = nullptr;
    //   D3D11ShaderCompiler::CompileFromFile(L"Shaders/water_vs.hlsl", "main", "vs_4_0", &vsBlob);
    //   device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &m_waterVS);
    //
    //   D3D11_INPUT_ELEMENT_DESC layout[] = { ... 4 elements from file header comment ... };
    //   device->CreateInputLayout(layout, 4, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &m_waterLayout);
    //   vsBlob->Release();

    // TODO (Qwen): Step 2 — compile water_ps.hlsl
    //   ID3DBlob* psBlob = nullptr;
    //   D3D11ShaderCompiler::CompileFromFile(L"Shaders/water_ps.hlsl", "main", "ps_4_0", &psBlob);
    //   device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_waterPS);
    //   psBlob->Release();

    // TODO (Qwen): Step 3 — create WaterParamsCBLayout constant buffer (slot b3)
    // D3D11_BUFFER_DESC cbd = {};
    // cbd.ByteWidth = sizeof(WaterParamsCBLayout);
    // cbd.Usage = D3D11_USAGE_DYNAMIC;
    // cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    // cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    // device->CreateBuffer(&cbd, nullptr, &m_waterParamsCB);
    // (same for WaterVisualCBLayout → m_waterVisualCB)

    // TODO (Qwen): Step 4 — create alpha blend state (see header for desc fields)

    // TODO (Qwen): Step 5 — create depth-no-write state
    // D3D11_DEPTH_STENCIL_DESC dsDesc = {};
    // dsDesc.DepthEnable = TRUE;
    // dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO; // Read depth, don't write
    // dsDesc.DepthFunc = D3D11_COMPARISON_LESS;
    // device->CreateDepthStencilState(&dsDesc, &m_depthNoWrite);

    // TODO (Qwen): Step 6 — create linear wrap sampler for normal map
    // D3D11_SAMPLER_DESC sd = {};
    // sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    // sd.AddressU = sd.AddressV = sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    // device->CreateSamplerState(&sd, &m_wrapSampler);

    LOG_INFO("WaterRenderer: initialized (STUB — GPU resources not yet created)");
    return true;
}


// ============================================================
// Shutdown
// ============================================================
void WaterRenderer::Shutdown()
{
    SafeRelease(m_wrapSampler);
    SafeRelease(m_normalMapSRV);
    SafeRelease(m_normalMapTexture);
    SafeRelease(m_depthNoWrite);
    SafeRelease(m_alphaBlendState);
    SafeRelease(m_waterVisualCB);
    SafeRelease(m_waterParamsCB);
    SafeRelease(m_indexBuffer);
    SafeRelease(m_vertexBuffer);
    SafeRelease(m_waterLayout);
    SafeRelease(m_waterPS);
    SafeRelease(m_waterVS);
}


// ============================================================
// Rebuild
// Generates the water plane grid mesh and uploads to GPU.
// Call when cell changes or water body parameters change.
// ============================================================
bool WaterRenderer::Rebuild(const WaterBodyParams& params)
{
    m_params = params;
    if (!params.enabled)
    {
        m_enabled = false;
        return true;
    }

    // Release previous buffers
    SafeRelease(m_vertexBuffer);
    SafeRelease(m_indexBuffer);
    m_indexCount = 0;

    const int res = params.gridResolution; // quads per side (e.g. 32)
    const int vertsPerSide = res + 1;
    const int totalVerts   = vertsPerSide * vertsPerSide;
    const int totalIndices = res * res * 6;

    // --------------------------------------------------------
    // TODO (Qwen): Generate vertices
    // Outer loop over Z, inner over X. For each (x, z):
    //   float wx = params.originX + (x / (float)res) * params.extentX;
    //   float wz = params.originZ + (z / (float)res) * params.extentZ;
    //   WaterVertex v;
    //   v.pos    = XMFLOAT3(wx, 0.0f, wz); // Y=0 object space; VS lifts to waterLevel
    //   v.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
    //   v.color  = XMFLOAT4(params.tintR, params.tintG, params.tintB, params.tintA);
    //   v.uv     = XMFLOAT2(x/(float)res, z/(float)res);
    //   verts.push_back(v);
    // --------------------------------------------------------
    std::vector<WaterVertex> verts;
    verts.reserve(totalVerts);
    // STUB: generate flat vertices (no wave — wave is in VS at runtime)
    for (int z = 0; z <= res; ++z)
    {
        for (int x = 0; x <= res; ++x)
        {
            WaterVertex v{};
            v.pos    = XMFLOAT3(params.originX + (x / (float)res) * params.extentX,
                                 0.0f,
                                 params.originZ + (z / (float)res) * params.extentZ);
            v.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
            v.color  = XMFLOAT4(params.tintR, params.tintG, params.tintB, params.tintA);
            v.uv     = XMFLOAT2(x / (float)res, z / (float)res);
            verts.push_back(v);
        }
    }

    // --------------------------------------------------------
    // TODO (Qwen): Generate indices (CCW tri winding for D3D11 default)
    // For each quad (x,z):
    //   uint16 v00 = z*vertsPerSide + x;
    //   uint16 v10 = z*vertsPerSide + x+1;
    //   uint16 v01 = (z+1)*vertsPerSide + x;
    //   uint16 v11 = (z+1)*vertsPerSide + x+1;
    //   indices: v00, v01, v11,  v00, v11, v10
    // --------------------------------------------------------
    std::vector<uint16_t> indices;
    indices.reserve(totalIndices);
    for (int z = 0; z < res; ++z)
    {
        for (int x = 0; x < res; ++x)
        {
            uint16_t v00 = (uint16_t)(z * vertsPerSide + x);
            uint16_t v10 = (uint16_t)(z * vertsPerSide + x + 1);
            uint16_t v01 = (uint16_t)((z + 1) * vertsPerSide + x);
            uint16_t v11 = (uint16_t)((z + 1) * vertsPerSide + x + 1);
            indices.push_back(v00); indices.push_back(v01); indices.push_back(v11);
            indices.push_back(v00); indices.push_back(v11); indices.push_back(v10);
        }
    }
    m_indexCount = (UINT)indices.size();

    // Upload vertex buffer
    // TODO (Qwen): replace stub with D3D11 buffer creation:
    if (m_device)
    {
        D3D11_BUFFER_DESC vbd{};
        vbd.Usage     = D3D11_USAGE_DEFAULT;
        vbd.ByteWidth = (UINT)(verts.size() * sizeof(WaterVertex));
        vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        D3D11_SUBRESOURCE_DATA vinit{};
        vinit.pSysMem = verts.data();
        HRESULT hr = m_device->CreateBuffer(&vbd, &vinit, &m_vertexBuffer);
        if (FAILED(hr))
        {
            LOG_ERROR("WaterRenderer: failed to create vertex buffer");
            return false;
        }

        // Upload index buffer
        D3D11_BUFFER_DESC ibd{};
        ibd.Usage     = D3D11_USAGE_DEFAULT;
        ibd.ByteWidth = (UINT)(indices.size() * sizeof(uint16_t));
        ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
        D3D11_SUBRESOURCE_DATA iinit{};
        iinit.pSysMem = indices.data();
        hr = m_device->CreateBuffer(&ibd, &iinit, &m_indexBuffer);
        if (FAILED(hr))
        {
            LOG_ERROR("WaterRenderer: failed to create index buffer");
            return false;
        }
    }

    m_enabled = true;
    LOG_INFO("WaterRenderer: rebuilt water plane grid");
    return true;
}


// ============================================================
// Draw
// Renders the water plane for the current frame.
// ============================================================
void WaterRenderer::Draw(float dt,
                          const DirectX::XMFLOAT4X4& mvpMatrix,
                          const DirectX::XMFLOAT4X4& worldMatrix,
                          float windStrength,
                          float weatherRainIntensity)
{
    if (!m_enabled || !m_context) return;
    if (!m_vertexBuffer || !m_indexBuffer) return; // Rebuild not called yet

    // Step 1: Advance wave animation time
    m_waterTime += dt;

    // TODO (Qwen): Step 2 — upload WaterParamsCBLayout to m_waterParamsCB
    // Scale wave amplitudes by weatherRainIntensity (rain = choppier water):
    //   WaterParamsCBLayout cb{};
    //   cb.waterTime       = m_waterTime;
    //   cb.waterWave1Amp   = 0.08f * (1.0f + weatherRainIntensity * 0.5f);
    //   cb.waterWave1Freq  = 1.2f;
    //   cb.waterWave1Speed = 0.6f + windStrength * 0.4f;
    //   cb.waterWave2Amp   = 0.03f * (1.0f + weatherRainIntensity);
    //   cb.waterWave2Freq  = 2.8f;
    //   cb.waterWave2Speed = 1.8f + windStrength * 0.6f;
    //   cb.waterLevel      = m_params.level;
    //   Map → memcpy → Unmap → PSSetConstantBuffers(3, 1, &m_waterParamsCB)

    // TODO (Qwen): Step 3 — upload WaterVisualCBLayout to m_waterVisualCB
    // Values are mostly constants tuned for the visual targets in water_ps.hlsl.

    // TODO (Qwen): Step 4 — set D3D11 render state:
    //   m_context->OMSetBlendState(m_alphaBlendState, nullptr, 0xFFFFFFFF);
    //   m_context->OMSetDepthStencilState(m_depthNoWrite, 0);

    // TODO (Qwen): Step 5 — bind vertex/index buffers + input layout + shaders:
    //   UINT stride = sizeof(WaterVertex); UINT offset = 0;
    //   m_context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
    //   m_context->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R16_UINT, 0);
    //   m_context->IASetInputLayout(m_waterLayout);
    //   m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //   m_context->VSSetShader(m_waterVS, nullptr, 0);
    //   m_context->PSSetShader(m_waterPS, nullptr, 0);

    // TODO (Qwen): Step 6 — bind constant buffer for mvp/world (PerDraw cbuffer b0)
    // The existing m_constantBuffer from D3D11Renderer should be reused.
    // This requires passing it in as a parameter or storing a reference.
    // For now, D3D11Renderer will need to upload mvp/world before calling Draw().

    // TODO (Qwen): Step 7 — draw
    //   m_context->DrawIndexed(m_indexCount, 0, 0);

    // TODO (Qwen): Step 8 — restore default depth/blend states after water draw
    //   m_context->OMSetBlendState(nullptr, nullptr, 0xFFFFFFFF);
    //   m_context->OMSetDepthStencilState(nullptr, 0);

    (void)mvpMatrix; (void)worldMatrix; (void)dt; // suppress stub warnings
}

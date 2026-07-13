// ============================================================
// FILE: src/rendering/d3d11/D3D11Renderer.cpp
// SYSTEM: Rendering
// ROLE: rendering GPU resources, shader flow, and draw submission
// ============================================================

#include "D3D11Renderer.hpp"
#include "Terrain_Renderer.hpp"
#include "D3D11ShaderCompiler.hpp"
#include "../../logger/Logger.hpp"
#include <algorithm>
#include <cmath>
#include <string>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

using namespace DirectX;

// File-scope safe-release helper; nulls the pointer after releasing.
template<typename T>
static void SafeRelease(T*& ptr)
{
    if (ptr) { ptr->Release(); ptr = nullptr; }
}

static void NormalizeLightDirection(RenderContracts::LightCBuffer& lightData)
{
    const float lenSq =
        lightData.lightDirX * lightData.lightDirX +
        lightData.lightDirY * lightData.lightDirY +
        lightData.lightDirZ * lightData.lightDirZ;

    if (lenSq <= 0.000001f)
    {
        lightData = RenderContracts::DefaultDirectionalLight();
        return;
    }

    const float invLen = 1.0f / std::sqrt(lenSq);
    lightData.lightDirX *= invLen;
    lightData.lightDirY *= invLen;
    lightData.lightDirZ *= invLen;
}

// ============================================================
// CONSTRUCTOR & DESTRUCTOR
// ============================================================

D3D11Renderer::D3D11Renderer()
{
    renderWidth  = 800;
    renderHeight = 600;
}

D3D11Renderer::~D3D11Renderer()
{
    Shutdown();
}

// ============================================================
// INITIALIZATION & SHUTDOWN
// ============================================================

bool D3D11Renderer::Initialize(HWND windowHandle, int width, int height)
{
    renderWidth  = width;
    renderHeight = height;

    DXGI_SWAP_CHAIN_DESC scd               = {};
    scd.BufferCount                        = 1;
    scd.BufferDesc.Width                   = static_cast<UINT>(width);
    scd.BufferDesc.Height                  = static_cast<UINT>(height);
    scd.BufferDesc.Format                  = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator   = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferUsage                        = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow                       = windowHandle;
    scd.SampleDesc.Count                   = 1;
    scd.SampleDesc.Quality                 = 0;
    scd.Windowed                           = TRUE;

    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        featureLevels, ARRAYSIZE(featureLevels),
        D3D11_SDK_VERSION,
        &scd,
        &swapChain,
        &device,
        &featureLevel,
        &context
    );

    if (FAILED(hr))
    {
        LOG_ERROR("Failed to create D3D11 device and swap chain.");
        return false;
    }

    if (!CreateRenderTarget())      return false;
    if (!CreateTriangleResources()) return false;
    if (!CreateSceneConstantBuffers()) return false;
    if (!CreateFallbackResources()) return false;
    if (!CreateTerrainRasterizerStates()) return false;

    if (!CreateTerrainPatch())
        LOG_INFO("Initial terrain patch creation skipped.");
    if (!CreateGroundPlaneGeometry())
        LOG_WARN("Ground fallback geometry creation failed.");

    CreateGroundShaders();
    CreateSkyShaders();
    UploadLightConstants();
    ValidateRenderState("Initialize");

    return true;
}

void D3D11Renderer::Shutdown()
{
    LOG_INFO("Shutting down renderer...");

    SafeRelease(vertexShader);
    SafeRelease(pixelShader);
    SafeRelease(inputLayout);
    SafeRelease(vertexBuffer);
    SafeRelease(m_constantBuffer);

    SafeRelease(groundVertexShader);
    SafeRelease(groundPixelShader);
    SafeRelease(groundInputLayout);
    SafeRelease(m_groundVertexBuffer);
    SafeRelease(m_groundIndexBuffer);

    SafeRelease(skyVertexShader);
    SafeRelease(skyPixelShader);
    SafeRelease(skyInputLayout);

    SafeRelease(m_lightCBuffer);
    SafeRelease(m_fallbackWhiteTexture);
    SafeRelease(m_terrainPatchVertexBuffer);
    SafeRelease(m_textureSampler);
    SafeRelease(m_terrainSolidRasterState);
    SafeRelease(m_terrainNoCullRasterState);
    SafeRelease(m_terrainWireRasterState);

    SafeRelease(renderTargetView);
    SafeRelease(depthView);
    SafeRelease(depthTexture);
    SafeRelease(swapChain);
    SafeRelease(context);
    SafeRelease(device);

    m_textureCache = nullptr;
    m_loggedMissingTerrainWarning = false;
    ClearTerrainPatch();
}

// ============================================================
// SHADER & RESOURCE CREATION
// ============================================================

bool D3D11Renderer::CreateTriangleResources()
{
    // Vertex data: POSITION (float3) + COLOR (float4) — matches triangle_vs.hlsl
    SimpleVertex verts[3] = {
        { XMFLOAT3(-0.5f, -0.5f, 0.0f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
        { XMFLOAT3( 0.5f, -0.5f, 0.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
        { XMFLOAT3( 0.0f,  0.5f, 0.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
    };
    m_triangleVertexCount = 3;

    D3D11_BUFFER_DESC vbd   = {};
    vbd.Usage               = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth           = sizeof(verts);
    vbd.BindFlags           = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA init = {};
    init.pSysMem            = verts;

    HRESULT hr = device->CreateBuffer(&vbd, &init, &vertexBuffer);
    if (FAILED(hr))
    {
        LOG_ERROR("Failed to create triangle vertex buffer.");
        return false;
    }

    // Compile vertex shader and create input layout
    ID3DBlob* vsBlob = nullptr;
    hr = D3D11ShaderCompiler::CompileFromFile(
        L"Shaders/triangle_vs.hlsl", "main", "vs_4_0", &vsBlob);
    if (SUCCEEDED(hr) && vsBlob)
    {
        device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
            nullptr, &vertexShader);

        D3D11_INPUT_ELEMENT_DESC triLayout[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };
        device->CreateInputLayout(triLayout, 2,
            vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &inputLayout);
        vsBlob->Release();
    }

    // Compile pixel shader
    ID3DBlob* psBlob = nullptr;
    hr = D3D11ShaderCompiler::CompileFromFile(
        L"Shaders/triangle_ps.hlsl", "main", "ps_4_0", &psBlob);
    if (SUCCEEDED(hr) && psBlob)
    {
        device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(),
            nullptr, &pixelShader);
        psBlob->Release();
    }

    return true;
}

bool D3D11Renderer::CreateRenderTarget()
{
    // Obtain the swap chain back buffer and create a render target view
    ID3D11Texture2D* backBuffer = nullptr;
    HRESULT hr = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
        reinterpret_cast<void**>(&backBuffer));
    if (FAILED(hr))
    {
        LOG_ERROR("Failed to get swap chain back buffer.");
        return false;
    }

    hr = device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
    backBuffer->Release();
    if (FAILED(hr))
    {
        LOG_ERROR("Failed to create render target view.");
        return false;
    }

    // Create depth stencil texture
    D3D11_TEXTURE2D_DESC depthDesc   = {};
    depthDesc.Width                  = static_cast<UINT>(renderWidth);
    depthDesc.Height                 = static_cast<UINT>(renderHeight);
    depthDesc.MipLevels              = 1;
    depthDesc.ArraySize              = 1;
    depthDesc.Format                 = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depthDesc.SampleDesc.Count       = 1;
    depthDesc.SampleDesc.Quality     = 0;
    depthDesc.Usage                  = D3D11_USAGE_DEFAULT;
    depthDesc.BindFlags              = D3D11_BIND_DEPTH_STENCIL;

    hr = device->CreateTexture2D(&depthDesc, nullptr, &depthTexture);
    if (FAILED(hr))
    {
        LOG_ERROR("Failed to create depth texture.");
        return false;
    }

    hr = device->CreateDepthStencilView(depthTexture, nullptr, &depthView);
    if (FAILED(hr))
    {
        LOG_ERROR("Failed to create depth stencil view.");
        return false;
    }

    // Bind render target and depth buffer to the output merger
    context->OMSetRenderTargets(1, &renderTargetView, depthView);

    // Set the full-window viewport
    D3D11_VIEWPORT vp = {};
    vp.Width          = static_cast<float>(renderWidth);
    vp.Height         = static_cast<float>(renderHeight);
    vp.MinDepth       = 0.0f;
    vp.MaxDepth       = 1.0f;
    vp.TopLeftX       = 0.0f;
    vp.TopLeftY       = 0.0f;
    context->RSSetViewports(1, &vp);

    return true;
}

bool D3D11Renderer::CreateTerrainPatch()
{
    // No initial geometry — geometry is built on demand via RebuildTerrainPatch().
    m_terrainVertsX          = 0;
    m_terrainVertsZ          = 0;
    m_terrainAvailable       = false;
    m_terrainPatchVertexCount = 0;
    return true;
}

bool D3D11Renderer::CreateGroundPlaneGeometry()
{
    SafeRelease(m_groundVertexBuffer);
    static const D3D11RendererHelpers::TerrainVertex verts[6] = {
        { -800.0f, 0.0f, -800.0f, 0.0f, 1.0f, 0.0f, 0.45f, 0.55f, 0.45f, 1.0f },
        { -800.0f, 0.0f,  800.0f, 0.0f, 1.0f, 0.0f, 0.45f, 0.55f, 0.45f, 1.0f },
        {  800.0f, 0.0f, -800.0f, 0.0f, 1.0f, 0.0f, 0.45f, 0.55f, 0.45f, 1.0f },
        {  800.0f, 0.0f, -800.0f, 0.0f, 1.0f, 0.0f, 0.45f, 0.55f, 0.45f, 1.0f },
        { -800.0f, 0.0f,  800.0f, 0.0f, 1.0f, 0.0f, 0.45f, 0.55f, 0.45f, 1.0f },
        {  800.0f, 0.0f,  800.0f, 0.0f, 1.0f, 0.0f, 0.45f, 0.55f, 0.45f, 1.0f },
    };

    D3D11_BUFFER_DESC vbd = {};
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = sizeof(verts);
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA init = {};
    init.pSysMem = verts;
    return SUCCEEDED(device->CreateBuffer(&vbd, &init, &m_groundVertexBuffer));
}

bool D3D11Renderer::CreateSceneConstantBuffers()
{
    D3D11_BUFFER_DESC transformDesc = {};
    transformDesc.Usage = D3D11_USAGE_DEFAULT;
    transformDesc.ByteWidth = sizeof(RenderContracts::TransformCBuffer);
    transformDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    if (FAILED(device->CreateBuffer(&transformDesc, nullptr, &m_constantBuffer)))
    {
        LOG_ERROR("Failed to create scene transform constant buffer.");
        return false;
    }

    D3D11_BUFFER_DESC lightDesc = {};
    lightDesc.Usage = D3D11_USAGE_DEFAULT;
    lightDesc.ByteWidth = sizeof(RenderContracts::LightCBuffer);
    lightDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    D3D11_SUBRESOURCE_DATA lightInit = {};
    lightInit.pSysMem = &m_lightData;
    if (FAILED(device->CreateBuffer(&lightDesc, &lightInit, &m_lightCBuffer)))
    {
        LOG_ERROR("Failed to create scene light constant buffer.");
        return false;
    }

    return true;
}

bool D3D11Renderer::CreateFallbackResources()
{
    D3D11_TEXTURE2D_DESC texDesc = {};
    texDesc.Width = 1;
    texDesc.Height = 1;
    texDesc.MipLevels = 1;
    texDesc.ArraySize = 1;
    texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    texDesc.SampleDesc.Count = 1;
    texDesc.Usage = D3D11_USAGE_IMMUTABLE;
    texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

    const unsigned int whitePixel = 0xFFFFFFFFu;
    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = &whitePixel;
    initData.SysMemPitch = sizeof(whitePixel);

    ID3D11Texture2D* tex = nullptr;
    if (FAILED(device->CreateTexture2D(&texDesc, &initData, &tex)))
    {
        LOG_ERROR("Failed to create fallback white texture.");
        return false;
    }

    const HRESULT srvHr = device->CreateShaderResourceView(tex, nullptr, &m_fallbackWhiteTexture);
    tex->Release();
    if (FAILED(srvHr))
    {
        LOG_ERROR("Failed to create fallback white texture SRV.");
        return false;
    }

    D3D11_SAMPLER_DESC sampDesc = {};
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
    if (FAILED(device->CreateSamplerState(&sampDesc, &m_textureSampler)))
    {
        LOG_ERROR("Failed to create terrain/ground sampler.");
        return false;
    }

    return true;
}

bool D3D11Renderer::CreateTerrainRasterizerStates()
{
    D3D11_RASTERIZER_DESC solidDesc = {};
    solidDesc.FillMode = D3D11_FILL_SOLID;
    solidDesc.CullMode = D3D11_CULL_BACK;
    solidDesc.DepthClipEnable = TRUE;
    if (FAILED(device->CreateRasterizerState(&solidDesc, &m_terrainSolidRasterState)))
    {
        LOG_ERROR("Failed to create terrain solid rasterizer state.");
        return false;
    }

    D3D11_RASTERIZER_DESC wireDesc = solidDesc;
    wireDesc.FillMode = D3D11_FILL_WIREFRAME;
    wireDesc.CullMode = D3D11_CULL_NONE;
    if (FAILED(device->CreateRasterizerState(&wireDesc, &m_terrainWireRasterState)))
    {
        LOG_ERROR("Failed to create terrain wireframe rasterizer state.");
        return false;
    }

    D3D11_RASTERIZER_DESC noCullDesc = solidDesc;
    noCullDesc.CullMode = D3D11_CULL_NONE;
    if (FAILED(device->CreateRasterizerState(&noCullDesc, &m_terrainNoCullRasterState)))
    {
        LOG_ERROR("Failed to create terrain no-cull rasterizer state.");
        return false;
    }

    return true;
}

void D3D11Renderer::CreateGroundShaders()
{
    // Vertex shader
    ID3DBlob* vsBlob = nullptr;
    HRESULT hr = D3D11ShaderCompiler::CompileFromFile(
        L"Shaders/ground_vs.hlsl", "main", "vs_4_0", &vsBlob);
    if (SUCCEEDED(hr) && vsBlob)
    {
        device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
            nullptr, &groundVertexShader);

        // Input layout matches TerrainVertex (POSITION | NORMAL | COLOR)
        D3D11ShaderCompiler::CreateTerrainInputLayout(
            device, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &groundInputLayout);

        vsBlob->Release();
    }

    // Pixel shader
    ID3DBlob* psBlob = nullptr;
    hr = D3D11ShaderCompiler::CompileFromFile(
        L"Shaders/ground_ps.hlsl", "main", "ps_4_0", &psBlob);
    if (SUCCEEDED(hr) && psBlob)
    {
        device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(),
            nullptr, &groundPixelShader);
        psBlob->Release();
    }
}

void D3D11Renderer::CreateSkyShaders()
{
    // The sky vertex shader uses SV_VertexID — no vertex buffer or input layout required.
    ID3DBlob* vsBlob = nullptr;
    HRESULT hr = D3D11ShaderCompiler::CompileFromFile(
        L"Shaders/sky_vs.hlsl", "main", "vs_4_0", &vsBlob);
    if (SUCCEEDED(hr) && vsBlob)
    {
        device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
            nullptr, &skyVertexShader);
        vsBlob->Release();
    }

    ID3DBlob* psBlob = nullptr;
    hr = D3D11ShaderCompiler::CompileFromFile(
        L"Shaders/sky_ps.hlsl", "main", "ps_4_0", &psBlob);
    if (SUCCEEDED(hr) && psBlob)
    {
        device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(),
            nullptr, &skyPixelShader);
        psBlob->Release();
    }
}

// ============================================================
// DRAWING FUNCTIONS
// ============================================================

void D3D11Renderer::ClearScreen(float red, float green, float blue, float alpha)
{
    float clearColor[4] = { red, green, blue, alpha };
    context->ClearRenderTargetView(renderTargetView, clearColor);
    context->ClearDepthStencilView(depthView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
}

void D3D11Renderer::PresentFrame()
{
    UINT syncInterval = m_vsyncEnabled ? 1u : 0u;
    HRESULT hr = swapChain->Present(syncInterval, 0);
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
    {
        LOG_ERROR("Device lost. Restart required.");
        Shutdown();
    }
}

void D3D11Renderer::DrawRotatingTriangle(float deltaTime)
{
    if (!vertexShader || !pixelShader || !inputLayout || !vertexBuffer)
        return;

    UINT stride = sizeof(SimpleVertex);
    UINT offset = 0;
    context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    context->IASetInputLayout(inputLayout);
    context->VSSetShader(vertexShader, nullptr, 0);
    context->PSSetShader(pixelShader,  nullptr, 0);
    context->Draw(m_triangleVertexCount, 0);
}

void D3D11Renderer::DrawSky()
{
    if (!skyVertexShader || !skyPixelShader)
    {
        LOG_ERROR("Sky shaders not initialized.");
        return;
    }

    // Sky uses SV_VertexID — no vertex buffer or input layout needed.
    // Draw a full-screen triangle (3 vertices cover the entire screen).
    context->IASetInputLayout(nullptr);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    context->VSSetShader(skyVertexShader, nullptr, 0);
    context->PSSetShader(skyPixelShader,  nullptr, 0);
    context->Draw(3, 0);
}

void D3D11Renderer::SetCameraPosition(float x, float y, float z)
{
    cameraX = x; cameraY = y; cameraZ = z;
}

void D3D11Renderer::SetCameraRotation(float yaw, float pitch)
{
    cameraYaw = yaw; cameraPitch = pitch;
}

void D3D11Renderer::GetCameraPosition(float& x, float& y, float& z) const
{
    x = cameraX; y = cameraY; z = cameraZ;
}

void D3D11Renderer::GetCameraRotation(float& yaw, float& pitch) const
{
    yaw = cameraYaw; pitch = cameraPitch;
}

void D3D11Renderer::SetSunDirection(float x, float y, float z)
{
    m_lightData.lightDirX = x;
    m_lightData.lightDirY = y;
    m_lightData.lightDirZ = z;
    NormalizeLightDirection(m_lightData);
    UploadLightConstants();
}

void D3D11Renderer::GetSunDirection(float& x, float& y, float& z) const
{
    x = m_lightData.lightDirX;
    y = m_lightData.lightDirY;
    z = m_lightData.lightDirZ;
}

float D3D11Renderer::GetAmbientStrength() const
{
    return m_lightData.ambientStrength;
}

void D3D11Renderer::SetAmbientStrength(float a)
{
    m_lightData.ambientStrength = std::clamp(a, 0.05f, 1.0f);
    UploadLightConstants();
}

void D3D11Renderer::SetVSyncEnabled(bool enabled)
{
    m_vsyncEnabled = enabled;
}

void D3D11Renderer::SetFrameRateLimit(int fps)
{
    m_frameRateLimit = fps;
}

void D3D11Renderer::ApplyGraphicsPreset(GraphicsPreset preset)
{
    m_graphicsPreset = preset;
}

void D3D11Renderer::Tick(float deltaTime)
{
    (void)deltaTime;
    UploadLightConstants();
}

bool D3D11Renderer::ValidateRenderState(const char* stage) const
{
    const char* at = stage ? stage : "unknown";
    bool ok = true;

    auto require = [&](bool condition, const char* message)
    {
        if (!condition)
        {
            LOG_ERROR(std::string("Render validation [") + at + "]: " + message);
            ok = false;
        }
    };

    require(device != nullptr, "device missing");
    require(context != nullptr, "context missing");
    require(renderTargetView != nullptr, "render target view missing");
    require(depthView != nullptr, "depth view missing");
    require(m_constantBuffer != nullptr, "transform constant buffer missing");
    require(m_lightCBuffer != nullptr, "light constant buffer missing");
    require(m_fallbackWhiteTexture != nullptr, "fallback texture SRV missing");
    require(groundVertexShader != nullptr && groundPixelShader != nullptr, "ground shaders missing");
    require(groundInputLayout != nullptr, "ground input layout missing");

    if (!m_terrainManager)
        LOG_WARN(std::string("Render validation [") + at + "]: TerrainManager not bound; terrain draw will fallback.");

    return ok;
}

void D3D11Renderer::DebugDraw()
{
    // TODO(next-ai): purpose=draw terrain bounds/debug overlays
    // required inputs/outputs=TerrainManager mesh bounds + camera frustum; output debug primitives
    // invariants=must not mutate world state; must run after terrain draw and before PresentFrame
    // acceptance checks=bounds are visible when debug flag is enabled and no gameplay state changes
    // file ownership/expected edit scope=src/rendering/d3d11/D3D11Renderer.cpp only
}

// ============================================================
// TERRAIN RENDERING FUNCTIONS
// ============================================================

bool D3D11Renderer::RebuildTerrainPatch(const TerrainParams& params)
{
    if (!m_terrainManager)
    {
        LOG_ERROR("Cannot rebuild terrain: TerrainManager not initialized.");
        return false;
    }
    return m_terrainManager->RebuildTerrainPatch(params);
}

void D3D11Renderer::DrawGroundPlane()
{
    if (!m_groundVertexBuffer || !groundVertexShader || !groundPixelShader)
    {
        LOG_ERROR("Ground resources not initialized.");
        return;
    }

    SetupGroundAndTerrainSceneConstants(2000.0f);
    UploadLightConstants();

    ID3D11RasterizerState* rs = m_terrainSolidRasterState;
    if (m_debugTerrainWireframe)
        rs = m_terrainWireRasterState;
    else if (m_debugTerrainDisableCulling)
        rs = m_terrainNoCullRasterState;
    if (rs) context->RSSetState(rs);

    context->IASetInputLayout(groundInputLayout);
    context->VSSetShader(groundVertexShader, nullptr, 0);
    context->PSSetShader(groundPixelShader,  nullptr, 0);
    if (m_constantBuffer)
        context->VSSetConstantBuffers(RenderContracts::kTransformBufferRegister, 1, &m_constantBuffer);
    if (m_lightCBuffer)
        context->PSSetConstantBuffers(RenderContracts::kLightBufferRegister, 1, &m_lightCBuffer);
    if (m_fallbackWhiteTexture)
        context->PSSetShaderResources(0, 1, &m_fallbackWhiteTexture);
    if (m_textureSampler)
        context->PSSetSamplers(0, 1, &m_textureSampler);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    UINT stride = sizeof(D3D11RendererHelpers::TerrainVertex);
    UINT offset = 0;
    context->IASetVertexBuffers(0, 1, &m_groundVertexBuffer, &stride, &offset);
    context->Draw(6, 0);
    context->RSSetState(nullptr);
}

void D3D11Renderer::DrawTerrainPatch()
{
    if (!m_terrainManager)
    {
        if (!m_loggedMissingTerrainWarning)
        {
            LOG_WARN("TerrainManager missing; drawing fallback ground plane.");
            m_loggedMissingTerrainWarning = true;
        }
        DrawGroundPlane();
        return;
    }

    if (!m_terrainManager->IsTerrainAvailable())
    {
        DrawGroundPlane();
        return;
    }

    SetupGroundAndTerrainSceneConstants(2000.0f);
    UploadLightConstants();

    ID3D11RasterizerState* rs = m_terrainSolidRasterState;
    if (m_debugTerrainWireframe)
        rs = m_terrainWireRasterState;
    else if (m_debugTerrainDisableCulling)
        rs = m_terrainNoCullRasterState;
    if (rs) context->RSSetState(rs);
    context->IASetInputLayout(groundInputLayout);
    context->VSSetShader(groundVertexShader, nullptr, 0);
    context->PSSetShader(groundPixelShader,  nullptr, 0);
    if (m_constantBuffer)
        context->VSSetConstantBuffers(RenderContracts::kTransformBufferRegister, 1, &m_constantBuffer);

    // Bind light constants to pixel shader register b1
    if (m_lightCBuffer)
        context->PSSetConstantBuffers(RenderContracts::kLightBufferRegister, 1, &m_lightCBuffer);

    // Bind optional sampler for texture sampling in ground_ps.hlsl
    if (m_textureSampler)
        context->PSSetSamplers(0, 1, &m_textureSampler);
    if (m_fallbackWhiteTexture)
        context->PSSetShaderResources(0, 1, &m_fallbackWhiteTexture);

    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    UINT stride = sizeof(D3D11RendererHelpers::TerrainVertex);
    UINT offset = 0;

    ID3D11Buffer* terrainVB = m_terrainManager->GetVertexBuffer();
    if (!terrainVB || m_terrainManager->GetVertexCount() == 0)
    {
        LOG_WARN("Terrain vertex buffer unavailable; drawing fallback ground plane.");
        DrawGroundPlane();
        return;
    }

    context->IASetVertexBuffers(0, 1, &terrainVB, &stride, &offset);
    context->Draw(m_terrainManager->GetVertexCount(), 0);
    context->RSSetState(nullptr);
}

float D3D11Renderer::SampleTerrainHeight(float worldX, float worldZ) const
{
    if (!m_terrainManager) return 0.0f;
    return m_terrainManager->SampleTerrainHeight(worldX, worldZ);
}

bool D3D11Renderer::IsTerrainAvailable() const
{
    return m_terrainManager && m_terrainManager->IsTerrainAvailable();
}

void D3D11Renderer::ClearTerrainPatch()
{
    if (m_terrainManager)
        m_terrainManager->ClearResources();
    m_terrainHeights.clear();
    m_terrainAvailable = false;
    m_terrainVertsX    = 0;
    m_terrainVertsZ    = 0;
    m_loggedMissingTerrainWarning = false;
}

// ============================================================
// CAMERA & PHYSICS CONTROL
// ============================================================

void D3D11Renderer::SetCameraVelocityY(float velocity) { cameraVelocityY = velocity; }
float D3D11Renderer::GetCameraVelocityY() const        { return cameraVelocityY; }
void D3D11Renderer::SetIsGrounded(bool grounded)        { isGrounded = grounded; }
bool D3D11Renderer::GetIsGrounded() const               { return isGrounded; }

// ============================================================
// CEL SHADING
// ============================================================

bool D3D11Renderer::SetCelShadingParameters(float count, float minVal, float maxVal,
    float rimAmount, float shadowR, float shadowG, float shadowB, float specThreshold)
{
    // Cel shading constants would be uploaded to a shader cbuffer here.
    return true;
}

void D3D11Renderer::DrawCharacterOutlinePass(float outlineThickness)
{
    LOG_INFO("Drawing character outline (placeholder).");
}

// ============================================================
// SCENE CONSTANTS SETUP
// ============================================================

void D3D11Renderer::SetupGroundAndTerrainSceneConstants(float farPlane)
{
    if (!m_constantBuffer)
        return;

    const float safeWidth = std::max(1, renderWidth);
    const float safeHeight = std::max(1, renderHeight);
    const float aspect = static_cast<float>(safeWidth) / static_cast<float>(safeHeight);
    const auto mats = D3D11RendererHelpers::BuildSceneMatrices(
        cameraX, cameraY, cameraZ, cameraYaw, cameraPitch,
        aspect, 0.1f, std::max(100.0f, farPlane));

    RenderContracts::TransformCBuffer cb = {};
    DirectX::XMStoreFloat4x4(&cb.world, DirectX::XMMatrixTranspose(mats.world));
    DirectX::XMStoreFloat4x4(&cb.mvp, DirectX::XMMatrixTranspose(mats.world * mats.view * mats.projection));
    context->UpdateSubresource(m_constantBuffer, 0, nullptr, &cb, 0, 0);
}

void D3D11Renderer::UploadLightConstants()
{
    if (!m_lightCBuffer || !context)
        return;

    RenderContracts::LightCBuffer data = m_lightData;
    NormalizeLightDirection(data);
    if (m_debugTerrainUnlit)
    {
        data.lightColorR = 0.0f;
        data.lightColorG = 0.0f;
        data.lightColorB = 0.0f;
        data.ambientStrength = 1.0f;
    }
    context->UpdateSubresource(m_lightCBuffer, 0, nullptr, &data, 0, 0);
}

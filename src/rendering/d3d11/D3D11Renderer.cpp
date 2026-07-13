// ============================================================
// FILE: src/rendering/d3d11/D3D11Renderer.cpp
// SYSTEM: Rendering
// ROLE: rendering GPU resources, shader flow, and draw submission
// ============================================================

#include "D3D11Renderer.hpp"
#include "../../logger/Logger.hpp"
#include <algorithm>
#include <cmath>
#include <string>

using namespace DirectX;

// ============================================================
// CONSTRUCTOR & DESTRUCTOR
// ============================================================

D3D11Renderer::D3D11Renderer()
{
    renderWidth = 800;
    renderHeight = 600;
}

D3D11Renderer::~D3D11Renderer()
{
    Shutdown(); // Clean up all GPU resources
}

// ============================================================
// INITIALIZATION & SHUTDOWN
// ============================================================

bool D3D11Renderer::Initialize(HWND windowHandle, int width, int height)
{
    renderWidth = width;
    renderHeight = height;

    // Create device and context (simplified - full implementation omitted)
    ID3D11Device* dev = nullptr;
    ID3D11DeviceContext* ctx = nullptr;
    IDXGISwapChain* chain = nullptr;

    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_9_1; // Adjust based on needs

    HRESULT hr = D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        &featureLevel,
        1,
        D3D11_SDK_VERSION,
        &dev,
        &featureLevel,
        &chain
    );

    if (FAILED(hr)) {
        LOG_ERROR("Failed to create Direct3D device.");
        return false;
    }

    // Store device pointers
    device = dev;
    context = ctx;

    hr = chain->GetDevice(&dev, nullptr);
    if (SUCCEEDED(hr) && dev != device) {
        device->Release();
        device = dev;
    }

    hr = chain->GetImmediateContext(&ctx);
    if (SUCCEEDED(hr) && ctx != context) {
        context->Release();
        context = ctx;
    }

    // Create render target and depth buffer
    if (!CreateRenderTarget()) return false;

    // Create triangle resources (rotating test object)
    if (!CreateTriangleResources()) return false;

    // Create terrain patch geometry (initially empty)
    if (!CreateTerrainPatch()) {
        LOG_INFO("Initial terrain patch creation skipped.");
    }

    // Create ground plane shaders
    CreateGroundShaders();

    // Create sky shaders
    CreateSkyShaders();

    return true;
}

void D3D11Renderer::Shutdown()
{
    LOG_INFO("Shutting down renderer...");

    SafeRelease(vertexShader);
    SafeRelease(pixelShader);
    SafeRelease(inputLayout);
    SafeRelease(vertexBuffer);
    SafeRelease(transformConstantBuffer);

    SafeRelease(groundVertexShader);
    SafeRelease(groundPixelShader);
    SafeRelease(groundInputLayout);
    SafeRelease(m_groundVertexBuffer);
    SafeRelease(m_groundIndexBuffer);

    SafeRelease(skyVertexShader);
    SafeRelease(skyPixelShader);
    SafeRelease(skyInputLayout);

    SafeRelease(m_lightCBuffer);
    SafeRelease(m_constantBuffer);
    SafeRelease(m_terrainPatchVertexBuffer);

    SafeRelease(device);
    SafeRelease(context);
    SafeRelease(swapChain);
    SafeRelease(renderTargetView);
    SafeRelease(depthTexture);
    SafeRelease(depthView);

    m_textureCache = nullptr;
    ClearTerrainPatch(); // Release terrain-specific resources
}

// ============================================================
// HELPER FUNCTIONS: SAFE RELEASE MACRO (Add to Helpers file)
// ============================================================

void D3D11Renderer::SafeRelease(ID3D11DeviceChild* ptr) {
    if (ptr) {
        ptr->Release();
        ptr = nullptr;
    }
}

// ============================================================
// SHADER & RESOURCE CREATION
// ============================================================

bool D3D11Renderer::CreateTriangleResources()
{
    // Create vertex buffer for rotating triangle
    std::vector<Vertex> verts(3);
    verts[0] = { XMFLOAT3(-0.5f, -0.5f, 0.0f), XMFLOAT2(0.0f, 0.0f) };
    verts[1] = { XMFLOAT3(0.5f, -0.5f, 0.0f), XMFLOAT2(1.0f, 0.0f) };
    verts[2] = { XMFLOAT3(0.0f, 0.5f, 0.0f), XMFLOAT2(0.5f, 1.0f) };

    D3D11_BUFFER_DESC vbd = {};
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = static_cast<UINT>(verts.size() * sizeof(Vertex));
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA vinit = {};
    vinit.pSysMem = verts.data();

    HRESULT hr = device->CreateBuffer(&vbd, &vinit, &vertexBuffer);
    if (FAILED(hr)) {
        LOG_ERROR("Failed to create vertex buffer.");
        return false;
    }

    return true;
}

bool D3D11Renderer::CreateRenderTarget()
{
    DXGI_SWAP_CHAIN_DESC sdc = {};
    sdc.BufferDesc.Width = renderWidth;
    sdc.BufferDesc.Height = renderHeight;
    sdc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sdc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sdc.BufferCount = 1;
    sdc.Windowed = true;

    ID3D11DeviceContext* ctx = context; // Context reference
    HRESULT hr = swapChain->CreateOutputWindow(0, &ctx);

    if (FAILED(hr)) {
        LOG_ERROR("Failed to create render target.");
        return false;
    }

    return true;
}

bool D3D11Renderer::CreateTerrainPatch()
{
    // Initial empty patch creation
    m_terrainVertsX = 0;
    m_terrainVertsZ = 0;
    m_terrainAvailable = false;
    m_terrainPatchVertexCount = 0;

    D3D11_BUFFER_DESC vbd = {};
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = 0;
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    ID3D11Buffer* emptyBuffer = nullptr;
    HRESULT hr = device->CreateBuffer(&vbd, nullptr, &emptyBuffer);
    if (SUCCEEDED(hr)) {
        m_terrainPatchVertexBuffer = emptyBuffer;
        LOG_INFO("Terrain patch buffer created (empty).");
    }

    return true;
}

void D3D11Renderer::CreateGroundShaders()
{
    ID3DBlob* vertexBlob = nullptr;
    ID3DBlob* pixelBlob = nullptr;

    HRESULT hr = CompileShaderFromFile(
        L"shaders/groundVertex.hlsl",
        "vs_main",
        "vs_4_0",
        &vertexBlob
    );

    if (SUCCEEDED(hr)) {
        device->CreateVertexShader(vertexBlob->GetBufferPointer(), nullptr, &groundVertexShader);
        vertexBlob->Release();
    }

    hr = CompileShaderFromFile(
        L"shaders/groundPixel.hlsl",
        "ps_main",
        "ps_4_0",
        &pixelBlob
    );

    if (SUCCEEDED(hr)) {
        device->CreatePixelShader(pixelBlob->GetBufferPointer(), nullptr, &groundPixelShader);
        pixelBlob->Release();

        // Create input layout for terrain vertex format
        DXGI_FORMAT format = DXGI_FORMAT_R32G32B32_FLOAT; // Example: position-only
        ID3D11InputElement* elements[1] = { nullptr };
        UINT strides[1] = { 0 };
        UINT offsets[1] = { 0 };

        elements[0]->Format = format;
        elements[0]->ElementOffset = 0;
        elements[0]->SemanticName = "POSITION";
        elements[0]->SemanticIndex = 0;
        elements[0]->InputSlot = 0;

        hr = D3D11CreateDevice(
            nullptr, D3D_DRIVER_TYPE_NULL, nullptr, 0,
            nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &context
        );

        if (SUCCEEDED(hr)) {
            device->CreateInputLayout(elements, 1, vertexBlob->GetBufferPointer(),
                sizeof(Vertex), &groundInputLayout);
        }
    }
}

void D3D11Renderer::CreateSkyShaders()
{
    ID3DBlob* vertexBlob = nullptr;
    ID3DBlob* pixelBlob = nullptr;

    HRESULT hr = CompileShaderFromFile(
        L"shaders/skyVertex.hlsl",
        "vs_main",
        "vs_4_0",
        &vertexBlob
    );

    if (SUCCEEDED(hr)) {
        device->CreateVertexShader(vertexBlob->GetBufferPointer(), nullptr, &skyVertexShader);
        vertexBlob->Release();
    }

    hr = CompileShaderFromFile(
        L"shaders/skyPixel.hlsl",
        "ps_main",
        "ps_4_0",
        &pixelBlob
    );

    if (SUCCEEDED(hr)) {
        device->CreatePixelShader(pixelBlob->GetBufferPointer(), nullptr, &skyPixelShader);
        pixelBlob->Release();

        // Create input layout for sky vertex format
        DXGI_FORMAT format = DXGI_FORMAT_R32G32B32_FLOAT;
        ID3D11InputElement* elements[1] = { nullptr };

        elements[0]->Format = format;
        hr = D3D11CreateDevice(
            nullptr, D3D_DRIVER_TYPE_NULL, nullptr, 0,
            nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &context
        );

        if (SUCCEEDED(hr)) {
            device->CreateInputLayout(elements, 1, vertexBlob->GetBufferPointer(),
                sizeof(Vertex), &skyInputLayout);
        }
    }
}

HRESULT D3D11Renderer::CompileShaderFromFile(const wchar_t* path, const char* entryPoint,
    const char* target, ID3D11ShaderResourceView** outSRV) {
    // Simplified shader compilation - use real D3DCompile in production
    LOG_INFO("Compiling shader: " + std::string(path));
    return S_OK; // Placeholder for actual HLSL loader logic
}

// ============================================================
// DRAWING FUNCTIONS
// ============================================================

void D3D11Renderer::ClearScreen(float red, float green, float blue, float alpha)
{
    device->ClearRenderTargetView(renderTargetView, { red, green, blue, alpha });
}

void D3D11Renderer::PresentFrame()
{
    HRESULT hr = swapChain->Present(0, 1);
    if (hr == DXGI_ERROR_DEVICERemoved || hr == DXGI_ERROR_DEVICELOST) {
        LOG_ERROR("Device lost. Restart required.");
        Shutdown();
    }
}

void D3D11Renderer::DrawRotatingTriangle(float deltaTime)
{
    // Rotate triangle around center
    float angle = 0.0f;

    // Draw triangle (same as terrain but with rotation logic)
    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // Apply shader states for triangle
    context->VSSetShader(vertexShader, nullptr, 0);
    context->PSSetShader(pixelShader, nullptr, 0);

    context->IASetInputLayout(inputLayout);

    UINT vertexCount = static_cast<UINT>(verts.size());
    context->Draw(vertexCount, 0);
}

void D3D11Renderer::DrawSky()
{
    // Clear screen for sky (dark blue background)
    ClearScreen(0.1f, 0.2f, 0.5f, 1.0f);

    if (!skyVertexShader || !skyPixelShader || !skyInputLayout) {
        LOG_ERROR("Sky shaders not initialized.");
        return;
    }

    // Enable sky shaders
    context->VSSetShader(skyVertexShader, nullptr, 0);
    context->PSSetShader(skyPixelShader, nullptr, 0);
    context->IASetInputLayout(skyInputLayout);

    // Set primitive topology to draw triangles
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // Draw sky quad (simplified - replace with actual geometry)
    UINT vertexCount = 4; // Quad has 4 vertices for D3D11
    context->Draw(vertexCount, 0);
}

void D3D11Renderer::SetCameraPosition(float x, float y, float z)
{
    cameraX = x;
    cameraY = y;
    cameraZ = z;
}

void D3D11Renderer::SetCameraRotation(float yaw, float pitch)
{
    cameraYaw = yaw;
    cameraPitch = pitch;
}

void D3D11Renderer::GetCameraPosition(float& x, float& y, float& z) const
{
    x = cameraX;
    y = cameraY;
    z = cameraZ;
}

void D3D11Renderer::GetCameraRotation(float& yaw, float& pitch) const
{
    yaw = cameraYaw;
    pitch = cameraPitch;
}

void D3D11Renderer::SetSunDirection(float x, float y, float z)
{
    m_lightData.lightDirX = x;
    m_lightData.lightDirY = y;
    m_lightData.lightDirZ = z;
}

float D3D11Renderer::GetAmbientStrength() const
{
    return m_lightData.ambientStrength;
}

void D3D11Renderer::SetAmbientStrength(float a)
{
    m_lightData.ambientStrength = a;
}

bool D3D11Renderer::SetVSyncEnabled(bool enabled)
{
    if (enabled != m_vsyncEnabled) {
        HRESULT hr = swapChain->GetDevice(&device, nullptr);
        if (SUCCEEDED(hr)) {
            device->Release(); // Release old device
        }
        m_vsyncEnabled = enabled;

        hr = D3D11CreateDevice(
            nullptr, D3D_DRIVER_TYPE_NULL, nullptr, 0,
            nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &context
        );

        if (SUCCEEDED(hr)) {
            device->Release(); // Release old device
        }
    }
    return m_vsyncEnabled == enabled;
}

void D3D11Renderer::SetFrameRateLimit(int fps)
{
    m_frameRateLimit = fps;
}

void D3D11Renderer::ApplyGraphicsPreset(GraphicsPreset preset)
{
    m_graphicsPreset = preset;
}

// ============================================================
// TERRAIN RENDERING FUNCTIONS (MAIN SYSTEM!)
// ============================================================

bool D3D11Renderer::RebuildTerrainPatch(const TerrainParams& params)
{
    if (!m_terrainManager) {
        LOG_ERROR("Cannot rebuild terrain: TerrainManager not initialized.");
        return false;
    }

    // Delegate geometry building to manager (manager owns mesh logic)
    return m_terrainManager->RebuildTerrainPatch(params);
}

void D3D11Renderer::DrawGroundPlane()
{
    // Simple ground plane draw call
    if (!m_groundVertexBuffer || !groundVertexShader || !groundPixelShader) {
        LOG_ERROR("Ground resources not initialized.");
        return;
    }

    context->IASetInputLayout(groundInputLayout);
    context->VSSetShader(groundVertexShader, nullptr, 0);
    context->PSSetShader(groundPixelShader, nullptr, 0);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    context->IASetVertexBuffers(0, 1, &m_groundVertexBuffer, &stride, &offset);

    // Draw ground plane (6 vertices for a quad)
    context->Draw(6, 0);
}

void D3D11Renderer::DrawTerrainPatch() const
{
    // 1. Check if terrain manager exists
    if (!m_terrainManager) {
        LOG_ERROR("Cannot draw terrain: TerrainManager not initialized.");
        return;
    }

    // 2. Check if terrain is available (don't rebuild every frame!)
    if (!m_terrainManager->IsTerrainAvailable()) {
        LOG_INFO("Terrain not available - skip this draw call.");
        return;
    }

    // 3. Set up input layout and shaders
    context->IASetInputLayout(groundInputLayout);
    context->VSSetShader(groundVertexShader, nullptr, 0);
    context->PSSetShader(groundPixelShader, nullptr, 0);

    // 4. Bind constant buffer for lighting (register 1)
    if (m_lightCBuffer) {
        context->PSSetConstantBuffers(1, 1, &m_lightCBuffer);
    }

    // 5. Bind texture and sampler if cache is attached
    if (m_textureCache) {
        ID3D11ShaderResourceView* srv = m_textureCache->GetActiveTexture();
        if (srv) {
            context->PSSetShaderResources(0, 1, &srv);

            // Set sampler state for low-poly aesthetic (point filtering)
            if (m_textureSampler) {
                context->PSSetSamplers(0, 1, &m_textureSampler);
            }
        }
    }

    // 6. Set primitive topology to draw triangles
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // 7. Bind vertex buffer from manager (manager owns the mesh data)
    UINT stride = sizeof(D3D11RendererHelpers::Vertex);
    UINT offset = 0;

    ID3D11Buffer* terrainVertexBuffer = m_terrainManager->GetVertexBuffer();
    if (!terrainVertexBuffer) {
        LOG_ERROR("Terrain vertex buffer not allocated!");
        return;
    }

    context->IASetVertexBuffers(0, 1, &terrainVertexBuffer, &stride, &offset);

    // 8. Get vertex count from manager (manager reports how many vertices to draw)
    UINT vertexCount = m_terrainManager->GetVertexCount();

    // 9. Draw the terrain mesh!
    context->Draw(vertexCount, 0);

    // ✅ Success - terrain drawn!
}

float D3D11Renderer::SampleTerrainHeight(float worldX, float worldZ) const
{
    if (!m_terrainManager) {
        return 0.0f;
    }

    return m_terrainManager->SampleTerrainHeight(worldX, worldZ);
}

bool D3D11Renderer::IsTerrainAvailable() const
{
    return m_terrainManager && m_terrainManager->IsTerrainAvailable();
}

// ============================================================
// CAMERA & PHYSICS CONTROL (FOR THIRD-PERSON)
// ============================================================

void D3D11Renderer::SetCameraVelocityY(float velocity)
{
    cameraVelocityY = velocity;
}

float D3D11Renderer::GetCameraVelocityY() const
{
    return cameraVelocityY;
}

void D3D11Renderer::SetIsGrounded(bool grounded)
{
    isGrounded = grounded;
}

bool D3D11Renderer::GetIsGrounded() const
{
    return isGrounded;
}

// ============================================================
// TEXTURE CACHE & CEL SHADING
// ============================================================

void D3D11Renderer::SetTextureCache(TextureCache* cache) { m_textureCache = cache; }

bool D3D11Renderer::SetCelShadingParameters(float count, float minVal, float maxVal,
    float rimAmount, float shadowR, float shadowG, float shadowB,
    float specThreshold) {
    // Cel shading would be enabled here (set shader constants)
    return true;
}

void D3D11Renderer::DrawCharacterOutlinePass(float outlineThickness) {
    // Outline pass for cel-shaded characters
    LOG_INFO("Drawing character outline (placeholder).");
}

#include "D3D11Renderer.hpp"
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#include <iostream>
#include <sstream>
#include <windows.h>
#include "../../logger/Logger.hpp"
#include <vector>
#include <cmath>

using namespace DirectX;

D3D11Renderer::D3D11Renderer()
    : renderWidth(0), renderHeight(0),
    device(nullptr), context(nullptr), swapChain(nullptr),
    renderTargetView(nullptr), featureLevel(D3D_FEATURE_LEVEL_10_0),
    vertexShader(nullptr), pixelShader(nullptr), inputLayout(nullptr),
    vertexBuffer(nullptr), transformConstantBuffer(nullptr), rasterizerState(nullptr), depthTexture(nullptr), depthView(nullptr),
    indexBuffer(nullptr),
    cameraX(0.0f), cameraY(0.0f), cameraZ(-8.0f), // Camera starts farther back
    cameraYaw(static_cast<float>(atan2(0.0f - cameraX, 0.0f - cameraZ))), // Horizontal angle to look at (0, 0, 0)
    cameraPitch(static_cast<float>(atan2(0.0f - cameraY, sqrt(pow(cameraX, 2) + pow(cameraZ, 2))))) // Vertical angle to look at (0, 0, 0)
    , cameraVelocityY(0.0f), isGrounded(true)
{
    


}

bool D3D11Renderer::Initialize(HWND windowHandle, int width, int height)
{
    renderWidth = width;
    renderHeight = height;

    DXGI_SWAP_CHAIN_DESC swapChainDesc{};
    swapChainDesc.BufferCount = 2;
    swapChainDesc.BufferDesc.Width = width;
    swapChainDesc.BufferDesc.Height = height;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.OutputWindow = windowHandle;
    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.Windowed = TRUE;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;

    UINT creationFlags = 0;
#if defined(_DEBUG)
    creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0
    };

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        creationFlags,
        featureLevels,
        (UINT)_countof(featureLevels),
        D3D11_SDK_VERSION,
        &swapChainDesc,
        &swapChain,
        &device,
        &featureLevel,
        &context
    );
    D3D11_TEXTURE2D_DESC depthDesc = {};
    depthDesc.Width = renderWidth;
    depthDesc.Height = renderHeight;
    depthDesc.MipLevels = 1;
    depthDesc.ArraySize = 1;
    depthDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depthDesc.SampleDesc.Count = 1;
    depthDesc.Usage = D3D11_USAGE_DEFAULT;
    depthDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;

    
    hr = device->CreateTexture2D(&depthDesc, nullptr, &depthTexture);
    if (FAILED(hr)) return false;

    hr = device->CreateDepthStencilView(depthTexture, nullptr, &depthView);
    if (FAILED(hr)) return false;
    if (FAILED(hr))
        return false;

    if (!CreateRenderTarget()) return false;
    if (!CreateTriangleResources()) return false;
	CreateGroundShaders();
	CreateSkyShaders();
    
    

    
    CreateGroundPlane();
    if (!CreateTerrainPatch()) return false;
    return true;
    
}

void D3D11Renderer::CreateGroundShaders()
{
    ID3DBlob* vsBlob = nullptr;
    ID3DBlob* psBlob = nullptr;

    // Compile the ground vertex shader
    HRESULT hr = D3DCompileFromFile(L"Shaders/ground_vs.hlsl", nullptr, nullptr, "main", "vs_5_0", 0, 0, &vsBlob, nullptr);
    if (FAILED(hr)) { LOG_ERROR("Failed to compile Shaders/ground_vs.hlsl"); }
    device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &groundVertexShader);

    // Compile the ground pixel shader
    hr = D3DCompileFromFile(L"Shaders/ground_ps.hlsl", nullptr, nullptr, "main", "ps_5_0", 0, 0, &psBlob, nullptr);
    if (FAILED(hr)) { LOG_ERROR("Failed to compile Shaders/ground_ps.hlsl"); }
    device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &groundPixelShader);

    // Create the input layout for the ground plane
    D3D11_INPUT_ELEMENT_DESC groundInputDesc[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    device->CreateInputLayout(
        groundInputDesc, 3,
        vsBlob->GetBufferPointer(),
        vsBlob->GetBufferSize(),
        &groundInputLayout
    );

    if (vsBlob) vsBlob->Release();
    if (psBlob) psBlob->Release();
}
void D3D11Renderer::Shutdown()
{
    if (transformConstantBuffer) { transformConstantBuffer->Release(); transformConstantBuffer = nullptr; }
    if (vertexBuffer) { vertexBuffer->Release(); vertexBuffer = nullptr; }
    if (inputLayout) { inputLayout->Release(); inputLayout = nullptr; }
    if (vertexShader) { vertexShader->Release(); vertexShader = nullptr; }
    if (pixelShader) { pixelShader->Release(); pixelShader = nullptr; }
    if (renderTargetView) { renderTargetView->Release(); renderTargetView = nullptr; }
    if (swapChain) { swapChain->Release(); swapChain = nullptr; }
    if (context) { context->Release(); context = nullptr; }
    if (device) { device->Release(); device = nullptr; }
    if (rasterizerState) { rasterizerState->Release(); rasterizerState = nullptr; }
    if (depthView) { depthView->Release(); depthView = nullptr; }
    if (depthTexture) { depthTexture->Release(); depthTexture = nullptr; }
    if (indexBuffer) { indexBuffer->Release(); indexBuffer = nullptr; }
    if (m_groundVertexBuffer) { m_groundVertexBuffer->Release(); m_groundVertexBuffer = nullptr; }
    if (m_groundIndexBuffer) { m_groundIndexBuffer->Release(); m_groundIndexBuffer = nullptr; }
    if (skyVertexShader) { skyVertexShader->Release(); skyVertexShader = nullptr; }
    if (skyPixelShader) { skyPixelShader->Release(); skyPixelShader = nullptr; }
    if (lightConstantBuffer) { lightConstantBuffer->Release(); lightConstantBuffer = nullptr; }
    if (m_terrainPatchVertexBuffer) { m_terrainPatchVertexBuffer->Release(); m_terrainPatchVertexBuffer = nullptr; }
    if (m_terrainPatchIndexBuffer) { m_terrainPatchIndexBuffer->Release(); m_terrainPatchIndexBuffer  = nullptr; }
    // In Shutdown(), add:
    m_terrainHeights.clear();
    m_terrainAvailable = false;
}

void D3D11Renderer::ClearScreen(float red, float green, float blue, float alpha)
{
    float color[4] = { red, green, blue, alpha };
    context->OMSetRenderTargets(1, &renderTargetView, nullptr);
    context->ClearRenderTargetView(renderTargetView, color);
    context->OMSetRenderTargets(1, &renderTargetView, depthView);
    context->ClearRenderTargetView(renderTargetView, color);
    context->ClearDepthStencilView(depthView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    D3D11_VIEWPORT viewport{};
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = (float)renderWidth;
    viewport.Height = (float)renderHeight;
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    context->RSSetViewports(1, &viewport);
}

void D3D11Renderer::PresentFrame()
{
    swapChain->Present(1, 0);
}

void D3D11Renderer::CreateSkyShaders()
{
    ID3DBlob* vsBlob = nullptr;
    ID3DBlob* psBlob = nullptr;

    // Compile sky vertex shader
    HRESULT hr = D3DCompileFromFile(L"Shaders/sky_vs.hlsl", nullptr, nullptr, "main", "vs_5_0", 0, 0, &vsBlob, nullptr);
    if (FAILED(hr)) { LOG_ERROR("Failed to compile Shaders/sky_vs.hlsl"); }
    device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &skyVertexShader);

    // Compile sky pixel shader
    hr = D3DCompileFromFile(L"Shaders/sky_ps.hlsl", nullptr, nullptr, "main", "ps_5_0", 0, 0, &psBlob, nullptr);
    if (FAILED(hr)) { LOG_ERROR("Failed to compile Shaders/sky_ps.hlsl"); }
    device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &skyPixelShader);

    // No input layout needed for SV_VertexID trick

    if (vsBlob) vsBlob->Release();
    if (psBlob) psBlob->Release();
}

void D3D11Renderer::DrawSky()
{
    context->IASetInputLayout(nullptr);
    context->IASetVertexBuffers(0, 0, nullptr, nullptr, nullptr);
    context->IASetIndexBuffer(nullptr, DXGI_FORMAT_UNKNOWN, 0);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    context->VSSetShader(skyVertexShader, nullptr, 0);
    context->PSSetShader(skyPixelShader, nullptr, 0);

    context->Draw(3, 0);
}
void D3D11Renderer::CreateGroundPlane()
{
    struct Vertex {
        float x, y, z;
        float nx, ny, nz;
        float r, g, b, a;
    };

    Vertex vertices[] = {
        { -1000.0f, -1.0f, -1000.0f, 0.0f, 1.0f, 0.0f, 0.2f, 0.8f, 0.2f, 1.0f },
        {  1000.0f, -1.0f, -1000.0f, 0.0f, 1.0f, 0.0f, 0.2f, 0.8f, 0.2f, 1.0f },
        { -1000.0f, -1.0f,  1000.0f, 0.0f, 1.0f, 0.0f, 0.2f, 0.8f, 0.2f, 1.0f },
        {  1000.0f, -1.0f,  1000.0f, 0.0f, 1.0f, 0.0f, 0.2f, 0.8f, 0.2f, 1.0f },
    };
    unsigned int indices[] = { 0, 2, 1, 1, 2, 3 };
    m_groundIndexCount = 6;

    D3D11_BUFFER_DESC vbd = {};
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = sizeof(vertices);
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA vinit = {};
    vinit.pSysMem = vertices;
    device->CreateBuffer(&vbd, &vinit, &m_groundVertexBuffer);

    D3D11_BUFFER_DESC ibd = {};
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.ByteWidth = sizeof(indices);
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    D3D11_SUBRESOURCE_DATA iinit = {};
    iinit.pSysMem = indices;
    device->CreateBuffer(&ibd, &iinit, &m_groundIndexBuffer);
}

bool D3D11Renderer::CreateTerrainPatch()
{
    // User-reviewed defaults:
    // 200x200 quads => 201x201 vertices
    const int quadsX = 200;
    const int quadsZ = 200;
    const int vertsX = quadsX + 1;
    const int vertsZ = quadsZ + 1;
    const float cellSize = 1.0f;
    const float halfSizeX = (quadsX * cellSize) * 0.5f;
    const float halfSizeZ = (quadsZ * cellSize) * 0.5f;
    const float halfHeightRange = 7.5f; // ~15 total range

    auto sampleHeight = [halfHeightRange](float x, float z) -> float
        {
            float h0 = sinf(x * 0.08f) * cosf(z * 0.08f);   // [-1,1]
            float h1 = sinf((x + z) * 0.03f);               // [-1,1]
            return (h0 * 5.0f) + (h1 * 2.5f);               // approx [-7.5, +7.5]
        };

    std::vector<Vertex> vertices;
    vertices.resize(static_cast<size_t>(vertsX * vertsZ));

    // Build positions + colors for entire grid
    for (int z = 0; z < vertsZ; ++z)
    {
        for (int x = 0; x < vertsX; ++x)
        {
            float worldX = (x * cellSize) - halfSizeX;
            float worldZ = (z * cellSize) - halfSizeZ;
            float worldY = sampleHeight(worldX, worldZ);

            float h01 = (worldY + halfHeightRange) / (halfHeightRange * 2.0f);
            if (h01 < 0.0f) h01 = 0.0f;
            if (h01 > 1.0f) h01 = 1.0f;

            // Low=green, high=rock-ish
            float lowR = 0.15f, lowG = 0.50f, lowB = 0.15f;
            float hiR = 0.45f, hiG = 0.42f, hiB = 0.38f;
            float r = lowR + (hiR - lowR) * h01;
            float g = lowG + (hiG - lowG) * h01;
            float b = lowB + (hiB - lowB) * h01;

            Vertex v{};
            v.x = worldX; v.y = worldY; v.z = worldZ;
            v.nx = 0.0f; v.ny = 1.0f; v.nz = 0.0f;
            v.r = r; v.g = g; v.b = b; v.a = 1.0f;
            vertices[static_cast<size_t>(z * vertsX + x)] = v;
        }
    }

    // Store height grid for sampling (do this once after vertices fully built)
    m_terrainVertsX = vertsX;
    m_terrainVertsZ = vertsZ;
    m_terrainCellSize = cellSize;
    m_terrainHalfSizeX = halfSizeX;
    m_terrainHalfSizeZ = halfSizeZ;
    m_terrainHeights.clear();
    m_terrainHeights.reserve(static_cast<size_t>(vertsX * vertsZ));
    for (int z = 0; z < vertsZ; ++z)
    {
        for (int x = 0; x < vertsX; ++x)
        {
            const Vertex& vv = vertices[static_cast<size_t>(z * vertsX + x)];
            m_terrainHeights.push_back(vv.y);
        }
    }
    m_terrainAvailable = true;

    // Compute normals (finite differences)
    for (int z = 0; z < vertsZ; ++z)
    {
        for (int x = 0; x < vertsX; ++x)
        {
            int xL = (x > 0) ? x - 1 : x;
            int xR = (x < vertsX - 1) ? x + 1 : x;
            int zD = (z > 0) ? z - 1 : z;
            int zU = (z < vertsZ - 1) ? z + 1 : z;

            const Vertex& vL = vertices[static_cast<size_t>(z * vertsX + xL)];
            const Vertex& vR = vertices[static_cast<size_t>(z * vertsX + xR)];
            const Vertex& vD = vertices[static_cast<size_t>(zD * vertsX + x)];
            const Vertex& vU = vertices[static_cast<size_t>(zU * vertsX + x)];

            float dx = vR.y - vL.y;
            float dz = vU.y - vD.y;

            // Up-biased normal
            float nx = -dx;
            float ny = 2.0f;
            float nz = -dz;
            float len = sqrtf(nx * nx + ny * ny + nz * nz);
            if (len > 0.0001f)
            {
                nx /= len; ny /= len; nz /= len;
            }

            Vertex& out = vertices[static_cast<size_t>(z * vertsX + x)];
            out.nx = nx; out.ny = ny; out.nz = nz;
        }
    }

    std::vector<uint32_t> indices;
    indices.reserve(static_cast<size_t>(quadsX * quadsZ * 6));

    for (int z = 0; z < quadsZ; ++z)
    {
        for (int x = 0; x < quadsX; ++x)
        {
            uint32_t i0 = static_cast<uint32_t>(z * vertsX + x);
            uint32_t i1 = static_cast<uint32_t>(z * vertsX + (x + 1));
            uint32_t i2 = static_cast<uint32_t>((z + 1) * vertsX + x);
            uint32_t i3 = static_cast<uint32_t>((z + 1) * vertsX + (x + 1));

            // Winding for LH system
            indices.push_back(i0); indices.push_back(i2); indices.push_back(i1);
            indices.push_back(i1); indices.push_back(i2); indices.push_back(i3);
        }
    }

    m_terrainPatchIndexCount = static_cast<UINT>(indices.size());

    D3D11_BUFFER_DESC vbd{};
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = static_cast<UINT>(vertices.size() * sizeof(Vertex));
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA vinit{};
    vinit.pSysMem = vertices.data();

    HRESULT hr = device->CreateBuffer(&vbd, &vinit, &m_terrainPatchVertexBuffer);
    if (FAILED(hr)) return false;

    D3D11_BUFFER_DESC ibd{};
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.ByteWidth = static_cast<UINT>(indices.size() * sizeof(uint32_t));
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;

    D3D11_SUBRESOURCE_DATA iinit{};
    iinit.pSysMem = indices.data();

    hr = device->CreateBuffer(&ibd, &iinit, &m_terrainPatchIndexBuffer);
    if (FAILED(hr)) return false;

    return true;
}
// Add near other method implementations (after CreateTerrainPatch or before Shutdown)

float D3D11Renderer::SampleTerrainHeight(float worldX, float worldZ) const
{
    if (!m_terrainAvailable || m_terrainVertsX <= 0 || m_terrainVertsZ <= 0)
        return 0.0f;

    // Convert world pos -> grid local coordinates (0..vertsX-1, 0..vertsZ-1)
    float localX = (worldX + m_terrainHalfSizeX) / m_terrainCellSize;
    float localZ = (worldZ + m_terrainHalfSizeZ) / m_terrainCellSize;

    // Clamp to grid extents (so sampling near edges works)
    if (localX < 0.0f) localX = 0.0f;
    if (localZ < 0.0f) localZ = 0.0f;
    if (localX > (float)(m_terrainVertsX - 1)) localX = (float)(m_terrainVertsX - 1);
    if (localZ > (float)(m_terrainVertsZ - 1)) localZ = (float)(m_terrainVertsZ - 1);

    int x0 = static_cast<int>(floorf(localX));
    int z0 = static_cast<int>(floorf(localZ));
    int x1 = (x0 + 1 < m_terrainVertsX) ? x0 + 1 : x0;
    int z1 = (z0 + 1 < m_terrainVertsZ) ? z0 + 1 : z0;

    float sx = localX - (float)x0;
    float sz = localZ - (float)z0;

    auto hAt = [this](int xi, int zi) -> float {
        return m_terrainHeights[static_cast<size_t>(zi * m_terrainVertsX + xi)];
        };

    // Bilinear interp
    float h00 = hAt(x0, z0);
    float h10 = hAt(x1, z0);
    float h01 = hAt(x0, z1);
    float h11 = hAt(x1, z1);

    float hx0 = h00 + (h10 - h00) * sx;
    float hx1 = h01 + (h11 - h01) * sx;
    float h = hx0 + (hx1 - hx0) * sz;
    return h;
}

bool D3D11Renderer::IsTerrainAvailable() const
{
    return m_terrainAvailable;
}
void D3D11Renderer::DrawTerrainPatch()
{
    using namespace DirectX;

    XMMATRIX world = XMMatrixIdentity();

    float lookDirX = cosf(cameraPitch) * sinf(cameraYaw);
    float lookDirY = sinf(cameraPitch);
    float lookDirZ = cosf(cameraPitch) * cosf(cameraYaw);

    XMVECTOR cameraPosition = XMVectorSet(cameraX, cameraY, cameraZ, 1.0f);
    XMVECTOR cameraTarget = XMVectorSet(cameraX + lookDirX, cameraY + lookDirY, cameraZ + lookDirZ, 1.0f);
    XMVECTOR cameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtLH(cameraPosition, cameraTarget, cameraUp);
    XMMATRIX projection = XMMatrixPerspectiveFovLH(
        XM_PIDIV4,
        (float)renderWidth / (float)renderHeight,
        0.1f,
        2000.0f
    );

    TransformConstantBuffer cb{};
    XMStoreFloat4x4(&cb.mvp, XMMatrixTranspose(world * view * projection));
    XMStoreFloat4x4(&cb.world, XMMatrixTranspose(world));
    context->UpdateSubresource(transformConstantBuffer, 0, nullptr, &cb, 0, 0);
    context->VSSetConstantBuffers(0, 1, &transformConstantBuffer);

    LightConstantBuffer lightCB{};
    lightCB.lightDirection = DirectX::XMFLOAT4(0.5f, -1.0f, 0.5f, 0.0f);
    lightCB.lightColor = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
    context->UpdateSubresource(lightConstantBuffer, 0, nullptr, &lightCB, 0, 0);
    context->PSSetConstantBuffers(1, 1, &lightConstantBuffer);

    context->IASetInputLayout(groundInputLayout);
    context->VSSetShader(groundVertexShader, nullptr, 0);
    context->PSSetShader(groundPixelShader, nullptr, 0);

    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    context->IASetVertexBuffers(0, 1, &m_terrainPatchVertexBuffer, &stride, &offset);
    context->IASetIndexBuffer(m_terrainPatchIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    context->DrawIndexed(m_terrainPatchIndexCount, 0, 0);
}

// Simple ground plane: two triangles forming a large quad

void D3D11Renderer::DrawGroundPlane()
{
    using namespace DirectX;

    XMMATRIX world = XMMatrixIdentity();

    float lookDirX = cosf(cameraPitch) * sinf(cameraYaw);
    float lookDirY = sinf(cameraPitch);
    float lookDirZ = cosf(cameraPitch) * cosf(cameraYaw);

    XMVECTOR cameraPosition = XMVectorSet(cameraX, cameraY, cameraZ, 1.0f);
    XMVECTOR cameraTarget = XMVectorSet(cameraX + lookDirX, cameraY + lookDirY, cameraZ + lookDirZ, 1.0f);
    XMVECTOR cameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtLH(cameraPosition, cameraTarget, cameraUp);
    XMMATRIX projection = XMMatrixPerspectiveFovLH(
        XM_PIDIV4,
        (float)renderWidth / (float)renderHeight,
        0.1f,
        1000.0f
    );

    TransformConstantBuffer cb{};
    XMStoreFloat4x4(&cb.mvp, XMMatrixTranspose(world * view * projection));
    XMStoreFloat4x4(&cb.world, XMMatrixTranspose(world));
    context->UpdateSubresource(transformConstantBuffer, 0, nullptr, &cb, 0, 0);
    context->VSSetConstantBuffers(0, 1, &transformConstantBuffer);

    LightConstantBuffer lightCB{};
    lightCB.lightDirection = DirectX::XMFLOAT4(0.5f, -1.0f, 0.5f, 0.0f);
    lightCB.lightColor = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
    context->UpdateSubresource(lightConstantBuffer, 0, nullptr, &lightCB, 0, 0);
    context->PSSetConstantBuffers(1, 1, &lightConstantBuffer);

    context->IASetInputLayout(groundInputLayout);
    context->VSSetShader(groundVertexShader, nullptr, 0);
    context->PSSetShader(groundPixelShader, nullptr, 0);

    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    context->IASetVertexBuffers(0, 1, &m_groundVertexBuffer, &stride, &offset);
    context->IASetIndexBuffer(m_groundIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    context->DrawIndexed(m_groundIndexCount, 0, 0);
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
ID3D11Device* D3D11Renderer::GetDevice() const { return device; }
ID3D11DeviceContext* D3D11Renderer::GetContext() const { return context; }

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

void D3D11Renderer::DrawRotatingTriangle(float deltaTime)
{
    context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R16_UINT, 0);
    context->RSSetState(rasterizerState);

    UINT stride = sizeof(Vertex);
    UINT offset = 0;

    static float time = 0.0f;
    time += deltaTime * 1.0f;

    XMMATRIX world = XMMatrixRotationY(time * 0.7f);

    float lookDirX = cosf(cameraPitch) * sinf(cameraYaw);
    float lookDirY = sinf(cameraPitch);
    float lookDirZ = cosf(cameraPitch) * cosf(cameraYaw);

    XMVECTOR cameraPosition = XMVectorSet(cameraX, cameraY, cameraZ, 1.0f);
    XMVECTOR cameraTarget = XMVectorSet(cameraX + lookDirX, cameraY + lookDirY, cameraZ + lookDirZ, 1.0f);
    XMVECTOR cameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtLH(cameraPosition, cameraTarget, cameraUp);
    XMMATRIX projection = XMMatrixPerspectiveFovLH(
        XM_PIDIV4,
        (float)renderWidth / (float)renderHeight,
        0.1f,
        1000.0f
    );

    TransformConstantBuffer cb{};
    XMStoreFloat4x4(&cb.mvp, XMMatrixTranspose(world * view * projection));
    XMStoreFloat4x4(&cb.world, XMMatrixTranspose(world));
    context->UpdateSubresource(transformConstantBuffer, 0, nullptr, &cb, 0, 0);
    context->VSSetConstantBuffers(0, 1, &transformConstantBuffer);

    LightConstantBuffer lightCB{};
    lightCB.lightDirection = DirectX::XMFLOAT4(0.5f, -1.0f, 0.5f, 0.0f);
    lightCB.lightColor = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
    context->UpdateSubresource(lightConstantBuffer, 0, nullptr, &lightCB, 0, 0);
    context->PSSetConstantBuffers(1, 1, &lightConstantBuffer);

    context->IASetInputLayout(inputLayout);
    context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    context->VSSetShader(vertexShader, nullptr, 0);
    context->PSSetShader(pixelShader, nullptr, 0);

    context->DrawIndexed(36, 0, 0);
}

   

bool D3D11Renderer::CreateRenderTarget()
{
    ID3D11Texture2D* backBuffer = nullptr;
    HRESULT hr = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    if (FAILED(hr))
        return false;

    hr = device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
    backBuffer->Release();

    if (FAILED(hr))
        return false;

    return true;
}

bool D3D11Renderer::CreateTriangleResources()
{
    ID3DBlob* vsBlob = nullptr;
    ID3DBlob* psBlob = nullptr;

    HRESULT hr = CompileShaderFromFile(L"Shaders/basic3d_vs.hlsl", "main", "vs_4_0", &vsBlob);
    if (FAILED(hr)) return false;

    hr = CompileShaderFromFile(L"Shaders/basic3d_ps.hlsl", "main", "ps_4_0", &psBlob);
    if (FAILED(hr)) { vsBlob->Release(); return false; }

    hr = device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

    hr = device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

    D3D11_INPUT_ELEMENT_DESC layout[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    hr = device->CreateInputLayout(layout, 3,
        vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
        &inputLayout);

    vsBlob->Release();
    psBlob->Release();
    if (FAILED(hr)) return false;

    Vertex cubeVertices[] = {
        // Front (+Z)
        { -0.5f, -0.5f,  0.5f,   0, 0, 1,   1, 0, 0, 1 },
        {  0.5f, -0.5f,  0.5f,   0, 0, 1,   0, 1, 0, 1 },
        {  0.5f,  0.5f,  0.5f,   0, 0, 1,   0, 0, 1, 1 },
        { -0.5f,  0.5f,  0.5f,   0, 0, 1,   1, 1, 0, 1 },

        // Back (-Z)
        {  0.5f, -0.5f, -0.5f,   0, 0, -1,  1, 0, 1, 1 },
        { -0.5f, -0.5f, -0.5f,   0, 0, -1,  0, 1, 1, 1 },
        { -0.5f,  0.5f, -0.5f,   0, 0, -1,  1, 1, 1, 1 },
        {  0.5f,  0.5f, -0.5f,   0, 0, -1,  0, 0, 0, 1 },

        // Left (-X)
        { -0.5f, -0.5f, -0.5f,  -1, 0, 0,   1, 0, 0, 1 },
        { -0.5f, -0.5f,  0.5f,  -1, 0, 0,   0, 1, 0, 1 },
        { -0.5f,  0.5f,  0.5f,  -1, 0, 0,   0, 0, 1, 1 },
        { -0.5f,  0.5f, -0.5f,  -1, 0, 0,   1, 1, 0, 1 },

        // Right (+X)
        {  0.5f, -0.5f,  0.5f,   1, 0, 0,   1, 0, 1, 1 },
        {  0.5f, -0.5f, -0.5f,   1, 0, 0,   0, 1, 1, 1 },
        {  0.5f,  0.5f, -0.5f,   1, 0, 0,   1, 1, 1, 1 },
        {  0.5f,  0.5f,  0.5f,   1, 0, 0,   0, 0, 0, 1 },

        // Top (+Y)
        { -0.5f,  0.5f,  0.5f,   0, 1, 0,   1, 0, 0, 1 },
        {  0.5f,  0.5f,  0.5f,   0, 1, 0,   0, 1, 0, 1 },
        {  0.5f,  0.5f, -0.5f,   0, 1, 0,   0, 0, 1, 1 },
        { -0.5f,  0.5f, -0.5f,   0, 1, 0,   1, 1, 0, 1 },

        // Bottom (-Y)
        { -0.5f, -0.5f, -0.5f,   0, -1, 0,  1, 0, 1, 1 },
        {  0.5f, -0.5f, -0.5f,   0, -1, 0,  0, 1, 1, 1 },
        {  0.5f, -0.5f,  0.5f,   0, -1, 0,  1, 1, 1, 1 },
        { -0.5f, -0.5f,  0.5f,   0, -1, 0,  0, 0, 0, 1 },
    };

    unsigned short cubeIndices[] = {
        0,1,2,  2,3,0,      // Front
        4,5,6,  6,7,4,      // Back
        8,9,10, 10,11,8,    // Left
        12,13,14, 14,15,12, // Right
        16,17,18, 18,19,16, // Top
        20,21,22, 22,23,20  // Bottom
    };
   
    
    
    

    D3D11_BUFFER_DESC vertexBufferDesc{};
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof(cubeVertices);
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA vertexData{};
    vertexData.pSysMem = cubeVertices;

   
    
    hr = device->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);
    if (FAILED(hr)) return false;

    D3D11_BUFFER_DESC cbDesc{};
    cbDesc.Usage = D3D11_USAGE_DEFAULT;
    cbDesc.ByteWidth = sizeof(TransformConstantBuffer);
    cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    hr = device->CreateBuffer(&cbDesc, nullptr, &transformConstantBuffer);
    if (FAILED(hr)) return false;

    D3D11_RASTERIZER_DESC rasterDesc{};
    rasterDesc.FillMode = D3D11_FILL_SOLID;
    rasterDesc.CullMode = D3D11_CULL_NONE;
    ID3D11RasterizerState* noCullState = nullptr;
    rasterDesc.DepthClipEnable = TRUE;

    hr = device->CreateRasterizerState(&rasterDesc, &rasterizerState);
    if (FAILED(hr)) return false;
    context->RSSetState(noCullState);
    D3D11_BUFFER_DESC indexBufferDesc{};
    indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    indexBufferDesc.ByteWidth = sizeof(cubeIndices);
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

    D3D11_SUBRESOURCE_DATA indexData{};
    indexData.pSysMem = cubeIndices;

    hr = device->CreateBuffer(&indexBufferDesc, &indexData, &indexBuffer);
    if (FAILED(hr)) return false;
    
    D3D11_BUFFER_DESC lightDesc{};
    lightDesc.Usage = D3D11_USAGE_DEFAULT;
    lightDesc.ByteWidth = sizeof(LightConstantBuffer);
    lightDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    hr = device->CreateBuffer(&lightDesc, nullptr, &lightConstantBuffer);
    if (FAILED(hr)) return false;
    return true;
}

HRESULT D3D11Renderer::CompileShaderFromFile(const wchar_t* path, const char* entryPoint, const char* target, ID3DBlob** outBlob)
{
    UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(_DEBUG)
    flags |= D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

    ID3DBlob* errors = nullptr;
    HRESULT hr = D3DCompileFromFile(
        path,
        nullptr,
        D3D_COMPILE_STANDARD_FILE_INCLUDE,
        entryPoint,
        target,
        flags,
        0,
        outBlob,
        &errors
    );

    if (errors) errors->Release();
    return hr;
}
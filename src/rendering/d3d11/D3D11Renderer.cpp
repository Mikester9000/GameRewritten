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

namespace
{
    template <typename T>
    void SafeRelease(T*& resource)
    {
        if (resource)
        {
            resource->Release();
            resource = nullptr;
        }
    }

    std::string WideToUtf8(const wchar_t* text)
    {
        if (!text)
            return "<null>";

        const int size = WideCharToMultiByte(CP_UTF8, 0, text, -1, nullptr, 0, nullptr, nullptr);
        if (size <= 1)
            return "<invalid>";

        std::vector<char> buffer(static_cast<size_t>(size), '\0');
        WideCharToMultiByte(CP_UTF8, 0, text, -1, buffer.data(), size, nullptr, nullptr);
        return std::string(buffer.data());
    }
}

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
    auto failAndCleanup = [&](const char* message)
        {
            LOG_ERROR(message);
            SafeRelease(vsBlob);
            SafeRelease(psBlob);
            SafeRelease(groundInputLayout);
            SafeRelease(groundVertexShader);
            SafeRelease(groundPixelShader);
        };

    // Compile the ground vertex shader
    HRESULT hr = CompileShaderFromFile(L"Shaders/ground_vs.hlsl", "main", "vs_5_0", &vsBlob);
    if (FAILED(hr) || !vsBlob)
    {
        failAndCleanup("Failed to compile Shaders/ground_vs.hlsl");
        return;
    }

    hr = device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &groundVertexShader);
    if (FAILED(hr) || !groundVertexShader)
    {
        failAndCleanup("Failed to create ground vertex shader");
        return;
    }

    // Compile the ground pixel shader
    hr = CompileShaderFromFile(L"Shaders/ground_ps.hlsl", "main", "ps_5_0", &psBlob);
    if (FAILED(hr) || !psBlob)
    {
        failAndCleanup("Failed to compile Shaders/ground_ps.hlsl");
        return;
    }

    hr = device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &groundPixelShader);
    if (FAILED(hr) || !groundPixelShader)
    {
        failAndCleanup("Failed to create ground pixel shader");
        return;
    }

    // Create the input layout for the ground plane
    D3D11_INPUT_ELEMENT_DESC groundInputDesc[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    hr = device->CreateInputLayout(
        groundInputDesc, 3,
        vsBlob->GetBufferPointer(),
        vsBlob->GetBufferSize(),
        &groundInputLayout
    );
    if (FAILED(hr) || !groundInputLayout)
    {
        failAndCleanup("Failed to create ground input layout");
        return;
    }

    SafeRelease(vsBlob);
    SafeRelease(psBlob);
}
void D3D11Renderer::Shutdown()
{
    SafeRelease(transformConstantBuffer);
    SafeRelease(vertexBuffer);
    SafeRelease(indexBuffer);

    SafeRelease(inputLayout);
    SafeRelease(groundInputLayout);
    SafeRelease(skyInputLayout);

    SafeRelease(vertexShader);
    SafeRelease(pixelShader);
    SafeRelease(groundVertexShader);
    SafeRelease(groundPixelShader);
    SafeRelease(skyVertexShader);
    SafeRelease(skyPixelShader);

    SafeRelease(lightConstantBuffer);

    SafeRelease(m_groundVertexBuffer);
    SafeRelease(m_groundIndexBuffer);
    SafeRelease(m_terrainPatchVertexBuffer);

    SafeRelease(rasterizerState);
    SafeRelease(depthView);
    SafeRelease(depthTexture);
    SafeRelease(renderTargetView);
    SafeRelease(swapChain);
    SafeRelease(context);
    SafeRelease(device);

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

    SafeRelease(vsBlob);
    SafeRelease(psBlob);
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
    // Build the initial terrain for a default grassland cell at origin.
    TerrainParams defaults{};
    defaults.biome        = "grassland";
    defaults.seed         = 12345;
    defaults.cellOriginX  = 0.0f;
    defaults.cellOriginZ  = 0.0f;
    defaults.cellWorldSize = 100.0f;
    defaults.heightScale  = 8.0f;
    defaults.noiseFreq    = 0.08f;
    defaults.noiseFreq2   = 0.03f;
    return RebuildTerrainPatch(defaults);
}

bool D3D11Renderer::RebuildTerrainPatch(const TerrainParams& params)
{
    // Release any existing GPU vertex buffer before rebuilding.
    SafeRelease(m_terrainPatchVertexBuffer);
    m_terrainPatchVertexCount = 0;
    m_terrainAvailable = false;
    m_terrainHeights.clear();

    // 100x100 quads — bold low-poly faces up close, reads as smooth terrain at distance.
    const int quadsX = 100;
    const int quadsZ = 100;
    const int vertsX = quadsX + 1; // 101 verts per row for the height grid
    const int vertsZ = quadsZ + 1;
    const float quadSize = params.cellWorldSize / static_cast<float>(quadsX);

    // Biome colour gradients: low-height colour → high-height colour.
    float lowR, lowG, lowB, hiR, hiG, hiB;
    if (params.biome == "desert")
    {
        lowR = 0.78f; lowG = 0.65f; lowB = 0.35f;
        hiR = 0.90f; hiG = 0.85f; hiB = 0.72f;
    }
    else if (params.biome == "rocky")
    {
        lowR = 0.38f; lowG = 0.36f; lowB = 0.34f;
        hiR = 0.58f; hiG = 0.56f; hiB = 0.52f;
    }
    else if (params.biome == "snow")
    {
        lowR = 0.45f; lowG = 0.47f; lowB = 0.52f;
        hiR = 0.95f; hiG = 0.96f; hiB = 1.00f;
    }
    else // grassland (default)
    {
        lowR = 0.15f; lowG = 0.50f; lowB = 0.15f;
        hiR = 0.45f; hiG = 0.42f; hiB = 0.38f;
    }

    // Biome-specific noise tuning fed by JSON fields.
    float nFreq = params.noiseFreq;
    float hScale = params.heightScale;
    if (params.biome == "desert") { nFreq *= 0.6f; }
    if (params.biome == "rocky") { nFreq *= 1.3f; hScale *= 1.1f; }
    if (params.biome == "snow") { nFreq *= 1.1f; }

    // Seed shifts sample space so each seed produces unique, non-repeating terrain.
    float seedOX = static_cast<float>(params.seed) * 0.12345f;
    float seedOZ = static_cast<float>(params.seed) * 0.09876f;

    // --- 4-octave FBM value noise (no external library needed) ---
    // hashNoise: maps integer grid cell to a pseudo-random float in [-1, 1].
    auto hashNoise = [](int ix, int iz) -> float
        {
            int n = ix * 1619 + iz * 31337;
            n = (n << 13) ^ n;
            n = n * (n * n * 15731 + 789221) + 1376312589;
            return 1.0f - static_cast<float>(n & 0x7fffffff) / 1073741824.0f;
        };

    // smoothNoise: bilinear interpolation with smoothstep curve between hash values.
    auto smoothNoise = [&](float fx, float fz) -> float
        {
            int   ix = static_cast<int>(floorf(fx));
            int   iz = static_cast<int>(floorf(fz));
            float tx = fx - static_cast<float>(ix);
            float tz = fz - static_cast<float>(iz);
            // Smoothstep: eases in/out to remove grid artifacts.
            tx = tx * tx * (3.0f - 2.0f * tx);
            tz = tz * tz * (3.0f - 2.0f * tz);
            float h00 = hashNoise(ix, iz);
            float h10 = hashNoise(ix + 1, iz);
            float h01 = hashNoise(ix, iz + 1);
            float h11 = hashNoise(ix + 1, iz + 1);
            return h00 + (h10 - h00) * tx
                + (h01 - h00) * tz
                + (h11 - h10 - h01 + h00) * tx * tz;
        };

    
    // Each octave: double the frequency, half the amplitude.
        // sampleHeight: stacks 4 octaves (big hills → fine detail).
    // Rocky terrain uses a special diagonal mountain-range shape first,
    // then adds smaller noise on top as surface detail.
    auto sampleHeight = [&](float wx, float wz) -> float
        {
            float sx = wx + seedOX;
            float sz = wz + seedOZ;

            if (params.biome == "rocky")
            {
                const float cellCenterX = params.cellOriginX + params.cellWorldSize * 0.5f;
                const float cellCenterZ = params.cellOriginZ + params.cellWorldSize * 0.5f;
                const float invSqrt2 = 0.70710678f;

                // Local position around the middle of the cell.
                float localX = wx - cellCenterX;
                float localZ = wz - cellCenterZ;

                // Rotate the coordinates 45 degrees so the range runs diagonally.
                float alongRange = (localX + localZ) * invSqrt2;
                float acrossRange = (localX - localZ) * invSqrt2;

                // Wide cross-range falloff creates a broad gentle mountain body.
                float halfRangeWidth = params.cellWorldSize * 0.30f;
                float across01 = 1.0f - (fabsf(acrossRange) / halfRangeWidth);
                if (across01 < 0.0f) across01 = 0.0f;
                if (across01 > 1.0f) across01 = 1.0f;
                across01 = across01 * across01 * (3.0f - 2.0f * across01);

                // Broad variation along the range gives several connected mountain masses.
                float ridgeFreq = (nFreq > 0.0001f) ? nFreq : 0.0001f;
                float alongShape = 0.5f + 0.5f * smoothNoise(
                    alongRange * ridgeFreq + seedOX * 0.01f,
                    seedOZ * 0.01f);
                alongShape = 0.55f + alongShape * 0.45f;

                // Secondary peaks keep the chain from looking too uniform.
                float secondary = 0.5f + 0.5f * smoothNoise(
                    alongRange * (ridgeFreq * 2.2f) + seedOZ * 0.02f,
                    seedOX * 0.02f);
                secondary *= 0.25f;

                // noise_freq2 becomes rocky surface detail instead of the main shape.
                float detailFreq = (params.noiseFreq2 > 0.0001f) ? params.noiseFreq2 : (ridgeFreq * 3.0f);
                float detail = 0.0f;
                float amp = hScale * 0.12f;
                float freq = detailFreq;
                for (int oct = 0; oct < 3; ++oct)
                {
                    detail += smoothNoise(sx * freq, sz * freq) * amp;
                    amp *= 0.5f;
                    freq *= 2.0f;
                }
                detail *= across01;

                float baseRange = across01 * hScale * (alongShape + secondary);
                return baseRange + detail;
            }

            float h = 0.0f;
            float amp = hScale;
            float freq = nFreq;
            for (int oct = 0; oct < 4; ++oct)
            {
                h += smoothNoise(sx * freq, sz * freq) * amp;
                amp *= 0.5f;
                freq *= 2.0f;
            }
            return h;
        };

    // --- Step 1: Build shared height grid for SampleTerrainHeight() ---
    // This lets the camera and forest placement know the terrain Y at any world position.
    m_terrainVertsX = vertsX;
    m_terrainVertsZ = vertsZ;
    m_terrainCellSize = quadSize;
    m_terrainOriginX = params.cellOriginX;
    m_terrainOriginZ = params.cellOriginZ;
    m_terrainHalfSizeX = params.cellWorldSize * 0.5f;
    m_terrainHalfSizeZ = params.cellWorldSize * 0.5f;

    m_terrainHeights.resize(static_cast<size_t>(vertsX * vertsZ));
    for (int z = 0; z < vertsZ; ++z)
    {
        for (int x = 0; x < vertsX; ++x)
        {
            float wx = params.cellOriginX + x * quadSize;
            float wz = params.cellOriginZ + z * quadSize;
            m_terrainHeights[static_cast<size_t>(z * vertsX + x)] = sampleHeight(wx, wz);
        }
    }

    // Helper: fetch height from the grid by grid index.
    auto hAt = [&](int xi, int zi) -> float
        {
            return m_terrainHeights[static_cast<size_t>(zi * vertsX + xi)];
        };

    // Helper: map a height value to a biome colour via the gradient.
    const float halfRange = hScale * 1.5f; // slightly wider than max FBM output for safe clamping
    auto heightToColor = [&](float hy, float& r, float& g, float& b)
        {
            float h01 = (halfRange > 0.0001f) ? (hy + halfRange) / (halfRange * 2.0f) : 0.5f;
            if (h01 < 0.0f) h01 = 0.0f;
            if (h01 > 1.0f) h01 = 1.0f;
            r = lowR + (hiR - lowR) * h01;
            g = lowG + (hiG - lowG) * h01;
            b = lowB + (hiB - lowB) * h01;
        };

    // Helper: normalise a 3-component vector in place.
    auto normalise = [](float& nx, float& ny, float& nz)
        {
            float len = sqrtf(nx * nx + ny * ny + nz * nz);
            if (len > 0.0001f) { nx /= len; ny /= len; nz /= len; }
        };

    // --- Step 2: Build unindexed flat-shaded triangle vertices ---
    // Each quad emits 6 private vertices (2 triangles × 3 verts).
    // Every triangle gets its own computed face normal — gives the PS2 faceted look.
    // Colour is based on the average height of the face centre.
    std::vector<Vertex> triVerts;
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

            float y00 = hAt(x, z);
            float y10 = hAt(x + 1, z);
            float y01 = hAt(x, z + 1);
            float y11 = hAt(x + 1, z + 1);

            // Triangle A: (x,z) → (x,z+1) → (x+1,z)
            {
                float ax = wx0 - wx0, ay = y01 - y00, az = wz1 - wz0; // edge0
                float bx = wx1 - wx0, by = y10 - y00, bz = wz0 - wz0; // edge1
                float nx = ay * bz - az * by;
                float ny = az * bx - ax * bz;
                float nz = ax * by - ay * bx;
                normalise(nx, ny, nz);

                float avgY = (y00 + y01 + y10) / 3.0f;
                float r, g, b;
                heightToColor(avgY, r, g, b);

                Vertex v0{}; v0.x = wx0; v0.y = y00; v0.z = wz0; v0.nx = nx; v0.ny = ny; v0.nz = nz; v0.r = r; v0.g = g; v0.b = b; v0.a = 1.0f;
                Vertex v1{}; v1.x = wx0; v1.y = y01; v1.z = wz1; v1.nx = nx; v1.ny = ny; v1.nz = nz; v1.r = r; v1.g = g; v1.b = b; v1.a = 1.0f;
                Vertex v2{}; v2.x = wx1; v2.y = y10; v2.z = wz0; v2.nx = nx; v2.ny = ny; v2.nz = nz; v2.r = r; v2.g = g; v2.b = b; v2.a = 1.0f;
                triVerts.push_back(v0);
                triVerts.push_back(v1);
                triVerts.push_back(v2);
            }

            // Triangle B: (x+1,z) → (x,z+1) → (x+1,z+1)
            {
                float ax = wx0 - wx1, ay = y01 - y10, az = wz1 - wz0; // edge0
                float bx = wx1 - wx1, by = y11 - y10, bz = wz1 - wz0; // edge1
                float nx = ay * bz - az * by;
                float ny = az * bx - ax * bz;
                float nz = ax * by - ay * bx;
                normalise(nx, ny, nz);

                float avgY = (y10 + y01 + y11) / 3.0f;
                float r, g, b;
                heightToColor(avgY, r, g, b);

                Vertex v0{}; v0.x = wx1; v0.y = y10; v0.z = wz0; v0.nx = nx; v0.ny = ny; v0.nz = nz; v0.r = r; v0.g = g; v0.b = b; v0.a = 1.0f;
                Vertex v1{}; v1.x = wx0; v1.y = y01; v1.z = wz1; v1.nx = nx; v1.ny = ny; v1.nz = nz; v1.r = r; v1.g = g; v1.b = b; v1.a = 1.0f;
                Vertex v2{}; v2.x = wx1; v2.y = y11; v2.z = wz1; v2.nx = nx; v2.ny = ny; v2.nz = nz; v2.r = r; v2.g = g; v2.b = b; v2.a = 1.0f;
                triVerts.push_back(v0);
                triVerts.push_back(v1);
                triVerts.push_back(v2);
            }
        }
    }

    m_terrainPatchVertexCount = static_cast<UINT>(triVerts.size());

    // Upload unindexed vertices to GPU — no index buffer needed for flat shading.
    D3D11_BUFFER_DESC vbd{};
    vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = static_cast<UINT>(triVerts.size() * sizeof(Vertex));
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA vinit{};
    vinit.pSysMem = triVerts.data();
    HRESULT hr = device->CreateBuffer(&vbd, &vinit, &m_terrainPatchVertexBuffer);
    if (FAILED(hr)) return false;

    // Both height grid and GPU buffer are ready — terrain is available.
    m_terrainAvailable = true;
    return true;
}

void D3D11Renderer::ClearTerrainPatch()
{
    SafeRelease(m_terrainPatchVertexBuffer);
    
    
    m_terrainHeights.clear();
    m_terrainAvailable = false;
}

float D3D11Renderer::SampleTerrainHeight(float worldX, float worldZ) const
{
    if (!m_terrainAvailable || m_terrainVertsX <= 0 || m_terrainVertsZ <= 0)
        return 0.0f;

    // Convert world pos → local grid index using the cell origin.
    float localX = (worldX - m_terrainOriginX) / m_terrainCellSize;
    float localZ = (worldZ - m_terrainOriginZ) / m_terrainCellSize;

    // Clamp to grid extents so sampling near/outside edges still works.
    if (localX < 0.0f) localX = 0.0f;
    if (localZ < 0.0f) localZ = 0.0f;
    if (localX > static_cast<float>(m_terrainVertsX - 1)) localX = static_cast<float>(m_terrainVertsX - 1);
    if (localZ > static_cast<float>(m_terrainVertsZ - 1)) localZ = static_cast<float>(m_terrainVertsZ - 1);

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
    
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    
    context->Draw(m_terrainPatchVertexCount, 0);
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
    SafeRelease(backBuffer);

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
    if (FAILED(hr)) { SafeRelease(vsBlob); return false; }

    hr = device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader);
    if (FAILED(hr)) { SafeRelease(vsBlob); SafeRelease(psBlob); return false; }

    hr = device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader);
    if (FAILED(hr)) { SafeRelease(vsBlob); SafeRelease(psBlob); return false; }

    D3D11_INPUT_ELEMENT_DESC layout[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    hr = device->CreateInputLayout(layout, 3,
        vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
        &inputLayout);

    SafeRelease(vsBlob);
    SafeRelease(psBlob);
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

    if (FAILED(hr))
    {
        std::ostringstream message;
        message << "Shader compile failed: path=" << WideToUtf8(path)
            << ", entry=" << (entryPoint ? entryPoint : "<null>")
            << ", target=" << (target ? target : "<null>");

        if (errors && errors->GetBufferPointer() && errors->GetBufferSize() > 0)
        {
            message << ", errors="
                << std::string(
                    static_cast<const char*>(errors->GetBufferPointer()),
                    static_cast<size_t>(errors->GetBufferSize()));
        }

        LOG_ERROR(message.str());
    }

    SafeRelease(errors);
    return hr;
}

#include "D3D11Renderer.hpp"
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#include <iostream>
#include <sstream>
#include <windows.h>

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
    return true;
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

void D3D11Renderer::DrawRotatingTriangle()
{
    context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R16_UINT, 0);
    context->RSSetState(rasterizerState);
    UINT stride = sizeof(Vertex);
    UINT offset = 0;

    static float time = 0.0f;
    time += 0.01f;

    XMMATRIX world = XMMatrixRotationY(time * 0.7f);

    // Corrected cameraTarget and cameraUp definitions
    XMVECTOR cameraPosition = XMVectorSet(cameraX, cameraY, cameraZ, 1.0f);
    XMVECTOR cameraTarget = XMVectorSet(
            cameraX + cosf(cameraPitch) * sinf(cameraYaw),
            cameraY + sinf(cameraPitch),
            cameraZ + cosf(cameraPitch) * cosf(cameraYaw),
            1.0f
        );
    
    
    XMVECTOR cameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtLH(cameraPosition, cameraTarget, cameraUp);

    XMMATRIX projection = XMMatrixPerspectiveFovLH(
        XM_PIDIV4,
        (float)renderWidth / (float)renderHeight,
        0.1f,
        100.0f
    );

    TransformConstantBuffer cb{};
    XMStoreFloat4x4(&cb.mvp, XMMatrixTranspose(world * view * projection));
    context->UpdateSubresource(transformConstantBuffer, 0, nullptr, &cb, 0, 0);
    context->VSSetConstantBuffers(0, 1, &transformConstantBuffer);
    context->IASetInputLayout(inputLayout);
    context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    context->VSSetShader(vertexShader, nullptr, 0);
    context->PSSetShader(pixelShader, nullptr, 0);
    context->DrawIndexed(36, 0, 0);

    std::ostringstream debugStream;
    debugStream << "cameraYaw: " << cameraYaw << ", cameraPitch: " << cameraPitch << "\n";
    debugStream << "cameraX: " << cameraX << ", cameraY: " << cameraY << ", cameraZ: " << cameraZ << "\n";
    OutputDebugStringA(debugStream.str().c_str());


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

    hr = CompileShaderFromFile(L"Shaders/triangle_ps.hlsl", "main", "ps_4_0", &psBlob);
    if (FAILED(hr)) { vsBlob->Release(); return false; }

    hr = device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

    hr = device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

    D3D11_INPUT_ELEMENT_DESC layout[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    hr = device->CreateInputLayout(layout, 2,
        vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
        &inputLayout);

    vsBlob->Release();
    psBlob->Release();
    if (FAILED(hr)) return false;

    Vertex cubeVertices[8] = {
        // x, y, z,    r, g, b, a
        { -0.5f, -0.5f, -0.5f,  1, 0, 0, 1 }, // 0
        {  0.5f, -0.5f, -0.5f,  0, 1, 0, 1 }, // 1
        {  0.5f,  0.5f, -0.5f,  0, 0, 1, 1 }, // 2
        { -0.5f,  0.5f, -0.5f,  1, 1, 0, 1 }, // 3
        { -0.5f, -0.5f,  0.5f,  1, 0, 1, 1 }, // 4
        {  0.5f, -0.5f,  0.5f,  0, 1, 1, 1 }, // 5
        {  0.5f,  0.5f,  0.5f,  1, 1, 1, 1 }, // 6
        { -0.5f,  0.5f,  0.5f,  0, 0, 0, 1 }, // 7
        
   
    
    };
    

    D3D11_BUFFER_DESC vertexBufferDesc{};
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof(cubeVertices);
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA vertexData{};
    vertexData.pSysMem = cubeVertices;

    unsigned short cubeIndices[36] = {
    0,1,2,  2,3,0, // back
    4,5,6,  6,7,4, // front
    0,4,7,  7,3,0, // left
    1,5,6,  6,2,1, // right
    3,2,6,  6,7,3, // top
    0,1,5,  5,4,0  // bottom
    };
    
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
    rasterDesc.DepthClipEnable = TRUE;

    hr = device->CreateRasterizerState(&rasterDesc, &rasterizerState);
    if (FAILED(hr)) return false;
    
    D3D11_BUFFER_DESC indexBufferDesc{};
    indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    indexBufferDesc.ByteWidth = sizeof(cubeIndices);
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

    D3D11_SUBRESOURCE_DATA indexData{};
    indexData.pSysMem = cubeIndices;

    hr = device->CreateBuffer(&indexBufferDesc, &indexData, &indexBuffer);
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
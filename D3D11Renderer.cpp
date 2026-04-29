// D3D11Renderer.cpp
// Minimal D3D11 setup: device, swap chain, render target, clear screen.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include<d3dcompiler.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

class D3D11Renderer
{
public:
    bool Init(HWND hwnd, int width, int height)
    {
        m_width = width;
        m_height = height;

        DXGI_SWAP_CHAIN_DESC scd{};
        scd.BufferCount = 2; // double buffering
        scd.BufferDesc.Width = width;
        scd.BufferDesc.Height = height;
        scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        scd.OutputWindow = hwnd;
        scd.SampleDesc.Count = 1;
        scd.Windowed = TRUE;
        scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

        UINT flags = 0;
#if defined(_DEBUG)
        flags |= D3D11_CREATE_DEVICE_DEBUG; // if the debug layer is available
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
            flags,
            featureLevels,
            (UINT)_countof(featureLevels),
            D3D11_SDK_VERSION,
            &scd,
            &m_swapChain,
            &m_device,
            &m_featureLevel,
            &m_context
        );

        if (FAILED(hr))
            return false;

        if (!CreateBackBufferRTV()) return false;
        if (!CreateTriangleResources()) return false;
        return true;
    }

    void Shutdown()
    {
        if (m_vertexBuffer) { m_vertexBuffer->Release(); m_vertexBuffer = nullptr; }
        if (m_inputLayout) { m_inputLayout->Release();  m_inputLayout = nullptr; }
        if (m_vs) { m_vs->Release();           m_vs = nullptr; }
        if (m_ps) { m_ps->Release();           m_ps = nullptr; }
        if (m_rtv) { m_rtv->Release(); m_rtv = nullptr; }
        if (m_swapChain) { m_swapChain->Release(); m_swapChain = nullptr; }
        if (m_context) { m_context->Release(); m_context = nullptr; }
        if (m_device) { m_device->Release(); m_device = nullptr; }

    }

    void Clear(float r, float g, float b, float a)
    {
        float color[4] = { r, g, b, a };
        m_context->OMSetRenderTargets(1, &m_rtv, nullptr);
        m_context->ClearRenderTargetView(m_rtv, color);

        D3D11_VIEWPORT vp{};
        vp.TopLeftX = 0;
        vp.TopLeftY = 0;
        vp.Width = (float)m_width;
        vp.Height = (float)m_height;
        vp.MinDepth = 0.0f;
        vp.MaxDepth = 1.0f;
        m_context->RSSetViewports(1, &vp);
    }

    void Present()
    {
        // vsync off (0) so it runs even on weird setups; can switch to 1 later.
        m_swapChain->Present(1, 0);
    }
    
    void DrawTriangle()
    {
        UINT stride = sizeof(Vertex);
        UINT offset = 0;

        m_context->IASetInputLayout(m_inputLayout);
        m_context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
        m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

        m_context->VSSetShader(m_vs, nullptr, 0);
        m_context->PSSetShader(m_ps, nullptr, 0);

        m_context->Draw(3, 0);
    }
private:
    
    struct Vertex
    {
        float x, y, z;
        float r, g, b, a;
    };
    
    bool CreateBackBufferRTV()
    {
        ID3D11Texture2D* backBuffer = nullptr;
        HRESULT hr = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
        if (FAILED(hr))
            return false;

        hr = m_device->CreateRenderTargetView(backBuffer, nullptr, &m_rtv);
        backBuffer->Release();

        if (FAILED(hr))
            return false;

        return true;
    }
    
    bool CreateTriangleResources()
    {
        ID3DBlob* vsBlob = nullptr;
        ID3DBlob* psBlob = nullptr;

        HRESULT hr = CompileShaderFromFile(L"Shaders/triangle_vs.hlsl", "main", "vs_4_0", &vsBlob);
        if (FAILED(hr)) return false;

        hr = CompileShaderFromFile(L"Shaders/triangle_ps.hlsl", "main", "ps_4_0", &psBlob);
        if (FAILED(hr)) { vsBlob->Release(); return false; }

        hr = m_device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &m_vs);
        if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

        hr = m_device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_ps);
        if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

        D3D11_INPUT_ELEMENT_DESC layout[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        hr = m_device->CreateInputLayout(layout, 2,
            vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
            &m_inputLayout);

        vsBlob->Release();
        psBlob->Release();
        if (FAILED(hr)) return false;

        Vertex verts[3] = {
            {  0.0f,  0.5f, 0.0f,  1, 0, 0, 1 },
            {  0.5f, -0.5f, 0.0f,  0, 1, 0, 1 },
            { -0.5f, -0.5f, 0.0f,  0, 0, 1, 1 },
        };

        D3D11_BUFFER_DESC bd{};
        bd.Usage = D3D11_USAGE_DEFAULT;
        bd.ByteWidth = sizeof(verts);
        bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

        D3D11_SUBRESOURCE_DATA init{};
        init.pSysMem = verts;

        hr = m_device->CreateBuffer(&bd, &init, &m_vertexBuffer);
        if (FAILED(hr)) return false;

        return true;
    }
private:
    int m_width = 0;
    int m_height = 0;

    ID3D11Device* m_device = nullptr;
    ID3D11DeviceContext* m_context = nullptr;
    IDXGISwapChain* m_swapChain = nullptr;
    ID3D11RenderTargetView* m_rtv = nullptr;
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_10_0;
    ID3D11VertexShader* m_vs = nullptr;
    ID3D11PixelShader* m_ps = nullptr;
    ID3D11InputLayout* m_inputLayout = nullptr;
    ID3D11Buffer* m_vertexBuffer = nullptr;

    static HRESULT CompileShaderFromFile(
        const wchar_t* path,
        const char* entryPoint,
        const char* target,
        ID3DBlob** outBlob
    )
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
};
// PrimitiveRenderer.cpp
// Renders multi-part primitive (box) prefab instances via Direct3D 11.

#include "PrimitiveRenderer.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../logger/Logger.hpp"

#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <cmath>

#pragma comment(lib, "d3dcompiler.lib")

using namespace DirectX;

// ---------------------------------------------------------------------------
// Constant buffer layout (shared between VS and PS via slot b0).
// Total = 64 + 64 + 16 = 144 bytes (multiple of 16 — valid for D3D11).
// ---------------------------------------------------------------------------
struct PrimCB
{
    XMFLOAT4X4 mvp;        // model-view-projection (row-major, transposed for HLSL)
    XMFLOAT4X4 world;      // world matrix (for normal transform + world-pos gradient)
    XMFLOAT4   tintColor;  // per-part RGBA color
};

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------
bool PrimitiveRenderer::CreateShaders(const wchar_t* vsPath, const wchar_t* psPath,
                                       ID3D11VertexShader** outVS, ID3D11PixelShader** outPS,
                                       ID3DBlob** outVSBlob)
{
    ID3DBlob* vsBlob = nullptr;
    ID3DBlob* psBlob = nullptr;
    ID3DBlob* errBlob = nullptr;

    HRESULT hr = D3DCompileFromFile(vsPath, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "main", "vs_4_0", 0, 0, &vsBlob, &errBlob);
    if (FAILED(hr))
    {
        if (errBlob)
        {
            LOG_ERROR(std::string("PrimitiveRenderer VS compile error: ")
                + static_cast<const char*>(errBlob->GetBufferPointer()));
            errBlob->Release();
        }
        return false;
    }

    hr = D3DCompileFromFile(psPath, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "main", "ps_4_0", 0, 0, &psBlob, &errBlob);
    if (FAILED(hr))
    {
        vsBlob->Release();
        if (errBlob)
        {
            LOG_ERROR(std::string("PrimitiveRenderer PS compile error: ")
                + static_cast<const char*>(errBlob->GetBufferPointer()));
            errBlob->Release();
        }
        return false;
    }

    hr = m_device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
                                       nullptr, outVS);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

    hr = m_device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(),
                                      nullptr, outPS);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

    psBlob->Release();
    *outVSBlob = vsBlob; // caller must Release this
    return true;
}

// ---------------------------------------------------------------------------
// Initialize
// ---------------------------------------------------------------------------
bool PrimitiveRenderer::Initialize(D3D11Renderer& renderer)
{
    m_device  = renderer.GetDevice();
    m_context = renderer.GetContext();
    if (!m_device || !m_context) return false;

    // --- Compile prim shaders ---
    ID3DBlob* primVSBlob = nullptr;
    if (!CreateShaders(L"Shaders/prim_vs.hlsl", L"Shaders/prim_ps.hlsl",
                       &m_primVS, &m_primPS, &primVSBlob))
    {
        LOG_ERROR("PrimitiveRenderer: failed to compile prim shaders.");
        return false;
    }

    // --- Compile tree shaders ---
    ID3DBlob* treeVSBlob = nullptr;
    if (!CreateShaders(L"Shaders/tree_vs.hlsl", L"Shaders/tree_ps.hlsl",
                       &m_treeVS, &m_treePS, &treeVSBlob))
    {
        LOG_WARN("PrimitiveRenderer: failed to compile tree shaders; trees will use prim shaders.");
        treeVSBlob = nullptr;
    }

    // --- Input layout (POSITION + NORMAL + COLOR, 40 bytes/vertex) ---
    D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    HRESULT hr = m_device->CreateInputLayout(layoutDesc, 3,
        primVSBlob->GetBufferPointer(), primVSBlob->GetBufferSize(), &m_layout);
    primVSBlob->Release();
    if (treeVSBlob) treeVSBlob->Release();
    if (FAILED(hr)) return false;

    // --- Unit cube mesh (all-white vertex colors so tintColor drives appearance) ---
    struct V { float x, y, z; float nx, ny, nz; float r, g, b, a; };
    static const V cubeVerts[] = {
        // Front  (+Z face, normal 0,0,+1)
        { -0.5f,-0.5f, 0.5f, 0,0,1, 1,1,1,1 }, {  0.5f,-0.5f, 0.5f, 0,0,1, 1,1,1,1 },
        {  0.5f, 0.5f, 0.5f, 0,0,1, 1,1,1,1 }, { -0.5f, 0.5f, 0.5f, 0,0,1, 1,1,1,1 },
        // Back   (-Z face)
        {  0.5f,-0.5f,-0.5f, 0,0,-1, 1,1,1,1 }, { -0.5f,-0.5f,-0.5f, 0,0,-1, 1,1,1,1 },
        { -0.5f, 0.5f,-0.5f, 0,0,-1, 1,1,1,1 }, {  0.5f, 0.5f,-0.5f, 0,0,-1, 1,1,1,1 },
        // Left   (-X face)
        { -0.5f,-0.5f,-0.5f,-1,0,0, 1,1,1,1 }, { -0.5f,-0.5f, 0.5f,-1,0,0, 1,1,1,1 },
        { -0.5f, 0.5f, 0.5f,-1,0,0, 1,1,1,1 }, { -0.5f, 0.5f,-0.5f,-1,0,0, 1,1,1,1 },
        // Right  (+X face)
        {  0.5f,-0.5f, 0.5f, 1,0,0, 1,1,1,1 }, {  0.5f,-0.5f,-0.5f, 1,0,0, 1,1,1,1 },
        {  0.5f, 0.5f,-0.5f, 1,0,0, 1,1,1,1 }, {  0.5f, 0.5f, 0.5f, 1,0,0, 1,1,1,1 },
        // Top    (+Y face)
        { -0.5f, 0.5f, 0.5f, 0,1,0, 1,1,1,1 }, {  0.5f, 0.5f, 0.5f, 0,1,0, 1,1,1,1 },
        {  0.5f, 0.5f,-0.5f, 0,1,0, 1,1,1,1 }, { -0.5f, 0.5f,-0.5f, 0,1,0, 1,1,1,1 },
        // Bottom (-Y face)
        { -0.5f,-0.5f,-0.5f, 0,-1,0, 1,1,1,1 }, {  0.5f,-0.5f,-0.5f, 0,-1,0, 1,1,1,1 },
        {  0.5f,-0.5f, 0.5f, 0,-1,0, 1,1,1,1 }, { -0.5f,-0.5f, 0.5f, 0,-1,0, 1,1,1,1 },
    };
    static const unsigned short cubeIndices[] = {
         0, 1, 2,  2, 3, 0,   4, 5, 6,  6, 7, 4,
         8, 9,10, 10,11, 8,  12,13,14, 14,15,12,
        16,17,18, 18,19,16,  20,21,22, 22,23,20
    };
    m_indexCount = 36;

    D3D11_BUFFER_DESC vbd{}; vbd.Usage = D3D11_USAGE_DEFAULT;
    vbd.ByteWidth = sizeof(cubeVerts); vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA vi{}; vi.pSysMem = cubeVerts;
    hr = m_device->CreateBuffer(&vbd, &vi, &m_vb);
    if (FAILED(hr)) return false;

    D3D11_BUFFER_DESC ibd{}; ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.ByteWidth = sizeof(cubeIndices); ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    D3D11_SUBRESOURCE_DATA ii{}; ii.pSysMem = cubeIndices;
    hr = m_device->CreateBuffer(&ibd, &ii, &m_ib);
    if (FAILED(hr)) return false;

    // --- Constant buffer ---
    D3D11_BUFFER_DESC cbd{}; cbd.Usage = D3D11_USAGE_DEFAULT;
    cbd.ByteWidth = sizeof(PrimCB); cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    hr = m_device->CreateBuffer(&cbd, nullptr, &m_cb);
    if (FAILED(hr)) return false;

    LOG_INFO("PrimitiveRenderer: GPU resources initialized.");
    return true;
}

// ---------------------------------------------------------------------------
// Shutdown
// ---------------------------------------------------------------------------
void PrimitiveRenderer::Shutdown()
{
    if (m_cb)      { m_cb->Release();      m_cb      = nullptr; }
    if (m_ib)      { m_ib->Release();      m_ib      = nullptr; }
    if (m_vb)      { m_vb->Release();      m_vb      = nullptr; }
    if (m_layout)  { m_layout->Release();  m_layout  = nullptr; }
    if (m_primPS)  { m_primPS->Release();  m_primPS  = nullptr; }
    if (m_primVS)  { m_primVS->Release();  m_primVS  = nullptr; }
    if (m_treePS)  { m_treePS->Release();  m_treePS  = nullptr; }
    if (m_treeVS)  { m_treeVS->Release();  m_treeVS  = nullptr; }
    m_worldParts.clear();
    m_runtimeParts.clear();
    m_device  = nullptr;
    m_context = nullptr;
}

// ---------------------------------------------------------------------------
// AddInstanceToBucket
// ---------------------------------------------------------------------------
void PrimitiveRenderer::AddInstanceToBucket(std::vector<DrawPart>& bucket,
                                            const PrimitivePrefab& prefab,
                                            float x, float y, float z,
                                            float yaw, float scale)
{
    bool isTree = (prefab.category == "tree");

    for (const auto& part : prefab.parts)
    {
        // Rotate the part's local offset around Y by the instance yaw.
        float cosY = cosf(yaw), sinY = sinf(yaw);
        float rotOffX = part.offsetX * cosY - part.offsetZ * sinY;
        float rotOffZ = part.offsetX * sinY + part.offsetZ * cosY;

        DrawPart dp;
        dp.worldX   = x;
        dp.worldY   = y;
        dp.worldZ   = z;
        dp.offsetX  = rotOffX;
        dp.offsetY  = part.offsetY;  // Y offset is not rotated
        dp.offsetZ  = rotOffZ;
        dp.scaleX   = part.scaleX * scale;
        dp.scaleY   = part.scaleY * scale;
        dp.scaleZ   = part.scaleZ * scale;
        dp.yaw      = yaw;
        dp.r        = part.r;
        dp.g        = part.g;
        dp.b        = part.b;
        dp.a        = part.a;
        dp.isTree   = isTree;
        bucket.push_back(dp);
    }
}

// ---------------------------------------------------------------------------
// AddWorldInstance
// ---------------------------------------------------------------------------
void PrimitiveRenderer::AddWorldInstance(const PrimitivePrefab& prefab,
                                         float x, float y, float z,
                                         float yaw, float scale)
{
    AddInstanceToBucket(m_worldParts, prefab, x, y, z, yaw, scale);
}

// ---------------------------------------------------------------------------
// ClearWorldInstances
// ---------------------------------------------------------------------------
void PrimitiveRenderer::ClearWorldInstances()
{
    m_worldParts.clear();
}

// ---------------------------------------------------------------------------
// AddRuntimeInstance
// ---------------------------------------------------------------------------
void PrimitiveRenderer::AddRuntimeInstance(const PrimitivePrefab& prefab,
                                           float x, float y, float z,
                                           float yaw, float scale)
{
    AddInstanceToBucket(m_runtimeParts, prefab, x, y, z, yaw, scale);
}

// ---------------------------------------------------------------------------
// ClearRuntimeInstances
// ---------------------------------------------------------------------------
void PrimitiveRenderer::ClearRuntimeInstances()
{
    m_runtimeParts.clear();
}

// ---------------------------------------------------------------------------
// Draw
// ---------------------------------------------------------------------------
void PrimitiveRenderer::Draw(const D3D11Renderer& renderer)
{
    if ((m_worldParts.empty() && m_runtimeParts.empty()) || !m_device || !m_context) return;

    // Build camera matrices the same way Forest and the terrain renderer do.
    float camX, camY, camZ; renderer.GetCameraPosition(camX, camY, camZ);
    float yaw, pitch;        renderer.GetCameraRotation(yaw, pitch);

    XMVECTOR camPos    = XMVectorSet(camX, camY, camZ, 1.0f);
    XMVECTOR camTarget = XMVectorSet(
        camX + cosf(pitch) * sinf(yaw),
        camY + sinf(pitch),
        camZ + cosf(pitch) * cosf(yaw), 1.0f);
    XMVECTOR camUp     = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtLH(camPos, camTarget, camUp);
    XMMATRIX proj = XMMatrixPerspectiveFovLH(
        XM_PIDIV4,
        static_cast<float>(renderer.GetRenderWidth()) /
        static_cast<float>(renderer.GetRenderHeight()),
        0.1f, 2000.0f);

    // Shared pipeline state.
    UINT stride = sizeof(float) * 10; // 3+3+4 = 10 floats per vertex, 40 bytes total
    UINT offset = 0;
    m_context->IASetInputLayout(m_layout);
    m_context->IASetVertexBuffers(0, 1, &m_vb, &stride, &offset);
    m_context->IASetIndexBuffer(m_ib, DXGI_FORMAT_R16_UINT, 0);
    m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    ID3D11Buffer* lightCBuffer = renderer.GetLightConstantBuffer();
    if (lightCBuffer)
        m_context->PSSetConstantBuffers(1, 1, &lightCBuffer);

    ID3D11VertexShader* activeVS = nullptr;
    ID3D11PixelShader*  activePS = nullptr;

    auto drawParts = [&](const std::vector<DrawPart>& parts)
    {
        for (const auto& dp : parts)
        {
            // Select shader pair.
            ID3D11VertexShader* wantVS = (dp.isTree && m_treeVS) ? m_treeVS : m_primVS;
            ID3D11PixelShader*  wantPS = (dp.isTree && m_treePS) ? m_treePS : m_primPS;
            if (wantVS != activeVS) { m_context->VSSetShader(wantVS, nullptr, 0); activeVS = wantVS; }
            if (wantPS != activePS) { m_context->PSSetShader(wantPS, nullptr, 0); activePS = wantPS; }

            // Build world matrix: scale → rotate (Y axis) → translate to (world + offset).
            // The offset was already rotated by yaw in AddInstanceToBucket, so rotation here
            // only affects cube faces/normals — matching placement orientation.
            XMMATRIX scaleMat = XMMatrixScaling(dp.scaleX, dp.scaleY, dp.scaleZ);
            XMMATRIX rotMat = XMMatrixRotationY(dp.yaw);
            XMMATRIX transMat = XMMatrixTranslation(
                dp.worldX + dp.offsetX,
                dp.worldY + dp.offsetY,
                dp.worldZ + dp.offsetZ);
            XMMATRIX worldMat = scaleMat * rotMat * transMat;

            // Fill constant buffer.
            PrimCB cb;
            XMStoreFloat4x4(&cb.mvp, XMMatrixTranspose(worldMat * view * proj));
            XMStoreFloat4x4(&cb.world, XMMatrixTranspose(worldMat));
            cb.tintColor = { dp.r, dp.g, dp.b, dp.a };

            m_context->UpdateSubresource(m_cb, 0, nullptr, &cb, 0, 0);
            m_context->VSSetConstantBuffers(0, 1, &m_cb);
            m_context->PSSetConstantBuffers(0, 1, &m_cb);

            m_context->DrawIndexed(m_indexCount, 0, 0);
        }
    };

    drawParts(m_worldParts);
    drawParts(m_runtimeParts);
}

// ============================================================
// FILE: src/game/Forest.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: Forest module behavior and local implementation details.
// ============================================================

#include "Forest.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <random>

#pragma comment(lib, "d3dcompiler.lib")

using namespace DirectX;



bool Forest::Initialize(D3D11Renderer& renderer)
{
    // Acquire device/context via small renderer getters (added below).
    m_device = renderer.GetDevice();
    m_context = renderer.GetContext();
    if (!m_device || !m_context) return false;

    // Compile simple cube shaders (reuse existing basic3d shaders in repo)
    ID3DBlob* vsBlob = nullptr;
    ID3DBlob* psBlob = nullptr;
    HRESULT hr = D3DCompileFromFile(L"Shaders/basic3d_vs.hlsl", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "main", "vs_4_0", 0, 0, &vsBlob, nullptr);
    if (FAILED(hr)) return false;
    hr = D3DCompileFromFile(L"Shaders/basic3d_ps.hlsl", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "main", "ps_4_0", 0, 0, &psBlob, nullptr);
    if (FAILED(hr)) { if (vsBlob) vsBlob->Release(); return false; }

    hr = m_device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &m_vs);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }
    hr = m_device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_ps);
    if (FAILED(hr)) { vsBlob->Release(); psBlob->Release(); return false; }

    // Vertex layout (POSITION,NORMAL,COLOR) -- must match shader inputs
    D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    hr = m_device->CreateInputLayout(layoutDesc, 3, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &m_layout);
    vsBlob->Release();
    psBlob->Release();
    if (FAILED(hr)) return false;

    // Create a small cube mesh (same layout used elsewhere). Single cube; we will draw it per-instance via CPU loop.
    struct V { float x, y, z; float nx, ny, nz; float r, g, b, a; };
    V cubeVerts[] = {
        // Front
        { -0.5f,-0.5f, 0.5f, 0,0,1, 1,0,0,1 },
        {  0.5f,-0.5f, 0.5f, 0,0,1, 0,1,0,1 },
        {  0.5f, 0.5f, 0.5f, 0,0,1, 0,0,1,1 },
        { -0.5f, 0.5f, 0.5f, 0,0,1, 1,1,0,1 },
        // Back
        {  0.5f,-0.5f,-0.5f, 0,0,-1, 1,0,1,1 },
        { -0.5f,-0.5f,-0.5f, 0,0,-1, 0,1,1,1 },
        { -0.5f, 0.5f,-0.5f, 0,0,-1, 1,1,1,1 },
        {  0.5f, 0.5f,-0.5f, 0,0,-1, 0,0,0,1 },
        // Left
        { -0.5f,-0.5f,-0.5f,-1,0,0, 1,0,0,1 },
        { -0.5f,-0.5f, 0.5f,-1,0,0, 0,1,0,1 },
        { -0.5f, 0.5f, 0.5f,-1,0,0, 0,0,1,1 },
        { -0.5f, 0.5f,-0.5f,-1,0,0, 1,1,0,1 },
        // Right
        {  0.5f,-0.5f, 0.5f, 1,0,0, 1,0,1,1 },
        {  0.5f,-0.5f,-0.5f, 1,0,0, 0,1,1,1 },
        {  0.5f, 0.5f,-0.5f, 1,0,0, 1,1,1,1 },
        {  0.5f, 0.5f, 0.5f, 1,0,0, 0,0,0,1 },
        // Top
        { -0.5f, 0.5f, 0.5f, 0,1,0, 1,0,0,1 },
        {  0.5f, 0.5f, 0.5f, 0,1,0, 0,1,0,1 },
        {  0.5f, 0.5f,-0.5f, 0,1,0, 0,0,1,1 },
        { -0.5f, 0.5f,-0.5f, 0,1,0, 1,1,0,1 },
        // Bottom
        { -0.5f,-0.5f,-0.5f, 0,-1,0, 1,0,1,1 },
        {  0.5f,-0.5f,-0.5f, 0,-1,0, 0,1,1,1 },
        {  0.5f,-0.5f, 0.5f, 0,-1,0, 1,1,1,1 },
        { -0.5f,-0.5f, 0.5f, 0,-1,0, 0,0,0,1 },
    };
    unsigned short cubeIndices[] = {
        0,1,2, 2,3,0,
        4,5,6, 6,7,4,
        8,9,10,10,11,8,
        12,13,14,14,15,12,
        16,17,18,18,19,16,
        20,21,22,22,23,20
    };
    m_indexCount = 36;

    D3D11_BUFFER_DESC vbDesc{}; vbDesc.Usage = D3D11_USAGE_DEFAULT;
    vbDesc.ByteWidth = sizeof(cubeVerts);
    vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA vinit{}; vinit.pSysMem = cubeVerts;
    hr = m_device->CreateBuffer(&vbDesc, &vinit, &m_vb);
    if (FAILED(hr)) return false;

    D3D11_BUFFER_DESC ibDesc{}; ibDesc.Usage = D3D11_USAGE_DEFAULT;
    ibDesc.ByteWidth = sizeof(cubeIndices);
    ibDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    D3D11_SUBRESOURCE_DATA iinit{}; iinit.pSysMem = cubeIndices;
    hr = m_device->CreateBuffer(&ibDesc, &iinit, &m_ib);
    if (FAILED(hr)) return false;

    D3D11_BUFFER_DESC cbDesc{}; cbDesc.Usage = D3D11_USAGE_DEFAULT;
    cbDesc.ByteWidth = sizeof(XMFLOAT4X4) * 2; // mvp + world simple
    cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    hr = m_device->CreateBuffer(&cbDesc, nullptr, &m_cb);
    if (FAILED(hr)) return false;

    return true;
}

void Forest::Shutdown()
{
    if (m_cb) { m_cb->Release(); m_cb = nullptr; }
    if (m_ib) { m_ib->Release(); m_ib = nullptr; }
    if (m_vb) { m_vb->Release(); m_vb = nullptr; }
    if (m_layout) { m_layout->Release(); m_layout = nullptr; }
    if (m_vs) { m_vs->Release(); m_vs = nullptr; }
    if (m_ps) { m_ps->Release(); m_ps = nullptr; }
    m_instances.clear();
    m_device = nullptr;
    m_context = nullptr;
}

void Forest::ClearInstances()
{
    m_instances.clear();
}

void Forest::AddInstance(D3D11Renderer& renderer, float x, float y, float z, float scale)
{
    // Snap y to terrain so the instance sits on the ground.
    float groundY = renderer.IsTerrainAvailable()
                        ? renderer.SampleTerrainHeight(x, z)
                        : y;
    Instance inst{ x, groundY, z, scale };
    m_instances.push_back(inst);
}

// Replace the existing Populate and Draw implementations with the following:

void Forest::Populate(D3D11Renderer& renderer, int count, float radius, float centerX, float centerZ)
{
    m_instances.clear();
    std::mt19937 rng(12345);
    std::uniform_real_distribution<float> d(-radius, radius);
    std::uniform_real_distribution<float> s(0.8f, 1.6f);

    bool canSampleTerrain = renderer.IsTerrainAvailable();

    for (int i = 0; i < count; ++i)
    {
        Instance inst;
        inst.x = centerX + d(rng);
        inst.z = centerZ + d(rng);
        inst.scale = s(rng);

        if (canSampleTerrain)
        {
            // Sample once at placement time and store Y
            float h = renderer.SampleTerrainHeight(inst.x, inst.z);
            inst.y = h;
        }
        else
        {
            inst.y = 0.0f;
        }

        m_instances.push_back(inst);
    }
}

void Forest::Draw(const D3D11Renderer& renderer)
{
    if (m_instances.empty()) return;
    // Prepare camera matrices from renderer (public getters exist)
    float camX, camY, camZ; renderer.GetCameraPosition(camX, camY, camZ);
    float yaw, pitch; renderer.GetCameraRotation(yaw, pitch);
    XMVECTOR camPos = XMVectorSet(camX, camY, camZ, 1.0f);
    XMVECTOR camTarget = XMVectorSet(camX + cosf(pitch) * sinf(yaw), camY + sinf(pitch), camZ + cosf(pitch) * cosf(yaw), 1.0f);
    XMVECTOR camUp = XMVectorSet(0, 1, 0, 0);

    XMMATRIX view = XMMatrixLookAtLH(camPos, camTarget, camUp);
    XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, (float)renderer.GetRenderWidth() / (float)renderer.GetRenderHeight(), 0.1f, 1000.0f);

    // Setup pipeline
    UINT stride = sizeof(float) * 10; // 3 pos + 3 normal + 4 color = 10 floats (40 bytes)
    UINT offset = 0;
    m_context->IASetInputLayout(m_layout);
    m_context->IASetVertexBuffers(0, 1, &m_vb, &stride, &offset);
    m_context->IASetIndexBuffer(m_ib, DXGI_FORMAT_R16_UINT, 0);
    m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_context->VSSetShader(m_vs, nullptr, 0);
    m_context->PSSetShader(m_ps, nullptr, 0);
    ID3D11Buffer* lightCBuffer = renderer.GetLightConstantBuffer();
    if (lightCBuffer)
        m_context->PSSetConstantBuffers(1, 1, &lightCBuffer);

    const float trunkNudge = -0.02f; // small downward tweak to ensure contact

    for (const auto& inst : m_instances)
    {
        // Use stored inst.y (sampled at placement). No per-frame sampling.
        const float trunkNudge = -0.02f; // small downward tweak to ensure contact (tweak if needed)

        float halfHeight = inst.scale; // half-height after scaling: 0.5 * (inst.scale*2.0f) == inst.scale
        float transY = inst.y + halfHeight + trunkNudge;

        XMMATRIX scaleMat = XMMatrixScaling(inst.scale, inst.scale * 2.0f, inst.scale); // scale
        XMMATRIX transMat = XMMatrixTranslation(inst.x, transY, inst.z);               // translation
        XMMATRIX worldMat = scaleMat * transMat;

        // mvp + world
        XMMATRIX mvp = XMMatrixTranspose(worldMat * view * proj);
        XMMATRIX worldT = XMMatrixTranspose(worldMat);
        struct CB { XMFLOAT4X4 mvp; XMFLOAT4X4 world; } cbData;
        XMStoreFloat4x4(&cbData.mvp, mvp);
        XMStoreFloat4x4(&cbData.world, worldT);
        m_context->UpdateSubresource(m_cb, 0, nullptr, &cbData, 0, 0);
        m_context->VSSetConstantBuffers(0, 1, &m_cb);

        m_context->DrawIndexed(m_indexCount, 0, 0);
    }
}

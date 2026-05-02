#pragma once
#include <vector>
#include <d3d11.h>

class D3D11Renderer; // forward

class Forest
{
public:
    Forest() = default;
    bool Initialize(D3D11Renderer& renderer);
    void Shutdown();
    // changed: accept renderer so we sample terrain when placing instances
    void Populate(D3D11Renderer& renderer, int count, float radius, float centerX = 0.0f, float centerZ = 0.0f);
    void Draw(const D3D11Renderer& renderer);

private:
    struct Instance { float x, y, z, scale; };
    std::vector<Instance> m_instances;

    // GPU resources owned by Forest
    ID3D11Device* m_device = nullptr;
    ID3D11DeviceContext* m_context = nullptr;
    ID3D11Buffer* m_vb = nullptr;
    ID3D11Buffer* m_ib = nullptr;
    ID3D11Buffer* m_cb = nullptr;
    ID3D11VertexShader* m_vs = nullptr;
    ID3D11PixelShader* m_ps = nullptr;
    ID3D11InputLayout* m_layout = nullptr;
    UINT m_indexCount = 0;
};
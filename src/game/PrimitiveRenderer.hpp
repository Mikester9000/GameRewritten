#pragma once
// PrimitiveRenderer.hpp
// Renders multi-part primitive (box) prefab instances using Direct3D 11.
//
// GT 610 design notes:
//   - One unit-cube mesh shared by all draw calls (no per-frame allocations).
//   - One draw call per part. For ~30 prefabs with 2-5 parts each this is well
//     within the 200 draw-call budget on Low/Medium quality.
//   - Two shader pairs: "prim" (default, used by rocks/props/etc.) and
//     "tree" (adds a vertical gradient + cheap world-position variation).
//     The shader is selected per draw call based on the prefab category.
//   - No textures — vertex color tinted by a per-draw constant buffer.
//
// Usage:
//   PrimitiveRenderer pr;
//   pr.Initialize(renderer);            // call once after device is ready
//   // when a prefab is placed or a cell is loaded:
//   pr.AddInstance(prefab, x, y, z);
//   // each frame:
//   pr.Draw(renderer);
//   // on reload / clear:
//   pr.ClearInstances();
//   // on shutdown:
//   pr.Shutdown();

#include "PrefabDef.hpp"

#include <vector>
#include <d3d11.h>

class D3D11Renderer;

class PrimitiveRenderer
{
public:
    PrimitiveRenderer() = default;

    // Set up GPU resources (cube mesh + both shader pairs).
    // Returns false if any D3D11 call fails.
    bool Initialize(D3D11Renderer& renderer);

    // Release all GPU resources.
    void Shutdown();

    // Expand a prefab into render parts at the given world position.
    // yaw   = Y-axis rotation in radians (0 = facing +Z).
    // scale = uniform scale applied on top of each part's own scale.
    void AddInstance(const PrimitivePrefab& prefab,
                     float x, float y, float z,
                     float yaw = 0.0f, float scale = 1.0f);

    // Remove all previously added instances (call on F5 reload or Clear button).
    void ClearInstances();

    // How many render parts are queued.
    int GetPartCount() const { return static_cast<int>(m_parts.size()); }

    // Draw all queued parts.  Call once per frame after setting camera state.
    void Draw(const D3D11Renderer& renderer);

private:
    // One draw-ready part (already decomposed from the prefab definition).
    struct DrawPart
    {
        float worldX, worldY, worldZ; // prefab placement position
        float offsetX, offsetY, offsetZ;
        float scaleX, scaleY, scaleZ;
        float r, g, b, a;
        bool  isTree; // selects tree shader vs default prim shader
    };

    std::vector<DrawPart> m_parts;

    // D3D11 device/context (borrowed from the renderer — do not Release them).
    ID3D11Device*        m_device  = nullptr;
    ID3D11DeviceContext* m_context = nullptr;

    // Shared unit-cube mesh with white vertex colors.
    ID3D11Buffer* m_vb = nullptr;
    ID3D11Buffer* m_ib = nullptr;
    UINT          m_indexCount = 0;

    // Input layout (POSITION + NORMAL + COLOR — matches prim_vs.hlsl).
    ID3D11InputLayout* m_layout = nullptr;

    // Default primitive shader pair (rocks, props, ruins, …).
    ID3D11VertexShader* m_primVS = nullptr;
    ID3D11PixelShader*  m_primPS = nullptr;

    // Tree shader pair (trees, bushes — adds gradient + variation).
    ID3D11VertexShader* m_treeVS = nullptr;
    ID3D11PixelShader*  m_treePS = nullptr;

    // Per-draw constant buffer (MVP + world + tint + light).
    ID3D11Buffer* m_cb = nullptr;

    // Helper: compile + create a VS and PS from two .hlsl files.
    bool CreateShaders(const wchar_t* vsPath, const wchar_t* psPath,
                       ID3D11VertexShader** outVS, ID3D11PixelShader** outPS,
                       ID3DBlob** outVSBlob);
};

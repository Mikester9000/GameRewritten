// ============================================================
// FILE: src/game/PrimitiveRenderer.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PrimitiveRenderer module behavior and local implementation details.
// ============================================================

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
//   pr.AddWorldInstance(prefab, x, y, z);
//   // each frame:
//   pr.ClearRuntimeInstances();         // rebuild runtime visuals for this frame
//   pr.Draw(renderer);
//   // on reload / clear:
//   pr.ClearWorldInstances();
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

    // Set the accumulated game time (seconds since startup) used by the tree
    // wind shader.  Call once per frame before Draw().
    void SetGlobalTime(float t)         { m_globalTime = t; }

    // Set wind strength [0,1] that scales the tree sway amplitude.
    void SetWindStrength(float w)       { m_windStrength = w; }

    // Expand a prefab into WORLD (authored/static) render parts at the given world position.
    // yaw   = Y-axis rotation in radians (0 = facing +Z).
    // scale = uniform scale applied on top of each part's own scale.
    void AddWorldInstance(const PrimitivePrefab& prefab,
                          float x, float y, float z,
                          float yaw = 0.0f, float scale = 1.0f);

    // Remove all WORLD instances (call on F5 reload or Clear button).
    void ClearWorldInstances();

    // Expand a prefab into RUNTIME (dynamic/per-frame) render parts.
    void AddRuntimeInstance(const PrimitivePrefab& prefab,
                            float x, float y, float z,
                            float yaw = 0.0f, float scale = 1.0f,
                            bool useCel = false);

    // Remove all RUNTIME instances (typically called once per frame before rebuild).
    void ClearRuntimeInstances();

    // Compatibility wrappers for older call sites.
    void AddInstance(const PrimitivePrefab& prefab,
                     float x, float y, float z,
                     float yaw = 0.0f, float scale = 1.0f)
    {
        AddWorldInstance(prefab, x, y, z, yaw, scale);
    }
    void ClearInstances()
    {
        ClearWorldInstances();
        ClearRuntimeInstances();
    }

    // How many render parts are queued.
    int GetPartCount() const
    {
        return static_cast<int>(m_worldParts.size() + m_runtimeParts.size());
    }

    // Draw all queued parts.  Call once per frame after setting camera state.
    void Draw(const D3D11Renderer& renderer);

private:
    // One draw-ready part (already decomposed from the prefab definition).
    struct DrawPart
    {
        float worldX, worldY, worldZ; // prefab placement position
        float offsetX, offsetY, offsetZ;
        float scaleX, scaleY, scaleZ;
        float yaw;    // Y-axis rotation of the whole instance (radians)
        float r, g, b, a;
        bool  isTree; // selects tree shader vs default prim shader
        bool  useCel = false;
        bool  drawOutline = false;
    };

    std::vector<DrawPart> m_worldParts;
    std::vector<DrawPart> m_runtimeParts;

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
    ID3D11VertexShader* m_celVS = nullptr;
    ID3D11PixelShader*  m_celPS = nullptr;
    ID3D11VertexShader* m_outlineVS = nullptr;
    ID3D11PixelShader*  m_outlinePS = nullptr;

    // Per-draw constant buffer (MVP + world + tint + wind params).
    ID3D11Buffer* m_cb = nullptr;
    ID3D11Buffer* m_celParamsCB = nullptr;
    ID3D11RasterizerState* m_outlineRasterizerState = nullptr;

    // Global time (seconds since startup) and wind strength forwarded to tree shader.
    float m_globalTime   = 0.0f;
    float m_windStrength = 0.05f;

    // Helper: compile + create a VS and PS from two .hlsl files.
    bool CreateShaders(const wchar_t* vsPath, const wchar_t* psPath,
                       ID3D11VertexShader** outVS, ID3D11PixelShader** outPS,
                       ID3DBlob** outVSBlob);

    // Helper: expand prefab parts into the target storage bucket.
    void AddInstanceToBucket(std::vector<DrawPart>& bucket,
                             const PrimitivePrefab& prefab,
                             float x, float y, float z,
                             float yaw, float scale,
                             bool useCel);
};

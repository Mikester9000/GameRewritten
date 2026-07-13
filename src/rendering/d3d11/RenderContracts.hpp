#pragma once

#include <DirectXMath.h>

namespace RenderContracts
{
// Shared CPU-side constant-buffer contracts for HLSL bindings.
// HLSL contract: Transform@b0 and Light@b1 for ground/terrain/primitive shading.
constexpr unsigned int kTransformBufferRegister = 0;
constexpr unsigned int kLightBufferRegister = 1;

struct TransformCBuffer
{
    DirectX::XMFLOAT4X4 mvp;
    DirectX::XMFLOAT4X4 world;
};
static_assert(sizeof(TransformCBuffer) == 128, "TransformCBuffer layout mismatch.");
static_assert((sizeof(TransformCBuffer) % 16) == 0, "TransformCBuffer must be 16-byte aligned.");

struct LightCBuffer
{
    float lightDirX, lightDirY, lightDirZ;
    float pad0;
    float lightColorR, lightColorG, lightColorB;
    float ambientStrength;
};
static_assert(sizeof(LightCBuffer) == 32, "LightCBuffer layout mismatch.");
static_assert((sizeof(LightCBuffer) % 16) == 0, "LightCBuffer must be 16-byte aligned.");

inline LightCBuffer DefaultDirectionalLight()
{
    return LightCBuffer{
        0.45f, -1.0f, 0.35f, 0.0f,
        1.0f, 0.98f, 0.95f, 0.30f
    };
}
}

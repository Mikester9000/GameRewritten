#pragma once

#include "../rendering/d3d11/D3D11Renderer.hpp"

class QualityPresetEnforcer
{
public:
    static D3D11Renderer::GraphicsPreset ClampRequestedPreset(bool lowSpecGpu, D3D11Renderer::GraphicsPreset requested);
    static bool Enforce(D3D11Renderer& renderer, bool lowSpecGpu, D3D11Renderer::GraphicsPreset requestedPreset);
};

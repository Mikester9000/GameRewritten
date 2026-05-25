#include "QualityPreset.hpp"

D3D11Renderer::GraphicsPreset QualityPresetEnforcer::ClampRequestedPreset(
    bool lowSpecGpu,
    D3D11Renderer::GraphicsPreset requested)
{
    if (!lowSpecGpu)
        return requested;

    switch (requested)
    {
    case D3D11Renderer::GraphicsPreset::Ultra:
        return D3D11Renderer::GraphicsPreset::High;
    default:
        return requested;
    }
}

bool QualityPresetEnforcer::Enforce(
    D3D11Renderer& renderer,
    bool lowSpecGpu,
    D3D11Renderer::GraphicsPreset requestedPreset)
{
    const D3D11Renderer::GraphicsPreset clamped = ClampRequestedPreset(lowSpecGpu, requestedPreset);
    const bool changed = (renderer.GetGraphicsPreset() != clamped);
    renderer.ApplyGraphicsPreset(clamped);
    return changed;
}

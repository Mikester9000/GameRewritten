#pragma once
// SfxSpatialRules.hpp
// Distance attenuation and occlusion rules for SFX playback.
// Outputs an effective volume multiplier for a given source/listener pair.

#include <DirectXMath.h>
#include <cmath>

struct SfxSpatialRules
{
    float minDistance  = 2.0f;   // full volume within this range
    float maxDistance  = 30.0f;  // inaudible beyond this range
    float occlusionMult= 0.3f;   // volume multiplier when source is occluded

    // Linear attenuation between min and max distance.
    float CalcVolume(const DirectX::XMFLOAT3& source,
                     const DirectX::XMFLOAT3& listener,
                     bool occluded = false) const
    {
        const float dx   = source.x - listener.x;
        const float dz   = source.z - listener.z;
        const float dist = std::sqrt(dx * dx + dz * dz);

        float vol = 1.0f;
        if (dist > minDistance)
        {
            const float range = maxDistance - minDistance;
            vol = 1.0f - std::fmin(1.0f, (dist - minDistance) / range);
        }
        return vol * (occluded ? occlusionMult : 1.0f);
    }
};

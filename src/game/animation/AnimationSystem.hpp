// ============================================================
// FILE: src/game/animation/AnimationSystem.hpp
// SYSTEM: Game
// ROLE: per-frame CPU keyframe sampling for all AnimationComponents
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimationSystem module behavior and local implementation details.
// ============================================================

#pragma once

#include "AnimationComponent.hpp"
#include <DirectXMath.h>
#include <vector>

// Single bone transform — position, rotation (quaternion), and scale.
struct BoneTransform
{
    DirectX::XMFLOAT3 position = {0.0f, 0.0f, 0.0f};
    DirectX::XMFLOAT4 rotation = {0.0f, 0.0f, 0.0f, 1.0f};
    DirectX::XMFLOAT3 scale    = {1.0f, 1.0f, 1.0f};
};

// CPU-sampled output for one actor — up to 64 bones plus root motion delta.
struct BoneTransformBuffer
{
    static constexpr int kMaxBones = 64;
    BoneTransform         bones[kMaxBones];
    DirectX::XMFLOAT3     rootMotionDelta = {0.0f, 0.0f, 0.0f};
};

// Advances all AnimationComponents and samples per-bone transforms each frame.
class AnimationSystem
{
public:
    // Advance all components by dt and fill outBuffers (one per component).
    // outBuffers is resized to match components.size().
    static void Advance(float dt,
                        std::vector<AnimationComponent>& components,
                        std::vector<BoneTransformBuffer>& outBuffers);

private:
    // Sample a translation channel at time t → XMFLOAT3.
    static DirectX::XMFLOAT3 SampleTranslation(const AnimChannel& ch, float t);
    // Sample a rotation channel at time t → XMFLOAT4 quaternion.
    static DirectX::XMFLOAT4 SampleRotation(const AnimChannel& ch, float t);
    // Sample a scale channel at time t → XMFLOAT3.
    static DirectX::XMFLOAT3 SampleScale(const AnimChannel& ch, float t);
};

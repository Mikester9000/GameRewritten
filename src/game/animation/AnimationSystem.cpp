// ============================================================
// FILE: src/game/animation/AnimationSystem.cpp
// SYSTEM: Game
// ROLE: per-frame CPU keyframe sampling for all AnimationComponents
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: AnimationSystem module behavior and local implementation details.
// ============================================================

#include "AnimationSystem.hpp"
#include <cstring>

using namespace DirectX;

// ---------------------------------------------------------------------------
// Keyframe sampling helpers.
// ---------------------------------------------------------------------------

// Find the two surrounding keyframes for time t and return the blend factor.
// Returns left index in outA, right index in outB, factor in [0..1] in outAlpha.
static void FindKeyframeRange(const std::vector<AnimKeyframe>& kfs,
                              float t,
                              int& outA, int& outB, float& outAlpha)
{
    if (kfs.empty())
    {
        outA = outB = 0;
        outAlpha = 0.0f;
        return;
    }
    if (kfs.size() == 1 || t <= kfs.front().time)
    {
        outA = outB = 0;
        outAlpha = 0.0f;
        return;
    }
    if (t >= kfs.back().time)
    {
        outA = outB = static_cast<int>(kfs.size()) - 1;
        outAlpha = 0.0f;
        return;
    }

    // Binary search for surrounding pair.
    int lo = 0, hi = static_cast<int>(kfs.size()) - 1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (kfs[mid].time <= t)
            lo = mid;
        else
            hi = mid;
    }
    outA = lo;
    outB = hi;
    const float span = kfs[hi].time - kfs[lo].time;
    outAlpha = (span > 0.0f) ? (t - kfs[lo].time) / span : 0.0f;
}

// ---------------------------------------------------------------------------
XMFLOAT3 AnimationSystem::SampleTranslation(const AnimChannel& ch, float t)
{
    if (ch.keyframes.empty())
        return XMFLOAT3(0.0f, 0.0f, 0.0f);

    int a, b;
    float alpha;
    FindKeyframeRange(ch.keyframes, t, a, b, alpha);

    const float* va = ch.keyframes[a].value;
    const float* vb = ch.keyframes[b].value;

    if (ch.interpolation == "STEP" || a == b)
        return XMFLOAT3(va[0], va[1], va[2]);

    // LINEAR (also used as CUBIC fallback).
    return XMFLOAT3(
        va[0] + alpha * (vb[0] - va[0]),
        va[1] + alpha * (vb[1] - va[1]),
        va[2] + alpha * (vb[2] - va[2])
    );
}

// ---------------------------------------------------------------------------
XMFLOAT4 AnimationSystem::SampleRotation(const AnimChannel& ch, float t)
{
    if (ch.keyframes.empty())
        return XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);

    int a, b;
    float alpha;
    FindKeyframeRange(ch.keyframes, t, a, b, alpha);

    const float* va = ch.keyframes[a].value;
    const float* vb = ch.keyframes[b].value;

    if (ch.interpolation == "STEP" || a == b)
        return XMFLOAT4(va[0], va[1], va[2], va[3]);

    // Slerp for smooth rotation blending.
    XMVECTOR qa = XMVectorSet(va[0], va[1], va[2], va[3]);
    XMVECTOR qb = XMVectorSet(vb[0], vb[1], vb[2], vb[3]);
    XMVECTOR result = XMQuaternionSlerp(qa, qb, alpha);
    XMFLOAT4 out;
    XMStoreFloat4(&out, result);
    return out;
}

// ---------------------------------------------------------------------------
XMFLOAT3 AnimationSystem::SampleScale(const AnimChannel& ch, float t)
{
    // Reuse translation sampler — both are float3.
    return SampleTranslation(ch, t);
}

// ---------------------------------------------------------------------------
// Build a BoneTransformBuffer by sampling all channels of one clip at time t.
static void SampleClip(const LoadedAnimClip& clip, float t, BoneTransformBuffer& buf)
{
    std::memset(&buf, 0, sizeof(buf));
    // Default rotations to identity.
    for (int i = 0; i < BoneTransformBuffer::kMaxBones; ++i)
    {
        buf.bones[i].scale    = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
        buf.bones[i].rotation = DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
    }

    int boneIndex = 0;
    for (const AnimChannel& ch : clip.channels)
    {
        if (boneIndex >= BoneTransformBuffer::kMaxBones)
            break;

        if (ch.target == "translation" || ch.target == "TRANSLATION")
            buf.bones[boneIndex].position = AnimationSystem::SampleTranslation(ch, t);
        else if (ch.target == "rotation" || ch.target == "ROTATION")
            buf.bones[boneIndex].rotation = AnimationSystem::SampleRotation(ch, t);
        else if (ch.target == "scale" || ch.target == "SCALE")
            buf.bones[boneIndex].scale = AnimationSystem::SampleScale(ch, t);

        // Each channel targets one bone; increment per channel group.
        // Simple mapping: one bone per channel entry (sparse packing).
        ++boneIndex;
    }
}

// ---------------------------------------------------------------------------
void AnimationSystem::Advance(float dt,
                              std::vector<AnimationComponent>& components,
                              std::vector<BoneTransformBuffer>& outBuffers)
{
    outBuffers.resize(components.size());

    for (size_t i = 0; i < components.size(); ++i)
    {
        AnimationComponent& comp = components[i];
        BoneTransformBuffer& buf = outBuffers[i];

        comp.Update(dt);

        if (!comp.activeClip)
        {
            std::memset(&buf, 0, sizeof(buf));
            continue;
        }

        // Sample active clip.
        SampleClip(*comp.activeClip, comp.playbackTime, buf);

        // If blending, sample next clip and lerp.
        if (comp.nextClip != nullptr && comp.blendAlpha > 0.0f)
        {
            BoneTransformBuffer nextBuf;
            // Next clip playback time: scale by duration ratio.
            float nextTime = comp.playbackTime;
            if (comp.activeClip->durationSec > 0.0f && comp.nextClip->durationSec > 0.0f)
            {
                nextTime = comp.playbackTime
                    * (comp.nextClip->durationSec / comp.activeClip->durationSec);
            }
            SampleClip(*comp.nextClip, nextTime, nextBuf);

            const float alpha = comp.blendAlpha;
            for (int b = 0; b < BoneTransformBuffer::kMaxBones; ++b)
            {
                // Lerp position and scale.
                XMVECTOR pa = XMLoadFloat3(&buf.bones[b].position);
                XMVECTOR pb = XMLoadFloat3(&nextBuf.bones[b].position);
                XMStoreFloat3(&buf.bones[b].position,
                              XMVectorLerp(pa, pb, alpha));

                // Slerp rotation.
                XMVECTOR ra = XMLoadFloat4(&buf.bones[b].rotation);
                XMVECTOR rb = XMLoadFloat4(&nextBuf.bones[b].rotation);
                XMStoreFloat4(&buf.bones[b].rotation,
                              XMQuaternionSlerp(ra, rb, alpha));

                // Lerp scale.
                XMVECTOR sa = XMLoadFloat3(&buf.bones[b].scale);
                XMVECTOR sb = XMLoadFloat3(&nextBuf.bones[b].scale);
                XMStoreFloat3(&buf.bones[b].scale,
                              XMVectorLerp(sa, sb, alpha));
            }
        }

        // Root motion delta: position of root bone this frame (simple approximation).
        buf.rootMotionDelta = buf.bones[0].position;
    }
}

#pragma once
// AbilityTargeting.hpp
// Targeting shape templates for abilities: single target, cone, and AoE circle.
// Builds a hit-list of actors that fall within the shape.

#include <DirectXMath.h>
#include <vector>

// Forward declarations to avoid heavy includes.
struct EnemyActor;

enum class TargetShape { Single, Cone, AoE };

struct TargetingResult
{
    std::vector<int> hitIndices; // indices into the caller's enemy array
};

class AbilityTargeting
{
public:
    // Single-target: returns the one enemy whose centre is nearest originPos
    // within maxRange, or empty if none.
    static TargetingResult Single(const DirectX::XMFLOAT3& originPos,
                                  float maxRange,
                                  const std::vector<EnemyActor>& enemies);

    // Cone: half-angle in radians from forwardDir, maxRange depth.
    static TargetingResult Cone(const DirectX::XMFLOAT3& originPos,
                                const DirectX::XMFLOAT3& forwardDir,
                                float halfAngle,
                                float maxRange,
                                const std::vector<EnemyActor>& enemies);

    // AoE circle: all enemies within radius of originPos.
    static TargetingResult AoE(const DirectX::XMFLOAT3& originPos,
                               float radius,
                               const std::vector<EnemyActor>& enemies);
};

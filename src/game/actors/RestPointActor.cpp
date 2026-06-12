// ============================================================
// FILE: src/game/actors/RestPointActor.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: RestPointActor module behavior and local implementation details.
// ============================================================

// RestPointActor.cpp
// Campfire rest point: orange box visual + proximity HP/MP restore.

#include "RestPointActor.hpp"

#include "../PrimitiveRenderer.hpp"
#include "../PrefabDef.hpp"
#include "PlayerStats.hpp"

#include <cmath>

namespace
{
// Orange campfire prefab — two parts (base ring + fire glow box).
PrimitivePrefab BuildCampfirePrefab()
{
    PrimitivePrefab p;
    p.name     = "_campfire_blockout";
    p.category = "prop";

    // Stone ring base (dark grey).
    PrimitivePart base;
    base.offsetX = 0.0f; base.offsetY = 0.1f; base.offsetZ = 0.0f;
    base.scaleX  = 0.8f; base.scaleY  = 0.2f; base.scaleZ  = 0.8f;
    base.r = 0.35f; base.g = 0.30f; base.b = 0.25f; base.a = 1.0f;
    p.parts.push_back(base);

    // Flame glow (bright orange).
    PrimitivePart flame;
    flame.offsetX = 0.0f; flame.offsetY = 0.55f; flame.offsetZ = 0.0f;
    flame.scaleX  = 0.4f; flame.scaleY  = 0.7f;  flame.scaleZ  = 0.4f;
    flame.r = 1.0f; flame.g = 0.50f; flame.b = 0.05f; flame.a = 1.0f;
    p.parts.push_back(flame);

    return p;
}

const PrimitivePrefab& CampfirePrefab()
{
    static const PrimitivePrefab kPrefab = BuildCampfirePrefab();
    return kPrefab;
}
} // anonymous namespace

void RestPointActor::Init(float startX, float startZ, float interactRadius)
{
    x = startX;
    y = 0.0f;
    z = startZ;
    radius        = interactRadius;
    usedThisVisit = false;
}

bool RestPointActor::Update(float playerX, float playerZ,
                            bool interactPressed,
                            PlayerStats& stats)
{
    // --- Distance to campfire ---
    const float dx         = playerX - x;
    const float dz         = playerZ - z;
    const float distanceSq = dx * dx + dz * dz;
    const float inRange    = (distanceSq <= radius * radius);

    // --- Reset flag once the player walks far enough away ---
    const float resetDistSq = (radius * 2.0f) * (radius * 2.0f);
    if (usedThisVisit && distanceSq > resetDistSq)
        usedThisVisit = false;

    // --- Heal on E press while nearby and not yet used ---
    if (inRange && interactPressed && !usedThisVisit)
    {
        stats.hp  = stats.maxHp;
        stats.mp  = stats.maxMp;
        usedThisVisit = true;
        return true; // signal caller to show toast
    }

    return false;
}

void RestPointActor::SubmitVisual(PrimitiveRenderer& pr) const
{
    pr.AddRuntimeInstance(CampfirePrefab(), x, y, z, 0.0f, 1.0f, false);
}

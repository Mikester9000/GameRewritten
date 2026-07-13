// ChestActor.cpp
// Treasure chest: golden box visual + one-shot loot drop on E press.

#include "ChestActor.hpp"

#include "../PrimitiveRenderer.hpp"
#include "../PrefabDef.hpp"

namespace
{
PrimitivePrefab BuildChestPrefab(bool opened)
{
    PrimitivePrefab p;
    p.name     = "_chest_blockout";
    p.category = "prop";

    // Box body (wood-brown).
    PrimitivePart body;
    body.offsetX = 0.0f; body.offsetY = 0.35f; body.offsetZ = 0.0f;
    body.scaleX  = 0.7f; body.scaleY  = 0.5f;  body.scaleZ  = 0.5f;
    body.r = 0.55f; body.g = 0.35f; body.b = 0.10f; body.a = 1.0f;
    p.parts.push_back(body);

    // Lid (gold when closed, dark when open).
    PrimitivePart lid;
    lid.offsetX = 0.0f; lid.offsetY = 0.75f; lid.offsetZ = 0.0f;
    lid.scaleX  = 0.72f; lid.scaleY = 0.18f; lid.scaleZ  = 0.52f;
    if (opened) { lid.r = 0.25f; lid.g = 0.20f; lid.b = 0.10f; lid.a = 1.0f; }
    else        { lid.r = 0.85f; lid.g = 0.70f; lid.b = 0.10f; lid.a = 1.0f; }
    p.parts.push_back(lid);

    return p;
}
} // anonymous namespace

void ChestActor::Init(float startX, float startZ,
                      std::vector<LootEntry> lootItems, float radius)
{
    x = startX; y = 0.0f; z = startZ;
    interactRadius = radius;
    opened         = false;
    loot           = std::move(lootItems);
}

bool ChestActor::Update(float playerX, float playerZ, bool interactPressed)
{
    if (opened) return false;

    const float dx = playerX - x;
    const float dz = playerZ - z;
    const bool  inRange = (dx * dx + dz * dz) <= interactRadius * interactRadius;

    if (inRange && interactPressed)
    {
        opened = true;
        return true;
    }
    return false;
}

void ChestActor::SubmitVisual(PrimitiveRenderer& pr) const
{
    static const PrimitivePrefab kClosed = BuildChestPrefab(false);
    static const PrimitivePrefab kOpen   = BuildChestPrefab(true);
    pr.AddRuntimeInstance(opened ? kOpen : kClosed, x, y, z, 0.0f, 1.0f, false);
}

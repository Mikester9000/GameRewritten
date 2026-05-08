#pragma once
// WorldRuntimeRefresh.hpp
// Small app-layer helpers for refreshing the current cell's runtime/world visuals.

#include "../game/CameraController.hpp"
#include "../game/Forest.hpp"
#include "../game/PrefabLibrary.hpp"
#include "../game/PrimitiveRenderer.hpp"
#include "../game/physics/CollisionWorld.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../ui/WorldEditor.hpp"
#include "../world/WorldGrid.hpp"
#include <cmath>

namespace WorldRefresh
{
struct RefreshContext
{
    D3D11Renderer& renderer;
    Forest& forest;
    PrimitiveRenderer& primitiveRenderer;
    PrefabLibrary& prefabLibrary;
    CollisionWorld& collisionWorld;
    WorldEditor& worldEditor;
};

inline void RefreshCellVisuals(const WorldCell& cell, const RefreshContext& context)
{
    D3D11Renderer::TerrainParams tp;
    tp.biome         = cell.terrainBiome;
    tp.seed          = cell.terrainSeed;
    tp.cellOriginX   = cell.OriginX();
    tp.cellOriginZ   = cell.OriginZ();
    tp.cellWorldSize = cell.cellSize;
    tp.heightScale   = cell.terrainHeightScale;
    tp.noiseFreq     = cell.terrainNoiseFreq;
    tp.noiseFreq2    = cell.terrainNoiseFreq2;
    if (cell.terrainEnabled)
        context.renderer.RebuildTerrainPatch(tp);
    else
        context.renderer.ClearTerrainPatch();

    if (cell.forestEnabled)
    {
        context.forest.Populate(context.renderer, cell.forestTreeCount,
                                cell.forestRadius, cell.CenterX(), cell.CenterZ());
    }
    else
    {
        context.forest.ClearInstances();
    }

    context.collisionWorld.Clear();
    for (const auto& inst : cell.instances)
    {
        const PrimitivePrefab* prefab = context.prefabLibrary.GetPrefab(inst.prefab);
        if (!prefab)
            continue;

        const float cosY = cosf(inst.yaw);
        const float sinY = sinf(inst.yaw);
        const float absCosY = fabsf(cosY);
        const float absSinY = fabsf(sinY);

        for (const auto& part : prefab->parts)
        {
            const float rotOffX = part.offsetX * cosY - part.offsetZ * sinY;
            const float rotOffZ = part.offsetX * sinY + part.offsetZ * cosY;

            const float cx = inst.x + rotOffX;
            const float cy = inst.y + part.offsetY;
            const float cz = inst.z + rotOffZ;

            const float halfX = part.scaleX * inst.scale * 0.5f;
            const float halfY = part.scaleY * inst.scale * 0.5f;
            const float halfZ = part.scaleZ * inst.scale * 0.5f;

            const float worldHalfX = absCosY * halfX + absSinY * halfZ;
            const float worldHalfZ = absSinY * halfX + absCosY * halfZ;

            context.collisionWorld.AddBox(cx, cy, cz, worldHalfX, halfY, worldHalfZ);
        }
    }

    context.primitiveRenderer.ClearWorldInstances();
    context.worldEditor.SpawnCellInstances(cell.cx, cell.cz, context.renderer);
}

// Returns the cell containing the world-space position, or nullptr if that
// grid coordinate is outside the loaded world manifest.
inline WorldCell* FindCellAtWorldPosition(WorldGrid& worldGrid, float worldX, float worldZ,
                                          int& outCellX, int& outCellZ)
{
    worldGrid.WorldToCell(worldX, worldZ, outCellX, outCellZ);
    return worldGrid.FindCell(outCellX, outCellZ);
}

// Returns the cell containing the player's current world position, or nullptr
// if the player is currently outside any loaded world cell.
inline WorldCell* FindCellForPlayerPosition(WorldGrid& worldGrid,
                                            const CameraController& camController,
                                            int& outCellX, int& outCellZ)
{
    return FindCellAtWorldPosition(worldGrid,
                                   camController.GetPlayerX(),
                                   camController.GetPlayerZ(),
                                   outCellX, outCellZ);
}
}

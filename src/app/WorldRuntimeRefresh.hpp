#pragma once
// WorldRuntimeRefresh.hpp
// Small app-layer helpers for refreshing the current cell's runtime/world visuals.

#include "../game/CameraController.hpp"
#include "../game/Forest.hpp"
#include "../game/PrimitiveRenderer.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../ui/WorldEditor.hpp"
#include "../world/WorldGrid.hpp"

namespace WorldRefresh
{
struct RefreshContext
{
    D3D11Renderer& renderer;
    Forest& forest;
    PrimitiveRenderer& primitiveRenderer;
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

    context.primitiveRenderer.ClearWorldInstances();
    context.worldEditor.SpawnCellInstances(cell.cx, cell.cz, context.renderer);
}

// Returns the cell containing the world-space position, or nullptr if that
// grid coordinate is outside the loaded world manifest.
inline WorldCell* FindCellAtWorldPosition(WorldGrid& worldGrid, float worldX, float worldZ,
                                          int& outCX, int& outCZ)
{
    worldGrid.WorldToCell(worldX, worldZ, outCX, outCZ);
    return worldGrid.FindCell(outCX, outCZ);
}

// Returns the cell containing the player's current world position, or nullptr
// if the player is currently outside any loaded world cell.
inline WorldCell* FindCellForPlayerPosition(WorldGrid& worldGrid,
                                            const CameraController& camController,
                                            int& outCX, int& outCZ)
{
    return FindCellAtWorldPosition(worldGrid,
                                   camController.GetPlayerX(),
                                   camController.GetPlayerZ(),
                                   outCX, outCZ);
}
}

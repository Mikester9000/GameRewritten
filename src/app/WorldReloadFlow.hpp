// ============================================================
// FILE: src/app/WorldReloadFlow.hpp
// SYSTEM: WorldReloadFlow.hpp
// SYSTEM: app startup/shutdown wiring and frame orchestration

#pragma once
// WorldReloadFlow.hpp
// Handles the F5 world/registry reload workflow used by Main.cpp.

#include "../assets/AssetRegistry.hpp"
#include "../game/CameraController.hpp"
#include "../game/PrefabLibrary.hpp"
#include "../ui/WorldEditor.hpp"
#include "../world/WorldGrid.hpp"
#include "WorldRuntimeRefresh.hpp"
#include <logger/Logger.hpp>

namespace WorldReload
{
struct ReloadContext
{
    AssetRegistry& registry;
    WorldGrid& worldGrid;
    PrefabLibrary& prefabLibrary;
    WorldEditor& worldEditor;
    CameraController& camController;
    const WorldRefresh::RefreshContext& cellRefreshContext;
    int& lastPlayerCX;
    int& lastPlayerCZ;
};

// Reloads registry and world grid in place. Both Reload() calls are resilient:
// on failure they retain prior in-memory data, so runtime state remains usable.
inline void ReloadAssetsAndWorld(ReloadContext& context)
{
    LOG_INFO("F5: reloading Asset Registry and World Grid...");
    bool regOk  = context.registry.Reload();   // safe: keeps old data on parse error
    bool gridOk = context.worldGrid.Reload();  // safe: keeps old grid on parse error

    if (regOk)
    {
        LOG_INFO("F5: AssetRegistry reloaded OK.");
        context.prefabLibrary.Reload(context.registry);
        context.worldEditor.RefreshPrefabList();
    }
    else
    {
        LOG_WARN("F5: AssetRegistry reload failed — keeping old registry.");
    }

    if (gridOk)
    {
        LOG_INFO("F5: WorldGrid reloaded OK — rebuilding terrain for active cell...");
        int playerCX = 0, playerCZ = 0;
        WorldCell* playerCell = WorldRefresh::FindCellForPlayerPosition(
            context.worldGrid, context.camController, playerCX, playerCZ);
        if (playerCell)
        {
            WorldRefresh::RefreshCellVisuals(*playerCell, context.cellRefreshContext);
            context.lastPlayerCX = playerCX;
            context.lastPlayerCZ = playerCZ;
            LOG_INFO("F5: terrain rebuilt and instances respawned.");
        }
    }
    else
    {
        LOG_WARN("F5: WorldGrid reload failed — keeping old world grid.");
    }
}
}

#pragma once

#include "../logger/Logger.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../rendering/d3d11/Terrain_Renderer.hpp"

// Central app-layer service wiring for render-world dependencies.
// Keeps ownership in app while preserving renderer subsystem decoupling.
struct EngineContext
{
    D3D11Renderer* renderer = nullptr;
    TerrainManager terrainManager;
    bool terrainReady = false;

    bool Initialize(D3D11Renderer& inRenderer)
    {
        renderer = &inRenderer;
        terrainReady = terrainManager.Initialize(renderer->GetDevice(), renderer->GetContext());
        if (!terrainReady)
        {
            LOG_ERROR("EngineContext: TerrainManager initialization failed.");
            renderer->SetTerrainManager(nullptr);
            return false;
        }
        renderer->SetTerrainManager(&terrainManager);
        return true;
    }

    void Shutdown()
    {
        if (renderer)
            renderer->SetTerrainManager(nullptr);
        terrainManager.Shutdown();
        terrainReady = false;
    }

    void Tick(float deltaTime)
    {
        terrainManager.Tick(deltaTime);
        // TODO(next-ai): purpose=central per-frame service updates
        // required inputs/outputs=input dt, service state; output updated service runtime data
        // invariants=must remain app-owned orchestration only and never own gameplay state
        // acceptance checks=new service can add Tick call here without cross-file renderer edits
        // file ownership/expected edit scope=src/app/EngineContext.hpp only
    }

    bool Validate() const
    {
        if (!renderer)
            return false;
        if (!renderer->ValidateRenderState("EngineContext::Validate"))
            return false;
        if (!terrainManager.Validate())
            return false;
        return terrainReady;
    }

    void DebugDraw()
    {
        terrainManager.DebugDraw();
        if (renderer)
            renderer->DebugDraw();
    }
};

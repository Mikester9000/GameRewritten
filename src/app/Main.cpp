// Main.cpp
// Application entry point: initializes all engine systems, runs the main game loop,
// and shuts everything down cleanly on exit.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cmath>
#include <cstdint>
#include <sstream>   // for std::ostringstream (cell crossing log)
#include "../platform/win32/Win32Window.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../game/Forest.hpp"
#include "../game/CameraController.hpp"
#include "../game/actors/PlayerActor.hpp"
#include "../game/PrefabLibrary.hpp"
#include "../game/PrimitiveRenderer.hpp"
#include "../game/RuntimeScene.hpp"
#include "../game/physics/CollisionWorld.hpp"
#include "../ui/GameHUD.hpp"
#include "../ui/DamageNumbers.hpp"
#include "../ui/ImGuiLayer.hpp"
#include "../ui/DialogBox.hpp"
#include "../ui/Minimap.hpp"
#include "../ui/WorldEditor.hpp"
#include "../assets/AssetLoader.hpp"
#include "../assets/AssetRegistry.hpp"
#include "../assets/TextureCache.hpp"
#include "../audio/AudioManager.hpp"
#include "../world/WorldGrid.hpp"
#include "FrameTiming.hpp"
#include "InputActionMap.hpp"
#include "InputEdgeState.hpp"
#include "CursorModeController.hpp"
#include "WorldEditorFrameOps.hpp"
#include "WorldReloadFlow.hpp"
#include "ThirdPartyBootstrap.hpp"
#include "WorldRuntimeRefresh.hpp"
#include <logger/Logger.hpp>

#include "tp_tracy.hpp"
#include <imgui.h>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    Win32Window window;
    if (!window.Create(1280, 720, L"My Engine Seed (D3D11)"))
    {
        MessageBoxW(nullptr, L"Failed to create window.", L"Error", 0);
        return 1;
    }

    D3D11Renderer renderer;
    if (!renderer.Initialize(window.GetHandle(), window.GetWidth(), window.GetHeight()))
    {
        MessageBoxW(nullptr, L"Failed to initialize D3D11.", L"Error", 0);
        return 1;
    }

    // --- Texture Cache ---
    // Loads D3D11 textures via DirectXTex and caches SRVs by file path.
    TextureCache textureCache;
    renderer.SetTextureCache(&textureCache);

    // --- Asset Registry ---
    // Maps scoped IDs (e.g. "textures.placeholder") to file paths.
    // Press F5 at runtime to reload without restarting.
    AssetRegistry registry;
    registry.Load("Content/AssetRegistry.json");

    // --- World Grid ---
    // Loads Content/World/world.json which lists all world cells.
    // Each cell drives terrain + forest for that chunk of the open world.
    WorldGrid worldGrid;
    worldGrid.Load("Content/World/world.json");

    // Create and initialize forest (after renderer is initialized).
    Forest forest;
    if (!forest.Initialize(renderer))
    {
        MessageBoxW(nullptr, L"Failed to initialize Forest.", L"Error", 0);
        return 1;
    }

    // Initialize ImGui overlay (pause menu + debug overlay).
    ImGuiLayer imguiLayer;
    if (!imguiLayer.Initialize(window.GetHandle(), renderer.GetDevice(), renderer.GetContext()))
    {
        MessageBoxW(nullptr, L"Failed to initialize ImGui.", L"Error", 0);
        return 1;
    }
    imguiLayer.SetRendererRef(&renderer);
    // Forward Win32 messages to ImGui (mouse, keyboard, etc.).
    window.SetWndProcHook(&ImGuiLayer::WndProcHook);

    // --- Prefab Library ---
    // Loads all "prefabs.*" from the Asset Registry and caches their primitive-part
    // definitions so the World Editor can look up prefab shapes at placement time.
    PrefabLibrary prefabLibrary;
    prefabLibrary.Load(registry);

    // --- Primitive Renderer ---
    // Draws multi-part box prefab instances placed via the World Editor.
    // Separate from Forest (which handles procedural trees).
    // primRendererPtr stays nullptr if initialization fails so WorldEditor falls
    // back to the legacy Forest cube renderer instead of queuing invisible parts.
    PrimitiveRenderer primRenderer;
    CollisionWorld collisionWorld;
    PrimitiveRenderer* primRendererPtr = nullptr;
    if (primRenderer.Initialize(renderer))
    {
        primRendererPtr = &primRenderer;
    }
    else
    {
        LOG_WARN("Main: PrimitiveRenderer failed to initialize; placed prefabs will use fallback cube.");
    }

    // --- World Editor ---
    GameHUD gameHud;
    DamageNumbers damageNumbers;
    WorldEditor worldEditor;
    DialogBox dialogBox;
    Minimap minimap;
    worldEditor.SetReferences(&registry, &worldGrid, &forest, &prefabLibrary, primRendererPtr);

    WorldRefresh::RefreshContext cellRefreshContext{
        renderer,
        forest,
        primRenderer,
        prefabLibrary,
        collisionWorld,
        worldEditor
    };
    const float startupCellCenter = worldGrid.GetCellSize() * 0.5f;
    // Build terrain + instances for the startup cell (centre of grassland cell 0,0).
    {
        int startCX = 0, startCZ = 0;
        WorldCell* startCell = WorldRefresh::FindCellAtWorldPosition(worldGrid,
                                                                     startupCellCenter,
                                                                     startupCellCenter,
                                                                     startCX, startCZ);
        if (startCell)
            WorldRefresh::RefreshCellVisuals(*startCell, cellRefreshContext);
        else
            forest.Populate(renderer, 80, 50.0f); // fallback if no cell data
    }

    // Load sample Content/ assets and log them (stub — no GPU resources yet).
    {
        GR_ZONE_SCOPED_N("Asset Load");
        MaterialAsset mat;
        AssetLoader::LoadMaterial("Content/Materials/default.material.json", mat);

        PrefabAsset prefab;
        AssetLoader::LoadPrefab("Content/Prefabs/tree.prefab.json", prefab);

        SceneAsset scene;
        AssetLoader::LoadScene("Content/Scenes/test.scene.json", scene);
    }

    // ── ThirdParty subsystem smoke tests ──────────────────────────────────
    ThirdPartyBootstrap::InitializeAndRunSmokeTests();
    AudioManager audioManager;
    // Current tp::Audio wrapper is one-shot only; this is non-looping startup BGM.
    audioManager.PlayBGM("Content/Audio/bgm_field.ogg");
    // ── End ThirdParty smoke tests ─────────────────────────────────────────

    // --- Camera + player movement (now owned by CameraController) ---
    CameraController camController;
    PlayerActor playerActor;
    RuntimeScene runtimeScene(playerActor, primRenderer);
    // Spawn in the center of grassland cell (0,0), derived from world cell size.
    // This keeps the player well inside the first terrain patch and away from
    // any cell-boundary void on the first frame.
    camController.Init(startupCellCenter, 0.0f, startupCellCenter, 0.0f, -0.5f);
    runtimeScene.InitEnemies(startupCellCenter, startupCellCenter);

    renderer.SetCameraPosition(startupCellCenter, 0.0f, startupCellCenter);
    renderer.SetCameraRotation(0.0f, -0.5f);
    imguiLayer.SetAudioManager(&audioManager);
    // Center the mouse before the loop
    RECT windowRect;
    GetClientRect(window.GetHandle(), &windowRect);
    POINT centerPoint{ (windowRect.right - windowRect.left) / 2, (windowRect.bottom - windowRect.top) / 2 };
    ClientToScreen(window.GetHandle(), &centerPoint);
    SetCursorPos(centerPoint.x, centerPoint.y);
    camController.SetCenterPoint(centerPoint);
    InputActionMap actionMap = InputActionMap::Default();
    camController.SetInputActionMap(&actionMap);
    camController.SetCollisionWorld(&collisionWorld);

    bool firstFrame = true;
    bool dialogSmokeTestShown = false;
    float debugClearColorTime = 0.0f; // dev-only: drives the animated clear-color pulse
    FrameTiming::State frameTimingState;
    FrameTiming::Initialize(frameTimingState);
    InputEdge::State inputEdgeState;
    bool wasPauseActionDown = false;
    bool wasDebugActionDown = false;
    bool wasReloadActionDown = false;
    bool wasInteractActionDown = false;
    bool wasAttackActionDown = false;
    CursorMode::State cursorModeState;
    bool useTerrainPatch = true;
    // Track the cell the player was in last frame to detect cell-crossing.
    // Initialize from the actual spawn position at the center of cell (0,0).
    int lastPlayerCX = 0, lastPlayerCZ = 0;
    worldGrid.WorldToCell(startupCellCenter, startupCellCenter, lastPlayerCX, lastPlayerCZ);
    WorldReload::ReloadContext worldReloadContext{
        registry,
        worldGrid,
        prefabLibrary,
        worldEditor,
        camController,
        cellRefreshContext,
        lastPlayerCX,
        lastPlayerCZ
    };
    // Main game loop: process Win32 messages, update, draw, repeat.
    while (window.ProcessEvents())
    {
        float deltaTime = FrameTiming::BeginFrame(frameTimingState);

        // Check if the window is active
        if (GetForegroundWindow() != window.GetHandle()) {
            continue; // Skip the loop if the window is not active
        }

        // Temporary startup dialog line for feature smoke testing.
        if (!dialogSmokeTestShown)
        {
            dialogBox.Show("???", "The wind carries a strange scent from the east...");
            dialogSmokeTestShown = true;
        }

        dialogBox.Update(deltaTime);

        // --- Toggle keys (edge-detect so they fire once per press) ---

        // Esc: toggle pause menu (was: exit the program).
        if (actionMap.IsPressed(InputAction::TogglePause, wasPauseActionDown))
            imguiLayer.TogglePauseMenu();

        // F1: toggle debug overlay.
        if (actionMap.IsPressed(InputAction::ToggleDebug, wasDebugActionDown))
            imguiLayer.ToggleDebugOverlay();

        // F5: reload Asset Registry and World Grid without restarting.
        // Also rebuilds terrain + forest for the active cell and respawns instances.
        if (actionMap.IsPressed(InputAction::ReloadAssets, wasReloadActionDown))
        {
            WorldReload::ReloadAssetsAndWorld(worldReloadContext);
        }

        const bool interactPressed = actionMap.IsPressed(InputAction::Interact, wasInteractActionDown);

        // Handle quit/resume signals from the UI.
        if (imguiLayer.WantsQuit())
            break;
        imguiLayer.ClearFrameFlags();

        // T / G — terrain toggle (only when not paused).
        if (!imguiLayer.IsPauseMenuOpen())
        {
            if (InputEdge::PollTPressed(inputEdgeState))
                useTerrainPatch = true;

            if (InputEdge::PollGPressed(inputEdgeState))
                useTerrainPatch = false;
        }

        // Show/hide system cursor and re-center mouse based on pause state.
        // Show cursor when paused OR when the World Editor is in placement mode.
        const bool paused = imguiLayer.IsPauseMenuOpen();
        const bool editorActive = worldEditor.IsEditorInteractionActive();
        const bool wantCursorVisible = paused || editorActive;
        CursorMode::ApplyCursorVisibility(cursorModeState, wantCursorVisible);

        if (!paused && dialogBox.IsOpen() && interactPressed)
            dialogBox.Dismiss();

        // Animate the clear color so you can see it is updating.
        debugClearColorTime += deltaTime;
        float r = 0.2f + 0.2f * sinf(debugClearColorTime);
        float g = 0.2f + 0.2f * sinf(debugClearColorTime * 1.7f);
        float b = 0.3f + 0.2f * sinf(debugClearColorTime * 2.3f);

        // --- Camera + movement (now handled by CameraController) ---
        // Movement: enabled as long as the pause menu is closed.
        //   Player can still walk/jump while World Editor Placement Mode is active.
        // Mouse look: disabled during Placement Mode so the cursor stays free for
        //   clicking on the ground.  Re-enabled when Placement Mode turns off.
        //   To avoid a sudden camera jump when mouse-look re-enables, we treat the
        //   first frame after the transition as a "first frame" (skips the delta).
        const bool allowMovement  = !paused;
        const bool allowMouseLook = !paused && !editorActive;

        // Detect the moment Placement Mode turns OFF so we can reset mouse baseline.
        CursorMode::HandleMouseLookTransition(cursorModeState, allowMouseLook, centerPoint, firstFrame);

        // F — edge-detect unconditionally to keep state consistent while paused.
        const bool attackPressed = actionMap.IsPressed(InputAction::Attack, wasAttackActionDown);
        const bool playerIsGrounded = camController.IsGrounded();
        runtimeScene.BeginPlayerFrame(deltaTime, actionMap, playerIsGrounded, attackPressed, camController);

        camController.Update(deltaTime, allowMovement, allowMouseLook, firstFrame, renderer);

        // --- Cell-crossing detection: rebuild terrain instantly on biome change ---
        // This gives hard biome borders with no loading screen.
        {
            int playerCX = 0, playerCZ = 0;
            worldGrid.WorldToCell(camController.GetPlayerX(), camController.GetPlayerZ(),
                                  playerCX, playerCZ);
            if (playerCX != lastPlayerCX || playerCZ != lastPlayerCZ)
            {
                WorldCell* newCell = worldGrid.FindCell(playerCX, playerCZ);
                if (newCell)
                {
                    std::ostringstream ss;
                    ss << "Cell change: (" << lastPlayerCX << "," << lastPlayerCZ
                       << ") -> (" << playerCX << "," << playerCZ
                       << ") biome=" << newCell->terrainBiome;
                    LOG_INFO(ss.str());
                    WorldRefresh::RefreshCellVisuals(*newCell, cellRefreshContext);
                }
                lastPlayerCX = playerCX;
                lastPlayerCZ = playerCZ;
            }
        }

        // --- Left-click placement ---
        const WorldEditorFrameOps::PlacementResult placementResult = WorldEditorFrameOps::HandlePlacementClick(
            window.GetHandle(),
            InputEdge::PollLeftButtonClicked(inputEdgeState),
            editorActive,
            worldEditor,
            worldGrid,
            camController,
            renderer);
        if (placementResult.editedCellInstances)
        {
            WorldCell* activeCell = worldGrid.FindCell(placementResult.activeCellX, placementResult.activeCellZ);
            if (activeCell)
                WorldRefresh::RefreshCellVisuals(*activeCell, cellRefreshContext);
        }

        // Pass camera info and FPS stats to ImGuiLayer for the debug overlay.
        imguiLayer.SetCameraInfo(camController.GetCamX(), camController.GetCamY(), camController.GetCamZ(),
                                 camController.GetYaw(),  camController.GetPitch());
        imguiLayer.SetFrameStats(frameTimingState.displayFPS, deltaTime);
        // Rebuild runtime actor visuals for this frame (player, future enemies, NPCs).
        // Pass current player XZ (post camController.Update) so enemy AI is up-to-date.
        runtimeScene.BeginFrame(deltaTime, renderer,
                                camController.GetPlayerX(),
                                camController.GetPlayerZ());

        const CombatSystem& combatSystem = runtimeScene.GetCombatSystem();
        if (!paused)
        {
            for (int hitIndex = 0; hitIndex < combatSystem.GetRecentEnemyHitCount(); ++hitIndex)
            {
                const CombatSystem::EnemyHitRecord& hit = combatSystem.GetRecentEnemyHits()[hitIndex];
                damageNumbers.Spawn(hit.damage, hit.x, hit.y, hit.z);
            }
        }
        if (!paused)
            damageNumbers.Update(deltaTime);

        // F — player attack (ATB-gated, ignored while paused).
        // Runs after BeginPlayerFrame so the ATB readiness check uses the current frame's value.
        if (!paused && attackPressed && runtimeScene.TriggerPlayerAttack(camController))
            audioManager.PlaySFX("Content/Audio/sfx_attack.wav");

        runtimeScene.SubmitActors(camController, prefabLibrary);

        renderer.ClearScreen(r, g, b, 1.0f);
        {
            GR_ZONE_SCOPED_N("Renderer Frame");
            renderer.DrawSky();
            // draw terrain/ground
            if (useTerrainPatch) renderer.DrawTerrainPatch();
            else renderer.DrawGroundPlane();
            // draw the forest
            forest.Draw(renderer);
            // draw placed primitive prefab instances
            primRenderer.Draw(renderer);
            renderer.DrawRotatingTriangle(deltaTime);

            // ImGui: begin frame, draw UI panels, then render ImGui draw data.
            imguiLayer.BeginFrame();
            if (!imguiLayer.IsPauseMenuOpen())
            {
                gameHud.Draw(playerActor.stats, ImGui::GetIO());
                damageNumbers.Draw(camController.GetCamX(),
                                   camController.GetCamY(),
                                   camController.GetCamZ(),
                                   camController.GetYaw(),
                                   camController.GetPitch(),
                                   static_cast<float>(window.GetWidth()),
                                   static_cast<float>(window.GetHeight()));
                dialogBox.Draw(ImGui::GetIO());
                minimap.Draw(worldGrid,
                             camController.GetPlayerX(), camController.GetPlayerZ(),
                             camController.GetYaw(), ImGui::GetIO());
            }
            // Draw the World Editor panel inside the ImGui frame.
            WorldEditorFrameOps::DrawEditorPanelForActiveCell(
                worldEditor, worldGrid, camController, renderer);
            // Combat debug overlay (hitboxes, radii, state labels).
            if (imguiLayer.showCombatDebug)
            {
                imguiLayer.DrawCombatDebug(
                    runtimeScene.GetCombatSystem(),
                    runtimeScene.GetEnemies(),
                    runtimeScene.GetEnemyCount(),
                    camController.GetCamX(),
                    camController.GetCamY(),
                    camController.GetCamZ(),
                    camController.GetYaw(),
                    camController.GetPitch(),
                    static_cast<float>(window.GetWidth()),
                    static_cast<float>(window.GetHeight()));
            }
            imguiLayer.EndFrame();

            renderer.PresentFrame();
        }
        GR_FRAME_MARK;
        Sleep(1); // tiny sleep so we don't peg CPU at 100%
    }
    primRenderer.Shutdown();
    forest.Shutdown();
    imguiLayer.Shutdown();
    audioManager.Shutdown();
    ThirdPartyBootstrap::Shutdown();
    textureCache.ReleaseAll();
    renderer.Shutdown();
    window.Close();
    return 0;
}

// main.cpp
// Creates the window, initializes D3D11, runs a simple game loop that clears the screen.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cmath>
#include <cstdint>
#include <algorithm> // for std::clamp
#include <sstream>   // for std::ostringstream (cell crossing log)
// --- Hacky but simple approach for day 1 ---
// We include the .cpp files to avoid headers for now.
// This is NOT how big projects do it, but it's a good beginner stepping stone.
#include "../platform/win32/Win32Window.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../game/Forest.hpp"
#include "../game/CameraController.hpp"
#include "../game/PrefabLibrary.hpp"
#include "../game/PrimitiveRenderer.hpp"
#include "../ui/ImGuiLayer.hpp"
#include "../ui/WorldEditor.hpp"
#include "../assets/AssetLoader.hpp"
#include "../assets/AssetRegistry.hpp"
#include "../world/WorldGrid.hpp"
#include "WorldRuntimeRefresh.hpp"
#include <logger/Logger.hpp>
// We defined the classes in the other .cpp files.
// For this beginner seed, the simplest way is to forward-declare them here
// and rely on the linker. (Later we will convert to headers.)
class Win32Window;
class D3D11Renderer;

// Tell the compiler these classes exist somewhere else.
extern "C" __declspec(dllimport) int __stdcall MessageBoxW(HWND, LPCWSTR, LPCWSTR,unsigned int);



// ThirdParty subsystem wrappers (from the ThirdParty static library)
#include "tp_audio.hpp"
#include "tp_physics.hpp"
#include "tp_navigation.hpp"
#include "tp_image.hpp"
#include "tp_texture.hpp"
#include "tp_tracy.hpp"

// ImGui for WantCaptureMouse check
#include "../../third_party/imgui/imgui.h"

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
    WorldEditor worldEditor;
    worldEditor.SetReferences(&registry, &worldGrid, &forest, &prefabLibrary, primRendererPtr);

    WorldRuntimeRefresh::WorldRuntimeRefreshContext worldRuntimeRefresh{
        renderer,
        forest,
        primRenderer,
        worldEditor
    };
    const float startupCellCenter = worldGrid.GetCellSize() * 0.5f;
    // Build terrain + instances for the startup cell (centre of grassland cell 0,0).
    {
        int startCX = 0, startCZ = 0;
        WorldCell* startCell = WorldRuntimeRefresh::FindCellAtWorldPosition(worldGrid,
                                                                            startupCellCenter,
                                                                            startupCellCenter,
                                                                            startCX, startCZ);
        if (startCell)
            WorldRuntimeRefresh::RefreshCellVisuals(*startCell, worldRuntimeRefresh);
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
    // Audio: initialize the miniaudio engine (opens the default audio device).
    tp::Audio::Init();

    // Physics: initialize Jolt and run a quick one-step smoke test.
    tp::PhysicsBodyId physGroundId, physSphereId;
    if (tp::Physics::Init())
    {
        physGroundId = tp::Physics::AddStaticGround(0.0f);
        physSphereId = tp::Physics::AddDynamicSphere(0.0f, 5.0f, 0.0f, 0.5f, 1.0f);
        // Take one physics step so we know integration runs without crashing.
        {
            GR_ZONE_SCOPED_N("Physics Step");
            tp::Physics::Step(1.0f / 60.0f);
        }
        float sx = 0.0f, sy = 0.0f, sz = 0.0f;
        tp::Physics::GetBodyPosition(physSphereId, sx, sy, sz);
        OutputDebugStringA("[Game] Physics smoke test: sphere stepped OK.\n");
    }

    // Navigation: init (navmesh build is deferred until level geometry is ready).
    tp::Nav::Init();

    // Image: attempt to load Content/Textures/placeholder.png (may not exist yet).
    {
        tp::Image img;
        tp::Image::Load("Content/Textures/placeholder.png", img);
        img.Free(); // safe to call even if load failed
    }

    // DirectXTex smoke test: load placeholder.png via DirectXTex and log metadata.
    tp::Texture::SmokeTest();
    // ── End ThirdParty smoke tests ─────────────────────────────────────────

    // Simple loop: process messages + render frames.
    float t = 0.0f;

    // --- Camera + player movement (now owned by CameraController) ---
    CameraController camController;
    // Spawn in the center of grassland cell (0,0), derived from world cell size.
    // This keeps the player well inside the first terrain patch and away from
    // any cell-boundary void on the first frame.
    camController.Init(startupCellCenter, 0.0f, startupCellCenter, 0.0f, -0.5f);

    renderer.SetCameraPosition(startupCellCenter, 0.0f, startupCellCenter);
    renderer.SetCameraRotation(0.0f, -0.5f);
    // Center the mouse before the loop
    RECT windowRect;
    GetClientRect(window.GetHandle(), &windowRect);
    POINT centerPoint{ (windowRect.right - windowRect.left) / 2, (windowRect.bottom - windowRect.top) / 2 };
    ClientToScreen(window.GetHandle(), &centerPoint);
    SetCursorPos(centerPoint.x, centerPoint.y);
    camController.SetCenterPoint(centerPoint);

    bool firstFrame = true;
    bool prevEditorActive = false;  // tracks previous frame's placement-mode state
    LARGE_INTEGER perfFreq{};
    QueryPerformanceFrequency(&perfFreq);

    LARGE_INTEGER prevCounter{};
    QueryPerformanceCounter(&prevCounter);
    bool useTerrainPatch = true;
    bool wasTDown = false;
    bool wasGDown = false;
    // Toggle key edge-detection state (track previous frame state).
    bool wasEscDown = false;
    bool wasF1Down  = false;
    bool wasF5Down  = false;
    bool wasLButtonDown = false;
    // Track the cell the player was in last frame to detect cell-crossing.
    // Initialize from the actual spawn position at the center of cell (0,0).
    int lastPlayerCX = 0, lastPlayerCZ = 0;
    worldGrid.WorldToCell(startupCellCenter, startupCellCenter, lastPlayerCX, lastPlayerCZ);
    // FPS smoothing accumulator.
    float fpsAccum = 0.0f;
    int   fpsFrames = 0;
    float displayFPS = 0.0f; 
    bool cursorVisible = false; // track actual cursor visibility state we requested
    while (window.ProcessEvents())
    {
        LARGE_INTEGER currCounter{};
        QueryPerformanceCounter(&currCounter);

        float deltaTime = static_cast<float>(currCounter.QuadPart - prevCounter.QuadPart) /
            static_cast<float>(perfFreq.QuadPart);
        prevCounter = currCounter;

        // Clamp to avoid huge spikes when app loses focus
        deltaTime = std::clamp(deltaTime, 0.0f, 0.05f);
        
        // FPS calculation (smooth over ~0.5 s).
        fpsAccum += deltaTime;
        fpsFrames++;
        if (fpsAccum >= 0.5f)
        {
            displayFPS = static_cast<float>(fpsFrames) / fpsAccum;
            fpsAccum = 0.0f;
            fpsFrames = 0;
        }

        // Check if the window is active
        if (GetForegroundWindow() != window.GetHandle()) {
            continue; // Skip the loop if the window is not active
        }

        // --- Toggle keys (edge-detect so they fire once per press) ---

        // Esc: toggle pause menu (was: exit the program).
        bool escDown = (GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0;
        if (escDown && !wasEscDown)
            imguiLayer.TogglePauseMenu();
        wasEscDown = escDown;

        // F1: toggle debug overlay.
        bool f1Down = (GetAsyncKeyState(VK_F1) & 0x8000) != 0;
        if (f1Down && !wasF1Down)
            imguiLayer.ToggleDebugOverlay();
        wasF1Down = f1Down;

        // F5: reload Asset Registry and World Grid without restarting.
        // Also rebuilds terrain + forest for the active cell and respawns instances.
        bool f5Down = (GetAsyncKeyState(VK_F5) & 0x8000) != 0;
        if (f5Down && !wasF5Down)
        {
            LOG_INFO("F5: reloading Asset Registry and World Grid...");
            bool regOk  = registry.Reload();    // safe: keeps old data on parse error
            bool gridOk = worldGrid.Reload();   // safe: keeps old grid on parse error

            if (regOk)
            {
                LOG_INFO("F5: AssetRegistry reloaded OK.");
                prefabLibrary.Reload(registry);
                worldEditor.RefreshPrefabList();
            }
            else
                LOG_WARN("F5: AssetRegistry reload failed — keeping old registry.");

            if (gridOk)
            {
                LOG_INFO("F5: WorldGrid reloaded OK — rebuilding terrain for active cell...");
                int playerCX = 0, playerCZ = 0;
                WorldCell* playerCell = WorldRuntimeRefresh::FindCellForPlayerPosition(worldGrid, camController,
                                                                                       playerCX, playerCZ);
                if (playerCell)
                {
                    WorldRuntimeRefresh::RefreshCellVisuals(*playerCell, worldRuntimeRefresh);
                    lastPlayerCX = playerCX;
                    lastPlayerCZ = playerCZ;
                    LOG_INFO("F5: terrain rebuilt and instances respawned.");
                }
            }
            else
            {
                LOG_WARN("F5: WorldGrid reload failed — keeping old world grid.");
            }
        }
        wasF5Down = f5Down;

        // Handle quit/resume signals from the UI.
        if (imguiLayer.WantsQuit())
            break;
        imguiLayer.ClearFrameFlags();

        // T / G — terrain toggle (only when not paused).
        if (!imguiLayer.IsPauseMenuOpen())
        {
            bool tDown = (GetAsyncKeyState('T') & 0x8000) != 0;
            if (tDown && !wasTDown)
                useTerrainPatch = true;
            wasTDown = tDown;

            bool gDown = (GetAsyncKeyState('G') & 0x8000) != 0;
            if (gDown && !wasGDown)
                useTerrainPatch = false;
            wasGDown = gDown;
        }

        // Show/hide system cursor and re-center mouse based on pause state.
        // Show cursor when paused OR when the World Editor is in placement mode.
       
        const bool paused = imguiLayer.IsPauseMenuOpen();
        const bool editorActive = worldEditor.IsPlacementModeActive();
        const bool wantCursorVisible = paused || editorActive;
        if (wantCursorVisible != cursorVisible)
        {
            if (wantCursorVisible)
            {
                // Ensure visible regardless of current internal ShowCursor counter.
                while (ShowCursor(TRUE) < 0) {}
            }
            else
            {
                // Ensure hidden regardless of current internal ShowCursor counter.
                while (ShowCursor(FALSE) >= 0) {}
            }
            cursorVisible = wantCursorVisible;
        }

        // Animate the clear color so you can see it is updating.
        t += deltaTime * 1.0f;
        float r = 0.2f + 0.2f * sinf(t);
        float g = 0.2f + 0.2f * sinf(t * 1.7f);
        float b = 0.3f + 0.2f * sinf(t * 2.3f);

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
        if (prevEditorActive && !editorActive)
        {
            // Re-center cursor and skip the first mouse-look delta to avoid a jump.
            SetCursorPos(centerPoint.x, centerPoint.y);
            firstFrame = true;
        }
        prevEditorActive = editorActive;

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
                    WorldRuntimeRefresh::RefreshCellVisuals(*newCell, worldRuntimeRefresh);
                }
                lastPlayerCX = playerCX;
                lastPlayerCZ = playerCZ;
            }
        }

        // --- Left-click placement ---
        // Check ImGui::GetIO().WantCaptureMouse BEFORE BeginFrame for the
        // value from the previous frame — correct for input processing.
        bool lbDown = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
        bool lbClicked = lbDown && !wasLButtonDown;
        wasLButtonDown = lbDown;

        if (lbClicked && editorActive && !ImGui::GetIO().WantCaptureMouse)
        {
            // Get cursor position in window client coordinates.
            POINT clickPos;
            GetCursorPos(&clickPos);
            ScreenToClient(window.GetHandle(), &clickPos);

            // Determine the active cell from the player position.
            // Use direct WorldToCell here because placement only needs coordinates,
            // not a validated cell lookup.
            int activeCX = 0, activeCZ = 0;
            worldGrid.WorldToCell(camController.GetPlayerX(), camController.GetPlayerZ(),
                                  activeCX, activeCZ);

            worldEditor.HandlePlacement(
                clickPos,
                static_cast<float>(renderer.GetRenderWidth()),
                static_cast<float>(renderer.GetRenderHeight()),
                camController, renderer,
                activeCX, activeCZ);
        }

        // Pass camera info and FPS stats to ImGuiLayer for the debug overlay.
        {
            imguiLayer.SetCameraInfo(camController.GetCamX(), camController.GetCamY(), camController.GetCamZ(),
                                     camController.GetYaw(),  camController.GetPitch());
            imguiLayer.SetFrameStats(displayFPS, deltaTime);
        }
        // Clear dynamic/runtime visuals before rebuilding them for this frame.
        primRenderer.ClearRuntimeInstances();

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
            // Draw the World Editor panel inside the ImGui frame.
            {
                // Use direct WorldToCell here because the panel displays the current
                // grid coordinates even when no loaded cell exists there.
                int activeCX = 0, activeCZ = 0;
                worldGrid.WorldToCell(camController.GetPlayerX(), camController.GetPlayerZ(),
                                      activeCX, activeCZ);
                worldEditor.DrawPanel(activeCX, activeCZ, renderer);
            }
            imguiLayer.EndFrame();

            renderer.PresentFrame();
        }
        GR_FRAME_MARK;
        Sleep(1); // tiny sleep so we don't peg CPU at 100%
    }
    // before renderer.Shutdown();
    primRenderer.Shutdown();
    forest.Shutdown();
    imguiLayer.Shutdown();
    tp::Nav::Shutdown();
    tp::Physics::Shutdown();
    tp::Audio::Shutdown();
    renderer.Shutdown();
    window.Close();
    return 0;
}

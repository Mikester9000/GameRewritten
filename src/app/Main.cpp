// main.cpp
// Creates the window, initializes D3D11, runs a simple game loop that clears the screen.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cmath>
#include <cstdint>
#include <algorithm> // for std::clamp
// --- Hacky but simple approach for day 1 ---
// We include the .cpp files to avoid headers for now.
// This is NOT how big projects do it, but it's a good beginner stepping stone.
#include "../platform/win32/Win32Window.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../game/Forest.hpp"
#include "../ui/ImGuiLayer.hpp"
#include "../assets/AssetLoader.hpp"
#include "../assets/AssetRegistry.hpp"
#include "../world/WorldGrid.hpp"
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

    // Create and initialize forest (after renderer is initialized)
    Forest forest;
    if (!forest.Initialize(renderer))
    {
        MessageBoxW(nullptr, L"Failed to initialize Forest.", L"Error", 0);
        return 1;
    }
    // Populate forest from the first active world cell (cell-driven open world).
    // The player starts at world (0,0), which is cell (0,0).
    {
        int startCX = 0, startCZ = 0;
        auto activeCells = worldGrid.GetActiveCells(startCX, startCZ, 0);
        if (!activeCells.empty() && activeCells[0].forestEnabled)
        {
            const WorldCell& c = activeCells[0];
            forest.Populate(renderer, c.forestTreeCount, c.forestRadius,
                            c.CenterX(), c.CenterZ());
        }
        else
        {
            forest.Populate(renderer, 80, 50.0f); // fallback if no cell data
        }
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
    float yaw = 0.0f, pitch = 0.0f;
    renderer.SetCameraPosition(0.0f, 0.0f, -3.0f);
    renderer.SetCameraRotation(0.0f, -0.5f);
    // Player (world) state separate from camera (insert here)
float playerX = 0.0f;
float playerY = 0.0f;
float playerZ = -3.0f;

// Camera follow parameters (tweakable)
const float cameraDistance = 4.0f; // how far behind the player the camera sits
const float cameraHeight = 2.0f;   // camera height above player
const float eyeOffset = 1.0f;      // how high the player's "eyes" sit above ground

// Helper to update camera from player each frame
auto updateCameraFromPlayer = [&]() {
    float camOffsetX = -sinf(yaw) * cameraDistance;
    float camOffsetZ = -cosf(yaw) * cameraDistance;
    float camX = playerX + camOffsetX;
    float camZ = playerZ + camOffsetZ;
    float camY = playerY + cameraHeight;
    renderer.SetCameraPosition(camX, camY, camZ);
    };
// Set initial camera once from player
updateCameraFromPlayer();
    // Center the mouse before the loop
    RECT windowRect;
    GetClientRect(window.GetHandle(), &windowRect);
    POINT centerPoint{ (windowRect.right - windowRect.left) / 2, (windowRect.bottom - windowRect.top) / 2 };
    ClientToScreen(window.GetHandle(), &centerPoint);
    SetCursorPos(centerPoint.x, centerPoint.y);

    bool firstFrame = true;
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
    // FPS smoothing accumulator.
    float fpsAccum = 0.0f;
    int   fpsFrames = 0;
    float displayFPS = 0.0f;
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
        // Also repopulates the forest from the reloaded cell data so changes
        // to tree_count/radius in cell JSON take effect immediately.
        bool f5Down = (GetAsyncKeyState(VK_F5) & 0x8000) != 0;
        if (f5Down && !wasF5Down)
        {
            LOG_INFO("F5: reloading Asset Registry and World Grid...");
            bool regOk  = registry.Reload();    // safe: keeps old data on parse error
            bool gridOk = worldGrid.Reload();   // safe: keeps old grid on parse error

            if (regOk)
                LOG_INFO("F5: AssetRegistry reloaded OK.");
            else
                LOG_WARN("F5: AssetRegistry reload failed — keeping old registry.");

            if (gridOk)
            {
                LOG_INFO("F5: WorldGrid reloaded OK — repopulating forest...");
                // Rebuild forest from updated cell data so gameplay sees the changes.
                // Compute which cell the player is currently standing in.
                int playerCX = 0, playerCZ = 0;
                worldGrid.WorldToCell(playerX, playerZ, playerCX, playerCZ);

                // Find the exact cell by coordinates (not by array index) to be safe.
                auto reloadedCells = worldGrid.GetActiveCells(playerCX, playerCZ, 0);
                const WorldCell* playerCell = nullptr;
                for (const auto& c : reloadedCells)
                {
                    if (c.cx == playerCX && c.cz == playerCZ)
                    {
                        playerCell = &c;
                        break;
                    }
                }

                if (playerCell && playerCell->forestEnabled)
                {
                    forest.Populate(renderer, playerCell->forestTreeCount,
                                    playerCell->forestRadius,
                                    playerCell->CenterX(), playerCell->CenterZ());
                    LOG_INFO("F5: forest repopulated from cell data.");
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
        const bool paused = imguiLayer.IsPauseMenuOpen();
        if (paused)
        {
            ShowCursor(TRUE);
        }
        else
        {
            ShowCursor(FALSE);
        }

        // Animate the clear color so you can see it is updating.
        t += deltaTime * 1.0f;
        float r = 0.2f + 0.2f * sinf(t);
        float g = 0.2f + 0.2f * sinf(t * 1.7f);
        float b = 0.3f + 0.2f * sinf(t * 2.3f);

        // Mouse look — skip when pause menu is open so the mouse can interact
        // with ImGui widgets.
        int mouseDeltaX = 0, mouseDeltaY = 0;
        POINT mouse;
        GetCursorPos(&mouse);

        if (!paused && !firstFrame) {
            mouseDeltaX = mouse.x - centerPoint.x;
            mouseDeltaY = mouse.y - centerPoint.y;
            yaw += mouseDeltaX * 0.005f;
            pitch -= mouseDeltaY * 0.005f;
            if (pitch > 1.5f) pitch = 1.5f;
            if (pitch < -1.5f) pitch = -1.5f;
        }
        if (!paused)
            SetCursorPos(centerPoint.x, centerPoint.y);
        firstFrame = false;

        // Update renderer rotation from yaw/pitch
        renderer.SetCameraRotation(yaw, pitch);

        // Movement + gravity — skipped while pause menu is open.
        if (!paused)
        {
            // Movement uses yaw for forward/right directions (player-facing movement)
            float forwardX = sinf(yaw);
            float forwardZ = cosf(yaw);
            float rightX = cosf(yaw);
            float rightZ = -sinf(yaw);

            const float moveSpeed = 4.0f; // units per second
            const float moveStep = moveSpeed * deltaTime;

            // Apply horizontal movement to the player position (XZ plane)
            if (GetAsyncKeyState('W') & 0x8000) { playerX += forwardX * moveStep; playerZ += forwardZ * moveStep; }
            if (GetAsyncKeyState('S') & 0x8000) { playerX -= forwardX * moveStep; playerZ -= forwardZ * moveStep; }
            if (GetAsyncKeyState('A') & 0x8000) { playerX -= rightX * moveStep; playerZ -= rightZ * moveStep; }
            if (GetAsyncKeyState('D') & 0x8000) { playerX += rightX * moveStep; playerZ += rightZ * moveStep; }

            // Gravity and jumping applied to player vertical velocity
            const float gravity = -20.0f;
            const float jumpVelocity = 6.0f;
            const float terminalVelocity = -30.0f;

            float velocityY = renderer.GetCameraVelocityY(); // reuse existing velocity storage
            if (!renderer.GetIsGrounded()) {
                velocityY += gravity * deltaTime;
            }
            else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                velocityY = jumpVelocity;
                renderer.SetIsGrounded(false);
            }

            if (velocityY < terminalVelocity) velocityY = terminalVelocity;
            renderer.SetCameraVelocityY(velocityY);

            // Integrate vertical motion into playerY
            playerY += velocityY * deltaTime;

            // Ground collision / terrain snap (operate on player position)
            float groundY = 0.0f;
            if (renderer.IsTerrainAvailable()) {
                groundY = renderer.SampleTerrainHeight(playerX, playerZ) + eyeOffset;
            }

            if (playerY <= groundY) {
                playerY = groundY;
                velocityY = 0.0f;
                renderer.SetCameraVelocityY(0.0f);
                renderer.SetIsGrounded(true);
            }
            else if (renderer.GetIsGrounded()) {
                // While grounded and walking, keep player snapped to terrain so movement follows slopes
                playerY = groundY;
                renderer.SetCameraVelocityY(0.0f);
            }

            // Compute camera from player and apply rotation
            updateCameraFromPlayer();
            renderer.SetCameraRotation(yaw, pitch);
        }

        // Pass camera info and FPS stats to ImGuiLayer for the debug overlay.
        {
            float cx, cy, cz, cyaw, cpitch;
            renderer.GetCameraPosition(cx, cy, cz);
            renderer.GetCameraRotation(cyaw, cpitch);
            imguiLayer.SetCameraInfo(cx, cy, cz, cyaw, cpitch);
            imguiLayer.SetFrameStats(displayFPS, deltaTime);
        }
        renderer.ClearScreen(r, g, b, 1.0f);
        {
            GR_ZONE_SCOPED_N("Renderer Frame");
            renderer.DrawSky();
            
                
            
            
            // draw terrain/ground
            if (useTerrainPatch) renderer.DrawTerrainPatch();
            else renderer.DrawGroundPlane();
            // draw the forest
            forest.Draw(renderer);
            renderer.DrawRotatingTriangle(deltaTime);

            // ImGui: begin frame, draw UI panels, then render ImGui draw data.
            imguiLayer.BeginFrame();
            imguiLayer.EndFrame();

            renderer.PresentFrame();
        }
        GR_FRAME_MARK;
        Sleep(1); // tiny sleep so we don't peg CPU at 100%
    }
    // before renderer.Shutdown();
    forest.Shutdown();
    imguiLayer.Shutdown();
    tp::Nav::Shutdown();
    tp::Physics::Shutdown();
    tp::Audio::Shutdown();
    renderer.Shutdown();
    window.Close();
    return 0;
}
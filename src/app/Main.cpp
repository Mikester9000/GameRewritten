// ============================================================
// FILE: src/app/Main.cpp
// SYSTEM: App
// ROLE: app startup/shutdown wiring and frame orchestration
// DO NOT: add permanent gameplay logic here; own it in a subsystem.
// OWNS: system construction, dependency injection, and game loop.
// ============================================================
//
// ================================================================
// HOW THIS FILE IS STRUCTURED  (Lego Block Architecture)
// ================================================================
// Main.cpp is the ORCHESTRATOR. It:
//   1. Constructs every engine "lego block" (one system = one object)
//   2. Wires them together by passing references/pointers
//   3. Runs the game loop calling each block's Update() in order
//   4. Shuts every block down cleanly on exit
//
// TO ADD A NEW SYSTEM ("snap in a new lego block"):
//   STEP A — Add the include in the INCLUDES section below.
//             Example: #include "../game/quests/QuestSystem.hpp"
//   STEP B — Declare an instance in the SYSTEM OBJECTS section.
//             Example: QuestSystem questSystem;
//   STEP C — Call Init() in the INITIALIZATION section.
//             Example: questSystem.Init(registry);
//   STEP D — Call Update(dt) in the matching GAME LOOP section.
//             Example: questSystem.Update(gameplayDt);
//   STEP E — Call Shutdown() in the SHUTDOWN section.
//             Example: questSystem.Shutdown();
//
// ================================================================
// SYSTEM SECTIONS (in order of execution each frame):
//   [1]  Frame Timing
//   [2]  Input
//   [3]  UI State (pause, dialog)
//   [4]  Player Update
//   [5]  Camera Update
//   [6]  World Update (cell streaming, editor)
//   [7]  Combat Update (enemies, hits, audio events)
//   [8]  Actor Visuals Submission
//   [9]  Draw (clear → 3D → UI → present)
// ================================================================

// ================================================================
// [LEGO: INCLUDES]
// Add new system headers here, grouped by subsystem.
// Each group maps to a block in the SYSTEM OBJECTS section below.
// ================================================================
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>
#include <cmath>
#include <sstream>   // for std::ostringstream (cell crossing log)
#include <unordered_map>
#include <vector>

// -- Platform --
#include "../platform/win32/Win32Window.hpp"

// -- Rendering --
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../rendering/d3d11/D3D11RendererHelpers.hpp"
#include "../renderer/PostProcessToggles.hpp"
#include "../rendering/d3d11/Terrain_Renderer.hpp"

// -- World / Environment --
#include "../world/WorldGrid.hpp"
#include "../world/DayNightCycle.hpp"
#include "../world/WeatherSystem.hpp"
// EXTEND: #include "../world/YourNewWorldSystem.hpp"

// -- Game / Scene --
#include "../game/Forest.hpp"
#include "../game/CameraController.hpp"
#include "../game/actors/PlayerActor.hpp"
#include "../game/PrefabLibrary.hpp"
#include "../game/PrimitiveRenderer.hpp"
#include "../game/RuntimeScene.hpp"
#include "../game/physics/CollisionWorld.hpp"
#include "../game/ParticleSystem.hpp"
#include "../game/world/EventZone.hpp"
#include "../game/loot/LootTable.hpp"
// EXTEND: #include "../game/quests/QuestSystem.hpp"
// EXTEND: #include "../game/dialogue/DialogueTree.hpp"

// -- Animation --
#include "../game/animation/AnimPackManifestLoader.hpp"
#include "../game/animation/AnimClipLoader.hpp"
#include "../game/animation/AnimationComponent.hpp"
#include "../game/animation/AnimationSystem.hpp"
#include "../game/animation/PlayerAnimBridge.hpp"
#include "../game/animation/AnimEventDispatch.hpp"

// -- UI --
#include "../ui/GameHUD.hpp"
#include "../ui/WeakPointReticle.hpp"
#include "../ui/ImGuiLayer.hpp"
#include "../ui/TacticalPauseMenu.hpp"
#include "../ui/DialogBox.hpp"
#include "../ui/Minimap.hpp"
#include "../ui/WorldEditor.hpp"
// EXTEND: #include "../ui/QuestJournal.hpp"
// EXTEND: #include "../ui/ShopMenu.hpp"

// -- Assets --
#include "../assets/AssetLoader.hpp"
#include "../assets/AssetRegistry.hpp"
#include "../assets/CreationMaterialLoader.hpp"
#include "../assets/TextureCache.hpp"

// -- Audio --
#include "../audio/AudioManager.hpp"
// EXTEND: #include "../audio/MusicManager.hpp"

// -- App layer (helpers used only by Main) --
#include "FrameTiming.hpp"
#include "InputActionMap.hpp"
#include "InputEdgeState.hpp"
#include "CursorModeController.hpp"
#include "EngineContext.hpp"
#include "WorldEditorFrameOps.hpp"
#include "WorldReloadFlow.hpp"
#include "ThirdPartyBootstrap.hpp"
#include "WorldRuntimeRefresh.hpp"
#include <logger/Logger.hpp>

// -- Third party --
#include "tp_tracy.hpp"
#include <imgui.h>

namespace
{
constexpr float kMissConfirmDelaySec = 0.17f;
constexpr float kMissIndicatorForwardOffset = 1.8f;
constexpr float kMissIndicatorHeightOffset = 2.8f;
constexpr float kCombatMusicReleaseDelaySec = 5.0f;

void QueueAttackFeedback(const RuntimeScene& runtimeScene,
                         const CameraController& camController,
                         AudioManager& audioManager,
                         bool& pendingMissIndicator,
                         float& pendingMissTimerSec,
                         float& pendingMissWorldX,
                         float& pendingMissWorldY,
                         float& pendingMissWorldZ)
{
    const EnemyActor* lockedTarget = runtimeScene.GetLockedTarget();
    float attackYaw = camController.GetYaw();

    if (lockedTarget)
    {
        const float toTargetX = lockedTarget->x - camController.GetPlayerX();
        const float toTargetZ = lockedTarget->z - camController.GetPlayerZ();
        const float toTargetLenSq = (toTargetX * toTargetX) + (toTargetZ * toTargetZ);
        if (toTargetLenSq > 0.0001f)
            attackYaw = atan2f(toTargetX, toTargetZ);
    }

    pendingMissWorldX = camController.GetPlayerX() + sinf(attackYaw) * kMissIndicatorForwardOffset;
    pendingMissWorldY = camController.GetPlayerGroundY() + kMissIndicatorHeightOffset;
    pendingMissWorldZ = camController.GetPlayerZ() + cosf(attackYaw) * kMissIndicatorForwardOffset;
    pendingMissTimerSec = kMissConfirmDelaySec;
    pendingMissIndicator = true;
    audioManager.PlaySFX("Content/Audio/sfx_attack.wav");
}

void HandleEventZoneTrigger(int eventID, DialogBox& dialogBox, GameHUD& gameHud)
{
    switch (eventID)
    {
    case 1:
        dialogBox.Show("Guide", "You've entered the ruins...");
        gameHud.PushToast("Event triggered: Ancient Ruins");
        LOG_INFO("EventZone: triggered eventID=1");
        break;
    case 2:
        dialogBox.Show("Guide", "Stay alert. Something is watching from the ridge.");
        gameHud.PushToast("Event triggered: Watcher Ridge");
        LOG_INFO("EventZone: triggered eventID=2");
        break;
    default:
        LOG_INFO("EventZone: triggered eventID=" + std::to_string(eventID));
        break;
    }
}

void UpdateCombatMusicState(const RuntimeScene& runtimeScene,
                            float dt,
                            float& cooldownSec,
                            AudioManager& audioManager)
{
    bool anyEnemyInCombatState = false;
    for (int enemyIndex = 0; enemyIndex < runtimeScene.GetEnemyCount(); ++enemyIndex)
    {
        const EnemyActor& enemy = runtimeScene.GetEnemies()[enemyIndex];
        if (enemy.isDead)
            continue;

        if (enemy.state == EnemyState::Chase || enemy.state == EnemyState::Attack)
        {
            anyEnemyInCombatState = true;
            break;
        }
    }

    if (anyEnemyInCombatState)
    {
        cooldownSec = kCombatMusicReleaseDelaySec;
        audioManager.SetCombatState(true);
        return;
    }

    if (cooldownSec > 0.0f)
        cooldownSec -= dt;

    if (cooldownSec <= 0.0f)
    {
        cooldownSec = 0.0f;
        audioManager.SetCombatState(false);
    }
}
}

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    // ================================================================
    // [LEGO: WINDOW]
    // The Win32 window is the root surface. Everything else attaches to it.
    // To change resolution or title, edit the constants here.
    // EXTEND: pass a config struct from a settings file instead of literals.
    // ================================================================
    Win32Window window;
    if (!window.Create(1280, 720, L"My Engine Seed (D3D11)"))
    {
        MessageBoxW(nullptr, L"Failed to create window.", L"Error", 0);
        return 1;
    }

    // ================================================================
    // [LEGO: RENDERER]
    // D3D11Renderer owns the swap chain, depth buffer, and all shaders.
    // It must be initialized before any other system that submits draw calls.
    // EXTEND: replace with a D3D12Renderer or VulkanRenderer here when ready —
    //   swap the type and keep the same Initialize/Shutdown contract.
    // ================================================================
    D3D11Renderer renderer;
    if (!renderer.Initialize(window.GetHandle(), window.GetWidth(), window.GetHeight()))
    {
        MessageBoxW(nullptr, L"Failed to initialize D3D11.", L"Error", 0);
        return 1;
    }

    EngineContext engineContext;
    if (!engineContext.Initialize(renderer))
    {
        LOG_WARN("Main: EngineContext render-world wiring failed; terrain will use renderer fallback path.");
    }

    // ================================================================
    // [LEGO: ASSET SYSTEMS]
    // TextureCache, AssetRegistry, and related loaders form the asset
    // pipeline. Load order matters: Registry must be loaded before
    // PrefabLibrary, and TextureCache must attach to renderer first.
    // EXTEND: add a new loader (e.g. SoundBankLoader) by declaring it
    //   here and calling Load() with a registry path.
    // ================================================================

    // --- Texture Cache ---
    // Loads D3D11 textures via DirectXTex and caches SRVs by file path.
    TextureCache textureCache;
    renderer.SetTextureCache(&textureCache);

    // --- Asset Registry ---
    // Maps scoped IDs (e.g. "textures.placeholder") to file paths.
    // Press F5 at runtime to reload without restarting.
    AssetRegistry registry;
    registry.Load("Content/AssetRegistry.json");

    // ================================================================
    // [LEGO: WORLD SYSTEMS]
    // WorldGrid, DayNightCycle, and WeatherSystem drive the open world.
    // Each is independent — update order below controls their interaction.
    // EXTEND: add a new world-layer system (e.g. EcosystemSystem for
    //   wildlife simulation) by declaring it here and calling
    //   ecosystem.Update(dt) in the [7] World Update game-loop section.
    // ================================================================

    // --- World Grid ---
    // Loads Content/World/world.json which lists all world cells.
    // Each cell drives terrain + forest for that chunk of the open world.
    WorldGrid worldGrid;
    worldGrid.Load("Content/World/world.json");

    // --- Day/night cycle ---
    // Advances an accelerated 24-hour clock; updates sun direction + ambient each frame.
    DayNightCycle dayNight;
    dayNight.Init(9.0f); // start at 9 AM

    // --- Weather system ---
    // Drives ambient modifiers and wind strength; transitions probabilistically.
    WeatherSystem weather;

    // --- Ambient particle system ---
    // Dust motes / leaves drawn as ImGui background dots — zero extra draw calls.
    ParticleSystem particles;

    // ================================================================
    // [LEGO: SCENE / GAMEPLAY OBJECTS]
    // PrimitiveRenderer, CollisionWorld, WorldEditor, HUD, and dialog
    // all attach here. Forest is the vegetation renderer.
    // EXTEND: add a new gameplay system (e.g. QuestSystem) here:
    //   QuestSystem questSystem;
    //   questSystem.Init(registry);
    // ================================================================

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
    WeakPointReticle weakPointReticle;
    TacticalPauseMenu tacticalPauseMenu;
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

        const std::vector<std::string> animationIds = registry.GetIdsByPrefix("animations.");
        if (animationIds.empty())
        {
            LOG_INFO("Main: no 'animations.*' entries found in AssetRegistry.");
        }
        else
        {
            for (const std::string& animationId : animationIds)
            {
                const std::string animationPath = registry.GetPath(animationId);
                if (animationPath.size() < 5 ||
                    animationPath.compare(animationPath.size() - 5, 5, ".anim") != 0)
                {
                    continue;
                }

                AnimationAsset animation;
                if (!AssetLoader::LoadAnimation(animationPath, animation))
                    LOG_WARN("Main: failed to load animation asset id '" + animationId + "'");
            }
        }

        // Load all registered Creation-Engine materials (materials.*).
        {
            const std::vector<std::string> materialIds = registry.GetIdsByPrefix("materials.");
            if (materialIds.empty())
            {
                LOG_INFO("Main: no 'materials.*' entries found in AssetRegistry.");
            }
            else
            {
                for (const std::string& matId : materialIds)
                {
                    const std::string matPath = registry.GetPath(matId);
                    if (matPath.size() < 5 ||
                        matPath.compare(matPath.size() - 5, 5, ".json") != 0)
                    {
                        continue;
                    }
                    CreationMaterialLoader::Load(matPath);
                }
            }
        }
    }

    // ================================================================
    // [LEGO: ANIMATION SYSTEM]
    // Loads animation clips from a named pack manifest, builds a clip
    // library, then advances AnimationComponent instances each frame.
    // EXTEND: add new character packs by loading another manifest:
    //   auto npcPaths = AnimPackManifestLoader::Load("npc_pack");
    //   // then build npcClipLibrary the same way as heroClipLibrary
    // ================================================================

    // ── Animation system — load hero_pack clips into a named library ───────
    std::unordered_map<std::string, LoadedAnimClip> heroClipLibrary;
    {
        const std::vector<std::string> orderedPaths =
            AnimPackManifestLoader::Load("hero_pack");

        for (const std::string& animPath : orderedPaths)
        {
            LoadedAnimClip clip = AnimClipLoader::Load(animPath);
            if (!clip.name.empty())
                heroClipLibrary[clip.name] = std::move(clip);
        }
        LOG_INFO("Main: hero_pack clip library built — "
                 + std::to_string(heroClipLibrary.size()) + " clip(s)");
    }

    // AnimationComponent for the player actor (one component per actor).
    AnimationComponent playerAnimComp;
    {
        auto it = heroClipLibrary.find("idle");
        if (it != heroClipLibrary.end())
        {
            playerAnimComp.activeClip = &it->second;
            playerAnimComp.playing    = true;
        }
    }

    // Per-frame bone transform output buffers (one per AnimationComponent).
    std::vector<AnimationComponent> animComponents = { playerAnimComp };
    std::vector<BoneTransformBuffer> animBuffers;
    // ── End animation system init ──────────────────────────────────────────

    // ================================================================
    // [LEGO: THIRD-PARTY SUBSYSTEMS + AUDIO]
    // All third-party libraries (Jolt physics, miniaudio, Recast nav,
    // DirectXTex, Tracy) are bootstrapped here via ThirdPartyBootstrap.
    // AudioManager wraps miniaudio for BGM, SFX, and ambient tracks.
    // EXTEND: add a new third-party library by:
    //   1. Adding its smoke-test call in ThirdPartyBootstrap.hpp
    //   2. Adding a wrapper class in src/audio/ or a relevant folder
    //   3. Calling its Init() here and Shutdown() at the bottom
    // ================================================================

    // ── ThirdParty subsystem smoke tests ──────────────────────────────────
    ThirdPartyBootstrap::InitializeAndRunSmokeTests();
    AudioManager audioManager;
    // Start looping field-day BGM and forest ambient at launch.
    audioManager.PlayBGM("Content/Audio/bgm_field_day.ogg");
    audioManager.PlayAmbient("Content/Audio/amb_forest_day_loop.wav");
    // ── End ThirdParty smoke tests ─────────────────────────────────────────

    // ================================================================
    // [LEGO: PLAYER + CAMERA + RUNTIME SCENE]
    // CameraController owns player movement and camera follow.
    // RuntimeScene owns enemy/NPC instances and drives combat.
    // EXTEND: add new actor types to RuntimeScene (src/game/RuntimeScene.hpp)
    //   by following the same Init/Update/SubmitVisual pattern.
    // ================================================================

    // --- Camera + player movement (now owned by CameraController) ---
    CameraController camController;
    PlayerActor playerActor;
    RuntimeScene runtimeScene(playerActor, primRenderer);
    // Spawn in the center of grassland cell (0,0), derived from world cell size.
    // This keeps the player well inside the first terrain patch and away from
    // any cell-boundary void on the first frame.
    camController.Init(startupCellCenter, 0.0f, startupCellCenter, 0.0f, -0.5f);
    runtimeScene.InitEnemies(startupCellCenter, startupCellCenter);
    runtimeScene.InitNpcs(startupCellCenter, startupCellCenter);
    runtimeScene.InitRestPoints(startupCellCenter, startupCellCenter);

    // Register enemy drop tables: enemyType 0 → 70% Health Herb, 30% Ore Shard.
    LootTable::Get().Register(0, {
        { 1, 70.0f, 1 },   // itemID 1 = Health Herb
        { 2, 30.0f, 1 }    // itemID 2 = Ore Shard
    });

    EventZoneRegistry eventZoneRegistry;
    eventZoneRegistry.AddZone({
        { startupCellCenter + 6.0f, 1.0f, startupCellCenter + 2.0f },
        { 2.5f, 2.0f, 2.5f },
        1,
        true,
        false
    });
    eventZoneRegistry.AddZone({
        { startupCellCenter + 12.0f, 1.0f, startupCellCenter + 10.0f },
        { 2.5f, 2.0f, 2.5f },
        2,
        true,
        false
    });

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

    // Initialise ambient particles centred on the startup spawn position.
    particles.Init(startupCellCenter, startupCellCenter);

    // Accumulated game time for wind shader (starts at 0).
    float gameTimeAccum = 0.0f;

    bool firstFrame = true;
    FrameTiming::State frameTimingState;
    FrameTiming::Initialize(frameTimingState);
    InputEdge::State inputEdgeState;
    bool wasPauseActionDown = false;
    bool wasDebugActionDown = false;
    bool wasReloadActionDown = false;
    bool wasInteractActionDown = false;
    bool wasAttackActionDown = false;
    bool wasLockOnActionDown = false;
    bool wasTacticalPauseHeld = false; // tracks edge transitions for SFX
    bool wasStatusKeyDown = false;
    bool wasMapKeyDown = false;
    bool wasTerrainUnlitKeyDown = false;
    bool wasTerrainNoCullKeyDown = false;
    bool wasTerrainWireframeKeyDown = false;
    bool statusScreenOpen = false;
    bool mapScreenOpen = false;
    int lastObservedPlayerLevel = playerActor.stats.level;
    CursorMode::State cursorModeState;
    bool useTerrainPatch = true;
    bool pendingMissIndicator = false;
    bool loggedRenderValidationFailure = false;
    float pendingMissTimerSec = 0.0f;
    float pendingMissWorldX = 0.0f;
    float pendingMissWorldY = 0.0f;
    float pendingMissWorldZ = 0.0f;
    // Track the cell the player was in last frame to detect cell-crossing.
    // Initialize from the actual spawn position at the center of cell (0,0).
    int lastPlayerCX = 0, lastPlayerCZ = 0;
    float combatMusicCooldownSec = 0.0f;
    worldGrid.WorldToCell(startupCellCenter, startupCellCenter, lastPlayerCX, lastPlayerCZ);
    if (WorldCell* spawnCell = worldGrid.FindCell(lastPlayerCX, lastPlayerCZ))
        gameHud.SetAreaName(spawnCell->terrainBiome);
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
    // ================================================================
    // GAME LOOP — one pass per frame
    // Each numbered section is a "lego slot". Add new per-frame logic
    // to the matching numbered section below; do not mix concerns.
    // ================================================================
    // Main game loop: process Win32 messages, update, draw, repeat.
    while (window.ProcessEvents())
    {
        // ============================================================
        // [1] FRAME TIMING
        // Establish deltaTime. All systems downstream read this value.
        // EXTEND: add a fixed-timestep accumulator here if you need
        //   deterministic physics updates separate from render rate.
        // ============================================================
        float deltaTime = FrameTiming::BeginFrame(frameTimingState);
        runtimeScene.UpdateImpactFeedback(deltaTime);

        // ============================================================
        // [1a] ENVIRONMENT UPDATE (day/night, weather, biome blend)
        // EXTEND: add a new time-driven environment effect here.
        //   Example: seasonSystem.Update(deltaTime);
        // ============================================================
        // --- Day/night cycle + weather update ---
        dayNight.Advance(deltaTime);
        weather.Update(deltaTime);
        worldGrid.UpdateBiomeTransition(deltaTime);

        // Accumulate game time for the wind shader (unscaled, not paused).
        gameTimeAccum += deltaTime;

        // Push sun direction and ambient to renderer.
        {
            float sx, sy, sz;
            dayNight.GetSunDirection(sx, sy, sz);
            renderer.SetSunDirection(sx, sy, sz);
            // Combine day/night ambient with weather modifier.
            renderer.SetAmbientStrength(dayNight.GetAmbientStrength() * weather.GetAmbientModifier());
        }
        renderer.Tick(deltaTime);
        engineContext.Tick(deltaTime);
        if (!engineContext.Validate() && !loggedRenderValidationFailure)
        {
            LOG_WARN("Main: render validation failed; fallback rendering path may be active.");
            loggedRenderValidationFailure = true;
        }

        // Push wind time and strength to primitive renderer for tree sway.
        primRenderer.SetGlobalTime(gameTimeAccum);
        primRenderer.SetWindStrength(weather.GetWindStrength());

        // ============================================================
        // [2] INPUT
        // Read raw key/button state — no logic here, just booleans.
        // EXTEND: add new InputAction enum values in InputActionMap.hpp,
        //   bind a key in InputActionMap::Default(), then read it here.
        //   Example:
        //     const bool craftPressed = actionMap.IsPressed(InputAction::OpenCrafting, wasCraftDown);
        // ============================================================
        // Read all input for this frame. No logic yet — just read state.
        const bool pausePressed  = actionMap.IsPressed(InputAction::TogglePause, wasPauseActionDown);
        const bool debugPressed  = actionMap.IsPressed(InputAction::ToggleDebug, wasDebugActionDown);
        const bool reloadPressed = actionMap.IsPressed(InputAction::ReloadAssets, wasReloadActionDown);
        const bool interactPressed = actionMap.IsPressed(InputAction::Interact, wasInteractActionDown);
        const bool attackPressed = actionMap.IsPressed(InputAction::Attack, wasAttackActionDown);
        const bool lockOnPressed = actionMap.IsPressed(InputAction::LockOn, wasLockOnActionDown);
        // Tab is reserved for Tactical Pause. VK_TAB is checked directly
        // because it is not a combat InputAction — it controls time scale only.
        constexpr int kTacticalPauseKey   = VK_TAB;
        constexpr int kStatusScreenKey = 'C';
        constexpr int kMapScreenKey = 'M';
        constexpr int kTerrainUnlitToggleKey = VK_F6;
        constexpr int kTerrainNoCullToggleKey = VK_F7;
        constexpr int kTerrainWireframeToggleKey = VK_F8;
        const bool tacticalPauseHeld = actionMap.IsVirtualKeyHeld(kTacticalPauseKey);
        const bool statusKeyDown = actionMap.IsVirtualKeyHeld(kStatusScreenKey);
        const bool mapKeyDown = actionMap.IsVirtualKeyHeld(kMapScreenKey);
        const bool terrainUnlitKeyDown = actionMap.IsVirtualKeyHeld(kTerrainUnlitToggleKey);
        const bool terrainNoCullKeyDown = actionMap.IsVirtualKeyHeld(kTerrainNoCullToggleKey);
        const bool terrainWireframeKeyDown = actionMap.IsVirtualKeyHeld(kTerrainWireframeToggleKey);
        const bool statusPressed = statusKeyDown && !wasStatusKeyDown;
        const bool mapPressed = mapKeyDown && !wasMapKeyDown;
        const bool terrainUnlitPressed = terrainUnlitKeyDown && !wasTerrainUnlitKeyDown;
        const bool terrainNoCullPressed = terrainNoCullKeyDown && !wasTerrainNoCullKeyDown;
        const bool terrainWireframePressed = terrainWireframeKeyDown && !wasTerrainWireframeKeyDown;
        wasStatusKeyDown = statusKeyDown;
        wasMapKeyDown = mapKeyDown;
        wasTerrainUnlitKeyDown = terrainUnlitKeyDown;
        wasTerrainNoCullKeyDown = terrainNoCullKeyDown;
        wasTerrainWireframeKeyDown = terrainWireframeKeyDown;

        // Tactical Pause SFX on edge transitions.
        if (tacticalPauseHeld && !wasTacticalPauseHeld)
            audioManager.PlayTacticalPauseEnter();
        else if (!tacticalPauseHeld && wasTacticalPauseHeld)
            audioManager.PlayTacticalPauseExit();
        wasTacticalPauseHeld = tacticalPauseHeld;

        // Scale gameplay delta time to 15% while Tactical Pause is open.
        // UI, dialog, and HUD animations always use the unscaled deltaTime.
        const float kTacticalTimeScale = 0.15f;
        const float scaledDt = tacticalPauseHeld ? deltaTime * kTacticalTimeScale : deltaTime;
        float gameplayDt = scaledDt;

        // ============================================================
        // [3] UI STATE
        // Menus, dialogs, and cursor-visibility decisions.
        // EXTEND: add new screen toggles here (shop, quest journal, map).
        //   Pattern: bool shopOpen = false; ... if (shopKeyPressed) shopOpen = !shopOpen;
        //   Then call shopMenu.Draw(io) in the [9] Draw section.
        // ============================================================
        // Apply pause, cursor visibility, dialog update.
        // Determines what is allowed in the steps below.
        if (GetForegroundWindow() != window.GetHandle())
            continue;

        dialogBox.Update(deltaTime);
        imguiLayer.SetLetterboxEventActive(dialogBox.IsOpen());

        if (pausePressed)
            imguiLayer.TogglePauseMenu();
        if (debugPressed)
            imguiLayer.ToggleDebugOverlay();
        if (terrainUnlitPressed)
            renderer.SetTerrainUnlitDebug(!renderer.IsTerrainUnlitDebugEnabled());
        if (terrainNoCullPressed)
            renderer.SetTerrainDisableCullingDebug(!renderer.IsTerrainDisableCullingDebugEnabled());
        if (terrainWireframePressed)
            renderer.SetTerrainWireframeDebug(!renderer.IsTerrainWireframeDebugEnabled());
        if (reloadPressed)
        {
            WorldReload::ReloadAssetsAndWorld(worldReloadContext);
            gameHud.ShowSavingIndicator(1.25f);
        }

        if (imguiLayer.WantsQuit())
            break;
        imguiLayer.ClearFrameFlags();

        const bool paused = imguiLayer.IsPauseMenuOpen();
        if (paused)
        {
            // Freeze gameplay updates while the pause menu is open.
            // This ensures enemy AI, player state, and combat do not advance.
            // UI and HUD still update using the unscaled delta.
            gameplayDt = 0.0f;
        }
        const float combatDt = gameplayDt * imguiLayer.GetCombatSpeedScale() * runtimeScene.GetGameplayTimeScale();
      

        const bool editorActive = worldEditor.IsEditorInteractionActive();
        const bool tacticalMenuActive = tacticalPauseHeld;
        const bool wantCursorVisible = paused || editorActive || tacticalMenuActive;
        CursorMode::ApplyCursorVisibility(cursorModeState, wantCursorVisible);

        if (!paused)
        {
            if (InputEdge::PollTPressed(inputEdgeState))
                useTerrainPatch = true;

            if (InputEdge::PollGPressed(inputEdgeState))
                useTerrainPatch = false;
        }

        if (!paused && dialogBox.IsOpen() && interactPressed)
            dialogBox.Dismiss();
        gameHud.SetContextPrompt("Press E to continue", dialogBox.IsOpen() && dialogBox.IsComplete() && !paused);

        if (!paused && !tacticalPauseHeld && statusPressed)
        {
            statusScreenOpen = !statusScreenOpen;
            if (statusScreenOpen)
                mapScreenOpen = false;
        }
        if (!paused && !tacticalPauseHeld && mapPressed)
        {
            mapScreenOpen = !mapScreenOpen;
            if (mapScreenOpen)
                statusScreenOpen = false;
        }
        if (paused)
        {
            statusScreenOpen = false;
            mapScreenOpen = false;
        }
        gameHud.SetStatusScreenOpen(statusScreenOpen);
        gameHud.SetMapScreenOpen(mapScreenOpen);

        // ============================================================
        // [4] PLAYER UPDATE
        // Drives player actor state machine (idle/attack/dodge/...).
        // EXTEND: add a companion system update here:
        //   companionActor.Update(combatDt, playerActor, camController);
        // ============================================================
        // Update player state, stats, and dodge burst.
        // Uses input and grounded state from above.
        const bool playerIsGrounded = camController.IsGrounded();
        runtimeScene.BeginPlayerFrame(combatDt, actionMap, playerIsGrounded, attackPressed, camController);
        if (playerActor.stats.level > lastObservedPlayerLevel)
        {
            gameHud.TriggerLevelUpOverlay(playerActor.stats.level);
            lastObservedPlayerLevel = playerActor.stats.level;
        }

        // ============================================================
        // [5] CAMERA UPDATE
        // Moves and rotates the camera. Must run AFTER player so
        // lock-on target positions are up to date.
        // EXTEND: add cutscene camera override here:
        //   if (cutsceneSystem.IsActive()) cutsceneSystem.ApplyCamera(camController);
        // ============================================================
        // Move and rotate the camera based on input and player state.
        if (!paused)
        {
            const EnemyActor* lockedTarget = runtimeScene.GetLockedTarget();
            if (lockedTarget)
            {
                camController.SetCombatCameraFocus(true, lockedTarget->x, lockedTarget->y + 1.6f, lockedTarget->z);
            }
            else
            {
                camController.SetCombatCameraFocus(false, 0.0f, 0.0f, 0.0f);
            }
            // Apply lock-on bias before free-look input so mouse deltas and
            // lock framing blend together in one camera update path.
            if (lockedTarget)
                camController.BiasYawTowardTarget(lockedTarget->x, lockedTarget->z, combatDt);
        }
        else
        {
            camController.SetCombatCameraFocus(false, 0.0f, 0.0f, 0.0f);
        }

       

        const bool allowMovement = !paused;
        const bool allowMouseLook = !paused && !editorActive && !tacticalMenuActive;
        CursorMode::HandleMouseLookTransition(cursorModeState, allowMouseLook, centerPoint, firstFrame);
        camController.Update(gameplayDt, allowMovement, allowMouseLook, firstFrame, renderer);

        // ============================================================
        // [6] WORLD UPDATE
        // Cell crossing, asset hot-reload, world editor placement.
        // Must run AFTER camera so player position is current.
        // EXTEND: add quest zone / trigger zone checks here:
        //   questSystem.CheckZoneTriggers(playerPos);
        // ============================================================
        // Cell crossing detection, asset reload, editor placement.
        // Runs after camera so player position is up to date.
        {
            int playerCX;
            int playerCZ;
            worldGrid.WorldToCell(camController.GetPlayerX(), camController.GetPlayerZ(), playerCX, playerCZ);
            if (playerCX != lastPlayerCX || playerCZ != lastPlayerCZ)
            {
                WorldCell* newCell = worldGrid.FindCell(playerCX, playerCZ);
                if (newCell)
                {
                    std::ostringstream cellChangeMessage;
                    cellChangeMessage << "Cell change: (" << lastPlayerCX << "," << lastPlayerCZ
                                      << ") -> (" << playerCX << "," << playerCZ
                                      << ") biome=" << newCell->terrainBiome;
                    LOG_INFO(cellChangeMessage.str());
                    WorldRefresh::RefreshCellVisuals(*newCell, cellRefreshContext);
                    // Notify biome transition (WorldGrid blends smoothly over ~2.5s).
                    worldGrid.NotifyBiomeChange(newCell->terrainBiome);
                    gameHud.SetAreaName(newCell->terrainBiome);
                }
                lastPlayerCX = playerCX;
                lastPlayerCZ = playerCZ;
            }
        }

        eventZoneRegistry.Update({ camController.GetPlayerX(), camController.GetPlayerY(), camController.GetPlayerZ() },
                                 [&](int eventID) { HandleEventZoneTrigger(eventID, dialogBox, gameHud); });

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

        // ============================================================
        // [7] COMBAT & GAMEPLAY UPDATE
        // Enemy AI, hit resolution, damage numbers, audio events,
        // animation, respawn. All gameplay consequences land here.
        // EXTEND: add a new combat feedback hook after the audio hooks:
        //   if (runtimeScene.ConsumeSomethingNew()) audioManager.PlayNewSFX();
        // ============================================================
        // Update enemies, resolve hits, spawn damage numbers.
        // Runs after world so terrain and positions are final.
        runtimeScene.BeginFrame(combatDt, renderer,
                                camController.GetPlayerX(),
                                camController.GetPlayerY(),
                                camController.GetPlayerZ());
        runtimeScene.RefreshLockOnTarget();
        const CombatSystem& combat = runtimeScene.GetCombatSystem();

        // Update NPC dialog and rest point healing (both use cached player position from BeginFrame).
        if (!paused)
        {
            runtimeScene.UpdateNpcs(interactPressed, dialogBox);
            if (runtimeScene.UpdateRestPoint(interactPressed))
                gameHud.PushToast("Rested — HP and MP restored");
        }

        // Show loot drop toast if an enemy died and dropped something.
        {
            std::string lootToastMsg;
            if (runtimeScene.ConsumeLootToast(lootToastMsg))
                gameHud.PushToast(lootToastMsg);
        }

        float shakeAmplitude = 0.0f;
        float shakeDuration = 0.0f;
        if (runtimeScene.ConsumePendingCameraShake(shakeAmplitude, shakeDuration))
            camController.AddCameraShake(shakeAmplitude, shakeDuration);

        if (runtimeScene.ConsumePlayerHitFlash())
            gameHud.TriggerDamageFlash();

        // --- Audio event hooks ---
        if (runtimeScene.ConsumeEnemyDied())
            audioManager.PlayVictoryFanfare();

        if (runtimeScene.ConsumeEnemyAlert())
            audioManager.PlayEnemyAlertBark();

        if (runtimeScene.ConsumeParryOccurred())
            audioManager.PlayParrySFX();

        UpdateCombatMusicState(runtimeScene, combatDt, combatMusicCooldownSec, audioManager);

        {
            bool hasTarget = false;
            if (runtimeScene.ConsumeLockOnChanged(hasTarget))
            {
                if (hasTarget)
                    audioManager.PlayLockOnAcquire();
                else
                    audioManager.PlayLockOnBreak();
            }
        }

        if (pendingMissIndicator)
        {
            if (combat.GetRecentEnemyHitCount() > 0)
            {
                pendingMissIndicator = false;
                pendingMissTimerSec = 0.0f;
            }
            else
            {
                pendingMissTimerSec -= combatDt;
                if (pendingMissTimerSec <= 0.0f)
                {
                    runtimeScene.damageNumbers.SpawnMiss(
                        pendingMissWorldX,
                        pendingMissWorldY,
                        pendingMissWorldZ);
                    pendingMissIndicator = false;
                    pendingMissTimerSec = 0.0f;
                }
            }
        }

        if (!paused && lockOnPressed && !tacticalPauseHeld)
        {
            runtimeScene.ToggleLockOn();
        }

        if (!paused)
            runtimeScene.damageNumbers.Update(combatDt);

        // Ambient particles (dust/leaves) — always update using unscaled dt so
        // they feel natural even during Tactical Pause slow-motion.
        particles.Update(deltaTime, weather.GetWindStrength(),
                         camController.GetPlayerX(),
                         camController.GetPlayerGroundY(),
                         camController.GetPlayerZ());

        // --- Animation system per-frame update ---
        // Bridge player state → clip, then advance all components + sample bones.
        {
            const float prevPlayerAnimTime = animComponents.empty()
                ? 0.0f : animComponents[0].playbackTime;

            PlayerAnimBridge::Update(runtimeScene.GetPlayerActionState(),
                                     animComponents[0],
                                     heroClipLibrary);

            AnimationSystem::Advance(gameplayDt, animComponents, animBuffers);

            // Dispatch anim events (footstep SFX, hit windows, etc.).
            AnimEventDispatch::Dispatch(animComponents[0], prevPlayerAnimTime,
                                        runtimeScene.GetCombatSystemMutable(), gameplayDt);
        }

        if (runtimeScene.WantsRespawn())
        {
            camController.ResetToSpawn(
                runtimeScene.GetRespawnX(), 0.0f, runtimeScene.GetRespawnZ(),
                0.0f, -0.5f);
            runtimeScene.ClearRespawnFlag();
            firstFrame = true;
        }

        if (!paused && attackPressed && !tacticalPauseHeld)
        {
            // --- Attack priority: Limit Break → Surge Strike → Normal combo ---
            // Try each in order; stop at the first one that fires.
            bool attackHandled = false;

            // Priority 1: Limit Break (Shift held + F pressed while Limit is full).
            // InputAction::Dodge is bound to VK_SHIFT — we reuse it here as the modifier key.
            if (!attackHandled && actionMap.IsHeld(InputAction::Dodge))
                attackHandled = runtimeScene.TriggerLimitBreak(camController);

            // Priority 2: Surge Strike (F pressed while Surge is full).
            if (!attackHandled)
                attackHandled = runtimeScene.TriggerSurgeStrike(camController);

            // Priority 3: Normal two-step combo (always free).
            if (!attackHandled)
                attackHandled = runtimeScene.TriggerPlayerAttack(camController);

            if (attackHandled)
            {
                QueueAttackFeedback(runtimeScene,
                                    camController,
                                    audioManager,
                                    pendingMissIndicator,
                                    pendingMissTimerSec,
                                    pendingMissWorldX,
                                    pendingMissWorldY,
                                    pendingMissWorldZ);
            }
        }

        // ============================================================
        // [8] ACTOR VISUALS SUBMISSION
        // Push all actor states into the PrimitiveRenderer bucket for
        // this frame. Must run after all state is resolved.
        // EXTEND: add a new actor type's SubmitRuntimeVisual() here.
        // ============================================================
        // Submit all actor visual data to the primitive renderer.
        // Runs after all state is resolved for this frame.
        runtimeScene.SubmitActors(camController, prefabLibrary);

        imguiLayer.SetCameraInfo(camController.GetCamX(), camController.GetCamY(), camController.GetCamZ(),
                                 camController.GetYaw(), camController.GetPitch());
        imguiLayer.SetFrameStats(frameTimingState.displayFPS, deltaTime);
        gameHud.SetOpacity(imguiLayer.GetHudOpacity());
        gameHud.SetUltrawideLayoutEnabled(
            imguiLayer.UseUltrawideHudLayout(static_cast<float>(window.GetWidth()) / static_cast<float>(window.GetHeight())));

        // ============================================================
        // [9] DRAW
        // Clear → 3D scene → ImGui begin → HUD → ImGui end → Present.
        // NO game state changes here — read-only from all systems.
        // EXTEND: add a new HUD element inside the !paused block:
        //   questJournal.Draw(io);   // call Draw(), not Update()
        // ============================================================
        // Clear screen, draw world, draw UI, present.
        // Nothing in this section changes game state.
        renderer.ClearScreen(0.1f, 0.1f, 0.15f, 1.0f);
        {
            GR_ZONE_SCOPED_N("Renderer Frame");
            auto drawTerrainPass = [&]()
            {
                if (useTerrainPatch)
                    renderer.DrawTerrainPatch();
                else
                    renderer.DrawGroundPlane();
            };
            auto drawActorsPass = [&]()
            {
                forest.Draw(renderer);
                primRenderer.Draw(renderer);
            };
            auto drawLightingPass = [&]()
            {
                // TODO(next-ai): purpose=add full-screen lighting/post pass stage
                // required inputs/outputs=gbuffer or lit color target in/out
                // invariants=must execute after terrain/actor geometry and before debug overlays
                // acceptance checks=pass can be toggled independently without changing world update flow
                // file ownership/expected edit scope=src/app/Main.cpp only
            };

            renderer.DrawSky();
            drawTerrainPass();  // Render pass 1
            drawActorsPass();   // Render pass 2
            drawLightingPass(); // Render pass 3 (stub)
            engineContext.DebugDraw();

            imguiLayer.BeginFrame();

            // Ambient particles are drawn as ImGui background geometry so they sit
            // between the 3-D scene and HUD without needing a dedicated render pass.
            particles.Draw(camController.GetCamX(),
                           camController.GetCamY(),
                           camController.GetCamZ(),
                           camController.GetYaw(),
                           camController.GetPitch(),
                           static_cast<float>(window.GetWidth()),
                           static_cast<float>(window.GetHeight()));
            if (!imguiLayer.IsPauseMenuOpen())
            {
                const ImGuiIO&    io     = ImGui::GetIO();
                gameHud.SetDeathScreenActive(runtimeScene.IsDefeatScreenActive());
                gameHud.Draw(playerActor.stats, io, deltaTime);
                if (gameHud.ConsumeDeathRetryRequested())
                    runtimeScene.ConfirmRetryFromDefeat();
                gameHud.DrawTargetInfo(runtimeScene.GetLockedTarget(), io);
                gameHud.DrawOffScreenTargetIndicator(runtimeScene.GetLockedTarget(),
                                                     camController.GetCamX(),
                                                     camController.GetCamY(),
                                                     camController.GetCamZ(),
                                                     camController.GetYaw(),
                                                     camController.GetPitch(),
                                                     static_cast<float>(window.GetWidth()),
                                                     static_cast<float>(window.GetHeight()));
                weakPointReticle.Draw(runtimeScene.GetLockedTarget(),
                                      camController.GetCamX(),
                                      camController.GetCamY(),
                                      camController.GetCamZ(),
                                      camController.GetYaw(),
                                      camController.GetPitch(),
                                      static_cast<float>(window.GetWidth()),
                                      static_cast<float>(window.GetHeight()),
                                      imguiLayer.GetHudOpacity());
                gameHud.DrawComboIndicator(combat.comboStep,
                                           combat.comboTimer,
                                           CombatSystem::kComboWindowSec,
                                           io);
                if (tacticalPauseHeld)
                {
                    const TacticalCommand tacticalCmd = tacticalPauseMenu.Draw(playerActor.stats, io);
                    bool tacticalAttackHandled = false;

                    switch (tacticalCmd)
                    {
                    case TacticalCommand::BasicAttack:
                        tacticalAttackHandled = runtimeScene.TriggerPlayerAttack(camController);
                        break;
                    case TacticalCommand::SurgeStrike:
                        tacticalAttackHandled = runtimeScene.TriggerSurgeStrike(camController);
                        break;
                    case TacticalCommand::LimitBreak:
                        tacticalAttackHandled = runtimeScene.TriggerLimitBreak(camController);
                        break;
                    case TacticalCommand::None:
                    default:
                        break;
                    }

                    if (tacticalAttackHandled)
                    {
                        QueueAttackFeedback(runtimeScene,
                                            camController,
                                            audioManager,
                                            pendingMissIndicator,
                                            pendingMissTimerSec,
                                            pendingMissWorldX,
                                            pendingMissWorldY,
                                            pendingMissWorldZ);
                    }
                }
                runtimeScene.damageNumbers.Draw(camController.GetCamX(),
                                                camController.GetCamY(),
                                                camController.GetCamZ(),
                                                camController.GetYaw(),
                                                camController.GetPitch(),
                                                static_cast<float>(window.GetWidth()),
                                                static_cast<float>(window.GetHeight()));
                dialogBox.Draw(io);
                runtimeScene.DrawNpcNameTags(
                    camController.GetCamX(),
                    camController.GetCamY(),
                    camController.GetCamZ(),
                    camController.GetYaw(),
                    camController.GetPitch(),
                    static_cast<float>(window.GetWidth()),
                    static_cast<float>(window.GetHeight()));
                minimap.Draw(worldGrid,
                             camController.GetPlayerX(), camController.GetPlayerZ(),
                             camController.GetYaw(), io);

                imguiLayer.DrawLockOnMarker(
                    runtimeScene.GetLockedTarget(),
                    camController.GetCamX(),
                    camController.GetCamY(),
                    camController.GetCamZ(),
                    camController.GetYaw(),
                    camController.GetPitch(),
                    static_cast<float>(window.GetWidth()),
                    static_cast<float>(window.GetHeight()));
            }

            WorldEditorFrameOps::DrawEditorPanelForActiveCell(
                worldEditor, worldGrid, camController, renderer);

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
            FrameTiming::ApplyFrameLimit(frameTimingState, imguiLayer.GetFrameRateLimit(), imguiLayer.IsVSyncEnabled());
        }

        GR_FRAME_MARK;
        Sleep(1); // tiny sleep so we don't peg CPU at 100%
    }
    // ================================================================
    // [LEGO: SHUTDOWN]
    // Shut down every system in reverse initialization order.
    // EXTEND: add yourSystem.Shutdown() here for every new system
    //   that owns GPU resources, file handles, or threads.
    // ================================================================
    primRenderer.Shutdown();
    forest.Shutdown();
    imguiLayer.Shutdown();
    audioManager.Shutdown();
    ThirdPartyBootstrap::Shutdown();
    textureCache.ReleaseAll();
    engineContext.Shutdown();
    renderer.Shutdown();
    window.Close();
    return 0;
}

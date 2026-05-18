# Codebase Glossary & Table of Contents

Covers `src/` and `Shaders/`. Use this as the first stop when deciding where to add code,
which names to reuse, and which constraints to respect when modifying existing files.

See also: [Architecture.md](./Architecture.md), [SYSTEM_OWNERSHIP.md](./SYSTEM_OWNERSHIP.md),
[MAIN_CPP_PROTECTION.md](./MAIN_CPP_PROTECTION.md).

---

## Part 1 — System Map (Files → Responsibilities)

### 1.1 App Layer — `src/app/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `Main.cpp` | Win32 entry point (`wWinMain`). Constructs every subsystem, runs the 9-step frame loop, tears everything down on exit. | Add new per-frame calls in the numbered sections. Never reorder the 9 steps — order is load-bearing. |
| `FrameTiming.hpp` | `FrameTiming::State` + `Initialize()` + `BeginFrame()`. Computes `deltaTime` via `QueryPerformanceCounter`, clamps to 50 ms, maintains smoothed FPS. | Replace timing only here; never inline timing logic in `Main.cpp`. |
| `InputActionMap.hpp` | `InputAction` enum (12 actions), `InputActionMap` struct (bindings map), `IsHeld()`, `IsPressed()`, `IsVirtualKeyHeld()`. Default WASD/F/Shift/Q/E/Esc/F1/F5 layout. | Add new `InputAction` values here, never hard-code `GetAsyncKeyState` elsewhere. |
| `InputEdgeState.hpp` | `InputEdge::State` (6 bool latches). Edge-trigger helpers for T, G, Escape, F1, F5, LMB. | Add a bool + `PollXPressed()` helper here for any new edge-triggered key. |
| `CursorModeController.hpp` | `CursorMode::State`. `ApplyCursorVisibility()` manages Win32 `ShowCursor` counter. `HandleMouseLookTransition()` warps cursor on mouse-look enable and sets `firstFrame=true`. | Only touch if cursor/mouse-look rules change. |
| `WorldEditorFrameOps.hpp` | App-level helpers: `GetActiveCellFromPlayer()`, `HandlePlacementClick()`, `DrawEditorPanelForActiveCell()`. Bridges `WorldEditor ↔ CameraController ↔ D3D11Renderer`. | Safe to extend with new editor frame operations. |
| `WorldReloadFlow.hpp` | `WorldReload::ReloadContext` + `ReloadAssetsAndWorld()`. On F5: reloads registry and grid, then rebuilds prefab library, editor prefab list, and active-cell visuals. | Extend here if more systems need F5 rebuild. |
| `WorldRuntimeRefresh.hpp` | `WorldRefresh::RefreshContext` + `RefreshCellVisuals()` + `FindCellAtWorldPosition()` + `FindCellForPlayerPosition()`. Called on cell-crossing and F5. Populates terrain, forest, collision AABBs, and primitive instances for one cell. | Core wiring for cell transitions. Add new cell-driven systems here. |
| `ThirdPartyBootstrap.hpp` | `ThirdPartyBootstrap::InitializeAndRunSmokeTests()` + `Shutdown()`. Initializes `tp::Audio`, `tp::Physics`, `tp::Nav`, `tp::Image`, `tp::Texture`. | Add new third-party init/shutdown here — never in `Main.cpp` directly. |

---

### 1.2 Platform Layer — `src/platform/win32/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `Win32Window.hpp/.cpp` | Creates the OS window, runs `ProcessEvents()` (the message pump), exposes `GetHandle()`, `GetWidth()`, `GetHeight()`. Supports an optional `WndProcHook` for message interception. | Only touch if window creation settings change (resolution, title). |

---

### 1.3 Rendering Layer — `src/rendering/d3d11/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `D3D11Renderer.hpp/.cpp` | Owns the D3D11 device, context, swap chain, and depth buffer. Exposes `Initialize()`, `Shutdown()`, `ClearScreen()`, `PresentFrame()`, `DrawSky()`, `DrawGroundPlane()`, `DrawTerrainPatch()`, `RebuildTerrainPatch()`, `ClearTerrainPatch()`, `SampleTerrainHeight()`, `SetCameraPosition()`, `SetCameraRotation()`, `GetDevice()`, `GetContext()`, `SetTextureCache()`. Holds constant buffer slots b0 (transform/MVP) and b1 (light). | Add new draw methods here. Never allocate GPU buffers in game code — always call renderer. |
| `D3D11RendererHelpers.hpp/.cpp` | Pure CPU helpers: `BuildTerrainHeightGrid()`, `SelectBiomeGradient()`, `ApplyBiomeTerrainTuning()`, `HashNoise()`, `SmoothNoise()`, `HeightToColor()`, `EmitTerrainTriangleA/B()`, `BuildSceneMatrices()`, `BuildDefaultDirectionalLight()`. Shared vertex layout `TerrainVertex` (40 bytes). | Add new terrain biomes or noise algorithms here. |

**Shader constant buffer slots (binding contract):**

| Slot | Name | Used by |
|---|---|---|
| `b0` | `PerDraw` (MVP + world + tintColor) | `prim_vs.hlsl`, `tree_vs.hlsl`, ground shaders |
| `b1` | `LightCBuffer` (lightDir + lightColor + ambientStrength, 32 bytes) | `prim_ps.hlsl`, `ground_ps.hlsl`, `sky_ps.hlsl` |

---

### 1.4 Game Layer — `src/game/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `CameraController.hpp/.cpp` | Owns all player + camera state: `m_playerX/Y/Z`, `m_yaw`, `m_pitch`, `m_camX/Y/Z`, `m_velocityY`, `m_isGrounded`, dodge velocity/timer. `Init()` sets spawn, `Update()` drives WASD, gravity, jump, dodge, mouse-look, collision, terrain-snap, and camera follow. `ResetToSpawn()` for respawn. `BiasYawTowardTarget()` for lock-on framing. | Safest touch point for movement feel tweaks. Public floats (`moveSpeed`, `gravity`, `jumpVelocity`, etc.) can be tuned without touching logic. |
| `Forest.hpp/.cpp` | Manages procedural tree instances. `Initialize()` sets up cube-mesh GPU resources. `Populate()` places `count` instances within `radius` at terrain height. `AddInstance()` adds one tree. `ClearInstances()` clears all. `Draw()` renders per frame. | Add or replace tree geometry here. |
| `PrefabDef.hpp` | POD data: `PrimitivePart` (shape/offset/scale/RGBA) and `PrimitivePrefab` (name/category/parts[]). No logic. | Add new part attributes here — update JSON schema and `PrefabLibrary` parser to match. |
| `PrefabLibrary.hpp/.cpp` | Parses all `"prefabs.*"` registry entries into `m_prefabs` map. `GetPrefab(assetId)` returns `const PrimitivePrefab*` or `nullptr`. `Reload()` is a safe alias for `Load()`. | Safe to call `GetPrefab()` anywhere. Never store raw pointer across a reload. |
| `PrimitiveRenderer.hpp/.cpp` | Draws box prefab instances in two buckets: *world* (static, placed by editor) and *runtime* (dynamic, actors). `AddWorldInstance()` / `ClearWorldInstances()` for authored content; `AddRuntimeInstance()` / `ClearRuntimeInstances()` for per-frame actor visuals. `Draw()` emits one draw call per part via `prim` or `tree` shader pair. | Add new shader categories here (new shader pair + `isTree`-style flag per DrawPart). |
| `RuntimeScene.hpp/.cpp` | Scene coordinator. Owns `m_enemies[]`, `m_combatSystem`, `m_targeting`, `m_player` ref, `m_primRenderer` ref, and `damageNumbers`. Frame contract: `BeginPlayerFrame()` → `BeginFrame()` → `SubmitActors()`. Also owns respawn state (`m_wantsRespawn`, `m_spawnCenterX/Z`). | Add new actors by adding members here and wiring in `BeginFrame()` + `SubmitActors()`. Never call `ClearRuntimeInstances()` anywhere else. |

---

#### 1.4a Actors — `src/game/actors/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `ActorCommon.hpp` | Shared constants and `RuntimeActorPose` (x/y/z/yaw/scale). `PLAYER_VISUAL_PREFAB_ID = "prefabs.player_hero_blockout"`. | Change the prefab ID here to remap player visuals. |
| `PlayerActionState.hpp` | Enum `PlayerActionState`: `Idle`, `Move`, `Jump`, `Fall`, `Attack1`, `Attack2`, `Dodge`, `Stunned`, `Dead`. | Add new player states here — then handle them in `PlayerActor::Update()` and `RuntimeScene`. |
| `EnemyState.hpp` | Enum `EnemyState`: `Patrol`, `Chase`, `Attack`, `Hit`, `Dead`. | Add new enemy AI states here — handle in `EnemyActor::Update()`. |
| `PlayerStats.hpp` | `PlayerStats` struct: `hp/maxHp`, `mp/maxMp`, `surgeCharge`, `limitCharge`. `Update(dt)` ticks passive Surge fill + MP regen. `TakeDamage(int)`, `IsDead()`, `Reset()`, `AddSurge()`, `SpendSurge()`, `IsSurgeReady()`, `AddLimitCharge()`, `SpendLimit()`, `IsLimitReady()`. | Central source of truth for all player resource values. Tune rates via `surgeChargeRate`, `kMpRegenRate`, `kLimitChargePerHit`. |
| `PlayerActor.hpp/.cpp` | Stateful player: `stats` (PlayerStats), `state` (PlayerActionState), `stateTimer`. `Update()` drives state machine (Dodge/Attack/Stunned/Dead transitions). `SubmitRuntimeVisual()` pushes blockout prefab into `PrimitiveRenderer`. | Add new player ability animations by adding `PlayerActionState` values and handling them in `Update()`. |
| `EnemyActor.hpp/.cpp` | AI actor: position, yaw, HP, waypoints, `EnemyState` machine. `Init()` sets spawn + patrol. `Update()` drives Patrol→Chase→Attack→Hit→Dead. `OnHit()` applies damage + stagger. `SubmitRuntimeVisual()` pushes blockout prefab. Public static constants: `kDetectRadius`, `kAttackRadius`, `kLeashRadius`. | Add more enemy types by sub-classing or adding a second struct. Tweak AI radii as public constants. |

---

#### 1.4b Combat — `src/game/combat/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `HitBox.hpp` | `HitBox` struct: world-space AABB center + half-extents + `damage` + `framesToLive` + `hasHitPlayer`. | Pure data — safe to add fields, but update `CombatSystem::Update()` to consume them. |
| `CombatSystem.hpp/.cpp` | Owns active hitbox pool and combo state. `TriggerAttack(px,py,pz,yaw,attackStep)` spawns a hitbox with step-specific size/damage. `Update(dt, enemies, count)` decrements lifetimes, tests AABB overlap, calls `enemy.OnHit()`, accumulates `EnemyHitRecord[]`. Public: `comboStep`, `comboTimer`, `kComboWindowSec`. | Add new combo steps by extending `TriggerAttack()`'s step switch. Add new enemy types to `Update()`'s loop. |
| `Targeting.hpp` | `Targeting` class: `ToggleLockOn()` (nearest-then-cycle), `RefreshLock()` (clears dead/out-of-range targets), `IsLocked()`, `GetTarget()`. Lock radius `kLockRadius = 25.0f`. | Safe to tune radius. Extend `FindNearestAliveEnemyInRange()` to factor in angle or obscurance. |

---

#### 1.4c Physics — `src/game/physics/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `AABB.hpp` | `AABB` struct with `Overlaps()` and `FromCenter()` factory. | Pure geometry helper — safe to add methods. |
| `CollisionWorld.hpp/.cpp` | `AddBox()` / `Clear()` / `ResolveMovement()`. Maintains `m_staticBlockers` (vector of AABBs) rebuilt each cell refresh. | Add dynamic blockers by adding a second vector and updating `ResolveMovement()`. |

---

### 1.5 World Layer — `src/world/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `WorldGrid.hpp/.cpp` | Loads `Content/World/world.json`. Owns `WorldCell[]`. `WorldToCell()`, `FindCell()`, `GetActiveCells()`, `SaveCell()`, `Reload()`. `WorldCell` holds per-cell terrain/forest/instance settings. | Add new per-cell properties to `WorldCell` struct, and update JSON load/save in `WorldGrid.cpp`. |

**Key structs in this file:**

- `CellInstance` — one authored object (`prefab` ID, x/y/z/yaw/scale).
- `WorldCell` — one grid tile (cx/cz, `cellSize`, terrain settings, forest settings, `instances[]`).

---

### 1.6 UI Layer — `src/ui/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `ImGuiLayer.hpp/.cpp` | Dear ImGui context lifecycle (`Initialize`, `BeginFrame`, `EndFrame`, `Shutdown`). Owns pause menu and debug overlay state. `DrawCombatDebug()` renders AABB/radius overlays. `DrawLockOnMarker()` draws lock-on crosshair. `WndProcHook` forwards Win32 messages. | Add new debug overlay panels by adding methods here and calling inside `BeginFrame/EndFrame`. |
| `GameHUD.hpp/.cpp` | `Draw(stats, io, dt)` — HP/MP/Surge/Limit bars + low-HP pulse. `DrawTargetInfo(enemy, io)` — target name + HP bar. `DrawComboIndicator(step, timer, windowSec, io)` — combo step readout. `DrawOffScreenTargetIndicator()` — edge arrow for off-screen lock-on target. | Add new HUD elements by adding methods here. Always use ImGui foreground draw list for world-space-anchored elements. |
| `DamageNumbers.hpp/.cpp` | 64-slot pool of floating numbers/MISS labels. `Spawn(damage, x,y,z)`, `SpawnMiss(x,y,z)`, `Update(dt)` ticks rise + age, `Draw(cam...)` projects world → screen via `ScreenProjection`. | Increase `kMaxEntries` for more simultaneous numbers. |
| `ScreenProjection.hpp` | Header-only namespace. `BuildViewProj()` — builds combined view×proj matrix. `WorldToScreenVP()` — fast per-point projection. `WorldToScreen()` — convenience single-point. All match the renderer's 45-degree FOV / 0.1-2000 near-far. | Reuse `BuildViewProj` + `WorldToScreenVP` pattern for any new world→screen projections. |
| `WorldEditor.hpp/.cpp` | ImGui editor panel. `SetReferences()` binds registry/grid/forest/prefabLib/primRenderer. `DrawPanel()` renders the prefab picker + mode toggles. `HandlePlacement()` ray-casts a click to place or delete a `CellInstance`. `SpawnCellInstances()` re-expands a saved cell into `PrimitiveRenderer`. `RefreshPrefabList()` re-reads prefabs after F5. | Add new editor tools (move, rotate, scale) as new methods + `DrawPanel()` sections. |
| `TacticalPauseMenu.hpp/.cpp` | Draws the FF-style command panel while Tab is held. Returns `TacticalCommand::None` or `TacticalCommand::SurgeStrike`. | Add new `TacticalCommand` values here and handle them in `Main.cpp`. |
| `Minimap.hpp/.cpp` | Draws 160×160 top-right minimap. Colors cells by biome. Shows player dot + facing arrow. | Safe to resize or add new entity dots by extending `Draw()`. |
| `DialogBox.hpp/.cpp` | Typewriter-style dialog box. `Show(speaker, text)`, `Update(dt)` advances character reveal, `Draw(io)` renders, `Dismiss()` / `IsOpen()`. | Add new dialog features (portraits, choices) here. |

---

### 1.7 Assets Layer — `src/assets/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `AssetRegistry.hpp/.cpp` | Loads `Content/AssetRegistry.json` (scoped ID → file path map). `GetPath(id)`, `GetIdsByPrefix(prefix)`, `Reload()`. | Add new asset categories by adding JSON entries — no code change required. |
| `AssetLoader.hpp/.cpp` | Stub JSON loaders for `MaterialAsset`, `PrefabAsset`, `SceneAsset`. Uses nlohmann/json. Returns `false` on parse error. Currently no GPU resources. | Implement real GPU resource creation in these methods when the asset pipeline matures. |
| `TextureCache.hpp/.cpp` | `Load(device, path)` — uploads once via DirectXTex, returns cached `ID3D11ShaderResourceView*`. `ReleaseAll()` on shutdown. | Route all texture loads through here, never load SRVs directly. |

---

### 1.8 Audio Layer — `src/audio/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `AudioManager.hpp/.cpp` | `PlayBGM(path)`, `PlaySFX(path)`, `StopBGM()`, `SetBGMVolume()`, `SetSFXVolume()`, `Shutdown()`. Wraps `tp::Audio` (miniaudio). Current limitation: one-shot only, no looping BGM. | Add looping BGM support by extending the `tp::Audio` wrapper in `ThirdParty/tp_audio.hpp`. |

---

### 1.9 Logger — `src/logger/`

| File | Responsibility | Safe to Modify? |
|---|---|---|
| `Logger.hpp` | `Logger::Info/Warn/Error()` write to the VS Output window. Macros `LOG_INFO`, `LOG_WARN`, `LOG_ERROR`. | All new code must use these macros — never `printf` or `OutputDebugStringA` in new files. |

---

### 1.10 Shaders — `Shaders/`

| Shader pair | Used by | Constant buffers |
|---|---|---|
| `prim_vs/ps.hlsl` | `PrimitiveRenderer` for rocks/props | b0 PerDraw (MVP+world+tint), b1 LightCBuffer |
| `tree_vs/ps.hlsl` | `PrimitiveRenderer` for trees/bushes (vertical gradient + variation) | b0, b1 |
| `ground_vs/ps.hlsl` | `D3D11Renderer::DrawGroundPlane()` | b0, b1 |
| `sky_vs/ps.hlsl` | `D3D11Renderer::DrawSky()` | (minimal — no b1 light) |
| `basic3d_vs/ps.hlsl` | `D3D11Renderer::DrawRotatingTriangle()` (debug stub) | b0 |
| `triangle_vs/ps.hlsl` | Unused legacy triangle | — |

**Input layout contract for prim/tree shaders:** `POSITION (float3)` + `NORMAL (float3)` + `COLOR (float4)` = 40 bytes (`TerrainVertex` layout, see `D3D11RendererHelpers.hpp`).

---

## Part 2 — Main Entry Points

### `wWinMain` — `src/app/Main.cpp:58`

The single Win32 entry point. The only place where all subsystems are constructed and wired together.
Initialization order (never change this sequence):

1. `Win32Window::Create()` (line 60)
2. `D3D11Renderer::Initialize()` (line 68)
3. `TextureCache` + `AssetRegistry::Load()` (lines 76–83)
4. `WorldGrid::Load()` (line 89)
5. `Forest::Initialize()` (line 93)
6. `ImGuiLayer::Initialize()` (line 101)
7. `PrefabLibrary::Load()` (line 114)
8. `PrimitiveRenderer::Initialize()` (line 124)
9. `WorldEditor::SetReferences()` (line 139)
10. `ThirdPartyBootstrap::InitializeAndRunSmokeTests()` (line 177)
11. `AudioManager::PlayBGM()` (line 180)
12. `CameraController::Init()` (line 190)
13. `RuntimeScene::InitEnemies()` (line 191)

Shutdown is the reverse of initialization (lines 556–563).

---

### The 9-Step Frame Loop — `src/app/Main.cpp:240–554`

```
Step 1  FrameTiming::BeginFrame()              — compute deltaTime            (line 244)
Step 2  Input read                             — actionMap.IsPressed() all    (line 248)
Step 3  UI state / pause / reload              — Esc, F1, F5, cursor mode     (line 265)
Step 4  runtimeScene.BeginPlayerFrame()        — player state + dodge burst   (line 310)
Step 5  camController.BiasYawTowardTarget()    — lock-on camera bias          (line 320)
        camController.Update()                 — WASD, gravity, mouse-look    (line 326)
Step 6  Cell-crossing + WorldRefresh           — terrain/instances refresh    (line 332)
Step 7  runtimeScene.BeginFrame()              — enemy AI + combat resolution (line 370)
        runtimeScene.RefreshLockOnTarget()     — clear dead/range locks       (line 374)
        Attack priority chain                  — LimitBreak→Surge→Combo       (line 416)
Step 8  runtimeScene.SubmitActors()            — fill PrimitiveRenderer       (line 461)
Step 9  Draw                                   — Sky→Terrain→Forest→Prims→
                                                 ImGui HUD→Present            (line 470)
```

---

## Part 3 — Module Boundaries and Ownership

```
Main.cpp
  ├── Win32Window            (platform: window + message pump)
  ├── D3D11Renderer          (rendering: GPU device + all draw calls)
  │     └── D3D11RendererHelpers   (CPU terrain gen + math helpers)
  ├── TextureCache           (assets: SRV cache)
  ├── AssetRegistry          (assets: ID → path map)
  ├── AssetLoader            (assets: JSON stub loaders)
  ├── WorldGrid              (world: cell manifest + cell data)
  ├── Forest                 (game: tree instances + GPU resources)
  ├── ImGuiLayer             (ui: Dear ImGui context + menus + debug)
  ├── PrefabLibrary          (game: name → PrimitivePrefab cache)
  ├── PrimitiveRenderer      (game: box-prefab GPU renderer)
  ├── CollisionWorld         (game/physics: static AABB blockers)
  ├── WorldEditor            (ui: editor panel + placement logic)
  ├── GameHUD                (ui: HP/MP/Surge/Limit/target bars)
  ├── TacticalPauseMenu      (ui: Tab-held command panel)
  ├── DialogBox              (ui: typewriter dialog)
  ├── Minimap                (ui: top-right cell map)
  ├── AudioManager           (audio: BGM + SFX playback)
  ├── CameraController       (game: player position + camera)
  ├── PlayerActor            (game/actors: player state + visual)
  └── RuntimeScene           (game: scene coordinator)
        ├── EnemyActor[]     (game/actors: AI state machine)
        ├── CombatSystem     (game/combat: hitboxes + hit records)
        ├── Targeting        (game/combat: lock-on state)
        └── DamageNumbers    (ui: floating damage labels)
```

**Key boundary rules:**

- `RuntimeScene.hpp` forward-declares `D3D11Renderer` and `PrefabLibrary` — it does NOT `#include` their full headers. Only `RuntimeScene.cpp` pulls them in. Preserve this.
- `RuntimeScene.hpp` forward-declares `DamageNumbers` (line 35). Only `RuntimeScene.cpp` includes `DamageNumbers.hpp`.
- `CameraController.hpp` forward-declares `D3D11Renderer`, `InputActionMap`, `CollisionWorld` — same pattern.
- `EnemyActor.hpp` forward-declares `D3D11Renderer`, `PrefabLibrary`, `PrimitiveRenderer`.
- `CombatSystem.hpp` forward-declares `EnemyActor` — full definition only in `.cpp`.

---

## Part 4 — Public-Facing Names to Reuse When Extending

### Camera & Player Position

| Name | Type | Location | Reuse Guidance |
|---|---|---|---|
| `CameraController::GetPlayerX/Y/Z()` | `float` | `CameraController.hpp:96–99` | Always read player world position from here — never cache separately. |
| `CameraController::GetPlayerGroundY()` | `float` | `CameraController.hpp:98` | Ground level = `GetPlayerY() - eyeOffset`. Use for hitbox placement. |
| `CameraController::GetYaw/Pitch()` | `float` | `CameraController.hpp:101–102` | Camera facing angles; pass to `ScreenProjection`. |
| `CameraController::GetCamX/Y/Z()` | `float` | `CameraController.hpp:104–106` | Camera follow position; pass to render calls. |
| `CameraController::IsGrounded()` | `bool` | `CameraController.hpp:100` | Gate jump / Surge / Limit attack triggers on this. |
| `CameraController::ResetToSpawn()` | method | `CameraController.hpp:73` | Only valid path to teleport the player + reset physics. |
| `CameraController::BiasYawTowardTarget()` | method | `CameraController.hpp:67` | Call once per frame before `Update()` when locked on. |

### Combat

| Name | Type | Location | Reuse Guidance |
|---|---|---|---|
| `CombatSystem::kComboWindowSec` | `static constexpr float` | `CombatSystem.hpp:31` | Pass to `GameHUD::DrawComboIndicator()` — do not hardcode `0.60f`. |
| `CombatSystem::comboStep` | `int` | `CombatSystem.hpp:34` | Read for combo-gating in `RuntimeScene::TriggerPlayerAttack()`. |
| `CombatSystem::comboTimer` | `float` | `CombatSystem.hpp:36` | Pass to HUD for progress bar. |
| `CombatSystem::GetRecentEnemyHits()` | `const EnemyHitRecord*` | `CombatSystem.hpp:59` | Per-frame hit records — used for Surge fill + damage numbers. Valid for current frame only. |
| `CombatSystem::GetRecentEnemyHitCount()` | `int` | `CombatSystem.hpp:62` | Always pair with `GetRecentEnemyHits()`. |
| `Targeting::kLockRadius` | `static constexpr float` | `Targeting.hpp:17` | Exposed for debug visualization. |
| `RuntimeScene::GetLockedTarget()` | `const EnemyActor*` | `RuntimeScene.hpp:251` | Null when not locked. Used by HUD, camera bias, and attack yaw. |
| `RuntimeScene::TriggerPlayerAttack()` | method | `RuntimeScene.hpp:142` | Returns `bool`; triggers combo step 1 or 2. |
| `RuntimeScene::TriggerSurgeStrike()` | method | `RuntimeScene.hpp:186` | Returns `bool`; requires full Surge bar + grounded. |
| `RuntimeScene::TriggerLimitBreak()` | method | `RuntimeScene.hpp:210` | Returns `bool`; requires full Limit bar + grounded. Grants half Surge on fire. |
| `RuntimeScene::ToggleLockOn()` | method | `RuntimeScene.hpp:253` | Call on Q press (not held). |
| `RuntimeScene::damageNumbers` | `DamageNumbers` | `RuntimeScene.hpp:71` | Public member; `Main.cpp` calls `Update()` + `Draw()` directly. |
| `RuntimeScene::WantsRespawn()` | `bool` | `RuntimeScene.hpp:238` | Check each frame after `BeginFrame()`. Call `ResetToSpawn()` then `ClearRespawnFlag()`. |

### Player Stats

| Name | Type | Location | Reuse Guidance |
|---|---|---|---|
| `PlayerStats::hp/maxHp/mp/maxMp` | `float` | `PlayerStats.hpp:15–17` | Read directly for HUD bars. |
| `PlayerStats::surgeCharge/limitCharge` | `float` | `PlayerStats.hpp:21, 26` | 0.0–1.0 range. Full = `>= 1.0f`. |
| `PlayerStats::TakeDamage(int)` | method | `PlayerStats.hpp:66` | Only call this to apply damage — it also advances Limit gauge. |
| `PlayerStats::IsDead()` | `bool` | `PlayerStats.hpp:74` | Used by `RuntimeScene` to gate respawn. |
| `PlayerStats::Reset()` | method | `PlayerStats.hpp:78` | Call on respawn — restores hp, mp, surge, limit. |

### Prefabs & Rendering

| Name | Type | Location | Reuse Guidance |
|---|---|---|---|
| `ActorCommon::PLAYER_VISUAL_PREFAB_ID` | `const char*` | `ActorCommon.hpp:14` | The registry ID for the player blockout prefab. |
| `PrefabLibrary::GetPrefab(assetId)` | `const PrimitivePrefab*` | `PrefabLibrary.hpp:39` | Returns `nullptr` on miss. Always null-check before use. |
| `PrimitiveRenderer::AddRuntimeInstance()` | method | `PrimitiveRenderer.hpp:65` | Call from any actor's `SubmitRuntimeVisual()` method. |
| `PrimitiveRenderer::ClearRuntimeInstances()` | method | `PrimitiveRenderer.hpp:70` | Called once per frame at start of `RuntimeScene::BeginFrame()`. Do not call from elsewhere. |
| `PrimitiveRenderer::AddWorldInstance()` | method | `PrimitiveRenderer.hpp:57` | For authored/placed content only — called from `WorldEditor::SpawnCellInstances()`. |

### World & Assets

| Name | Type | Location | Reuse Guidance |
|---|---|---|---|
| `WorldGrid::FindCell(cx,cz)` | `WorldCell*` | `WorldGrid.hpp:98` | Returns `nullptr` when out of bounds — always null-check. |
| `WorldGrid::WorldToCell()` | method | `WorldGrid.hpp:91` | Convert world-space XZ to grid coords. |
| `WorldGrid::SaveCell(cx,cz)` | method | `WorldGrid.hpp:102` | Only call after modifying a cell's `instances[]`. |
| `AssetRegistry::GetPath(id)` | method | `AssetRegistry.hpp:33` | Returns empty string on miss and logs an error. |
| `AssetRegistry::GetIdsByPrefix(prefix)` | method | `AssetRegistry.hpp:36` | Use `"prefabs."` prefix to enumerate all prefab IDs. |
| `TextureCache::Load(device, path)` | method | `TextureCache.hpp:24` | Returns `nullptr` on failure, never throws. Route all SRV loads here. |

### UI & Projection

| Name | Type | Location | Reuse Guidance |
|---|---|---|---|
| `ScreenProjection::BuildViewProj()` | `inline bool` | `ScreenProjection.hpp:34` | Call once per frame before projecting many world points. |
| `ScreenProjection::WorldToScreenVP()` | `inline bool` | `ScreenProjection.hpp:62` | Fast path per-point. Returns `false` when behind camera or off-screen. |
| `ScreenProjection::WorldToScreen()` | `inline bool` | `ScreenProjection.hpp:95` | Convenience single-point version — avoid in tight loops. |
| `ImGuiLayer::WndProcHook` | `static LRESULT CALLBACK` | `ImGuiLayer.hpp:98` | Pass to `Win32Window::SetWndProcHook()` exactly once at startup. |
| `ImGuiLayer::BeginFrame/EndFrame()` | methods | `ImGuiLayer.hpp:36–39` | All `ImGui::*` calls must be between these two. |
| `ImGuiLayer::showCombatDebug` | `bool` | `ImGuiLayer.hpp:93` | Public flag toggled by the debug overlay checkbox. |

### Logging

| Macro | Location | Guidance |
|---|---|---|
| `LOG_INFO(msg)` | `Logger.hpp:24` | All new code uses this — pass `std::string`. |
| `LOG_WARN(msg)` | `Logger.hpp:25` | Non-fatal anomalies (missing asset, parse warning). |
| `LOG_ERROR(msg)` | `Logger.hpp:26` | Fatal or near-fatal errors. |

---

## Part 5 — Modification Safety Checklists

### Adding a New Actor Type

1. Create `src/game/actors/MyActor.hpp/.cpp` following the `EnemyActor` pattern.
2. Add `.cpp` to `GameRewritten.vcxproj` and `GameRewritten.vcxproj.filters`.
3. Add a member in `RuntimeScene.hpp` (private section, alongside `m_enemies[]`).
4. Call `myActor.Update(dt, renderer, playerX, playerZ)` inside `RuntimeScene::BeginFrame()` in `RuntimeScene.cpp`.
5. Call `myActor.SubmitRuntimeVisual(prefabLibrary, m_primRenderer)` inside `RuntimeScene::SubmitActors()` in `RuntimeScene.hpp`.
6. Expose a getter in `RuntimeScene` if `Main.cpp` or HUD needs to read actor state.

### Adding a New ImGui Panel

1. Create `src/ui/MyPanel.hpp/.cpp` with a `Draw(...)` method.
2. Add to `GameRewritten.vcxproj`.
3. Construct in `Main.cpp` before the game loop (alongside `gameHud`, `minimap`, etc.).
4. Call `myPanel.Draw(...)` inside `imguiLayer.BeginFrame()` / `imguiLayer.EndFrame()` block (`Main.cpp:481–548`).
5. Guard with `if (!imguiLayer.IsPauseMenuOpen())` if it should hide when paused.

### Adding a New Shader Constant Buffer

1. Declare the `cbuffer` struct in the owning module's `.hpp`.
2. Create the `ID3D11Buffer*` in `Initialize()`, update it in `Update()` or per-frame as needed.
3. Use slot `b2+` (b0 = PerDraw, b1 = LightCBuffer are taken).
4. Match the slot in both `VSSetConstantBuffers`/`PSSetConstantBuffers` (C++) and `register(b#)` (HLSL).
5. Ensure struct size is a multiple of 16 bytes (D3D11 requirement).

### Adding a New Input Action

1. Add a value to the `InputAction` enum in `InputActionMap.hpp:20`.
2. Add its binding in `InputActionMap::Default()` at `InputActionMap.hpp:49`.
3. Declare a `bool wasMyActionDown = false;` in `Main.cpp` before the loop.
4. Read with `actionMap.IsPressed(InputAction::MyAction, wasMyActionDown)` in Step 2 of the frame loop.

### Extending the World Cell Format

1. Add fields to `WorldCell` in `WorldGrid.hpp`.
2. Parse them in `WorldGrid::LoadCellFile()` in `WorldGrid.cpp`.
3. Write them in `WorldGrid::SaveCell()` in `WorldGrid.cpp`.
4. Consume the new fields in `WorldRefresh::RefreshCellVisuals()` in `WorldRuntimeRefresh.hpp`.

---

## Part 6 — File Header Convention

Every `.cpp` and `.hpp` in `src/` opens with this block:

```cpp
// ============================================================
// FILE: src/<subsystem>/<FileName>.<ext>
// SYSTEM: <App|Game|Rendering|UI|World|Assets|Audio|Platform|Logger>
// ROLE: <one-line description of what this file does>
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: <FileName> module behavior and local implementation details.
// ============================================================
```

New files must include this block with the correct `SYSTEM` and `ROLE` values.

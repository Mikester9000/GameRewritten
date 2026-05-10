# System Registry

This file is the source of truth for what exists, what is stubbed, and what is missing.
Agents must read this before implementing anything to avoid reimplementing existing systems.

## Status Legend
- ✅ Complete — do not reimplement
- 🔧 Stub — exists but needs expansion
- ❌ Not started

## Systems

| System | Status | Key Files |
|---|---|---|
| Win32 window | ✅ | `src/platform/win32/` |
| D3D11 renderer | ✅ | `src/rendering/d3d11/D3D11Renderer.cpp/hpp` |
| D3D11 helpers | ✅ | `src/rendering/d3d11/D3D11RendererHelpers.cpp/hpp` |
| Sky shader | ✅ | `Shaders/sky_vs/ps.hlsl` |
| Ground/terrain shader | ✅ | `Shaders/ground_vs/ps.hlsl` |
| Tree shader | ✅ | `Shaders/tree_vs/ps.hlsl` |
| Primitive shader | ✅ | `Shaders/prim_vs/ps.hlsl` |
| Basic 3D shader | ✅ | `Shaders/basic3d_vs/ps.hlsl` |
| Camera + player movement | ✅ | `src/game/CameraController.cpp/hpp` |
| Gravity + jumping | ✅ | `src/game/CameraController.cpp` |
| Terrain height snap | ✅ | `CameraController` → `renderer.SampleTerrainHeight` |
| Player actor visual | ✅ | `src/game/actors/PlayerActor.cpp/hpp` |
| Actor common types | ✅ | `src/game/actors/ActorCommon.hpp` |
| Scene coordinator | ✅ | `src/game/RuntimeScene.hpp` |
| Prefab system | ✅ | `src/game/PrefabDef.hpp`, `PrefabLibrary.cpp/hpp` |
| Primitive renderer | ✅ | `src/game/PrimitiveRenderer.cpp/hpp` |
| Forest / tree instancing | ✅ | `src/game/Forest.cpp/hpp` |
| World grid + biomes | ✅ | `src/world/WorldGrid.cpp/hpp` |
| Asset registry | ✅ | `src/assets/AssetRegistry`, `AssetLoader` |
| ImGui context | ✅ | `src/ui/ImGuiLayer.cpp/hpp` |
| Pause menu | ✅ | `ImGuiLayer::DrawPauseMenu()` |
| Debug overlay (F1) | ✅ | `ImGuiLayer::DrawDebugOverlay()` |
| World editor panel | ✅ | `src/ui/WorldEditor.cpp/hpp` |
| Frame timing | ✅ | `src/app/FrameTiming.hpp` |
| Input edge detection | ✅ | `src/app/InputEdgeState.hpp` |
| Cursor mode controller | ✅ | `src/app/CursorModeController.hpp` |
| Logger | ✅ | `src/logger/Logger.hpp` |
| Tracy profiling | ✅ | `GR_ZONE_SCOPED_N`, `GR_FRAME_MARK` |
| miniaudio (init only) | 🔧 | `ThirdPartyBootstrap` → `tp::Audio` |
| Jolt Physics (init only) | 🔧 | `ThirdPartyBootstrap` → `tp::Physics` |
| Recast/Detour nav (init only) | 🔧 | `ThirdPartyBootstrap` → `tp::Nav` |
| DirectXTex (smoke test only) | 🔧 | `ThirdPartyBootstrap` → `tp::Texture` |
| Player stats (hp/mp/atb) | ✅ | `src/game/actors/PlayerStats.hpp`, `src/game/actors/PlayerActor.hpp`, `src/game/RuntimeScene.hpp` |
| Gameplay HUD | ✅ | `src/ui/GameHUD.hpp`, `src/ui/GameHUD.cpp`, `src/app/Main.cpp` |
| Texture cache | ✅ | `src/assets/TextureCache.hpp`, `src/assets/TextureCache.cpp` |
| Directional lighting | ✅ | `src/rendering/d3d11/D3D11Renderer.cpp/hpp`, `Shaders/ground_ps.hlsl`, `Shaders/basic3d_ps.hlsl`, `Shaders/tree_ps.hlsl`, `src/ui/ImGuiLayer.cpp/hpp` |
| Input action map | ✅ | `src/app/InputActionMap.hpp`, `src/app/Main.cpp`, `src/game/CameraController.cpp/hpp` |
| AABB collision | ✅ | `src/game/physics/AABB.hpp`, `src/game/physics/CollisionWorld.cpp/hpp`, `src/game/CameraController.cpp/hpp`, `src/app/WorldRuntimeRefresh.hpp`, `src/app/Main.cpp` |
| Enemy actor | ✅ | `src/game/actors/EnemyActor.cpp/hpp` |
| Dialog box | ✅ | `src/ui/DialogBox.cpp/hpp`, `src/app/Main.cpp` |
| Combat system | ❌ | — |
| Audio manager | ❌ | — |
| Minimap | ❌ | — |

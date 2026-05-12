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
| Player action state machine | ✅ | `src/game/actors/PlayerActionState.hpp`, `src/game/actors/PlayerActor.cpp/hpp` |
| Gameplay HUD | ✅ | `src/ui/GameHUD.hpp`, `src/ui/GameHUD.cpp`, `src/app/Main.cpp` |
| Texture cache | ✅ | `src/assets/TextureCache.hpp`, `src/assets/TextureCache.cpp` |
| Directional lighting | ✅ | `src/rendering/d3d11/D3D11Renderer.cpp/hpp`, `Shaders/ground_ps.hlsl`, `Shaders/basic3d_ps.hlsl`, `Shaders/tree_ps.hlsl`, `src/ui/ImGuiLayer.cpp/hpp` |
| Input action map | ✅ | `src/app/InputActionMap.hpp`, `src/app/Main.cpp`, `src/game/CameraController.cpp/hpp` |
| AABB collision | ✅ | `src/game/physics/AABB.hpp`, `src/game/physics/CollisionWorld.cpp/hpp`, `src/game/CameraController.cpp/hpp`, `src/app/WorldRuntimeRefresh.hpp`, `src/app/Main.cpp` |
| Enemy actor | ✅ | `src/game/actors/EnemyActor.cpp/hpp` |
| Dialog box | ✅ | `src/ui/DialogBox.cpp/hpp`, `src/app/Main.cpp` |
| Combat system | ✅ | `src/game/combat/HitBox.hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Audio manager | ✅ | `src/audio/AudioManager.hpp`, `src/audio/AudioManager.cpp` |
| Minimap | ✅ | `src/ui/Minimap.cpp/hpp` |
| Dodge burst movement | ✅ | `src/game/CameraController.cpp/hpp` |
| 2-step combo chain | ✅ | `src/game/combat/CombatSystem.cpp/hpp`, `src/game/RuntimeScene.hpp` |
| Lock-on targeting | ❌ | `src/game/combat/Targeting.hpp` |
| Enemy combat states (chase/attack/hit) | ✅ | `src/game/actors/EnemyActor.cpp/hpp`, `src/game/actors/EnemyState.hpp` |
| Enemy awareness radius visualization   | ✅ | `src/ui/ImGuiLayer.cpp/hpp` |
| Player damage intake + defeat reset | ✅ | `src/game/actors/PlayerStats.hpp`, `src/game/RuntimeScene.hpp`, `src/game/CameraController.cpp/hpp` |
| Floating damage numbers | ✅ | `src/ui/DamageNumbers.cpp/hpp` |
| Hit flash system | ❌ | `src/game/actors/EnemyActor.cpp/hpp` |
| Screen edge damage flash | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Hit pause / hitstop | ❌ | `src/game/RuntimeScene.hpp` |
| Stagger meter | ❌ | `src/game/actors/EnemyActor.cpp/hpp` |
| Enemy attack telegraph | ❌ | `src/game/actors/EnemyActor.cpp/hpp` |
| Parry / counter window | ❌ | `src/game/actors/PlayerActor.cpp/hpp` |
| Miss indicator | ❌ | `src/ui/DamageNumbers.cpp/hpp` |
| Weak point damage | ❌ | `src/game/combat/CombatSystem.cpp/hpp` |
| Combo counter display | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Area name display | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Notification toast system | ❌ | `src/ui/NotificationSystem.cpp/hpp` |
| Letterbox event bars | ❌ | `src/ui/ImGuiLayer.cpp/hpp` |
| Contextual button prompts | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Level up screen overlay | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Status screen | ❌ | `src/ui/StatusScreen.cpp/hpp` |
| Map screen stub | ❌ | `src/ui/MapScreen.cpp/hpp` |
| Tooltip system | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Saving indicator | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Death / defeat screen | ❌ | `src/ui/GameHUD.cpp/hpp` |
| Low HP warning pulse | ✅ | `src/ui/GameHUD.cpp/hpp` |
| Camera shake | ❌ | `src/game/CameraController.cpp/hpp` |
| Combat camera zoom | ❌ | `src/game/CameraController.cpp/hpp` |
| Camera collision avoidance | ❌ | `src/game/CameraController.cpp/hpp` |
| Target framing adjustment | ❌ | `src/game/CameraController.cpp/hpp` |
| Wind effect on trees | ❌ | `Shaders/tree_vs.hlsl` |
| Weather system lite | ❌ | `src/world/WeatherSystem.cpp/hpp` |
| Ambient particles | ❌ | `src/game/ParticleSystem.cpp/hpp` |
| Day/night cycle | ❌ | `src/world/DayNightCycle.cpp/hpp` |
| Biome transition fade | ❌ | `src/world/WorldGrid.cpp/hpp` |
| Fog of war on minimap | ❌ | `src/ui/Minimap.cpp/hpp` |
| World event trigger zones | ❌ | `src/game/world/EventZone.cpp/hpp` |
| NPC actor | ❌ | `src/game/actors/NpcActor.cpp/hpp` |
| Quest objective system | ❌ | `src/game/quest/QuestSystem.cpp/hpp` |
| Treasure chest actor | ❌ | `src/game/actors/ChestActor.cpp/hpp` |
| Campfire / rest point actor | ❌ | `src/game/actors/RestPointActor.cpp/hpp` |
| Inventory system | ❌ | `src/game/inventory/Inventory.cpp/hpp` |
| XP / level system | ❌ | `src/game/actors/PlayerStats.hpp` |
| Status effects | ❌ | `src/game/actors/PlayerStats.hpp` |
| Fast travel stub | ❌ | `src/game/world/FastTravel.cpp/hpp` |
| Save / load system | ❌ | `src/app/SaveSystem.cpp/hpp` |
| Quality preset enforcement | ❌ | `src/app/QualityPreset.cpp/hpp` |
| Victory fanfare trigger | ❌ | `src/audio/AudioManager.cpp/hpp` |
| Environmental ambient audio | ❌ | `src/audio/AudioManager.cpp/hpp` |
| Looping BGM | ❌ | `src/audio/AudioManager.cpp/hpp` |

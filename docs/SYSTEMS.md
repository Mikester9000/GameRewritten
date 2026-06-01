# System Registry

This file is the source of truth for what exists, what is stubbed, and what is missing.
Agents must read this before implementing anything to avoid reimplementing existing systems.

## Status Legend
- ✅ Complete — do not reimplement
- 🔧 Stub — exists but needs expansion
- ❌ Not started

Latest task update: Task 001 pressure/stagger flow hardened for non-positive hit handling and minimum combat hit damage.

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
| miniaudio (SFX playback only) | 🔧 | `ThirdPartyBootstrap` → `tp::Audio` |
| Jolt Physics (init only) | 🔧 | `ThirdPartyBootstrap` → `tp::Physics` |
| Recast/Detour nav (init only) | 🔧 | `ThirdPartyBootstrap` �� `tp::Nav` |
| DirectXTex (texture upload path) | 🔧 | `ThirdPartyBootstrap` → `tp::Texture` |
| Player stats (hp/mp/surge/limit) | ✅ | `src/game/actors/PlayerStats.hpp` — Surge fills from hits, Limit fills from damage taken |
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
| Surge Strike | ✅ | `src/game/RuntimeScene.hpp`, `src/game/combat/CombatSystem.cpp` |
| Limit Break gauge + move | ✅ | `src/game/actors/PlayerStats.hpp`, `src/game/RuntimeScene.hpp`, `src/game/combat/CombatSystem.cpp` |
| MP passive regeneration | ✅ | `src/game/actors/PlayerStats.hpp` |
| Lock-on targeting | ✅ | `src/game/combat/Targeting.hpp`, `src/game/RuntimeScene.hpp`, `src/game/CameraController.cpp/hpp`, `src/app/Main.cpp` |
| Enemy combat states (chase/attack/hit) | ✅ | `src/game/actors/EnemyActor.cpp/hpp`, `src/game/actors/EnemyState.hpp` |
| Enemy awareness radius visualization | ✅ | `src/ui/ImGuiLayer.cpp/hpp` |
| Player damage intake + defeat reset | ✅ | `src/game/actors/PlayerStats.hpp`, `src/game/RuntimeScene.hpp`, `src/game/CameraController.cpp/hpp` |
| Floating damage numbers | ✅ | `src/ui/DamageNumbers.cpp/hpp` |
| Tactical Pause (hold Tab) | ✅ | `src/ui/TacticalPauseMenu.cpp/hpp`, `src/app/Main.cpp` |
| Combat HUD expansion (target info + combo step) | ✅ | `src/ui/GameHUD.hpp`, `src/ui/GameHUD.cpp`, `src/app/Main.cpp` |
| Lock-on target cycling | ✅ | `src/game/combat/Targeting.hpp`, `src/app/Main.cpp` |
| Auto-retarget on target death / range loss | ✅ | `src/game/combat/Targeting.hpp`, `src/game/RuntimeScene.hpp` |
| Pressure / stagger integration stub | ✅ | `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Tactical Pause command readiness reasons | ✅ | `src/ui/TacticalPauseMenu.cpp/hpp` |
| Off-screen lock-on target indicator | ✅ | `src/ui/GameHUD.cpp/hpp`, `src/app/Main.cpp` |
| Enemy reaction / interrupt-lite | ✅ | `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Enemy attack telegraph lite | ✅ | `src/game/actors/EnemyActor.cpp/hpp` |
| Hit flash system | ✅ | `src/game/actors/EnemyActor.cpp/hpp` |
| Screen edge damage flash | ✅ | `src/ui/GameHUD.cpp/hpp` |
| Hit pause / hitstop | ✅ | `src/game/RuntimeScene.hpp` |
| Stagger meter | ✅ | `src/game/actors/EnemyActor.cpp/hpp` |
| Enemy attack telegraph | ✅ | `src/game/actors/EnemyActor.cpp/hpp` |
| Parry / counter window | ✅ | `src/game/actors/PlayerActor.cpp/hpp`, `src/game/RuntimeScene.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Miss indicator | ✅ | `src/ui/DamageNumbers.cpp/hpp`, `src/app/Main.cpp` |
| Weak point damage | ✅ | `src/game/combat/CombatSystem.cpp/hpp`, `src/game/combat/HitBox.hpp` |
| Combo counter display | ✅ | `src/ui/GameHUD.cpp/hpp` |
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
| Camera shake | ✅ | `src/game/CameraController.cpp/hpp` |
| Combat camera zoom | ✅ | `src/game/CameraController.cpp/hpp` |
| Camera collision avoidance | ✅ | `src/game/CameraController.cpp/hpp` |
| Target framing adjustment | ✅ | `src/game/CameraController.cpp/hpp` |
| Lock-on camera recovery smoothing | ✅ | `src/game/CameraController.cpp/hpp` |
| Wind effect on trees | ✅ | `Shaders/tree_vs.hlsl` |
| Weather system lite | ✅ | `src/world/WeatherSystem.cpp/hpp` |
| Ambient particles | ✅ | `src/game/ParticleSystem.cpp/hpp` |
| Day/night cycle | ✅ | `src/world/DayNightCycle.cpp/hpp` |
| Biome transition fade | ✅ | `src/world/WorldGrid.cpp/hpp` |
| Fog of war on minimap | ✅ | `src/ui/Minimap.cpp/hpp` |
| World event trigger zones | ❌ | `src/game/world/EventZone.cpp/hpp` |
| Interaction hotspot registry stub | ❌ | `src/game/world/InteractionRegistry.cpp/hpp` |
| Landmark discovery trigger stub | ❌ | `src/game/world/LandmarkTrigger.cpp/hpp` |
| NPC actor | ❌ | `src/game/actors/NpcActor.cpp/hpp` |
| Quest objective system | ❌ | `src/game/quest/QuestSystem.cpp/hpp` |
| Treasure chest actor | ❌ | `src/game/actors/ChestActor.cpp/hpp` |
| Campfire / rest point actor | ❌ | `src/game/actors/RestPointActor.cpp/hpp` |
| NPC interaction prompt routing stub | ❌ | `src/ui/GameHUD.cpp/hpp`, `src/game/world/InteractionRegistry.cpp/hpp` |
| Quest flag / world-state hook | ❌ | `src/game/quest/QuestFlags.hpp`, `src/game/quest/QuestSystem.cpp/hpp` |
| Spawn composition table stub (solo / pair / pack) | ❌ | `src/world/SpawnTable.hpp`, `src/world/WorldGrid.cpp/hpp` |
| Inventory system | ❌ | `src/game/inventory/Inventory.cpp/hpp` |
| XP / level system | ✅ | `src/game/actors/PlayerStats.hpp` |
| Status effects | ✅ | `src/game/actors/PlayerStats.hpp` |
| Fast travel stub | ❌ | `src/game/world/FastTravel.cpp/hpp` |
| Save / load system | ❌ | `src/app/SaveSystem.cpp/hpp` |
| Quality preset enforcement | ✅ | `src/app/QualityPreset.cpp/hpp` |
| Victory fanfare trigger | ✅ | `src/audio/AudioManager.cpp/hpp` |
| Environmental ambient audio | ✅ | `src/audio/AudioManager.cpp/hpp` |
| Looping BGM | ✅ | `src/audio/AudioManager.cpp/hpp` |
| Tactical Pause enter / exit SFX | ✅ | `src/audio/AudioManager.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp` |
| Lock-on acquire / break SFX | ✅ | `src/audio/AudioManager.cpp/hpp`, `src/game/combat/Targeting.hpp` |
| Enemy alert bark stub | ✅ | `src/audio/AudioManager.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp` |
| Equipment slot stub | ⚠️ stub | `src/game/inventory/Equipment.hpp` |
| Ability unlock / progression hook | ⚠️ stub | `src/game/progression/AbilityProgression.hpp`, `src/game/progression/AbilityProgression.cpp` |
| Combat stat modifier pipeline stub | ✅ | `src/game/combat/CombatModifiers.hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| World partition + region streaming core | ✅ | `src/world/WorldPartition.cpp/hpp, src/world/WorldGrid.cpp/hpp` |
| Asynchronous chunk IO + prefetch queue | ⚠️ stub | `src/world/StreamingIO.cpp/hpp` |
| Large-world coordinate rebasing | ✅ | `src/world/WorldOriginRebase.cpp/hpp, src/app/Main.cpp` |
| Terrain/mesh LOD tier manager | ✅ | `src/world/WorldLodManager.cpp/hpp, src/rendering/d3d11/D3D11Renderer.cpp/hpp` |
| Streaming budget governor (CPU/GPU/IO) | ✅ | `src/world/StreamingBudget.hpp, src/world/WorldGrid.cpp/hpp` |
| Far-distance continent impostors | ⚠️ stub | `src/world/ContinentImpostor.cpp/hpp` |
| Global nav tile streaming bridge | ❌ | `src/game/world/NavTileStream.cpp/hpp, ThirdParty/tp_navigation.hpp` |
| Seamless continent transition triggers | ❌ | `src/world/ContinentTransition.cpp/hpp, src/world/WorldGrid.cpp/hpp` |
| Traversal mount/vehicle framework stub | ❌ | `src/game/traversal/TraversalMount.cpp/hpp, src/game/RuntimeScene.hpp` |
| Traversal verbs: climb/swim/glide base | ❌ | `src/game/traversal/TraversalController.cpp/hpp, src/game/CameraController.cpp/hpp` |
| Seamless interior/exterior cell portals | ❌ | `src/world/CellPortal.cpp/hpp, src/game/world/EventZone.cpp/hpp` |
| World map overlay with continent zoom | ❌ | `src/ui/WorldMap.cpp/hpp, src/ui/MapScreen.cpp/hpp` |
| Discovery journal for landmarks/routes | ❌ | `src/game/world/DiscoveryJournal.cpp/hpp, src/ui/GameHUD.cpp/hpp` |
| Biome-aware population spawn director | ❌ | `src/world/PopulationDirector.cpp/hpp, src/world/WorldGrid.cpp/hpp` |
| World event scheduler (time/weather/region) | ❌ | `src/world/WorldEventScheduler.cpp/hpp, src/world/DayNightCycle.cpp/hpp` |
| Region state persistence for streamed world | ❌ | `src/world/RegionStateStore.cpp/hpp, src/app/SaveSystem.cpp/hpp` |
| Party member runtime slot + follow AI | ❌ | `src/game/party/PartyRuntime.cpp/hpp, src/game/RuntimeScene.hpp` |
| Command wheel + tactical slow-time commands | ❌ | `src/ui/CommandWheel.cpp/hpp, src/ui/TacticalPauseMenu.cpp/hpp` |
| ATB-style action charge lanes | ❌ | `src/game/combat/AtbSystem.cpp/hpp, src/game/actors/PlayerStats.hpp` |
| Ability targeting templates (single/cone/aoe) | ❌ | `src/game/combat/AbilityTargeting.cpp/hpp, src/game/combat/CombatSystem.cpp/hpp` |
| Enemy archetype behavior profiles | ❌ | `src/game/ai/EnemyArchetypeProfile.hpp, src/game/actors/EnemyActor.cpp/hpp` |
| Enemy squad tactics coordinator | ❌ | `src/game/ai/SquadCoordinator.cpp/hpp, src/game/RuntimeScene.hpp` |
| Boss phase state machine framework | ❌ | `src/game/actors/BossActor.cpp/hpp, src/game/ai/BossPhaseState.hpp` |
| Guard-break / poise combat pipeline | ✅ | `src/game/combat/PoiseSystem.cpp/hpp, src/game/combat/CombatSystem.cpp/hpp` |
| Elemental damage/resistance matrix | ✅ | `src/game/combat/ElementSystem.hpp, src/game/combat/CombatSystem.cpp/hpp` |
| Status ailment counters + immunity windows | ✅ | `src/game/combat/StatusAilmentSystem.cpp/hpp, src/game/combat/CombatSystem.cpp/hpp` |
| Combat speed slider | ✅ | `src/game/combat/CombatSpeedSlider.cpp/hpp, src/ui/ImGuiLayer.cpp/hpp, src/app/Main.cpp` |
| Combo cancel system | ✅ | `src/game/combat/ComboSystem.cpp/hpp, src/game/RuntimeScene.cpp/hpp` |
| Perfect dodge i-frames | ✅ | `src/game/actors/PlayerActor.cpp/hpp, src/game/RuntimeScene.cpp` |
| Break-state vulnerability window | ✅ | `src/game/combat/PoiseSystem.cpp/hpp, src/game/combat/CombatSystem.cpp/hpp` |
| Weak-point targeting UI overlay | ✅ | `src/ui/WeakPointReticle.cpp/hpp, src/app/Main.cpp` |
| Limit break cinematic camera | ✅ | `src/game/combat/LimitBreakCamera.cpp/hpp, src/game/RuntimeScene.cpp/hpp` |
| Limit break evolution/leveling system | ✅ | `src/game/combat/LimitBreakEvolution.cpp/hpp, src/game/RuntimeScene.cpp/hpp` |
| Elemental weakness exploitation bonus | ✅ | `src/game/combat/ElementalWeaknessBonus.cpp/hpp, src/game/combat/CombatSystem.cpp` |
| Combat bugfix sweep | ✅ | `src/game/combat/CombatSystem.cpp, src/ui/ImGuiLayer.cpp` |
| Equipment progression + socket rules | ❌ | `src/game/inventory/EquipmentProgression.cpp/hpp, src/game/inventory/Equipment.hpp` |
| Skill tree graph + unlock prerequisites | ❌ | `src/game/progression/SkillTree.cpp/hpp, src/game/progression/AbilityProgression.hpp` |
| Loot table tiers + drop weighting | ❌ | `src/game/loot/LootTable.cpp/hpp, src/game/actors/EnemyActor.cpp/hpp` |
| Crafting + upgrade station flow | ❌ | `src/game/crafting/CraftingSystem.cpp/hpp, src/game/actors/RestPointActor.cpp/hpp` |
| Open-world encounter director | ❌ | `src/game/ai/EncounterDirector.cpp/hpp, src/world/PopulationDirector.cpp/hpp` |
| Combat telemetry + balance debug panel | ❌ | `src/ui/CombatDebugPanel.cpp/hpp, src/game/combat/CombatSystem.cpp/hpp` |
| Quest authoring schema + validator | ❌ | `src/game/quest/QuestSchema.hpp, src/game/quest/QuestSystem.cpp/hpp` |
| Dialogue branching + localization keys | ❌ | `src/game/dialogue/DialogueRuntime.cpp/hpp, src/ui/DialogBox.cpp/hpp` |
| Cutscene timeline stub + camera rails | ❌ | `src/game/cutscene/CutsceneTimeline.cpp/hpp, src/game/CameraController.cpp/hpp` |
| Audio event router + mixer bus controls | ❌ | `src/audio/AudioRouter.cpp/hpp, src/audio/AudioManager.cpp/hpp` |
| Adaptive music state machine | ❌ | `src/audio/MusicStateMachine.cpp/hpp, src/audio/AudioManager.cpp/hpp` |
| SFX variation + distance/occlusion rules | ❌ | `src/audio/SfxSpatialRules.cpp/hpp, src/audio/AudioManager.cpp/hpp` |
| Voice placeholder + subtitle timing pipeline | ❌ | `src/audio/VoicePlayback.cpp/hpp, src/ui/SubtitleOverlay.cpp/hpp` |
| Save versioning + migration compatibility | ❌ | `src/app/SaveMigration.cpp/hpp, src/app/SaveSystem.cpp/hpp` |
| Crash capture + runtime diagnostics pack | ❌ | `src/app/CrashDiagnostics.cpp/hpp, src/logger/Logger.hpp` |
| Full settings menu (graphics/audio/input/accessibility) | ❌ | `src/ui/SettingsMenu.cpp/hpp, src/app/QualityPreset.cpp/hpp` |
| Input rebinding + controller glyph profiles | ❌ | `src/app/InputBindingProfile.cpp/hpp, src/ui/GameHUD.cpp/hpp` |
| Performance HUD + auto quality scaler | ❌ | `src/app/AutoQualityScaler.cpp/hpp, src/ui/ImGuiLayer.cpp/hpp` |
| Build packaging + release manifest scripts | ❌ | `tools/release/PackageBuild.ps1, docs/RELEASE_BUILD.md` |
| Legal/credits/third-party attribution pass | ❌ | `src/ui/CreditsScreen.cpp/hpp, docs/THIRD_PARTY.md` |
| New game bootstrap + onboarding tutorial | ❌ | `src/game/NewGameFlow.cpp/hpp, src/ui/TutorialOverlay.cpp/hpp` |
| Vertical-slice certification and ship checklist | ❌ | `docs/SHIP_CHECKLIST.md, docs/QUALITY_BAR.md` |
| World partition + region streaming core | ✅ | `src/world/WorldPartition.cpp/hpp`, `src/world/WorldGrid.cpp/hpp` |
| Asynchronous chunk IO + prefetch queue | ✅ | `src/world/StreamingIO.cpp/hpp`, `src/assets/AssetLoader.hpp` |
| Large-world coordinate rebasing | ✅ | `src/world/WorldOriginRebase.cpp/hpp`, `src/app/Main.cpp` |
| Terrain/mesh LOD tier manager | ✅ | `src/world/WorldLodManager.cpp/hpp`, `src/rendering/d3d11/D3D11Renderer.cpp/hpp` |
| Streaming budget governor (CPU/GPU/IO) | ✅ | `src/world/StreamingBudget.hpp`, `src/world/WorldGrid.cpp/hpp` |
| Far-distance continent impostors | ✅ | `src/world/ContinentImpostor.cpp/hpp`, `Shaders/continent_impostor_vs.hlsl` |
| Global nav tile streaming bridge | ❌ | `src/game/world/NavTileStream.cpp/hpp`, `ThirdParty/tp_navigation.hpp` |
| Seamless continent transition triggers | ❌ | `src/world/ContinentTransition.cpp/hpp`, `src/world/WorldGrid.cpp/hpp` |
| Traversal mount/vehicle framework stub | ❌ | `src/game/traversal/TraversalMount.cpp/hpp`, `src/game/RuntimeScene.hpp` |
| Traversal verbs: climb/swim/glide base | ❌ | `src/game/traversal/TraversalController.cpp/hpp`, `src/game/CameraController.cpp/hpp` |
| Seamless interior/exterior cell portals | ❌ | `src/world/CellPortal.cpp/hpp`, `src/game/world/EventZone.cpp/hpp` |
| World map overlay with continent zoom | ❌ | `src/ui/WorldMap.cpp/hpp`, `src/ui/MapScreen.cpp/hpp` |
| Discovery journal for landmarks/routes | ❌ | `src/game/world/DiscoveryJournal.cpp/hpp`, `src/ui/GameHUD.cpp/hpp` |
| Biome-aware population spawn director | ❌ | `src/world/PopulationDirector.cpp/hpp`, `src/world/WorldGrid.cpp/hpp` |
| World event scheduler (time/weather/region) | ❌ | `src/world/WorldEventScheduler.cpp/hpp`, `src/world/DayNightCycle.cpp/hpp` |
| Region state persistence for streamed world | ❌ | `src/world/RegionStateStore.cpp/hpp`, `src/app/SaveSystem.cpp/hpp` |
| Party member runtime slot + follow AI | ❌ | `src/game/party/PartyRuntime.cpp/hpp`, `src/game/RuntimeScene.hpp` |
| Command wheel + tactical slow-time commands | ❌ | `src/ui/CommandWheel.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp` |
| ATB-style action charge lanes | ❌ | `src/game/combat/AtbSystem.cpp/hpp`, `src/game/actors/PlayerStats.hpp` |
| Ability targeting templates (single/cone/aoe) | ❌ | `src/game/combat/AbilityTargeting.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Enemy archetype behavior profiles | ❌ | `src/game/ai/EnemyArchetypeProfile.hpp`, `src/game/actors/EnemyActor.cpp/hpp` |
| Enemy squad tactics coordinator | ❌ | `src/game/ai/SquadCoordinator.cpp/hpp`, `src/game/RuntimeScene.hpp` |
| Boss phase state machine framework | ❌ | `src/game/actors/BossActor.cpp/hpp`, `src/game/ai/BossPhaseState.hpp` |
| Guard-break / poise combat pipeline | ✅ | `src/game/combat/PoiseSystem.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Elemental damage/resistance matrix | ✅ | `src/game/combat/ElementSystem.hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Status ailment counters + immunity windows | ✅ | `src/game/combat/StatusAilmentSystem.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Equipment progression + socket rules | ❌ | `src/game/inventory/EquipmentProgression.cpp/hpp`, `src/game/inventory/Equipment.hpp` |
| Skill tree graph + unlock prerequisites | ❌ | `src/game/progression/SkillTree.cpp/hpp`, `src/game/progression/AbilityProgression.hpp` |
| Loot table tiers + drop weighting | ❌ | `src/game/loot/LootTable.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp` |
| Crafting + upgrade station flow | ❌ | `src/game/crafting/CraftingSystem.cpp/hpp`, `src/game/actors/RestPointActor.cpp/hpp` |
| Open-world encounter director | ❌ | `src/game/ai/EncounterDirector.cpp/hpp`, `src/world/PopulationDirector.cpp/hpp` |
| Combat telemetry + balance debug panel | ❌ | `src/ui/CombatDebugPanel.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp` |
| Quest authoring schema + validator | ❌ | `src/game/quest/QuestSchema.hpp`, `src/game/quest/QuestSystem.cpp/hpp` |
| Dialogue branching + localization keys | ❌ | `src/game/dialogue/DialogueRuntime.cpp/hpp`, `src/ui/DialogBox.cpp/hpp` |
| Cutscene timeline stub + camera rails | ❌ | `src/game/cutscene/CutsceneTimeline.cpp/hpp`, `src/game/CameraController.cpp/hpp` |
| Audio event router + mixer bus controls | ❌ | `src/audio/AudioRouter.cpp/hpp`, `src/audio/AudioManager.cpp/hpp` |
| Adaptive music state machine | ❌ | `src/audio/MusicStateMachine.cpp/hpp`, `src/audio/AudioManager.cpp/hpp` |
| SFX variation + distance/occlusion rules | ❌ | `src/audio/SfxSpatialRules.cpp/hpp`, `src/audio/AudioManager.cpp/hpp` |
| Voice placeholder + subtitle timing pipeline | ❌ | `src/audio/VoicePlayback.cpp/hpp`, `src/ui/SubtitleOverlay.cpp/hpp` |
| Save versioning + migration compatibility | ❌ | `src/app/SaveMigration.cpp/hpp`, `src/app/SaveSystem.cpp/hpp` |
| Crash capture + runtime diagnostics pack | ❌ | `src/app/CrashDiagnostics.cpp/hpp`, `src/logger/Logger.hpp` |
| Full settings menu (graphics/audio/input/accessibility) | ❌ | `src/ui/SettingsMenu.cpp/hpp`, `src/app/QualityPreset.cpp/hpp` |
| Input rebinding + controller glyph profiles | ❌ | `src/app/InputBindingProfile.cpp/hpp`, `src/ui/GameHUD.cpp/hpp` |
| Performance HUD + auto quality scaler | ❌ | `src/app/AutoQualityScaler.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp` |
| Build packaging + release manifest scripts | ❌ | `tools/release/PackageBuild.ps1`, `docs/RELEASE_BUILD.md` |
| Legal/credits/third-party attribution pass | ❌ | `src/ui/CreditsScreen.cpp/hpp`, `docs/THIRD_PARTY.md` |
| New game bootstrap + onboarding tutorial | ❌ | `src/game/NewGameFlow.cpp/hpp`, `src/ui/TutorialOverlay.cpp/hpp` |
| Vertical-slice certification and ship checklist | ❌ | `docs/SHIP_CHECKLIST.md`, `docs/QUALITY_BAR.md` |

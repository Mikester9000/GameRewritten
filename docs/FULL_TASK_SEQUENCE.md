# Full Task Sequence (Autopilot)

This file is the complete ordered sequence from current state to "all planned systems in `docs/SYSTEMS.md` marked ✅" and ship-ready release tasks complete.

## Execution Rule (No Thinking Required)
1. Run `python tools/llm/worst_llm_guard.py doctor`.
2. Run `python tools/llm/worst_llm_guard.py start`.
3. Execute only the task written into `docs/NEXT_TASK.md`.
4. When done: update `docs/SYSTEMS.md`, `docs/CHANGELOG.md`, `docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete`.
6. Stop. Repeat next run.

## Message Visibility Fallback (If outputs are not appearing)
1. Print a one-line heartbeat first: `STATUS: START Task ###`.
2. Print only one file payload at a time.
3. If output is long, split into chunks and label each chunk:
   - `STATUS: CHUNK 1/N`
   - `STATUS: CHUNK 2/N`
4. End with: `STATUS: DONE Task ###`.

## Mandatory micro-steps per task
1. Read listed files once.
2. Make only the minimum edits needed.
3. Keep edits inside listed files unless compiler requires one extra file.
4. Do not rename/move files.
5. Do not add dependencies.
6. Keep frame-safe defaults for GT610.
7. Update the 3 docs (`SYSTEMS`, `CHANGELOG`, `AGENT_WORK_LOG`).
8. Advance to next task using the guarded command above.

## Global Constraints
- Keep one task per run.
- Keep edits minimal and scoped to listed files.
- Do not create new dependencies.
- Keep D3D11 + GT610-safe defaults.
- If a task requires a new `.cpp`, also update `GameRewritten.vcxproj` and `GameRewritten.vcxproj.filters`.

## Full-System Policy (No Placeholder-Only Completion)
- Any task label containing **stub / lite / base / hook** must be delivered as a **playable production-ready v1 vertical slice**.
- Do not mark a task complete for scaffolding-only code.
- Minimum completion bar per gameplay system task:
  1. Runtime logic path is implemented.
  2. Player-visible feedback exists (UI/audio/animation/event).
  3. Data/config path exists for tuning and content authoring.
  4. Persistence/state continuity is handled when relevant.
  5. Failure-safe fallback path is present.
- If a full implementation does not fit one run, split into sub-tasks (A/B/C) and finish the full chain before checking the parent task.

## Task Ownership Matrix (SLM vs Copilot)
Use this as the execution owner source of truth for Task 001-108.

### SLM-first
- Primary range: **001-030**
- Additional tasks: **046-048, 050-052, 056-058, 106**
- Workflow: strict one-file prompts and deterministic edits.

### Copilot-required
- Primary ranges: **031-045**, **061-105**, **107-108**
- Additional tasks: **049, 053-055, 059-060**
- Includes high-coupling architecture, multi-system reasoning, streaming/world scale, quest/progression depth, and ship gates.

### Escalation rule
- If an SLM-assigned task fails twice, introduces compile/runtime uncertainty, or requires broad multi-file reasoning, escalate to Copilot immediately.

## Professional Gameplay Content Playbook
Use this playbook for questing, NPCs, dialogue, textures, and content quality work.

1. Define content contracts first (IDs, required fields, paths, validators, fallback defaults).
2. Build/import assets within GT610 budgets (mips, compression, low/high fallbacks).
3. Wire loading + validation + clear error logging.
4. Integrate runtime behavior (spawn/state/interaction/feedback/persistence).
5. Document author workflow end-to-end (how to add NPCs, dialogue, quest steps, textures, and references).
6. Run QA checklist (progression continuity, save/load, missing asset behavior, readability, performance).
7. Mark done only when the full loop is playable end-to-end.

## Completion Target
Project completion for this autopilot track means:
- Every `❌` item from `docs/SYSTEMS.md` is implemented and flipped to `✅`.
- No remaining unchecked tasks in this file.
- Open-world traversal works at multi-continent scale with streaming-safe runtime behavior.
- Release gates for packaging/legal/settings/onboarding are complete.
- Systems are fully playable and integrated, not placeholder-only.

---

## Phase 1 — Combat + HUD foundation

- [x] **Task 001: Pressure / stagger integration stub**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 002: Enemy reaction / interrupt-lite**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 003: Enemy attack telegraph lite**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 004: Screen edge damage flash**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 005: Hit pause / hitstop**
  - Files: `src/game/RuntimeScene.hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 006: Stagger meter**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 007: Enemy attack telegraph**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 008: Parry / counter window**
  - Files: `src/game/actors/PlayerActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 009: Weak point damage**
  - Files: `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 010: Area name display**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 011: Notification toast system**
  - Files: `src/ui/NotificationSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 012: Letterbox event bars**
  - Files: `src/ui/ImGuiLayer.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 013: Contextual button prompts**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 014: Level up screen overlay**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 015: Status screen**
  - Files: `src/ui/StatusScreen.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 016: Map screen stub**
  - Files: `src/ui/MapScreen.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 017: Tooltip system**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 018: Saving indicator**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 019: Death / defeat screen**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

---

## Phase 2 — Camera + visual polish

- [x] **Task 020: Camera shake**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 021: Combat camera zoom**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 022: Camera collision avoidance**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 023: Target framing adjustment**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 024: Lock-on camera recovery smoothing**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 025: Wind effect on trees**
  - Files: `Shaders/tree_vs.hlsl`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 026: Weather system lite**
  - Files: `src/world/WeatherSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 027: Ambient particles**
  - Files: `src/game/ParticleSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 028: Day/night cycle**
  - Files: `src/world/DayNightCycle.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 029: Biome transition fade**
  - Files: `src/world/WorldGrid.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 030: Fog of war on minimap**
  - Files: `src/ui/Minimap.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 030A: Cel shading band quantization**
  - Files: `Shaders/basic3d_ps.hlsl`, `src/rendering/d3d11/D3D11Renderer.cpp`
  - Steps: add quantized diffuse lighting bands and wire cel-shading constants into the basic 3D pass.
  - Done when: toon bands render on runtime actors and shader constants are runtime-configurable.

- [x] **Task 030B: Cel shader shadow tint + rim gate**
  - Files: `Shaders/basic3d_ps.hlsl`
  - Steps: add shadow tint control and gated rim light for silhouette readability without full-screen cost.
  - Done when: backlit silhouettes stay readable while preserving low-spec lighting cost.

- [x] **Task 030C: Cel specular step highlights**
  - Files: `Shaders/basic3d_ps.hlsl`
  - Steps: replace smooth specular with thresholded highlight bands to match FF-style stylized materials.
  - Done when: metallic/highlight response uses stepped specular instead of continuous gloss.

- [x] **Task 030D: Cel shader material parameter plumbing**
  - Files: `src/rendering/d3d11/D3D11Renderer.cpp`, `src/assets/AssetLoader.cpp/hpp`
  - Steps: expose cel parameters (band count, rim amount, shadow tint, spec threshold) through renderer/material load path.
  - Done when: materials can override cel defaults without shader recompilation.

- [ ] **Task 030E: Character outline pass (inverted hull)**
  - Files: `Shaders/basic3d_vs.hlsl`, `Shaders/basic3d_ps.hlsl`, `src/rendering/d3d11/D3D11Renderer.cpp`
  - Steps: add low-cost outline pass using expanded backfaces and depth-tested dark silhouette color.
  - Done when: player/enemy silhouettes remain readable in busy environments.

- [ ] **Task 030F: Cel shader debug controls + fallback path**
  - Files: `src/ui/ImGuiLayer.cpp/hpp`, `src/rendering/d3d11/D3D11Renderer.cpp`
  - Steps: add debug toggles and a safe fallback to legacy shading for validation and low-risk rollout.
  - Done when: cel shading can be toggled live and fallback path renders identically to current baseline.

---

## Phase 3 — World + quest + progression core

- [x] **Task 031: World event trigger zones**
  - Files: `src/game/world/EventZone.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 032: Interaction hotspot registry stub**
  - Files: `src/game/world/InteractionRegistry.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 033: Landmark discovery trigger stub**
  - Files: `src/game/world/LandmarkTrigger.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 034: NPC actor**
  - Files: `src/game/actors/NpcActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 035: Quest objective system**
  - Files: `src/game/quest/QuestSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 036: Treasure chest actor**
  - Files: `src/game/actors/ChestActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [x] **Task 037: Campfire / rest point actor**
  - Files: `src/game/actors/RestPointActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 038: NPC interaction prompt routing stub**
  - Files: `src/ui/GameHUD.cpp/hpp`, `src/game/world/InteractionRegistry.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 039: Quest flag / world-state hook**
  - Files: `src/game/quest/QuestFlags.hpp`, `src/game/quest/QuestSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 040: Spawn composition table stub (solo / pair / pack)**
  - Files: `src/world/SpawnTable.hpp`, `src/world/WorldGrid.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 041: Inventory system**
  - Files: `src/game/inventory/Inventory.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 042: XP / level system**
  - Files: `src/game/actors/PlayerStats.hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 043: Status effects**
  - Files: `src/game/actors/PlayerStats.hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 044: Fast travel stub**
  - Files: `src/game/world/FastTravel.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 045: Save / load system**
  - Files: `src/app/SaveSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

---

## Phase 4 — Audio + quality + progression glue

- [ ] **Task 046: Quality preset enforcement**
  - Files: `src/app/QualityPreset.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 047: Victory fanfare trigger**
  - Files: `src/audio/AudioManager.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 048: Environmental ambient audio**
  - Files: `src/audio/AudioManager.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 049: Looping BGM**
  - Files: `src/audio/AudioManager.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 050: Tactical Pause enter / exit SFX**
  - Files: `src/audio/AudioManager.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 051: Lock-on acquire / break SFX**
  - Files: `src/audio/AudioManager.cpp/hpp`, `src/game/combat/Targeting.hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 052: Enemy alert bark stub**
  - Files: `src/audio/AudioManager.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 053: Equipment slot stub**
  - Files: `src/game/inventory/Equipment.hpp`, `src/game/actors/PlayerStats.hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 054: Ability unlock / progression hook**
  - Files: `src/game/progression/AbilityProgression.hpp`, `src/game/actors/PlayerStats.hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 055: Combat stat modifier pipeline stub**
  - Files: `src/game/combat/CombatModifiers.hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

---

## Phase 5 — Debugging + polish completion pass (mandatory)

- [ ] **Task 056: Combat bugfix sweep**
  - Files: `src/game/combat/CombatSystem.cpp/hpp`, `src/game/RuntimeScene.hpp`, `src/app/Main.cpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 057: Camera/input bugfix sweep**
  - Files: `src/game/CameraController.cpp/hpp`, `src/app/InputActionMap.hpp`, `src/app/Main.cpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 058: UI/HUD polish and bugfix sweep**
  - Files: `src/ui/GameHUD.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 059: World/runtime stability sweep**
  - Files: `src/world/WorldGrid.cpp/hpp`, `src/game/RuntimeScene.cpp/hpp`, `src/game/Forest.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 060: Audio and final quality sweep**
  - Files: `src/audio/AudioManager.cpp/hpp`, `src/app/QualityPreset.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

---

## Phase 6 — Open-world scale foundation (multi-continent)

- [ ] **Task 061: World partition + region streaming core**
  - Files: `src/world/WorldPartition.cpp/hpp`, `src/world/WorldGrid.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 062: Asynchronous chunk IO + prefetch queue**
  - Files: `src/world/StreamingIO.cpp/hpp`, `src/assets/AssetLoader.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 063: Large-world coordinate rebasing**
  - Files: `src/world/WorldOriginRebase.cpp/hpp`, `src/app/Main.cpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 064: Terrain/mesh LOD tier manager**
  - Files: `src/world/WorldLodManager.cpp/hpp`, `src/rendering/d3d11/D3D11Renderer.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 065: Streaming budget governor (CPU/GPU/IO)**
  - Files: `src/world/StreamingBudget.hpp`, `src/world/WorldGrid.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 066: Far-distance continent impostors**
  - Files: `src/world/ContinentImpostor.cpp/hpp`, `Shaders/continent_impostor_vs.hlsl`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 067: Global nav tile streaming bridge**
  - Files: `src/game/world/NavTileStream.cpp/hpp`, `ThirdParty/tp_navigation.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 068: Seamless continent transition triggers**
  - Files: `src/world/ContinentTransition.cpp/hpp`, `src/world/WorldGrid.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 069: Traversal mount/vehicle framework stub**
  - Files: `src/game/traversal/TraversalMount.cpp/hpp`, `src/game/RuntimeScene.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 070: Traversal verbs: climb/swim/glide base**
  - Files: `src/game/traversal/TraversalController.cpp/hpp`, `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 071: Seamless interior/exterior cell portals**
  - Files: `src/world/CellPortal.cpp/hpp`, `src/game/world/EventZone.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 072: World map overlay with continent zoom**
  - Files: `src/ui/WorldMap.cpp/hpp`, `src/ui/MapScreen.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 073: Discovery journal for landmarks/routes**
  - Files: `src/game/world/DiscoveryJournal.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 074: Biome-aware population spawn director**
  - Files: `src/world/PopulationDirector.cpp/hpp`, `src/world/WorldGrid.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 075: World event scheduler (time/weather/region)**
  - Files: `src/world/WorldEventScheduler.cpp/hpp`, `src/world/DayNightCycle.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 076: Region state persistence for streamed world**
  - Files: `src/world/RegionStateStore.cpp/hpp`, `src/app/SaveSystem.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

---

## Phase 7 — FF7R-style gameplay depth (party/combat/progression)

- [ ] **Task 077: Party member runtime slot + follow AI**
  - Files: `src/game/party/PartyRuntime.cpp/hpp`, `src/game/RuntimeScene.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 078: Command wheel + tactical slow-time commands**
  - Files: `src/ui/CommandWheel.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 079: ATB-style action charge lanes**
  - Files: `src/game/combat/AtbSystem.cpp/hpp`, `src/game/actors/PlayerStats.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 080: Ability targeting templates (single/cone/aoe)**
  - Files: `src/game/combat/AbilityTargeting.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [x] **Task 081: Enemy archetype behavior profiles**
  - Files: `src/game/ai/EnemyArchetypeProfile.hpp`, `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 082: Enemy squad tactics coordinator**
  - Files: `src/game/ai/SquadCoordinator.cpp/hpp`, `src/game/RuntimeScene.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 083: Boss phase state machine framework**
  - Files: `src/game/actors/BossActor.cpp/hpp`, `src/game/ai/BossPhaseState.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 084: Guard-break / poise combat pipeline**
  - Files: `src/game/combat/PoiseSystem.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 085: Elemental damage/resistance matrix**
  - Files: `src/game/combat/ElementSystem.hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 086: Status ailment counters + immunity windows**
  - Files: `src/game/combat/StatusAilmentSystem.cpp/hpp`, `src/game/actors/PlayerStats.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 087: Equipment progression + socket rules**
  - Files: `src/game/inventory/EquipmentProgression.cpp/hpp`, `src/game/inventory/Equipment.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 088: Skill tree graph + unlock prerequisites**
  - Files: `src/game/progression/SkillTree.cpp/hpp`, `src/game/progression/AbilityProgression.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [x] **Task 089: Loot table tiers + drop weighting**
  - Files: `src/game/loot/LootTable.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 090: Crafting + upgrade station flow**
  - Files: `src/game/crafting/CraftingSystem.cpp/hpp`, `src/game/actors/RestPointActor.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 091: Open-world encounter director**
  - Files: `src/game/ai/EncounterDirector.cpp/hpp`, `src/world/PopulationDirector.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 092: Combat telemetry + balance debug panel**
  - Files: `src/ui/CombatDebugPanel.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

---

## Phase 8 — Audio/content pipeline + ship readiness

- [ ] **Task 093: Quest authoring schema + validator**
  - Files: `src/game/quest/QuestSchema.hpp`, `src/game/quest/QuestSystem.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 094: Dialogue branching + localization keys**
  - Files: `src/game/dialogue/DialogueRuntime.cpp/hpp`, `src/ui/DialogBox.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 095: Cutscene timeline stub + camera rails**
  - Files: `src/game/cutscene/CutsceneTimeline.cpp/hpp`, `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 096: Audio event router + mixer bus controls**
  - Files: `src/audio/AudioRouter.cpp/hpp`, `src/audio/AudioManager.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 097: Adaptive music state machine**
  - Files: `src/audio/MusicStateMachine.cpp/hpp`, `src/audio/AudioManager.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 098: SFX variation + distance/occlusion rules**
  - Files: `src/audio/SfxSpatialRules.cpp/hpp`, `src/audio/AudioManager.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 099: Voice placeholder + subtitle timing pipeline**
  - Files: `src/audio/VoicePlayback.cpp/hpp`, `src/ui/SubtitleOverlay.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 100: Save versioning + migration compatibility**
  - Files: `src/app/SaveMigration.cpp/hpp`, `src/app/SaveSystem.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 101: Crash capture + runtime diagnostics pack**
  - Files: `src/app/CrashDiagnostics.cpp/hpp`, `src/logger/Logger.hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 102: Full settings menu (graphics/audio/input/accessibility)**
  - Files: `src/ui/SettingsMenu.cpp/hpp`, `src/app/QualityPreset.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 103: Input rebinding + controller glyph profiles**
  - Files: `src/app/InputBindingProfile.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 104: Performance HUD + auto quality scaler**
  - Files: `src/app/AutoQualityScaler.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 105: Build packaging + release manifest scripts**
  - Files: `tools/release/PackageBuild.ps1`, `docs/RELEASE_BUILD.md`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 106: Legal/credits/third-party attribution pass**
  - Files: `src/ui/CreditsScreen.cpp/hpp`, `docs/THIRD_PARTY.md`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 107: New game bootstrap + onboarding tutorial**
  - Files: `src/game/NewGameFlow.cpp/hpp`, `src/ui/TutorialOverlay.cpp/hpp`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

- [ ] **Task 108: Vertical-slice certification and ship checklist**
  - Files: `docs/SHIP_CHECKLIST.md`, `docs/QUALITY_BAR.md`
  - Steps: implement smallest viable ship-path slice in listed files, keep GT610-safe defaults, and avoid cross-task scope creep.
  - Done when: runtime or tooling behavior is usable, tracking row in `docs/SYSTEMS.md` is flipped to ✅ when implemented, changelog/log updated.

---

# Full Task Sequence (Autopilot)

This file is the complete ordered sequence from current state to "all planned systems in `docs/SYSTEMS.md` marked ✅".

## Execution Rule (No Thinking Required)
1. Run `python tools/llm/advance_next_task.py`.
2. Execute only the task written into `docs/NEXT_TASK.md`.
3. When done: update `docs/SYSTEMS.md`, `docs/CHANGELOG.md`, `docs/AGENT_WORK_LOG.md`.
4. Run `python tools/llm/advance_next_task.py --complete-current`.
5. Stop. Repeat next run.

## Mandatory micro-steps per task
1. Read listed files once.
2. Make only the minimum edits needed.
3. Keep edits inside listed files unless compiler requires one extra file.
4. Do not rename/move files.
5. Do not add dependencies.
6. Keep frame-safe defaults for GT610.
7. Update the 3 docs (`SYSTEMS`, `CHANGELOG`, `AGENT_WORK_LOG`).
8. Advance to next task using the script command above.

## Global Constraints
- Keep one task per run.
- Keep edits minimal and scoped to listed files.
- Do not create new dependencies.
- Keep D3D11 + GT610-safe defaults.
- If a task requires a new `.cpp`, also update `GameRewritten.vcxproj` and `GameRewritten.vcxproj.filters`.

## Completion Target
Project completion for this autopilot track means:
- Every `❌` item from `docs/SYSTEMS.md` is implemented and flipped to `✅`.
- No remaining unchecked tasks in this file.

---

## Phase 1 — Combat + HUD foundation

- [ ] **Task 001: Pressure / stagger integration stub**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 002: Enemy reaction / interrupt-lite**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 003: Enemy attack telegraph lite**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 004: Screen edge damage flash**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 005: Hit pause / hitstop**
  - Files: `src/game/RuntimeScene.hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 006: Stagger meter**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 007: Enemy attack telegraph**
  - Files: `src/game/actors/EnemyActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 008: Parry / counter window**
  - Files: `src/game/actors/PlayerActor.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 009: Weak point damage**
  - Files: `src/game/combat/CombatSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 010: Area name display**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 011: Notification toast system**
  - Files: `src/ui/NotificationSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 012: Letterbox event bars**
  - Files: `src/ui/ImGuiLayer.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 013: Contextual button prompts**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 014: Level up screen overlay**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 015: Status screen**
  - Files: `src/ui/StatusScreen.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 016: Map screen stub**
  - Files: `src/ui/MapScreen.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 017: Tooltip system**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 018: Saving indicator**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 019: Death / defeat screen**
  - Files: `src/ui/GameHUD.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.


---

## Phase 2 — Camera + visual polish

- [ ] **Task 020: Camera shake**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 021: Combat camera zoom**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 022: Camera collision avoidance**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 023: Target framing adjustment**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 024: Lock-on camera recovery smoothing**
  - Files: `src/game/CameraController.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 025: Wind effect on trees**
  - Files: `Shaders/tree_vs.hlsl`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 026: Weather system lite**
  - Files: `src/world/WeatherSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 027: Ambient particles**
  - Files: `src/game/ParticleSystem.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 028: Day/night cycle**
  - Files: `src/world/DayNightCycle.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 029: Biome transition fade**
  - Files: `src/world/WorldGrid.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.

- [ ] **Task 030: Fog of war on minimap**
  - Files: `src/ui/Minimap.cpp/hpp`
  - Steps: implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
  - Done when: feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.


---

## Phase 3 — World + quest + progression core

- [ ] **Task 031: World event trigger zones**
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

- [ ] **Task 034: NPC actor**
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

- [ ] **Task 037: Campfire / rest point actor**
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

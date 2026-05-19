# One-File Completion Plan (Copy/Paste Task Prompt Pack)

This document is self-contained and is the only file needed to run the completion track.
Do not execute multiple tasks in one run. Use exactly one task card per run.

## Completion Definition (Locked)
- `docs/SYSTEMS.md` has no `❌` entries.
- `docs/FULL_TASK_SEQUENCE.md` has no unchecked tasks.
- `docs/NEXT_TASK.md` reports no remaining unchecked tasks.

## Global Rules (Non-Negotiable)
1. One task per run only.
2. Edit only the files listed in the chosen task card unless compile errors force one extra file.
3. No dependency additions.
4. No file moves or renames.
5. Keep D3D11 + GT610-safe defaults.
6. Apply smallest safe implementation (stub is acceptable when blocked).
7. Required docs per task: `docs/SYSTEMS.md`, `docs/CHANGELOG.md`, `docs/AGENT_WORK_LOG.md`.
8. After each task, run guarded completion and stop.

## Environment Note (Build Tooling)
- In this environment, `dotnet build` for this C++ solution fails with `MSB4278` (missing Visual Studio C++ targets).
- Use the existing guarded workflow commands as the mandatory pass/fail gate for task progression.

## Zero-Decision Run Commands (Every Run)
```bash
python tools/llm/worst_llm_guard.py doctor
python tools/llm/worst_llm_guard.py start
# implement exactly one task card from this file
python tools/llm/worst_llm_guard.py complete
```

## Copy/Paste Prompt Template (Use per Task)
Use this exact template for each run and replace placeholders:

```text
Implement Task <ID>: <NAME>.

Scope (only these files): <FILES>

Rules: one-task-only, no new dependencies, no file moves/renames, GT610-safe defaults, smallest working slice.

Required docs update before complete:
- docs/SYSTEMS.md: flip this system from ❌ to ✅
- docs/CHANGELOG.md: add one line for this task
- docs/AGENT_WORK_LOG.md: append one entry with files changed + known issues

Run guarded completion and stop: python tools/llm/worst_llm_guard.py complete
```

## Task Cards (001–060)
For each card: copy the card into your prompt, implement only that card, update required docs, run `complete`, stop.

### Task 001: Pressure / stagger integration stub
- **Code to work on:** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 001: Pressure / stagger integration stub.
Scope (only these files): `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 002: Enemy reaction / interrupt-lite
- **Code to work on:** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 002: Enemy reaction / interrupt-lite.
Scope (only these files): `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 003: Enemy attack telegraph lite
- **Code to work on:** `src/game/actors/EnemyActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 003: Enemy attack telegraph lite.
Scope (only these files): `src/game/actors/EnemyActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 004: Screen edge damage flash
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 004: Screen edge damage flash.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 005: Hit pause / hitstop
- **Code to work on:** `src/game/RuntimeScene.hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 005: Hit pause / hitstop.
Scope (only these files): `src/game/RuntimeScene.hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 006: Stagger meter
- **Code to work on:** `src/game/actors/EnemyActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 006: Stagger meter.
Scope (only these files): `src/game/actors/EnemyActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 007: Enemy attack telegraph
- **Code to work on:** `src/game/actors/EnemyActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 007: Enemy attack telegraph.
Scope (only these files): `src/game/actors/EnemyActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 008: Parry / counter window
- **Code to work on:** `src/game/actors/PlayerActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 008: Parry / counter window.
Scope (only these files): `src/game/actors/PlayerActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 009: Weak point damage
- **Code to work on:** `src/game/combat/CombatSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 009: Weak point damage.
Scope (only these files): `src/game/combat/CombatSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 010: Area name display
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 010: Area name display.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 011: Notification toast system
- **Code to work on:** `src/ui/NotificationSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 011: Notification toast system.
Scope (only these files): `src/ui/NotificationSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 012: Letterbox event bars
- **Code to work on:** `src/ui/ImGuiLayer.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 012: Letterbox event bars.
Scope (only these files): `src/ui/ImGuiLayer.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 013: Contextual button prompts
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 013: Contextual button prompts.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 014: Level up screen overlay
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 014: Level up screen overlay.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 015: Status screen
- **Code to work on:** `src/ui/StatusScreen.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 015: Status screen.
Scope (only these files): `src/ui/StatusScreen.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 016: Map screen stub
- **Code to work on:** `src/ui/MapScreen.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 016: Map screen stub.
Scope (only these files): `src/ui/MapScreen.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 017: Tooltip system
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 017: Tooltip system.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 018: Saving indicator
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 018: Saving indicator.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 019: Death / defeat screen
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 019: Death / defeat screen.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 020: Camera shake
- **Code to work on:** `src/game/CameraController.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 020: Camera shake.
Scope (only these files): `src/game/CameraController.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 021: Combat camera zoom
- **Code to work on:** `src/game/CameraController.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 021: Combat camera zoom.
Scope (only these files): `src/game/CameraController.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 022: Camera collision avoidance
- **Code to work on:** `src/game/CameraController.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 022: Camera collision avoidance.
Scope (only these files): `src/game/CameraController.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 023: Target framing adjustment
- **Code to work on:** `src/game/CameraController.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 023: Target framing adjustment.
Scope (only these files): `src/game/CameraController.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 024: Lock-on camera recovery smoothing
- **Code to work on:** `src/game/CameraController.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 024: Lock-on camera recovery smoothing.
Scope (only these files): `src/game/CameraController.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 025: Wind effect on trees
- **Code to work on:** `Shaders/tree_vs.hlsl`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 025: Wind effect on trees.
Scope (only these files): `Shaders/tree_vs.hlsl`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 026: Weather system lite
- **Code to work on:** `src/world/WeatherSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 026: Weather system lite.
Scope (only these files): `src/world/WeatherSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 027: Ambient particles
- **Code to work on:** `src/game/ParticleSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 027: Ambient particles.
Scope (only these files): `src/game/ParticleSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 028: Day/night cycle
- **Code to work on:** `src/world/DayNightCycle.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 028: Day/night cycle.
Scope (only these files): `src/world/DayNightCycle.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 029: Biome transition fade
- **Code to work on:** `src/world/WorldGrid.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 029: Biome transition fade.
Scope (only these files): `src/world/WorldGrid.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 030: Fog of war on minimap
- **Code to work on:** `src/ui/Minimap.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 030: Fog of war on minimap.
Scope (only these files): `src/ui/Minimap.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 031: World event trigger zones
- **Code to work on:** `src/game/world/EventZone.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 031: World event trigger zones.
Scope (only these files): `src/game/world/EventZone.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 032: Interaction hotspot registry stub
- **Code to work on:** `src/game/world/InteractionRegistry.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 032: Interaction hotspot registry stub.
Scope (only these files): `src/game/world/InteractionRegistry.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 033: Landmark discovery trigger stub
- **Code to work on:** `src/game/world/LandmarkTrigger.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 033: Landmark discovery trigger stub.
Scope (only these files): `src/game/world/LandmarkTrigger.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 034: NPC actor
- **Code to work on:** `src/game/actors/NpcActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 034: NPC actor.
Scope (only these files): `src/game/actors/NpcActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 035: Quest objective system
- **Code to work on:** `src/game/quest/QuestSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 035: Quest objective system.
Scope (only these files): `src/game/quest/QuestSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 036: Treasure chest actor
- **Code to work on:** `src/game/actors/ChestActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 036: Treasure chest actor.
Scope (only these files): `src/game/actors/ChestActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 037: Campfire / rest point actor
- **Code to work on:** `src/game/actors/RestPointActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 037: Campfire / rest point actor.
Scope (only these files): `src/game/actors/RestPointActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 038: NPC interaction prompt routing stub
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`, `src/game/world/InteractionRegistry.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 038: NPC interaction prompt routing stub.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`, `src/game/world/InteractionRegistry.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 039: Quest flag / world-state hook
- **Code to work on:** `src/game/quest/QuestFlags.hpp`, `src/game/quest/QuestSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 039: Quest flag / world-state hook.
Scope (only these files): `src/game/quest/QuestFlags.hpp`, `src/game/quest/QuestSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 040: Spawn composition table stub (solo / pair / pack)
- **Code to work on:** `src/world/SpawnTable.hpp`, `src/world/WorldGrid.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 040: Spawn composition table stub (solo / pair / pack).
Scope (only these files): `src/world/SpawnTable.hpp`, `src/world/WorldGrid.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 041: Inventory system
- **Code to work on:** `src/game/inventory/Inventory.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 041: Inventory system.
Scope (only these files): `src/game/inventory/Inventory.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 042: XP / level system
- **Code to work on:** `src/game/actors/PlayerStats.hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 042: XP / level system.
Scope (only these files): `src/game/actors/PlayerStats.hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 043: Status effects
- **Code to work on:** `src/game/actors/PlayerStats.hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 043: Status effects.
Scope (only these files): `src/game/actors/PlayerStats.hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 044: Fast travel stub
- **Code to work on:** `src/game/world/FastTravel.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 044: Fast travel stub.
Scope (only these files): `src/game/world/FastTravel.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 045: Save / load system
- **Code to work on:** `src/app/SaveSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 045: Save / load system.
Scope (only these files): `src/app/SaveSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 046: Quality preset enforcement
- **Code to work on:** `src/app/QualityPreset.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 046: Quality preset enforcement.
Scope (only these files): `src/app/QualityPreset.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 047: Victory fanfare trigger
- **Code to work on:** `src/audio/AudioManager.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 047: Victory fanfare trigger.
Scope (only these files): `src/audio/AudioManager.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 048: Environmental ambient audio
- **Code to work on:** `src/audio/AudioManager.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 048: Environmental ambient audio.
Scope (only these files): `src/audio/AudioManager.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 049: Looping BGM
- **Code to work on:** `src/audio/AudioManager.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 049: Looping BGM.
Scope (only these files): `src/audio/AudioManager.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 050: Tactical Pause enter / exit SFX
- **Code to work on:** `src/audio/AudioManager.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 050: Tactical Pause enter / exit SFX.
Scope (only these files): `src/audio/AudioManager.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 051: Lock-on acquire / break SFX
- **Code to work on:** `src/audio/AudioManager.cpp/hpp`, `src/game/combat/Targeting.hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 051: Lock-on acquire / break SFX.
Scope (only these files): `src/audio/AudioManager.cpp/hpp`, `src/game/combat/Targeting.hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 052: Enemy alert bark stub
- **Code to work on:** `src/audio/AudioManager.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 052: Enemy alert bark stub.
Scope (only these files): `src/audio/AudioManager.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 053: Equipment slot stub
- **Code to work on:** `src/game/inventory/Equipment.hpp`, `src/game/actors/PlayerStats.hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 053: Equipment slot stub.
Scope (only these files): `src/game/inventory/Equipment.hpp`, `src/game/actors/PlayerStats.hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 054: Ability unlock / progression hook
- **Code to work on:** `src/game/progression/AbilityProgression.hpp`, `src/game/actors/PlayerStats.hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 054: Ability unlock / progression hook.
Scope (only these files): `src/game/progression/AbilityProgression.hpp`, `src/game/actors/PlayerStats.hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 055: Combat stat modifier pipeline stub
- **Code to work on:** `src/game/combat/CombatModifiers.hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 055: Combat stat modifier pipeline stub.
Scope (only these files): `src/game/combat/CombatModifiers.hpp`, `src/game/combat/CombatSystem.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 056: Combat bugfix sweep
- **Code to work on:** `src/game/combat/CombatSystem.cpp/hpp`, `src/game/RuntimeScene.hpp`, `src/app/Main.cpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 056: Combat bugfix sweep.
Scope (only these files): `src/game/combat/CombatSystem.cpp/hpp`, `src/game/RuntimeScene.hpp`, `src/app/Main.cpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 057: Camera/input bugfix sweep
- **Code to work on:** `src/game/CameraController.cpp/hpp`, `src/app/InputActionMap.hpp`, `src/app/Main.cpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 057: Camera/input bugfix sweep.
Scope (only these files): `src/game/CameraController.cpp/hpp`, `src/app/InputActionMap.hpp`, `src/app/Main.cpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 058: UI/HUD polish and bugfix sweep
- **Code to work on:** `src/ui/GameHUD.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 058: UI/HUD polish and bugfix sweep.
Scope (only these files): `src/ui/GameHUD.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 059: World/runtime stability sweep
- **Code to work on:** `src/world/WorldGrid.cpp/hpp`, `src/game/RuntimeScene.cpp/hpp`, `src/game/Forest.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 059: World/runtime stability sweep.
Scope (only these files): `src/world/WorldGrid.cpp/hpp`, `src/game/RuntimeScene.cpp/hpp`, `src/game/Forest.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

### Task 060: Audio and final quality sweep
- **Code to work on:** `src/audio/AudioManager.cpp/hpp`, `src/app/QualityPreset.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
- **Implementation target:** smallest viable, visible/usable slice, guarded and reversible.
- **Required task-finish updates:**
  - `docs/SYSTEMS.md` status row for this system -> `✅`
  - one bullet line in `docs/CHANGELOG.md`
  - one entry in `docs/AGENT_WORK_LOG.md`
- **Task prompt block (copy exactly):**
```text
Implement Task 060: Audio and final quality sweep.
Scope (only these files): `src/audio/AudioManager.cpp/hpp`, `src/app/QualityPreset.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
Implement the smallest working version only. Keep edits scoped and GT610-safe. No new dependencies.
Update docs/SYSTEMS.md, docs/CHANGELOG.md, docs/AGENT_WORK_LOG.md, then run: python tools/llm/worst_llm_guard.py complete
```

## Final Completion Checklist (After Task 060)
1. Run `python tools/llm/worst_llm_guard.py doctor`.
2. Confirm `docs/NEXT_TASK.md` says no unchecked tasks remain.
3. Confirm all tasks are checked in `docs/FULL_TASK_SEQUENCE.md`.
4. Confirm no `❌` rows remain in `docs/SYSTEMS.md`.
5. Review `docs/AGENT_WORK_LOG.md` and close or clearly document unresolved issues.
6. Reconcile docs drift (current state/workflow/vision docs) to implemented reality.
7. Verify `Main.cpp` remains orchestration-only and avoid new monolithic regressions.
8. Verify GT610-safe defaults and quality preset behavior remain conservative.
9. Verify save/load + progression + world-state hooks do not block gameplay loop.
10. Verify combat loop and audio state transitions are stable and deterministic.
11. Add final release-readiness changelog summary.
12. Mark completion-track reached and freeze this backlog baseline.
13. Start post-completion roadmap as a separate track.

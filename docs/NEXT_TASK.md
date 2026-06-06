# NEXT TASK (Auto-Generated)

This is your only coding task.
Do not choose a different task.

**Task ID:** 031
**System:** World event trigger zones
**Files to touch:** `src/game/world/EventZone.cpp`, `src/game/world/EventZone.hpp`

---

## What this system does
Trigger zones placed in the world that fire events when the player enters them.
Used for: dialog triggers, area transitions, cutscene starts, quest progression, enemy spawns.
This is the foundation that all narrative and quest systems depend on.

## Zero-decision execution steps
1. Run `python tools/llm/worst_llm_guard.py doctor`.
2. Open each listed file and read it once top-to-bottom.
3. Implement the smallest working version: an AABB zone in world space that detects player entry and fires a callback/event ID.
4. Keep edits inside listed files only unless strictly required by compiler errors.
5. Do not rename files or move files.
6. Do not add dependencies.
7. Keep D3D11 + GT610-safe defaults.

## Minimum viable implementation
- `EventZone` struct: position (vec3), half-extents (vec3), event ID (string or int), one-shot flag (bool), triggered flag (bool)
- `EventZoneRegistry`: flat list of zones, `Update(playerPos)` checks all zones each frame, fires callback on first entry
- Callback: for now, just a std::function<void(int)> or simple delegate — keep it simple
- Integration point: `src/app/Main.cpp` or `WorldRuntimeRefresh` calls `EventZoneRegistry::Update()` each frame

## Required completion updates
1. Update `docs/SYSTEMS.md` for this system (`❌` -> `✅`).
2. Add one line in `docs/CHANGELOG.md`.
3. Append one entry in `docs/AGENT_WORK_LOG.md`.
4. Run:
   `python tools/llm/worst_llm_guard.py complete`

## Hard stop rule
After the command above succeeds, stop immediately.

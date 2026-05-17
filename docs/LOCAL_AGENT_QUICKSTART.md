## Section 1 — What this is:
Direct3D 11 C++ game engine. Windows only. GT 610 target.

## Section 2 — Folder map (one line each):
- `src/app/` startup/shutdown/frame loop
- `src/rendering/` D3D11 resources/shaders/draw
- `src/game/` gameplay/actors/combat/camera
- `src/world/` world cells/biomes/streaming
- `src/assets/` asset IDs/loaders/caches
- `src/ui/` HUD/menus/editor panels
- `src/audio/` audio playback wrappers

## Section 3 — Hard rules:
1. Run `python tools/llm/worst_llm_guard.py doctor` then `start` before coding.
2. Implement only what `docs/NEXT_TASK.md` says, in listed files only.
3. Use `LOG_INFO`/`LOG_WARN`/`LOG_ERROR`; never `printf`/`std::cout`.
4. Keep `Main.cpp` init/shutdown order unchanged.
5. Add every new `.cpp` to `GameRewritten.vcxproj` and `.filters`.

## Section 4 — Copy-paste boilerplate:
```cpp
LOG_INFO("message");
LOG_WARN("message");
LOG_ERROR("message");
{ GR_ZONE_SCOPED_N("ZoneName"); /* code */ }
```

## Section 5 — After writing code:
1. Update `docs/SYSTEMS.md` (`❌` -> `✅`) for the implemented system.
2. Add one `[YYYY-MM-DD] ...` line in `docs/CHANGELOG.md`.
3. Add one entry in `docs/AGENT_WORK_LOG.md`.
4. Run `python tools/llm/worst_llm_guard.py complete` and stop.

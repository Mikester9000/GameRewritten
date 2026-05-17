# LOCAL AGENT QUICKSTART

## Section 1 — What this is:
> Direct3D 11 C++ game engine. Windows only. GT 610 GPU target.

## Section 2 — Folder map (one line each):
- `src/app/` → startup, shutdown, frame orchestration only
- `src/rendering/` → GPU resources, shaders, draw calls only
- `src/game/` → gameplay, actors, combat, camera
- `src/world/` → world cells, biomes, streaming
- `src/assets/` → asset registry, content loading
- `src/ui/` → HUD, menus, editor panels
- `src/audio/` → audio playback only
- `src/logger/` → logger only, do not modify

## Section 3 — Hard rules (numbered, one sentence each):
1. Log with `LOG_INFO` / `LOG_WARN` / `LOG_ERROR` only. Never `printf` or `std::cout`.
2. Never add third-party libraries. All are vendored.
3. Never change `Main.cpp` init or shutdown order.
4. Every new `.cpp` file must be added to `GameRewritten.vcxproj` AND `GameRewritten.vcxproj.filters`.
5. One function = one job. Write top-to-bottom: setup → guards → logic → output.
6. ONE ACTION PER RUN. Write one function or edit one block. Stop after that.

## Section 4 — Copy-paste boilerplate (verbatim, no generation needed):
```cpp
// Logging:
LOG_INFO("message");
LOG_WARN("message");
LOG_ERROR("message");

// Tracy profiling zone (Debug only):
{ GR_ZONE_SCOPED_N("ZoneName"); /* code here */ }
```

## Section 5 — After writing code:
- Open `docs/SYSTEMS.md`. Find the system you just built. Change ❌ to ✅.
- Open `docs/CHANGELOG.md`. Add one line: `[YYYY-MM-DD] Added <SystemName>.`

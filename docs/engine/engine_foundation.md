# Engine Foundation Reference

**GameRewritten — Action RPG Engine**  
Target feel: early PlayStation Final Fantasy visual style (FF7/FF8/FF10) with modern real-time
action combat (FF7 Remake / FF15) and seamless open-world traversal.

---

## 1. Module Boundaries

Each top-level directory under `src/` is an isolated module. Modules communicate through
explicit interfaces, not by reaching into each other's private state.

| Module | Path | Responsibility |
|---|---|---|
| **app** | `src/app/` | Application entry, system wiring, main loop orchestration |
| **platform** | `src/platform/` | OS-specific window and input surface (Win32 today) |
| **rendering** | `src/rendering/` | GPU resource lifetime, shaders, draw submission |
| **assets** | `src/assets/` | Async-ready asset loading, texture cache, registry |
| **game/actors** | `src/game/actors/` | Player, enemy, NPC, boss — runtime gameplay state |
| **game/combat** | `src/game/combat/` | Hit resolution, status effects, ability targeting |
| **game/progression** | `src/game/progression/` | Skill tree, ability progression, SP management |
| **game/ai** | `src/game/ai/` | Enemy AI, squad coordination, encounter direction |
| **game/animation** | `src/game/animation/` | Clip loading, event dispatch, animation component |
| **world** | `src/world/` | World partition, streaming, day/night, weather, grid |
| **audio** | `src/audio/` | Music state machine, SFX routing, voice playback |
| **ui** | `src/ui/` | ImGui-based HUD, menus, debug panels |
| **save** | `src/save/` | Save/load slot management, quick-save |
| **progression** | `src/progression/` | Job system, skill trees (lower-level data forms) |
| **materia** | `src/materia/` | Ability socket and summon collection systems |
| **equipment** | `src/equipment/` | Upgrade tree, transmog, loadout presets |
| **crafting** | `src/crafting/` | Recipe discovery, status-effect crafting |
| **camera** | `src/camera/` | Sensitivity controller, camera state |
| **renderer** | `src/renderer/` | Post-process toggles and render pass helpers |

---

## 2. Dependency Direction Rules

```
app  ──→  game  ──→  rendering
          │           │
          │           ↓
          │         assets
          │
          ↓
        world ──→ rendering
                      │
                      ↓
                    assets
```

**Hard rules:**
- `rendering` must NOT include from `game/` or `app/`.
- `game/` must NOT include from `ui/` or `app/`.
- `world/` must NOT include from `game/actors/` or `ui/`.
- `ui/` may include from `game/`, `rendering/` (read-only queries only), and `world/`.
- `app/` is the only layer allowed to own pointers to all subsystems simultaneously.

If a system needs data from a "higher" layer, use a **callback, interface pointer, or event**.
Do not create a reverse include just to get one value.

---

## 3. How to Add a New System Safely

1. **Pick the right module folder** based on the table above. Create `.hpp` + `.cpp` files there.
2. **Define a minimal public interface** — prefer named methods over exposing member variables.
3. **Wire it in `Main.cpp` or the appropriate app helper** — do not let systems find each other through globals.
4. **Forward-declare, do not include** — if another system only needs a pointer to your type, use a forward declaration in its header and include your full header only in the `.cpp`.
5. **Mark TODOs clearly** — use `// TODO(expansion):` for intended extension points so future agents can find them.
6. **Register it in `docs/SYSTEMS.md`** with its status (`✅`, `🔧`, or `❌`).

---

## 4. Compile-Error Root Causes Fixed (Build Stabilisation Pass)

### C2059/C2238 — SkillTree `requires` keyword clash
`SkillNode::requires` was a legal identifier in C++17 but became a reserved keyword in C++20.
Renamed to `prereqs` in `SkillTree.hpp` and all callsites in `SkillTree.cpp`.

### C1083 — ImGui include path mismatch in UI files
Seven UI `.cpp` files used `"../ThirdParty/imgui/imgui.h"` which resolved to a non-existent
path. The actual location is `third_party/imgui/` (lowercase, at repo root). All affected files
updated to use `"../../third_party/imgui/imgui.h"`.

### C4996 — `fopen` deprecated under MSVC `/W4 /WX`
`SaveSystem.cpp` and `CrashDiagnostics.cpp` called `fopen`. Replaced with `fopen_s` which
returns an error code, allowing proper null-check without additional branching.

### C2027 — Incomplete `TerrainManager` type in `D3D11Renderer.cpp`
`D3D11Renderer.hpp` forward-declared `TerrainManager` for the pointer member. The `.cpp`
called methods on that pointer but never included the full definition. Fixed by adding
`#include "Terrain_Renderer.hpp"` to `D3D11Renderer.cpp`.

### C2589 — `std::min` illegal token in `Terrain_Renderer.cpp`
`<windows.h>` (pulled in transitively through `D3D11Renderer.hpp`) defines `min`/`max` as
macros, breaking `std::min(...)`. Fixed by defining `NOMINMAX` in `D3D11Renderer.hpp` before
`<windows.h>` is included, preventing the macros from ever being injected.

### C2039 — `GetSunDirection` not a member of `D3D11Renderer`
`ImGuiLayer.cpp` called `renderer->GetSunDirection(x, y, z)` to read back the sun direction
after calling `SetSunDirection`. The getter was missing. Added
`void GetSunDirection(float& x, float& y, float& z) const` to `D3D11Renderer.hpp/.cpp`,
reading directly from `m_lightData`.

### C4099 — `struct`/`class` mismatch for `EnemyActor`
`SquadCoordinator.hpp` and `AbilityTargeting.hpp` forward-declared `EnemyActor` as `struct`
while the definition in `EnemyActor.hpp` uses `class`. Changed both forward declarations to
`class EnemyActor;` to match the definition.

---

## 5. Open-World Architecture Notes

### World Partitioning
- `WorldPartition` divides the continuous world into cells (`WorldGrid`).
- Each cell owns its terrain patch (`TerrainManager::RebuildTerrainPatch`), population
  (`PopulationDirector`), and region state (`RegionStateStore`).
- Cells are streamed in/out via `StreamingIO` using a budget defined in `StreamingBudget.hpp`.
- The renderer holds a **pointer** to `TerrainManager` (set via `SetTerrainManager`); it never
  owns or creates the manager.

### Update Phase Ordering (intended)
```
1. Input
2. CameraController / PlayerActor
3. AI (EncounterDirector → SquadCoordinator → individual enemy state machines)
4. Combat resolution (CombatSystem, ATB, status effects)
5. World streaming tick (WorldPartition → StreamingIO)
6. Audio state machine (MusicStateMachine, DayNightCycle → SetSunDirection)
7. Render submission (D3D11Renderer::ClearScreen → Draw* → PresentFrame)
8. UI overlay (ImGuiLayer — reads state, never writes back to gameplay systems)
```

### Async Content Loading Seam
`AssetLoader` and `AssetRegistry` are designed as the boundary for async loading. Future
streaming work should go through these rather than loading directly from disk in game systems.

### Gameplay System Isolation
- **Combat** (`src/game/combat/`) must not reach into world streaming or UI.
- **UI** (`src/ui/`) must not modify gameplay state — it reads and presents only.
- **Audio** (`src/audio/`) receives events from gameplay via `AudioRouter`; it does not poll
  gameplay state directly.

---

## 6. Naming and Extension Conventions

- Interfaces use the `I` prefix: `IRenderer`, `IAudioSink` (introduce as needed).
- Extension points are marked `// TODO(expansion): ...` in the source.
- Forward declarations always match the definition keyword (`class` vs `struct`).
- New stub files should include at minimum: a constructor, a destructor, an `Initialize()`, a
  `Shutdown()`, and a prominent `TODO` comment describing expected data flow.
- Use `#pragma once` in all headers.
- Platform includes (`<windows.h>`, `<d3d11.h>`) live only in platform/rendering layers and
  are never pulled into gameplay headers.

---

## 7. Adding New Open-World Features Safely

| Feature category | Where it lives | How it hooks in |
|---|---|---|
| New biome / region | `src/world/`, `Content/World/` | `WorldGrid` biome table + `TerrainManager::RebuildTerrainPatch` |
| New enemy type | `src/game/actors/`, `src/game/ai/` | `EnemyArchetypeProfile` entry + `EncounterDirector` spawn table |
| New ability | `src/game/progression/`, `src/materia/` | `AbilityProgression` entry + `SkillTree` node |
| New UI panel | `src/ui/` | New `.cpp/.hpp`, wired in `ImGuiLayer::Draw*` |
| New save data | `src/app/SaveSystem.cpp` | Add field to `PlayerStats` or new section with bumped `kSaveVersion` |
| New world event | `src/world/WorldEventScheduler.cpp` | Register in the event table |
| New audio cue | `src/audio/AudioRouter.cpp` | Add route entry + cue name constant |

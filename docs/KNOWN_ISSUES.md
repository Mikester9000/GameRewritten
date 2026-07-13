# Known Issues and Fragile Spots

Use this before touching risky areas.  
See also: [CURRENT_STATE.md](./CURRENT_STATE.md), [SAFE_REFACTOR_RULES.md](./SAFE_REFACTOR_RULES.md),
[engine_foundation.md](./engine/engine_foundation.md).

## ✅ RESOLVED — Build-blocking compile errors (stabilisation pass)
The following errors were resolved in the build stabilisation pass. See
`docs/engine/engine_foundation.md` §4 for root cause details.
- C2059/C2238: `SkillTree::requires` keyword clash → renamed to `prereqs`
- C1083: Wrong ImGui include path in 7 UI files → fixed to `../../third_party/imgui/imgui.h`
- C4996: `fopen` deprecated → replaced with `fopen_s` in SaveSystem and CrashDiagnostics
- C2027: `TerrainManager` incomplete type in D3D11Renderer.cpp → included `Terrain_Renderer.hpp`
- C2589: `std::min` macro collision → added `#define NOMINMAX` before `<windows.h>` in `D3D11Renderer.hpp`
- C2039: `GetSunDirection` missing from D3D11Renderer → method added
- C4099: `struct`/`class` mismatch for `EnemyActor` → forward decls corrected to `class`

## 1) Main loop is overloaded
- **Impact:** harder maintenance, more regression risk.
- **Likely files:** `src/app/Main.cpp`, related app helpers.
- **Status:** active technical debt.
- **Avoid unless asked:** no (safe extraction work is welcome).

## 2) Documentation drift in older docs
- **Impact:** wrong assumptions for future agents.
- **Likely files:** roadmap/checklist/older vision docs.
- **Status:** ongoing cleanup needed.
- **Avoid unless asked:** no (doc fixes are useful).

## 3) Audio behavior breadth is still limited
- **Impact:** incomplete music/state feedback depth.
- **Likely files:** `src/audio/*`, `ThirdParty` wrappers.
- **Status:** partial.
- **Avoid unless asked:** yes for major redesign.

## 4) World progression depth is early
- **Impact:** open-world structure exists but many gameplay layers are not yet built.
- **Likely files:** `src/world/*`, `src/game/*`, `Content/World/*`.
- **Status:** expected.
- **Avoid unless asked:** no for incremental additions.

## 5) Performance regression risk from UI/debug growth
- **Impact:** low-spec stability can degrade quietly.
- **Likely files:** `src/ui/*`, `src/rendering/*`.
- **Status:** monitor.
- **Avoid unless asked:** no, but keep features guarded/toggled.

## 6) FULL_TASK_SEQUENCE checkbox drift (Phase 2 legacy rows)
- **Impact:** task status can be misread, causing duplicate or skipped work.
- **Likely files:** `docs/FULL_TASK_SEQUENCE.md`.
- **Status:** recently identified; keep status in sync with `docs/SYSTEMS.md` and work logs.
- **Avoid unless asked:** no (safe doc correction).

## 7) ORDER_PLAN missing cel shader/toon tasks
- **Impact:** visual roadmap omits a critical style dependency and can mis-prioritize implementation.
- **Likely files:** `docs/docs_ORDER_PLAN.md`, phase ordering docs.
- **Status:** active doc gap.
- **Avoid unless asked:** no (planning accuracy fix).

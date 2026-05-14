# Current State (Source-of-Truth Snapshot)

Use this first when starting work.  
See also: [SYSTEMS.md](./SYSTEMS.md), [Architecture.md](./Architecture.md), [Workflow.md](./Workflow.md), [AGENT_JOB.md](./AGENT_JOB.md).

## Current state (implemented now)
- Win32 app + D3D11 renderer boots and runs.
- Main loop in `src/app/Main.cpp` supports:
  - movement/camera
  - world cell detection + refresh
  - combat update
  - runtime actor submission
  - world + UI draw
- Runtime gameplay loop is playable:
  - move/jump/dodge
  - lock-on (`Q`)
  - basic combo
  - Surge Strike / Limit Break
  - enemy chase/attack/hit/death
  - player damage + respawn reset
- UI/HUD exists:
  - pause/debug overlays
  - gameplay HUD
  - tactical pause (`Tab` hold)
  - minimap
  - dialog box
  - floating damage numbers

## Playable/testable loop (today)
1. Launch game.
2. Move in world, cross cells, observe world refresh.
3. Enter enemy range, lock-on, attack/dodge.
4. Watch HUD feedback (HP/MP/Surge/Limit, target info, combo).
5. Take damage, test defeat/respawn.
6. Use `F5` reload path for assets/world data.

## Implemented systems (do not rebuild)
- `RuntimeScene`, `PlayerActor`, `EnemyActor`, `CombatSystem`, `Targeting`
- `WorldGrid`, `AssetRegistry`, `PrefabLibrary`, `PrimitiveRenderer`
- `ImGuiLayer`, `WorldEditor`, `GameHUD`, `TacticalPauseMenu`, `DamageNumbers`, `Minimap`
- `CameraController`, collision world (AABB), frame/input helpers in `src/app`

## Partial systems (expand, do not replace)
- Audio wrapper path (basic one-shot flow; broader audio behavior still limited)
- Third-party wrappers initialized, but gameplay integration is still shallow in places
- Open-world structure exists, but content density and multi-system world logic are early

## Not started / clearly future
- Full quest/event framework
- robust save/load
- advanced AI frameworks
- large progression/equipment framework
- high-end rendering pipeline work
- multiplayer/networking

## Temporary or fragile areas
- `Main.cpp` still owns too much detail.
- Some docs have drift against latest implementation.
- Multiple systems are feature-complete enough for playtesting but still tuned by hardcoded values.

## Current technical constraints
- D3D11 target first.
- GT 610 low-spec safety is a hard constraint.
- Keep shader/material complexity low.
- Keep code narrative/readable over clever.

## Safe next work areas
- Small UX/readability improvements in HUD/combat feedback.
- Main-loop extraction into helpers without behavior changes.
- Data/content expansion via prefabs/world cells.
- Quality guardrails and debug metrics.

## What should not be rebuilt
- Existing combat baseline loop.
- Existing world/editor registry flow.
- Existing D3D11 core setup.
- Existing runtime scene ownership pattern.

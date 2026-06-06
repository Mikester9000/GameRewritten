# Agent Job (Start Here)

This is the routing document for coding agents.

## Required reading order before coding
1. [CURRENT_STATE.md](./CURRENT_STATE.md)
2. [SYSTEMS.md](./SYSTEMS.md)
3. [Architecture.md](./Architecture.md)
4. [SYSTEM_OWNERSHIP.md](./SYSTEM_OWNERSHIP.md)
5. [DECISION_DEFAULTS.md](./DECISION_DEFAULTS.md)
6. [QUALITY_BAR.md](./QUALITY_BAR.md)

Then read area-specific docs below.

## Task-to-doc mapping
| Task type | Read these first |
|---|---|
| Gameplay/combat | `vision/GAME_DESIGN_BIBLE.md`, `PERFORMANCE_GUARDRAILS.md` |
| Rendering/visual | `vision/GAME_DESIGN_BIBLE.md`, `PERFORMANCE_GUARDRAILS.md`, `GRAPHICS_VISION.md` |
| World/content | `vision/GAME_DESIGN_BIBLE.md`, `CONTENT_PIPELINE_GUIDE.md`, `WORLD_EDITOR.md` |
| UI/HUD/menu | `vision/GAME_DESIGN_BIBLE.md`, `UI_VISION.md` |
| Cleanup/refactor | `SAFE_REFACTOR_RULES.md`, `MAIN_CPP_PROTECTION.md`, `CODING_STYLE.md` |

## Required docs for gameplay work
- `vision/GAME_DESIGN_BIBLE.md`
- `PROGRESSION_PHILOSOPHY.md` (if progression touched)

## Required docs for rendering work
- `PERFORMANCE_GUARDRAILS.md`
- `vision/GAME_DESIGN_BIBLE.md`
- `GRAPHICS_VISION.md`

## Required docs for world/content work
- `vision/GAME_DESIGN_BIBLE.md`
- `CONTENT_PIPELINE_GUIDE.md`
- `BLOCKOUT_FIRST_POLICY.md`

## Required docs for UI work
- `vision/GAME_DESIGN_BIBLE.md`
- `UI_PRESENTATION_STYLE.md`

## Required docs for cleanup/refactor work
- `SAFE_REFACTOR_RULES.md`
- `CODING_STYLE.md`
- `MAIN_CPP_PROTECTION.md`

## Required docs before touching `Main.cpp`
- `MAIN_CPP_PROTECTION.md`
- `SYSTEM_OWNERSHIP.md`
- `SAFE_REFACTOR_RULES.md`

## Required docs before adding a new file
- `SYSTEM_OWNERSHIP.md`
- `DECISION_DEFAULTS.md`
- `CODING_STYLE.md`

## Do-not-skip checklist
- [ ] Confirm system is not already ✅ in `SYSTEMS.md`.
- [ ] Confirm correct folder ownership.
- [ ] Confirm task scope is small and clear.
- [ ] Confirm performance constraints are respected.
- [ ] Confirm docs need updates if behavior/rules changed.

## Stop-and-recheck checklist
Stop and re-check if:
- You are about to add non-orchestration logic into `Main.cpp`.
- You are about to add a new framework/abstraction layer.
- You are unsure where code belongs.
- You are adding expensive render/UI behavior without guardrails.

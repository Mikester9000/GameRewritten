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
| Gameplay/combat | `COMBAT_PILLARS.md`, `PLAYER_FEEL.md`, `ENEMY_DESIGN.md`, `DESIGN_PHILOSOPHY.md` |
| Rendering/visual | `PERFORMANCE_GUARDRAILS.md`, `ARTISTIC_STYLE.md`, `LIGHTING_AND_COLOR.md`, `GRAPHICS_VISION.md` |
| World/content | `EXPLORATION_DESIGN.md`, `WORLD_STRUCTURE.md`, `CONTENT_PIPELINE_GUIDE.md`, `WORLD_EDITOR.md` |
| UI/HUD/menu | `UI_PRESENTATION_STYLE.md`, `UI_VISION.md`, `FINAL_FANTASY_FEEL.md` |
| Cleanup/refactor | `SAFE_REFACTOR_RULES.md`, `MAIN_CPP_PROTECTION.md`, `CODING_STYLE.md` |

## Required docs for gameplay work
- `COMBAT_PILLARS.md`
- `PLAYER_FEEL.md`
- `ENEMY_DESIGN.md`
- `PROGRESSION_PHILOSOPHY.md` (if progression touched)

## Required docs for rendering work
- `PERFORMANCE_GUARDRAILS.md`
- `ARTISTIC_STYLE.md`
- `LIGHTING_AND_COLOR.md`
- `GRAPHICS_VISION.md`

## Required docs for world/content work
- `WORLD_STRUCTURE.md`
- `EXPLORATION_DESIGN.md`
- `CONTENT_PIPELINE_GUIDE.md`
- `BLOCKOUT_FIRST_POLICY.md`

## Required docs for UI work
- `UI_PRESENTATION_STYLE.md`
- `FINAL_FANTASY_FEEL.md`
- `PLAYER_FEEL.md` (combat HUD responsiveness)

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

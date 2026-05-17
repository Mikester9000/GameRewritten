# Agent Docs Index

Start here: [AGENT_JOB.md](./AGENT_JOB.md)

## Source-of-truth docs (highest priority)
- [CURRENT_STATE.md](./CURRENT_STATE.md) — what exists now.
- [SYSTEM_OWNERSHIP.md](./SYSTEM_OWNERSHIP.md) — where code belongs.
- [DECISION_DEFAULTS.md](./DECISION_DEFAULTS.md) — default choices.
- [MAIN_CPP_PROTECTION.md](./MAIN_CPP_PROTECTION.md) — Main.cpp guardrails.
- [QUALITY_BAR.md](./QUALITY_BAR.md) — minimum acceptable quality.

## Foundation / agent guidance
- `AUTOPILOT_WORKFLOW.md` — deterministic run loop for small local LLM execution.
- `WORST_LLM_MODE.md` — strictest zero-decision mode for weakest local LLMs.
- `../tools/llm/worst_llm_guard.py` — guarded start/complete commands that enforce scope + required doc updates.
- `FULL_TASK_SEQUENCE.md` — complete ordered task list from current state to completion.
- `NEXT_TASK.md` — single active task card (only coding target per run).
- `AGENT_WORK_LOG.md` — append-only implementation history.
- `AGENT_TASK_TEMPLATE.md` — reusable task format.
- `KNOWN_ISSUES.md` — fragile spots and current risks.
- `SUGGESTED_FEATURES.md` — practical future work list.
- `CODING_STYLE.md` — narrative code style.

## Vision / final destination
- `FINAL_GOAL.md`
- `FINAL_FANTASY_FEEL.md`
- `DESIGN_PHILOSOPHY.md`

## Visual / presentation direction
- `ARTISTIC_STYLE.md`
- `CHARACTER_VISUAL_STYLE.md`
- `ENVIRONMENT_VISUAL_STYLE.md`
- `LIGHTING_AND_COLOR.md`
- `UI_PRESENTATION_STYLE.md`
- `ANIMATION_FEEL.md`

## Gameplay / world direction
- `COMBAT_PILLARS.md`
- `PLAYER_FEEL.md`
- `ENEMY_DESIGN.md`
- `EXPLORATION_DESIGN.md`
- `WORLD_STRUCTURE.md`
- `QUEST_AND_EVENT_PHILOSOPHY.md`
- `PROGRESSION_PHILOSOPHY.md`
- `PARTY_SYSTEM_DIRECTION.md`

## Story / tone direction
- `STORY_TONE.md`
- `WORLD_LORE_DIRECTION.md`
- `REGION_IDENTITY_GUIDE.md`

## Implementation / production rules
- `FEATURE_ROADMAP_STRUCTURE.md`
- `CONTENT_PIPELINE_GUIDE.md`
- `BLOCKOUT_FIRST_POLICY.md`
- `SAFE_REFACTOR_RULES.md`
- `PERFORMANCE_GUARDRAILS.md`

## Scope control docs
- `DO_NOT_BUILD_YET.md`
- `QUALITY_BAR.md`

> Note: Keep this index short; details live in the linked docs.

# Agent Task Template

Use this template when creating tasks for future agents.

## Task Brief
- **Goal:**
- **Why this matters:**
- **Current state reference:** `docs/CURRENT_STATE.md`
- **Architecture reference:** `docs/Architecture.md`
- **System status reference:** `docs/SYSTEMS.md`

## Scope
- **Files to touch (exact paths):**
- **Exact insertion points (function names or line anchors):**
- **Exact text to insert/replace (if known):**
- **Files not to touch:**
- **Allowed side-effects:**
- **Out of scope (explicit):**

## Constraints
- Keep `Main.cpp` orchestration-only (see `docs/MAIN_CPP_PROTECTION.md`).
- Follow narrative coding style (see `docs/CODING_STYLE.md`).
- Respect GT 610 guardrails (see `docs/PERFORMANCE_GUARDRAILS.md`).
- No new dependencies unless explicitly requested.

## Acceptance criteria
- [ ] Behavior goal is met.
- [ ] Existing behavior remains intact.
- [ ] Correct code placement by ownership rules.
- [ ] Docs updated if system behavior/rules changed.
- [ ] Build/test/smoke checks completed.

## Verification steps
1. Run `python tools/llm/worst_llm_guard.py doctor`.
2. Build the project with existing toolchain.
3. Run in-game smoke pass for changed path.
4. Validate no regressions in adjacent systems.
5. Confirm logs/UI show expected results.
6. Run `python tools/llm/worst_llm_guard.py complete`.

## Copy-paste example
- **Goal:** Add enemy telegraph-lite visual before enemy attack.
- **Why:** Improve combat readability without heavy systems.
- **Files to touch:**  
  `src/game/actors/EnemyActor.hpp`  
  `src/game/actors/EnemyActor.cpp`  
  `src/ui/GameHUD.cpp` (only if UI indicator is needed)
- **Files not to touch:**  
  `src/rendering/d3d11/*`, `src/world/*`, `src/assets/*`
- **Out of scope:** new AI framework, animation graph, new shader pipeline.
- **Acceptance:** Telegraph appears before attack; no FPS drop; no lock-on regression.

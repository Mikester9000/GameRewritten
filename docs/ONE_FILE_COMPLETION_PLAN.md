# ONE_FILE_COMPLETION_PLAN.md

This plan is now normalized for small-model execution.
Every task below is **one file only** and includes required fields **0-8**.

## Global Rules (apply to every task)
- Run exactly one task at a time.
- Do not edit any file other than the task's target file.
- Read only the listed `READ_FILE` and `READ_LINES` range.
- Output copy-ready final code that a human can paste directly.
- Keep changes small, deterministic, and reversible.

## Required Output Shape (for every task)
```text
FILE: <absolute path>
READ_FILE: <absolute path>
READ_LINES: <start-end>
ACTION: <replace-range|insert-after-anchor>
ANCHOR: <exact anchor text>
PASTE_BLOCK_START
```<language>
<exact final text to paste>
```
PASTE_BLOCK_END
```

---

## Task 001
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add lock-on input hint text.
2. **What it does + logic:** Shows a simple on-screen control hint so players know lock-on and tactical controls without opening docs.
3. **Narrative code logic:** Write one clear helper that builds the hint string, then call it in the UI draw path; keep flow `setup -> guard -> draw`.
4. **FF7 Remake + PS2 target:** Keep UX readable like FF7R tutorials, but visually lightweight and text-only like PS2-era overlays.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where to edit:** `READ_LINES: 1-320`; insert after anchor `void GameHUD::Draw(` where control help text is assembled.
7. **Additional info:** Keep it non-intrusive; no new textures, no animation.
8. **Copy-ready finish rule:** Return full final block(s) for direct paste into this file only.

## Task 002
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add low-cost camera sensitivity constants.
2. **What it does + logic:** Introduces explicit low/medium/high mouse look sensitivity constants and uses low preset by default.
3. **Narrative code logic:** Define constants once, apply them in one place, avoid magic numbers, and keep update code linear.
4. **FF7 Remake + PS2 target:** Camera feel should be stable and cinematic, but simplified for low-end hardware.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where to edit:** `READ_LINES: 1-320`; replace numeric sensitivity literals in camera update logic.
7. **Additional info:** Do not change projection near/far planes in this task.
8. **Copy-ready finish rule:** Return final code block that includes constant definitions plus updated usage.

## Task 003
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add pause-safe damage-number timing comment + guard.
2. **What it does + logic:** Ensures damage numbers do not age while paused and clarifies why in code.
3. **Narrative code logic:** Add one guard clause early, then run existing logic unchanged.
4. **FF7 Remake + PS2 target:** Keep combat readability while preserving deterministic pause behavior.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/DamageNumbers.cpp`
6. **Where to edit:** `READ_LINES: 1-260`; insert guard in update function before timer decrement.
7. **Additional info:** Do not add new systems; small local edit only.
8. **Copy-ready finish rule:** Return a paste-ready replacement of the edited function only.

## Task 004
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add quality-preset struct for GT610 defaults.
2. **What it does + logic:** Creates explicit low/medium/high values for draw-call and post-process caps.
3. **Narrative code logic:** Define one struct, one default instance, and one accessor; keep names explicit.
4. **FF7 Remake + PS2 target:** Targets FF7-inspired scene composition with PS2-grade fallback budgets.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
6. **Where to edit:** `READ_LINES: 1-520`; insert near top-level app configuration area.
7. **Additional info:** This task only introduces config values; no render-path rewiring yet.
8. **Copy-ready finish rule:** Return exact block to paste and exact anchor placement.

## Task 005
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add lightweight footstep one-shot call hook.
2. **What it does + logic:** Plays a footstep sound when movement threshold is met and cooldown elapsed.
3. **Narrative code logic:** Use clear steps: check move state, check cooldown, trigger audio, reset timer.
4. **FF7 Remake + PS2 target:** Gives action-game feedback while using compressed low-cost one-shots.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
6. **Where to edit:** `READ_LINES: 1-340`; edit movement update section where velocity is known.
7. **Additional info:** Use existing `tp::Audio::PlayOneShot` only; no new API.
8. **Copy-ready finish rule:** Return full edited function block for manual paste.

## Task 006
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add enemy hit-react cooldown variable.
2. **What it does + logic:** Prevents repeated hit-react retrigger every frame while still allowing regular attacks.
3. **Narrative code logic:** Declare member, decrement timer, guard retrigger, then execute hit-react.
4. **FF7 Remake + PS2 target:** Keeps responsive stagger feel with low-complexity state rules.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
6. **Where to edit:** `READ_LINES: 1-180`; add member fields in combat-state member section.
7. **Additional info:** Header-only in this step; cpp wiring is separate task.
8. **Copy-ready finish rule:** Return final member block only with placement anchor.

## Task 007
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Wire enemy hit-react cooldown update.
2. **What it does + logic:** Updates and consumes the new cooldown timer inside runtime update loop.
3. **Narrative code logic:** Update timer first, evaluate trigger second, then run existing visual/gameplay effects.
4. **FF7 Remake + PS2 target:** Supports clear combat rhythm without expensive animation graph complexity.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where to edit:** `READ_LINES: 1-320`; modify combat update/hit handling function.
7. **Additional info:** Keep behavior deterministic and frame-rate independent using `dt`.
8. **Copy-ready finish rule:** Return full replacement of the modified function.

## Task 008
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add combo HUD decay color ramp.
2. **What it does + logic:** Changes combo text color as combo window nears expiration.
3. **Narrative code logic:** Compute normalized timer ratio, choose color in ordered if-blocks, render once.
4. **FF7 Remake + PS2 target:** Mimics urgency cues from modern action HUDs while using cheap 2D color changes.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where to edit:** `READ_LINES: 1-320`; in combo indicator draw function.
7. **Additional info:** No gradients, shaders, or extra draw passes.
8. **Copy-ready finish rule:** Return edited combo draw function for direct paste.

## Task 009
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add lock-on camera distance clamp.
2. **What it does + logic:** Prevents camera from zooming too close/far during lock-on tracking.
3. **Narrative code logic:** Clamp calculated target distance with named min/max constants before assignment.
4. **FF7 Remake + PS2 target:** Keeps readable combat framing with low-cost camera math.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where to edit:** `READ_LINES: 1-320`; lock-on camera positioning function.
7. **Additional info:** Keep existing view/projection path unchanged.
8. **Copy-ready finish rule:** Return direct-paste replacement block.

## Task 010
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add world-streaming debug counters.
2. **What it does + logic:** Displays current active cells and cell-load operations per frame for tuning.
3. **Narrative code logic:** Collect counters in update step, expose const getters, keep side effects isolated.
4. **FF7 Remake + PS2 target:** Supports controlled open-area feel by tracking low-spec streaming budgets.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
6. **Where to edit:** `READ_LINES: 1-360`; update path where cells are activated/deactivated.
7. **Additional info:** Logging/counters only; no streaming policy change.
8. **Copy-ready finish rule:** Return updated code blocks for this file only.

## Task 011
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add lightweight ambient volume preset constants.
2. **What it does + logic:** Introduces explicit ambient/music/effect target levels for low preset balancing.
3. **Narrative code logic:** Store values in named constants and use them where audio starts.
4. **FF7 Remake + PS2 target:** Keeps emotional scene mix with compressed, low-memory audio strategy.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
6. **Where to edit:** `READ_LINES: 1-520`; startup/audio init area.
7. **Additional info:** No runtime slider UI in this task.
8. **Copy-ready finish rule:** Return exact replacement/insert block with anchor text.

## Task 012
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add tactical pause control row in pause menu.
2. **What it does + logic:** Shows current tactical pause keybind and short behavior summary in pause UI.
3. **Narrative code logic:** Build one row helper and call it from the existing pause menu draw flow.
4. **FF7 Remake + PS2 target:** Reinforces hybrid action+command identity using simple text UI.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp`
6. **Where to edit:** `READ_LINES: 1-340`; pause menu drawing function.
7. **Additional info:** Keep existing menu style; no layout rewrite.
8. **Copy-ready finish rule:** Return one paste-ready code block for this file.

## Task 013
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add player movement deadzone constant.
2. **What it does + logic:** Prevents tiny movement noise from triggering run/footstep behavior.
3. **Narrative code logic:** Define named threshold constant and gate movement state updates through it.
4. **FF7 Remake + PS2 target:** Keeps movement feeling deliberate and stable on low-spec frame variance.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
6. **Where to edit:** `READ_LINES: 1-340`; movement input interpretation block.
7. **Additional info:** Maintain current control mapping.
8. **Copy-ready finish rule:** Return edited movement section for direct paste.

## Task 014
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add lock-on target validity helper extraction.
2. **What it does + logic:** Centralizes target validity checks used before lock-on keep/cycle operations.
3. **Narrative code logic:** Create one small helper with guard checks, then reuse it in existing branches.
4. **FF7 Remake + PS2 target:** Keeps lock-on behavior predictable with minimal CPU overhead.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp`
6. **Where to edit:** `READ_LINES: 1-220`; inside targeting utilities section.
7. **Additional info:** Keep public API signatures unchanged.
8. **Copy-ready finish rule:** Return one direct-paste block with helper + callsite updates.

## Task 015
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add concise combat HUD state labels.
2. **What it does + logic:** Displays `LOCKED`, `FREE`, `TACTICAL` labels to improve player state awareness.
3. **Narrative code logic:** Compute state enum/string once, draw one compact label block.
4. **FF7 Remake + PS2 target:** Uses modern combat readability goals with low-cost static text rendering.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where to edit:** `READ_LINES: 1-320`; main HUD draw path after health/combo blocks.
7. **Additional info:** Avoid flashing or per-pixel effects.
8. **Copy-ready finish rule:** Return exact final code for the edited HUD region.

## Task 016
0. **Single-file edit:** yes, one file only.
1. **Task Name:** Add docs reminder block for manual paste workflow.
2. **What it does + logic:** Keeps contributors aligned that local LLM output must be pasted manually and verified.
3. **Narrative code logic:** Add one short, explicit checklist block in docs.
4. **FF7 Remake + PS2 target:** Ensures workflow quality so low-spec-compatible features are implemented reliably.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/AUTOPILOT_WORKFLOW.md`
6. **Where to edit:** `READ_LINES: 1-260`; add section near execution loop instructions.
7. **Additional info:** Documentation-only; no code behavior change.
8. **Copy-ready finish rule:** Return final markdown block for direct paste.

---

## Completion Notes
- The tasks above are intentionally small so a small local model can execute safely.
- If a task cannot be done in one file, split it into additional single-file tasks before implementation.
- Do not merge task outputs together; complete one task, paste, save, then move to next.

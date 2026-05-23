# ONE_FILE_COMPLETION_PLAN(CON1).md

Continuation/addendum for missing headers and missing-item task coverage in strict one-file task format.
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

## Verification Summary
- Base file reviewed: `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN.md`
- Source of truth checked: `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md`
- Base plan task count: **201** total — **108** primary `.cpp` feature tasks (Task 001-108) + **93** `.hpp` companion tasks (Task 001H-107H, one per `.cpp` task that needed a header pair).
- `.hpp` companion coverage: all `.cpp` tasks in the base plan have a matching `###H` companion task already in the base plan. No `.hpp` companions are missing.
- Addendum purpose: this file (CON1) extends the base plan with tasks that fall outside the 001-108 + 001H-107H scope: release readiness gates, plan-document maintenance, build wiring, content pipeline, PS2-era graphics, water/swimming, all vehicle types, roads/traffic AI, open-world systems (climbing, gliding, fishing, mounts, photo mode, interior portals), NPC day/night schedules, final integration sweeps, and world-building authoring guide, plus modern open-world layers (faction reputation, crime/wanted response, dynamic world events, camps, companions/banter runtime, fast travel, collectibles, bounty hunts, NG+, endgame trials, and save-backup resilience).
- Tasks in this addendum: **214** total — **8** plan-document maintenance tasks (H01-H08) + **12** release gate tasks (Task 109-120) + **126** open-world/graphics/feature tasks (Task 121-246, covering build wiring, content pipeline, PS2-era graphics, water/swimming, all vehicle classes, roads/traffic AI, open-world systems, FF nostalgia features, audio zones, accessibility, WorldEditor tools, content authoring templates, final integration sweeps, world-building documentation, and missing modern layers such as faction reputation, crime/wanted response, dynamic world events, camps, companions/banter runtime, fast travel, collectibles, bounty hunts, NG+, endgame trials, and save-backup resilience) + **68** `.hpp` companion tasks (added where declarations are required by implementation tasks).

## Execution Rule (No Thinking Required)
1. Read this addendum and the base one-file plan.
2. Execute one task per run.
3. Use absolute paths only.
4. Output copy-ready payload only.
5. Update required docs for each completed task.
6. Stop after one task.

## Message Visibility Fallback (If outputs are not appearing)
1. Print `STATUS: START Task ###` first.
2. Print one file payload at a time.
3. Split long output and label:
   - `STATUS: CHUNK 1/N`
   - `STATUS: CHUNK 2/N`
4. End with `STATUS: DONE Task ###`.

## Mandatory micro-steps per task
1. Read listed file once using listed line range.
2. Make only minimum edits.
3. Keep edits inside the listed file.
4. Do not rename/move files.
5. Do not add dependencies.
6. Keep GT610-safe defaults.
7. Return copy-ready output only.

## Global Constraints
- One task per run.
- One file per task prompt.
- Absolute paths only.
- No dependency additions.
- Keep D3D11 + GT610-safe defaults.

## Full-System Policy (No Placeholder-Only Completion)
- Do not mark scaffold-only output as complete.
- Each task must produce player-visible, runtime-usable or release-usable output.
- Include fallback-safe behavior where applicable.

## Task Ownership Matrix (SLM vs Copilot)
- Use task routing from `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md`.
- If uncertainty or multi-file coupling appears, escalate to Copilot-required flow.

## Completion Target
- All base tasks plus continuation tasks in this file are complete.
- Release/readiness gates are documented and verifiable.
- No remaining unchecked release-critical plan items.

## Required Output Contract
```text
FILE: <absolute path>
READ_FILE: <absolute path>
READ_LINES: <start-end>
LINE_BUDGET: <max lines modified/added in this file>
ACTION: <replace-range|insert-after-anchor>
ANCHOR: <exact anchor text>
EXECUTOR: <SLM|COPILOT>
STATUS: <START|CHUNK X/N|DONE>
PASTE_BLOCK_START
```<language>
<exact final text to paste>
```
PASTE_BLOCK_END
```

---

## Plan Document Maintenance Tasks
These tasks update the CONTROL SECTIONS of this CON1 addendum file itself (the workflow rules at the top of this document).
They are **document maintenance tasks**, not C++ code tasks. Each edits one section of this file at a time.
Run these only when the corresponding control section needs updating.

> **Note:** For C++ code tasks, see the base plan (Tasks 001-108 for `.cpp` files, Tasks 001H-107H for `.hpp` companion headers).
> All `.hpp` header companion tasks already exist in the base plan — none are missing from CON1.

## Task H01
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Update Execution Rule section in this continuation file
2. **What the task does + logic:** Inserts/updates the `## Execution Rule (No Thinking Required)` section in this continuation file.
3. **Narrative logic explanation:** Locate section at lines 13-19, guard duplicate step entries, correct or expand canonical execution steps, then verify order.
4. **Game design target (FF7 Remake + PS2):** Keep deterministic low-reasoning workflow that supports consistent GT610-safe development output.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 13-19; replace/update only the Execution Rule block.
7. **Additional information:** LINE_BUDGET target <=20 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task H02
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Update Message Visibility Fallback section in this continuation file
2. **What the task does + logic:** Inserts/updates the `## Message Visibility Fallback (If outputs are not appearing)` section in this continuation file.
3. **Narrative logic explanation:** Locate section at lines 21-27, guard duplicate markers, correct START/CHUNK/DONE visibility steps, then verify order.
4. **Game design target (FF7 Remake + PS2):** Keep deterministic execution outputs reliable for weak local LLM workflows.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 21-27; replace/update only the Message Visibility Fallback block.
7. **Additional information:** LINE_BUDGET target <=20 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task H03
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Update Mandatory micro-steps section in this continuation file
2. **What the task does + logic:** Inserts/updates the `## Mandatory micro-steps per task` section in this continuation file.
3. **Narrative logic explanation:** Locate section at lines 29-36, guard duplicate step list, correct micro-step sequence, then verify order.
4. **Game design target (FF7 Remake + PS2):** Preserve predictable one-step execution and low-risk edits for constrained hardware targets.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 29-36; replace/update only the Mandatory micro-steps block.
7. **Additional information:** LINE_BUDGET target <=20 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task H04
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Update Global Constraints section in this continuation file
2. **What the task does + logic:** Inserts/updates the `## Global Constraints` section in this continuation file.
3. **Narrative logic explanation:** Locate section at lines 38-43, guard duplicates, correct constraints list, then verify order and wording alignment.
4. **Game design target (FF7 Remake + PS2):** Keep safe scope control and GT610 budget discipline during automated task execution.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 38-43; replace/update only the Global Constraints block.
7. **Additional information:** LINE_BUDGET target <=20 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task H05
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Update Full-System Policy section in this continuation file
2. **What the task does + logic:** Inserts/updates the `## Full-System Policy (No Placeholder-Only Completion)` section in this continuation file.
3. **Narrative logic explanation:** Locate section at lines 45-48, guard duplicate policy blocks, correct completion policy requirements, then verify placement.
4. **Game design target (FF7 Remake + PS2):** Ensure deliverables remain playable and production-usable rather than scaffold-only.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 45-48; replace/update only the Full-System Policy block.
7. **Additional information:** LINE_BUDGET target <=20 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task H06
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Update Task Ownership Matrix section in this continuation file
2. **What the task does + logic:** Inserts/updates the `## Task Ownership Matrix (SLM vs Copilot)` section in this continuation file.
3. **Narrative logic explanation:** Locate section at lines 50-52, guard duplicate routing guidance, correct owner matrix, then verify alignment with source-of-truth.
4. **Game design target (FF7 Remake + PS2):** Keep deterministic executor routing for minimal-reasoning local LLM workflow.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 50-52; replace/update only the Task Ownership Matrix block.
7. **Additional information:** LINE_BUDGET target <=20 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task H07
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Update Completion Target section in this continuation file
2. **What the task does + logic:** Inserts/updates the `## Completion Target` section in this continuation file.
3. **Narrative logic explanation:** Locate section at lines 54-57, guard duplicate target criteria, correct completion gates, then verify list ordering.
4. **Game design target (FF7 Remake + PS2):** Maintain clear ship-target gates with low-spec-safe execution expectations.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 54-57; replace/update only the Completion Target block.
7. **Additional information:** LINE_BUDGET target <=20 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task H08
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Control-header verification pass for this continuation file
2. **What the task does + logic:** Performs one-file verification/update pass to ensure all required control headers exist and are ordered correctly in this continuation file.
3. **Narrative logic explanation:** Read lines 1-75, guard missing/misordered blocks, apply final reorder if needed, then output final normalized header block.
4. **Game design target (FF7 Remake + PS2):** Ensure deterministic plan execution remains stable for low-capacity local LLMs.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
6. **Where in file to edit:** READ_LINES: 1-75; normalize only the control-header block before first `## Plan Document Maintenance Tasks`.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

---

## Release Gate Tasks (Task 109-120)
These tasks add release-readiness validation content to documentation files (ship checklists, QA gates, legal review, animation compatibility gates, etc.).
Each targets a single `.md` documentation file. They follow the same one-file-at-a-time rule as all code tasks.

## Task 109
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Stability soak test gate
2. **What the task does + logic:** Adds/updates documented 30-minute soak validation pass requirements and pass/fail output contract for release gating.
3. **Narrative logic explanation:** Define soak entry conditions, guard failure thresholds, run soak checklist, then report pass/fail evidence.
4. **Game design target (FF7 Remake + PS2):** Preserve readable action flow and stable frame pacing with low-cost visuals suitable for GT610.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under release validation section.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 110
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** GT610 performance certification gate
2. **What the task does + logic:** Adds/updates explicit GT610 frame-time and budget acceptance gates with measurable pass/fail criteria.
3. **Narrative logic explanation:** Define target budgets, guard unsafe regressions, run benchmark checklist, then record results.
4. **Game design target (FF7 Remake + PS2):** Keep visual readability while honoring low-spec GPU limits and stable performance.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/PERFORMANCE_GUARDRAILS.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under runtime validation/budgets.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 111
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Save/load recovery and migration release gate
2. **What the task does + logic:** Adds/updates release checklist requirements for save compatibility, rollback safety, and migration verification.
3. **Narrative logic explanation:** Define valid save scenarios, guard migration failures, run load/migrate checks, then log evidence.
4. **Game design target (FF7 Remake + PS2):** Maintain seamless progression continuity with low-overhead runtime safety.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert in persistence/reliability checklist.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 112
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Settings persistence verification gate
2. **What the task does + logic:** Adds/updates required validation matrix for graphics/audio/input/accessibility settings persistence and application on startup.
3. **Narrative logic explanation:** Define settings matrix, guard invalid combinations, run persist/apply checks, then report failures.
4. **Game design target (FF7 Remake + PS2):** Keep controls and readability consistent while supporting low-spec quality defaults.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under settings/options checklist.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 113
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Content and animation compatibility vertical-slice gate
2. **What the task does + logic:** Adds/updates minimum content acceptance criteria for one complete region loop (combat + NPC interaction + reward) and verifies completed animation clips/states remain compatible with planned animation state/event contracts.
3. **Narrative logic explanation:** Define required loop stages and animation compatibility matrix, guard incomplete progression and missing/mismatched animation transitions/events, validate handoff outcomes, then mark completion.
4. **Game design target (FF7 Remake + PS2):** Deliver readable action-RPG loop with constrained assets, animation continuity, and performant world flow.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/QUALITY_BAR.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under release quality gates and animation readiness checks.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 114
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Open-world seamless traversal certification gate
2. **What the task does + logic:** Adds/updates acceptance checks that verify no hard loading gates during normal multi-continent traversal.
3. **Narrative logic explanation:** Define traversal path, guard streaming failures, execute traversal checks, then capture cert status.
4. **Game design target (FF7 Remake + PS2):** Preserve large-world feel with low-cost streaming behavior suitable for GT610 budgets.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/WORLD_STRUCTURE.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under streaming and travel validation.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 115
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** HUD readability and feedback polish gate
2. **What the task does + logic:** Adds/updates minimum readability/feedback acceptance rules for HUD, combat cues, and failure-safe visual fallback behavior.
3. **Narrative logic explanation:** Define readability thresholds, guard noisy/unclear states, run UI checks, then record pass/fail.
4. **Game design target (FF7 Remake + PS2):** Maintain clear action readability and low-cost UI rendering.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/UI_VISION.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under HUD clarity/feedback requirements.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 116
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Audio readability and mix consistency gate
2. **What the task does + logic:** Adds/updates release checks for cue clarity, mix balance, fallback behavior, and event-audio consistency.
3. **Narrative logic explanation:** Define audio checks, guard clipping/masking cases, run scene validation, then record acceptance.
4. **Game design target (FF7 Remake + PS2):** Keep impactful cues and stable low-cost audio playback on target hardware.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/QUALITY_BAR.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under audio quality criteria.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 117
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Packaging reproducibility certification gate
2. **What the task does + logic:** Adds/updates reproducible packaging and artifact verification criteria for release candidates.
3. **Narrative logic explanation:** Define package inputs, guard missing artifacts, run package verification, then log signed result.
4. **Game design target (FF7 Remake + PS2):** Ensure reliable distribution while preserving low-spec-compatible runtime defaults.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/Workflow.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under build/release workflow.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 118
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Legal attribution lock gate
2. **What the task does + logic:** Adds/updates final legal and third-party attribution lock criteria before commercial release.
3. **Narrative logic explanation:** Define attribution scope, guard missing licenses, run legal checklist, then produce final status.
4. **Game design target (FF7 Remake + PS2):** Preserve safe commercial distribution requirements without runtime overhead.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/THIRD_PARTY.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under release/legal verification section.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 119
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Release-candidate blocker triage gate
2. **What the task does + logic:** Adds/updates blocker severity definitions and must-fix exit criteria for release candidate sign-off.
3. **Narrative logic explanation:** Define blocker classes, guard unresolved critical issues, run triage pass, then record release decision.
4. **Game design target (FF7 Remake + PS2):** Ensure stable, readable final experience with performance-safe risk controls.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/KNOWN_ISSUES.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under release blocker policy.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

## Task 120
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Final ship-signoff manifest gate
2. **What the task does + logic:** Adds/updates final sign-off manifest format tying technical, content, animation compatibility, legal, and performance gates into one release approval record.
3. **Narrative logic explanation:** Define sign-off fields (including animation-compatibility approval), guard missing approvals, assemble final manifest, then publish final ship-ready status.
4. **Game design target (FF7 Remake + PS2):** Deliver commercially acceptable final package with predictable low-spec behavior.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert near end of release checklist as final gate section.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

---

## Open-World + PS2-Graphics + Vehicles + Content Pipeline Tasks (Task 121–223)

These tasks bring the engine to a fully commercial, feature-complete open-world JRPG state with seamless streaming, PS2-era graphics, water/swimming, all vehicle classes, roads/traffic, complete content pipeline for story authoring, and every system a large studio would ship.

### Section A — Build Wiring + Content Pipeline (Tasks 121–132)

## Task 121
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Register all new .cpp files in the Visual Studio project (compile list)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Register all new .cpp files in the Visual Studio project (compile list)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Ensures every new feature system compiles and links into the game executable on GT610.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/GameRewritten.vcxproj`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 122
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Add new source files to the Visual Studio solution explorer filter groups
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Add new source files to the Visual Studio solution explorer filter groups" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keeps the solution explorer organised by subsystem so developers can find and edit files quickly.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/GameRewritten.vcxproj.filters`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 123
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Wire all new systems (quest, dialogue, NPC, audio router, party, traversal, vehicles, water, streaming) into the Main.cpp frame loop
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Wire all new systems (quest, dialogue, NPC, audio router, party, traversal, vehicles, water, streaming) into the Main.cpp frame loop" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Connects every new system to the boot, per-frame update, and shutdown paths so features are reachable at runtime.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=200 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 124
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Localisation table — string key to display-text map loaded from en_us.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Localisation table — string key to display-text map loaded from en_us.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lets all quest/dialogue/UI text be authored in JSON rather than hardcoded C++ strings, enabling the story-writing phase.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/localization/LocalizationTable.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 124H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 124 (Localisation table — string key to display-text map loaded from en_us.json)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 124 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 124, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/localization/LocalizationTable.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 124.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 125
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest loader — reads Content/Quests/*.json and populates QuestSystem at startup
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Quest loader — reads Content/Quests/*.json and populates QuestSystem at startup" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Allows quests to be authored as data files; the LLM/developer only edits JSON to add new quests, not C++.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/QuestLoader.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 125H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 125 (Quest loader — reads Content/Quests/*.json and populates QuestSystem at startup)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 125 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 125, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/QuestLoader.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 125.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 126
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dialogue loader — reads Content/Dialogue/*.json and populates DialogueRuntime at startup
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Dialogue loader — reads Content/Dialogue/*.json and populates DialogueRuntime at startup" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Enables branching NPC conversations to be written as data-file trees, ready for story authoring.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/DialogueLoader.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 126H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 126 (Dialogue loader — reads Content/Dialogue/*.json and populates DialogueRuntime at startup)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 126 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 126, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/DialogueLoader.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 126.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 127
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NPC spawn loader — reads Content/NPCs/cell_X_Y.json and spawns NpcActors into RuntimeScene on cell load
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "NPC spawn loader — reads Content/NPCs/cell_X_Y.json and spawns NpcActors into RuntimeScene on cell load" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Makes NPC placement purely data-driven so world-builders place characters via JSON or the editor, not code.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/NpcSpawnLoader.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 127H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 127 (NPC spawn loader — reads Content/NPCs/cell_X_Y.json and spawns NpcActors into RuntimeScene on cell load)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 127 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 127, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/NpcSpawnLoader.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 127.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 128
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WorldEditor: add NPC placement, quest-zone paint, dialogue-trigger, and landmark panels to the in-game editor
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WorldEditor: add NPC placement, quest-zone paint, dialogue-trigger, and landmark panels to the in-game editor" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Gives the world-building stage a visual tool to place all story-critical objects without hand-editing JSON.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 128H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 128 (WorldEditor: add NPC placement, quest-zone paint, dialogue-trigger, and landmark panels to the in-game editor)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 128 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 128, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 128.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 129
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest authoring template — Content/Quests/quest_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Quest authoring template — Content/Quests/quest_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical JSON schema for quests: id, name, objectives[], flag hooks, reward block.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Quests/quest_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 130
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dialogue tree authoring template — Content/Dialogue/dialogue_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Dialogue tree authoring template — Content/Dialogue/dialogue_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical JSON schema for branching dialogue: node id, speaker, text key, choices[].
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Dialogue/dialogue_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 131
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NPC world placement template — Content/NPCs/npc_placement_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "NPC world placement template — Content/NPCs/npc_placement_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines NPC spawn entry format: archetype, world position, dialogue_id, quest_hook, schedule.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/NPCs/npc_placement_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 132
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** English string table — Content/Localization/en_us.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "English string table — Content/Localization/en_us.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Central text table for all quest/dialogue/UI display strings; edit this file to write story content.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Localization/en_us.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

### Section B — PS2-Era Graphics (Tasks 133–140)

## Task 133
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** PS2-era vertex-colour / baked-lighting vertex shader (ps2_vertcolor_vs.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "PS2-era vertex-colour / baked-lighting vertex shader (ps2_vertcolor_vs.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Replicates the flat per-vertex-lit look of FF7/FF8/FF10 on GT610 with minimal shader cost.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/ps2_vertcolor_vs.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 134
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** PS2-era flat-shaded pixel shader with palette-warm colour tint (ps2_vertcolor_ps.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "PS2-era flat-shaded pixel shader with palette-warm colour tint (ps2_vertcolor_ps.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Produces the warm, slightly posterised tone of PS2-era FF titles within D3D11.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/ps2_vertcolor_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 135
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cel outline back-face extrusion vertex shader (cel_outline_vs.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cel outline back-face extrusion vertex shader (cel_outline_vs.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Adds hand-drawn outline silhouettes to characters and props, reinforcing the handmade FF aesthetic.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/cel_outline_vs.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 136
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cel outline solid-colour pixel shader (cel_outline_ps.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cel outline solid-colour pixel shader (cel_outline_ps.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Outputs the solid dark outline colour for the cel-shading pass on GT610.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/cel_outline_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=40 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 137
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Warm colour-grading post-pass pixel shader (color_grade_ps.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Warm colour-grading post-pass pixel shader (color_grade_ps.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Applies a FF7/FF8 inspired warm colour grade (lifted shadows, golden mids) to the final frame.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/color_grade_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 138
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Single-pass soft bloom pixel shader for GT610 (bloom_ps.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Single-pass soft bloom pixel shader for GT610 (bloom_ps.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Adds the soft magical glow seen in FF10 cutscenes; single-pass to stay within GT610 bandwidth.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/bloom_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 139
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** PS2 render pass controller — manages vertex-colour, cel-outline, and post-process order
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "PS2 render pass controller — manages vertex-colour, cel-outline, and post-process order" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Sequences the vertex-colour draw, cel-outline back-face pass, and post-process chain each frame.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/Ps2RenderPass.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 139H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 139 (PS2 render pass controller — manages vertex-colour, cel-outline, and post-process order)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 139 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 139, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/Ps2RenderPass.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 139.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 140
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Post-process pipeline — binds colour-grade and bloom passes to back-buffer each frame
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Post-process pipeline — binds colour-grade and bloom passes to back-buffer each frame" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Provides a single ordered post-process chain (bloom → colour grade) that runs after scene render, GT610-safe.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/PostProcessPipeline.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 140H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 140 (Post-process pipeline — binds colour-grade and bloom passes to back-buffer each frame)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 140 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 140, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/PostProcessPipeline.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 140.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section C — Water System (Tasks 141–148)

## Task 141
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Water surface animated vertex shader — scrolling sine-wave displacement (water_surface_vs.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Water surface animated vertex shader — scrolling sine-wave displacement (water_surface_vs.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Produces the gentle bobbing water surface seen in FF10-era games at low vertex cost for GT610.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/water_surface_vs.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 142
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Water surface pixel shader — ripple normal map, reflection, and depth fade (water_surface_ps.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Water surface pixel shader — ripple normal map, reflection, and depth fade (water_surface_ps.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Gives open-world water bodies the reflective, slightly transparent look of PS2-era coastal zones.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/water_surface_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 143
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Underwater post-pass pixel shader — blue tint, caustic pattern, edge blur (underwater_ps.hlsl)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Underwater post-pass pixel shader — blue tint, caustic pattern, edge blur (underwater_ps.hlsl)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Applies the immersive underwater visual filter when the camera is below a water volume.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/underwater_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 144
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Water renderer — submits water plane meshes and binds water shaders per visible WaterVolume
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Water renderer — submits water plane meshes and binds water shaders per visible WaterVolume" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Integrates the water surface and underwater shaders into the D3D11 renderer frame loop.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/WaterRenderer.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 144H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 144 (Water renderer — submits water plane meshes and binds water shaders per visible WaterVolume)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 144 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 144, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/WaterRenderer.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 144.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 145
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Water volume — axis-aligned zone that detects player/actors entering and exiting water
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Water volume — axis-aligned zone that detects player/actors entering and exiting water" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Tracks which actors are submerged and drives swim-state transitions and audio filter activation.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WaterVolume.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 145H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 145 (Water volume — axis-aligned zone that detects player/actors entering and exiting water)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 145 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 145, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WaterVolume.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 145.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 146
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Buoyancy component — per-actor buoyancy force applied each physics step when in water
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Buoyancy component — per-actor buoyancy force applied each physics step when in water" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keeps boats, debris, and the player floating correctly on the water surface using Jolt Physics forces.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/physics/BuoyancyComponent.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 146H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 146 (Buoyancy component — per-actor buoyancy force applied each physics step when in water)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 146 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 146, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/physics/BuoyancyComponent.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 146.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 147
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Swim controller — surface swim, dive, sprint-swim, and surface-break state machine
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Swim controller — surface swim, dive, sprint-swim, and surface-break state machine" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Handles all water locomotion states: floating, diving, surfacing, and swimming at speed.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/SwimController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 147H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 147 (Swim controller — surface swim, dive, sprint-swim, and surface-break state machine)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 147 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 147, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/SwimController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 147.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 148
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** PlayerActor swim state integration — detect water entry, delegate to SwimController, restore on exit
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "PlayerActor swim state integration — detect water entry, delegate to SwimController, restore on exit" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Connects the swim controller to the player so entering a WaterVolume switches input and animation state.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 148H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 148 (PlayerActor swim state integration — detect water entry, delegate to SwimController, restore on exit)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 148 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 148, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 148.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section D — Vehicles (Tasks 149–155)

## Task 149
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** VehicleActor base — shared physics body, enter/exit boarding, occupant seat management
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "VehicleActor base — shared physics body, enter/exit boarding, occupant seat management" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Common base for all driveable vehicles; keeps boarding logic, collision, and camera handoff in one place.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/VehicleActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 149H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 149 (VehicleActor base — shared physics body, enter/exit boarding, occupant seat management)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 149 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 149, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/VehicleActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 149.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 150
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** CarActor — 4-wheel ground vehicle (car / truck / van) with suspension physics and engine audio hook
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "CarActor — 4-wheel ground vehicle (car / truck / van) with suspension physics and engine audio hook" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Provides the primary ground transport option; handles road-surface friction and AI traffic spawning.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/CarActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 150H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 150 (CarActor — 4-wheel ground vehicle (car / truck / van) with suspension physics and engine audio hook)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 150 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 150, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/CarActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 150.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 151
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** MotorcycleActor — 2-wheel lean-physics ground vehicle with higher speed cap and tighter turning
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "MotorcycleActor — 2-wheel lean-physics ground vehicle with higher speed cap and tighter turning" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Delivers a FF15-style fast scout vehicle; lean simulation gives it a distinct handling feel.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MotorcycleActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 151H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 151 (MotorcycleActor — 2-wheel lean-physics ground vehicle with higher speed cap and tighter turning)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 151 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 151, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MotorcycleActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 151.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 152
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** AirshipActor — free-flight 6DOF aircraft with altitude limits and hover mode
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "AirshipActor — free-flight 6DOF aircraft with altitude limits and hover mode" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Classic FF airship for continent-scale fast travel; free-flight feel with FF nostalgia lineage.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/AirshipActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 152H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 152 (AirshipActor — free-flight 6DOF aircraft with altitude limits and hover mode)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 152 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 152, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/AirshipActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 152.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 153
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** BoatActor — water-surface vessel with BuoyancyComponent, throttle, and wake particle hook
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "BoatActor — water-surface vessel with BuoyancyComponent, throttle, and wake particle hook" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Enables sea travel between islands; stays on water surface via BuoyancyComponent.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/BoatActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 153H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 153 (BoatActor — water-surface vessel with BuoyancyComponent, throttle, and wake particle hook)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 153 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 153, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/BoatActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 153.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 154
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** InputActionMap: add vehicle-specific actions — VehicleSteer, VehicleAccel, VehicleBrake, VehicleExit, VehicleBoost
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "InputActionMap: add vehicle-specific actions — VehicleSteer, VehicleAccel, VehicleBrake, VehicleExit, VehicleBoost" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Separates vehicle controls from foot movement so input routing is deterministic and remappable.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=40 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 155
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** CameraController: vehicle camera mode — third-person follow with speed-adaptive FOV and drift lag
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "CameraController: vehicle camera mode — third-person follow with speed-adaptive FOV and drift lag" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Switches to a wider speed-sensitive camera when inside a vehicle, returning to combat camera on exit.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 155H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 155 (CameraController: vehicle camera mode — third-person follow with speed-adaptive FOV and drift lag)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 155 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 155, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 155.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section E — Roads + Traffic (Tasks 156–161)

## Task 156
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Road spline system — spline data loader and road-mesh generator from Content/Roads/*.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Road spline system — spline data loader and road-mesh generator from Content/Roads/*.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Builds driveable road meshes from authored spline data; AI traffic and player vehicles follow these paths.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/RoadSpline.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 156H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 156 (Road spline system — spline data loader and road-mesh generator from Content/Roads/*.json)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 156 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 156, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/RoadSpline.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 156.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 157
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Traffic director — spawns and drives AI cars along RoadSpline paths at configurable density
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Traffic director — spawns and drives AI cars along RoadSpline paths at configurable density" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Fills the world with ambient vehicle traffic that makes towns and highways feel alive.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/TrafficDirector.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 157H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 157 (Traffic director — spawns and drives AI cars along RoadSpline paths at configurable density)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 157 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 157, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/TrafficDirector.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 157.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 158
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Pedestrian actor — crowd NPC that walks patrol paths, reacts to combat and vehicles
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Pedestrian actor — crowd NPC that walks patrol paths, reacts to combat and vehicles" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Adds civilians and town-dwellers that give settlements population depth and react believably to the player.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/PedestrianActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 158H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 158 (Pedestrian actor — crowd NPC that walks patrol paths, reacts to combat and vehicles)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 158 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 158, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/PedestrianActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 158.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 159
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Road spline authoring template — Content/Roads/road_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Road spline authoring template — Content/Roads/road_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical JSON schema for a road spline: id, control points[], lane width, surface type.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Roads/road_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 160
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Vehicle spawn point template — Content/Vehicles/vehicle_spawns_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Vehicle spawn point template — Content/Vehicles/vehicle_spawns_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines spawn entries for parked/world vehicles: type, position, rotation, ownership flag.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Vehicles/vehicle_spawns_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 161
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WorldEditor: road painter panel — click-to-place spline control points, save to Content/Roads/
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WorldEditor: road painter panel — click-to-place spline control points, save to Content/Roads/" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lets the world-builder draw road networks visually in-engine rather than hand-editing spline JSON.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section F — Open-World Systems (Tasks 162–170)

## Task 162
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NpcActor day/night schedule — state table (shop-open / patrol / sleep) keyed by DayNightCycle hour
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "NpcActor day/night schedule — state table (shop-open / patrol / sleep) keyed by DayNightCycle hour" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** NPCs go to bed, open stalls, and walk to work based on the time of day, giving the world a lived-in feel.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 162H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 162 (NpcActor day/night schedule — state table (shop-open / patrol / sleep) keyed by DayNightCycle hour)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 162 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 162, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 162.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 163
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fishing minigame — cast, wait, reel timing minigame with loot table hook for fish items
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Fishing minigame — cast, wait, reel timing minigame with loot table hook for fish items" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Classic JRPG side activity; reuses LootTable for fish drops and links to Inventory for item rewards.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FishingMinigame.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 163H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 163 (Fishing minigame — cast, wait, reel timing minigame with loot table hook for fish items)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 163 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 163, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FishingMinigame.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 163.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 164
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Mount actor — rideable chocobo/mount with speed bonus, auto-dismount at combat proximity
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Mount actor — rideable chocobo/mount with speed bonus, auto-dismount at combat proximity" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Delivers the FF-iconic chocobo ride; faster than running but dismounts when enemies are near.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MountActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 164H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 164 (Mount actor — rideable chocobo/mount with speed bonus, auto-dismount at combat proximity)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 164 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 164, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MountActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 164.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 165
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Photo mode — freeze simulation, free-fly camera, exposure + depth-of-field sliders, screenshot
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Photo mode — freeze simulation, free-fly camera, exposure + depth-of-field sliders, screenshot" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Standard in all modern open-world games; lets players capture the world's handmade PS2-style vistas.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/PhotoMode.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 165H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 165 (Photo mode — freeze simulation, free-fly camera, exposure + depth-of-field sliders, screenshot)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 165 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 165, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/PhotoMode.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 165.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 166
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Climb system — ledge detection, grab, pull-up, wall shimmy, and vault over short obstacles
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Climb system — ledge detection, grab, pull-up, wall shimmy, and vault over short obstacles" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Extends world traversal so players can explore terrain naturally without invisible walls.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/ClimbSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 166H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 166 (Climb system — ledge detection, grab, pull-up, wall shimmy, and vault over short obstacles)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 166 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 166, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/ClimbSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 166.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 167
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Glide controller — equip-triggered wing-suit / parachute glide from airship or high ledge
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Glide controller — equip-triggered wing-suit / parachute glide from airship or high ledge" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Provides large-world aerial traversal similar to FF15 regalia air descent, GT610-safe physics.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/GlideController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 167H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 167 (Glide controller — equip-triggered wing-suit / parachute glide from airship or high ledge)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 167 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 167, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/GlideController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 167.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 168
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Chase AI — enemy pursuit across streaming terrain using NavMesh with memory and give-up timer
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Chase AI — enemy pursuit across streaming terrain using NavMesh with memory and give-up timer" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Gives enemies persistent pursuit behaviour that feels threatening without infinite-chase exploits.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/ChaseAI.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 168H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 168 (Chase AI — enemy pursuit across streaming terrain using NavMesh with memory and give-up timer)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 168 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 168, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/ChaseAI.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 168.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 169
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Interior portal system — seamless trigger-based transition between indoor cells and the open world
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Interior portal system — seamless trigger-based transition between indoor cells and the open world" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Eliminates loading screens when entering buildings by streaming the interior cell and blending fog.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteriorPortalSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 169H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 169 (Interior portal system — seamless trigger-based transition between indoor cells and the open world)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 169 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 169, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteriorPortalSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 169.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 170
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Region definition template — Content/World/region_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Region definition template — Content/World/region_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical schema for a world region: id, biome, weather table, ambient audio id, BGM id, population density.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/World/region_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

### Section G — Audio Completion (Tasks 171–172)

## Task 171
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** AudioManager: underwater audio filter — low-pass muffle applied when player submerges
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "AudioManager: underwater audio filter — low-pass muffle applied when player submerges" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Activates a low-pass filter on all non-music buses when the player is inside a WaterVolume.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 172
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** AudioManager: vehicle engine audio — pitch/volume scale by throttle and speed each frame
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "AudioManager: vehicle engine audio — pitch/volume scale by throttle and speed each frame" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Drives the engine sound loop so cars and boats sound alive and proportional to player input.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section H — Final Sweeps + World-Building Documentation (Tasks 173–177)

## Task 173
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** PlayerActor: full traversal integration sweep — walk/run/swim/climb/mount/vehicle state unification
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "PlayerActor: full traversal integration sweep — walk/run/swim/climb/mount/vehicle state unification" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Ensures every locomotion state transitions cleanly to every other state with no stuck-states or camera pops.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 174
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** D3D11Renderer: integrate PS2 render pass, water renderer, and post-process pipeline into main frame
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "D3D11Renderer: integrate PS2 render pass, water renderer, and post-process pipeline into main frame" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Connects the new render systems into the main draw loop: scene → water → PS2 pass → post-process.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/D3D11Renderer.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 175
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Main.cpp: final system wiring sweep — verify every new system is constructed, ordered, and shut down
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Main.cpp: final system wiring sweep — verify every new system is constructed, ordered, and shut down" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Guarantees no system is silently orphaned; the game boots cleanly and all new features are active.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 176
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WORLD_BUILDING_GUIDE.md — step-by-step guide for authoring quests, dialogue, NPCs, and regions in JSON
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WORLD_BUILDING_GUIDE.md — step-by-step guide for authoring quests, dialogue, NPCs, and regions in JSON" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Empowers the story/world-building phase to proceed without touching C++; covers every JSON schema.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/WORLD_BUILDING_GUIDE.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under the most relevant section heading.
7. **Additional information:** LINE_BUDGET target <=200 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

## Task 177
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** SHIP_CHECKLIST.md: extended gates — open-world streaming, vehicles, water, PS2 visuals, content pipeline
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "SHIP_CHECKLIST.md: extended gates — open-world streaming, vehicles, water, PS2 visuals, content pipeline" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Adds release acceptance criteria for every system added in tasks 121-176.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under the most relevant section heading.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

### Section I — Core Missing UI Screens (Tasks 178–183)

## Task 178
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Title screen and main menu — New Game / Continue / Settings / Quit with animated FF-style background
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Title screen and main menu — New Game / Continue / Settings / Quit with animated FF-style background" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Every commercial game needs a title screen; styled like FF7/FF8 with logo animation and menu music sting.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/TitleScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 178H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 178 (Title screen and main menu — New Game / Continue / Settings / Quit with animated FF-style background)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 178 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 178, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/TitleScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 178.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 179
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Inventory screen — full grid-based item list with category tabs and detail panel on selection
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Inventory screen — full grid-based item list with category tabs and detail panel on selection" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lets the player manage all items, see descriptions, and use/equip from a dedicated full-screen UI.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/InventoryScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 179H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 179 (Inventory screen — full grid-based item list with category tabs and detail panel on selection)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 179 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 179, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/InventoryScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 179.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 180
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Bestiary / enemy codex screen — unlocked entries with enemy lore, stats, and weak-point diagram
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Bestiary / enemy codex screen — unlocked entries with enemy lore, stats, and weak-point diagram" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Rewards exploration and adds FF-style collectible depth; entries unlock when an enemy is first defeated.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/BestiaryScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 180H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 180 (Bestiary / enemy codex screen — unlocked entries with enemy lore, stats, and weak-point diagram)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 180 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 180, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/BestiaryScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 180.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 181
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Skill tree screen — visual node graph showing unlocked/locked abilities with unlock cost and description
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Skill tree screen — visual node graph showing unlocked/locked abilities with unlock cost and description" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Wraps the SkillTree backend (Task 088) in a browsable visual UI using ImGui node-style drawing.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/SkillTreeScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 181H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 181 (Skill tree screen — visual node graph showing unlocked/locked abilities with unlock cost and description)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 181 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 181, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/SkillTreeScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 181.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 182
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Crafting screen — recipe list, ingredient status bars, and Craft button tied to CraftingSystem
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Crafting screen — recipe list, ingredient status bars, and Craft button tied to CraftingSystem" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Gives players a clear crafting interface at upgrade stations; shows missing ingredients in red.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CraftingScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 182H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 182 (Crafting screen — recipe list, ingredient status bars, and Craft button tied to CraftingSystem)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 182 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 182, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CraftingScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 182.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 183
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Shop screen — buy/sell tabs, item grid, price list, and Gil balance tied to ShopInventory
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Shop screen — buy/sell tabs, item grid, price list, and Gil balance tied to ShopInventory" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Standard JRPG shop UI; buy or sell with Gil currency, scrollable list, confirm dialog.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ShopScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 183H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 183 (Shop screen — buy/sell tabs, item grid, price list, and Gil balance tied to ShopInventory)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 183 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 183, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ShopScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 183.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section J — Merchant + Inn NPC System (Tasks 184–186)

## Task 184
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Merchant actor — shop NPC that opens ShopScreen and references a ShopInventory data asset
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Merchant actor — shop NPC that opens ShopScreen and references a ShopInventory data asset" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Places buyable-goods vendors in towns; authored by placing a MerchantActor with a shop_inventory_id.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MerchantActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 184H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 184 (Merchant actor — shop NPC that opens ShopScreen and references a ShopInventory data asset)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 184 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 184, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MerchantActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 184.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 185
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Innkeeper actor — inn NPC that offers rest (restores HP/MP, saves game) for a Gil cost
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Innkeeper actor — inn NPC that offers rest (restores HP/MP, saves game) for a Gil cost" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Classic JRPG inn mechanic; links to SaveSystem and restores player stats on confirm.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/InnkeeperActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 185H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 185 (Innkeeper actor — inn NPC that offers rest (restores HP/MP, saves game) for a Gil cost)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 185 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 185, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/InnkeeperActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 185.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 186
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Shop inventory system — data-driven item stock list with base prices loaded from JSON
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Shop inventory system — data-driven item stock list with base prices loaded from JSON" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Decouples shop contents from NPC code; each merchant references a ShopInventory JSON asset.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/ShopInventory.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 186H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 186 (Shop inventory system — data-driven item stock list with base prices loaded from JSON)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 186 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 186, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/ShopInventory.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 186.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section K — Shadow + Emissive Rendering (Tasks 187–190)

## Task 187
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Shadow map depth-pass vertex shader (shadow_vs.hlsl) — renders scene depth from directional light
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Shadow map depth-pass vertex shader (shadow_vs.hlsl) — renders scene depth from directional light" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** PS2-era games used baked shadows, but a single directional shadow map gives modern grounding at low GT610 cost.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/shadow_vs.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 188
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Shadow map depth-pass pixel shader (shadow_ps.hlsl) — outputs depth to shadow RT
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Shadow map depth-pass pixel shader (shadow_ps.hlsl) — outputs depth to shadow RT" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Pairs with shadow_vs to produce a 512×512 shadow map per frame — sufficient for PS2-style scenes.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/shadow_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=40 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 189
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Shadow renderer — manages shadow RT, depth pass, and shadow-factor injection into main render
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Shadow renderer — manages shadow RT, depth pass, and shadow-factor injection into main render" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Runs the depth pass before the main render, then supplies the shadow texture to the lit material shader.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/ShadowRenderer.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 189H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 189 (Shadow renderer — manages shadow RT, depth pass, and shadow-factor injection into main render)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 189 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 189, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/ShadowRenderer.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 189.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 190
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Emissive material pixel shader (emissive_ps.hlsl) — glowing signs, fire pits, materia, magic effects
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Emissive material pixel shader (emissive_ps.hlsl) — glowing signs, fire pits, materia, magic effects" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Adds bright self-lit surfaces for world props; drives the FF materia glow look without dynamic point lights.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/emissive_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section L — Weather Particle Rendering (Tasks 191–192)

## Task 191
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Rain particle vertex shader (rain_particle_vs.hlsl) — GPU-driven streaking rain drop positions
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Rain particle vertex shader (rain_particle_vs.hlsl) — GPU-driven streaking rain drop positions" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Drives hundreds of rain streak instances on the GPU; negligible cost on GT610 using instanced draw.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/rain_particle_vs.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 192
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Rain particle pixel shader (rain_particle_ps.hlsl) — translucent alpha-blended rain streak colour
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Rain particle pixel shader (rain_particle_ps.hlsl) — translucent alpha-blended rain streak colour" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Renders rain with a semi-transparent streak, consistent with PS2-era visual fidelity targets.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/rain_particle_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=40 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section M — Combat Extras (Tasks 193–196)

## Task 193
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Projectile system — spawn, simulate, and collide hitscan and physics projectiles (arrow, bolt, spell)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Projectile system — spawn, simulate, and collide hitscan and physics projectiles (arrow, bolt, spell)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Supports ranged enemies and magic attacks; projectiles travel in world space and trigger CombatSystem on hit.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/ProjectileSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 193H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 193 (Projectile system — spawn, simulate, and collide hitscan and physics projectiles (arrow, bolt, spell))
2. **What the task does + logic:** Adds/updates the required header declarations that Task 193 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 193, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/ProjectileSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 193.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 194
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cinematic finishing blow — slow-motion time scale with camera cut to close-up on kill
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cinematic finishing blow — slow-motion time scale with camera cut to close-up on kill" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Delivers the dramatic kill moment from FF7 Remake; triggered at the last combo hit on a staggered enemy.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/FinishingBlow.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 194H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 194 (Cinematic finishing blow — slow-motion time scale with camera cut to close-up on kill)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 194 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 194, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/FinishingBlow.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 194.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 195
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** EnemyActor: flee/retreat behaviour and death ragdoll placeholder on HP reaching zero
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "EnemyActor: flee/retreat behaviour and death ragdoll placeholder on HP reaching zero" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Enemies run from dominant players and crumple on death; ragdoll is a static death pose placeholder.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 196
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** AoE ground indicator — circle/ring decal drawn on terrain showing incoming area attack zone
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "AoE ground indicator — circle/ring decal drawn on terrain showing incoming area attack zone" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Telegraphs enemy AoE attacks with a visible ground ring before they fire; essential for action-RPG readability.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/AoEIndicator.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 196H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 196 (AoE ground indicator — circle/ring decal drawn on terrain showing incoming area attack zone)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 196 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 196, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/AoEIndicator.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 196.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section N — World Interaction Props (Tasks 197–198)

## Task 197
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Destructible prop — world object (crate, barrel, jar) that fractures on attack hit with loot drop
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Destructible prop — world object (crate, barrel, jar) that fractures on attack hit with loot drop" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Adds environmental reward to exploration; breaking props drops Gil or consumables from the loot table.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/DestructibleProp.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 197H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 197 (Destructible prop — world object (crate, barrel, jar) that fractures on attack hit with loot drop)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 197 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 197, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/DestructibleProp.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 197.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 198
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Interactive prop — world object (door, lever, switch) that triggers state changes or EventZone signals
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Interactive prop — world object (door, lever, switch) that triggers state changes or EventZone signals" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Powers dungeon puzzles, locked gates, and secret passages; state is persisted via RegionStateStore.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractiveProp.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 198H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 198 (Interactive prop — world object (door, lever, switch) that triggers state changes or EventZone signals)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 198 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 198, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractiveProp.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 198.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section O — Developer / Debug Tools (Tasks 199–201)

## Task 199
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** In-game developer console — toggle with tilde, accepts typed commands (teleport, give, spawn, set_time)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "In-game developer console — toggle with tilde, accepts typed commands (teleport, give, spawn, set_time)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Dev-build only; essential for QA and balancing without recompiling; stripped from release build.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/DebugConsole.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 199H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 199 (In-game developer console — toggle with tilde, accepts typed commands (teleport, give, spawn, set_time))
2. **What the task does + logic:** Adds/updates the required header declarations that Task 199 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 199, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/DebugConsole.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 199.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 200
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Asset hot-reloader — file-watcher that reloads changed HLSL shaders and textures without restart
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Asset hot-reloader — file-watcher that reloads changed HLSL shaders and textures without restart" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Cuts iteration time when tweaking shaders or texture colours; dev-build only, no release cost.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/AssetHotReloader.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 200H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 200 (Asset hot-reloader — file-watcher that reloads changed HLSL shaders and textures without restart)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 200 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 200, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/AssetHotReloader.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 200.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 201
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WorldEditor: NPC patrol-path drawing tool — place waypoints, preview path loop, save to NPC JSON
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WorldEditor: NPC patrol-path drawing tool — place waypoints, preview path loop, save to NPC JSON" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lets world-builders define guard routes, town-walker loops, and escort paths visually in-engine.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section P — FF Nostalgia Features (Tasks 202–206)

## Task 202
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Battle transition — screen flash and wipe effect on random encounter or scripted combat entry
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Battle transition — screen flash and wipe effect on random encounter or scripted combat entry" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Recreates the iconic FF7/FF8 battle-entry flash that signals a combat shift; skippable after first play.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/BattleTransition.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 202H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 202 (Battle transition — screen flash and wipe effect on random encounter or scripted combat entry)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 202 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 202, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/BattleTransition.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 202.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 203
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Victory screen — post-battle XP / Gil / item summary panel with fanfare audio hook and pose trigger
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Victory screen — post-battle XP / Gil / item summary panel with fanfare audio hook and pose trigger" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Classic FF victory moment: musical sting, level-up count, rare drop highlight; essential for the nostalgia feel.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/VictoryScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 203H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 203 (Victory screen — post-battle XP / Gil / item summary panel with fanfare audio hook and pose trigger)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 203 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 203, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/VictoryScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 203.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 204
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Gil currency system — central balance tracker, earn/spend API, and persistence in SaveSystem
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Gil currency system — central balance tracker, earn/spend API, and persistence in SaveSystem" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Header-only currency singleton; used by shops, loot drops, inn costs, and quest rewards.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/GilSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 205
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Materia / magic-slot glow shader (materia_glow_ps.hlsl) — pulsing sphere glow for equipped materia
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Materia / magic-slot glow shader (materia_glow_ps.hlsl) — pulsing sphere glow for equipped materia" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Renders the signature coloured glow on materia slots in the equipment screen and world pickups.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/materia_glow_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 206
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World map overview mode — zoom-out to full continent chibi-style overview with location pins
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "World map overview mode — zoom-out to full continent chibi-style overview with location pins" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lets players see the full world at once in a stylised FF7/FF10 world-map aesthetic to plan travel.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldMapMode.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 206H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 206 (World map overview mode — zoom-out to full continent chibi-style overview with location pins)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 206 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 206, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldMapMode.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 206.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section Q — Audio Zones (Tasks 207–208)

## Task 207
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Reverb zone system — trigger volumes that blend indoor/cave/underwater reverb on audio buses
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Reverb zone system — trigger volumes that blend indoor/cave/underwater reverb on audio buses" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Caves echo, cathedrals resonate, and open fields are dry; driven by trigger zones placed in the editor.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/ReverbZoneSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 207H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 207 (Reverb zone system — trigger volumes that blend indoor/cave/underwater reverb on audio buses)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 207 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 207, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/ReverbZoneSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 207.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 208
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Footstep audio system — material-tagged surface lookup plays correct footstep SFX per step
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Footstep audio system — material-tagged surface lookup plays correct footstep SFX per step" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Differentiates stone, grass, metal, water, and sand footsteps for immersive world traversal.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/FootstepAudioSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 208H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 208 (Footstep audio system — material-tagged surface lookup plays correct footstep SFX per step)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 208 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 208, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/FootstepAudioSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 208.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section R — Accessibility (Tasks 209–210)

## Task 209
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Colorblind mode post-pass shader (colorblind_ps.hlsl) — Deuteranopia / Protanopia / Tritanopia LUT
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Colorblind mode post-pass shader (colorblind_ps.hlsl) — Deuteranopia / Protanopia / Tritanopia LUT" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Three LUT-based colour remap modes applied as a final post-pass; zero GT610 performance cost.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/colorblind_ps.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 210
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Accessibility settings — text scale multiplier, high-contrast UI, subtitle size, and icon mode
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Accessibility settings — text scale multiplier, high-contrast UI, subtitle size, and icon mode" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Header-only settings struct read by all UI renderers; no separate .cpp needed.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/AccessibilitySettings.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type or constant block and keep changes local.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section S — WorldEditor Tool Extensions (Tasks 211–214)

## Task 211
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WorldEditor: terrain height painter — brush radius + strength sliders, paint height on cell mesh
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WorldEditor: terrain height painter — brush radius + strength sliders, paint height on cell mesh" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lets world-builders sculpt hills, valleys, and cliffs without hand-editing vertex data.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 212
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WorldEditor: foliage scatter painter — paint tree/grass instances across terrain by brush stroke
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WorldEditor: foliage scatter painter — paint tree/grass instances across terrain by brush stroke" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Populates landscape with Forest/foliage density using a paint brush rather than manually placing prefabs.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 213
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WorldEditor: point-light placement panel — drag to place, set colour/radius/intensity, save to cell JSON
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WorldEditor: point-light placement panel — drag to place, set colour/radius/intensity, save to cell JSON" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lets artists light towns, dungeons, and campfires visually without modifying C++ or prefab definitions.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=100 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 214
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WorldEditor: trigger volume paint tool — draw AABB trigger zones linked to EventZone or DialogueTrigger
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WorldEditor: trigger volume paint tool — draw AABB trigger zones linked to EventZone or DialogueTrigger" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Unifies quest zone, cutscene trigger, and ambient-audio zone placement in one visual brush tool.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldEditor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

### Section T — Content Authoring Templates (Tasks 215–218)

## Task 215
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy archetype template — Content/Enemies/enemy_archetype_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Enemy archetype template — Content/Enemies/enemy_archetype_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical schema for enemy stats, AI profile, loot table reference, and weak points.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Enemies/enemy_archetype_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 216
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Item definition template — Content/Items/item_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Item definition template — Content/Items/item_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical schema for all item types: id, name key, icon path, stat modifiers, use effect.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Items/item_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 217
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Shop stock template — Content/Shops/shop_inventory_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Shop stock template — Content/Shops/shop_inventory_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical schema for a merchant's stock list: item_id, quantity, price_gil, restock_flag.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Shops/shop_inventory_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 218
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cutscene script template — Content/Cutscenes/cutscene_template.json
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cutscene script template — Content/Cutscenes/cutscene_template.json" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Defines the canonical timeline schema for cutscenes: tracks[], camera rail[], dialogue cue[], event cue[].
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Cutscenes/cutscene_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file; output the full JSON document as the paste block.
7. **Additional information:** LINE_BUDGET target <=40 lines in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

### Section U — Final Integration Sweeps + Ship Documentation (Tasks 219–223)

## Task 219
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** D3D11Renderer: integrate shadow renderer, emissive pass, and rain particle pass into frame loop
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "D3D11Renderer: integrate shadow renderer, emissive pass, and rain particle pass into frame loop" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Stitches the new render layers (shadow → scene → emissive → particles → PS2 pass → post) into the main loop.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/rendering/d3d11/D3D11Renderer.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 220
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Main.cpp: complete system wiring final sweep — all 178-219 systems constructed, ordered, and shut down
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Main.cpp: complete system wiring final sweep — all 178-219 systems constructed, ordered, and shut down" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Guarantees the entire feature set is live at runtime with zero orphaned or double-initialised systems.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 221
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WORLD_BUILDING_GUIDE.md — complete authoritative guide for story, quest, dialogue, NPC, and region authoring
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "WORLD_BUILDING_GUIDE.md — complete authoritative guide for story, quest, dialogue, NPC, and region authoring" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** After this task the user can write the full game story using only JSON files and the in-game WorldEditor.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/WORLD_BUILDING_GUIDE.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under the most relevant section heading.
7. **Additional information:** LINE_BUDGET target <=200 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

## Task 222
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** CONTENT_CREATION_GUIDE.md — guide for adding art assets (textures, models, audio) to Content/ folders
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "CONTENT_CREATION_GUIDE.md — guide for adding art assets (textures, models, audio) to Content/ folders" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Explains how to import and register every asset type so artists can work independently from engineers.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/CONTENT_CREATION_GUIDE.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under the most relevant section heading.
7. **Additional information:** LINE_BUDGET target <=200 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

## Task 223
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** SHIP_CHECKLIST.md: final extended checklist — all systems, content pipeline, QA gates, legal, and performance
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "SHIP_CHECKLIST.md: final extended checklist — all systems, content pipeline, QA gates, legal, and performance" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Single definitive sign-off document confirming the game is commercially complete and release-ready.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under the most relevant section heading.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

### Section V — Modern Open-World Systems Missing Pass (Tasks 224–235)

## Task 224
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Faction reputation system — multi-faction standing with thresholds that gate shops, quests, and guard reactions
2. **What the task does + logic:** Implements a runtime-visible reputation tracker for major world factions so player actions influence world access and social consequences.
3. **Narrative logic explanation:** Initialize faction table, guard invalid faction ids, apply gain/loss deltas from events, then expose threshold queries for UI and quest gating.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds modern systemic reactivity while preserving readable JRPG progression and low-overhead logic on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FactionReputationSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 224H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 224 (Faction reputation system)
2. **What the task does + logic:** Adds/updates declarations required by Task 224 so implementation compiles and can be consumed by quest/UI systems.
3. **Narrative logic explanation:** Read current declarations, add only required signatures/types, guard duplicates, then keep ordering stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep interfaces explicit and deterministic for weak local LLM execution.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FactionReputationSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 225
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Wanted / crime system — witness-based crime scoring with guard pursuit and cooldown decay
2. **What the task does + logic:** Implements a modern open-world crime loop where illegal actions increase wanted level and trigger guard responses.
3. **Narrative logic explanation:** Track crime events, guard invalid categories, accumulate wanted score with decay, then publish guard response state.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds city-law reactivity like modern RPGs while keeping simple deterministic state transitions.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/WantedSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 225H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 225 (Wanted / crime system)
2. **What the task does + logic:** Adds/updates declarations required by Task 225 for use by AI, UI, and save systems.
3. **Narrative logic explanation:** Read current declarations, add only needed members/signatures, guard duplicates, then keep declaration flow clear.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep external API stable for one-file-at-a-time implementation flow.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/WantedSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 226
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dynamic world event director — ambient encounters, rescue events, convoy ambushes, and roaming bosses
2. **What the task does + logic:** Implements weighted event spawning based on region, time, weather, and player progression flags.
3. **Narrative logic explanation:** Build event pool, guard invalid spawn contexts, roll deterministic weighted pick, then publish active world event entry.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Makes traversal feel alive like large studios while retaining lightweight event logic.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/DynamicEventDirector.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 226H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 226 (Dynamic world event director)
2. **What the task does + logic:** Adds/updates declarations required by Task 226 so world, quest, and map systems can query active events.
3. **Narrative logic explanation:** Read declarations, add event structs and query signatures, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Preserve predictable interfaces for low-reasoning LLM execution.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/DynamicEventDirector.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 227
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Camp system — place camp, rest until chosen time, party healing, and camp interaction menu
2. **What the task does + logic:** Implements a modern open-world camp loop for pacing, recovery, and time control.
3. **Narrative logic explanation:** Validate camp placement, guard unsafe locations, open camp menu flow, then apply rest/heal/time-skip outputs.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds FF15-style world downtime while staying low-cost and deterministic.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/CampSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 227H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 227 (Camp system)
2. **What the task does + logic:** Adds/updates declarations required by Task 227 for integration with day/night, party, and save systems.
3. **Narrative logic explanation:** Read declarations, add only required signatures/state structs, guard duplicates, then keep ordering stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep camp flow integration explicit and beginner-friendly.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/CampSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 228
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Companion manager — active party member selection, swap rules, and tactical role presets
2. **What the task does + logic:** Implements multi-companion management expected in modern party-based open-world RPGs.
3. **Narrative logic explanation:** Initialize party slots, guard invalid swap requests, apply role preset updates, then expose active roster state.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Supports FF7-style party identity with modern role-swapping convenience.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/CompanionManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 228H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 228 (Companion manager)
2. **What the task does + logic:** Adds/updates declarations required by Task 228 for RuntimeScene and UI integration.
3. **Narrative logic explanation:** Read declarations, add only required companion state/query API, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep party APIs simple for predictable one-file implementation.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/CompanionManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 229
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Companion banter authoring template — contextual banter triggers (region, weather, quest phase, combat aftermath)
2. **What the task does + logic:** Adds a JSON schema template for authored companion dialogue banter in open-world traversal.
3. **Narrative logic explanation:** Define top-level keys, guard required fields, include trigger context arrays, then output canonical template.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps handcrafted party personality while enabling scalable authored content.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Dialogue/companion_banter_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; output full JSON template.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

## Task 230
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fast-travel network — unlockable travel nodes, map selection, and travel cost/conditions
2. **What the task does + logic:** Implements modern fast-travel flow with discoverable nodes and quest/region lock conditions.
3. **Narrative logic explanation:** Load nodes, guard locked destinations, resolve travel request, then update player position and streaming prewarm hints.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Balances open-world scale with practical traversal while preserving regional identity.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravelNetwork.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 230H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 230 (Fast-travel network)
2. **What the task does + logic:** Adds/updates declarations required by Task 230 so UI/map and world streaming can call travel APIs.
3. **Narrative logic explanation:** Read declarations, add node structs and query methods, guard duplicates, then keep declaration ordering clear.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps travel integration straightforward for tiny-step LLM workflows.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravelNetwork.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 231
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Discovery log screen — records discovered landmarks, dungeons, camps, and hidden areas
2. **What the task does + logic:** Implements a completion-tracking UI page for exploration milestones.
3. **Narrative logic explanation:** Build discovery list model, guard duplicate entries, group by region/type, then render completion progress in UI.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Encourages exploration with visible progress while keeping UI low-cost.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/DiscoveryLogScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 231H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 231 (Discovery log screen)
2. **What the task does + logic:** Adds/updates declarations required by Task 231 so exploration systems can push discovery entries.
3. **Narrative logic explanation:** Read declarations, add entry structs/query methods, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps completion logging interface explicit and easy to maintain.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/DiscoveryLogScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 232
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Collectible system — region-based collectible sets with completion rewards and world pin hints
2. **What the task does + logic:** Implements collectible tracking and reward unlocks expected in modern open-world progression loops.
3. **Narrative logic explanation:** Register collectibles, guard duplicate pickups, update per-region completion, then publish reward unlock events.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds exploration rewards without heavy runtime cost.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/CollectibleSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 232H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 232 (Collectible system)
2. **What the task does + logic:** Adds/updates declarations required by Task 232 for save/load, UI, and reward systems.
3. **Narrative logic explanation:** Read declarations, add only required types and methods, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps collectible APIs deterministic for step-by-step execution.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/CollectibleSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 233
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Treasure map / clue system — clue text links to world regions and unlocks hidden chest markers
2. **What the task does + logic:** Implements clue-driven treasure hunts that bridge lore text and exploration gameplay.
3. **Narrative logic explanation:** Parse clue entries, guard unresolved clue ids, evaluate region hint conditions, then publish marker reveal events.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds handcrafted mystery loops with simple low-cost logic.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/TreasureClueSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 233H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 233 (Treasure map / clue system)
2. **What the task does + logic:** Adds/updates declarations required by Task 233 for quest log and map marker integration.
3. **Narrative logic explanation:** Read declarations, add clue structs/signatures, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Maintain clear interfaces for content-authored clue expansion.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/TreasureClueSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 234
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Bounty board system — region hunt contracts with rank tiers, timers, and reward payouts
2. **What the task does + logic:** Implements modern hunt-contract loops for repeatable combat content and region progression.
3. **Narrative logic explanation:** Load contracts, guard invalid target states, evaluate completion/failure, then emit payout and reputation deltas.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds FF12/FF15-style hunt depth while preserving simple contract flow.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/BountyBoardSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 234H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 234 (Bounty board system)
2. **What the task does + logic:** Adds/updates declarations required by Task 234 for UI board listings and contract lifecycle hooks.
3. **Narrative logic explanation:** Read declarations, add contract data/query APIs, guard duplicates, then keep declaration order clear.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep contract interfaces small and deterministic for low-reasoning tool execution.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/BountyBoardSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 235
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Hunt contract authoring template — contract id, target archetype, region, time window, rewards
2. **What the task does + logic:** Adds canonical JSON schema template for bounty contract authoring.
3. **Narrative logic explanation:** Define root keys, guard required fields, include reward and condition blocks, then output canonical contract template.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Enables rapid content expansion without C++ edits.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Content/Quests/hunt_contract_template.json`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; output full JSON template.
7. **Additional information:** LINE_BUDGET target <=60 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready JSON for this file only, with no extra files or commentary.

### Section W — Completion Depth + Large-Studio Polish Missing Pass (Tasks 236–246)

## Task 236
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Photo album gallery — stores in-game screenshots with location/time metadata and browse UI
2. **What the task does + logic:** Implements persistent photo gallery browsing to complete the photo-mode feature loop.
3. **Narrative logic explanation:** Register capture metadata, guard invalid image references, sort/filter gallery entries, then render browse/delete UI.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Preserves the handcrafted world memory loop expected in modern RPGs.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/PhotoAlbumScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 236H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 236 (Photo album gallery)
2. **What the task does + logic:** Adds/updates declarations required by Task 236 for save integration and UI calls.
3. **Narrative logic explanation:** Read declarations, add only needed entry structs/methods, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep interface minimal and easy for one-file task execution.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/PhotoAlbumScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 237
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Mount summon whistle system — call nearest owned mount with cooldown and path-safe arrival
2. **What the task does + logic:** Implements modern mount quality-of-life summon flow used in large open-world games.
3. **Narrative logic explanation:** Validate summon request, guard blocked contexts, resolve spawn path-safe arrival point, then issue mount approach command.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps traversal smooth while retaining handcrafted mount identity.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MountSummonSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 237H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 237 (Mount summon whistle system)
2. **What the task does + logic:** Adds/updates declarations required by Task 237 for input and mount actor integration.
3. **Narrative logic explanation:** Read declarations, add summon structs/signatures, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep mount summon API deterministic and easy to call.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/MountSummonSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 238
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Companion banter runtime player — triggers contextual banter lines and cooldown arbitration
2. **What the task does + logic:** Implements runtime playback and conflict-resolution logic for authored companion banter entries.
3. **Narrative logic explanation:** Pull contextual candidate lines, guard overlap conflicts, apply cooldown arbitration, then dispatch selected line to dialogue/audio.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds party personality density expected in modern FF-like adventures.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/dialogue/CompanionBanterRuntime.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 238H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 238 (Companion banter runtime player)
2. **What the task does + logic:** Adds/updates declarations required by Task 238 for dialogue/audio integration points.
3. **Narrative logic explanation:** Read declarations, add runtime structs/signatures, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep banter runtime contract simple for deterministic execution.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/dialogue/CompanionBanterRuntime.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 239
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Full keybind remap screen — editable action bindings with conflict detection and reset defaults
2. **What the task does + logic:** Implements modern control-remapping UX needed for accessibility and player preference.
3. **Narrative logic explanation:** List current bindings, guard invalid/repeated key assignments, apply remap with conflict prompts, then persist settings.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps action controls modern and configurable while preserving classic menu tone.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/KeybindSettingsScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 239H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 239 (Full keybind remap screen)
2. **What the task does + logic:** Adds/updates declarations required by Task 239 for input settings integration.
3. **Narrative logic explanation:** Read declarations, add remap state/query APIs, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps input configuration interfaces clear for one-file iteration.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/KeybindSettingsScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 240
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** New Game Plus flow — carry-over rules, enemy scaling tier, and optional chapter-skip flags
2. **What the task does + logic:** Implements replay progression expected in modern action RPG endgame loops.
3. **Narrative logic explanation:** Validate NG+ profile data, guard incompatible carry-over fields, apply scaling tier, then initialize NG+ session flags.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Supports replay value while preserving handcrafted progression pacing.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/NewGamePlusFlow.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 240H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 240 (New Game Plus flow)
2. **What the task does + logic:** Adds/updates declarations required by Task 240 for save/select/menu integration.
3. **Narrative logic explanation:** Read declarations, add profile/carry-over structs and init APIs, guard duplicates, then keep ordering stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep replay APIs explicit and low risk.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/NewGamePlusFlow.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 241
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Endgame trial gates — optional high-difficulty arena/boss challenge progression with score ranks
2. **What the task does + logic:** Implements post-story challenge structure used by large-studio action RPGs.
3. **Narrative logic explanation:** Register trial definitions, guard invalid unlock conditions, evaluate completion score tiers, then unlock next trial/reward.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Adds long-tail mastery content without inflating base campaign complexity.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/endgame/TrialGateSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 241H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 241 (Endgame trial gates)
2. **What the task does + logic:** Adds/updates declarations required by Task 241 so UI and reward systems can query trial status.
3. **Narrative logic explanation:** Read declarations, add trial structs/status API, guard duplicates, then keep declaration ordering stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep endgame integration deterministic and one-file friendly.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/endgame/TrialGateSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 242
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Save backup manifest — rolling backup slots and corruption recovery selection logic
2. **What the task does + logic:** Implements robust save resilience expected in large-scale open-world games.
3. **Narrative logic explanation:** Create backup manifest model, guard invalid slot metadata, rotate backups on save, then expose recovery candidate list.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Protects long playthroughs without heavy runtime overhead.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/save/SaveBackupManifest.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type/function and keep insertion local.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 242H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 242 (Save backup manifest)
2. **What the task does + logic:** Adds/updates declarations required by Task 242 for save/load and menu recovery integration.
3. **Narrative logic explanation:** Read declarations, add backup manifest structs/methods, guard duplicates, then keep declaration order stable.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keep save recovery API simple and reliable.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/save/SaveBackupManifest.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 243
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** WORLD_BUILDING_GUIDE.md addendum — faction, event, bounty, collectible, and banter authoring workflow
2. **What the task does + logic:** Extends world-authoring documentation with exact content pipeline for newly added modern systems.
3. **Narrative logic explanation:** Insert new section blocks, guard duplicate headings, provide deterministic order of authoring steps, then include acceptance checks.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Keeps handmade content production scalable like a studio pipeline.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/WORLD_BUILDING_GUIDE.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under authoring workflow sections.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

## Task 244
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** CONTENT_CREATION_GUIDE.md addendum — assets and data for camps, trials, hunt boards, and discovery collectibles
2. **What the task does + logic:** Extends content-production guide with exact file/folder contracts for newly added systems.
3. **Narrative logic explanation:** Add content pipeline sections, guard duplicate contracts, specify naming conventions and validation checklist, then provide publish flow.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Aligns handmade asset creation with predictable studio-grade pipeline rules.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/CONTENT_CREATION_GUIDE.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under content pipeline sections.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

## Task 245
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** SHIP_CHECKLIST.md addendum — acceptance gates for factions, wanted system, dynamic events, camps, companions, fast travel, NG+, endgame
2. **What the task does + logic:** Extends release readiness checklist with measurable pass/fail gates for the missing modern features.
3. **Narrative logic explanation:** Add new ship gate blocks, guard overlap with existing entries, define measurable criteria, then include evidence capture checklist.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Ensures final release quality matches modern expectations without violating PS2-era target constraints.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under release gate sections.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready markdown for this file only, with no extra files or commentary.

## Task 246
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Final integration sweep (modern systems pass) — wire new systems into Main.cpp lifecycle in deterministic order
2. **What the task does + logic:** Performs one final integration/wiring pass for Tasks 224–245 so systems initialize, update, and shutdown cleanly.
3. **Narrative logic explanation:** Add construction order block, guard null/uninitialized calls, insert update ordering, then add shutdown order and integration comments.
4. **Game design target (FF7 action + PS2 nostalgia + handmade):** Completes modern open-world feature parity while preserving stable GT610-safe runtime behavior.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor in startup/update/shutdown blocks and keep each insertion local.
7. **Additional information:** LINE_BUDGET target <=180 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

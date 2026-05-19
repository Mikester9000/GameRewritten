# ONE_FILE_COMPLETION_PLAN(CON1).md

Continuation/addendum for missing headers and missing-item task coverage in strict one-file task format.
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

## Verification Summary
- Base file reviewed: `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN.md`
- Source of truth checked: `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md`
- Base plan task count: **201** total — **108** primary `.cpp` feature tasks (Task 001-108) + **93** `.hpp` companion tasks (Task 001H-107H, one per `.cpp` task that needed a header pair).
- `.hpp` companion coverage: all `.cpp` tasks in the base plan have a matching `###H` companion task already in the base plan. No `.hpp` companions are missing.
- Addendum purpose: this file (CON1) extends the base plan with tasks that fall outside the 001-108 + 001H-107H scope: release readiness gates, plan-document maintenance, build wiring, content pipeline, PS2-era graphics, water/swimming, all vehicle types, roads/traffic AI, open-world systems (climbing, gliding, fishing, mounts, photo mode, interior portals), NPC day/night schedules, final integration sweeps, and world-building authoring guide.
- Tasks in this addendum: **106** total — **8** plan-document maintenance tasks (H01-H08) + **12** release gate tasks (Task 109-120) + **57** open-world/graphics/feature tasks (Task 121-177) + **29** `.hpp` companion tasks (121H-169H, one per new `.cpp` task that introduces new declarations).

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
These tasks add release-readiness validation content to documentation files (ship checklists, QA gates, legal review, etc.).
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
1. **Task Name:** Content minimum vertical-slice gate
2. **What the task does + logic:** Adds/updates minimum content acceptance criteria for one complete region loop (combat + NPC interaction + reward).
3. **Narrative logic explanation:** Define required loop stages, guard incomplete progression, validate handoff outcomes, then mark completion.
4. **Game design target (FF7 Remake + PS2):** Deliver readable action-RPG loop with constrained assets and performant world flow.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/QUALITY_BAR.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert under release quality gates.
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
2. **What the task does + logic:** Adds/updates final sign-off manifest format tying technical, content, legal, and performance gates into one release approval record.
3. **Narrative logic explanation:** Define sign-off fields, guard missing approvals, assemble final manifest, then publish final ship-ready status.
4. **Game design target (FF7 Remake + PS2):** Deliver commercially acceptable final package with predictable low-spec behavior.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; insert near end of release checklist as final gate section.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready text for this file only, with no extra files or commentary.

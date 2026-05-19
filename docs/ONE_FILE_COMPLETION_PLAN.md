# ONE_FILE_COMPLETION_PLAN.md

Commercial/retail completion plan in strict one-file task format.
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

## Verification Summary
- Source of truth checked: `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md`
- Required task count found: **108** (Task 001-108).
- Tasks listed in this plan: **108** (Task 001-108) primary `.cpp` feature tasks + **93** `.hpp` companion tasks (001H-107H).
- Coverage result: **108/108 included**. All `.hpp` companions present.
- Continuation addendum: see `ONE_FILE_COMPLETION_PLAN(CON1).md` for Tasks 109-120 (release gates), Tasks 121-246 (open-world / PS2 graphics / water / vehicles / roads / shops / FF nostalgia / audio zones / accessibility / WorldEditor tools / content pipeline / world-building docs / faction reputation / wanted-crime / dynamic events / camps / companions-banter / fast travel / collectibles / bounty hunts / NG+ / endgame trials / save backup resilience), and all H companions for those new tasks. Run base tasks 001-108 first, then CON1 tasks in order.
- Completion status reference checked: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md` (items mapped to these tasks remain tracked there).

## Global Rules
- One task per run.
- One file per task prompt.
- Use absolute paths only.
- Output copy-ready final text for manual paste.
- Do not claim direct file edits.
- Treat any "stub/lite/base/hook" task as full playable v1 delivery, not scaffold-only output.
- Use task owner routing from `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md` (SLM-first vs Copilot-required).
- If messages are not showing up, emit heartbeat lines:
  - `STATUS: START Task ###`
  - `STATUS: CHUNK X/N`
  - `STATUS: DONE Task ###`

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

## Full-System Completion Addendum (applies to every task card)
- Do not output placeholder-only code blocks for completion.
- Ensure paste-ready output can produce a playable end-to-end path for that task scope.
- For content tasks (NPC/quest/dialogue/textures), include or update:
  - data contract field usage,
  - asset/reference path usage,
  - runtime integration point,
  - save/load continuity hook if relevant.

## Task Cards (001-108)

## Task 001
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Pressure / stagger integration stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Pressure / stagger integration stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 002
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy reaction / interrupt-lite
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy reaction / interrupt-lite" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 003
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy attack telegraph lite
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy attack telegraph lite" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 004
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Screen edge damage flash
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Screen edge damage flash" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 005
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Hit pause / hitstop
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Hit pause / hitstop" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 006
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Stagger meter
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Stagger meter" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 007
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy attack telegraph
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy attack telegraph" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 008
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Parry / counter window
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Parry / counter window" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 009
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Weak point damage
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Weak point damage" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 010
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Area name display
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Area name display" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 011
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Notification toast system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Notification toast system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 012
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Letterbox event bars
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Letterbox event bars" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 013
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Contextual button prompts
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Contextual button prompts" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 014
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Level up screen overlay
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Level up screen overlay" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 015
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Status screen
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Status screen" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 016
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Map screen stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Map screen stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 017
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Tooltip system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Tooltip system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 018
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Saving indicator
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Saving indicator" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 019
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Death / defeat screen
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Death / defeat screen" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 020
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Camera shake
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Camera shake" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 021
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combat camera zoom
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Combat camera zoom" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 022
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Camera collision avoidance
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Camera collision avoidance" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 023
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Target framing adjustment
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Target framing adjustment" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 024
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Lock-on camera recovery smoothing
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Lock-on camera recovery smoothing" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 025
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Wind effect on trees
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Wind effect on trees" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 026
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Weather system lite
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Weather system lite" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 027
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Ambient particles
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Ambient particles" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 028
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Day/night cycle
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Day/night cycle" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 029
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Biome transition fade
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Biome transition fade" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 030
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fog of war on minimap
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Fog of war on minimap" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 031
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World event trigger zones
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "World event trigger zones" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 032
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Interaction hotspot registry stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Interaction hotspot registry stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 033
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Landmark discovery trigger stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Landmark discovery trigger stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 034
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NPC actor
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "NPC actor" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 035
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest objective system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Quest objective system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 036
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Treasure chest actor
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Treasure chest actor" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 037
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Campfire / rest point actor
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Campfire / rest point actor" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 038
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NPC interaction prompt routing stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "NPC interaction prompt routing stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 039
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest flag / world-state hook
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Quest flag / world-state hook" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 040
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Spawn composition table stub (solo / pair / pack)
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Spawn composition table stub (solo / pair / pack)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 041
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Inventory system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Inventory system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 042
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** XP / level system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "XP / level system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 043
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Status effects
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Status effects" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 044
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fast travel stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Fast travel stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 045
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Save / load system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Save / load system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 046
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quality preset enforcement
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Quality preset enforcement" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 047
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Victory fanfare trigger
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Victory fanfare trigger" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 048
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Environmental ambient audio
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Environmental ambient audio" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 049
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Looping BGM
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Looping BGM" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 050
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Tactical Pause enter / exit SFX
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Tactical Pause enter / exit SFX" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 051
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Lock-on acquire / break SFX
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Lock-on acquire / break SFX" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 052
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy alert bark stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy alert bark stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 053
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Equipment slot stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Equipment slot stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 054
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Ability unlock / progression hook
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Ability unlock / progression hook" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 055
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combat stat modifier pipeline stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Combat stat modifier pipeline stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 056
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combat bugfix sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Combat bugfix sweep" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 057
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Camera/input bugfix sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Camera/input bugfix sweep" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 058
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** UI/HUD polish and bugfix sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "UI/HUD polish and bugfix sweep" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 059
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World/runtime stability sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "World/runtime stability sweep" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 060
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Audio and final quality sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Audio and final quality sweep" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 061
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World partition + region streaming core
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "World partition + region streaming core" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldPartition.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 062
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Asynchronous chunk IO + prefetch queue
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Asynchronous chunk IO + prefetch queue" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/StreamingIO.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 063
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Large-world coordinate rebasing
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Large-world coordinate rebasing" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldOriginRebase.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 064
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Terrain/mesh LOD tier manager
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Terrain/mesh LOD tier manager" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldLodManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 065
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Streaming budget governor (CPU/GPU/IO)
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Streaming budget governor (CPU/GPU/IO)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/StreamingBudget.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 066
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Far-distance continent impostors
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Far-distance continent impostors" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/ContinentImpostor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 067
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Global nav tile streaming bridge
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Global nav tile streaming bridge" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/NavTileStream.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 068
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Seamless continent transition triggers
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Seamless continent transition triggers" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/ContinentTransition.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 069
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Traversal mount/vehicle framework stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Traversal mount/vehicle framework stub" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/TraversalMount.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 070
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Traversal verbs: climb/swim/glide base
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Traversal verbs: climb/swim/glide base" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/TraversalController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 071
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Seamless interior/exterior cell portals
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Seamless interior/exterior cell portals" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/CellPortal.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 072
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World map overlay with continent zoom
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "World map overlay with continent zoom" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldMap.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 073
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Discovery journal for landmarks/routes
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Discovery journal for landmarks/routes" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/DiscoveryJournal.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 074
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Biome-aware population spawn director
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Biome-aware population spawn director" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/PopulationDirector.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 075
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World event scheduler (time/weather/region)
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "World event scheduler (time/weather/region)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldEventScheduler.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 076
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Region state persistence for streamed world
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Region state persistence for streamed world" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/RegionStateStore.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 077
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Party member runtime slot + follow AI
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Party member runtime slot + follow AI" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/PartyRuntime.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 078
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Command wheel + tactical slow-time commands
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Command wheel + tactical slow-time commands" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CommandWheel.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 079
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** ATB-style action charge lanes
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "ATB-style action charge lanes" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/AtbSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 080
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Ability targeting templates (single/cone/aoe)
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Ability targeting templates (single/cone/aoe)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/AbilityTargeting.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 081
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy archetype behavior profiles
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy archetype behavior profiles" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/EnemyArchetypeProfile.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 082
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy squad tactics coordinator
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy squad tactics coordinator" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/SquadCoordinator.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 083
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Boss phase state machine framework
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Boss phase state machine framework" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/BossActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 084
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Guard-break / poise combat pipeline
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Guard-break / poise combat pipeline" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/PoiseSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 085
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Elemental damage/resistance matrix
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Elemental damage/resistance matrix" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/ElementSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 086
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Status ailment counters + immunity windows
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Status ailment counters + immunity windows" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/StatusAilmentSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 087
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Equipment progression + socket rules
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Equipment progression + socket rules" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/EquipmentProgression.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 088
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Skill tree graph + unlock prerequisites
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Skill tree graph + unlock prerequisites" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/SkillTree.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 089
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Loot table tiers + drop weighting
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Loot table tiers + drop weighting" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/loot/LootTable.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 090
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Crafting + upgrade station flow
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Crafting + upgrade station flow" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/crafting/CraftingSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 091
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Open-world encounter director
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Open-world encounter director" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/EncounterDirector.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 092
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combat telemetry + balance debug panel
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Combat telemetry + balance debug panel" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CombatDebugPanel.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 093
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest authoring schema + validator
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Quest authoring schema + validator" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSchema.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 094
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dialogue branching + localization keys
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Dialogue branching + localization keys" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/dialogue/DialogueRuntime.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 095
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cutscene timeline stub + camera rails
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Cutscene timeline stub + camera rails" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/cutscene/CutsceneTimeline.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 096
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Audio event router + mixer bus controls
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Audio event router + mixer bus controls" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioRouter.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 097
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Adaptive music state machine
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Adaptive music state machine" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/MusicStateMachine.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 098
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** SFX variation + distance/occlusion rules
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "SFX variation + distance/occlusion rules" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/SfxSpatialRules.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 099
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Voice placeholder + subtitle timing pipeline
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Voice placeholder + subtitle timing pipeline" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/VoicePlayback.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 100
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Save versioning + migration compatibility
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Save versioning + migration compatibility" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveMigration.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 101
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Crash capture + runtime diagnostics pack
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Crash capture + runtime diagnostics pack" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/CrashDiagnostics.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 102
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Full settings menu (graphics/audio/input/accessibility)
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Full settings menu (graphics/audio/input/accessibility)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/SettingsMenu.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 103
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Input rebinding + controller glyph profiles
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Input rebinding + controller glyph profiles" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/InputBindingProfile.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 104
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Performance HUD + auto quality scaler
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Performance HUD + auto quality scaler" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/AutoQualityScaler.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 105
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Build packaging + release manifest scripts
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Build packaging + release manifest scripts" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/tools/release/PackageBuild.ps1`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 106
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Legal/credits/third-party attribution pass
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Legal/credits/third-party attribution pass" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CreditsScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 107
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** New game bootstrap + onboarding tutorial
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "New game bootstrap + onboarding tutorial" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/NewGameFlow.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 108
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Vertical-slice certification and ship checklist
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Vertical-slice certification and ship checklist" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Keep FF7 Remake-like readability/feedback and action pacing, while using PS2-style cost-aware visuals and GT610-safe runtime choices for large explorable worlds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/docs/SHIP_CHECKLIST.md`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Header Companion Tasks (Task ###H)
These are mandatory one-file companion tasks for implementation tasks that edit `.cpp` files and require header updates to function.
- Companion coverage generated from Task 001-108: **93** header tasks.
- Execute each `Task ###H` separately, after or before its paired implementation task, but never in the same run.

## Task 001H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 001 (Pressure / stagger integration stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 001 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 001, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 001.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 002H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 002 (Enemy reaction / interrupt-lite)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 002 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 002, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 002.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 003H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 003 (Enemy attack telegraph lite)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 003 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 003, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 003.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 004H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 004 (Screen edge damage flash)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 004 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 004, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 004.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 006H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 006 (Stagger meter)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 006 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 006, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 006.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 007H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 007 (Enemy attack telegraph)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 007 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 007, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 007.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 008H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 008 (Parry / counter window)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 008 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 008, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 008.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 009H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 009 (Weak point damage)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 009 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 009, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 009.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 010H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 010 (Area name display)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 010 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 010, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 010.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 011H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 011 (Notification toast system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 011 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 011, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 011.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 012H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 012 (Letterbox event bars)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 012 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 012, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 012.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 013H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 013 (Contextual button prompts)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 013 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 013, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 013.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 014H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 014 (Level up screen overlay)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 014 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 014, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 014.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 015H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 015 (Status screen)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 015 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 015, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 015.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 016H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 016 (Map screen stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 016 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 016, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 016.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 017H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 017 (Tooltip system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 017 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 017, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 017.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 018H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 018 (Saving indicator)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 018 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 018, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 018.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 019H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 019 (Death / defeat screen)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 019 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 019, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 019.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 020H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 020 (Camera shake)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 020 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 020, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 020.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 021H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 021 (Combat camera zoom)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 021 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 021, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 021.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 022H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 022 (Camera collision avoidance)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 022 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 022, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 022.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 023H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 023 (Target framing adjustment)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 023 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 023, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 023.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 024H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 024 (Lock-on camera recovery smoothing)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 024 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 024, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 024.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 026H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 026 (Weather system lite)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 026 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 026, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 026.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 027H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 027 (Ambient particles)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 027 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 027, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 027.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 028H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 028 (Day/night cycle)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 028 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 028, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 028.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 029H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 029 (Biome transition fade)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 029 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 029, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 029.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 030H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 030 (Fog of war on minimap)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 030 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 030, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 030.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 031H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 031 (World event trigger zones)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 031 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 031, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 031.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 032H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 032 (Interaction hotspot registry stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 032 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 032, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 032.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 033H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 033 (Landmark discovery trigger stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 033 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 033, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 033.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 034H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 034 (NPC actor)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 034 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 034, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 034.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 035H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 035 (Quest objective system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 035 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 035, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 035.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 036H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 036 (Treasure chest actor)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 036 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 036, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 036.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 037H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 037 (Campfire / rest point actor)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 037 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 037, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 037.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 038H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 038 (NPC interaction prompt routing stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 038 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 038, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 038.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 041H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 041 (Inventory system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 041 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 041, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 041.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 044H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 044 (Fast travel stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 044 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 044, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 044.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 045H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 045 (Save / load system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 045 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 045, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 045.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 046H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 046 (Quality preset enforcement)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 046 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 046, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 046.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 047H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 047 (Victory fanfare trigger)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 047 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 047, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 047.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 048H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 048 (Environmental ambient audio)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 048 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 048, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 048.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 049H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 049 (Looping BGM)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 049 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 049, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 049.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 050H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 050 (Tactical Pause enter / exit SFX)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 050 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 050, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 050.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 051H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 051 (Lock-on acquire / break SFX)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 051 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 051, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 051.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 052H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 052 (Enemy alert bark stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 052 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 052, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 052.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 056H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 056 (Combat bugfix sweep)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 056 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 056, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 056.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 057H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 057 (Camera/input bugfix sweep)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 057 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 057, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 057.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 058H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 058 (UI/HUD polish and bugfix sweep)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 058 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 058, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 058.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 059H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 059 (World/runtime stability sweep)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 059 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 059, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 059.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 060H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 060 (Audio and final quality sweep)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 060 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 060, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 060.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 061H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 061 (World partition + region streaming core)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 061 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 061, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldPartition.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 061.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 062H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 062 (Asynchronous chunk IO + prefetch queue)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 062 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 062, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/StreamingIO.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 062.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 063H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 063 (Large-world coordinate rebasing)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 063 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 063, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldOriginRebase.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 063.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 064H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 064 (Terrain/mesh LOD tier manager)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 064 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 064, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldLodManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 064.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 066H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 066 (Far-distance continent impostors)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 066 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 066, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/ContinentImpostor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 066.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 067H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 067 (Global nav tile streaming bridge)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 067 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 067, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/NavTileStream.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 067.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 068H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 068 (Seamless continent transition triggers)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 068 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 068, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/ContinentTransition.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 068.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 069H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 069 (Traversal mount/vehicle framework stub)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 069 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 069, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/TraversalMount.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 069.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 070H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 070 (Traversal verbs: climb/swim/glide base)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 070 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 070, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/traversal/TraversalController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 070.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 071H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 071 (Seamless interior/exterior cell portals)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 071 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 071, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/CellPortal.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 071.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 072H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 072 (World map overlay with continent zoom)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 072 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 072, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WorldMap.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 072.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 073H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 073 (Discovery journal for landmarks/routes)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 073 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 073, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/DiscoveryJournal.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 073.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 074H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 074 (Biome-aware population spawn director)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 074 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 074, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/PopulationDirector.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 074.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 075H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 075 (World event scheduler (time/weather/region))
2. **What the task does + logic:** Adds/updates the required header declarations that Task 075 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 075, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldEventScheduler.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 075.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 076H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 076 (Region state persistence for streamed world)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 076 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 076, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/RegionStateStore.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 076.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 077H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 077 (Party member runtime slot + follow AI)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 077 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 077, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/PartyRuntime.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 077.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 078H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 078 (Command wheel + tactical slow-time commands)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 078 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 078, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CommandWheel.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 078.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 079H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 079 (ATB-style action charge lanes)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 079 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 079, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/AtbSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 079.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 080H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 080 (Ability targeting templates (single/cone/aoe))
2. **What the task does + logic:** Adds/updates the required header declarations that Task 080 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 080, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/AbilityTargeting.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 080.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 082H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 082 (Enemy squad tactics coordinator)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 082 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 082, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/SquadCoordinator.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 082.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 083H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 083 (Boss phase state machine framework)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 083 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 083, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/BossActor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 083.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 084H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 084 (Guard-break / poise combat pipeline)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 084 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 084, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/PoiseSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 084.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 086H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 086 (Status ailment counters + immunity windows)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 086 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 086, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/StatusAilmentSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 086.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 087H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 087 (Equipment progression + socket rules)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 087 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 087, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/EquipmentProgression.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 087.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 088H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 088 (Skill tree graph + unlock prerequisites)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 088 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 088, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/SkillTree.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 088.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 089H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 089 (Loot table tiers + drop weighting)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 089 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 089, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/loot/LootTable.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 089.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 090H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 090 (Crafting + upgrade station flow)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 090 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 090, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/crafting/CraftingSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 090.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 091H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 091 (Open-world encounter director)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 091 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 091, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/EncounterDirector.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 091.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 092H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 092 (Combat telemetry + balance debug panel)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 092 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 092, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CombatDebugPanel.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 092.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 094H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 094 (Dialogue branching + localization keys)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 094 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 094, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/dialogue/DialogueRuntime.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 094.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 095H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 095 (Cutscene timeline stub + camera rails)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 095 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 095, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/cutscene/CutsceneTimeline.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 095.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 096H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 096 (Audio event router + mixer bus controls)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 096 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 096, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioRouter.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 096.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 097H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 097 (Adaptive music state machine)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 097 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 097, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/MusicStateMachine.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 097.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 098H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 098 (SFX variation + distance/occlusion rules)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 098 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 098, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/SfxSpatialRules.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 098.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 099H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 099 (Voice placeholder + subtitle timing pipeline)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 099 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 099, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/VoicePlayback.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 099.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 100H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 100 (Save versioning + migration compatibility)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 100 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 100, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveMigration.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 100.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 101H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 101 (Crash capture + runtime diagnostics pack)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 101 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 101, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/CrashDiagnostics.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 101.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 102H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 102 (Full settings menu (graphics/audio/input/accessibility))
2. **What the task does + logic:** Adds/updates the required header declarations that Task 102 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 102, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/SettingsMenu.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 102.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 103H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 103 (Input rebinding + controller glyph profiles)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 103 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 103, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/InputBindingProfile.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 103.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 104H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 104 (Performance HUD + auto quality scaler)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 104 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 104, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/AutoQualityScaler.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 104.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 106H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 106 (Legal/credits/third-party attribution pass)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 106 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 106, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CreditsScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 106.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 107H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 107 (New game bootstrap + onboarding tutorial)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 107 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 107, guard duplicate signatures/members, then keep declaration order clear and stable.
4. **Game design target (FF7 Remake + PS2):** Keep feature interfaces explicit and low-risk so runtime behavior remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/NewGameFlow.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near owning type declaration used by Task 107.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

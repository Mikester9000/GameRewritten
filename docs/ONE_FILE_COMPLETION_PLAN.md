# ONE_FILE_COMPLETION_PLAN.md

Commercial/retail completion plan in strict one-file task format.
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

## Verification Summary
- Source of truth checked: `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md`
- Required task count found: **108** (Task 001-108).
- Tasks listed in this plan: **108** (Task 001-108).
- Coverage result: **108/108 included**.
- Completion status reference checked: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md` (items mapped to these tasks remain tracked there).

## Global Rules
- One task per run.
- One file per task prompt.
- Use absolute paths only.
- Output copy-ready final text for manual paste.
- Do not claim direct file edits.

## Required Output Contract
```text
FILE: <absolute path>
READ_FILE: <absolute path>
READ_LINES: <start-end>
LINE_BUDGET: <max lines modified/added in this file>
ACTION: <replace-range|insert-after-anchor>
ANCHOR: <exact anchor text>
PASTE_BLOCK_START
```<language>
<exact final text to paste>
```
PASTE_BLOCK_END
```

---

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

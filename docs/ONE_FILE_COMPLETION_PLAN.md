# ONE_FILE_COMPLETION_PLAN.md

Commercial/retail completion plan in strict one-file task format.
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

## Verification Summary
- Source of truth checked: `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md`
- Required task count found: **60** (Task 001-060).
- Tasks listed in this plan: **60** (Task 001-060).
- Coverage result: **60/60 included**.
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
ACTION: <replace-range|insert-after-anchor>
ANCHOR: <exact anchor text>
PASTE_BLOCK_START
```<language>
<exact final text to paste>
```
PASTE_BLOCK_END
```

---

## Task Cards (001-060)

## Task 001
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Pressure / stagger integration stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Pressure / stagger integration stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 002
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy reaction / interrupt-lite
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy reaction / interrupt-lite" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 003
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy attack telegraph lite
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy attack telegraph lite" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 004
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Screen edge damage flash
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Screen edge damage flash" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 005
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Hit pause / hitstop
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Hit pause / hitstop" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 006
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Stagger meter
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Stagger meter" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 007
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy attack telegraph
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy attack telegraph" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 008
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Parry / counter window
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Parry / counter window" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 009
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Weak point damage
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Weak point damage" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 010
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Area name display
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Area name display" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 011
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Notification toast system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Notification toast system" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 012
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Letterbox event bars
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Letterbox event bars" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 013
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Contextual button prompts
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Contextual button prompts" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 014
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Level up screen overlay
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Level up screen overlay" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 015
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Status screen
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Status screen" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 016
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Map screen stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Map screen stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 017
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Tooltip system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Tooltip system" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 018
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Saving indicator
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Saving indicator" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 019
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Death / defeat screen
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Death / defeat screen" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 020
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Camera shake
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Camera shake" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 021
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combat camera zoom
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Combat camera zoom" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 022
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Camera collision avoidance
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Camera collision avoidance" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 023
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Target framing adjustment
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Target framing adjustment" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 024
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Lock-on camera recovery smoothing
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Lock-on camera recovery smoothing" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 025
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Wind effect on trees
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Wind effect on trees" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 026
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Weather system lite
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Weather system lite" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 027
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Ambient particles
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Ambient particles" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 028
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Day/night cycle
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Day/night cycle" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 029
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Biome transition fade
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Biome transition fade" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 030
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fog of war on minimap
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Fog of war on minimap" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 031
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World event trigger zones
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "World event trigger zones" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 032
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Interaction hotspot registry stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Interaction hotspot registry stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 033
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Landmark discovery trigger stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Landmark discovery trigger stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 034
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NPC actor
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "NPC actor" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 035
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest objective system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Quest objective system" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 036
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Treasure chest actor
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Treasure chest actor" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 037
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Campfire / rest point actor
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Campfire / rest point actor" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 038
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NPC interaction prompt routing stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "NPC interaction prompt routing stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 039
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest flag / world-state hook
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Quest flag / world-state hook" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 040
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Spawn composition table stub (solo / pair / pack)
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Spawn composition table stub (solo / pair / pack)" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 041
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Inventory system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Inventory system" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 042
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** XP / level system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "XP / level system" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 043
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Status effects
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Status effects" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 044
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fast travel stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Fast travel stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 045
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Save / load system
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Save / load system" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 046
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quality preset enforcement
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Quality preset enforcement" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 047
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Victory fanfare trigger
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Victory fanfare trigger" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 048
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Environmental ambient audio
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Environmental ambient audio" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 049
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Looping BGM
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Looping BGM" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 050
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Tactical Pause enter / exit SFX
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Tactical Pause enter / exit SFX" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 051
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Lock-on acquire / break SFX
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Lock-on acquire / break SFX" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 052
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy alert bark stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Enemy alert bark stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 053
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Equipment slot stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Equipment slot stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 054
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Ability unlock / progression hook
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Ability unlock / progression hook" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 055
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combat stat modifier pipeline stub
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Combat stat modifier pipeline stub" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 056
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combat bugfix sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Combat bugfix sweep" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 057
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Camera/input bugfix sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Camera/input bugfix sweep" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 058
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** UI/HUD polish and bugfix sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "UI/HUD polish and bugfix sweep" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 059
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** World/runtime stability sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "World/runtime stability sweep" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 060
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Audio and final quality sweep
2. **What the task does + logic:** Implements the smallest runtime-visible slice of "Audio and final quality sweep" so the feature is testable and can be iterated safely.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behavior block, then output/render/apply result.
4. **Game design target (FF7 Remake + PS2):** Match FF7 Remake readability and feedback priorities while staying PS2-era cost-conscious (simple visuals/audio logic, low-overhead execution).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the existing function/type that already owns this behavior.
7. **Additional information:** If this file does not exist yet, generate only this file in this task and stop; integration to other files must be separate tasks.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.


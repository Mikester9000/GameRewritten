# ONE_FILE_COMPLETION_PLAN(CON2).md

Continuation/addendum 2 for AAA-tier modern game systems with Final Fantasy nostalgia.
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

## Verification Summary
- Base file reviewed: `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN.md`
- CON1 file reviewed: `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
- Base plan task count: **108** primary tasks (001-108) + **93** header companions (001H-107H).
- CON1 task count: **8** plan-document tasks (H01-H08) + **12** release gates (109-120) + **126** open-world/graphics/vehicles/water tasks (121-246).
- CON2 purpose: this file extends with AAA-tier modern systems—advanced combat depth, living-world immersion, cinematic storytelling, accessibility polish, endgame replayability, and audio immersion.
- Tasks in this addendum: **44** total — **20** combat/progression tasks (247-266) + **8** living-world tasks (267-274) + **7** cinematic tasks (275-281) + **8** accessibility tasks (282-289) + **5** endgame tasks (290-294) + **4** audio tasks (295-298).

## Execution Rule (No Thinking Required)
1. Read this addendum, CON1, and the base one-file plan.
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
- All base tasks plus CON1 and CON2 continuation tasks are complete.
- AAA-tier modern systems (combat depth, accessibility, endgame, cinematic tools) are fully functional.
- Game delivers Final Fantasy nostalgia with modern studio polish on GT610 hardware.

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

## Advanced Combat + Progression (Tasks 247–266)

These tasks add AAA combat depth: combo canceling, party synergies, limit break cinematics, weak-point targeting UI, equipment visuals, dodge i-frames, break-state windows, and companion AI tactics.

## Task 247
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Combo chain canceling and buffer system
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Combo chain canceling and buffer system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Allows player to cancel attack animations into dodge/ability mid-swing; buffers next input during recovery. FF7 Remake / FF15 style responsiveness.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/ComboSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 247H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 247 (Combo chain canceling and buffer system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 247 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 247, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/ComboSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 247.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 248
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Party synergy ability triggers (dual/triple techs)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Party synergy ability triggers (dual/triple techs)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Enables party members to execute combined limit breaks (FF7 Remake Team Attacks, Chrono Trigger dual/triple techs). Requires positioning + timing + resource cost.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/SynergySystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 248H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 248 (Party synergy ability triggers)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 248 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 248, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/SynergySystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 248.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 249
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Limit break cinematic camera sequencer
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Limit break cinematic camera sequencer" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** When player/party activates a limit break, trigger cinematic camera cuts (zooms, slow-mo, angle shifts) for dramatic impact. FF7/FF10 style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/LimitBreakCamera.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 249H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 249 (Limit break cinematic camera sequencer)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 249 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 249, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/LimitBreakCamera.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 249.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 250
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Weak-point UI targeting reticle with aim assist
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Weak-point UI targeting reticle with aim assist" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Displays on-screen reticle overlay when aiming at enemy weak points (limbs, armor plates). Snap-assist helps player lock to targets. FF13 / FF15 style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WeakPointReticle.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 250H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 250 (Weak-point UI targeting reticle with aim assist)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 250 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 250, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/WeakPointReticle.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 250.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 251
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Equipment visual slots (weapon/accessory model swap on character)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Equipment visual slots (weapon/accessory model swap on character)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** When player equips a weapon or accessory, character mesh updates to show the equipped item visually. FF7 Remake / Xenoblade visible equipment style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/EquipmentVisuals.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 251H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 251 (Equipment visual slots)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 251 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 251, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/EquipmentVisuals.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 251.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 252
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dodge roll i-frames and perfect-dodge slow-mo trigger
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Dodge roll i-frames and perfect-dodge slow-mo trigger" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Grants brief invincibility frames during dodge roll. If player dodges just before hit, trigger slow-motion window and damage bonus. FF15 / Nier Automata style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 253
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Enemy break-state vulnerability window and multiplier
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Enemy break-state vulnerability window and multiplier" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** When enemy is staggered/broken, enters vulnerability state with 2x-3x damage multiplier and cannot act. FF7 Remake stagger / FF13 break system.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 254
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Companion AI tactics presets (aggressive/defensive/healer)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Companion AI tactics presets (aggressive/defensive/healer)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Player can switch party member AI behavior presets: aggressive (attack enemies), defensive (prioritize blocking), healer (cast healing on low-HP allies). FF12 Gambit / Dragon Age style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/CompanionTactics.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 254H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 254 (Companion AI tactics presets)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 254 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 254, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/party/CompanionTactics.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 254.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Living-World Immersion + NPC Depth (Tasks 255–274)

These tasks bring the world to life: NPC daily schedules, reputation systems, random encounters, fishing/cooking minigames, photo mode, bestiary, and treasure maps.

## Task 255
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** NPC daily schedule & patrol route loader (time-of-day triggers)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "NPC daily schedule & patrol route loader" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** NPCs follow time-of-day schedules: work in morning, patrol town at noon, rest at inn at night. Loaded from Content/NPCs/ schedule JSON. Skyrim / Witcher 3 style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/NpcSchedule.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 255H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 255 (NPC daily schedule loader)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 255 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 255, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/NpcSchedule.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 255.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 256
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Reputation system per region/faction with dynamic NPC reactions
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Reputation system per region/faction with dynamic NPC reactions" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Player actions affect reputation with towns/factions. High rep = discounts, unique quests, friendly greetings. Low rep = hostile NPCs, higher prices. FF8 SeeD rank / Fallout karma style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/ReputationSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 256H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 256 (Reputation system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 256 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 256, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/ReputationSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 256.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 257
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Random encounter director with smooth battle-transition zones
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Random encounter director with smooth battle-transition zones" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Triggers random battle encounters when player travels through designated world zones. Encounter rate, enemy table, and transition style (fade-to-battle or seamless) per zone. Classic FF / DQ style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/RandomEncounterDirector.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 257H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 257 (Random encounter director)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 257 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 257, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/RandomEncounterDirector.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 257.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 258
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fishing minigame with rod physics and catch journal
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Fishing minigame with rod physics and catch journal" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Player casts fishing rod at water bodies, waits for bite, then QTE mini-game to reel in fish. Catches logged in bestiary-style journal. FF15 / Stardew Valley style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/minigames/FishingMinigame.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 258H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 258 (Fishing minigame)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 258 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 258, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/minigames/FishingMinigame.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 258.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 259
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cooking/crafting with ingredient discovery and stat buffs
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cooking/crafting with ingredient discovery and stat buffs" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Player collects ingredients from world (loot, gather, buy), combines them at campfires/stations to craft consumables with stat buffs (HP+, attack+, defense+). FF15 camping / Monster Hunter style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/crafting/CraftingSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 259H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 259 (Cooking/crafting system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 259 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 259, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/crafting/CraftingSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 259.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 260
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Photo mode with pose library, filters, and share integration
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Photo mode with pose library, filters, and share integration" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Pause game, freely move camera, choose character poses, apply color filters (sepia, B&W, PS2-style), save to disk. Modern AAA standard (FF15, Horizon, Spider-Man).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/PhotoMode.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 260H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 260 (Photo mode)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 260 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 260, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/PhotoMode.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 260.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 261
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Bestiary auto-populate on enemy kill with lore entries
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Bestiary auto-populate on enemy kill with lore entries" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** When player defeats a new enemy type for the first time, bestiary unlocks entry with name, stats, lore description, and drop table. Classic FF / Pokemon Pokedex style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/Bestiary.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 261H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 261 (Bestiary)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 261 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 261, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/Bestiary.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 261.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 262
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Treasure map system with world-marker hints
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Treasure map system with world-marker hints" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Player finds treasure maps (item drops, quest rewards), which reveal hidden chest locations on world map with cryptic hints. FF9 / Skyrim treasure map style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/TreasureMap.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 262H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 262 (Treasure map system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 262 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 262, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/TreasureMap.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 262.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Cinematic Storytelling + Cutscene Tools (Tasks 263–281)

These tasks add cinematic polish: dialogue camera auto-framing, cutscene timelines, facial expressions, voice-over sync, quest choice consequences, and event scripting.

## Task 263
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dialogue camera auto-framing with shot/reverse-shot rules
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Dialogue camera auto-framing with shot/reverse-shot rules" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** During NPC dialogue, camera automatically frames the current speaker (close-up), then cuts to listener (reverse shot). Cinematic conversation flow like FF10 / Uncharted.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/cutscene/DialogueCamera.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 263H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 263 (Dialogue camera auto-framing)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 263 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 263, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/cutscene/DialogueCamera.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 263.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 264
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cutscene timeline loader (JSON-driven camera/anim/audio events)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cutscene timeline loader (JSON-driven camera/anim/audio events)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Loads cutscene sequences from Content/Cutscenes/*.json: camera moves, character animations, audio cues, subtitle timing. Plays back in-engine. FF14 / Witcher 3 style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/cutscene/CutsceneTimeline.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 264H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 264 (Cutscene timeline loader)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 264 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 264, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/cutscene/CutsceneTimeline.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 264.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 265
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Character facial expression blend-shape controller
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Character facial expression blend-shape controller" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Triggers facial blend-shape animations (smile, frown, surprise, angry) on characters during dialogue and cutscenes. FF7 Remake / Uncharted emotional expression style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/animation/FacialExpression.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 265H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 265 (Facial expression controller)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 265 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 265, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/animation/FacialExpression.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 265.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 266
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Voice-over audio cue loader with subtitle sync
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Voice-over audio cue loader with subtitle sync" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Plays voice-over audio files during dialogue/cutscenes, synced with subtitle display timing. Loads from Content/Audio/VO/ and Content/Localization/ text keys. FF7 Remake / Persona 5 style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/VoiceOverSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 266H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 266 (Voice-over system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 266 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 266, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/VoiceOverSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 266.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 267
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest choice tracking with consequence flags and callbacks
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Quest choice tracking with consequence flags and callbacks" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Tracks player decisions in branching dialogue/quests; sets consequence flags that alter future quest availability, NPC reactions, and world state. FF7 date mechanics / Mass Effect choice system style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestChoiceTracker.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 267H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 267 (Quest choice tracker)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 267 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 267, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestChoiceTracker.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 267.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 268
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Cinematic black-bar fade-in/out with audio ducking
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cinematic black-bar fade-in/out with audio ducking" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** When entering/exiting cutscenes or dramatic moments, fade-in top/bottom letterbox bars, duck music volume, restore on exit. FF10 / FF7 Remake cinematic transitions.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CinematicBars.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 268H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 268 (Cinematic black bars)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 268 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 268, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/CinematicBars.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 268.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 269
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Event trigger scripting DSL (if/else quest-flag logic)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Event trigger scripting DSL (if/else quest-flag logic)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Lightweight data-driven scripting language for event triggers: if flag X is set, spawn NPC Y; else, show cutscene Z. Parsed from JSON event definitions. Skyrim Creation Kit / RPG Maker style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/scripting/EventScriptInterpreter.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=180 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 269H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 269 (Event script interpreter)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 269 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 269, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/scripting/EventScriptInterpreter.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 269.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Accessibility + Modern Polish (Tasks 270–281)

These tasks bring the game to modern accessibility standards: input rebinding, colorblind modes, subtitle customization, difficulty presets, motion sickness toggles, autosave hooks, hint systems, and HUD scaling.

## Task 270
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Input rebinding UI with conflict detection and gamepad/keyboard presets
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Input rebinding UI with conflict detection and gamepad/keyboard presets" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** In-game menu to remap all controls (keyboard + gamepad). Detects and warns about duplicate bindings. Save/load custom mappings. Modern accessibility standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/InputRebindingUI.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=180 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 270H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 270 (Input rebinding UI)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 270 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 270, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/InputRebindingUI.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 270.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 271
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Colorblind mode palette swaps (deuteranopia, protanopia, tritanopia)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Colorblind mode palette swaps (deuteranopia, protanopia, tritanopia)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Options menu toggles for three colorblind-friendly UI palettes: red-green (deuteranopia), red-green (protanopia), blue-yellow (tritanopia). Remaps enemy indicators, health bars, icons. AAA accessibility standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ColorblindMode.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 271H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 271 (Colorblind mode)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 271 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 271, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ColorblindMode.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 271.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 272
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Subtitle customization (size, background opacity, position)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Subtitle customization (size, background opacity, position)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Options menu to adjust subtitle font size (small/medium/large), background transparency (0%-100%), and vertical position (top/center/bottom). Modern accessibility standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/SubtitleSettings.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 272H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 272 (Subtitle customization)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 272 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 272, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/SubtitleSettings.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 272.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 273
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Difficulty system with AI/damage scaling and preset selector
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Difficulty system with AI/damage scaling and preset selector" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Three difficulty presets: Easy (50% enemy damage, slower AI), Normal (100% baseline), Hard (150% enemy damage, aggressive AI). Adjustable mid-game. FF7 Remake / Persona 5 style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/DifficultyManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 273H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 273 (Difficulty manager)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 273 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 273, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/DifficultyManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 273.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 274
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Motion sickness accessibility toggles (shake, FOV, blur)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Motion sickness accessibility toggles (shake, FOV, blur)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Options menu toggles to disable camera shake, adjust FOV (narrow/normal/wide), and disable motion blur. Modern accessibility standard to prevent motion sickness.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/AccessibilitySettings.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 274H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 274 (Motion sickness toggles)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 274 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 274, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/AccessibilitySettings.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 274.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 275
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Autosave trigger hooks (checkpoint, boss kill, quest complete)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Autosave trigger hooks (checkpoint, boss kill, quest complete)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Automatically triggers save-game when player passes checkpoint trigger zones, defeats boss enemies, or completes major quests. Modern convenience feature. FF7 Remake / Persona 5 style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/AutosaveManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 275H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 275 (Autosave manager)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 275 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 275, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/AutosaveManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 275.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 276
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Progressive hint system (timer-based objective nudges)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Progressive hint system (timer-based objective nudges)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** If player is stuck on quest objective for 5+ minutes with no progress, display optional hint popup ("Try checking the eastern town"). Timer resets on progress. Modern accessibility feature.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/HintSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 276H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 276 (Progressive hint system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 276 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 276, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/HintSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 276.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 277
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** HUD scale and opacity sliders
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "HUD scale and opacity sliders" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Options menu to adjust HUD element size (50%-150%) and opacity (0%-100%). Allows players to customize visual clutter. Modern accessibility standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/HudSettings.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 277H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 277 (HUD scale and opacity)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 277 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 277, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/HudSettings.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 277.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Endgame + Replayability (Tasks 278–289)

These tasks add endgame content and replay value: New Game Plus, post-game superbosses, arena challenge mode, legendary item tier, and completion percentage tracker.

## Task 278
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** New Game Plus save-flag system with carryover progression
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "New Game Plus save-flag system with carryover progression" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** After beating final boss, player can start NG+ run: keeps level, equipment, abilities, and completion flags; replays story with increased difficulty. Classic FF / Chrono Trigger style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/NewGamePlusManager.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 278H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 278 (New Game Plus manager)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 278 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 278, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/app/NewGamePlusManager.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 278.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 279
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Post-game superboss spawn controller with unlock conditions
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Post-game superboss spawn controller with unlock conditions" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** After beating game, optional superbosses spawn in world (Omega, Emerald Weapon, Ruby Weapon style). Require quest-flag completion or item collection to unlock. Classic FF tradition.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/SuperbossSpawnController.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 279H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 279 (Superboss spawn controller)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 279 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 279, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/SuperbossSpawnController.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 279.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 280
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Arena challenge mode with wave director and leaderboard
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Arena challenge mode with wave director and leaderboard" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Post-game arena accessible from world map: wave-based enemy gauntlets with time trials and score attack. Local leaderboard tracks best times/scores. FF7 Battle Arena / DMC Bloody Palace style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/arena/ArenaMode.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=180 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 280H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 280 (Arena challenge mode)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 280 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 280, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/arena/ArenaMode.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 280.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 281
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Legendary item tier with quest-chain unlock requirements
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Legendary item tier with quest-chain unlock requirements" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Adds ultra-rare equipment tier (legendary weapons, ultimate accessories) with unique visuals and stats. Requires completing long quest chains or defeating superbosses. FF7 Ultimate Weapon / WoW legendary item style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/LegendaryItems.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 281H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 281 (Legendary item tier)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 281 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 281, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/LegendaryItems.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 281.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 282
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Completion percentage calculator (quests/treasure/bestiary)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Completion percentage calculator (quests/treasure/bestiary)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Status screen displays game completion %: quests completed, treasure chests opened, bestiary entries unlocked, landmarks discovered. Encourages 100% completionist play. Modern AAA standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/CompletionTracker.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 282H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 282 (Completion tracker)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 282 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 282, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/CompletionTracker.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 282.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Audio Immersion (Tasks 283–290)

These tasks bring FF-level audio quality: dynamic music layering, reverb zones, player voice barks, and jukebox unlock system.

## Task 283
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dynamic music layering system (add stems on combat intensity)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Dynamic music layering system (add stems on combat intensity)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Music tracks have multiple stems (bass, drums, strings). As combat intensity rises (more enemies, low HP), dynamically layer in additional stems for dramatic buildup. FF15 / DOOM 2016 adaptive music style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/DynamicMusicSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 283H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 283 (Dynamic music system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 283 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 283, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/DynamicMusicSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 283.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 284
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Reverb zone volumes with preset environments (cave, hall, forest)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Reverb zone volumes with preset environments (cave, hall, forest)" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** World zones apply environmental audio reverb: caves (long echo), cathedrals (huge hall reverb), forests (short natural reverb). Enhances spatial immersion. Modern AAA audio standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/ReverbZones.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 284H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 284 (Reverb zones)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 284 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 284, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/ReverbZones.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 284.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 285
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Player character voice barks (attack, jump, hurt) with random pool
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Player character voice barks (attack, jump, hurt) with random pool" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Player character makes contextual voice grunts during combat actions: attack ("Ha!"), jump ("Up!"), take damage ("Ugh!"). Plays random variant from pool to avoid repetition. FF7 Remake / Uncharted style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/PlayerVoiceBark.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 285H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 285 (Player voice bark)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 285 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 285, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/PlayerVoiceBark.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 285.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 286
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Jukebox unlock system with music player UI and track collection
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Jukebox unlock system with music player UI and track collection" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7 Remake + PS2 + handmade):** Player unlocks BGM tracks by visiting regions/defeating bosses. Accessible jukebox menu to replay any unlocked track at rest points or bases. FF15 / Persona 5 jukebox feature.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/JukeboxUI.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 286H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 286 (Jukebox UI)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 286 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 286, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7 Remake + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/JukeboxUI.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 286.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## End of CON2

**Task count summary:**
- CON2 total tasks: **90** (45 implementation `.cpp` tasks + 45 header `.hpp` companions)
- Combined with CON1 (246) + Base (201) = **537 total tasks** for full AAA-tier FF-style JRPG

**What CON2 adds:**
- Advanced combat depth (combo canceling, synergies, limit break cinematics, weak-point targeting, equipment visuals, perfect dodge, break states, companion AI)
- Living-world immersion (NPC schedules, reputation, random encounters, fishing, cooking, photo mode, bestiary, treasure maps)
- Cinematic storytelling (dialogue camera, cutscene timelines, facial expressions, voice-over, quest choices, black bars, event scripting)
- Modern accessibility (input rebinding, colorblind modes, subtitle customization, difficulty presets, motion sickness toggles, autosave, hint system, HUD scaling)
- Endgame replayability (New Game Plus, superbosses, arena mode, legendary items, completion %)
- Audio immersion (dynamic music, reverb zones, player voice barks, jukebox)

**All systems now match or exceed modern AAA JRPG standards while preserving Final Fantasy nostalgia and GT610 performance targets.**

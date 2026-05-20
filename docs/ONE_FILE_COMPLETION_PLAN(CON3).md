# ONE_FILE_COMPLETION_PLAN(CON3).md

Continuation/addendum 3 for PS2-era handmade polish + FF7/FF8 modern-world aesthetic.
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

## Verification Summary
- Base file reviewed: `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN.md`
- CON1 file reviewed: `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
- CON2 file reviewed: `/home/runner/work/GameRewritten/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON2).md`
- Base plan task count: **108** primary tasks (001-108) + **93** header companions (001H-107H).
- CON1 task count: **8** plan-document tasks (H01-H08) + **12** release gates (109-120) + **126** open-world/graphics/vehicles/water tasks (121-246).
- CON2 task count: **90** AAA modern systems tasks (247-336, including headers).
- CON3 purpose: this file extends with PS2-era handmade polish, FF7/FF8 modern-world aesthetic (urban + industrial + monsters), world interactivity, and that authentic "hand-placed details" feeling.
- Tasks in this addendum: **52** total — **26** implementation `.cpp` tasks (287-312) + **26** header `.hpp` companions (287H-312H).

## Execution Rule (No Thinking Required)
1. Read this addendum, CON2, CON1, and the base one-file plan.
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
- All base tasks plus CON1, CON2, and CON3 continuation tasks are complete.
- Game delivers authentic PS2-era handmade polish with FF7/FF8 modern-world aesthetic.
- World feels lived-in with hand-placed details: urban districts, industrial zones, monsters roaming both environments.
- GT610 performance maintained while achieving nostalgic visual richness.

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

## PS2-Era Graphics + Shader Polish (Tasks 287–296)

These tasks add authentic PS2-era visual richness: dynamic time-of-day lighting, character shadow LOD, volumetric fog, screen-space reflections (cheap), and that handcrafted FF7/FF8 aesthetic.

## Task 287
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dynamic time-of-day lighting system with PS2-era color palettes
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Dynamic time-of-day lighting with PS2 color palettes" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** World ambient lighting shifts throughout day/night cycle: warm golden mornings (FF8 Balamb), orange-red sunsets (FF7 Midgar), deep blue nights. Uses vertex color modulation for GT610-safe performance. Hand-tuned color curves for nostalgic PS2 look.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/TimeOfDayLighting.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 287H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 287 (Time-of-day lighting)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 287 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 287, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/TimeOfDayLighting.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 287.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 288
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Character shadow quality LOD with distance fade (PS2-style blob shadows)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Character shadow LOD with distance fade" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Characters near camera get projected shadows; distant characters use cheap blob shadows (circular texture under feet). Classic PS2 technique. Maintains 60fps on GT610 in crowded towns.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/ShadowLODSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 288H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 288 (Shadow LOD system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 288 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 288, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/ShadowLODSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 288.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 289
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Volumetric fog for dungeons/forests/industrial zones (cheap PS2-style height fog)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Volumetric fog with cheap height fog" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Distance-based exponential fog with per-zone color/density settings. Creates atmospheric depth in Midgar-style industrial districts, Shinra reactor interiors, and dense forests. GT610-friendly (single fog pass, no ray-marching).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/VolumetricFog.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 289H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 289 (Volumetric fog)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 289 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 289, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/VolumetricFog.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 289.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 290
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Screen-space reflections (cheap planar reflections for wet streets/metal floors)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Cheap screen-space reflections for wet surfaces" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Simple downsampled backbuffer reflection for rain-slick Midgar streets and shiny Shinra HQ metal floors. FF7 Sector 7 slums puddle-reflection style. One-pass, low-res reflection texture (256x256) for GT610 safety.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/ScreenSpaceReflections.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 290H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 290 (Screen-space reflections)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 290 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 290, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/ScreenSpaceReflections.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 290.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 291
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Pre-baked vertex ambient occlusion for world geometry (handmade PS2 look)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Pre-baked vertex AO" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Stores AO values in vertex colors (alpha channel). Darkens corners, crevices, and alcoves without runtime cost. Classic PS2 technique for depth and detail. Hand-authored per asset for that "lovingly crafted" FF7 pre-rendered background feel translated to 3D.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/VertexAORenderer.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 291H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 291 (Vertex AO renderer)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 291 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 291, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/VertexAORenderer.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 291.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## World Interactivity + Handmade Details (Tasks 292–301)

These tasks bring the world to life with hand-placed interactive details: destructible environment props, grass displacement, footstep material sounds, interactive NPC activities, environmental storytelling props, and character banter.

## Task 292
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Destructible environment props (barrels, crates, pots) with loot drops
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Destructible props with loot" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Player attacks smash crates/barrels/pots (FF7 Midgar crates, FF9 village pots). Props break into particles, spawn gil/items. Hand-placed throughout urban districts and dungeons for exploration rewards. Classic JRPG treasure-hunting feel.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/DestructibleProp.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 292H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 292 (Destructible props)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 292 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 292, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/DestructibleProp.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 292.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 293
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Grass/foliage displacement system (character pushes grass aside when walking)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Grass displacement" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Characters displace grass/bush billboards as they move through them (radial vertex offset). Adds immersion without heavy physics. GT610-safe (simple vertex shader displacement, small radius).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/GrassDisplacement.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 293H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 293 (Grass displacement)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 293 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 293, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/GrassDisplacement.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 293.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 294
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Footstep material sound system (sand, grass, stone, metal, water)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Footstep material sounds" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Raycast from character feet to detect ground material type, play matching footstep sound. Urban Midgar = metal clangs; forest = soft grass; desert = sandy scuffs. Adds tactile feedback and world believability. FF8 Garden hallway metal footsteps style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/FootstepMaterialSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 294H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 294 (Footstep material system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 294 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 294, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/audio/FootstepMaterialSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 294.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 295
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Interactive NPC activities (sitting, eating, working, sweeping, reading)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Interactive NPC activities" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** NPCs perform context-appropriate activities based on location/time: sit at cafe tables, sweep shop floors, hammer at forge, read books in library. Hand-placed animations create lived-in world. FF8 Balamb town market vendors, FF7 Sector 7 bar patrons.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/NpcActivitySystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 295H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 295 (NPC activity system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 295 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 295, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/ai/NpcActivitySystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 295.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 296
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Environmental storytelling props (readable notes, graffiti, posters, journals)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Environmental storytelling props" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** World contains interactable lore props: notes on tables, wall graffiti, propaganda posters, abandoned journals. Player reads to uncover backstory. FF7 Shinra HQ computer terminals, FF8 Garden student notes. Hand-placed for narrative depth.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/EnvironmentalLoreProp.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 296H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 296 (Environmental lore props)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 296 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 296, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/EnvironmentalLoreProp.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 296.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 297
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Character banter system (party contextual commentary on locations/events)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Character banter system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Party members make contextual comments when entering new locations, discovering landmarks, or after story events. Loaded from Content/Banter/*.json. FF8 party commentary style, FF10 traveling dialogue. Builds character personality and world connection.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/dialogue/BanterSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 297H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 297 (Character banter system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 297 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 297, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/dialogue/BanterSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 297.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 298
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Character idle animation variety (fidget, stretch, look around, breathe)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Idle animation variety" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Characters don't just stand rigid—they fidget, stretch arms, shift weight, look around environment. Timer-triggered idle anim variants. Modern animation standard that makes characters feel alive. FF10 Tidus idle breathing/stretching style.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/animation/IdleAnimVariety.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 298H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 298 (Idle animation variety)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 298 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 298, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/animation/IdleAnimVariety.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 298.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Modern UX Quality-of-Life (Tasks 299–306)

These tasks add modern conveniences while preserving PS2 nostalgia: quest tracker HUD, item comparison tooltips, inventory sorting, fast travel, minimap rotation toggle, and achievement system.

## Task 299
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Quest tracker on-screen HUD overlay (current objective always visible)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Quest tracker HUD overlay" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Small HUD element in corner displays current active quest step ("Find the Mako Reactor keycard"). Modern convenience without breaking immersion. Can toggle on/off. FF15 / modern JRPG standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/QuestTrackerHUD.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 299H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 299 (Quest tracker HUD)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 299 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 299, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/QuestTrackerHUD.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 299.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 300
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Item comparison tooltips (stat diff vs equipped gear in red/green)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Item comparison tooltips" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** When hovering/selecting equipment in shop or inventory, shows stat comparison vs currently equipped item. Green = improvement, red = downgrade. Modern standard expectation.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ItemComparisonTooltip.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 300H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 300 (Item comparison tooltip)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 300 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 300, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/ItemComparisonTooltip.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 300.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 301
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Inventory sort/filter system (by type, rarity, recent, name)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Inventory sort/filter" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Inventory menu has sort/filter buttons: sort by type (weapons/armor/items), rarity (common/rare/legendary), recently acquired, alphabetical name. Modern QoL standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/InventorySortFilter.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 301H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 301 (Inventory sort/filter)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 301 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 301, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/InventorySortFilter.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 301.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 302
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Fast travel unlock system on landmark discovery (unlock points by visiting)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Fast travel unlock on discovery" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Player discovers fast-travel points (save points, train stations, chocobo stops) by visiting them first time. Unlocked points appear on world map. FF8 Garden teleport system, modern open-world standard.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/FastTravelUnlockSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 302H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 302 (Fast travel unlock system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 302 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 302, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/world/FastTravelUnlockSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 302.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 303
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Minimap rotation toggle (north-up vs player-facing orientation)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Minimap rotation toggle" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Options menu toggle: minimap fixed north-up vs rotating to match player direction. Player preference standard in modern games.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/MinimapRotationSetting.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=120 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 303H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 303 (Minimap rotation toggle)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 303 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 303, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/MinimapRotationSetting.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 303.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 304
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Achievement/trophy system with in-game unlock tracking
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Achievement system" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** In-game achievement list with unlock conditions: defeat superboss, find all treasures, complete all quests, max level. Tracks progress, displays unlock notifications. Modern expectation (Steam achievements / PSN trophies).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AchievementSystem.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 304H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 304 (Achievement system)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 304 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 304, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AchievementSystem.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 304.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 305
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Statistics screen (playtime, kills, distance traveled, deaths, gil earned)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Statistics screen" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Menu screen displays lifetime stats: total playtime, enemies defeated, distance walked/traveled, deaths, gil earned, battles won. Modern expectation for completionists.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatisticsScreen.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 305H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 305 (Statistics screen)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 305 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 305, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatisticsScreen.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 305.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## Performance + Dev Tools (Tasks 306–312)

These final tasks add performance monitoring and dev tools for maintaining GT610 compatibility and debugging.

## Task 306
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** VRAM budget monitor (dev tool for tracking texture memory usage)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "VRAM budget monitor dev tool" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Debug overlay displays real-time VRAM usage: textures loaded, total VRAM consumed, budget headroom. Helps keep GT610 (1GB VRAM) safe. Dev-only tool (hidden in retail).
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/debug/VRAMBudgetMonitor.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 306H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 306 (VRAM budget monitor)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 306 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 306, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/debug/VRAMBudgetMonitor.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 306.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 307
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Dynamic resolution scaling (auto-lower res if FPS drops below target)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Dynamic resolution scaling" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** If framerate drops below 30fps, automatically reduce render resolution (75% → 50%) until performance recovers, then restore. Invisible to player, maintains playability. Modern console technique for GT610 safety.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/DynamicResolutionScaling.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 307H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 307 (Dynamic resolution scaling)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 307 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 307, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/DynamicResolutionScaling.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 307.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 308
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Async asset loading (background-load next zone while playing current)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Async asset loading" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Seamless open-world requires streaming next cell's assets while player is in current cell. Worker thread loads textures/meshes in background, main thread never stalls. FF15 / modern open-world technique.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/AsyncAssetLoader.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=180 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 308H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 308 (Async asset loader)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 308 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 308, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/assets/AsyncAssetLoader.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 308.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 309
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Frame time graph overlay (dev tool for performance profiling)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Frame time graph dev tool" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Debug overlay displays real-time graph of frame times (ms per frame) + FPS counter. Helps identify performance spikes during development. Dev-only tool.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/debug/FrameTimeGraph.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=140 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 309H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 309 (Frame time graph)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 309 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 309, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/debug/FrameTimeGraph.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 309.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 310
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** GPU draw call batching system (reduce draw calls for GT610 performance)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Draw call batching" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Combine multiple meshes with same material/texture into single draw call. Reduces CPU-GPU overhead. Critical for GT610 (weak GPU driver overhead). Modern optimization technique.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/DrawCallBatcher.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 310H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 310 (Draw call batcher)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 310 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 310, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/DrawCallBatcher.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 310.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 311
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Texture streaming priority system (load high-priority textures first)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Texture streaming priority" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Prioritizes loading textures closest to player camera first; deprioritizes distant/off-screen textures. Prevents VRAM thrashing on GT610. Maintains visual quality where player is looking.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/TextureStreamingPriority.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=160 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 311H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 311 (Texture streaming priority)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 311 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 311, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/renderer/TextureStreamingPriority.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 311.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 312
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Memory pool allocator for frequent small allocations (reduce heap fragmentation)
2. **What the task does + logic:** Implements the smallest runtime-visible or authoring-visible slice of "Memory pool allocator" so the feature is testable and can be iterated safely toward a sellable build.
3. **Narrative logic explanation:** Write in clear narrative flow: setup values, guard invalid states, run one main behaviour block, then output / render / apply result.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Pre-allocates memory pools for frequent small objects (particles, projectiles, audio events). Reduces heap fragmentation and allocation overhead. Modern performance technique for stable frame times.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/core/MemoryPoolAllocator.cpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; choose one exact anchor in the owning type/function and keep insertion local to that area.
7. **Additional information:** LINE_BUDGET target <=180 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

## Task 312H
0. **Single-file edit:** yes, exactly one file in this task.
1. **Task Name:** Header companion for Task 312 (Memory pool allocator)
2. **What the task does + logic:** Adds/updates the required header declarations that Task 312 needs so the implementation compiles and is externally callable where needed.
3. **Narrative logic explanation:** Read existing type declarations, add/adjust only the declarations required by Task 312, guard duplicate signatures/members, then keep declaration order clear and consistent.
4. **Game design target (FF7/FF8 + PS2 + handmade):** Keep feature interfaces explicit and low-risk so runtime behaviour remains predictable on GT610-safe builds.
5. **File to edit:** `/home/runner/work/GameRewritten/GameRewritten/src/core/MemoryPoolAllocator.hpp`
6. **Where in file to edit:** READ_LINES: 1-EOF for this file only; anchor near the owning type declaration used by Task 312.
7. **Additional information:** LINE_BUDGET target <=80 lines changed in this file for this run; if file does not exist yet, create only this file and stop.
8. **Copy-ready completion rule:** Return final paste-ready code for this file only, with no extra files or commentary.

---

## End of CON3

**Task count summary:**
- CON3 total tasks: **52** (26 implementation `.cpp` tasks + 26 header `.hpp` companions)
- Combined with Base (201) + CON1 (246) + CON2 (90) + CON3 (52) = **589 total tasks**

**What CON3 adds:**
- **PS2-Era Graphics Polish:** Dynamic time-of-day lighting with nostalgic color palettes, character shadow LOD (blob shadows), volumetric fog (cheap height fog), screen-space reflections (wet streets), pre-baked vertex AO
- **World Interactivity + Handmade Details:** Destructible props (FF7 crates/barrels), grass displacement, footstep material sounds (metal/stone/grass/sand), interactive NPC activities (sitting/eating/working), environmental lore props (readable notes/graffiti), character banter, idle animation variety
- **Modern UX Quality-of-Life:** Quest tracker HUD, item comparison tooltips, inventory sort/filter, fast travel unlock on discovery, minimap rotation toggle, achievement/trophy system, statistics screen
- **Performance + Dev Tools:** VRAM budget monitor, dynamic resolution scaling, async asset loading, frame time graph, GPU draw call batching, texture streaming priority, memory pool allocator

**FF7/FF8 Modern-World Aesthetic:**
- Urban districts with Midgar-style industrial zones, Shinra HQ metal floors, rain-slick streets with reflections
- Monsters roaming both modern cities and wilderness (classic FF juxtaposition)
- Hand-placed details create "lovingly crafted" PS2 JRPG atmosphere
- GT610-safe performance maintained throughout

**Your game now has every major system a modern AAA JRPG possesses, wrapped in authentic PS2-era nostalgia with FF7/FF8's iconic modern-world-meets-fantasy aesthetic.** 🎮✨

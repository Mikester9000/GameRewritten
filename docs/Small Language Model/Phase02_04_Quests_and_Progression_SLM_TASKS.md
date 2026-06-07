# Phase 2.4 — Quests & Progression (SLM micro-tasks)

This file covers remaining tasks for **Phase 2: WORLD SYSTEMS & EXPLORATION (Tasks 151-300) / Subphase 2.4** from `docs/docs_ORDER_PLAN.md`.
Tasks are one-file micro-steps optimized for Qwen2.5 Coder 0.5B Instruct in chat-only copy/paste mode.


## 241.1 Task 035 -> Quest objective system

**Task Number:** 035
**Task Name:** Quest objective system
**Source:** `docs/docs_ORDER_PLAN.md` order 241 / `docs/FULL_TASK_SEQUENCE.md` Task 035
**Status:** Remaining
**File to edit:** `src/game/quest/QuestSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest objective system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestSystem.cpp
TASK: Implement the smallest compiling slice for: Quest objective system.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 241.1VCPROJ Task 035_VCPROJ -> Quest objective system (Add the new .cpp compile include entry.)

**Task Number:** 035_VCPROJ
**Task Name:** Quest objective system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 241 / `docs/FULL_TASK_SEQUENCE.md` Task 035 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/quest/QuestSystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 241.1FILTER Task 035_FILTER -> Quest objective system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 035_FILTER
**Task Name:** Quest objective system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 241 / `docs/FULL_TASK_SEQUENCE.md` Task 035 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/quest/QuestSystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 242.1 Task 035H -> Quest objective header

**Task Number:** 035H
**Task Name:** Quest objective header
**Source:** `docs/docs_ORDER_PLAN.md` order 242
**Status:** Remaining
**File to edit:** `src/game/quest/QuestSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Quest objective header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest objective header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestSystem.hpp
TASK: Implement the smallest compiling slice for: Quest objective header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Quest objective header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 243.1 Task 039 -> Quest flag / world-state hook

**Task Number:** 039
**Task Name:** Quest flag / world-state hook
**Source:** `docs/docs_ORDER_PLAN.md` order 243 / `docs/FULL_TASK_SEQUENCE.md` Task 039
**Status:** Remaining
**File to edit:** `src/game/quest/QuestFlags.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Quest flag / world-state hook and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest flag / world-state hook in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestFlags.hpp
TASK: Implement the smallest compiling slice for: Quest flag / world-state hook.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Quest flag / world-state hook and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 244.1 Task 039H -> Quest flag header

**Task Number:** 039H
**Task Name:** Quest flag header
**Source:** `docs/docs_ORDER_PLAN.md` order 244
**Status:** Remaining
**File to edit:** `src/game/quest/QuestFlags.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Quest flag header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest flag header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestFlags.hpp
TASK: Implement the smallest compiling slice for: Quest flag header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Quest flag header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 245.1 Task 036 -> Treasure chest actor

**Task Number:** 036
**Task Name:** Treasure chest actor
**Source:** `docs/docs_ORDER_PLAN.md` order 245 / `docs/FULL_TASK_SEQUENCE.md` Task 036
**Status:** Remaining
**File to edit:** `src/game/actors/ChestActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of treasure chest actor in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/ChestActor.cpp
TASK: Implement the smallest compiling slice for: Treasure chest actor.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 245.1VCPROJ Task 036_VCPROJ -> Treasure chest actor (Add the new .cpp compile include entry.)

**Task Number:** 036_VCPROJ
**Task Name:** Treasure chest actor (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 245 / `docs/FULL_TASK_SEQUENCE.md` Task 036 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/actors/ChestActor.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 245.1FILTER Task 036_FILTER -> Treasure chest actor (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 036_FILTER
**Task Name:** Treasure chest actor (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 245 / `docs/FULL_TASK_SEQUENCE.md` Task 036 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/actors/ChestActor.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 246.1 Task 036H -> Treasure chest header

**Task Number:** 036H
**Task Name:** Treasure chest header
**Source:** `docs/docs_ORDER_PLAN.md` order 246
**Status:** Remaining
**File to edit:** `src/game/actors/ChestActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Treasure chest header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of treasure chest header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/ChestActor.hpp
TASK: Implement the smallest compiling slice for: Treasure chest header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Treasure chest header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 247.1 Task 037 -> Campfire / rest point actor

**Task Number:** 037
**Task Name:** Campfire / rest point actor
**Source:** `docs/docs_ORDER_PLAN.md` order 247 / `docs/FULL_TASK_SEQUENCE.md` Task 037
**Status:** Remaining
**File to edit:** `src/game/actors/RestPointActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of campfire / rest point actor in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/RestPointActor.cpp
TASK: Implement the smallest compiling slice for: Campfire / rest point actor.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 247.1VCPROJ Task 037_VCPROJ -> Campfire / rest point actor (Add the new .cpp compile include entry.)

**Task Number:** 037_VCPROJ
**Task Name:** Campfire / rest point actor (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 247 / `docs/FULL_TASK_SEQUENCE.md` Task 037 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/actors/RestPointActor.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 247.1FILTER Task 037_FILTER -> Campfire / rest point actor (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 037_FILTER
**Task Name:** Campfire / rest point actor (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 247 / `docs/FULL_TASK_SEQUENCE.md` Task 037 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/actors/RestPointActor.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 248.1 Task 037H -> Rest point actor header

**Task Number:** 037H
**Task Name:** Rest point actor header
**Source:** `docs/docs_ORDER_PLAN.md` order 248
**Status:** Remaining
**File to edit:** `src/game/actors/RestPointActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Rest point actor header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of rest point actor header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/RestPointActor.hpp
TASK: Implement the smallest compiling slice for: Rest point actor header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Rest point actor header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 249.1 Task 189 -> Side quest discovery system

**Task Number:** 189
**Task Name:** Side quest discovery system
**Source:** `docs/docs_ORDER_PLAN.md` order 249
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/ShadowRenderer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of side quest discovery system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/ShadowRenderer.cpp
TASK: Implement the smallest compiling slice for: Side quest discovery system.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 249.1VCPROJ Task 189_VCPROJ -> Side quest discovery system (Add the new .cpp compile include entry.)

**Task Number:** 189_VCPROJ
**Task Name:** Side quest discovery system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 249 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/rendering/d3d11/ShadowRenderer.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 249.1FILTER Task 189_FILTER -> Side quest discovery system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 189_FILTER
**Task Name:** Side quest discovery system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 249 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/rendering/d3d11/ShadowRenderer.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 250.1 Task 189H -> Side quest discovery header

**Task Number:** 189H
**Task Name:** Side quest discovery header
**Source:** `docs/docs_ORDER_PLAN.md` order 250
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/ShadowRenderer.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Side quest discovery header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of side quest discovery header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/ShadowRenderer.hpp
TASK: Implement the smallest compiling slice for: Side quest discovery header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Side quest discovery header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 251.1 Task 294 -> Quest tracker HUD

**Task Number:** 294
**Task Name:** Quest tracker HUD
**Source:** `docs/docs_ORDER_PLAN.md` order 251
**Status:** Remaining
**File to edit:** `src/audio/FootstepMaterialSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest tracker hud in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/FootstepMaterialSystem.cpp
TASK: Implement the smallest compiling slice for: Quest tracker HUD.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 251.1VCPROJ Task 294_VCPROJ -> Quest tracker HUD (Add the new .cpp compile include entry.)

**Task Number:** 294_VCPROJ
**Task Name:** Quest tracker HUD (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 251 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/audio/FootstepMaterialSystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 251.1FILTER Task 294_FILTER -> Quest tracker HUD (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 294_FILTER
**Task Name:** Quest tracker HUD (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 251 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/audio/FootstepMaterialSystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 252.1 Task 294H -> Quest tracker HUD header

**Task Number:** 294H
**Task Name:** Quest tracker HUD header
**Source:** `docs/docs_ORDER_PLAN.md` order 252
**Status:** Remaining
**File to edit:** `src/audio/FootstepMaterialSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Quest tracker HUD header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest tracker hud header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/FootstepMaterialSystem.hpp
TASK: Implement the smallest compiling slice for: Quest tracker HUD header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Quest tracker HUD header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 253.1 Task 295 -> Minimap with rotation toggle

**Task Number:** 295
**Task Name:** Minimap with rotation toggle
**Source:** `docs/docs_ORDER_PLAN.md` order 253
**Status:** Remaining
**File to edit:** `src/game/ai/NpcActivitySystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of minimap with rotation toggle in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/NpcActivitySystem.cpp
TASK: Implement the smallest compiling slice for: Minimap with rotation toggle.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 253.1VCPROJ Task 295_VCPROJ -> Minimap with rotation toggle (Add the new .cpp compile include entry.)

**Task Number:** 295_VCPROJ
**Task Name:** Minimap with rotation toggle (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 253 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/ai/NpcActivitySystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 253.1FILTER Task 295_FILTER -> Minimap with rotation toggle (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 295_FILTER
**Task Name:** Minimap with rotation toggle (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 253 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/ai/NpcActivitySystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 254.1 Task 295H -> Minimap rotation header

**Task Number:** 295H
**Task Name:** Minimap rotation header
**Source:** `docs/docs_ORDER_PLAN.md` order 254
**Status:** Remaining
**File to edit:** `src/game/ai/NpcActivitySystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Minimap rotation header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of minimap rotation header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/NpcActivitySystem.hpp
TASK: Implement the smallest compiling slice for: Minimap rotation header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Minimap rotation header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 255.1 Task 215 -> Collectibles tracker system

**Task Number:** 215
**Task Name:** Collectibles tracker system
**Source:** `docs/docs_ORDER_PLAN.md` order 255
**Status:** Remaining
**File to edit:** `Content/Enemies/enemy_archetype_template.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of collectibles tracker system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/Enemies/enemy_archetype_template.json
TASK: Implement the smallest compiling slice for: Collectibles tracker system.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: inside the closest existing symbol for this task
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 256.1 Task 215H -> Collectibles tracker header

**Task Number:** 215H
**Task Name:** Collectibles tracker header
**Source:** `docs/docs_ORDER_PLAN.md` order 256
**Status:** Remaining
**File to edit:** `Content/Enemies/enemy_archetype_template.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of collectibles tracker header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/Enemies/enemy_archetype_template.json
TASK: Implement the smallest compiling slice for: Collectibles tracker header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: inside the closest existing symbol for this task
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 257.1 Task 216 -> Bounty hunt board system

**Task Number:** 216
**Task Name:** Bounty hunt board system
**Source:** `docs/docs_ORDER_PLAN.md` order 257
**Status:** Remaining
**File to edit:** `Content/Items/item_template.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of bounty hunt board system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/Items/item_template.json
TASK: Implement the smallest compiling slice for: Bounty hunt board system.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: inside the closest existing symbol for this task
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 258.1 Task 216H -> Bounty hunt board header

**Task Number:** 216H
**Task Name:** Bounty hunt board header
**Source:** `docs/docs_ORDER_PLAN.md` order 258
**Status:** Remaining
**File to edit:** `Content/Items/item_template.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of bounty hunt board header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/Items/item_template.json
TASK: Implement the smallest compiling slice for: Bounty hunt board header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: inside the closest existing symbol for this task
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 259.1 Task 350 -> Party member loyalty missions

**Task Number:** 350
**Task Name:** Party member loyalty missions
**Source:** `docs/docs_ORDER_PLAN.md` order 259
**Status:** Remaining
**File to edit:** `src/game/quest/LoyaltyMissions.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of party member loyalty missions in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/LoyaltyMissions.cpp
TASK: Implement the smallest compiling slice for: Party member loyalty missions.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 259.1VCPROJ Task 350_VCPROJ -> Party member loyalty missions (Add the new .cpp compile include entry.)

**Task Number:** 350_VCPROJ
**Task Name:** Party member loyalty missions (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 259 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/quest/LoyaltyMissions.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 259.1FILTER Task 350_FILTER -> Party member loyalty missions (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 350_FILTER
**Task Name:** Party member loyalty missions (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 259 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/quest/LoyaltyMissions.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 260.1 Task 350H -> Loyalty missions header

**Task Number:** 350H
**Task Name:** Loyalty missions header
**Source:** `docs/docs_ORDER_PLAN.md` order 260
**Status:** Remaining
**File to edit:** `src/game/quest/LoyaltyMissions.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Loyalty missions header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of loyalty missions header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/LoyaltyMissions.hpp
TASK: Implement the smallest compiling slice for: Loyalty missions header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Loyalty missions header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 261.1 Task 357 -> Point-of-no-return warning system

**Task Number:** 357
**Task Name:** Point-of-no-return warning system
**Source:** `docs/docs_ORDER_PLAN.md` order 261
**Status:** Remaining
**File to edit:** `src/game/quest/PointOfNoReturnWarning.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of point-of-no-return warning system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/PointOfNoReturnWarning.cpp
TASK: Implement the smallest compiling slice for: Point-of-no-return warning system.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 261.1VCPROJ Task 357_VCPROJ -> Point-of-no-return warning system (Add the new .cpp compile include entry.)

**Task Number:** 357_VCPROJ
**Task Name:** Point-of-no-return warning system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 261 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/quest/PointOfNoReturnWarning.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 261.1FILTER Task 357_FILTER -> Point-of-no-return warning system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 357_FILTER
**Task Name:** Point-of-no-return warning system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 261 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/quest/PointOfNoReturnWarning.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 262.1 Task 357H -> Point-of-no-return header

**Task Number:** 357H
**Task Name:** Point-of-no-return header
**Source:** `docs/docs_ORDER_PLAN.md` order 262
**Status:** Remaining
**File to edit:** `src/game/quest/PointOfNoReturnWarning.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Point-of-no-return header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of point-of-no-return header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/PointOfNoReturnWarning.hpp
TASK: Implement the smallest compiling slice for: Point-of-no-return header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Point-of-no-return header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 263.1 Task 358 -> Missable content notification system

**Task Number:** 358
**Task Name:** Missable content notification system
**Source:** `docs/docs_ORDER_PLAN.md` order 263
**Status:** Remaining
**File to edit:** `src/ui/MissableContentAlert.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of missable content notification system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/MissableContentAlert.cpp
TASK: Implement the smallest compiling slice for: Missable content notification system.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 263.1VCPROJ Task 358_VCPROJ -> Missable content notification system (Add the new .cpp compile include entry.)

**Task Number:** 358_VCPROJ
**Task Name:** Missable content notification system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 263 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/MissableContentAlert.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 263.1FILTER Task 358_FILTER -> Missable content notification system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 358_FILTER
**Task Name:** Missable content notification system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 263 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/MissableContentAlert.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 264.1 Task 358H -> Missable content alert header

**Task Number:** 358H
**Task Name:** Missable content alert header
**Source:** `docs/docs_ORDER_PLAN.md` order 264
**Status:** Remaining
**File to edit:** `src/ui/MissableContentAlert.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Missable content alert header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of missable content alert header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/MissableContentAlert.hpp
TASK: Implement the smallest compiling slice for: Missable content alert header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Missable content alert header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 265.1 Task 359 -> World state change system after story beats

**Task Number:** 359
**Task Name:** World state change system after story beats
**Source:** `docs/docs_ORDER_PLAN.md` order 265
**Status:** Remaining
**File to edit:** `src/world/WorldStateChangeSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of world state change system after story beats in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldStateChangeSystem.cpp
TASK: Implement the smallest compiling slice for: World state change system after story beats.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 265.1VCPROJ Task 359_VCPROJ -> World state change system after story beats (Add the new .cpp compile include entry.)

**Task Number:** 359_VCPROJ
**Task Name:** World state change system after story beats (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 265 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/WorldStateChangeSystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 265.1FILTER Task 359_FILTER -> World state change system after story beats (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 359_FILTER
**Task Name:** World state change system after story beats (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 265 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/WorldStateChangeSystem.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 266.1 Task 359H -> World state change header

**Task Number:** 359H
**Task Name:** World state change header
**Source:** `docs/docs_ORDER_PLAN.md` order 266
**Status:** Remaining
**File to edit:** `src/world/WorldStateChangeSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to World state change header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of world state change header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldStateChangeSystem.hpp
TASK: Implement the smallest compiling slice for: World state change header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to World state change header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 267.1 Task 360 -> NPC reaction dialogue to story progress

**Task Number:** 360
**Task Name:** NPC reaction dialogue to story progress
**Source:** `docs/docs_ORDER_PLAN.md` order 267
**Status:** Remaining
**File to edit:** `src/game/dialogue/NpcStoryReactions.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc reaction dialogue to story progress in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/dialogue/NpcStoryReactions.cpp
TASK: Implement the smallest compiling slice for: NPC reaction dialogue to story progress.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 267.1VCPROJ Task 360_VCPROJ -> NPC reaction dialogue to story progress (Add the new .cpp compile include entry.)

**Task Number:** 360_VCPROJ
**Task Name:** NPC reaction dialogue to story progress (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 267 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/dialogue/NpcStoryReactions.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 267.1FILTER Task 360_FILTER -> NPC reaction dialogue to story progress (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 360_FILTER
**Task Name:** NPC reaction dialogue to story progress (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 267 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/dialogue/NpcStoryReactions.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 268.1 Task 360H -> NPC story reactions header

**Task Number:** 360H
**Task Name:** NPC story reactions header
**Source:** `docs/docs_ORDER_PLAN.md` order 268
**Status:** Remaining
**File to edit:** `src/game/dialogue/NpcStoryReactions.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC story reactions header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc story reactions header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/dialogue/NpcStoryReactions.hpp
TASK: Implement the smallest compiling slice for: NPC story reactions header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to NPC story reactions header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 269.1 Task 356 -> Scripted world event trigger system

**Task Number:** 356
**Task Name:** Scripted world event trigger system
**Source:** `docs/docs_ORDER_PLAN.md` order 269
**Status:** Remaining
**File to edit:** `src/world/ScriptedWorldEvents.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of scripted world event trigger system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/ScriptedWorldEvents.cpp
TASK: Implement the smallest compiling slice for: Scripted world event trigger system.
CONTEXT TO PASTE: NEW FILE - no context needed
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: new file
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 269.1VCPROJ Task 356_VCPROJ -> Scripted world event trigger system (Add the new .cpp compile include entry.)

**Task Number:** 356_VCPROJ
**Task Name:** Scripted world event trigger system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 269 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/ScriptedWorldEvents.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 269.1FILTER Task 356_FILTER -> Scripted world event trigger system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 356_FILTER
**Task Name:** Scripted world event trigger system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 269 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/ScriptedWorldEvents.cpp` only.
CONTEXT TO PASTE: Paste 40-120 lines around similar `<ClCompile Include=...>` entries.
OUTPUT: Return only the XML block or minimal replacement to paste. No explanations.
RULES:
- Edit one file only.
- Keep XML formatting consistent with neighboring entries.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```xml
<!-- Ask for one minimal ClCompile entry for the new file. -->
```

### Additional information for the user
- Paste at: Near matching compile/filter entries for adjacent source files.
- Validate by: Reload solution and confirm the file appears under the expected filter and compiles.
- If it fails: revert this one edit and ask Qwen for a smaller XML-only patch.

## 270.1 Task 356H -> Scripted world events header

**Task Number:** 356H
**Task Name:** Scripted world events header
**Source:** `docs/docs_ORDER_PLAN.md` order 270
**Status:** Remaining
**File to edit:** `src/world/ScriptedWorldEvents.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Scripted world events header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of scripted world events header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/ScriptedWorldEvents.hpp
TASK: Implement the smallest compiling slice for: Scripted world events header.
CONTEXT TO PASTE: Paste 20-100 lines around the target symbol for this edit.
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

### Lego block to request from Qwen
```cpp
// Ask for one small paste-ready block for this file only.
// Keep existing names and include guards/signatures unchanged unless required.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Scripted world events header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

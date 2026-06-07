# Phase 5.1 — Dialogue & Cutscenes (SLM micro-tasks)

This file covers remaining tasks for **Phase 5: NARRATIVE & CINEMATICS (Tasks 501-550) / Subphase 5.1** from `docs/docs_ORDER_PLAN.md`.
Tasks are one-file micro-steps optimized for Qwen2.5 Coder 0.5B Instruct in chat-only copy/paste mode.


## 501.1 Task 275 -> Dialogue tree system

**Task Number:** 275
**Task Name:** Dialogue tree system
**Source:** `docs/docs_ORDER_PLAN.md` order 501
**Status:** Remaining
**File to edit:** `src/app/AutosaveManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue tree system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/AutosaveManager.cpp
TASK: Implement the smallest compiling slice for: Dialogue tree system.
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

## 501.1VCPROJ Task 275_VCPROJ -> Dialogue tree system (Add the new .cpp compile include entry.)

**Task Number:** 275_VCPROJ
**Task Name:** Dialogue tree system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 501 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/app/AutosaveManager.cpp` only.
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

## 501.1FILTER Task 275_FILTER -> Dialogue tree system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 275_FILTER
**Task Name:** Dialogue tree system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 501 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/app/AutosaveManager.cpp` only.
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

## 502.1 Task 275H -> Dialogue tree header

**Task Number:** 275H
**Task Name:** Dialogue tree header
**Source:** `docs/docs_ORDER_PLAN.md` order 502
**Status:** Remaining
**File to edit:** `src/app/AutosaveManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Dialogue tree header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue tree header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/AutosaveManager.hpp
TASK: Implement the smallest compiling slice for: Dialogue tree header.
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
- Paste at: Search for `class`/`struct` declarations related to Dialogue tree header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 503.1 Task 276 -> Branching choices tracker

**Task Number:** 276
**Task Name:** Branching choices tracker
**Source:** `docs/docs_ORDER_PLAN.md` order 503
**Status:** Remaining
**File to edit:** `src/game/quest/HintSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of branching choices tracker in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/HintSystem.cpp
TASK: Implement the smallest compiling slice for: Branching choices tracker.
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

## 503.1VCPROJ Task 276_VCPROJ -> Branching choices tracker (Add the new .cpp compile include entry.)

**Task Number:** 276_VCPROJ
**Task Name:** Branching choices tracker (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 503 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/quest/HintSystem.cpp` only.
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

## 503.1FILTER Task 276_FILTER -> Branching choices tracker (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 276_FILTER
**Task Name:** Branching choices tracker (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 503 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/quest/HintSystem.cpp` only.
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

## 504.1 Task 276H -> Branching choices header

**Task Number:** 276H
**Task Name:** Branching choices header
**Source:** `docs/docs_ORDER_PLAN.md` order 504
**Status:** Remaining
**File to edit:** `src/game/quest/HintSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Branching choices header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of branching choices header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/HintSystem.hpp
TASK: Implement the smallest compiling slice for: Branching choices header.
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
- Paste at: Search for `class`/`struct` declarations related to Branching choices header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 505.1 Task 277 -> Cutscene timeline player

**Task Number:** 277
**Task Name:** Cutscene timeline player
**Source:** `docs/docs_ORDER_PLAN.md` order 505
**Status:** Remaining
**File to edit:** `src/ui/HudSettings.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene timeline player in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/HudSettings.cpp
TASK: Implement the smallest compiling slice for: Cutscene timeline player.
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

## 505.1VCPROJ Task 277_VCPROJ -> Cutscene timeline player (Add the new .cpp compile include entry.)

**Task Number:** 277_VCPROJ
**Task Name:** Cutscene timeline player (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 505 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/HudSettings.cpp` only.
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

## 505.1FILTER Task 277_FILTER -> Cutscene timeline player (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 277_FILTER
**Task Name:** Cutscene timeline player (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 505 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/HudSettings.cpp` only.
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

## 506.1 Task 277H -> Cutscene timeline header

**Task Number:** 277H
**Task Name:** Cutscene timeline header
**Source:** `docs/docs_ORDER_PLAN.md` order 506
**Status:** Remaining
**File to edit:** `src/ui/HudSettings.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Cutscene timeline header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene timeline header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/HudSettings.hpp
TASK: Implement the smallest compiling slice for: Cutscene timeline header.
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
- Paste at: Search for `class`/`struct` declarations related to Cutscene timeline header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 507.1 Task 278 -> Cutscene camera paths

**Task Number:** 278
**Task Name:** Cutscene camera paths
**Source:** `docs/docs_ORDER_PLAN.md` order 507
**Status:** Remaining
**File to edit:** `src/app/NewGamePlusManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene camera paths in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/NewGamePlusManager.cpp
TASK: Implement the smallest compiling slice for: Cutscene camera paths.
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

## 507.1VCPROJ Task 278_VCPROJ -> Cutscene camera paths (Add the new .cpp compile include entry.)

**Task Number:** 278_VCPROJ
**Task Name:** Cutscene camera paths (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 507 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/app/NewGamePlusManager.cpp` only.
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

## 507.1FILTER Task 278_FILTER -> Cutscene camera paths (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 278_FILTER
**Task Name:** Cutscene camera paths (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 507 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/app/NewGamePlusManager.cpp` only.
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

## 508.1 Task 278H -> Cutscene camera header

**Task Number:** 278H
**Task Name:** Cutscene camera header
**Source:** `docs/docs_ORDER_PLAN.md` order 508
**Status:** Remaining
**File to edit:** `src/app/NewGamePlusManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Cutscene camera header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene camera header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/NewGamePlusManager.hpp
TASK: Implement the smallest compiling slice for: Cutscene camera header.
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
- Paste at: Search for `class`/`struct` declarations related to Cutscene camera header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 509.1 Task 279 -> Subtitle sync system

**Task Number:** 279
**Task Name:** Subtitle sync system
**Source:** `docs/docs_ORDER_PLAN.md` order 509
**Status:** Remaining
**File to edit:** `src/world/SuperbossSpawnController.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of subtitle sync system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/SuperbossSpawnController.cpp
TASK: Implement the smallest compiling slice for: Subtitle sync system.
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

## 509.1VCPROJ Task 279_VCPROJ -> Subtitle sync system (Add the new .cpp compile include entry.)

**Task Number:** 279_VCPROJ
**Task Name:** Subtitle sync system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 509 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/SuperbossSpawnController.cpp` only.
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

## 509.1FILTER Task 279_FILTER -> Subtitle sync system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 279_FILTER
**Task Name:** Subtitle sync system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 509 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/SuperbossSpawnController.cpp` only.
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

## 510.1 Task 279H -> Subtitle sync header

**Task Number:** 279H
**Task Name:** Subtitle sync header
**Source:** `docs/docs_ORDER_PLAN.md` order 510
**Status:** Remaining
**File to edit:** `src/world/SuperbossSpawnController.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Subtitle sync header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of subtitle sync header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/SuperbossSpawnController.hpp
TASK: Implement the smallest compiling slice for: Subtitle sync header.
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
- Paste at: Search for `class`/`struct` declarations related to Subtitle sync header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 511.1 Task 280 -> Voice-over audio playback

**Task Number:** 280
**Task Name:** Voice-over audio playback
**Source:** `docs/docs_ORDER_PLAN.md` order 511
**Status:** Remaining
**File to edit:** `src/game/arena/ArenaMode.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of voice-over audio playback in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/arena/ArenaMode.cpp
TASK: Implement the smallest compiling slice for: Voice-over audio playback.
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

## 511.1VCPROJ Task 280_VCPROJ -> Voice-over audio playback (Add the new .cpp compile include entry.)

**Task Number:** 280_VCPROJ
**Task Name:** Voice-over audio playback (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 511 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/arena/ArenaMode.cpp` only.
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

## 511.1FILTER Task 280_FILTER -> Voice-over audio playback (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 280_FILTER
**Task Name:** Voice-over audio playback (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 511 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/arena/ArenaMode.cpp` only.
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

## 512.1 Task 280H -> Voice-over playback header

**Task Number:** 280H
**Task Name:** Voice-over playback header
**Source:** `docs/docs_ORDER_PLAN.md` order 512
**Status:** Remaining
**File to edit:** `src/game/arena/ArenaMode.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Voice-over playback header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of voice-over playback header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/arena/ArenaMode.hpp
TASK: Implement the smallest compiling slice for: Voice-over playback header.
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
- Paste at: Search for `class`/`struct` declarations related to Voice-over playback header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 513.1 Task 281 -> Facial animation sync

**Task Number:** 281
**Task Name:** Facial animation sync
**Source:** `docs/docs_ORDER_PLAN.md` order 513
**Status:** Remaining
**File to edit:** `src/game/inventory/LegendaryItems.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of facial animation sync in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/LegendaryItems.cpp
TASK: Implement the smallest compiling slice for: Facial animation sync.
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

## 513.1VCPROJ Task 281_VCPROJ -> Facial animation sync (Add the new .cpp compile include entry.)

**Task Number:** 281_VCPROJ
**Task Name:** Facial animation sync (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 513 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/inventory/LegendaryItems.cpp` only.
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

## 513.1FILTER Task 281_FILTER -> Facial animation sync (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 281_FILTER
**Task Name:** Facial animation sync (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 513 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/inventory/LegendaryItems.cpp` only.
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

## 514.1 Task 281H -> Facial animation header

**Task Number:** 281H
**Task Name:** Facial animation header
**Source:** `docs/docs_ORDER_PLAN.md` order 514
**Status:** Remaining
**File to edit:** `src/game/inventory/LegendaryItems.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Facial animation header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of facial animation header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/LegendaryItems.hpp
TASK: Implement the smallest compiling slice for: Facial animation header.
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
- Paste at: Search for `class`/`struct` declarations related to Facial animation header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 515.1 Task 298 -> Character flashback sequences

**Task Number:** 298
**Task Name:** Character flashback sequences
**Source:** `docs/docs_ORDER_PLAN.md` order 515
**Status:** Remaining
**File to edit:** `src/game/animation/IdleAnimVariety.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of character flashback sequences in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/animation/IdleAnimVariety.cpp
TASK: Implement the smallest compiling slice for: Character flashback sequences.
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

## 515.1VCPROJ Task 298_VCPROJ -> Character flashback sequences (Add the new .cpp compile include entry.)

**Task Number:** 298_VCPROJ
**Task Name:** Character flashback sequences (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 515 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/animation/IdleAnimVariety.cpp` only.
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

## 515.1FILTER Task 298_FILTER -> Character flashback sequences (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 298_FILTER
**Task Name:** Character flashback sequences (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 515 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/animation/IdleAnimVariety.cpp` only.
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

## 516.1 Task 298H -> Character flashback header

**Task Number:** 298H
**Task Name:** Character flashback header
**Source:** `docs/docs_ORDER_PLAN.md` order 516
**Status:** Remaining
**File to edit:** `src/game/animation/IdleAnimVariety.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Character flashback header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of character flashback header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/animation/IdleAnimVariety.hpp
TASK: Implement the smallest compiling slice for: Character flashback header.
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
- Paste at: Search for `class`/`struct` declarations related to Character flashback header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 517.1 Task 299 -> Branching narrative endings

**Task Number:** 299
**Task Name:** Branching narrative endings
**Source:** `docs/docs_ORDER_PLAN.md` order 517
**Status:** Remaining
**File to edit:** `src/ui/QuestTrackerHUD.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of branching narrative endings in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/QuestTrackerHUD.cpp
TASK: Implement the smallest compiling slice for: Branching narrative endings.
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

## 517.1VCPROJ Task 299_VCPROJ -> Branching narrative endings (Add the new .cpp compile include entry.)

**Task Number:** 299_VCPROJ
**Task Name:** Branching narrative endings (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 517 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/QuestTrackerHUD.cpp` only.
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

## 517.1FILTER Task 299_FILTER -> Branching narrative endings (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 299_FILTER
**Task Name:** Branching narrative endings (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 517 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/QuestTrackerHUD.cpp` only.
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

## 518.1 Task 299H -> Branching endings header

**Task Number:** 299H
**Task Name:** Branching endings header
**Source:** `docs/docs_ORDER_PLAN.md` order 518
**Status:** Remaining
**File to edit:** `src/ui/QuestTrackerHUD.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Branching endings header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of branching endings header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/QuestTrackerHUD.hpp
TASK: Implement the smallest compiling slice for: Branching endings header.
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
- Paste at: Search for `class`/`struct` declarations related to Branching endings header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 519.1 Task 300 -> Ending credits sequence

**Task Number:** 300
**Task Name:** Ending credits sequence
**Source:** `docs/docs_ORDER_PLAN.md` order 519
**Status:** Remaining
**File to edit:** `src/ui/ItemComparisonTooltip.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of ending credits sequence in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ItemComparisonTooltip.cpp
TASK: Implement the smallest compiling slice for: Ending credits sequence.
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

## 519.1VCPROJ Task 300_VCPROJ -> Ending credits sequence (Add the new .cpp compile include entry.)

**Task Number:** 300_VCPROJ
**Task Name:** Ending credits sequence (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 519 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/ItemComparisonTooltip.cpp` only.
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

## 519.1FILTER Task 300_FILTER -> Ending credits sequence (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 300_FILTER
**Task Name:** Ending credits sequence (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 519 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/ItemComparisonTooltip.cpp` only.
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

## 520.1 Task 300H -> Ending credits header

**Task Number:** 300H
**Task Name:** Ending credits header
**Source:** `docs/docs_ORDER_PLAN.md` order 520
**Status:** Remaining
**File to edit:** `src/ui/ItemComparisonTooltip.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Ending credits header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of ending credits header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ItemComparisonTooltip.hpp
TASK: Implement the smallest compiling slice for: Ending credits header.
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
- Paste at: Search for `class`/`struct` declarations related to Ending credits header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 521.1 Task 301 -> In-game cinematic letterbox

**Task Number:** 301
**Task Name:** In-game cinematic letterbox
**Source:** `docs/docs_ORDER_PLAN.md` order 521
**Status:** Remaining
**File to edit:** `src/ui/InventorySortFilter.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of in-game cinematic letterbox in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/InventorySortFilter.cpp
TASK: Implement the smallest compiling slice for: In-game cinematic letterbox.
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

## 521.1VCPROJ Task 301_VCPROJ -> In-game cinematic letterbox (Add the new .cpp compile include entry.)

**Task Number:** 301_VCPROJ
**Task Name:** In-game cinematic letterbox (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 521 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/InventorySortFilter.cpp` only.
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

## 521.1FILTER Task 301_FILTER -> In-game cinematic letterbox (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 301_FILTER
**Task Name:** In-game cinematic letterbox (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 521 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/InventorySortFilter.cpp` only.
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

## 522.1 Task 301H -> Cinematic letterbox header

**Task Number:** 301H
**Task Name:** Cinematic letterbox header
**Source:** `docs/docs_ORDER_PLAN.md` order 522
**Status:** Remaining
**File to edit:** `src/ui/InventorySortFilter.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Cinematic letterbox header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cinematic letterbox header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/InventorySortFilter.hpp
TASK: Implement the smallest compiling slice for: Cinematic letterbox header.
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
- Paste at: Search for `class`/`struct` declarations related to Cinematic letterbox header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 523.1 Task 302 -> Skip cutscene prompt

**Task Number:** 302
**Task Name:** Skip cutscene prompt
**Source:** `docs/docs_ORDER_PLAN.md` order 523
**Status:** Remaining
**File to edit:** `src/world/FastTravelUnlockSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of skip cutscene prompt in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/FastTravelUnlockSystem.cpp
TASK: Implement the smallest compiling slice for: Skip cutscene prompt.
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

## 523.1VCPROJ Task 302_VCPROJ -> Skip cutscene prompt (Add the new .cpp compile include entry.)

**Task Number:** 302_VCPROJ
**Task Name:** Skip cutscene prompt (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 523 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/FastTravelUnlockSystem.cpp` only.
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

## 523.1FILTER Task 302_FILTER -> Skip cutscene prompt (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 302_FILTER
**Task Name:** Skip cutscene prompt (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 523 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/FastTravelUnlockSystem.cpp` only.
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

## 524.1 Task 302H -> Skip cutscene header

**Task Number:** 302H
**Task Name:** Skip cutscene header
**Source:** `docs/docs_ORDER_PLAN.md` order 524
**Status:** Remaining
**File to edit:** `src/world/FastTravelUnlockSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Skip cutscene header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of skip cutscene header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/FastTravelUnlockSystem.hpp
TASK: Implement the smallest compiling slice for: Skip cutscene header.
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
- Paste at: Search for `class`/`struct` declarations related to Skip cutscene header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 525.1 Task 303 -> Dialogue history log

**Task Number:** 303
**Task Name:** Dialogue history log
**Source:** `docs/docs_ORDER_PLAN.md` order 525
**Status:** Remaining
**File to edit:** `src/ui/MinimapRotationSetting.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue history log in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/MinimapRotationSetting.cpp
TASK: Implement the smallest compiling slice for: Dialogue history log.
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

## 525.1VCPROJ Task 303_VCPROJ -> Dialogue history log (Add the new .cpp compile include entry.)

**Task Number:** 303_VCPROJ
**Task Name:** Dialogue history log (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 525 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/MinimapRotationSetting.cpp` only.
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

## 525.1FILTER Task 303_FILTER -> Dialogue history log (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 303_FILTER
**Task Name:** Dialogue history log (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 525 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/MinimapRotationSetting.cpp` only.
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

## 526.1 Task 303H -> Dialogue history header

**Task Number:** 303H
**Task Name:** Dialogue history header
**Source:** `docs/docs_ORDER_PLAN.md` order 526
**Status:** Remaining
**File to edit:** `src/ui/MinimapRotationSetting.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Dialogue history header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue history header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/MinimapRotationSetting.hpp
TASK: Implement the smallest compiling slice for: Dialogue history header.
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
- Paste at: Search for `class`/`struct` declarations related to Dialogue history header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 527.1 Task 379 -> Codex entry database

**Task Number:** 379
**Task Name:** Codex entry database
**Source:** `docs/docs_ORDER_PLAN.md` order 527
**Status:** Remaining
**File to edit:** `src/game/narrative/CodexEntryDatabase.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of codex entry database in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/narrative/CodexEntryDatabase.cpp
TASK: Implement the smallest compiling slice for: Codex entry database.
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

## 527.1VCPROJ Task 379_VCPROJ -> Codex entry database (Add the new .cpp compile include entry.)

**Task Number:** 379_VCPROJ
**Task Name:** Codex entry database (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 527 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/narrative/CodexEntryDatabase.cpp` only.
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

## 527.1FILTER Task 379_FILTER -> Codex entry database (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 379_FILTER
**Task Name:** Codex entry database (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 527 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/narrative/CodexEntryDatabase.cpp` only.
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

## 528.1 Task 379H -> Codex entry database header

**Task Number:** 379H
**Task Name:** Codex entry database header
**Source:** `docs/docs_ORDER_PLAN.md` order 528
**Status:** Remaining
**File to edit:** `src/game/narrative/CodexEntryDatabase.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Codex entry database header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of codex entry database header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/narrative/CodexEntryDatabase.hpp
TASK: Implement the smallest compiling slice for: Codex entry database header.
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
- Paste at: Search for `class`/`struct` declarations related to Codex entry database header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 529.1 Task 380 -> Journal UI viewer

**Task Number:** 380
**Task Name:** Journal UI viewer
**Source:** `docs/docs_ORDER_PLAN.md` order 529
**Status:** Remaining
**File to edit:** `src/ui/JournalUIViewer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of journal ui viewer in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/JournalUIViewer.cpp
TASK: Implement the smallest compiling slice for: Journal UI viewer.
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

## 529.1VCPROJ Task 380_VCPROJ -> Journal UI viewer (Add the new .cpp compile include entry.)

**Task Number:** 380_VCPROJ
**Task Name:** Journal UI viewer (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 529 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/JournalUIViewer.cpp` only.
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

## 529.1FILTER Task 380_FILTER -> Journal UI viewer (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 380_FILTER
**Task Name:** Journal UI viewer (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 529 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/JournalUIViewer.cpp` only.
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

## 530.1 Task 380H -> Journal UI viewer header

**Task Number:** 380H
**Task Name:** Journal UI viewer header
**Source:** `docs/docs_ORDER_PLAN.md` order 530
**Status:** Remaining
**File to edit:** `src/ui/JournalUIViewer.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Journal UI viewer header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of journal ui viewer header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/JournalUIViewer.hpp
TASK: Implement the smallest compiling slice for: Journal UI viewer header.
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
- Paste at: Search for `class`/`struct` declarations related to Journal UI viewer header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

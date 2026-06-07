# Phase 2.5 — Weather & Environment (SLM micro-tasks)

This file covers remaining tasks for **Phase 2: WORLD SYSTEMS & EXPLORATION (Tasks 151-300) / Subphase 2.5** from `docs/docs_ORDER_PLAN.md`.
Tasks are one-file micro-steps optimized for Qwen2.5 Coder 0.5B Instruct in chat-only copy/paste mode.


## 271.1 Task 375 -> Rain terrain modifier system

**Task Number:** 375
**Task Name:** Rain terrain modifier system
**Source:** `docs/docs_ORDER_PLAN.md` order 271
**Status:** Remaining
**File to edit:** `src/world/RainTerrainModifier.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of rain terrain modifier system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/RainTerrainModifier.cpp
TASK: Implement the smallest compiling slice for: Rain terrain modifier system.
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

## 271.1VCPROJ Task 375_VCPROJ -> Rain terrain modifier system (Add the new .cpp compile include entry.)

**Task Number:** 375_VCPROJ
**Task Name:** Rain terrain modifier system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 271 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/RainTerrainModifier.cpp` only.
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

## 271.1FILTER Task 375_FILTER -> Rain terrain modifier system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 375_FILTER
**Task Name:** Rain terrain modifier system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 271 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/RainTerrainModifier.cpp` only.
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

## 272.1 Task 375H -> Rain terrain modifier header

**Task Number:** 375H
**Task Name:** Rain terrain modifier header
**Source:** `docs/docs_ORDER_PLAN.md` order 272
**Status:** Remaining
**File to edit:** `src/world/RainTerrainModifier.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Rain terrain modifier header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of rain terrain modifier header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/RainTerrainModifier.hpp
TASK: Implement the smallest compiling slice for: Rain terrain modifier header.
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
- Paste at: Search for `class`/`struct` declarations related to Rain terrain modifier header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 273.1 Task 376 -> Snow/ice terrain modifier system

**Task Number:** 376
**Task Name:** Snow/ice terrain modifier system
**Source:** `docs/docs_ORDER_PLAN.md` order 273
**Status:** Remaining
**File to edit:** `src/world/SnowIceTerrainModifier.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of snow/ice terrain modifier system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/SnowIceTerrainModifier.cpp
TASK: Implement the smallest compiling slice for: Snow/ice terrain modifier system.
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

## 273.1VCPROJ Task 376_VCPROJ -> Snow/ice terrain modifier system (Add the new .cpp compile include entry.)

**Task Number:** 376_VCPROJ
**Task Name:** Snow/ice terrain modifier system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 273 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/SnowIceTerrainModifier.cpp` only.
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

## 273.1FILTER Task 376_FILTER -> Snow/ice terrain modifier system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 376_FILTER
**Task Name:** Snow/ice terrain modifier system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 273 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/SnowIceTerrainModifier.cpp` only.
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

## 274.1 Task 376H -> Snow/ice terrain modifier header

**Task Number:** 376H
**Task Name:** Snow/ice terrain modifier header
**Source:** `docs/docs_ORDER_PLAN.md` order 274
**Status:** Remaining
**File to edit:** `src/world/SnowIceTerrainModifier.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Snow/ice terrain modifier header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of snow/ice terrain modifier header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/SnowIceTerrainModifier.hpp
TASK: Implement the smallest compiling slice for: Snow/ice terrain modifier header.
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
- Paste at: Search for `class`/`struct` declarations related to Snow/ice terrain modifier header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 275.1 Task 177 -> Dynamic weather system (rain/snow/fog)

**Task Number:** 177
**Task Name:** Dynamic weather system (rain/snow/fog)
**Source:** `docs/docs_ORDER_PLAN.md` order 275
**Status:** Remaining
**File to edit:** `docs/SHIP_CHECKLIST.md`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near similar task/documentation entries.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dynamic weather system (rain/snow/fog) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: docs/SHIP_CHECKLIST.md
TASK: Implement the smallest compiling slice for: Dynamic weather system (rain/snow/fog).
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
- Paste at: Append near similar task/documentation entries.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 276.1 Task 177H -> Dynamic weather header

**Task Number:** 177H
**Task Name:** Dynamic weather header
**Source:** `docs/docs_ORDER_PLAN.md` order 276
**Status:** Remaining
**File to edit:** `docs/SHIP_CHECKLIST.md`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near similar task/documentation entries.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dynamic weather header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: docs/SHIP_CHECKLIST.md
TASK: Implement the smallest compiling slice for: Dynamic weather header.
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
- Paste at: Append near similar task/documentation entries.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 277.1 Task 178 -> Weather transitions

**Task Number:** 178
**Task Name:** Weather transitions
**Source:** `docs/docs_ORDER_PLAN.md` order 277
**Status:** Remaining
**File to edit:** `src/ui/TitleScreen.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of weather transitions in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/TitleScreen.cpp
TASK: Implement the smallest compiling slice for: Weather transitions.
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

## 277.1VCPROJ Task 178_VCPROJ -> Weather transitions (Add the new .cpp compile include entry.)

**Task Number:** 178_VCPROJ
**Task Name:** Weather transitions (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 277 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/TitleScreen.cpp` only.
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

## 277.1FILTER Task 178_FILTER -> Weather transitions (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 178_FILTER
**Task Name:** Weather transitions (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 277 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/TitleScreen.cpp` only.
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

## 278.1 Task 178H -> Weather transitions header

**Task Number:** 178H
**Task Name:** Weather transitions header
**Source:** `docs/docs_ORDER_PLAN.md` order 278
**Status:** Remaining
**File to edit:** `src/ui/TitleScreen.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Weather transitions header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of weather transitions header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/TitleScreen.hpp
TASK: Implement the smallest compiling slice for: Weather transitions header.
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
- Paste at: Search for `class`/`struct` declarations related to Weather transitions header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 279.1 Task 179 -> Time-of-day lighting system

**Task Number:** 179
**Task Name:** Time-of-day lighting system
**Source:** `docs/docs_ORDER_PLAN.md` order 279
**Status:** Remaining
**File to edit:** `src/ui/InventoryScreen.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of time-of-day lighting system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/InventoryScreen.cpp
TASK: Implement the smallest compiling slice for: Time-of-day lighting system.
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

## 279.1VCPROJ Task 179_VCPROJ -> Time-of-day lighting system (Add the new .cpp compile include entry.)

**Task Number:** 179_VCPROJ
**Task Name:** Time-of-day lighting system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 279 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/InventoryScreen.cpp` only.
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

## 279.1FILTER Task 179_FILTER -> Time-of-day lighting system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 179_FILTER
**Task Name:** Time-of-day lighting system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 279 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/InventoryScreen.cpp` only.
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

## 280.1 Task 179H -> Time-of-day lighting header

**Task Number:** 179H
**Task Name:** Time-of-day lighting header
**Source:** `docs/docs_ORDER_PLAN.md` order 280
**Status:** Remaining
**File to edit:** `src/ui/InventoryScreen.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Time-of-day lighting header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of time-of-day lighting header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/InventoryScreen.hpp
TASK: Implement the smallest compiling slice for: Time-of-day lighting header.
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
- Paste at: Search for `class`/`struct` declarations related to Time-of-day lighting header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 281.1 Task 180 -> Atmospheric fog system

**Task Number:** 180
**Task Name:** Atmospheric fog system
**Source:** `docs/docs_ORDER_PLAN.md` order 281
**Status:** Remaining
**File to edit:** `src/ui/BestiaryScreen.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of atmospheric fog system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/BestiaryScreen.cpp
TASK: Implement the smallest compiling slice for: Atmospheric fog system.
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

## 281.1VCPROJ Task 180_VCPROJ -> Atmospheric fog system (Add the new .cpp compile include entry.)

**Task Number:** 180_VCPROJ
**Task Name:** Atmospheric fog system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 281 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/BestiaryScreen.cpp` only.
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

## 281.1FILTER Task 180_FILTER -> Atmospheric fog system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 180_FILTER
**Task Name:** Atmospheric fog system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 281 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/BestiaryScreen.cpp` only.
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

## 282.1 Task 180H -> Atmospheric fog header

**Task Number:** 180H
**Task Name:** Atmospheric fog header
**Source:** `docs/docs_ORDER_PLAN.md` order 282
**Status:** Remaining
**File to edit:** `src/ui/BestiaryScreen.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Atmospheric fog header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of atmospheric fog header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/BestiaryScreen.hpp
TASK: Implement the smallest compiling slice for: Atmospheric fog header.
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
- Paste at: Search for `class`/`struct` declarations related to Atmospheric fog header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 283.1 Task 181 -> Wind system for foliage

**Task Number:** 181
**Task Name:** Wind system for foliage
**Source:** `docs/docs_ORDER_PLAN.md` order 283
**Status:** Remaining
**File to edit:** `src/ui/SkillTreeScreen.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of wind system for foliage in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/SkillTreeScreen.cpp
TASK: Implement the smallest compiling slice for: Wind system for foliage.
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

## 283.1VCPROJ Task 181_VCPROJ -> Wind system for foliage (Add the new .cpp compile include entry.)

**Task Number:** 181_VCPROJ
**Task Name:** Wind system for foliage (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 283 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/SkillTreeScreen.cpp` only.
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

## 283.1FILTER Task 181_FILTER -> Wind system for foliage (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 181_FILTER
**Task Name:** Wind system for foliage (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 283 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/SkillTreeScreen.cpp` only.
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

## 284.1 Task 181H -> Wind system header

**Task Number:** 181H
**Task Name:** Wind system header
**Source:** `docs/docs_ORDER_PLAN.md` order 284
**Status:** Remaining
**File to edit:** `src/ui/SkillTreeScreen.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Wind system header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of wind system header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/SkillTreeScreen.hpp
TASK: Implement the smallest compiling slice for: Wind system header.
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
- Paste at: Search for `class`/`struct` declarations related to Wind system header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 285.1 Task 182 -> Lightning strikes during storms

**Task Number:** 182
**Task Name:** Lightning strikes during storms
**Source:** `docs/docs_ORDER_PLAN.md` order 285
**Status:** Remaining
**File to edit:** `src/ui/CraftingScreen.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of lightning strikes during storms in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CraftingScreen.cpp
TASK: Implement the smallest compiling slice for: Lightning strikes during storms.
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

## 285.1VCPROJ Task 182_VCPROJ -> Lightning strikes during storms (Add the new .cpp compile include entry.)

**Task Number:** 182_VCPROJ
**Task Name:** Lightning strikes during storms (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 285 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/CraftingScreen.cpp` only.
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

## 285.1FILTER Task 182_FILTER -> Lightning strikes during storms (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 182_FILTER
**Task Name:** Lightning strikes during storms (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 285 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/CraftingScreen.cpp` only.
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

## 286.1 Task 182H -> Lightning strikes header

**Task Number:** 182H
**Task Name:** Lightning strikes header
**Source:** `docs/docs_ORDER_PLAN.md` order 286
**Status:** Remaining
**File to edit:** `src/ui/CraftingScreen.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Lightning strikes header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of lightning strikes header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CraftingScreen.hpp
TASK: Implement the smallest compiling slice for: Lightning strikes header.
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
- Paste at: Search for `class`/`struct` declarations related to Lightning strikes header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 287.1 Task 183 -> Volumetric cloud system

**Task Number:** 183
**Task Name:** Volumetric cloud system
**Source:** `docs/docs_ORDER_PLAN.md` order 287
**Status:** Remaining
**File to edit:** `src/ui/ShopScreen.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of volumetric cloud system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ShopScreen.cpp
TASK: Implement the smallest compiling slice for: Volumetric cloud system.
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

## 287.1VCPROJ Task 183_VCPROJ -> Volumetric cloud system (Add the new .cpp compile include entry.)

**Task Number:** 183_VCPROJ
**Task Name:** Volumetric cloud system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 287 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/ShopScreen.cpp` only.
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

## 287.1FILTER Task 183_FILTER -> Volumetric cloud system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 183_FILTER
**Task Name:** Volumetric cloud system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 287 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/ShopScreen.cpp` only.
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

## 288.1 Task 183H -> Volumetric cloud header

**Task Number:** 183H
**Task Name:** Volumetric cloud header
**Source:** `docs/docs_ORDER_PLAN.md` order 288
**Status:** Remaining
**File to edit:** `src/ui/ShopScreen.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Volumetric cloud header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of volumetric cloud header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ShopScreen.hpp
TASK: Implement the smallest compiling slice for: Volumetric cloud header.
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
- Paste at: Search for `class`/`struct` declarations related to Volumetric cloud header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 289.1 Task 131 -> PS2-era texture filtering

**Task Number:** 131
**Task Name:** PS2-era texture filtering
**Source:** `docs/docs_ORDER_PLAN.md` order 289
**Status:** Remaining
**File to edit:** `Content/NPCs/npc_placement_template.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of ps2-era texture filtering in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/NPCs/npc_placement_template.json
TASK: Implement the smallest compiling slice for: PS2-era texture filtering.
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

## 290.1 Task 131H -> PS2-era texture filtering header

**Task Number:** 131H
**Task Name:** PS2-era texture filtering header
**Source:** `docs/docs_ORDER_PLAN.md` order 290
**Status:** Remaining
**File to edit:** `Content/NPCs/npc_placement_template.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of ps2-era texture filtering header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/NPCs/npc_placement_template.json
TASK: Implement the smallest compiling slice for: PS2-era texture filtering header.
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

## 291.1 Task 132 -> Pre-baked lightmaps

**Task Number:** 132
**Task Name:** Pre-baked lightmaps
**Source:** `docs/docs_ORDER_PLAN.md` order 291
**Status:** Remaining
**File to edit:** `Content/Localization/en_us.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of pre-baked lightmaps in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/Localization/en_us.json
TASK: Implement the smallest compiling slice for: Pre-baked lightmaps.
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

## 292.1 Task 132H -> Pre-baked lightmaps header

**Task Number:** 132H
**Task Name:** Pre-baked lightmaps header
**Source:** `docs/docs_ORDER_PLAN.md` order 292
**Status:** Remaining
**File to edit:** `Content/Localization/en_us.json`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task

### What the edit is doing
This micro-step adds a small, compile-safe slice of pre-baked lightmaps header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Content/Localization/en_us.json
TASK: Implement the smallest compiling slice for: Pre-baked lightmaps header.
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

## 293.1 Task 133 -> Vertex color ambient occlusion

**Task Number:** 133
**Task Name:** Vertex color ambient occlusion
**Source:** `docs/docs_ORDER_PLAN.md` order 293
**Status:** Remaining
**File to edit:** `Shaders/ps2_vertcolor_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of vertex color ambient occlusion in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/ps2_vertcolor_vs.hlsl
TASK: Implement the smallest compiling slice for: Vertex color ambient occlusion.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 294.1 Task 133H -> Vertex color AO header

**Task Number:** 133H
**Task Name:** Vertex color AO header
**Source:** `docs/docs_ORDER_PLAN.md` order 294
**Status:** Remaining
**File to edit:** `Shaders/ps2_vertcolor_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of vertex color ao header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/ps2_vertcolor_vs.hlsl
TASK: Implement the smallest compiling slice for: Vertex color AO header.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 295.1 Task 134 -> FF7-style pre-rendered backgrounds

**Task Number:** 134
**Task Name:** FF7-style pre-rendered backgrounds
**Source:** `docs/docs_ORDER_PLAN.md` order 295
**Status:** Remaining
**File to edit:** `Shaders/ps2_vertcolor_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of ff7-style pre-rendered backgrounds in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/ps2_vertcolor_ps.hlsl
TASK: Implement the smallest compiling slice for: FF7-style pre-rendered backgrounds.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 296.1 Task 134H -> Pre-rendered backgrounds header

**Task Number:** 134H
**Task Name:** Pre-rendered backgrounds header
**Source:** `docs/docs_ORDER_PLAN.md` order 296
**Status:** Remaining
**File to edit:** `Shaders/ps2_vertcolor_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of pre-rendered backgrounds header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/ps2_vertcolor_ps.hlsl
TASK: Implement the smallest compiling slice for: Pre-rendered backgrounds header.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 297.1 Task 135 -> Billboard impostor LODs

**Task Number:** 135
**Task Name:** Billboard impostor LODs
**Source:** `docs/docs_ORDER_PLAN.md` order 297
**Status:** Remaining
**File to edit:** `Shaders/cel_outline_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of billboard impostor lods in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/cel_outline_vs.hlsl
TASK: Implement the smallest compiling slice for: Billboard impostor LODs.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 298.1 Task 135H -> Billboard impostor header

**Task Number:** 135H
**Task Name:** Billboard impostor header
**Source:** `docs/docs_ORDER_PLAN.md` order 298
**Status:** Remaining
**File to edit:** `Shaders/cel_outline_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of billboard impostor header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/cel_outline_vs.hlsl
TASK: Implement the smallest compiling slice for: Billboard impostor header.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 299.1 Task 136 -> Handmade asset placement tools

**Task Number:** 136
**Task Name:** Handmade asset placement tools
**Source:** `docs/docs_ORDER_PLAN.md` order 299
**Status:** Remaining
**File to edit:** `Shaders/cel_outline_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of handmade asset placement tools in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/cel_outline_ps.hlsl
TASK: Implement the smallest compiling slice for: Handmade asset placement tools.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 300.1 Task 136H -> Handmade asset placement header

**Task Number:** 136H
**Task Name:** Handmade asset placement header
**Source:** `docs/docs_ORDER_PLAN.md` order 300
**Status:** Remaining
**File to edit:** `Shaders/cel_outline_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of handmade asset placement header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/cel_outline_ps.hlsl
TASK: Implement the smallest compiling slice for: Handmade asset placement header.
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
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

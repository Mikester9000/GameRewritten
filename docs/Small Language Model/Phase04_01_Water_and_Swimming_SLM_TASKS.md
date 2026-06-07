# Phase 4.1 — Water & Swimming (SLM micro-tasks)

This file covers remaining tasks for **Phase 4: WORLD CONTENT & ACTIVITIES (Tasks 401-500) / Subphase 4.1** from `docs/docs_ORDER_PLAN.md`.
Tasks are one-file micro-steps optimized for Qwen2.5 Coder 0.5B Instruct in chat-only copy/paste mode.


## 401.1 Task 137 -> Water plane rendering

**Task Number:** 137
**Task Name:** Water plane rendering
**Source:** `docs/docs_ORDER_PLAN.md` order 401
**Status:** Remaining
**File to edit:** `Shaders/color_grade_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of water plane rendering in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/color_grade_ps.hlsl
TASK: Implement the smallest compiling slice for: Water plane rendering.
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

## 402.1 Task 137H -> Water plane header

**Task Number:** 137H
**Task Name:** Water plane header
**Source:** `docs/docs_ORDER_PLAN.md` order 402
**Status:** Remaining
**File to edit:** `Shaders/color_grade_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of water plane header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/color_grade_ps.hlsl
TASK: Implement the smallest compiling slice for: Water plane header.
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

## 403.1 Task 138 -> Water reflection system

**Task Number:** 138
**Task Name:** Water reflection system
**Source:** `docs/docs_ORDER_PLAN.md` order 403
**Status:** Remaining
**File to edit:** `Shaders/bloom_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of water reflection system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/bloom_ps.hlsl
TASK: Implement the smallest compiling slice for: Water reflection system.
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

## 404.1 Task 138H -> Water reflection header

**Task Number:** 138H
**Task Name:** Water reflection header
**Source:** `docs/docs_ORDER_PLAN.md` order 404
**Status:** Remaining
**File to edit:** `Shaders/bloom_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of water reflection header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/bloom_ps.hlsl
TASK: Implement the smallest compiling slice for: Water reflection header.
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

## 405.1 Task 139 -> Water caustics (underwater light)

**Task Number:** 139
**Task Name:** Water caustics (underwater light)
**Source:** `docs/docs_ORDER_PLAN.md` order 405
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/Ps2RenderPass.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of water caustics (underwater light) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/Ps2RenderPass.cpp
TASK: Implement the smallest compiling slice for: Water caustics (underwater light).
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

## 405.1VCPROJ Task 139_VCPROJ -> Water caustics (underwater light) (Add the new .cpp compile include entry.)

**Task Number:** 139_VCPROJ
**Task Name:** Water caustics (underwater light) (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 405 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/rendering/d3d11/Ps2RenderPass.cpp` only.
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

## 405.1FILTER Task 139_FILTER -> Water caustics (underwater light) (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 139_FILTER
**Task Name:** Water caustics (underwater light) (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 405 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/rendering/d3d11/Ps2RenderPass.cpp` only.
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

## 406.1 Task 139H -> Water caustics header

**Task Number:** 139H
**Task Name:** Water caustics header
**Source:** `docs/docs_ORDER_PLAN.md` order 406
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/Ps2RenderPass.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Water caustics header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of water caustics header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/Ps2RenderPass.hpp
TASK: Implement the smallest compiling slice for: Water caustics header.
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
- Paste at: Search for `class`/`struct` declarations related to Water caustics header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 407.1 Task 140 -> Underwater fog/visibility

**Task Number:** 140
**Task Name:** Underwater fog/visibility
**Source:** `docs/docs_ORDER_PLAN.md` order 407
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/PostProcessPipeline.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of underwater fog/visibility in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/PostProcessPipeline.cpp
TASK: Implement the smallest compiling slice for: Underwater fog/visibility.
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

## 407.1VCPROJ Task 140_VCPROJ -> Underwater fog/visibility (Add the new .cpp compile include entry.)

**Task Number:** 140_VCPROJ
**Task Name:** Underwater fog/visibility (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 407 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/rendering/d3d11/PostProcessPipeline.cpp` only.
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

## 407.1FILTER Task 140_FILTER -> Underwater fog/visibility (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 140_FILTER
**Task Name:** Underwater fog/visibility (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 407 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/rendering/d3d11/PostProcessPipeline.cpp` only.
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

## 408.1 Task 140H -> Underwater fog header

**Task Number:** 140H
**Task Name:** Underwater fog header
**Source:** `docs/docs_ORDER_PLAN.md` order 408
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/PostProcessPipeline.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Underwater fog header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of underwater fog header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/PostProcessPipeline.hpp
TASK: Implement the smallest compiling slice for: Underwater fog header.
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
- Paste at: Search for `class`/`struct` declarations related to Underwater fog header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 409.1 Task 141 -> Swimming controls

**Task Number:** 141
**Task Name:** Swimming controls
**Source:** `docs/docs_ORDER_PLAN.md` order 409
**Status:** Remaining
**File to edit:** `Shaders/water_surface_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of swimming controls in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/water_surface_vs.hlsl
TASK: Implement the smallest compiling slice for: Swimming controls.
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

## 410.1 Task 141H -> Swimming controls header

**Task Number:** 141H
**Task Name:** Swimming controls header
**Source:** `docs/docs_ORDER_PLAN.md` order 410
**Status:** Remaining
**File to edit:** `Shaders/water_surface_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of swimming controls header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/water_surface_vs.hlsl
TASK: Implement the smallest compiling slice for: Swimming controls header.
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

## 411.1 Task 142 -> Underwater breathing meter

**Task Number:** 142
**Task Name:** Underwater breathing meter
**Source:** `docs/docs_ORDER_PLAN.md` order 411
**Status:** Remaining
**File to edit:** `Shaders/water_surface_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of underwater breathing meter in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/water_surface_ps.hlsl
TASK: Implement the smallest compiling slice for: Underwater breathing meter.
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

## 412.1 Task 142H -> Breathing meter header

**Task Number:** 142H
**Task Name:** Breathing meter header
**Source:** `docs/docs_ORDER_PLAN.md` order 412
**Status:** Remaining
**File to edit:** `Shaders/water_surface_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of breathing meter header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/water_surface_ps.hlsl
TASK: Implement the smallest compiling slice for: Breathing meter header.
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

## 413.1 Task 143 -> Underwater enemies

**Task Number:** 143
**Task Name:** Underwater enemies
**Source:** `docs/docs_ORDER_PLAN.md` order 413
**Status:** Remaining
**File to edit:** `Shaders/underwater_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of underwater enemies in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/underwater_ps.hlsl
TASK: Implement the smallest compiling slice for: Underwater enemies.
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

## 414.1 Task 143H -> Underwater enemies header

**Task Number:** 143H
**Task Name:** Underwater enemies header
**Source:** `docs/docs_ORDER_PLAN.md` order 414
**Status:** Remaining
**File to edit:** `Shaders/underwater_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of underwater enemies header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/underwater_ps.hlsl
TASK: Implement the smallest compiling slice for: Underwater enemies header.
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

## 415.1 Task 144 -> Underwater treasure chests

**Task Number:** 144
**Task Name:** Underwater treasure chests
**Source:** `docs/docs_ORDER_PLAN.md` order 415
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/WaterRenderer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of underwater treasure chests in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/WaterRenderer.cpp
TASK: Implement the smallest compiling slice for: Underwater treasure chests.
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

## 415.1VCPROJ Task 144_VCPROJ -> Underwater treasure chests (Add the new .cpp compile include entry.)

**Task Number:** 144_VCPROJ
**Task Name:** Underwater treasure chests (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 415 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/rendering/d3d11/WaterRenderer.cpp` only.
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

## 415.1FILTER Task 144_FILTER -> Underwater treasure chests (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 144_FILTER
**Task Name:** Underwater treasure chests (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 415 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/rendering/d3d11/WaterRenderer.cpp` only.
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

## 416.1 Task 144H -> Underwater treasure header

**Task Number:** 144H
**Task Name:** Underwater treasure header
**Source:** `docs/docs_ORDER_PLAN.md` order 416
**Status:** Remaining
**File to edit:** `src/rendering/d3d11/WaterRenderer.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Underwater treasure header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of underwater treasure header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/WaterRenderer.hpp
TASK: Implement the smallest compiling slice for: Underwater treasure header.
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
- Paste at: Search for `class`/`struct` declarations related to Underwater treasure header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 417.1 Task 145 -> Diving animation

**Task Number:** 145
**Task Name:** Diving animation
**Source:** `docs/docs_ORDER_PLAN.md` order 417
**Status:** Remaining
**File to edit:** `src/world/WaterVolume.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of diving animation in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WaterVolume.cpp
TASK: Implement the smallest compiling slice for: Diving animation.
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

## 417.1VCPROJ Task 145_VCPROJ -> Diving animation (Add the new .cpp compile include entry.)

**Task Number:** 145_VCPROJ
**Task Name:** Diving animation (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 417 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/WaterVolume.cpp` only.
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

## 417.1FILTER Task 145_FILTER -> Diving animation (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 145_FILTER
**Task Name:** Diving animation (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 417 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/WaterVolume.cpp` only.
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

## 418.1 Task 145H -> Diving animation header

**Task Number:** 145H
**Task Name:** Diving animation header
**Source:** `docs/docs_ORDER_PLAN.md` order 418
**Status:** Remaining
**File to edit:** `src/world/WaterVolume.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Diving animation header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of diving animation header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WaterVolume.hpp
TASK: Implement the smallest compiling slice for: Diving animation header.
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
- Paste at: Search for `class`/`struct` declarations related to Diving animation header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 419.1 Task 146 -> Surface breaking animation

**Task Number:** 146
**Task Name:** Surface breaking animation
**Source:** `docs/docs_ORDER_PLAN.md` order 419
**Status:** Remaining
**File to edit:** `src/game/physics/BuoyancyComponent.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of surface breaking animation in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/physics/BuoyancyComponent.cpp
TASK: Implement the smallest compiling slice for: Surface breaking animation.
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

## 419.1VCPROJ Task 146_VCPROJ -> Surface breaking animation (Add the new .cpp compile include entry.)

**Task Number:** 146_VCPROJ
**Task Name:** Surface breaking animation (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 419 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/physics/BuoyancyComponent.cpp` only.
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

## 419.1FILTER Task 146_FILTER -> Surface breaking animation (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 146_FILTER
**Task Name:** Surface breaking animation (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 419 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/physics/BuoyancyComponent.cpp` only.
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

## 420.1 Task 146H -> Surface breaking header

**Task Number:** 146H
**Task Name:** Surface breaking header
**Source:** `docs/docs_ORDER_PLAN.md` order 420
**Status:** Remaining
**File to edit:** `src/game/physics/BuoyancyComponent.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Surface breaking header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of surface breaking header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/physics/BuoyancyComponent.hpp
TASK: Implement the smallest compiling slice for: Surface breaking header.
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
- Paste at: Search for `class`/`struct` declarations related to Surface breaking header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

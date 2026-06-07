# FULL_TASK_SEQUENCE Reconciliation (SLM micro-tasks)

This file covers remaining unchecked tasks from `docs/FULL_TASK_SEQUENCE.md` that are not currently listed as unfinished in `docs/docs_ORDER_PLAN.md`.
Use these as reconciliation/verification micro-steps to keep both trackers aligned.


## FULL-030A.1 Task 030AA -> Cel shading band quantization

**Task Number:** 030AA
**Task Name:** Cel shading band quantization
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030A (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `Shaders/basic3d_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shading band quantization in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/basic3d_ps.hlsl
TASK: Implement the smallest compiling slice for: Cel shading band quantization.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030A.2 Task 030AB -> Cel shading band quantization

**Task Number:** 030AB
**Task Name:** Cel shading band quantization
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030A (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/rendering/d3d11/D3D11Renderer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Cel shading band quantization and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shading band quantization in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/D3D11Renderer.cpp
TASK: Implement the smallest compiling slice for: Cel shading band quantization.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Cel shading band quantization and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030B.1 Task 030B -> Cel shader shadow tint + rim gate

**Task Number:** 030B
**Task Name:** Cel shader shadow tint + rim gate
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030B (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `Shaders/basic3d_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shader shadow tint + rim gate in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/basic3d_ps.hlsl
TASK: Implement the smallest compiling slice for: Cel shader shadow tint + rim gate.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030C.1 Task 030C -> Cel specular step highlights

**Task Number:** 030C
**Task Name:** Cel specular step highlights
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030C (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `Shaders/basic3d_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel specular step highlights in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/basic3d_ps.hlsl
TASK: Implement the smallest compiling slice for: Cel specular step highlights.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030D.1 Task 030DA -> Cel shader material parameter plumbing

**Task Number:** 030DA
**Task Name:** Cel shader material parameter plumbing
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030D (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/rendering/d3d11/D3D11Renderer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Cel shader material parameter plumbing and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shader material parameter plumbing in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/D3D11Renderer.cpp
TASK: Implement the smallest compiling slice for: Cel shader material parameter plumbing.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Cel shader material parameter plumbing and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030D.2 Task 030DB -> Cel shader material parameter plumbing

**Task Number:** 030DB
**Task Name:** Cel shader material parameter plumbing
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030D (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/assets/AssetLoader.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Cel shader material parameter plumbing and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shader material parameter plumbing in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/assets/AssetLoader.cpp
TASK: Implement the smallest compiling slice for: Cel shader material parameter plumbing.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Cel shader material parameter plumbing and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030D.3 Task 030DC -> Cel shader material parameter plumbing

**Task Number:** 030DC
**Task Name:** Cel shader material parameter plumbing
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030D (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/assets/AssetLoader.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Cel shader material parameter plumbing and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shader material parameter plumbing in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/assets/AssetLoader.hpp
TASK: Implement the smallest compiling slice for: Cel shader material parameter plumbing.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Cel shader material parameter plumbing and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030E.1 Task 030EA -> Character outline pass (inverted hull)

**Task Number:** 030EA
**Task Name:** Character outline pass (inverted hull)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030E (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `Shaders/basic3d_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of character outline pass (inverted hull) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/basic3d_vs.hlsl
TASK: Implement the smallest compiling slice for: Character outline pass (inverted hull).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030E.2 Task 030EB -> Character outline pass (inverted hull)

**Task Number:** 030EB
**Task Name:** Character outline pass (inverted hull)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030E (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `Shaders/basic3d_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of character outline pass (inverted hull) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/basic3d_ps.hlsl
TASK: Implement the smallest compiling slice for: Character outline pass (inverted hull).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030E.3 Task 030EC -> Character outline pass (inverted hull)

**Task Number:** 030EC
**Task Name:** Character outline pass (inverted hull)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030E (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/rendering/d3d11/D3D11Renderer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Character outline pass (inverted hull) and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of character outline pass (inverted hull) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/D3D11Renderer.cpp
TASK: Implement the smallest compiling slice for: Character outline pass (inverted hull).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Character outline pass (inverted hull) and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030F.1 Task 030FA -> Cel shader debug controls + fallback path

**Task Number:** 030FA
**Task Name:** Cel shader debug controls + fallback path
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030F (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/ImGuiLayer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Cel shader debug controls + fallback path and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shader debug controls + fallback path in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ImGuiLayer.cpp
TASK: Implement the smallest compiling slice for: Cel shader debug controls + fallback path.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Cel shader debug controls + fallback path and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030F.2 Task 030FB -> Cel shader debug controls + fallback path

**Task Number:** 030FB
**Task Name:** Cel shader debug controls + fallback path
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030F (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/ImGuiLayer.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Cel shader debug controls + fallback path and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shader debug controls + fallback path in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ImGuiLayer.hpp
TASK: Implement the smallest compiling slice for: Cel shader debug controls + fallback path.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Cel shader debug controls + fallback path and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-030F.3 Task 030FC -> Cel shader debug controls + fallback path

**Task Number:** 030FC
**Task Name:** Cel shader debug controls + fallback path
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 030F (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/rendering/d3d11/D3D11Renderer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Cel shader debug controls + fallback path and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cel shader debug controls + fallback path in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/D3D11Renderer.cpp
TASK: Implement the smallest compiling slice for: Cel shader debug controls + fallback path.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Cel shader debug controls + fallback path and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-042.1 Task 042 -> XP / level system

**Task Number:** 042
**Task Name:** XP / level system
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 042 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/PlayerStats.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to XP / level system and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of xp / level system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/PlayerStats.hpp
TASK: Implement the smallest compiling slice for: XP / level system.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to XP / level system and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-043.1 Task 043 -> Status effects

**Task Number:** 043
**Task Name:** Status effects
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 043 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/PlayerStats.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Status effects and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of status effects in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/PlayerStats.hpp
TASK: Implement the smallest compiling slice for: Status effects.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Status effects and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-046.1 Task 046A -> Quality preset enforcement

**Task Number:** 046A
**Task Name:** Quality preset enforcement
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 046 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/QualityPreset.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Quality preset enforcement and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quality preset enforcement in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/QualityPreset.cpp
TASK: Implement the smallest compiling slice for: Quality preset enforcement.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Quality preset enforcement and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-046.2 Task 046B -> Quality preset enforcement

**Task Number:** 046B
**Task Name:** Quality preset enforcement
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 046 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/QualityPreset.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Quality preset enforcement and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quality preset enforcement in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/QualityPreset.hpp
TASK: Implement the smallest compiling slice for: Quality preset enforcement.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Quality preset enforcement and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-047.1 Task 047A -> Victory fanfare trigger

**Task Number:** 047A
**Task Name:** Victory fanfare trigger
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 047 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Victory fanfare trigger and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of victory fanfare trigger in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Victory fanfare trigger.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Victory fanfare trigger and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-047.2 Task 047B -> Victory fanfare trigger

**Task Number:** 047B
**Task Name:** Victory fanfare trigger
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 047 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Victory fanfare trigger and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of victory fanfare trigger in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Victory fanfare trigger.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Victory fanfare trigger and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-048.1 Task 048A -> Environmental ambient audio

**Task Number:** 048A
**Task Name:** Environmental ambient audio
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 048 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Environmental ambient audio and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of environmental ambient audio in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Environmental ambient audio.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Environmental ambient audio and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-048.2 Task 048B -> Environmental ambient audio

**Task Number:** 048B
**Task Name:** Environmental ambient audio
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 048 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Environmental ambient audio and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of environmental ambient audio in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Environmental ambient audio.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Environmental ambient audio and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-049.1 Task 049A -> Looping BGM

**Task Number:** 049A
**Task Name:** Looping BGM
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 049 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Looping BGM and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of looping bgm in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Looping BGM.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Looping BGM and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-049.2 Task 049B -> Looping BGM

**Task Number:** 049B
**Task Name:** Looping BGM
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 049 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Looping BGM and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of looping bgm in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Looping BGM.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Looping BGM and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-050.1 Task 050A -> Tactical Pause enter / exit SFX

**Task Number:** 050A
**Task Name:** Tactical Pause enter / exit SFX
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 050 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Tactical Pause enter / exit SFX and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of tactical pause enter / exit sfx in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Tactical Pause enter / exit SFX.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Tactical Pause enter / exit SFX and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-050.2 Task 050B -> Tactical Pause enter / exit SFX

**Task Number:** 050B
**Task Name:** Tactical Pause enter / exit SFX
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 050 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Tactical Pause enter / exit SFX and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of tactical pause enter / exit sfx in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Tactical Pause enter / exit SFX.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Tactical Pause enter / exit SFX and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-050.3 Task 050C -> Tactical Pause enter / exit SFX

**Task Number:** 050C
**Task Name:** Tactical Pause enter / exit SFX
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 050 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/TacticalPauseMenu.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Tactical Pause enter / exit SFX and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of tactical pause enter / exit sfx in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/TacticalPauseMenu.cpp
TASK: Implement the smallest compiling slice for: Tactical Pause enter / exit SFX.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Tactical Pause enter / exit SFX and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-050.4 Task 050D -> Tactical Pause enter / exit SFX

**Task Number:** 050D
**Task Name:** Tactical Pause enter / exit SFX
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 050 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/TacticalPauseMenu.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Tactical Pause enter / exit SFX and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of tactical pause enter / exit sfx in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/TacticalPauseMenu.hpp
TASK: Implement the smallest compiling slice for: Tactical Pause enter / exit SFX.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Tactical Pause enter / exit SFX and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-051.1 Task 051A -> Lock-on acquire / break SFX

**Task Number:** 051A
**Task Name:** Lock-on acquire / break SFX
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 051 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Lock-on acquire / break SFX and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of lock-on acquire / break sfx in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Lock-on acquire / break SFX.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Lock-on acquire / break SFX and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-051.2 Task 051B -> Lock-on acquire / break SFX

**Task Number:** 051B
**Task Name:** Lock-on acquire / break SFX
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 051 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Lock-on acquire / break SFX and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of lock-on acquire / break sfx in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Lock-on acquire / break SFX.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Lock-on acquire / break SFX and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-051.3 Task 051C -> Lock-on acquire / break SFX

**Task Number:** 051C
**Task Name:** Lock-on acquire / break SFX
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 051 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/Targeting.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Lock-on acquire / break SFX and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of lock-on acquire / break sfx in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/Targeting.hpp
TASK: Implement the smallest compiling slice for: Lock-on acquire / break SFX.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Lock-on acquire / break SFX and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-052.1 Task 052A -> Enemy alert bark stub

**Task Number:** 052A
**Task Name:** Enemy alert bark stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 052 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Enemy alert bark stub and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy alert bark stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Enemy alert bark stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Enemy alert bark stub and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-052.2 Task 052B -> Enemy alert bark stub

**Task Number:** 052B
**Task Name:** Enemy alert bark stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 052 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Enemy alert bark stub and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy alert bark stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Enemy alert bark stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Enemy alert bark stub and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-052.3 Task 052C -> Enemy alert bark stub

**Task Number:** 052C
**Task Name:** Enemy alert bark stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 052 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/EnemyActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Enemy alert bark stub and insert near similar runtime logic blocks.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy alert bark stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/EnemyActor.cpp
TASK: Implement the smallest compiling slice for: Enemy alert bark stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Enemy alert bark stub and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-052.4 Task 052D -> Enemy alert bark stub

**Task Number:** 052D
**Task Name:** Enemy alert bark stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 052 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/EnemyActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Enemy alert bark stub and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy alert bark stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/EnemyActor.hpp
TASK: Implement the smallest compiling slice for: Enemy alert bark stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Enemy alert bark stub and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-053.1 Task 053A -> Equipment slot stub

**Task Number:** 053A
**Task Name:** Equipment slot stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 053 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/inventory/Equipment.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Equipment slot stub and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of equipment slot stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/Equipment.hpp
TASK: Implement the smallest compiling slice for: Equipment slot stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Equipment slot stub and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-053.2 Task 053B -> Equipment slot stub

**Task Number:** 053B
**Task Name:** Equipment slot stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 053 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/PlayerStats.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Equipment slot stub and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of equipment slot stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/PlayerStats.hpp
TASK: Implement the smallest compiling slice for: Equipment slot stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Equipment slot stub and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-054.1 Task 054A -> Ability unlock / progression hook

**Task Number:** 054A
**Task Name:** Ability unlock / progression hook
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 054 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/progression/AbilityProgression.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Ability unlock / progression hook and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of ability unlock / progression hook in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/AbilityProgression.hpp
TASK: Implement the smallest compiling slice for: Ability unlock / progression hook.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Ability unlock / progression hook and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-054.2 Task 054B -> Ability unlock / progression hook

**Task Number:** 054B
**Task Name:** Ability unlock / progression hook
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 054 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/PlayerStats.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Ability unlock / progression hook and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of ability unlock / progression hook in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/PlayerStats.hpp
TASK: Implement the smallest compiling slice for: Ability unlock / progression hook.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Ability unlock / progression hook and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-055.1 Task 055A -> Combat stat modifier pipeline stub

**Task Number:** 055A
**Task Name:** Combat stat modifier pipeline stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 055 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatModifiers.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Combat stat modifier pipeline stub and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of combat stat modifier pipeline stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatModifiers.hpp
TASK: Implement the smallest compiling slice for: Combat stat modifier pipeline stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Combat stat modifier pipeline stub and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-055.2 Task 055B -> Combat stat modifier pipeline stub

**Task Number:** 055B
**Task Name:** Combat stat modifier pipeline stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 055 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Combat stat modifier pipeline stub and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of combat stat modifier pipeline stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.cpp
TASK: Implement the smallest compiling slice for: Combat stat modifier pipeline stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Combat stat modifier pipeline stub and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-055.3 Task 055C -> Combat stat modifier pipeline stub

**Task Number:** 055C
**Task Name:** Combat stat modifier pipeline stub
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 055 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Combat stat modifier pipeline stub and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of combat stat modifier pipeline stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.hpp
TASK: Implement the smallest compiling slice for: Combat stat modifier pipeline stub.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Combat stat modifier pipeline stub and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-061.1 Task 061A -> World partition + region streaming core

**Task Number:** 061A
**Task Name:** World partition + region streaming core
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 061 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldPartition.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for World partition + region streaming core and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of world partition + region streaming core in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldPartition.cpp
TASK: Implement the smallest compiling slice for: World partition + region streaming core.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for World partition + region streaming core and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-061.2 Task 061B -> World partition + region streaming core

**Task Number:** 061B
**Task Name:** World partition + region streaming core
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 061 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldPartition.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to World partition + region streaming core and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of world partition + region streaming core in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldPartition.hpp
TASK: Implement the smallest compiling slice for: World partition + region streaming core.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to World partition + region streaming core and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-061.3 Task 061C -> World partition + region streaming core

**Task Number:** 061C
**Task Name:** World partition + region streaming core
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 061 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldGrid.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for World partition + region streaming core and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of world partition + region streaming core in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldGrid.cpp
TASK: Implement the smallest compiling slice for: World partition + region streaming core.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for World partition + region streaming core and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-061.4 Task 061D -> World partition + region streaming core

**Task Number:** 061D
**Task Name:** World partition + region streaming core
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 061 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldGrid.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to World partition + region streaming core and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of world partition + region streaming core in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldGrid.hpp
TASK: Implement the smallest compiling slice for: World partition + region streaming core.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to World partition + region streaming core and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-062.1 Task 062A -> Asynchronous chunk IO + prefetch queue

**Task Number:** 062A
**Task Name:** Asynchronous chunk IO + prefetch queue
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 062 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/StreamingIO.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Asynchronous chunk IO + prefetch queue and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of asynchronous chunk io + prefetch queue in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/StreamingIO.cpp
TASK: Implement the smallest compiling slice for: Asynchronous chunk IO + prefetch queue.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Asynchronous chunk IO + prefetch queue and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-062.2 Task 062B -> Asynchronous chunk IO + prefetch queue

**Task Number:** 062B
**Task Name:** Asynchronous chunk IO + prefetch queue
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 062 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/StreamingIO.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Asynchronous chunk IO + prefetch queue and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of asynchronous chunk io + prefetch queue in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/StreamingIO.hpp
TASK: Implement the smallest compiling slice for: Asynchronous chunk IO + prefetch queue.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Asynchronous chunk IO + prefetch queue and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-062.3 Task 062C -> Asynchronous chunk IO + prefetch queue

**Task Number:** 062C
**Task Name:** Asynchronous chunk IO + prefetch queue
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 062 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/assets/AssetLoader.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Asynchronous chunk IO + prefetch queue and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of asynchronous chunk io + prefetch queue in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/assets/AssetLoader.hpp
TASK: Implement the smallest compiling slice for: Asynchronous chunk IO + prefetch queue.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Asynchronous chunk IO + prefetch queue and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-063.1 Task 063A -> Large-world coordinate rebasing

**Task Number:** 063A
**Task Name:** Large-world coordinate rebasing
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 063 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldOriginRebase.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Large-world coordinate rebasing and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of large-world coordinate rebasing in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldOriginRebase.cpp
TASK: Implement the smallest compiling slice for: Large-world coordinate rebasing.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Large-world coordinate rebasing and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-063.2 Task 063B -> Large-world coordinate rebasing

**Task Number:** 063B
**Task Name:** Large-world coordinate rebasing
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 063 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldOriginRebase.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Large-world coordinate rebasing and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of large-world coordinate rebasing in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldOriginRebase.hpp
TASK: Implement the smallest compiling slice for: Large-world coordinate rebasing.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Large-world coordinate rebasing and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-063.3 Task 063C -> Large-world coordinate rebasing

**Task Number:** 063C
**Task Name:** Large-world coordinate rebasing
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 063 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/Main.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Large-world coordinate rebasing and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of large-world coordinate rebasing in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/Main.cpp
TASK: Implement the smallest compiling slice for: Large-world coordinate rebasing.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Large-world coordinate rebasing and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-064.1 Task 064A -> Terrain/mesh LOD tier manager

**Task Number:** 064A
**Task Name:** Terrain/mesh LOD tier manager
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 064 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldLodManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Terrain/mesh LOD tier manager and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of terrain/mesh lod tier manager in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldLodManager.cpp
TASK: Implement the smallest compiling slice for: Terrain/mesh LOD tier manager.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Terrain/mesh LOD tier manager and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-064.2 Task 064B -> Terrain/mesh LOD tier manager

**Task Number:** 064B
**Task Name:** Terrain/mesh LOD tier manager
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 064 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldLodManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Terrain/mesh LOD tier manager and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of terrain/mesh lod tier manager in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldLodManager.hpp
TASK: Implement the smallest compiling slice for: Terrain/mesh LOD tier manager.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Terrain/mesh LOD tier manager and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-064.3 Task 064C -> Terrain/mesh LOD tier manager

**Task Number:** 064C
**Task Name:** Terrain/mesh LOD tier manager
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 064 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/rendering/d3d11/D3D11Renderer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Terrain/mesh LOD tier manager and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of terrain/mesh lod tier manager in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/D3D11Renderer.cpp
TASK: Implement the smallest compiling slice for: Terrain/mesh LOD tier manager.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Terrain/mesh LOD tier manager and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-064.4 Task 064D -> Terrain/mesh LOD tier manager

**Task Number:** 064D
**Task Name:** Terrain/mesh LOD tier manager
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 064 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/rendering/d3d11/D3D11Renderer.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Terrain/mesh LOD tier manager and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of terrain/mesh lod tier manager in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/rendering/d3d11/D3D11Renderer.hpp
TASK: Implement the smallest compiling slice for: Terrain/mesh LOD tier manager.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Terrain/mesh LOD tier manager and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-065.1 Task 065A -> Streaming budget governor (CPU/GPU/IO)

**Task Number:** 065A
**Task Name:** Streaming budget governor (CPU/GPU/IO)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 065 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/StreamingBudget.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Streaming budget governor (CPU/GPU/IO) and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of streaming budget governor (cpu/gpu/io) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/StreamingBudget.hpp
TASK: Implement the smallest compiling slice for: Streaming budget governor (CPU/GPU/IO).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Streaming budget governor (CPU/GPU/IO) and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-065.2 Task 065B -> Streaming budget governor (CPU/GPU/IO)

**Task Number:** 065B
**Task Name:** Streaming budget governor (CPU/GPU/IO)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 065 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldGrid.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Streaming budget governor (CPU/GPU/IO) and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of streaming budget governor (cpu/gpu/io) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldGrid.cpp
TASK: Implement the smallest compiling slice for: Streaming budget governor (CPU/GPU/IO).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Streaming budget governor (CPU/GPU/IO) and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-065.3 Task 065C -> Streaming budget governor (CPU/GPU/IO)

**Task Number:** 065C
**Task Name:** Streaming budget governor (CPU/GPU/IO)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 065 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/WorldGrid.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Streaming budget governor (CPU/GPU/IO) and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of streaming budget governor (cpu/gpu/io) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/WorldGrid.hpp
TASK: Implement the smallest compiling slice for: Streaming budget governor (CPU/GPU/IO).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Streaming budget governor (CPU/GPU/IO) and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-066.1 Task 066A -> Far-distance continent impostors

**Task Number:** 066A
**Task Name:** Far-distance continent impostors
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 066 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/ContinentImpostor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Far-distance continent impostors and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of far-distance continent impostors in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/ContinentImpostor.cpp
TASK: Implement the smallest compiling slice for: Far-distance continent impostors.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Far-distance continent impostors and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-066.2 Task 066B -> Far-distance continent impostors

**Task Number:** 066B
**Task Name:** Far-distance continent impostors
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 066 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/ContinentImpostor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Far-distance continent impostors and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of far-distance continent impostors in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/ContinentImpostor.hpp
TASK: Implement the smallest compiling slice for: Far-distance continent impostors.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Far-distance continent impostors and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-066.3 Task 066C -> Far-distance continent impostors

**Task Number:** 066C
**Task Name:** Far-distance continent impostors
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 066 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `Shaders/continent_impostor_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of far-distance continent impostors in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/continent_impostor_vs.hlsl
TASK: Implement the smallest compiling slice for: Far-distance continent impostors.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-084.1 Task 084A -> Guard-break / poise combat pipeline

**Task Number:** 084A
**Task Name:** Guard-break / poise combat pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 084 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/PoiseSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Guard-break / poise combat pipeline and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of guard-break / poise combat pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/PoiseSystem.cpp
TASK: Implement the smallest compiling slice for: Guard-break / poise combat pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Guard-break / poise combat pipeline and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-084.2 Task 084B -> Guard-break / poise combat pipeline

**Task Number:** 084B
**Task Name:** Guard-break / poise combat pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 084 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/PoiseSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Guard-break / poise combat pipeline and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of guard-break / poise combat pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/PoiseSystem.hpp
TASK: Implement the smallest compiling slice for: Guard-break / poise combat pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Guard-break / poise combat pipeline and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-084.3 Task 084C -> Guard-break / poise combat pipeline

**Task Number:** 084C
**Task Name:** Guard-break / poise combat pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 084 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Guard-break / poise combat pipeline and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of guard-break / poise combat pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.cpp
TASK: Implement the smallest compiling slice for: Guard-break / poise combat pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Guard-break / poise combat pipeline and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-084.4 Task 084D -> Guard-break / poise combat pipeline

**Task Number:** 084D
**Task Name:** Guard-break / poise combat pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 084 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Guard-break / poise combat pipeline and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of guard-break / poise combat pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.hpp
TASK: Implement the smallest compiling slice for: Guard-break / poise combat pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Guard-break / poise combat pipeline and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-085.1 Task 085A -> Elemental damage/resistance matrix

**Task Number:** 085A
**Task Name:** Elemental damage/resistance matrix
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 085 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/ElementSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Elemental damage/resistance matrix and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of elemental damage/resistance matrix in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/ElementSystem.hpp
TASK: Implement the smallest compiling slice for: Elemental damage/resistance matrix.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Elemental damage/resistance matrix and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-085.2 Task 085B -> Elemental damage/resistance matrix

**Task Number:** 085B
**Task Name:** Elemental damage/resistance matrix
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 085 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Elemental damage/resistance matrix and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of elemental damage/resistance matrix in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.cpp
TASK: Implement the smallest compiling slice for: Elemental damage/resistance matrix.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Elemental damage/resistance matrix and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-085.3 Task 085C -> Elemental damage/resistance matrix

**Task Number:** 085C
**Task Name:** Elemental damage/resistance matrix
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 085 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Elemental damage/resistance matrix and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of elemental damage/resistance matrix in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.hpp
TASK: Implement the smallest compiling slice for: Elemental damage/resistance matrix.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Elemental damage/resistance matrix and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-086.1 Task 086A -> Status ailment counters + immunity windows

**Task Number:** 086A
**Task Name:** Status ailment counters + immunity windows
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 086 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/StatusAilmentSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Status ailment counters + immunity windows and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of status ailment counters + immunity windows in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/StatusAilmentSystem.cpp
TASK: Implement the smallest compiling slice for: Status ailment counters + immunity windows.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Status ailment counters + immunity windows and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-086.2 Task 086B -> Status ailment counters + immunity windows

**Task Number:** 086B
**Task Name:** Status ailment counters + immunity windows
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 086 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/StatusAilmentSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Status ailment counters + immunity windows and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of status ailment counters + immunity windows in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/StatusAilmentSystem.hpp
TASK: Implement the smallest compiling slice for: Status ailment counters + immunity windows.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Status ailment counters + immunity windows and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-086.3 Task 086C -> Status ailment counters + immunity windows

**Task Number:** 086C
**Task Name:** Status ailment counters + immunity windows
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 086 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/PlayerStats.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Status ailment counters + immunity windows and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of status ailment counters + immunity windows in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/PlayerStats.hpp
TASK: Implement the smallest compiling slice for: Status ailment counters + immunity windows.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Status ailment counters + immunity windows and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-087.1 Task 087A -> Equipment progression + socket rules

**Task Number:** 087A
**Task Name:** Equipment progression + socket rules
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 087 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/inventory/EquipmentProgression.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of equipment progression + socket rules in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/EquipmentProgression.cpp
TASK: Implement the smallest compiling slice for: Equipment progression + socket rules.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-087.2 Task 087B -> Equipment progression + socket rules

**Task Number:** 087B
**Task Name:** Equipment progression + socket rules
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 087 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/inventory/EquipmentProgression.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Equipment progression + socket rules and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of equipment progression + socket rules in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/EquipmentProgression.hpp
TASK: Implement the smallest compiling slice for: Equipment progression + socket rules.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Equipment progression + socket rules and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-087.3 Task 087C -> Equipment progression + socket rules

**Task Number:** 087C
**Task Name:** Equipment progression + socket rules
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 087 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/inventory/Equipment.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Equipment progression + socket rules and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of equipment progression + socket rules in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/Equipment.hpp
TASK: Implement the smallest compiling slice for: Equipment progression + socket rules.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Equipment progression + socket rules and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-088.1 Task 088A -> Skill tree graph + unlock prerequisites

**Task Number:** 088A
**Task Name:** Skill tree graph + unlock prerequisites
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 088 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/progression/SkillTree.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of skill tree graph + unlock prerequisites in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/SkillTree.cpp
TASK: Implement the smallest compiling slice for: Skill tree graph + unlock prerequisites.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-088.2 Task 088B -> Skill tree graph + unlock prerequisites

**Task Number:** 088B
**Task Name:** Skill tree graph + unlock prerequisites
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 088 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/progression/SkillTree.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Skill tree graph + unlock prerequisites and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of skill tree graph + unlock prerequisites in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/SkillTree.hpp
TASK: Implement the smallest compiling slice for: Skill tree graph + unlock prerequisites.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Skill tree graph + unlock prerequisites and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-088.3 Task 088C -> Skill tree graph + unlock prerequisites

**Task Number:** 088C
**Task Name:** Skill tree graph + unlock prerequisites
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 088 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/progression/AbilityProgression.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Skill tree graph + unlock prerequisites and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of skill tree graph + unlock prerequisites in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/AbilityProgression.hpp
TASK: Implement the smallest compiling slice for: Skill tree graph + unlock prerequisites.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Skill tree graph + unlock prerequisites and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-089.1 Task 089A -> Loot table tiers + drop weighting

**Task Number:** 089A
**Task Name:** Loot table tiers + drop weighting
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 089 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/loot/LootTable.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of loot table tiers + drop weighting in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/loot/LootTable.cpp
TASK: Implement the smallest compiling slice for: Loot table tiers + drop weighting.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-089.2 Task 089B -> Loot table tiers + drop weighting

**Task Number:** 089B
**Task Name:** Loot table tiers + drop weighting
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 089 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/loot/LootTable.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Loot table tiers + drop weighting and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of loot table tiers + drop weighting in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/loot/LootTable.hpp
TASK: Implement the smallest compiling slice for: Loot table tiers + drop weighting.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Loot table tiers + drop weighting and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-089.3 Task 089C -> Loot table tiers + drop weighting

**Task Number:** 089C
**Task Name:** Loot table tiers + drop weighting
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 089 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/EnemyActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Loot table tiers + drop weighting and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of loot table tiers + drop weighting in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/EnemyActor.cpp
TASK: Implement the smallest compiling slice for: Loot table tiers + drop weighting.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Loot table tiers + drop weighting and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-089.4 Task 089D -> Loot table tiers + drop weighting

**Task Number:** 089D
**Task Name:** Loot table tiers + drop weighting
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 089 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/EnemyActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Loot table tiers + drop weighting and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of loot table tiers + drop weighting in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/EnemyActor.hpp
TASK: Implement the smallest compiling slice for: Loot table tiers + drop weighting.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Loot table tiers + drop weighting and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-090.1 Task 090A -> Crafting + upgrade station flow

**Task Number:** 090A
**Task Name:** Crafting + upgrade station flow
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 090 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/crafting/CraftingSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of crafting + upgrade station flow in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/crafting/CraftingSystem.cpp
TASK: Implement the smallest compiling slice for: Crafting + upgrade station flow.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-090.2 Task 090B -> Crafting + upgrade station flow

**Task Number:** 090B
**Task Name:** Crafting + upgrade station flow
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 090 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/crafting/CraftingSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Crafting + upgrade station flow and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of crafting + upgrade station flow in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/crafting/CraftingSystem.hpp
TASK: Implement the smallest compiling slice for: Crafting + upgrade station flow.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Crafting + upgrade station flow and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-090.3 Task 090C -> Crafting + upgrade station flow

**Task Number:** 090C
**Task Name:** Crafting + upgrade station flow
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 090 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/RestPointActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of crafting + upgrade station flow in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/RestPointActor.cpp
TASK: Implement the smallest compiling slice for: Crafting + upgrade station flow.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-090.4 Task 090D -> Crafting + upgrade station flow

**Task Number:** 090D
**Task Name:** Crafting + upgrade station flow
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 090 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/actors/RestPointActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Crafting + upgrade station flow and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of crafting + upgrade station flow in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/RestPointActor.hpp
TASK: Implement the smallest compiling slice for: Crafting + upgrade station flow.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Crafting + upgrade station flow and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-091.1 Task 091A -> Open-world encounter director

**Task Number:** 091A
**Task Name:** Open-world encounter director
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 091 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/ai/EncounterDirector.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of open-world encounter director in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/EncounterDirector.cpp
TASK: Implement the smallest compiling slice for: Open-world encounter director.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-091.2 Task 091B -> Open-world encounter director

**Task Number:** 091B
**Task Name:** Open-world encounter director
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 091 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/ai/EncounterDirector.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Open-world encounter director and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of open-world encounter director in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/EncounterDirector.hpp
TASK: Implement the smallest compiling slice for: Open-world encounter director.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Open-world encounter director and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-091.3 Task 091C -> Open-world encounter director

**Task Number:** 091C
**Task Name:** Open-world encounter director
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 091 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/PopulationDirector.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of open-world encounter director in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/PopulationDirector.cpp
TASK: Implement the smallest compiling slice for: Open-world encounter director.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-091.4 Task 091D -> Open-world encounter director

**Task Number:** 091D
**Task Name:** Open-world encounter director
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 091 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/world/PopulationDirector.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Open-world encounter director and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of open-world encounter director in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/PopulationDirector.hpp
TASK: Implement the smallest compiling slice for: Open-world encounter director.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Open-world encounter director and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-092.1 Task 092A -> Combat telemetry + balance debug panel

**Task Number:** 092A
**Task Name:** Combat telemetry + balance debug panel
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 092 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/CombatDebugPanel.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of combat telemetry + balance debug panel in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CombatDebugPanel.cpp
TASK: Implement the smallest compiling slice for: Combat telemetry + balance debug panel.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-092.2 Task 092B -> Combat telemetry + balance debug panel

**Task Number:** 092B
**Task Name:** Combat telemetry + balance debug panel
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 092 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/CombatDebugPanel.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Combat telemetry + balance debug panel and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of combat telemetry + balance debug panel in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CombatDebugPanel.hpp
TASK: Implement the smallest compiling slice for: Combat telemetry + balance debug panel.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Combat telemetry + balance debug panel and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-092.3 Task 092C -> Combat telemetry + balance debug panel

**Task Number:** 092C
**Task Name:** Combat telemetry + balance debug panel
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 092 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Combat telemetry + balance debug panel and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of combat telemetry + balance debug panel in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.cpp
TASK: Implement the smallest compiling slice for: Combat telemetry + balance debug panel.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Combat telemetry + balance debug panel and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-092.4 Task 092D -> Combat telemetry + balance debug panel

**Task Number:** 092D
**Task Name:** Combat telemetry + balance debug panel
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 092 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/combat/CombatSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Combat telemetry + balance debug panel and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of combat telemetry + balance debug panel in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/CombatSystem.hpp
TASK: Implement the smallest compiling slice for: Combat telemetry + balance debug panel.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Combat telemetry + balance debug panel and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-093.1 Task 093A -> Quest authoring schema + validator

**Task Number:** 093A
**Task Name:** Quest authoring schema + validator
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 093 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/quest/QuestSchema.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Quest authoring schema + validator and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest authoring schema + validator in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestSchema.hpp
TASK: Implement the smallest compiling slice for: Quest authoring schema + validator.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Quest authoring schema + validator and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-093.2 Task 093B -> Quest authoring schema + validator

**Task Number:** 093B
**Task Name:** Quest authoring schema + validator
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 093 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/quest/QuestSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest authoring schema + validator in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestSystem.cpp
TASK: Implement the smallest compiling slice for: Quest authoring schema + validator.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-093.3 Task 093C -> Quest authoring schema + validator

**Task Number:** 093C
**Task Name:** Quest authoring schema + validator
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 093 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/quest/QuestSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Quest authoring schema + validator and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of quest authoring schema + validator in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestSystem.hpp
TASK: Implement the smallest compiling slice for: Quest authoring schema + validator.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Quest authoring schema + validator and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-094.1 Task 094A -> Dialogue branching + localization keys

**Task Number:** 094A
**Task Name:** Dialogue branching + localization keys
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 094 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/dialogue/DialogueRuntime.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue branching + localization keys in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/dialogue/DialogueRuntime.cpp
TASK: Implement the smallest compiling slice for: Dialogue branching + localization keys.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-094.2 Task 094B -> Dialogue branching + localization keys

**Task Number:** 094B
**Task Name:** Dialogue branching + localization keys
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 094 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/dialogue/DialogueRuntime.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Dialogue branching + localization keys and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue branching + localization keys in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/dialogue/DialogueRuntime.hpp
TASK: Implement the smallest compiling slice for: Dialogue branching + localization keys.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Dialogue branching + localization keys and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-094.3 Task 094C -> Dialogue branching + localization keys

**Task Number:** 094C
**Task Name:** Dialogue branching + localization keys
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 094 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/DialogBox.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Dialogue branching + localization keys and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue branching + localization keys in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/DialogBox.cpp
TASK: Implement the smallest compiling slice for: Dialogue branching + localization keys.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Dialogue branching + localization keys and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-094.4 Task 094D -> Dialogue branching + localization keys

**Task Number:** 094D
**Task Name:** Dialogue branching + localization keys
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 094 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/DialogBox.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Dialogue branching + localization keys and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dialogue branching + localization keys in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/DialogBox.hpp
TASK: Implement the smallest compiling slice for: Dialogue branching + localization keys.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Dialogue branching + localization keys and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-095.1 Task 095A -> Cutscene timeline stub + camera rails

**Task Number:** 095A
**Task Name:** Cutscene timeline stub + camera rails
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 095 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/cutscene/CutsceneTimeline.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene timeline stub + camera rails in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/cutscene/CutsceneTimeline.cpp
TASK: Implement the smallest compiling slice for: Cutscene timeline stub + camera rails.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-095.2 Task 095B -> Cutscene timeline stub + camera rails

**Task Number:** 095B
**Task Name:** Cutscene timeline stub + camera rails
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 095 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/cutscene/CutsceneTimeline.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Cutscene timeline stub + camera rails and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene timeline stub + camera rails in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/cutscene/CutsceneTimeline.hpp
TASK: Implement the smallest compiling slice for: Cutscene timeline stub + camera rails.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Cutscene timeline stub + camera rails and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-095.3 Task 095C -> Cutscene timeline stub + camera rails

**Task Number:** 095C
**Task Name:** Cutscene timeline stub + camera rails
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 095 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/CameraController.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Cutscene timeline stub + camera rails and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene timeline stub + camera rails in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/CameraController.cpp
TASK: Implement the smallest compiling slice for: Cutscene timeline stub + camera rails.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Cutscene timeline stub + camera rails and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-095.4 Task 095D -> Cutscene timeline stub + camera rails

**Task Number:** 095D
**Task Name:** Cutscene timeline stub + camera rails
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 095 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/CameraController.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Cutscene timeline stub + camera rails and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of cutscene timeline stub + camera rails in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/CameraController.hpp
TASK: Implement the smallest compiling slice for: Cutscene timeline stub + camera rails.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Cutscene timeline stub + camera rails and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-096.1 Task 096A -> Audio event router + mixer bus controls

**Task Number:** 096A
**Task Name:** Audio event router + mixer bus controls
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 096 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioRouter.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of audio event router + mixer bus controls in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioRouter.cpp
TASK: Implement the smallest compiling slice for: Audio event router + mixer bus controls.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-096.2 Task 096B -> Audio event router + mixer bus controls

**Task Number:** 096B
**Task Name:** Audio event router + mixer bus controls
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 096 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioRouter.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Audio event router + mixer bus controls and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of audio event router + mixer bus controls in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioRouter.hpp
TASK: Implement the smallest compiling slice for: Audio event router + mixer bus controls.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Audio event router + mixer bus controls and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-096.3 Task 096C -> Audio event router + mixer bus controls

**Task Number:** 096C
**Task Name:** Audio event router + mixer bus controls
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 096 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Audio event router + mixer bus controls and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of audio event router + mixer bus controls in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Audio event router + mixer bus controls.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Audio event router + mixer bus controls and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-096.4 Task 096D -> Audio event router + mixer bus controls

**Task Number:** 096D
**Task Name:** Audio event router + mixer bus controls
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 096 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Audio event router + mixer bus controls and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of audio event router + mixer bus controls in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Audio event router + mixer bus controls.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Audio event router + mixer bus controls and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-097.1 Task 097A -> Adaptive music state machine

**Task Number:** 097A
**Task Name:** Adaptive music state machine
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 097 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/MusicStateMachine.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of adaptive music state machine in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/MusicStateMachine.cpp
TASK: Implement the smallest compiling slice for: Adaptive music state machine.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-097.2 Task 097B -> Adaptive music state machine

**Task Number:** 097B
**Task Name:** Adaptive music state machine
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 097 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/MusicStateMachine.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Adaptive music state machine and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of adaptive music state machine in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/MusicStateMachine.hpp
TASK: Implement the smallest compiling slice for: Adaptive music state machine.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Adaptive music state machine and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-097.3 Task 097C -> Adaptive music state machine

**Task Number:** 097C
**Task Name:** Adaptive music state machine
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 097 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Adaptive music state machine and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of adaptive music state machine in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: Adaptive music state machine.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Adaptive music state machine and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-097.4 Task 097D -> Adaptive music state machine

**Task Number:** 097D
**Task Name:** Adaptive music state machine
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 097 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Adaptive music state machine and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of adaptive music state machine in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: Adaptive music state machine.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Adaptive music state machine and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-098.1 Task 098A -> SFX variation + distance/occlusion rules

**Task Number:** 098A
**Task Name:** SFX variation + distance/occlusion rules
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 098 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/SfxSpatialRules.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of sfx variation + distance/occlusion rules in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/SfxSpatialRules.cpp
TASK: Implement the smallest compiling slice for: SFX variation + distance/occlusion rules.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-098.2 Task 098B -> SFX variation + distance/occlusion rules

**Task Number:** 098B
**Task Name:** SFX variation + distance/occlusion rules
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 098 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/SfxSpatialRules.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to SFX variation + distance/occlusion rules and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of sfx variation + distance/occlusion rules in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/SfxSpatialRules.hpp
TASK: Implement the smallest compiling slice for: SFX variation + distance/occlusion rules.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to SFX variation + distance/occlusion rules and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-098.3 Task 098C -> SFX variation + distance/occlusion rules

**Task Number:** 098C
**Task Name:** SFX variation + distance/occlusion rules
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 098 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for SFX variation + distance/occlusion rules and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of sfx variation + distance/occlusion rules in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.cpp
TASK: Implement the smallest compiling slice for: SFX variation + distance/occlusion rules.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for SFX variation + distance/occlusion rules and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-098.4 Task 098D -> SFX variation + distance/occlusion rules

**Task Number:** 098D
**Task Name:** SFX variation + distance/occlusion rules
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 098 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/AudioManager.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to SFX variation + distance/occlusion rules and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of sfx variation + distance/occlusion rules in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/AudioManager.hpp
TASK: Implement the smallest compiling slice for: SFX variation + distance/occlusion rules.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to SFX variation + distance/occlusion rules and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-099.1 Task 099A -> Voice placeholder + subtitle timing pipeline

**Task Number:** 099A
**Task Name:** Voice placeholder + subtitle timing pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 099 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/VoicePlayback.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of voice placeholder + subtitle timing pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/VoicePlayback.cpp
TASK: Implement the smallest compiling slice for: Voice placeholder + subtitle timing pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-099.2 Task 099B -> Voice placeholder + subtitle timing pipeline

**Task Number:** 099B
**Task Name:** Voice placeholder + subtitle timing pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 099 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/audio/VoicePlayback.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Voice placeholder + subtitle timing pipeline and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of voice placeholder + subtitle timing pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/audio/VoicePlayback.hpp
TASK: Implement the smallest compiling slice for: Voice placeholder + subtitle timing pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Voice placeholder + subtitle timing pipeline and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-099.3 Task 099C -> Voice placeholder + subtitle timing pipeline

**Task Number:** 099C
**Task Name:** Voice placeholder + subtitle timing pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 099 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/SubtitleOverlay.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of voice placeholder + subtitle timing pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/SubtitleOverlay.cpp
TASK: Implement the smallest compiling slice for: Voice placeholder + subtitle timing pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-099.4 Task 099D -> Voice placeholder + subtitle timing pipeline

**Task Number:** 099D
**Task Name:** Voice placeholder + subtitle timing pipeline
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 099 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/SubtitleOverlay.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Voice placeholder + subtitle timing pipeline and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of voice placeholder + subtitle timing pipeline in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/SubtitleOverlay.hpp
TASK: Implement the smallest compiling slice for: Voice placeholder + subtitle timing pipeline.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Voice placeholder + subtitle timing pipeline and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-100.1 Task 100A -> Save versioning + migration compatibility

**Task Number:** 100A
**Task Name:** Save versioning + migration compatibility
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 100 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/SaveMigration.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of save versioning + migration compatibility in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/SaveMigration.cpp
TASK: Implement the smallest compiling slice for: Save versioning + migration compatibility.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-100.2 Task 100B -> Save versioning + migration compatibility

**Task Number:** 100B
**Task Name:** Save versioning + migration compatibility
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 100 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/SaveMigration.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Save versioning + migration compatibility and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of save versioning + migration compatibility in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/SaveMigration.hpp
TASK: Implement the smallest compiling slice for: Save versioning + migration compatibility.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Save versioning + migration compatibility and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-100.3 Task 100C -> Save versioning + migration compatibility

**Task Number:** 100C
**Task Name:** Save versioning + migration compatibility
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 100 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/SaveSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of save versioning + migration compatibility in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/SaveSystem.cpp
TASK: Implement the smallest compiling slice for: Save versioning + migration compatibility.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-100.4 Task 100D -> Save versioning + migration compatibility

**Task Number:** 100D
**Task Name:** Save versioning + migration compatibility
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 100 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/SaveSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Save versioning + migration compatibility and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of save versioning + migration compatibility in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/SaveSystem.hpp
TASK: Implement the smallest compiling slice for: Save versioning + migration compatibility.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Save versioning + migration compatibility and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-101.1 Task 101A -> Crash capture + runtime diagnostics pack

**Task Number:** 101A
**Task Name:** Crash capture + runtime diagnostics pack
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 101 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/CrashDiagnostics.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of crash capture + runtime diagnostics pack in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/CrashDiagnostics.cpp
TASK: Implement the smallest compiling slice for: Crash capture + runtime diagnostics pack.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-101.2 Task 101B -> Crash capture + runtime diagnostics pack

**Task Number:** 101B
**Task Name:** Crash capture + runtime diagnostics pack
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 101 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/CrashDiagnostics.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Crash capture + runtime diagnostics pack and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of crash capture + runtime diagnostics pack in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/CrashDiagnostics.hpp
TASK: Implement the smallest compiling slice for: Crash capture + runtime diagnostics pack.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Crash capture + runtime diagnostics pack and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-101.3 Task 101C -> Crash capture + runtime diagnostics pack

**Task Number:** 101C
**Task Name:** Crash capture + runtime diagnostics pack
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 101 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/logger/Logger.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Crash capture + runtime diagnostics pack and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of crash capture + runtime diagnostics pack in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/logger/Logger.hpp
TASK: Implement the smallest compiling slice for: Crash capture + runtime diagnostics pack.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Crash capture + runtime diagnostics pack and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-102.1 Task 102A -> Full settings menu (graphics/audio/input/accessibility)

**Task Number:** 102A
**Task Name:** Full settings menu (graphics/audio/input/accessibility)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 102 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/SettingsMenu.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of full settings menu (graphics/audio/input/accessibility) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/SettingsMenu.cpp
TASK: Implement the smallest compiling slice for: Full settings menu (graphics/audio/input/accessibility).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-102.2 Task 102B -> Full settings menu (graphics/audio/input/accessibility)

**Task Number:** 102B
**Task Name:** Full settings menu (graphics/audio/input/accessibility)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 102 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/SettingsMenu.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Full settings menu (graphics/audio/input/accessibility) and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of full settings menu (graphics/audio/input/accessibility) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/SettingsMenu.hpp
TASK: Implement the smallest compiling slice for: Full settings menu (graphics/audio/input/accessibility).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Full settings menu (graphics/audio/input/accessibility) and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-102.3 Task 102C -> Full settings menu (graphics/audio/input/accessibility)

**Task Number:** 102C
**Task Name:** Full settings menu (graphics/audio/input/accessibility)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 102 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/QualityPreset.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Full settings menu (graphics/audio/input/accessibility) and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of full settings menu (graphics/audio/input/accessibility) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/QualityPreset.cpp
TASK: Implement the smallest compiling slice for: Full settings menu (graphics/audio/input/accessibility).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Full settings menu (graphics/audio/input/accessibility) and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-102.4 Task 102D -> Full settings menu (graphics/audio/input/accessibility)

**Task Number:** 102D
**Task Name:** Full settings menu (graphics/audio/input/accessibility)
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 102 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/QualityPreset.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Full settings menu (graphics/audio/input/accessibility) and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of full settings menu (graphics/audio/input/accessibility) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/QualityPreset.hpp
TASK: Implement the smallest compiling slice for: Full settings menu (graphics/audio/input/accessibility).
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Full settings menu (graphics/audio/input/accessibility) and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-103.1 Task 103A -> Input rebinding + controller glyph profiles

**Task Number:** 103A
**Task Name:** Input rebinding + controller glyph profiles
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 103 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/InputBindingProfile.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of input rebinding + controller glyph profiles in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/InputBindingProfile.cpp
TASK: Implement the smallest compiling slice for: Input rebinding + controller glyph profiles.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-103.2 Task 103B -> Input rebinding + controller glyph profiles

**Task Number:** 103B
**Task Name:** Input rebinding + controller glyph profiles
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 103 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/InputBindingProfile.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Input rebinding + controller glyph profiles and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of input rebinding + controller glyph profiles in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/InputBindingProfile.hpp
TASK: Implement the smallest compiling slice for: Input rebinding + controller glyph profiles.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Input rebinding + controller glyph profiles and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-103.3 Task 103C -> Input rebinding + controller glyph profiles

**Task Number:** 103C
**Task Name:** Input rebinding + controller glyph profiles
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 103 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/GameHUD.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Input rebinding + controller glyph profiles and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of input rebinding + controller glyph profiles in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/GameHUD.cpp
TASK: Implement the smallest compiling slice for: Input rebinding + controller glyph profiles.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Input rebinding + controller glyph profiles and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-103.4 Task 103D -> Input rebinding + controller glyph profiles

**Task Number:** 103D
**Task Name:** Input rebinding + controller glyph profiles
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 103 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/GameHUD.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Input rebinding + controller glyph profiles and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of input rebinding + controller glyph profiles in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/GameHUD.hpp
TASK: Implement the smallest compiling slice for: Input rebinding + controller glyph profiles.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Input rebinding + controller glyph profiles and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-104.1 Task 104A -> Performance HUD + auto quality scaler

**Task Number:** 104A
**Task Name:** Performance HUD + auto quality scaler
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 104 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/AutoQualityScaler.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of performance hud + auto quality scaler in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/AutoQualityScaler.cpp
TASK: Implement the smallest compiling slice for: Performance HUD + auto quality scaler.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-104.2 Task 104B -> Performance HUD + auto quality scaler

**Task Number:** 104B
**Task Name:** Performance HUD + auto quality scaler
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 104 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/app/AutoQualityScaler.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Performance HUD + auto quality scaler and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of performance hud + auto quality scaler in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/app/AutoQualityScaler.hpp
TASK: Implement the smallest compiling slice for: Performance HUD + auto quality scaler.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Performance HUD + auto quality scaler and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-104.3 Task 104C -> Performance HUD + auto quality scaler

**Task Number:** 104C
**Task Name:** Performance HUD + auto quality scaler
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 104 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/ImGuiLayer.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for Performance HUD + auto quality scaler and insert near similar runtime logic blocks.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of performance hud + auto quality scaler in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ImGuiLayer.cpp
TASK: Implement the smallest compiling slice for: Performance HUD + auto quality scaler.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for the main function/class for Performance HUD + auto quality scaler and insert near similar runtime logic blocks.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-104.4 Task 104D -> Performance HUD + auto quality scaler

**Task Number:** 104D
**Task Name:** Performance HUD + auto quality scaler
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 104 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/ImGuiLayer.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Performance HUD + auto quality scaler and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of performance hud + auto quality scaler in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/ImGuiLayer.hpp
TASK: Implement the smallest compiling slice for: Performance HUD + auto quality scaler.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Performance HUD + auto quality scaler and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-105.1 Task 105A -> Build packaging + release manifest scripts

**Task Number:** 105A
**Task Name:** Build packaging + release manifest scripts
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 105 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `tools/release/PackageBuild.ps1`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** inside the closest existing symbol for this task
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of build packaging + release manifest scripts in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: tools/release/PackageBuild.ps1
TASK: Implement the smallest compiling slice for: Build packaging + release manifest scripts.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: inside the closest existing symbol for this task
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-105.2 Task 105B -> Build packaging + release manifest scripts

**Task Number:** 105B
**Task Name:** Build packaging + release manifest scripts
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 105 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `docs/RELEASE_BUILD.md`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near similar task/documentation entries.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of build packaging + release manifest scripts in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: docs/RELEASE_BUILD.md
TASK: Implement the smallest compiling slice for: Build packaging + release manifest scripts.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Append near similar task/documentation entries.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-106.1 Task 106A -> Legal/credits/third-party attribution pass

**Task Number:** 106A
**Task Name:** Legal/credits/third-party attribution pass
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 106 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/CreditsScreen.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of legal/credits/third-party attribution pass in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CreditsScreen.cpp
TASK: Implement the smallest compiling slice for: Legal/credits/third-party attribution pass.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-106.2 Task 106B -> Legal/credits/third-party attribution pass

**Task Number:** 106B
**Task Name:** Legal/credits/third-party attribution pass
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 106 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/CreditsScreen.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Legal/credits/third-party attribution pass and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of legal/credits/third-party attribution pass in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CreditsScreen.hpp
TASK: Implement the smallest compiling slice for: Legal/credits/third-party attribution pass.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to Legal/credits/third-party attribution pass and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-106.3 Task 106C -> Legal/credits/third-party attribution pass

**Task Number:** 106C
**Task Name:** Legal/credits/third-party attribution pass
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 106 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `docs/THIRD_PARTY.md`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near similar task/documentation entries.

### What the edit is doing
This micro-step adds a small, compile-safe slice of legal/credits/third-party attribution pass in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: docs/THIRD_PARTY.md
TASK: Implement the smallest compiling slice for: Legal/credits/third-party attribution pass.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Append near similar task/documentation entries.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-107.1 Task 107A -> New game bootstrap + onboarding tutorial

**Task Number:** 107A
**Task Name:** New game bootstrap + onboarding tutorial
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 107 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/NewGameFlow.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of new game bootstrap + onboarding tutorial in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/NewGameFlow.cpp
TASK: Implement the smallest compiling slice for: New game bootstrap + onboarding tutorial.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-107.2 Task 107B -> New game bootstrap + onboarding tutorial

**Task Number:** 107B
**Task Name:** New game bootstrap + onboarding tutorial
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 107 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/game/NewGameFlow.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to New game bootstrap + onboarding tutorial and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of new game bootstrap + onboarding tutorial in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/NewGameFlow.hpp
TASK: Implement the smallest compiling slice for: New game bootstrap + onboarding tutorial.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to New game bootstrap + onboarding tutorial and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-107.3 Task 107C -> New game bootstrap + onboarding tutorial

**Task Number:** 107C
**Task Name:** New game bootstrap + onboarding tutorial
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 107 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/TutorialOverlay.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of new game bootstrap + onboarding tutorial in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/TutorialOverlay.cpp
TASK: Implement the smallest compiling slice for: New game bootstrap + onboarding tutorial.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: new file
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-107.4 Task 107D -> New game bootstrap + onboarding tutorial

**Task Number:** 107D
**Task Name:** New game bootstrap + onboarding tutorial
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 107 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `src/ui/TutorialOverlay.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to New game bootstrap + onboarding tutorial and add declarations in the matching public section.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of new game bootstrap + onboarding tutorial in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/TutorialOverlay.hpp
TASK: Implement the smallest compiling slice for: New game bootstrap + onboarding tutorial.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Search for `class`/`struct` declarations related to New game bootstrap + onboarding tutorial and add declarations in the matching public section.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-108.1 Task 108A -> Vertical-slice certification and ship checklist

**Task Number:** 108A
**Task Name:** Vertical-slice certification and ship checklist
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 108 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `docs/SHIP_CHECKLIST.md`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near similar task/documentation entries.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of vertical-slice certification and ship checklist in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: docs/SHIP_CHECKLIST.md
TASK: Implement the smallest compiling slice for: Vertical-slice certification and ship checklist.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Append near similar task/documentation entries.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## FULL-108.2 Task 108B -> Vertical-slice certification and ship checklist

**Task Number:** 108B
**Task Name:** Vertical-slice certification and ship checklist
**Source:** `docs/FULL_TASK_SEQUENCE.md` Task 108 (reconciliation coverage)
**Status:** Needs verification
**File to edit:** `docs/QUALITY_BAR.md`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near similar task/documentation entries.
**Complexity warning:** Marked Copilot-required in FULL ownership matrix; keep Qwen output tiny and compile-safe.

### What the edit is doing
This micro-step adds a small, compile-safe slice of vertical-slice certification and ship checklist in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: docs/QUALITY_BAR.md
TASK: Implement the smallest compiling slice for: Vertical-slice certification and ship checklist.
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
// Ask for one minimal block for this file and task only.
```

### Additional information for the user
- Paste at: Append near similar task/documentation entries.
- Validate by: Run focused compile/smoke checks for this subsystem and confirm behavior.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

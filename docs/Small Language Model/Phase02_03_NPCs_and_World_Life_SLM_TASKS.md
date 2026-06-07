# Phase 2.3 — NPCs & World Life (SLM micro-tasks)

This file covers remaining tasks for **Phase 2: WORLD SYSTEMS & EXPLORATION (Tasks 151-300) / Subphase 2.3** from `docs/docs_ORDER_PLAN.md`.
Tasks are one-file micro-steps optimized for Qwen2.5 Coder 0.5B Instruct in chat-only copy/paste mode.


## 211.1 Task 034 -> NPC actor

**Task Number:** 034
**Task Name:** NPC actor
**Source:** `docs/docs_ORDER_PLAN.md` order 211 / `docs/FULL_TASK_SEQUENCE.md` Task 034
**Status:** Remaining
**File to edit:** `src/game/actors/NpcActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc actor in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/NpcActor.cpp
TASK: Implement the smallest compiling slice for: NPC actor.
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

## 211.1VCPROJ Task 034_VCPROJ -> NPC actor (Add the new .cpp compile include entry.)

**Task Number:** 034_VCPROJ
**Task Name:** NPC actor (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 211 / `docs/FULL_TASK_SEQUENCE.md` Task 034 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/actors/NpcActor.cpp` only.
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

## 211.1FILTER Task 034_FILTER -> NPC actor (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 034_FILTER
**Task Name:** NPC actor (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 211 / `docs/FULL_TASK_SEQUENCE.md` Task 034 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/actors/NpcActor.cpp` only.
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

## 212.1 Task 034H -> NPC actor header

**Task Number:** 034H
**Task Name:** NPC actor header
**Source:** `docs/docs_ORDER_PLAN.md` order 212
**Status:** Remaining
**File to edit:** `src/game/actors/NpcActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC actor header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc actor header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/NpcActor.hpp
TASK: Implement the smallest compiling slice for: NPC actor header.
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
- Paste at: Search for `class`/`struct` declarations related to NPC actor header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 213.1 Task 038 -> NPC interaction prompt routing stub

**Task Number:** 038
**Task Name:** NPC interaction prompt routing stub
**Source:** `docs/docs_ORDER_PLAN.md` order 213 / `docs/FULL_TASK_SEQUENCE.md` Task 038
**Status:** Remaining
**File to edit:** `src/ui/GameHUD.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main function/class for NPC interaction prompt routing stub and insert near similar runtime logic blocks.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc interaction prompt routing stub in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/GameHUD.cpp
TASK: Implement the smallest compiling slice for: NPC interaction prompt routing stub.
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
- Paste at: Search for the main function/class for NPC interaction prompt routing stub and insert near similar runtime logic blocks.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 214.1 Task 038H -> NPC interaction header

**Task Number:** 038H
**Task Name:** NPC interaction header
**Source:** `docs/docs_ORDER_PLAN.md` order 214
**Status:** Remaining
**File to edit:** `src/ui/GameHUD.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC interaction header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc interaction header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/GameHUD.hpp
TASK: Implement the smallest compiling slice for: NPC interaction header.
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
- Paste at: Search for `class`/`struct` declarations related to NPC interaction header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 215.1 Task 184 -> NPC day/night schedule system

**Task Number:** 184
**Task Name:** NPC day/night schedule system
**Source:** `docs/docs_ORDER_PLAN.md` order 215
**Status:** Remaining
**File to edit:** `src/game/actors/MerchantActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc day/night schedule system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/MerchantActor.cpp
TASK: Implement the smallest compiling slice for: NPC day/night schedule system.
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

## 215.1VCPROJ Task 184_VCPROJ -> NPC day/night schedule system (Add the new .cpp compile include entry.)

**Task Number:** 184_VCPROJ
**Task Name:** NPC day/night schedule system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 215 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/actors/MerchantActor.cpp` only.
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

## 215.1FILTER Task 184_FILTER -> NPC day/night schedule system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 184_FILTER
**Task Name:** NPC day/night schedule system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 215 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/actors/MerchantActor.cpp` only.
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

## 216.1 Task 184H -> NPC schedule header

**Task Number:** 184H
**Task Name:** NPC schedule header
**Source:** `docs/docs_ORDER_PLAN.md` order 216
**Status:** Remaining
**File to edit:** `src/game/actors/MerchantActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC schedule header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc schedule header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/MerchantActor.hpp
TASK: Implement the smallest compiling slice for: NPC schedule header.
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
- Paste at: Search for `class`/`struct` declarations related to NPC schedule header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 217.1 Task 185 -> NPC idle behavior animations

**Task Number:** 185
**Task Name:** NPC idle behavior animations
**Source:** `docs/docs_ORDER_PLAN.md` order 217
**Status:** Remaining
**File to edit:** `src/game/actors/InnkeeperActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc idle behavior animations in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/InnkeeperActor.cpp
TASK: Implement the smallest compiling slice for: NPC idle behavior animations.
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

## 217.1VCPROJ Task 185_VCPROJ -> NPC idle behavior animations (Add the new .cpp compile include entry.)

**Task Number:** 185_VCPROJ
**Task Name:** NPC idle behavior animations (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 217 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/actors/InnkeeperActor.cpp` only.
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

## 217.1FILTER Task 185_FILTER -> NPC idle behavior animations (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 185_FILTER
**Task Name:** NPC idle behavior animations (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 217 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/actors/InnkeeperActor.cpp` only.
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

## 218.1 Task 185H -> NPC idle behavior header

**Task Number:** 185H
**Task Name:** NPC idle behavior header
**Source:** `docs/docs_ORDER_PLAN.md` order 218
**Status:** Remaining
**File to edit:** `src/game/actors/InnkeeperActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC idle behavior header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc idle behavior header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/InnkeeperActor.hpp
TASK: Implement the smallest compiling slice for: NPC idle behavior header.
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
- Paste at: Search for `class`/`struct` declarations related to NPC idle behavior header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 219.1 Task 186 -> NPC conversation system

**Task Number:** 186
**Task Name:** NPC conversation system
**Source:** `docs/docs_ORDER_PLAN.md` order 219
**Status:** Remaining
**File to edit:** `src/game/inventory/ShopInventory.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc conversation system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/ShopInventory.cpp
TASK: Implement the smallest compiling slice for: NPC conversation system.
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

## 219.1VCPROJ Task 186_VCPROJ -> NPC conversation system (Add the new .cpp compile include entry.)

**Task Number:** 186_VCPROJ
**Task Name:** NPC conversation system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 219 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/inventory/ShopInventory.cpp` only.
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

## 219.1FILTER Task 186_FILTER -> NPC conversation system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 186_FILTER
**Task Name:** NPC conversation system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 219 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/inventory/ShopInventory.cpp` only.
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

## 220.1 Task 186H -> NPC conversation header

**Task Number:** 186H
**Task Name:** NPC conversation header
**Source:** `docs/docs_ORDER_PLAN.md` order 220
**Status:** Remaining
**File to edit:** `src/game/inventory/ShopInventory.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC conversation header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc conversation header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/inventory/ShopInventory.hpp
TASK: Implement the smallest compiling slice for: NPC conversation header.
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
- Paste at: Search for `class`/`struct` declarations related to NPC conversation header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 221.1 Task 187 -> Shop vendor system

**Task Number:** 187
**Task Name:** Shop vendor system
**Source:** `docs/docs_ORDER_PLAN.md` order 221
**Status:** Remaining
**File to edit:** `Shaders/shadow_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of shop vendor system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/shadow_vs.hlsl
TASK: Implement the smallest compiling slice for: Shop vendor system.
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

## 222.1 Task 187H -> Shop vendor header

**Task Number:** 187H
**Task Name:** Shop vendor header
**Source:** `docs/docs_ORDER_PLAN.md` order 222
**Status:** Remaining
**File to edit:** `Shaders/shadow_vs.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of shop vendor header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/shadow_vs.hlsl
TASK: Implement the smallest compiling slice for: Shop vendor header.
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

## 223.1 Task 188 -> Inn/tavern rest system

**Task Number:** 188
**Task Name:** Inn/tavern rest system
**Source:** `docs/docs_ORDER_PLAN.md` order 223
**Status:** Remaining
**File to edit:** `Shaders/shadow_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of inn/tavern rest system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/shadow_ps.hlsl
TASK: Implement the smallest compiling slice for: Inn/tavern rest system.
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

## 224.1 Task 188H -> Inn/tavern rest header

**Task Number:** 188H
**Task Name:** Inn/tavern rest header
**Source:** `docs/docs_ORDER_PLAN.md` order 224
**Status:** Remaining
**File to edit:** `Shaders/shadow_ps.hlsl`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for the main shader entry function and add the smallest guarded block near similar lighting/post-process code.

### What the edit is doing
This micro-step adds a small, compile-safe slice of inn/tavern rest header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: Shaders/shadow_ps.hlsl
TASK: Implement the smallest compiling slice for: Inn/tavern rest header.
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

## 225.1 Task 267 -> Random NPC chatter system

**Task Number:** 267
**Task Name:** Random NPC chatter system
**Source:** `docs/docs_ORDER_PLAN.md` order 225
**Status:** Remaining
**File to edit:** `src/game/quest/QuestChoiceTracker.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of random npc chatter system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestChoiceTracker.cpp
TASK: Implement the smallest compiling slice for: Random NPC chatter system.
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

## 225.1VCPROJ Task 267_VCPROJ -> Random NPC chatter system (Add the new .cpp compile include entry.)

**Task Number:** 267_VCPROJ
**Task Name:** Random NPC chatter system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 225 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/quest/QuestChoiceTracker.cpp` only.
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

## 225.1FILTER Task 267_FILTER -> Random NPC chatter system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 267_FILTER
**Task Name:** Random NPC chatter system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 225 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/quest/QuestChoiceTracker.cpp` only.
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

## 226.1 Task 267H -> Random NPC chatter header

**Task Number:** 267H
**Task Name:** Random NPC chatter header
**Source:** `docs/docs_ORDER_PLAN.md` order 226
**Status:** Remaining
**File to edit:** `src/game/quest/QuestChoiceTracker.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Random NPC chatter header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of random npc chatter header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/QuestChoiceTracker.hpp
TASK: Implement the smallest compiling slice for: Random NPC chatter header.
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
- Paste at: Search for `class`/`struct` declarations related to Random NPC chatter header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 227.1 Task 268 -> NPC relationship memory system

**Task Number:** 268
**Task Name:** NPC relationship memory system
**Source:** `docs/docs_ORDER_PLAN.md` order 227
**Status:** Remaining
**File to edit:** `src/ui/CinematicBars.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc relationship memory system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CinematicBars.cpp
TASK: Implement the smallest compiling slice for: NPC relationship memory system.
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

## 227.1VCPROJ Task 268_VCPROJ -> NPC relationship memory system (Add the new .cpp compile include entry.)

**Task Number:** 268_VCPROJ
**Task Name:** NPC relationship memory system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 227 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/CinematicBars.cpp` only.
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

## 227.1FILTER Task 268_FILTER -> NPC relationship memory system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 268_FILTER
**Task Name:** NPC relationship memory system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 227 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/CinematicBars.cpp` only.
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

## 228.1 Task 268H -> NPC relationship memory header

**Task Number:** 268H
**Task Name:** NPC relationship memory header
**Source:** `docs/docs_ORDER_PLAN.md` order 228
**Status:** Remaining
**File to edit:** `src/ui/CinematicBars.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC relationship memory header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc relationship memory header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CinematicBars.hpp
TASK: Implement the smallest compiling slice for: NPC relationship memory header.
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
- Paste at: Search for `class`/`struct` declarations related to NPC relationship memory header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 229.1 Task 269 -> Dynamic NPC reactions to player actions

**Task Number:** 269
**Task Name:** Dynamic NPC reactions to player actions
**Source:** `docs/docs_ORDER_PLAN.md` order 229
**Status:** Remaining
**File to edit:** `src/game/scripting/EventScriptInterpreter.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of dynamic npc reactions to player actions in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/scripting/EventScriptInterpreter.cpp
TASK: Implement the smallest compiling slice for: Dynamic NPC reactions to player actions.
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

## 229.1VCPROJ Task 269_VCPROJ -> Dynamic NPC reactions to player actions (Add the new .cpp compile include entry.)

**Task Number:** 269_VCPROJ
**Task Name:** Dynamic NPC reactions to player actions (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 229 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/scripting/EventScriptInterpreter.cpp` only.
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

## 229.1FILTER Task 269_FILTER -> Dynamic NPC reactions to player actions (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 269_FILTER
**Task Name:** Dynamic NPC reactions to player actions (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 229 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/scripting/EventScriptInterpreter.cpp` only.
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

## 230.1 Task 269H -> Dynamic NPC reactions header

**Task Number:** 269H
**Task Name:** Dynamic NPC reactions header
**Source:** `docs/docs_ORDER_PLAN.md` order 230
**Status:** Remaining
**File to edit:** `src/game/scripting/EventScriptInterpreter.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Dynamic NPC reactions header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of dynamic npc reactions header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/scripting/EventScriptInterpreter.hpp
TASK: Implement the smallest compiling slice for: Dynamic NPC reactions header.
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
- Paste at: Search for `class`/`struct` declarations related to Dynamic NPC reactions header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 231.1 Task 345 -> Gift-giving affinity system

**Task Number:** 345
**Task Name:** Gift-giving affinity system
**Source:** `docs/docs_ORDER_PLAN.md` order 231
**Status:** Remaining
**File to edit:** `src/game/social/GiftAffinitySystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of gift-giving affinity system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/social/GiftAffinitySystem.cpp
TASK: Implement the smallest compiling slice for: Gift-giving affinity system.
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

## 231.1VCPROJ Task 345_VCPROJ -> Gift-giving affinity system (Add the new .cpp compile include entry.)

**Task Number:** 345_VCPROJ
**Task Name:** Gift-giving affinity system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 231 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/social/GiftAffinitySystem.cpp` only.
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

## 231.1FILTER Task 345_FILTER -> Gift-giving affinity system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 345_FILTER
**Task Name:** Gift-giving affinity system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 231 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/social/GiftAffinitySystem.cpp` only.
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

## 232.1 Task 345H -> Gift affinity system header

**Task Number:** 345H
**Task Name:** Gift affinity system header
**Source:** `docs/docs_ORDER_PLAN.md` order 232
**Status:** Remaining
**File to edit:** `src/game/social/GiftAffinitySystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Gift affinity system header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of gift affinity system header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/social/GiftAffinitySystem.hpp
TASK: Implement the smallest compiling slice for: Gift affinity system header.
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
- Paste at: Search for `class`/`struct` declarations related to Gift affinity system header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 233.1 Task 346 -> NPC memory/relationship tracking

**Task Number:** 346
**Task Name:** NPC memory/relationship tracking
**Source:** `docs/docs_ORDER_PLAN.md` order 233
**Status:** Remaining
**File to edit:** `src/game/ai/NpcMemorySystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc memory/relationship tracking in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/NpcMemorySystem.cpp
TASK: Implement the smallest compiling slice for: NPC memory/relationship tracking.
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

## 233.1VCPROJ Task 346_VCPROJ -> NPC memory/relationship tracking (Add the new .cpp compile include entry.)

**Task Number:** 346_VCPROJ
**Task Name:** NPC memory/relationship tracking (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 233 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/ai/NpcMemorySystem.cpp` only.
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

## 233.1FILTER Task 346_FILTER -> NPC memory/relationship tracking (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 346_FILTER
**Task Name:** NPC memory/relationship tracking (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 233 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/ai/NpcMemorySystem.cpp` only.
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

## 234.1 Task 346H -> NPC memory system header

**Task Number:** 346H
**Task Name:** NPC memory system header
**Source:** `docs/docs_ORDER_PLAN.md` order 234
**Status:** Remaining
**File to edit:** `src/game/ai/NpcMemorySystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to NPC memory system header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of npc memory system header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/NpcMemorySystem.hpp
TASK: Implement the smallest compiling slice for: NPC memory system header.
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
- Paste at: Search for `class`/`struct` declarations related to NPC memory system header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 235.1 Task 347 -> Inn/tavern rumors board

**Task Number:** 347
**Task Name:** Inn/tavern rumors board
**Source:** `docs/docs_ORDER_PLAN.md` order 235
**Status:** Remaining
**File to edit:** `src/world/InnRumorsBoard.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of inn/tavern rumors board in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/InnRumorsBoard.cpp
TASK: Implement the smallest compiling slice for: Inn/tavern rumors board.
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

## 235.1VCPROJ Task 347_VCPROJ -> Inn/tavern rumors board (Add the new .cpp compile include entry.)

**Task Number:** 347_VCPROJ
**Task Name:** Inn/tavern rumors board (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 235 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/InnRumorsBoard.cpp` only.
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

## 235.1FILTER Task 347_FILTER -> Inn/tavern rumors board (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 347_FILTER
**Task Name:** Inn/tavern rumors board (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 235 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/InnRumorsBoard.cpp` only.
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

## 236.1 Task 347H -> Inn rumors board header

**Task Number:** 347H
**Task Name:** Inn rumors board header
**Source:** `docs/docs_ORDER_PLAN.md` order 236
**Status:** Remaining
**File to edit:** `src/world/InnRumorsBoard.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Inn rumors board header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of inn rumors board header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/InnRumorsBoard.hpp
TASK: Implement the smallest compiling slice for: Inn rumors board header.
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
- Paste at: Search for `class`/`struct` declarations related to Inn rumors board header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 237.1 Task 348 -> Street performer/musician ambient system

**Task Number:** 348
**Task Name:** Street performer/musician ambient system
**Source:** `docs/docs_ORDER_PLAN.md` order 237
**Status:** Remaining
**File to edit:** `src/world/StreetPerformerSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of street performer/musician ambient system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/StreetPerformerSystem.cpp
TASK: Implement the smallest compiling slice for: Street performer/musician ambient system.
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

## 237.1VCPROJ Task 348_VCPROJ -> Street performer/musician ambient system (Add the new .cpp compile include entry.)

**Task Number:** 348_VCPROJ
**Task Name:** Street performer/musician ambient system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 237 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/StreetPerformerSystem.cpp` only.
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

## 237.1FILTER Task 348_FILTER -> Street performer/musician ambient system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 348_FILTER
**Task Name:** Street performer/musician ambient system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 237 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/StreetPerformerSystem.cpp` only.
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

## 238.1 Task 348H -> Street performer system header

**Task Number:** 348H
**Task Name:** Street performer system header
**Source:** `docs/docs_ORDER_PLAN.md` order 238
**Status:** Remaining
**File to edit:** `src/world/StreetPerformerSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Street performer system header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of street performer system header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/StreetPerformerSystem.hpp
TASK: Implement the smallest compiling slice for: Street performer system header.
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
- Paste at: Search for `class`/`struct` declarations related to Street performer system header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 239.1 Task 349 -> Romance system with dating scenes

**Task Number:** 349
**Task Name:** Romance system with dating scenes
**Source:** `docs/docs_ORDER_PLAN.md` order 239
**Status:** Remaining
**File to edit:** `src/game/social/RomanceSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of romance system with dating scenes in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/social/RomanceSystem.cpp
TASK: Implement the smallest compiling slice for: Romance system with dating scenes.
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

## 239.1VCPROJ Task 349_VCPROJ -> Romance system with dating scenes (Add the new .cpp compile include entry.)

**Task Number:** 349_VCPROJ
**Task Name:** Romance system with dating scenes (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 239 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/social/RomanceSystem.cpp` only.
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

## 239.1FILTER Task 349_FILTER -> Romance system with dating scenes (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 349_FILTER
**Task Name:** Romance system with dating scenes (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 239 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/social/RomanceSystem.cpp` only.
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

## 240.1 Task 349H -> Romance system header

**Task Number:** 349H
**Task Name:** Romance system header
**Source:** `docs/docs_ORDER_PLAN.md` order 240
**Status:** Remaining
**File to edit:** `src/game/social/RomanceSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Romance system header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of romance system header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/social/RomanceSystem.hpp
TASK: Implement the smallest compiling slice for: Romance system header.
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
- Paste at: Search for `class`/`struct` declarations related to Romance system header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

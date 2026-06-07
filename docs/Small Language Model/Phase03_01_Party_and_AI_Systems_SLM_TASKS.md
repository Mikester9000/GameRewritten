# Phase 3.1 — Party & AI Systems (SLM micro-tasks)

This file covers remaining tasks for **Phase 3: COMBAT DEPTH & PARTY (Tasks 301-400) / Subphase 3.1** from `docs/docs_ORDER_PLAN.md`.
Tasks are one-file micro-steps optimized for Qwen2.5 Coder 0.5B Instruct in chat-only copy/paste mode.


## 301.1 Task 077 -> Party member runtime slot + follow AI

**Task Number:** 077
**Task Name:** Party member runtime slot + follow AI
**Source:** `docs/docs_ORDER_PLAN.md` order 301 / `docs/FULL_TASK_SEQUENCE.md` Task 077
**Status:** Remaining
**File to edit:** `src/game/party/PartyRuntime.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of party member runtime slot + follow ai in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/party/PartyRuntime.cpp
TASK: Implement the smallest compiling slice for: Party member runtime slot + follow AI.
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

## 301.1VCPROJ Task 077_VCPROJ -> Party member runtime slot + follow AI (Add the new .cpp compile include entry.)

**Task Number:** 077_VCPROJ
**Task Name:** Party member runtime slot + follow AI (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 301 / `docs/FULL_TASK_SEQUENCE.md` Task 077 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/party/PartyRuntime.cpp` only.
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

## 301.1FILTER Task 077_FILTER -> Party member runtime slot + follow AI (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 077_FILTER
**Task Name:** Party member runtime slot + follow AI (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 301 / `docs/FULL_TASK_SEQUENCE.md` Task 077 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/party/PartyRuntime.cpp` only.
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

## 302.1 Task 077H -> Party runtime header

**Task Number:** 077H
**Task Name:** Party runtime header
**Source:** `docs/docs_ORDER_PLAN.md` order 302
**Status:** Remaining
**File to edit:** `src/game/party/PartyRuntime.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Party runtime header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of party runtime header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/party/PartyRuntime.hpp
TASK: Implement the smallest compiling slice for: Party runtime header.
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
- Paste at: Search for `class`/`struct` declarations related to Party runtime header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 303.1 Task 078 -> Command wheel + tactical slow-time commands

**Task Number:** 078
**Task Name:** Command wheel + tactical slow-time commands
**Source:** `docs/docs_ORDER_PLAN.md` order 303 / `docs/FULL_TASK_SEQUENCE.md` Task 078
**Status:** Remaining
**File to edit:** `src/ui/CommandWheel.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of command wheel + tactical slow-time commands in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CommandWheel.cpp
TASK: Implement the smallest compiling slice for: Command wheel + tactical slow-time commands.
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

## 303.1VCPROJ Task 078_VCPROJ -> Command wheel + tactical slow-time commands (Add the new .cpp compile include entry.)

**Task Number:** 078_VCPROJ
**Task Name:** Command wheel + tactical slow-time commands (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 303 / `docs/FULL_TASK_SEQUENCE.md` Task 078 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/CommandWheel.cpp` only.
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

## 303.1FILTER Task 078_FILTER -> Command wheel + tactical slow-time commands (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 078_FILTER
**Task Name:** Command wheel + tactical slow-time commands (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 303 / `docs/FULL_TASK_SEQUENCE.md` Task 078 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/CommandWheel.cpp` only.
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

## 304.1 Task 078H -> Command wheel header

**Task Number:** 078H
**Task Name:** Command wheel header
**Source:** `docs/docs_ORDER_PLAN.md` order 304
**Status:** Remaining
**File to edit:** `src/ui/CommandWheel.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Command wheel header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of command wheel header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/CommandWheel.hpp
TASK: Implement the smallest compiling slice for: Command wheel header.
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
- Paste at: Search for `class`/`struct` declarations related to Command wheel header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 305.1 Task 079 -> ATB-style action charge lanes

**Task Number:** 079
**Task Name:** ATB-style action charge lanes
**Source:** `docs/docs_ORDER_PLAN.md` order 305 / `docs/FULL_TASK_SEQUENCE.md` Task 079
**Status:** Remaining
**File to edit:** `src/game/combat/AtbSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of atb-style action charge lanes in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/AtbSystem.cpp
TASK: Implement the smallest compiling slice for: ATB-style action charge lanes.
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

## 305.1VCPROJ Task 079_VCPROJ -> ATB-style action charge lanes (Add the new .cpp compile include entry.)

**Task Number:** 079_VCPROJ
**Task Name:** ATB-style action charge lanes (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 305 / `docs/FULL_TASK_SEQUENCE.md` Task 079 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/combat/AtbSystem.cpp` only.
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

## 305.1FILTER Task 079_FILTER -> ATB-style action charge lanes (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 079_FILTER
**Task Name:** ATB-style action charge lanes (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 305 / `docs/FULL_TASK_SEQUENCE.md` Task 079 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/combat/AtbSystem.cpp` only.
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

## 306.1 Task 079H -> ATB system header

**Task Number:** 079H
**Task Name:** ATB system header
**Source:** `docs/docs_ORDER_PLAN.md` order 306
**Status:** Remaining
**File to edit:** `src/game/combat/AtbSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to ATB system header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of atb system header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/AtbSystem.hpp
TASK: Implement the smallest compiling slice for: ATB system header.
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
- Paste at: Search for `class`/`struct` declarations related to ATB system header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 307.1 Task 080 -> Ability targeting templates (single/cone/aoe)

**Task Number:** 080
**Task Name:** Ability targeting templates (single/cone/aoe)
**Source:** `docs/docs_ORDER_PLAN.md` order 307 / `docs/FULL_TASK_SEQUENCE.md` Task 080
**Status:** Remaining
**File to edit:** `src/game/combat/AbilityTargeting.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of ability targeting templates (single/cone/aoe) in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/AbilityTargeting.cpp
TASK: Implement the smallest compiling slice for: Ability targeting templates (single/cone/aoe).
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

## 307.1VCPROJ Task 080_VCPROJ -> Ability targeting templates (single/cone/aoe) (Add the new .cpp compile include entry.)

**Task Number:** 080_VCPROJ
**Task Name:** Ability targeting templates (single/cone/aoe) (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 307 / `docs/FULL_TASK_SEQUENCE.md` Task 080 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/combat/AbilityTargeting.cpp` only.
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

## 307.1FILTER Task 080_FILTER -> Ability targeting templates (single/cone/aoe) (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 080_FILTER
**Task Name:** Ability targeting templates (single/cone/aoe) (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 307 / `docs/FULL_TASK_SEQUENCE.md` Task 080 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/combat/AbilityTargeting.cpp` only.
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

## 308.1 Task 080H -> Ability targeting header

**Task Number:** 080H
**Task Name:** Ability targeting header
**Source:** `docs/docs_ORDER_PLAN.md` order 308
**Status:** Remaining
**File to edit:** `src/game/combat/AbilityTargeting.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Ability targeting header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of ability targeting header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/combat/AbilityTargeting.hpp
TASK: Implement the smallest compiling slice for: Ability targeting header.
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
- Paste at: Search for `class`/`struct` declarations related to Ability targeting header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 309.1 Task 081 -> Enemy archetype behavior profiles

**Task Number:** 081
**Task Name:** Enemy archetype behavior profiles
**Source:** `docs/docs_ORDER_PLAN.md` order 309 / `docs/FULL_TASK_SEQUENCE.md` Task 081
**Status:** Remaining
**File to edit:** `src/game/ai/EnemyArchetypeProfile.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Enemy archetype behavior profiles and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy archetype behavior profiles in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/EnemyArchetypeProfile.hpp
TASK: Implement the smallest compiling slice for: Enemy archetype behavior profiles.
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
- Paste at: Search for `class`/`struct` declarations related to Enemy archetype behavior profiles and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 310.1 Task 081H -> Enemy archetype header

**Task Number:** 081H
**Task Name:** Enemy archetype header
**Source:** `docs/docs_ORDER_PLAN.md` order 310
**Status:** Remaining
**File to edit:** `src/game/ai/EnemyArchetypeProfile.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Enemy archetype header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy archetype header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/EnemyArchetypeProfile.hpp
TASK: Implement the smallest compiling slice for: Enemy archetype header.
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
- Paste at: Search for `class`/`struct` declarations related to Enemy archetype header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 311.1 Task 082 -> Enemy squad tactics coordinator

**Task Number:** 082
**Task Name:** Enemy squad tactics coordinator
**Source:** `docs/docs_ORDER_PLAN.md` order 311 / `docs/FULL_TASK_SEQUENCE.md` Task 082
**Status:** Remaining
**File to edit:** `src/game/ai/SquadCoordinator.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy squad tactics coordinator in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/SquadCoordinator.cpp
TASK: Implement the smallest compiling slice for: Enemy squad tactics coordinator.
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

## 311.1VCPROJ Task 082_VCPROJ -> Enemy squad tactics coordinator (Add the new .cpp compile include entry.)

**Task Number:** 082_VCPROJ
**Task Name:** Enemy squad tactics coordinator (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 311 / `docs/FULL_TASK_SEQUENCE.md` Task 082 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/ai/SquadCoordinator.cpp` only.
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

## 311.1FILTER Task 082_FILTER -> Enemy squad tactics coordinator (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 082_FILTER
**Task Name:** Enemy squad tactics coordinator (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 311 / `docs/FULL_TASK_SEQUENCE.md` Task 082 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/ai/SquadCoordinator.cpp` only.
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

## 312.1 Task 082H -> Squad coordinator header

**Task Number:** 082H
**Task Name:** Squad coordinator header
**Source:** `docs/docs_ORDER_PLAN.md` order 312
**Status:** Remaining
**File to edit:** `src/game/ai/SquadCoordinator.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Squad coordinator header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of squad coordinator header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/ai/SquadCoordinator.hpp
TASK: Implement the smallest compiling slice for: Squad coordinator header.
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
- Paste at: Search for `class`/`struct` declarations related to Squad coordinator header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 313.1 Task 083 -> Boss phase state machine framework

**Task Number:** 083
**Task Name:** Boss phase state machine framework
**Source:** `docs/docs_ORDER_PLAN.md` order 313 / `docs/FULL_TASK_SEQUENCE.md` Task 083
**Status:** Remaining
**File to edit:** `src/game/actors/BossActor.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of boss phase state machine framework in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/BossActor.cpp
TASK: Implement the smallest compiling slice for: Boss phase state machine framework.
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

## 313.1VCPROJ Task 083_VCPROJ -> Boss phase state machine framework (Add the new .cpp compile include entry.)

**Task Number:** 083_VCPROJ
**Task Name:** Boss phase state machine framework (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 313 / `docs/FULL_TASK_SEQUENCE.md` Task 083 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/actors/BossActor.cpp` only.
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

## 313.1FILTER Task 083_FILTER -> Boss phase state machine framework (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 083_FILTER
**Task Name:** Boss phase state machine framework (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 313 / `docs/FULL_TASK_SEQUENCE.md` Task 083 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/actors/BossActor.cpp` only.
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

## 314.1 Task 083H -> Boss phase state machine header

**Task Number:** 083H
**Task Name:** Boss phase state machine header
**Source:** `docs/docs_ORDER_PLAN.md` order 314
**Status:** Remaining
**File to edit:** `src/game/actors/BossActor.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Boss phase state machine header and add declarations in the matching public section.
**Complexity warning:** This is tagged Copilot-required in `docs/FULL_TASK_SEQUENCE.md`; still use tiny compile-safe steps with Qwen.

### What the edit is doing
This micro-step adds a small, compile-safe slice of boss phase state machine header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/actors/BossActor.hpp
TASK: Implement the smallest compiling slice for: Boss phase state machine header.
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
- Paste at: Search for `class`/`struct` declarations related to Boss phase state machine header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 315.1 Task 248 -> Party synergy combos

**Task Number:** 248
**Task Name:** Party synergy combos
**Source:** `docs/docs_ORDER_PLAN.md` order 315
**Status:** Remaining
**File to edit:** `src/game/party/SynergySystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of party synergy combos in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/party/SynergySystem.cpp
TASK: Implement the smallest compiling slice for: Party synergy combos.
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

## 315.1VCPROJ Task 248_VCPROJ -> Party synergy combos (Add the new .cpp compile include entry.)

**Task Number:** 248_VCPROJ
**Task Name:** Party synergy combos (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 315 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/party/SynergySystem.cpp` only.
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

## 315.1FILTER Task 248_FILTER -> Party synergy combos (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 248_FILTER
**Task Name:** Party synergy combos (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 315 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/party/SynergySystem.cpp` only.
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

## 316.1 Task 248H -> Party synergy combos header

**Task Number:** 248H
**Task Name:** Party synergy combos header
**Source:** `docs/docs_ORDER_PLAN.md` order 316
**Status:** Remaining
**File to edit:** `src/game/party/SynergySystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Party synergy combos header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of party synergy combos header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/party/SynergySystem.hpp
TASK: Implement the smallest compiling slice for: Party synergy combos header.
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
- Paste at: Search for `class`/`struct` declarations related to Party synergy combos header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 317.1 Task 256 -> Companion AI tactics presets

**Task Number:** 256
**Task Name:** Companion AI tactics presets
**Source:** `docs/docs_ORDER_PLAN.md` order 317
**Status:** Remaining
**File to edit:** `src/game/quest/ReputationSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of companion ai tactics presets in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/ReputationSystem.cpp
TASK: Implement the smallest compiling slice for: Companion AI tactics presets.
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

## 317.1VCPROJ Task 256_VCPROJ -> Companion AI tactics presets (Add the new .cpp compile include entry.)

**Task Number:** 256_VCPROJ
**Task Name:** Companion AI tactics presets (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 317 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/quest/ReputationSystem.cpp` only.
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

## 317.1FILTER Task 256_FILTER -> Companion AI tactics presets (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 256_FILTER
**Task Name:** Companion AI tactics presets (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 317 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/quest/ReputationSystem.cpp` only.
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

## 318.1 Task 256H -> Companion AI tactics header

**Task Number:** 256H
**Task Name:** Companion AI tactics header
**Source:** `docs/docs_ORDER_PLAN.md` order 318
**Status:** Remaining
**File to edit:** `src/game/quest/ReputationSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Companion AI tactics header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of companion ai tactics header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/quest/ReputationSystem.hpp
TASK: Implement the smallest compiling slice for: Companion AI tactics header.
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
- Paste at: Search for `class`/`struct` declarations related to Companion AI tactics header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 319.1 Task 257 -> Enemy alert AI state machine

**Task Number:** 257
**Task Name:** Enemy alert AI state machine
**Source:** `docs/docs_ORDER_PLAN.md` order 319
**Status:** Remaining
**File to edit:** `src/world/RandomEncounterDirector.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy alert ai state machine in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/RandomEncounterDirector.cpp
TASK: Implement the smallest compiling slice for: Enemy alert AI state machine.
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

## 319.1VCPROJ Task 257_VCPROJ -> Enemy alert AI state machine (Add the new .cpp compile include entry.)

**Task Number:** 257_VCPROJ
**Task Name:** Enemy alert AI state machine (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 319 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/world/RandomEncounterDirector.cpp` only.
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

## 319.1FILTER Task 257_FILTER -> Enemy alert AI state machine (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 257_FILTER
**Task Name:** Enemy alert AI state machine (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 319 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/world/RandomEncounterDirector.cpp` only.
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

## 320.1 Task 257H -> Enemy alert AI header

**Task Number:** 257H
**Task Name:** Enemy alert AI header
**Source:** `docs/docs_ORDER_PLAN.md` order 320
**Status:** Remaining
**File to edit:** `src/world/RandomEncounterDirector.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Enemy alert AI header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy alert ai header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/world/RandomEncounterDirector.hpp
TASK: Implement the smallest compiling slice for: Enemy alert AI header.
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
- Paste at: Search for `class`/`struct` declarations related to Enemy alert AI header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 321.1 Task 258 -> Aggro range & line-of-sight

**Task Number:** 258
**Task Name:** Aggro range & line-of-sight
**Source:** `docs/docs_ORDER_PLAN.md` order 321
**Status:** Remaining
**File to edit:** `src/game/minigames/FishingMinigame.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of aggro range & line-of-sight in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/minigames/FishingMinigame.cpp
TASK: Implement the smallest compiling slice for: Aggro range & line-of-sight.
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

## 321.1VCPROJ Task 258_VCPROJ -> Aggro range & line-of-sight (Add the new .cpp compile include entry.)

**Task Number:** 258_VCPROJ
**Task Name:** Aggro range & line-of-sight (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 321 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/minigames/FishingMinigame.cpp` only.
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

## 321.1FILTER Task 258_FILTER -> Aggro range & line-of-sight (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 258_FILTER
**Task Name:** Aggro range & line-of-sight (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 321 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/minigames/FishingMinigame.cpp` only.
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

## 322.1 Task 258H -> Aggro range header

**Task Number:** 258H
**Task Name:** Aggro range header
**Source:** `docs/docs_ORDER_PLAN.md` order 322
**Status:** Remaining
**File to edit:** `src/game/minigames/FishingMinigame.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Aggro range header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of aggro range header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/minigames/FishingMinigame.hpp
TASK: Implement the smallest compiling slice for: Aggro range header.
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
- Paste at: Search for `class`/`struct` declarations related to Aggro range header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 323.1 Task 259 -> Enemy patrol routes

**Task Number:** 259
**Task Name:** Enemy patrol routes
**Source:** `docs/docs_ORDER_PLAN.md` order 323
**Status:** Remaining
**File to edit:** `src/game/crafting/CraftingSystem.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy patrol routes in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/crafting/CraftingSystem.cpp
TASK: Implement the smallest compiling slice for: Enemy patrol routes.
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

## 323.1VCPROJ Task 259_VCPROJ -> Enemy patrol routes (Add the new .cpp compile include entry.)

**Task Number:** 259_VCPROJ
**Task Name:** Enemy patrol routes (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 323 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/crafting/CraftingSystem.cpp` only.
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

## 323.1FILTER Task 259_FILTER -> Enemy patrol routes (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 259_FILTER
**Task Name:** Enemy patrol routes (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 323 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/crafting/CraftingSystem.cpp` only.
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

## 324.1 Task 259H -> Enemy patrol routes header

**Task Number:** 259H
**Task Name:** Enemy patrol routes header
**Source:** `docs/docs_ORDER_PLAN.md` order 324
**Status:** Remaining
**File to edit:** `src/game/crafting/CraftingSystem.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Enemy patrol routes header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy patrol routes header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/crafting/CraftingSystem.hpp
TASK: Implement the smallest compiling slice for: Enemy patrol routes header.
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
- Paste at: Search for `class`/`struct` declarations related to Enemy patrol routes header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 325.1 Task 260 -> Stealth detection cone

**Task Number:** 260
**Task Name:** Stealth detection cone
**Source:** `docs/docs_ORDER_PLAN.md` order 325
**Status:** Remaining
**File to edit:** `src/ui/PhotoMode.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of stealth detection cone in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/PhotoMode.cpp
TASK: Implement the smallest compiling slice for: Stealth detection cone.
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

## 325.1VCPROJ Task 260_VCPROJ -> Stealth detection cone (Add the new .cpp compile include entry.)

**Task Number:** 260_VCPROJ
**Task Name:** Stealth detection cone (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 325 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/ui/PhotoMode.cpp` only.
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

## 325.1FILTER Task 260_FILTER -> Stealth detection cone (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 260_FILTER
**Task Name:** Stealth detection cone (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 325 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/ui/PhotoMode.cpp` only.
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

## 326.1 Task 260H -> Stealth detection header

**Task Number:** 260H
**Task Name:** Stealth detection header
**Source:** `docs/docs_ORDER_PLAN.md` order 326
**Status:** Remaining
**File to edit:** `src/ui/PhotoMode.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Stealth detection header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of stealth detection header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/ui/PhotoMode.hpp
TASK: Implement the smallest compiling slice for: Stealth detection header.
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
- Paste at: Search for `class`/`struct` declarations related to Stealth detection header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 327.1 Task 261 -> Backstab damage multiplier

**Task Number:** 261
**Task Name:** Backstab damage multiplier
**Source:** `docs/docs_ORDER_PLAN.md` order 327
**Status:** Remaining
**File to edit:** `src/game/progression/Bestiary.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of backstab damage multiplier in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/Bestiary.cpp
TASK: Implement the smallest compiling slice for: Backstab damage multiplier.
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

## 327.1VCPROJ Task 261_VCPROJ -> Backstab damage multiplier (Add the new .cpp compile include entry.)

**Task Number:** 261_VCPROJ
**Task Name:** Backstab damage multiplier (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 327 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/progression/Bestiary.cpp` only.
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

## 327.1FILTER Task 261_FILTER -> Backstab damage multiplier (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 261_FILTER
**Task Name:** Backstab damage multiplier (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 327 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/progression/Bestiary.cpp` only.
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

## 328.1 Task 261H -> Backstab damage header

**Task Number:** 261H
**Task Name:** Backstab damage header
**Source:** `docs/docs_ORDER_PLAN.md` order 328
**Status:** Remaining
**File to edit:** `src/game/progression/Bestiary.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Backstab damage header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of backstab damage header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/Bestiary.hpp
TASK: Implement the smallest compiling slice for: Backstab damage header.
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
- Paste at: Search for `class`/`struct` declarations related to Backstab damage header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

## 329.1 Task 262 -> Enemy reinforcements system

**Task Number:** 262
**Task Name:** Enemy reinforcements system
**Source:** `docs/docs_ORDER_PLAN.md` order 329
**Status:** Remaining
**File to edit:** `src/game/progression/TreasureMap.cpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** new file

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy reinforcements system in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/TreasureMap.cpp
TASK: Implement the smallest compiling slice for: Enemy reinforcements system.
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

## 329.1VCPROJ Task 262_VCPROJ -> Enemy reinforcements system (Add the new .cpp compile include entry.)

**Task Number:** 262_VCPROJ
**Task Name:** Enemy reinforcements system (Add the new .cpp compile include entry.)
**Source:** `docs/docs_ORDER_PLAN.md` order 329 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj
TASK: Add XML entry for `src/game/progression/TreasureMap.cpp` only.
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

## 329.1FILTER Task 262_FILTER -> Enemy reinforcements system (Add the new .cpp filter entry so IDE folder layout is consistent.)

**Task Number:** 262_FILTER
**Task Name:** Enemy reinforcements system (Add the new .cpp filter entry so IDE folder layout is consistent.)
**Source:** `docs/docs_ORDER_PLAN.md` order 329 (new `.cpp` project wiring requirement)
**Status:** Remaining
**File to edit:** `GameRewritten.vcxproj.filters`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Append near existing `<ClCompile Include=...>` entries for sibling source files.

### What the edit is doing
This micro-step wires the new source file into Visual Studio project metadata so builds and IDE views stay consistent.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: GameRewritten.vcxproj.filters
TASK: Add XML entry for `src/game/progression/TreasureMap.cpp` only.
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

## 330.1 Task 262H -> Enemy reinforcements header

**Task Number:** 262H
**Task Name:** Enemy reinforcements header
**Source:** `docs/docs_ORDER_PLAN.md` order 330
**Status:** Remaining
**File to edit:** `src/game/progression/TreasureMap.hpp`
**One-file rule:** Edit only this file for this micro-step.
**Lines to edit:** Search for `class`/`struct` declarations related to Enemy reinforcements header and add declarations in the matching public section.

### What the edit is doing
This micro-step adds a small, compile-safe slice of enemy reinforcements header in one file. Keep behavior minimal and deterministic so you can validate quickly before continuing.

### Qwen2.5 Coder 0.5B Instruct prompt
```text
FILE: src/game/progression/TreasureMap.hpp
TASK: Implement the smallest compiling slice for: Enemy reinforcements header.
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
- Paste at: Search for `class`/`struct` declarations related to Enemy reinforcements header and add declarations in the matching public section.
- Validate by: Save file, run the smallest available build/smoke check for this area, and confirm no new compiler errors.
- If it fails: revert this one edit and ask Qwen for a smaller compiling version.

# SLM Microcoding Protocol (Qwen2.5 Coder 0.5B Instruct)

## Hard rules for tiny LLM coding
1. One micro-task entry at a time.
2. One file edit per prompt.
3. Keep changes minimal, compile-safe, and reversible.
4. No new dependencies.
5. Do not rename or move files.
6. Prefer deterministic, smallest-working implementations.

## Context size limits
- Preferred context: **20-100 lines** around target symbol.
- Hard maximum context: **180 lines**.
- New file creation: **NEW FILE - no context needed**.

## Output-only rules for Qwen
- Return only code block to paste.
- No extra explanation text.
- No multi-file output in one response.
- Keep existing style and naming.

## Universal prompt template
```text
FILE: <path/to/file>
TASK: <single simple coding instruction>
CONTEXT TO PASTE: <20-100 lines around target symbol OR NEW FILE - no context needed>
OUTPUT: Return only the code block to paste into this file. No explanations.
RULES:
- Edit one file only.
- Keep the code small and readable.
- Do not add dependencies.
- Keep D3D11 + GT610-safe defaults.
- Do not rename or move files.
- If unsure, write the smallest compiling version.
```

## Universal validation checklist
- [ ] Edited exactly one file from the micro-task.
- [ ] Build/smoke check for touched subsystem still passes (or no new errors).
- [ ] No unrelated code was changed.
- [ ] Defaults remain low-spec safe.
- [ ] Next step only after this step is stable.

## Rollback instructions
1. Revert only the last micro-step edit.
2. Re-open the same micro-task entry.
3. Re-run prompt with smaller context and stricter wording.
4. Request: "smallest compiling version".
5. Re-validate before continuing.

## New `.cpp` file project wiring rules
When creating a new `.cpp` file, add separate micro-steps to:
1. Create/update corresponding `.hpp` (if needed).
2. Create/update `.cpp` implementation.
3. Add `.cpp` to `GameRewritten.vcxproj` (`<ClCompile Include=...>`).
4. Add `.cpp` to `GameRewritten.vcxproj.filters`.

## Main.cpp safety guidance
From `docs/MAIN_CPP_PROTECTION.md`:
- Keep `Main.cpp` orchestration-only.
- Put subsystem logic into dedicated files.
- Only add minimal call-site wiring in `Main.cpp`.

## GT610 safety guidance
From `docs/PERFORMANCE_GUARDRAILS.md`:
- Keep shader/post effects lightweight and optional.
- Favor low-overhead logic and bounded loops.
- Avoid expensive per-frame allocations.
- Maintain D3D11-compatible fallback behavior.

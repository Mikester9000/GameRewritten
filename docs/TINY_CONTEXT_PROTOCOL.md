# Tiny Context Protocol — Autonomous LLM (Batch 64 / Context 484)

This file is a **standalone runbook** for an autonomous local LLM with **tiny context and near‑zero memory**. It is designed to complete **all remaining work** (systems marked ❌ in `docs/SYSTEMS.md`) with **no human interaction** beyond providing file chunks and applying output.

**Primary sources of truth**
- `docs/SYSTEMS.md` (✅/🔧/❌ status)
- `docs/FULL_TASK_SEQUENCE.md` (task order)
- `docs/CURRENT_STATE.md` (do not rebuild)
- `docs/GRAPHICS_VISION.md`, `docs/UI_VISION.md`, `docs/COMBAT_VISION.md`
- `docs/PERFORMANCE_GUARDRAILS.md`

---

## Hard Limits (must obey)
- **Context size:** 484 tokens
- **Batch size:** 64
- **Input limit:** ≤ 180 lines per message
- **One file per message** unless explicitly required
- **Never assume hidden context**

---

## One‑Task Loop (no memory needed)
Repeat for every ❌ item, in order from `docs/FULL_TASK_SEQUENCE.md`:

1. **Read task card** from `docs/NEXT_TASK.md` (or next task in `FULL_TASK_SEQUENCE.md`).
2. **Request file chunk A** (top ~180 lines) of the first file listed.
3. **Return one of only two outputs**:
   - `NEED_MORE` + exact next lines required (line range)
   - `PATCH_PART_1` + updated code for the pasted chunk only
4. **Repeat** chunk‑by‑chunk until file done.
5. If another file is required, repeat steps 2–4 for that file.
6. **Stop.** (Do not continue to next task in the same run.)

---

## Output‑Only Rules
Every response must be **one of these**:
- `NEED_MORE: <file> <line range>`
- `PATCH_PART_N: <file>\n<updated code for that chunk only>`

**Never** include explanations, analysis, or extra text.

---

## Chunking Strategy (tiny context)
- Work in **linear order** (top → bottom).
- Never edit code outside the pasted chunk.
- If a change needs context outside the chunk, request it explicitly:
  `NEED_MORE: <file> lines 181–360`

---

## Minimal Change Rule
- Implement **only** what the task requires.
- Do **not** refactor or reformat unrelated code.
- Do **not** add new dependencies.

---

## Required Safety Checks (before output)
- Does the patch compile with only the shown code?
- Does it respect D3D11 + GT610 limits?
- Does it avoid touching ✅ systems?
- Does it follow narrative‑style code rules?

---

## Template — Task Start Prompt
Use this exact prompt to start any task:

```
TASK: <copy from docs/NEXT_TASK.md>
FILES: <list from task>
RULES: Output only NEED_MORE or PATCH_PART_N. No explanations.
SEND: First 180 lines of <first file>.
```

---

## Template — Continuation Prompt
```
CONTINUE: <file> lines <start–end>
RULES: Output only NEED_MORE or PATCH_PART_N. No explanations.
```

---

## Template — Multi‑file Task
Finish file A **completely** before requesting file B.

---

## Finish Condition (for a single task)
Return:
```
PATCH_DONE: <list of files updated>
```
Then stop.

---

## Do Not Do
- Do not merge tasks.
- Do not request extra files unless required.
- Do not change filenames or move files.
- Do not add logging or debug unless task says so.

---

## Where this fits in the workflow
- `docs/NEXT_TASK.md` points to the current task.
- `docs/FULL_TASK_SEQUENCE.md` defines the full order.
- After a task is completed, a human should update:
  `docs/SYSTEMS.md`, `docs/CHANGELOG.md`, `docs/AGENT_WORK_LOG.md`.

---

## Absolute Priority
**Complete one tiny chunk at a time.**
**Never assume memory.**
**Never exceed the chunk limits.**

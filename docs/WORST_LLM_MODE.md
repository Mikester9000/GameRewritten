# Worst-LLM Mode (Maximum Ambiguity Removal)

Use this mode for very weak local models with poor planning, memory, and cross-file reasoning.

## Rules
- Never choose a task manually.
- Never reorder tasks.
- Never infer new scope from nearby code.
- Never continue to a second feature in the same run.

## Start command
Run exactly:

```bash
python tools/llm/worst_llm_guard.py start
```

This writes `docs/NEXT_TASK.md` from the first unchecked item in `docs/FULL_TASK_SEQUENCE.md`.

## One-run algorithm (strict)
1. Open `docs/NEXT_TASK.md`.
2. Edit only listed files for that task.
3. Finish implementation.
4. Update:
   - `docs/SYSTEMS.md`
   - `docs/CHANGELOG.md`
   - `docs/AGENT_WORK_LOG.md`
5. Run exactly:

```bash
python tools/llm/worst_llm_guard.py complete
```

6. Stop.

## What `complete` enforces automatically
- Fails if no files changed.
- Fails if any file outside task scope was edited.
- Fails if any required doc update is missing:
  - `docs/SYSTEMS.md`
  - `docs/CHANGELOG.md`
  - `docs/AGENT_WORK_LOG.md`
- If all checks pass, marks task done in `docs/FULL_TASK_SEQUENCE.md` and regenerates `docs/NEXT_TASK.md`.

## Failure fallback (no reasoning)
If blocked:
1. Revert only the last risky edit.
2. Implement a smaller stub that compiles and keeps behavior safe.
3. Document limitation in `docs/AGENT_WORK_LOG.md` under `KNOWN ISSUES`.
4. Still advance only one task at a time.

## Completion
The track is complete when `docs/NEXT_TASK.md` says no unchecked tasks remain.

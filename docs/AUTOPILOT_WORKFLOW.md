# Autopilot Workflow (Small Local LLM)

Use this exact workflow every run.
Do not improvise.

## Files used by the workflow
- `docs/NEXT_TASK.md` → current single task (only coding target for this run)
- `docs/FULL_TASK_SEQUENCE.md` → complete ordered list from now to project-complete
- `docs/SYSTEMS.md` → source of truth for implemented vs not implemented
- `docs/AGENT_WORK_LOG.md` → append-only change history
- `docs/CHANGELOG.md` → one-line release notes per completed task

## Run loop (mandatory)
1. Run `python tools/llm/worst_llm_guard.py doctor`.
2. Run `python tools/llm/worst_llm_guard.py start`.
3. Open `docs/NEXT_TASK.md`.
4. Implement exactly that task.
5. Update `docs/SYSTEMS.md` (`❌` to `✅` for the finished system).
6. Add one line to `docs/CHANGELOG.md`.
7. Append one entry to `docs/AGENT_WORK_LOG.md`.
8. Run `python tools/llm/worst_llm_guard.py complete`.
9. Stop.

## No-decision defaults
- If uncertain, implement the smallest safe stub in listed files.
- If a task appears to need extra files, only add those required by compile/link errors.
- If a task is too large, split into one minimal visible slice but keep the same task ID.

## Recommended zero-interpretation command sequence
1. `python tools/llm/worst_llm_guard.py doctor`
2. `python tools/llm/worst_llm_guard.py start`
3. `python tools/llm/worst_llm_guard.py complete`

## Completion condition
Project is complete for this track when:
- `docs/FULL_TASK_SEQUENCE.md` has no unchecked tasks.
- `docs/SYSTEMS.md` has no `❌` rows.

## Safety constraints
- One task per run.
- No new dependencies.
- Keep D3D11 + GT610 safe defaults.
- Keep edits in listed files only unless task explicitly says otherwise.

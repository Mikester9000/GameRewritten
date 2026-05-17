# Agent Work Log

This file records every change made by an automated agent or local LLM.
**Append one entry per completed task. Never delete entries.**

---

## Format (copy this for each entry)

```
[YYYY-MM-DD] TASK: <one-sentence task name>
  FILES CHANGED: <list of files changed>
  WHAT CHANGED: <one or two sentences>
  KNOWN ISSUES: <any breakage or regression noticed, or "none">
```

---

## Log

[2026-05-17] TASK: Harden worst-LLM workflow with machine-enforced completion guard
  FILES CHANGED: docs/WORST_LLM_MODE.md, docs/AUTOPILOT_WORKFLOW.md, docs/AGENT_RULES.md, docs/LOCAL_AGENT_QUICKSTART.md, docs/FULL_TASK_SEQUENCE.md, docs/README_AGENT_DOCS.md, docs/NEXT_TASK.md, README.md, tools/llm/advance_next_task.py, tools/llm/worst_llm_guard.py, docs/CHANGELOG.md
  WHAT CHANGED: Added a strict start/complete guard script that blocks out-of-scope edits and missing completion docs, then auto-advances backlog task state. Updated all relevant docs to use guarded commands and regenerated NEXT_TASK.
  KNOWN ISSUES: dotnet build still fails in this environment due missing Visual Studio C++ targets (MSB4278).

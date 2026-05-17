#!/usr/bin/env python3
"""
Deterministic NEXT_TASK rotator for low-capability local LLM agents.

Usage:
  python tools/llm/advance_next_task.py
      -> Writes docs/NEXT_TASK.md from the first unchecked task in docs/FULL_TASK_SEQUENCE.md

  python tools/llm/advance_next_task.py --complete-current
      -> Marks the current task (from docs/NEXT_TASK.md Task ID) as complete in docs/FULL_TASK_SEQUENCE.md
         and then writes docs/NEXT_TASK.md for the next unchecked task.
"""

from __future__ import annotations

import argparse
import re
from pathlib import Path
from typing import List, Optional


REPO_ROOT = Path(__file__).resolve().parents[2]
FULL_TASK_PATH = REPO_ROOT / "docs" / "FULL_TASK_SEQUENCE.md"
NEXT_TASK_PATH = REPO_ROOT / "docs" / "NEXT_TASK.md"

TASK_RE = re.compile(r"^- \[(?P<state>[ xX])\] \*\*Task (?P<id>\d+): (?P<name>.+?)\*\*$")
FILES_RE = re.compile(r"^\s*- Files:\s*(?P<files>.+?)\s*$")
TASK_ID_LINE_RE = re.compile(r"^\*\*Task ID:\*\*\s*(?P<id>\d+)\s*$")


class Task:
    def __init__(self, task_id: str, name: str, files: str, checked: bool, line_index: int) -> None:
        self.task_id = task_id
        self.name = name
        self.files = files
        self.checked = checked
        self.line_index = line_index


def read_lines(path: Path) -> List[str]:
    return path.read_text(encoding="utf-8").splitlines()


def write_lines(path: Path, lines: List[str]) -> None:
    path.write_text("\n".join(lines).rstrip() + "\n", encoding="utf-8")


def parse_tasks(lines: List[str]) -> List[Task]:
    tasks: List[Task] = []
    for i, line in enumerate(lines):
        match = TASK_RE.match(line)
        if not match:
            continue

        files = "`(missing files line)`"
        if i + 1 < len(lines):
            files_match = FILES_RE.match(lines[i + 1])
            if files_match:
                files = files_match.group("files")

        tasks.append(
            Task(
                task_id=match.group("id"),
                name=match.group("name"),
                files=files,
                checked=match.group("state").lower() == "x",
                line_index=i,
            )
        )
    return tasks


def first_unchecked(tasks: List[Task]) -> Optional[Task]:
    for task in tasks:
        if not task.checked:
            return task
    return None


def read_current_task_id(next_task_lines: List[str]) -> Optional[str]:
    for line in next_task_lines:
        match = TASK_ID_LINE_RE.match(line.strip())
        if match:
            return match.group("id")
    return None


def mark_task_complete(lines: List[str], task_id: str) -> List[str]:
    updated = list(lines)
    for i, line in enumerate(updated):
        match = TASK_RE.match(line)
        if not match:
            continue
        if match.group("id") != task_id:
            continue
        updated[i] = re.sub(r"^- \[ \]", "- [x]", line)
        return updated
    raise ValueError(f"Task ID {task_id} was not found in {FULL_TASK_PATH}")


def build_next_task_content(task: Task) -> str:
    return f"""# NEXT TASK (Auto-Generated)

This is your only coding task.
Do not choose a different task.

**Task ID:** {task.task_id}
**System:** {task.name}
**Files to touch:** {task.files}

---

## Zero-decision execution steps
1. Open each listed file and read it once top-to-bottom.
2. Implement the smallest working version of this system only.
3. Keep edits inside listed files only unless strictly required by compiler errors.
4. Do not rename files or move files.
5. Do not add dependencies.
6. Keep D3D11 + GT610-safe defaults.

## Required completion updates
1. Update `docs/SYSTEMS.md` for this system (`❌` -> `✅`).
2. Add one line in `docs/CHANGELOG.md`.
3. Append one entry in `docs/AGENT_WORK_LOG.md`.
4. Run:
   `python tools/llm/advance_next_task.py --complete-current`
   This marks this task complete in `docs/FULL_TASK_SEQUENCE.md` and writes the next task here.

## Hard stop rule
After the command above succeeds, stop immediately.
"""


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--complete-current",
        action="store_true",
        help="Mark current NEXT_TASK as complete and advance to next unchecked task.",
    )
    args = parser.parse_args()

    full_lines = read_lines(FULL_TASK_PATH)

    if args.complete_current:
        next_lines = read_lines(NEXT_TASK_PATH)
        current_id = read_current_task_id(next_lines)
        if not current_id:
            raise ValueError(
                "docs/NEXT_TASK.md does not contain '**Task ID:** <id>'. "
                "Run without --complete-current once to regenerate it."
            )
        full_lines = mark_task_complete(full_lines, current_id)
        write_lines(FULL_TASK_PATH, full_lines)

    tasks = parse_tasks(full_lines)
    next_task = first_unchecked(tasks)

    if not next_task:
        NEXT_TASK_PATH.write_text(
            "# NEXT TASK (Auto-Generated)\n\nNo unchecked tasks remain in docs/FULL_TASK_SEQUENCE.md.\nProject task sequence is complete.\n",
            encoding="utf-8",
        )
        print("No unchecked tasks remain. Marked project as complete in NEXT_TASK.")
        return 0

    NEXT_TASK_PATH.write_text(build_next_task_content(next_task), encoding="utf-8")
    print(f"Wrote NEXT_TASK for Task {next_task.task_id}: {next_task.name}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

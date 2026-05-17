#!/usr/bin/env python3
"""
Guardrail wrapper for ultra-low-capability local LLM workflows.

Commands:
  python tools/llm/worst_llm_guard.py start
      -> Regenerate docs/NEXT_TASK.md from the first unchecked backlog task.

  python tools/llm/worst_llm_guard.py complete
      -> Validate task-scope edits + required docs, then auto-advance task state.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path
from typing import List, Set


REPO_ROOT = Path(__file__).resolve().parents[2]
NEXT_TASK_PATH = REPO_ROOT / "docs" / "NEXT_TASK.md"
ADVANCE_SCRIPT = REPO_ROOT / "tools" / "llm" / "advance_next_task.py"

TASK_ID_RE = re.compile(r"^\*\*Task ID:\*\*\s*(?P<id>\d+)\s*$")
FILES_LINE_RE = re.compile(r"^\*\*Files to touch:\*\*\s*(?P<files>.+?)\s*$")
BACKTICK_PATH_RE = re.compile(r"`([^`]+)`")

REQUIRED_DOCS = {
    "docs/SYSTEMS.md",
    "docs/CHANGELOG.md",
    "docs/AGENT_WORK_LOG.md",
}

FLOW_FILES = {
    "docs/NEXT_TASK.md",
    "docs/FULL_TASK_SEQUENCE.md",
}


def run(cmd: List[str]) -> str:
    result = subprocess.run(cmd, cwd=REPO_ROOT, text=True, capture_output=True)
    if result.returncode != 0:
        stderr = result.stderr.strip()
        stdout = result.stdout.strip()
        raise RuntimeError(stderr or stdout or f"Command failed: {' '.join(cmd)}")
    return result.stdout


def read_next_task_text() -> str:
    if not NEXT_TASK_PATH.exists():
        raise RuntimeError("docs/NEXT_TASK.md not found. Run start first.")
    return NEXT_TASK_PATH.read_text(encoding="utf-8")


def parse_task_id(text: str) -> str:
    for line in text.splitlines():
        match = TASK_ID_RE.match(line.strip())
        if match:
            return match.group("id")
    raise RuntimeError("NEXT_TASK is missing '**Task ID:** <id>'. Regenerate with start.")


def parse_allowed_files(text: str) -> Set[str]:
    raw_line = None
    for line in text.splitlines():
        match = FILES_LINE_RE.match(line.strip())
        if match:
            raw_line = match.group("files")
            break
    if raw_line is None:
        raise RuntimeError("NEXT_TASK is missing '**Files to touch:** line.")

    allowed: Set[str] = set()
    for token in BACKTICK_PATH_RE.findall(raw_line):
        token = token.strip()
        if not token:
            continue
        for expanded in expand_file_token(token):
            allowed.add(expanded)
    return allowed


def expand_file_token(token: str) -> Set[str]:
    token = token.strip()
    if token.endswith(".cpp/hpp"):
        base = token[: -len(".cpp/hpp")]
        return {f"{base}.cpp", f"{base}.hpp"}
    if token.endswith(".h/.cpp"):
        base = token[: -len(".h/.cpp")]
        return {f"{base}.h", f"{base}.cpp"}
    if token.endswith("/hpp"):
        base = token[: -len("/hpp")]
        return {f"{base}.hpp"}
    if token.endswith("/cpp"):
        base = token[: -len("/cpp")]
        return {f"{base}.cpp"}
    return {token}


def current_changed_files() -> Set[str]:
    porcelain = run(["git", "status", "--porcelain"])
    changed: Set[str] = set()
    for line in porcelain.splitlines():
        if not line:
            continue
        path = line[3:]
        if " -> " in path:
            path = path.split(" -> ", 1)[1]
        changed.add(path.strip())
    return changed


def ensure_required_docs_present(changed: Set[str]) -> None:
    missing = sorted(REQUIRED_DOCS - changed)
    if missing:
        raise RuntimeError(
            "Missing required completion doc updates:\n"
            + "\n".join(f"- {item}" for item in missing)
        )


def ensure_scope(changed: Set[str], allowed_task_files: Set[str]) -> None:
    allowed = set(allowed_task_files) | REQUIRED_DOCS | FLOW_FILES
    disallowed = sorted(changed - allowed)
    if disallowed:
        raise RuntimeError(
            "Changed files outside task scope:\n"
            + "\n".join(f"- {item}" for item in disallowed)
        )


def do_start() -> int:
    run([sys.executable, str(ADVANCE_SCRIPT)])
    print("START OK: docs/NEXT_TASK.md regenerated from first unchecked backlog task.")
    print("Now implement only what docs/NEXT_TASK.md says.")
    return 0


def do_complete() -> int:
    text = read_next_task_text()
    task_id = parse_task_id(text)
    allowed_task_files = parse_allowed_files(text)
    changed = current_changed_files()

    if not changed:
        raise RuntimeError("No file changes detected. Complete the task before finishing.")

    ensure_required_docs_present(changed)
    ensure_scope(changed, allowed_task_files)

    run([sys.executable, str(ADVANCE_SCRIPT), "--complete-current"])
    print(f"COMPLETE OK: Task {task_id} closed and next task generated.")
    print("Hard stop: end this run now.")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("command", choices=["start", "complete"])
    args = parser.parse_args()

    if args.command == "start":
        return do_start()
    return do_complete()


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except RuntimeError as exc:
        print(f"ERROR: {exc}")
        raise SystemExit(1)

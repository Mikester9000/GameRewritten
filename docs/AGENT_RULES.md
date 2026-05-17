# Agent Rules

Rules that apply to every automated agent or Copilot coding session in this repo.

## Before Writing Any Code
1. Read `docs/NEXT_TASK.md` — only implement that one task.
2. Read `docs/FULL_TASK_SEQUENCE.md` — confirm the task order and current checkbox state.
3. Read `docs/SYSTEMS.md` — confirm the system you are about to build is not already listed as ✅ Complete.
4. Read `.github/copilot-instructions.md` — follow all rules there without exception.
5. Read the relevant existing files for the area you are changing before touching them.

## Hard Rules
- Never reimplement a system already marked ✅ in `docs/SYSTEMS.md`.
- Never use `printf`, `std::cout`, or `OutputDebugStringA` in new code — use `LOG_INFO` / `LOG_WARN` / `LOG_ERROR`.
- Never add a new third-party library without explicit instruction — all needed libraries are already vendored.
- Never modify `Main.cpp` structure (init order, shutdown order) except to insert a new system in the correct position.
- Never rename or move existing files unless the task explicitly says to.
- Never write to disk (save files, write config) without explicit instruction.
- Every new `.cpp` file must be added to `GameRewritten.vcxproj` and `GameRewritten.vcxproj.filters` in the same PR.
- Every new feature must compile without warnings on D3D11 / MSVC.
- Follow the Narrative Code style defined in
  `.github/copilot-instructions.md` — every function tells one
  story, reads top to bottom, and uses self-describing names.

## PR Scope Rules
- Each PR implements exactly one feature from the prompt. Do not bundle unrelated changes.
- Do not refactor existing code unless the prompt explicitly requests it.
- Do not change shader files unless the prompt explicitly requires it.

## After Writing Code
- Update `docs/SYSTEMS.md` — change the new system's status from ❌ to ✅.
- Add a one-line entry to `docs/CHANGELOG.md` (create it if it doesn't exist).
- Append one entry to `docs/AGENT_WORK_LOG.md` using the format shown in that file.
- Mark the completed item as `- [x]` in `docs/FULL_TASK_SEQUENCE.md`.
- Update `docs/NEXT_TASK.md` — copy the next unchecked task from `docs/FULL_TASK_SEQUENCE.md` to replace the completed one.

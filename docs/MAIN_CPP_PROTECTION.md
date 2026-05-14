# Main.cpp Protection Rules

## Purpose
Protect `src/app/Main.cpp` from becoming a long-term feature sink.

## `Main.cpp` is allowed to do
- Startup/shutdown sequencing
- System wiring
- High-level frame orchestration
- Calling update/draw entry points

## `Main.cpp` should not do
- Deep gameplay rules
- Per-feature state machine internals
- Long-term combat/AI logic
- Content parsing logic

## When to create helper/runtime systems
Create a helper/system when:
- logic is feature-specific,
- logic grows beyond a small orchestration call,
- same logic would be reused or expanded.

## Good change example
- Add a single call in `Main.cpp` to `RuntimeScene::UpdateCombatReadability()`.

## Bad change example
- Add 100+ lines of enemy behavior logic directly in `Main.cpp`.

## Rule before merge
If `Main.cpp` change adds behavior detail, stop and extract.

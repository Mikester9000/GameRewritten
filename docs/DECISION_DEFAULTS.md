# Decision Defaults (When Unsure)

## Default code placement
- New gameplay code → `src/game/*`
- New UI code → `src/ui/*`
- New world data logic → `src/world/*`
- New asset/lookup parsing logic → `src/assets/*`

## Main.cpp default
- Avoid adding feature internals in `Main.cpp`.
- Add orchestration calls only; extract detail elsewhere.

## Helpers default
- Add helper when logic is feature-specific and growing.
- Keep helper focused and narratively readable.

## Rendering default
- Prefer simple existing render path.
- Prefer low-cost shader/material approach.
- Defer heavy pipeline ideas unless explicitly requested.

## Defer-feature default
Defer if:
- core loop clarity is not improved now,
- scope is large and low confidence,
- adds architecture weight without immediate use.

## Readability vs complexity default
- Pick readability first unless complexity is required for correctness.

## What to do when unsure
1. Re-check `SYSTEM_OWNERSHIP.md`.
2. Re-check `MAIN_CPP_PROTECTION.md`.
3. Choose smallest reversible change.
4. Document assumptions in task notes.

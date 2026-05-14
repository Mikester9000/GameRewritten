# Coding Style (Practical)

See also: `.github/copilot-instructions.md`, [SAFE_REFACTOR_RULES.md](./SAFE_REFACTOR_RULES.md).

## Core rules
- One function = one story.
- Read top-to-bottom: setup → guards → main logic → output.
- Use self-describing names.
- Prefer clear helpers over giant monolithic functions.
- Avoid clever tricks that reduce readability.

## Narrative code style
- Each block should set up the next block.
- Use small helper functions with direct names.
- Keep flow predictable for beginners.

## Naming
- Good: `distanceToTarget`, `isLockOnValid`, `UpdateCombatTimers`
- Avoid: `d`, `tmp2`, `DoThing`

## Comment style
- Keep comments that explain **why**.
- Remove comments that just repeat **what** code already says.

## Helpers vs over-abstraction
- Add helpers when they simplify a repeated or long step.
- Do not create abstraction layers “for future maybe.”
- Prefer straightforward local code to premature frameworks.

## Avoid cleverness
- Prefer explicit loops/conditions.
- Avoid compact but cryptic patterns.
- Avoid deep indirection for simple logic.

## Keep `Main.cpp` orchestration-only
- `Main.cpp` should call systems, not own system internals.
- If a feature grows beyond a few lines, move it to a helper/system.

## Good vs bad style (short example)

### Good
- `BeginFrame()`
- `UpdateCombat()`
- `SubmitActors()`
- `DrawUI()`

### Bad
- Single 300-line mixed function doing input, combat, world loading, rendering decisions, and UI formatting in one block.

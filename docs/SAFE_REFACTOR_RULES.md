# Safe Refactor Rules

## Refactor intent
- Improve structure without changing behavior unless explicitly scoped.

## Rules
- One responsibility at a time.
- Prefer behavior-preserving edits.
- No giant mixed refactors.
- Keep rename/move scope minimal.
- Keep commits easy to review/revert.

## How to document cleanup
- State what changed structurally.
- State what behavior should remain identical.
- List verification checks run.

## Useful refactor vs churn
Useful refactor:
- reduces duplication,
- clarifies ownership,
- lowers future bug risk.

Churn:
- broad renaming/moving with no practical outcome,
- abstraction for abstraction’s sake.

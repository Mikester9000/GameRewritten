# Known Issues and Fragile Spots

Use this before touching risky areas.  
See also: [CURRENT_STATE.md](./CURRENT_STATE.md), [SAFE_REFACTOR_RULES.md](./SAFE_REFACTOR_RULES.md).

## 1) Main loop is overloaded
- **Impact:** harder maintenance, more regression risk.
- **Likely files:** `src/app/Main.cpp`, related app helpers.
- **Status:** active technical debt.
- **Avoid unless asked:** no (safe extraction work is welcome).

## 2) Documentation drift in older docs
- **Impact:** wrong assumptions for future agents.
- **Likely files:** roadmap/checklist/older vision docs.
- **Status:** ongoing cleanup needed.
- **Avoid unless asked:** no (doc fixes are useful).

## 3) Audio behavior breadth is still limited
- **Impact:** incomplete music/state feedback depth.
- **Likely files:** `src/audio/*`, `ThirdParty` wrappers.
- **Status:** partial.
- **Avoid unless asked:** yes for major redesign.

## 4) World progression depth is early
- **Impact:** open-world structure exists but many gameplay layers are not yet built.
- **Likely files:** `src/world/*`, `src/game/*`, `Content/World/*`.
- **Status:** expected.
- **Avoid unless asked:** no for incremental additions.

## 5) Performance regression risk from UI/debug growth
- **Impact:** low-spec stability can degrade quietly.
- **Likely files:** `src/ui/*`, `src/rendering/*`.
- **Status:** monitor.
- **Avoid unless asked:** no, but keep features guarded/toggled.

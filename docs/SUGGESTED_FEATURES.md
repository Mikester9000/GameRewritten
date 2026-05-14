# Suggested Features (Curated, Practical)

See also: [PLANNED_FEATURES.md](./PLANNED_FEATURES.md), [FEATURE_ROADMAP_STRUCTURE.md](./FEATURE_ROADMAP_STRUCTURE.md).

## Small safe improvements
### 1) Attack telegraph-lite
- **Likely files:** `src/game/actors/EnemyActor.*`
- **Why:** better readability with low complexity.
- **Do not break:** existing enemy chase/attack timing.

### 2) Screen-edge damage cue polish
- **Likely files:** `src/ui/GameHUD.*`
- **Why:** immediate player feedback.
- **Do not break:** HUD clarity and pause behavior.

### 3) Debug budget counters
- **Likely files:** `src/ui/ImGuiLayer.*`, renderer stats exposure.
- **Why:** catches low-spec regressions early.
- **Do not break:** release gameplay path.

## Medium features
### 4) Multi-cell runtime activation (limited radius)
- **Likely files:** `src/world/*`, app/world refresh flow.
- **Why:** stronger open-world feel.
- **Do not break:** existing single-cell stability.

### 5) Interaction actor baseline (NPC/chest/rest point stub)
- **Likely files:** `src/game/actors/*`, `src/game/*`, `src/ui/*`
- **Why:** meaningful exploration loop.
- **Do not break:** combat input flow.

## Content/workflow improvements
### 6) Better prefab naming + registry validation checks
- **Likely files:** `src/assets/*`, docs.
- **Why:** fewer content-side errors.
- **Do not break:** existing `AssetRegistry` IDs.

### 7) Region landmark pass in content
- **Likely files:** `Content/World/*`, `Content/Prefabs/*`
- **Why:** improves navigation and FF-style journey feel.
- **Do not break:** traversal readability.

## Readability/cleanup improvements
### 8) Extract more frame helpers from `Main.cpp`
- **Likely files:** `src/app/*`
- **Why:** lower regression risk, clearer ownership.
- **Do not break:** init/update/draw order.

## Performance-safe polish
### 9) Low-cost hit feedback polish
- **Likely files:** `src/ui/*`, `src/game/combat/*`
- **Why:** stronger combat feel without heavy rendering.
- **Do not break:** GT 610 frame-time.

# Suggested Features (Curated, Practical)

See also: [PLANNED_FEATURES.md](./PLANNED_FEATURES.md), [FEATURE_ROADMAP_STRUCTURE.md](./FEATURE_ROADMAP_STRUCTURE.md).

## Current gaps (highest value)
### 1) Cel shader / toon shading stack
- **Likely files:** `Shaders/basic3d_*.hlsl`, `src/rendering/d3d11/*`, `src/ui/ImGuiLayer.*`
- **Why:** closes major FF-style visual gap called out in project docs.
- **Do not break:** GT 610 frame-time and fallback render path.

### 2) Save / load system completion
- **Likely files:** `src/game/*`, `src/world/*`, serialization helpers.
- **Why:** required for progression continuity and release readiness.
- **Do not break:** current runtime scene ownership and reload flow.

### 3) NPC actor baseline
- **Likely files:** `src/game/actors/*`, `src/game/world/*`, interaction UI hooks.
- **Why:** unlocks quest/dialog/event gameplay loops.
- **Do not break:** combat controls and camera routing.

### 4) Event zone trigger system
- **Likely files:** `src/game/world/*`, `src/app/Main.cpp` orchestration hooks.
- **Why:** foundational world progression trigger layer.
- **Do not break:** world update cadence or low-spec stability.

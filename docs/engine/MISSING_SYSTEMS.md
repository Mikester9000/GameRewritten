# MISSING SYSTEMS (HUMAN GAP ANALYSIS)

This is a prioritized reality check for what is still missing to get the engine into a full playable foundation.

## Critical Rendering Gaps (not in any plan file)

### 1) Cel/toon shader (**highest visual priority**)
- Needed shader files: `Shaders/cel_ps.hlsl` and `Shaders/cel_vs.hlsl`
- Why critical: without cel shading, visuals read as a grey tech demo instead of FF-style JRPG
- 3-step shading approach (NdotL based):
  1. Compute `NdotL = saturate(dot(normal, lightDir))`
  2. Quantize into 3 bands (shadow / mid / highlight)
  3. Output banded diffuse color with stable thresholds

### 2) Silhouette/outline pass
- Option A: render backfaces slightly scaled in dark color
- Option B: post-process edge detection

### 3) Color grading / LUT pass
- Simple full-screen post-process to control mood and scene consistency

## Critical Gameplay Gaps (shown as ❌ in SYSTEMS.md)
- Save / load system — nothing persists without this
- World event trigger zones — every story moment depends on this
- NPC actor — needed before quests, shops, or story
- Inventory system — core RPG loop requires this
- Quest system — placeholder quests still need this scaffold

## NEXT_TASK.md status
- Current file is stale: points to **Task 021 (Combat camera zoom)**
- `SYSTEMS.md` already marks camera zoom as ✅
- Real next task from ORDER_PLAN should be **World event trigger zones**
  - Target files: `src/game/world/EventZone.cpp`, `src/game/world/EventZone.hpp`

## ORDER_PLAN issues to fix later
- Status column missing from tables after task 96
- PC release features (ultrawide, anti-aliasing) are incorrectly placed in Phase 1 before core gameplay systems
- Cel shader task is missing entirely

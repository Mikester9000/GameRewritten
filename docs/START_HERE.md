# START HERE

Use this file at the start of every coding session.

## Where am I today?
- Current project snapshot: [`CURRENT_STATE.md`](./CURRENT_STATE.md)
- Current single task: [`NEXT_TASK.md`](./NEXT_TASK.md)

## What do I build next?

### Tier 1 — Engine blockers (do first)
1. Save/load system
2. World event trigger zones
3. NPC actor stub
4. Cel shader / toon shading (**currently missing from all plan files**)

### Tier 2 — Engine completers (playable loop)
1. Inventory stub
2. Quest system stub
3. Dialogue branching
4. Fast travel

### Tier 3 — Content & polish (do last)
- All CON1–CON8 extended features

## What files do I open for what?

| Need | Open |
|---|---|
| Writing code today | `engine/ARCHITECTURE.md` + `engine/CODING_STYLE.md` |
| Checking what exists | `engine/SYSTEMS.md` |
| Next task details | `NEXT_TASK.md` |
| Visual style rules | `vision/GRAPHICS_VISION.md` |
| Combat rules | `vision/COMBAT_VISION.md` |
| Story placeholder | `story/STORY_PLACEHOLDER.md` |
| Performance rules | `engine/PERFORMANCE.md` |

## Known gaps in the plan
- Cel shader / toon shading (**CRITICAL** — FF7-style look depends on this)
- Character outline / silhouette pass
- Story actual content (use placeholder until engine is done)
- `NEXT_TASK.md` is currently stale in legacy docs; real next task is **World event trigger zones**

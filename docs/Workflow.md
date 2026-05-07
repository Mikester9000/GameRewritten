# Workflow Guide

This document describes the preferred workflow for adding and changing features in the project.

---

## 1. General Development Rule

When working on a new feature:

1. define the goal clearly
2. choose the correct home for the code
3. make the smallest safe change first
4. verify behavior
5. update docs if the workflow changed

Prefer small, reversible changes over large mixed refactors.

---

## 2. When Unsure What To Do Next

Check these files in order:

1. `docs/Development Roadmap.txt`
2. `docs/Engine Cleanup Checklist.txt`
3. `docs/ARCHITECTURE.md`

Use:
- roadmap for long-term direction
- cleanup checklist for small useful improvements
- architecture doc for deciding where code belongs

---

## 3. Adding a New Prefab

### Files involved
- `Content/Prefabs/...`
- `Content/AssetRegistry.json`

### Steps
1. Create a new prefab JSON file in `Content/Prefabs/`
2. Register it in `Content/AssetRegistry.json` under a `prefabs.*` ID
3. Press `F5` in-game to reload assets/world data
4. Verify it appears in the World Editor prefab list

### Acceptance
- prefab loads without parse errors
- prefab appears in the editor list
- prefab can be placed and saved

---

## 4. Adding a New World Cell

### Files involved
- `Content/World/world.json`
- `Content/World/cell_X_Z.json`

### Steps
1. Add the cell entry to `world.json`
2. Create the corresponding `cell_X_Z.json`
3. Set terrain/forest/instance values
4. Press `F5` in-game to reload
5. Walk into the cell and verify terrain/instances

### Acceptance
- cell loads
- biome settings apply
- crossing into the cell rebuilds correctly

---

## 5. Adding a New Shader

### Files involved
- `Shaders/...`
- one or more renderer source files

### Steps
1. Add the `.hlsl` files
2. Compile/load them in the appropriate renderer class
3. add error logging for compile failures
4. verify the draw path still succeeds

### Acceptance
- shader compiles
- render path uses it correctly
- failures are logged clearly

---

## 6. Adding a New Runtime Gameplay Feature

Examples:
- player ability
- enemy behavior
- runtime visual
- lock-on
- dodge

### Preferred process
1. add the data/logic in `src/game/`
2. expose only the minimum needed to `src/app/Main.cpp`
3. avoid putting long-term gameplay logic directly into `Main.cpp`
4. if rendering is needed, pass the minimum render-facing data into the renderer

### Acceptance
- feature has a clear home
- `Main.cpp` remains mostly orchestration

---

## 7. Refactoring Rules

Before refactoring:
- identify the exact problem
- keep behavior unchanged where possible
- refactor one responsibility at a time

Good refactor examples:
- split one large function into helpers
- replace duplicate resource cleanup
- isolate runtime actor logic from world/editor logic

Avoid:
- feature work mixed with large unrelated cleanup
- renaming many things at once without behavioral value

---

## 8. Debugging and Reload Workflow

### F5 reload
Use `F5` to reload:
- asset registry
- world grid
- terrain/cell-driven content

### Output and logs
Check logs when:
- shaders fail
- prefabs do not appear
- cells fail to load
- JSON parse fails

### Verification habit
After each change:
1. build
2. run
3. test only the changed behavior first
4. then do one short regression pass

---

## 9. Current Recommended Feature Order

Near-term:
1. runtime/static split in primitive rendering
2. FF7-style player blockout prefab
3. runtime player visual hookup
4. player state machine
5. first attack
6. first enemy

Do not jump ahead to high-end rendering before the actor/gameplay path is stable.

---

## 10. Documentation Update Rule

Update docs when:
- a new workflow is introduced
- a new folder ownership rule is established
- a new asset type is added
- an engine-wide convention changes

Minimum docs to keep current:
- `docs/Development Roadmap.txt`
- `docs/Engine Cleanup Checklist.txt`
- `docs/ARCHITECTURE.md`
- `docs/WORKFLOW.md`

---

## 11. Tasking Rule for Agents

When giving a task to an agent, include:

1. the goal
2. exact files to touch
3. whether behavior must remain unchanged
4. acceptance criteria
5. whether docs should be updated too

Preferred task style:
- one focused change
- one clear objective
- one validation target

This usually produces better results than broad open-ended requests.
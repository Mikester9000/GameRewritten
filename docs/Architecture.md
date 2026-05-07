# Architecture Overview

This document explains where code should go and how the main engine systems relate to each other.

---

## 1. Guiding Principles

1. Prefer clear ownership over convenience.
2. Prefer small extensible systems over one large god file.
3. Keep rendering, gameplay, world data, and tools separated.
4. `Main.cpp` should orchestrate systems, not permanently own their logic.
5. Build for long-term maintainability, not only short-term speed.

---

## 2. Current High-Level Structure

### `src/app/`
Application startup and high-level runtime orchestration.

Expected responsibilities:
- initialize systems
- wire dependencies
- run main loop
- shut systems down

Avoid placing long-term gameplay logic here.

---

### `src/rendering/`
Rendering systems and graphics resources.

Current examples:
- D3D11 device setup
- terrain rendering
- primitive rendering support through game-facing render helpers

Expected responsibilities:
- GPU resource setup
- shader management
- mesh/terrain/scene draw support
- render-time data flow

Avoid placing gameplay rules here.

---

### `src/game/`
Gameplay-facing systems.

Current examples:
- camera controller
- forest
- prefab library
- primitive renderer

Planned future responsibilities:
- player actor
- enemies
- combat
- runtime actors
- interaction logic

---

### `src/world/`
World layout and data-driven world structure.

Current examples:
- world grid
- cell loading
- cell save/load

Expected responsibilities:
- world cell definitions
- biome/cell metadata
- authored cell content
- streaming decisions

---

### `src/assets/`
Asset loading and registry systems.

Expected responsibilities:
- asset registry lookup
- prefab/material/scene loading
- future mesh/material pipeline support

---

### `src/ui/`
UI and in-engine tools.

Current examples:
- ImGui layer
- world editor

Expected responsibilities:
- debug UI
- editor panels
- pause menu
- future dev tools

---

## 3. Runtime Ownership Model

### Application layer
Owns:
- window
- renderer
- world grid
- UI layer
- high-level game systems

### World systems
Own:
- loaded cell data
- authored instances
- terrain/forest cell-driven content

### Runtime actor systems
Own:
- player
- enemies
- NPCs
- moving gameplay entities

### Renderer
Owns:
- GPU resources
- render pipelines
- draw submission support

Renderer should not own gameplay decisions.

---

## 4. File Placement Rules

### Put code in `src/app/` when:
- it wires systems together
- it controls startup/shutdown order
- it coordinates per-frame system calls

### Put code in `src/rendering/` when:
- it creates or manages GPU resources
- it compiles shaders
- it performs drawing
- it translates data into renderable form

### Put code in `src/game/` when:
- it affects gameplay behavior
- it models actors or interactions
- it governs movement, combat, targeting, or animation state

### Put code in `src/world/` when:
- it defines world data
- it loads/saves cell content
- it handles world-space partitioning

### Put code in `src/assets/` when:
- it resolves asset IDs
- it parses content files
- it loads reusable content definitions

### Put code in `src/ui/` when:
- it draws debug/editor UI
- it handles tool-side interactions

---

## 5. Desired Near-Term Structure

### Recommended future folders
- `src/game/actors/`
- `src/game/combat/`
- `src/game/camera/`
- `src/game/interaction/`

### Recommended future classes
- `GameApp`
- `EnemyActor`
- `CombatSystem`

### Existing coordinator classes
- `RuntimeScene` (`src/game/RuntimeScene.hpp`) — coordinates per-frame runtime actor
  visual submission; add enemies and NPCs here as they are implemented
- `PlayerActor` (`src/game/actors/PlayerActor.hpp`) — player runtime visual path

---

## 6. Important Current Technical Debt

### `src/app/Main.cpp`
Currently owns too much runtime logic.

Long-term goal:
- keep only setup, loop orchestration, and shutdown there

### `src/rendering/d3d11/D3D11Renderer.cpp`
Currently mixes multiple responsibilities.

Long-term goal:
- split terrain generation, terrain drawing, shader setup, and cleanup into clearer units

### Primitive world vs runtime visuals
Current rendering path needs cleaner separation between:
- authored/static world instances
- moving/runtime actor visuals

---

## 7. Current Target Direction

### Visual direction
- FF7-style readability
- stylized JRPG presentation
- simple but intentional shapes and materials

### Gameplay direction
- FF15 / FF7 Remake-inspired action combat
- responsive third-person movement
- runtime actor-based gameplay

This means gameplay architecture should be prioritized before high-end rendering features.

---

## 8. Architecture Rule of Thumb

When adding a new feature, ask:

1. Is this startup/orchestration code?
   - put it near `src/app/`

2. Is this draw/resource code?
   - put it near `src/rendering/`

3. Is this gameplay behavior?
   - put it near `src/game/`

4. Is this world/cell/streaming data?
   - put it near `src/world/`

5. Is this asset loading/parsing?
   - put it near `src/assets/`

6. Is this tool/debug/editor UI?
   - put it near `src/ui/`

If none of these are clear yet, stop and name the feature more precisely before writing code.
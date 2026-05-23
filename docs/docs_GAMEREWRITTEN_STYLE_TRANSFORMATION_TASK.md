# GameRewritten Style Transformation Task
## Goal
Transform `GameRewritten` into a full 3D explorable action RPG that preserves the handmade visual feeling of PS2-era Final Fantasy titles while remaining fully real-time and explorable like a modern 3D game.

The target is **not** photorealism.
The target is **not** modern AAA physically based rendering.
The target is a **stylized, authored, low-cost, emotionally composed 3D world** that feels like:

- the memory and mood of early Final Fantasy pre-rendered backgrounds
- the handmade readability of PS2-era JRPG art direction
- the movement and world exploration of modern real-time 3D games

This task defines the engine-side and runtime-side transformation needed inside `GameRewritten`.

---

## Core Visual Pillars

### 1. Handmade world, not procedural-looking world
Every region must feel authored, composed, and memorable.
The player should feel that each area was arranged intentionally, not randomly assembled from generic assets.

### 2. PS2-era stylization in a real-time 3D environment
The game should use:
- simple geometry
- readable silhouettes
- limited texture detail
- palette discipline
- low-cost shading
- selective fog and atmosphere
- strong color scripting
- clear separation of foreground, midground, and background

### 3. “Pre-rendered feel” without fixed cameras
The game remains fully 3D and explorable, but the presentation should borrow from pre-rendered era strengths:
- strong scene framing
- landmark composition
- background-like color design
- baked-feeling light relationships
- emotionally composed vistas
- curated camera behavior in important spaces

### 4. Readable modern gameplay in old-school presentation
Combat, traversal, interaction, and UI must remain legible even under stylized rendering.
The look must support gameplay clarity, not fight against it.

---

## Non-Goals

Do **not** turn the engine toward:
- photoreal materials
- full PBR dependency
- expensive real-time global illumination
- ultra-dense mesh detail
- texture realism as the primary source of beauty
- noisy shader complexity
- visually busy modern-AAA post-processing stacks

Do **not** lose:
- low-spec viability
- modularity
- readable architecture
- data-driven world/content flow
- beginner-extendable structure

---

## Transformation Outcome Required

`GameRewritten` must become capable of the following:

1. Render a full 3D explorable world with a consistent PS2/handmade Final Fantasy-inspired look.
2. Preserve strong gameplay readability during exploration and combat.
3. Support authored composition, mood, landmark visibility, and region identity.
4. Ingest stylized content from `Creation-Engine` through a stable asset contract.
5. Scale from a small vertical slice to a larger world without collapsing visual consistency.

---

# Required Engine Transformation Areas

## A. Rendering Style System
Create or complete a rendering style layer that enforces the project’s visual identity at runtime.

### Must support
- palette-aware color control
- diffuse light quantization / stepped lighting
- optional posterization
- low-cost outline support
- vertex-color-driven ambient occlusion
- fog-based depth shaping
- region-based color grading rules
- flat-shaded or lightly textured rendering modes
- strong value separation between gameplay-critical objects and background scenery

### Done when
- A scene can be made to look intentionally “PS2 handmade” through engine controls, not just raw asset luck.
- Characters, props, terrain, and architecture all sit in the same visual language.
- Lighting and shading do not drift into generic modern realism.

---

## B. Material and Shader Discipline
Materials must be intentionally limited so content remains visually cohesive.

### Required rules
- Prefer palette-driven, low-frequency, stylized material response.
- Avoid visually noisy materials.
- Support “cheap beauty” rather than simulation-heavy beauty.
- Use vertex colors and simple ramps where possible.
- Keep shader variants controlled and documented.

### Must support
- simple lit
- unlit stylized
- palette-tinted
- cel/step shaded
- world geometry with baked-feeling AO
- simple emissive accents for landmarks, save points, crystals, UI markers, etc.

### Done when
- Material usage across the project can be described as a small, reusable controlled set.
- New assets naturally fit the style without custom shader invention.

---

## C. Camera and Composition Layer
The engine must stop behaving like a purely generic free camera system and begin behaving like a directed visual experience.

### Must support
- exploration camera profiles
- combat camera profiles
- region-specific camera tuning
- landmark framing bias
- scripted composition zones for key locations
- controlled camera distance and angle choices that preserve silhouette readability
- optional light cinematic behavior in important spaces

### Design intent
The game remains fully explorable, but camera behavior should help produce “background painting” quality in motion.

### Done when
- Standing in a strong location naturally produces pleasing composition.
- Combat remains readable.
- Traversal does not feel visually flat or random.

---

## D. World Mood and Region Identity
Every area must have a recognizable mood and identity beyond geometry alone.

### Must support
- region atmosphere presets
- fog color and density profiles
- sky / ambient tone presets
- landmark visibility rules
- per-region palette emphasis
- region-based prop/material density guidance
- day/night or state variation only if it does not break style consistency

### Done when
- Two regions can be recognized instantly by color, mood, and shape language.
- The world feels like a sequence of authored places, not one continuous undifferentiated sandbox.

---

## E. Asset Ingestion and Style Validation
The runtime must accept art from `Creation-Engine` in a consistent, auditable way.

### Must support
- manifest-driven content import
- prefab/material/profile mapping
- style-profile validation
- fallback behavior for missing assets
- strict content categorization for terrain, props, architecture, foliage, decals, UI, actors, and enemies
- graceful rejection or warning for assets that violate runtime expectations

### Done when
- A full bundle import path is stable.
- Imported content arrives with the correct style assumptions and category behavior.
- The engine can validate whether content matches the intended visual contract.

---

## F. World Authoring Support
The game must support authored, memorable explorable spaces rather than only generic placement.

### Must support
- prefab placement workflows
- landmark-prefab support
- region kit usage
- traversal path shaping
- readable encounter spaces
- interior/exterior mood contrast
- controlled clutter density
- support for “vista” spaces, town hubs, dungeon corridors, and combat pockets

### Done when
- Designers can intentionally create a town, field, shrine, ruin, and dungeon with distinct silhouettes and flow.
- Areas feel designed for memory and emotion, not just function.

---

## G. Readability and Combat Presentation
Modern action gameplay readability must survive the old-school aesthetic.

### Must support
- telegraph clarity
- enemy silhouette separation
- VFX restraint
- readable hit feedback
- controlled screen shake
- combat camera protection rules
- UI contrast under stylized rendering
- target lock/readability priorities

### Done when
- Combat remains understandable at a glance.
- Stylization improves readability instead of muddying it.
- FX never overwhelm enemy/player state readability.

---

## H. Performance and Scope Guardrails
The visual target must remain achievable on the project’s intended hardware and architectural philosophy.

### Must preserve
- low-cost forward-friendly rendering
- controlled draw call growth
- modest memory usage
- limited shader complexity
- scalable world rendering rules
- no dependence on expensive high-end rendering features

### Done when
- The style still works under constrained hardware assumptions.
- Performance cost grows predictably as the world expands.

---

# Required Deliverable Milestones

## Milestone 1 — Style Lock
Implement the minimal runtime style controls required to prove the visual target.

### Must include
- one palette/style profile pipeline
- one stepped-light or stylized-light shader path
- one fog/mood profile system
- one outline or edge readability solution
- one vertex AO compatible path
- one style test scene

### Result
A small test scene already reads as “handmade PS2-era FF-inspired 3D”.

---

## Milestone 2 — Vertical Slice Presentation
Apply the style consistently to one playable area.

### Must include
- one exploration region
- one landmark vista
- one combat pocket
- one interior or dungeon-like space
- one stable camera behavior set
- one UI/readability pass
- one imported asset bundle path from `Creation-Engine`

### Result
A player can walk, look around, and fight in a space that already feels close to the final intended aesthetic.

---

## Milestone 3 — Region Identity Framework
Expand from one scene to a reusable authored-world framework.

### Must include
- region presets
- asset category rules
- landmark placement discipline
- visual composition rules
- mood transition handling
- stable prefab ingestion rules

### Result
Multiple areas can exist without losing style consistency.

---

## Milestone 4 — Full Runtime Art Contract
Finalize the runtime expectations that all content must follow.

### Must include
- documented shader/material categories
- documented prefab/material import expectations
- validation rules for style compliance
- fallback handling for incomplete content
- test checklist for visual drift

### Result
The project can grow without losing the handmade visual identity.

---

# Implementation Priorities

## Priority 1
Lock the visual style systems before adding more content.

Focus first on:
- shader language
- palette discipline
- fog and atmosphere
- AO and shading tone
- camera composition support

## Priority 2
Lock the engine-to-content contract before scaling production.

Focus second on:
- asset manifests
- import expectations
- category mapping
- style validation
- prefab workflows

## Priority 3
Build one excellent vertical slice before building a huge world.

Do not scale content breadth until:
- one field area works
- one landmark works
- one combat area works
- one interior works
- one UI/readability pass works

## Priority 4
Scale region identity, not generic map size.

When expanding the world, prioritize:
- memorable places
- mood shifts
- landmark silhouettes
- authored traversal routes
- scene composition

---

# Acceptance Standard

This task is complete only when `GameRewritten` can present a playable 3D area that:

- feels intentionally handmade
- looks visually tied to PS2-era Final Fantasy memory
- avoids photoreal rendering drift
- preserves readable action gameplay
- supports fully explorable 3D navigation
- demonstrates a stable art/content contract with `Creation-Engine`

If the result is only “a 3D game with retro shaders,” the task is **not** complete.
If the result feels like “a composed explorable world with old-school Final Fantasy soul in real-time 3D,” the task is on target.

---

# Final Instruction
All future engine, rendering, world, camera, UI, and import work in `GameRewritten` should be judged against this question:

**Does this change make the game feel more like a handmade, emotionally composed, PS2-era Final Fantasy-inspired 3D world without sacrificing playability?**

If not, the change should be revised, reduced, or rejected.
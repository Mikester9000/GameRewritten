# System Ownership Map

See also: [Architecture.md](./Architecture.md), [MAIN_CPP_PROTECTION.md](./MAIN_CPP_PROTECTION.md), [DECISION_DEFAULTS.md](./DECISION_DEFAULTS.md).

## `src/app`
- **Belongs:** startup/shutdown wiring, frame orchestration, app-level helpers.
- **Does not belong:** gameplay rules, enemy logic, long-term feature logic.
- **Common mistakes:** adding feature logic directly into `Main.cpp`.

## `src/game`
- **Belongs:** gameplay systems, runtime state, interaction and combat logic.
- **Does not belong:** D3D device setup, editor-only UI drawing internals.
- **Common mistakes:** putting renderer resource ownership here.

## `src/game/actors`
- **Belongs:** player/enemy/NPC actor state + per-actor behavior.
- **Does not belong:** global orchestration or world streaming policy.
- **Common mistakes:** actor-specific hacks in `Main.cpp` instead of actor/runtime scene.

## `src/game/combat`
- **Belongs:** hit resolution, target selection, combat timers/rules.
- **Does not belong:** UI rendering code or world loading.
- **Common mistakes:** coupling combat rules to ImGui state directly.

## `src/game/physics`
- **Belongs:** collision primitives/tests and gameplay-facing collision world logic.
- **Does not belong:** renderer math utilities unrelated to gameplay collision.
- **Common mistakes:** duplicating AABB checks elsewhere.

## `src/rendering`
- **Belongs:** draw paths, shaders, GPU resources, render-time buffers.
- **Does not belong:** gameplay decisions, quest rules, actor AI.
- **Common mistakes:** embedding gameplay state transitions in renderer code.

## `src/ui`
- **Belongs:** HUD, menus, overlays, world editor tools.
- **Does not belong:** combat outcome authority, world simulation rules.
- **Common mistakes:** treating UI state as gameplay truth.

## `src/world`
- **Belongs:** cell layout, biome/cell data, world structure helpers.
- **Does not belong:** actor combat behavior.
- **Common mistakes:** putting content-authoring UI logic in world module.

## `src/assets`
- **Belongs:** registry lookups, content parsing/loading helpers.
- **Does not belong:** gameplay tuning constants.
- **Common mistakes:** hardcoding gameplay defaults in loader code.

## `Content`
- **Belongs:** data files (prefabs, world cells, audio/textures).
- **Does not belong:** code-level logic.
- **Common mistakes:** relying on content data to replace missing ownership in code.

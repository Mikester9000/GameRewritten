# Content Pipeline Guide

See also: [ASSET_REGISTRY.md](./ASSET_REGISTRY.md), [PREFABS_GUIDE.md](./PREFABS_GUIDE.md), [WORLD_EDITOR.md](./WORLD_EDITOR.md).

## Content flow
1. Create/adjust prefab content.
2. Register IDs in `Content/AssetRegistry.json`.
3. Place/use in world cells.
4. Reload (`F5`) and verify in runtime/editor.

## Prefabs
- Store reusable object definitions in `Content/Prefabs/`.
- Keep naming clear and consistent with purpose.

## Registry
- Use scoped IDs (example style: `prefabs.*`, `textures.*`).
- Avoid ad-hoc naming drift.

## World cells
- Place instances in cell JSON via editor workflow.
- Keep region identity and traversal readability in mind.

## Asset references
- Prefer stable IDs over hardcoded path strings in gameplay logic.

## Naming discipline
- Use descriptive names.
- Avoid temporary/ambiguous IDs as long-term content keys.

## Reload workflow
- Use runtime reload path for fast iteration.
- Always verify editor/runtime both reflect changes.

## Beginner-friendly pipeline rule
- Keep authoring steps short and repeatable.
- Prefer simple data shapes over deeply nested formats.

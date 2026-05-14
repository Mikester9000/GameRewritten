# Performance Guardrails (GT 610 First)

See also: [GRAPHICS_VISION.md](./GRAPHICS_VISION.md), [QUALITY_BAR.md](./QUALITY_BAR.md).

## Low-spec philosophy
- Prefer stable frame-time over flashy effects.
- Prefer readability + consistency over expensive visuals.
- Add one cheap improvement at a time.

## GT 610 guardrails (default Low target)
- GPU memory footprint: keep within low budget discipline.
- Draw calls: keep scene complexity controlled.
- Dynamic lights: minimal.
- Full-screen passes: avoid by default.
- Texture sizes: small/moderate; avoid oversized defaults.

## Draw-call caution
- Batch where possible.
- Reuse existing render paths before adding new passes.
- Avoid “one draw per tiny effect” patterns.

## Shader/material simplicity
- Keep branch/loop complexity low.
- Limit texture fetches.
- Prefer parameterized materials over many unique shader variants.

## Update-frequency caution
- Do not update heavy systems every frame if event-based updates are enough.
- Use timers/throttles for debug-heavy or editor-only checks.

## Debug feature toggles
- Any expensive debug draw must be opt-in and easy to disable.
- Debug overlays should not permanently affect runtime costs.

## Safe defaults for new features
- Start disabled or minimal quality.
- Ship with “Low-safe” fallback behavior.
- Expose clear on/off or quality flags for expensive paths.

## Pre-merge performance checklist
- [ ] No obvious draw-call explosion.
- [ ] No expensive full-screen pass added without guard.
- [ ] No heavy shader path as default.
- [ ] No per-frame allocations in hot path.
- [ ] Feature is still readable in Low preset.
- [ ] Quick in-game smoke test run.

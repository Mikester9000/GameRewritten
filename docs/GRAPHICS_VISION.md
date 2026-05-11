# Graphics Vision Guide
**Date:** 2026-05-11

---

## Vision Statement

Render a world that feels like **FF7's original stylized 3D aesthetic** — bold silhouettes, flat color surfaces, strong contrast — while staying completely within the limits of a **GeForce GT 610** running **Direct3D 11**.

The goal is not photorealism. It is **readable, charming, low-cost stylization**.

---

## Core Visual Direction

| Goal | What it means in practice |
|---|---|
| FF7-inspired style | Simple geometry, palette-driven colors, strong silhouettes |
| Action-RPG readability | Enemies, player, and hazards are instantly distinguishable |
| GT610 constraint | ≤ 100 draw calls per frame on Low (hard cap), ≤ 512 MB GPU memory |
| D3D11 forward renderer | Single forward pass, no deferred pipeline, no heavy post |

---

## Geometry and Mesh Goals

- **Characters and actors**: built from colored box primitives (blockout style), matching FF7's pre-rendered figurine look in real-time 3D.
- **Terrain**: flat-shaded or gently textured ground planes. No high-poly displacement.
- **Props and prefabs**: low-poly box/primitive assemblies. Aim for 50–200 triangles per prop on Low.
- **Environment**: simple structural geometry with strong color separation between ground, sky, and objects.

No high-poly meshes until mesh streaming and LOD are implemented (post-Milestone 12).

---

## Lighting

### Approach
Use a **single directional sun light** (diffuse + ambient) bound to the `LightCBuffer` at PS b1.

### Rules
- One directional light per scene for now — no dynamic point lights on Low.
- Ambient fills shadows softly; do not go full black on unlit surfaces.
- Diffuse color tints should read like warm sunlight or cool overcast sky.
- No real-time shadows until a cheap shadow technique (shadow plane projection or depth bias) is implemented.

### Quality budget
| Preset | Dynamic lights | Shadows |
|---|---|---|
| Low | 1 directional only | None |
| Medium | 1 directional + up to 2 point | Projection plane |
| High | 1 directional + up to 4 point | Simple depth map |

---

## Shaders

### Current shaders (do not replace)
| Shader pair | Purpose |
|---|---|
| `sky_vs.hlsl` + `sky_ps.hlsl` | Gradient sky dome |
| `ground_vs.hlsl` + `ground_ps.hlsl` | Terrain / ground plane |
| `tree_vs.hlsl` + `tree_ps.hlsl` | Foliage instancing |
| `prim_vs.hlsl` + `prim_ps.hlsl` | Box primitive rendering (actors, props) |
| `basic3d_vs.hlsl` + `basic3d_ps.hlsl` | Generic 3D geometry |

### Shader rules
- Keep shaders simple: minimal branching, no large loops, few texture fetches per pixel.
- Prefer parameterized materials over many unique shader variants.
- All shaders must compile cleanly for D3D11 / MSVC (no GLSL, no SM 6.x).
- Constant buffer slots: b0 = per-object, b1 = per-scene/light, b2+ = per-pass.

---

## Post-Processing

- **Low preset**: zero post-process passes. No bloom, no SSAO, no motion blur.
- **Medium preset**: at most one cheap fullscreen pass (e.g. subtle color grading LUT).
- **High preset**: at most two passes (color grade + optional cheap bloom approximation).

The GT610 cannot sustain multiple fullscreen passes at 60 fps. Defer post-processing features.

---

## Color and Palette Direction

- **Sky**: gradient from deep blue/indigo at horizon to lighter blue above.
- **Terrain**: warm earth tones (brown, khaki, muted green). Avoid sharp grass green.
- **Characters / actors**: solid primary colors for readability. Each actor type has a distinct color family.
- **Effects / UI**: high-contrast accent colors (cyan, yellow, red) for combat feedback.

Avoid oversaturated neon. Prefer a muted palette with strong accent pops.

---

## Silhouette and Readability Rules

- Player, enemies, and NPCs must be readable at camera distance of 10+ world units.
- Use color contrast (not shape complexity) as the primary readability tool.
- Avoid dark-on-dark or same-hue actor pairs in the same scene.
- Combat hitbox areas should have a clear visual indicator (particle flash, color change).

---

## GT610 Hardware Budget (Low Preset)

| Resource | Budget |
|---|---|
| GPU memory (total) | ≤ 512 MB |
| Resident textures | ≤ 128 MB |
| Draw calls per frame | ≤ 100 |
| Fullscreen post passes | 0 |
| Dynamic lights | 1 directional |
| Target frame rate | 60 FPS (16 ms) |
| Max texture dimension | 512–1024 px (most assets); 2048 px max |

Validate against this budget after each rendering milestone.

---

## Implementation Notes for Agents

- D3D11 device, swap chain, and draw calls live in `src/rendering/d3d11/D3D11Renderer.cpp/hpp`.
- LightCBuffer is owned by `D3D11Renderer`; exposed via `GetLightConstantBuffer()`.
- New GPU resources belong in the module that owns them; declare members in `.hpp` before using in `.cpp`.
- `Initialize(ID3D11Device*)` and `Shutdown()` are required for any module that owns GPU resources.
- Never add a post-process pass on Low without an explicit quality-preset guard.

---

## Long-Term Visual Goal

The final game should look like:

- **Characters**: FF7-style stylized blockout figures with bold colors and clear silhouettes.
- **World**: open terrain with strong color-coded biomes, simple vegetation instancing.
- **Lighting**: warm directional sun with soft ambient fill — no flat or washed-out scenes.
- **Effects**: minimal but readable — bright flashes for combat hits, clear indicators for state changes.

Achievable on a GT610 at 60 fps with disciplined draw-call and texture budgets.

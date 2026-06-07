# CON9 — Cel Shader Task Definitions (Phase 2 Addendum)

These six tasks define the missing cel/toon shading implementation work with concrete HLSL-level requirements.

---

## Task 030A — Cel shading band quantization
- **Files:** `Shaders/basic3d_ps.hlsl`, `src/rendering/d3d11/D3D11Renderer.cpp`
- **HLSL implementation details:**
  - Add a cel-shading constant block (`CelBandCount`, `CelDiffuseMin`, `CelDiffuseMax`).
  - Compute `NdotL = saturate(dot(normalWS, lightDirWS))`.
  - Remap and quantize: `banded = floor(NdotL * CelBandCount) / max(CelBandCount - 1, 1)`.
  - Clamp output between `CelDiffuseMin` and `CelDiffuseMax` before albedo multiply.
- **Acceptance:** actor lighting uses discrete bands (not smooth Lambert) with runtime-adjustable band count.

## Task 030B — Shadow tint and rim gate
- **Files:** `Shaders/basic3d_ps.hlsl`
- **HLSL implementation details:**
  - Add `CelShadowTint` (`float3`) and `CelShadowThreshold` (`float`) parameters.
  - If `NdotL < CelShadowThreshold`, blend base color toward `CelShadowTint`.
  - Add rim gate using `rim = 1 - saturate(dot(normalWS, viewDirWS))`, then apply only when lit value is below the top diffuse band.
- **Acceptance:** shadowed faces get art-directed tint and silhouettes gain readable rim without full-screen passes.

## Task 030C — Stepped specular highlights
- **Files:** `Shaders/basic3d_ps.hlsl`
- **HLSL implementation details:**
  - Replace smooth Blinn-Phong output with thresholded spec response.
  - Compute half-vector term once, then apply `step(CelSpecThreshold, specPower)` for primary highlight.
  - Add optional second tier using `CelSpecThreshold2` with reduced intensity for stylized dual-band shine.
- **Acceptance:** highlights appear as hard stepped accents matching toon material intent.

## Task 030D — Material-level cel parameter plumbing
- **Files:** `src/rendering/d3d11/D3D11Renderer.cpp`, `src/assets/AssetLoader.cpp`, `src/assets/AssetLoader.hpp`
- **Implementation details:**
  - Extend material/runtime data to carry cel parameters: diffuse band count, shadow tint, rim amount, spec thresholds.
  - Populate per-material defaults if fields are missing.
  - Upload per-draw cel constants to the pixel-shader constant buffer without changing legacy material behavior.
- **Acceptance:** materials can tune cel response without shader edits and legacy content still renders.

## Task 030E — Character outline pass (inverted hull)
- **Files:** `Shaders/basic3d_vs.hlsl`, `Shaders/basic3d_ps.hlsl`, `src/rendering/d3d11/D3D11Renderer.cpp`
- **HLSL/render implementation details:**
  - Add outline mode vertex expansion in VS: offset along normal by `OutlineWidthWS`.
  - Render backfaces only for outline pass (`CullMode = FRONT`) with depth test enabled.
  - Use solid outline color in PS and skip lighting math in outline mode.
  - Run outline draw immediately before regular shaded draw for player/enemy meshes.
- **Acceptance:** stable silhouette outlines appear around core actors with low incremental GPU cost.

## Task 030F — Debug controls and safe fallback
- **Files:** `src/ui/ImGuiLayer.cpp`, `src/ui/ImGuiLayer.hpp`, `src/rendering/d3d11/D3D11Renderer.cpp`
- **Implementation details:**
  - Add runtime toggles for cel shading enabled, outline enabled, and band count.
  - Keep a fallback branch that uses existing non-cel shading constants and path.
  - Ensure toggle changes apply live without shader recompilation.
- **Acceptance:** QA can compare cel vs legacy shading instantly and revert at runtime for regression checks.

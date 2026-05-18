# Qwen 2.5 7B — **Code-Writing Prompts for Missing Work**

This file is a **work-order list**. Each item is a **small, code-writing task** that Qwen can complete with **minimal reasoning**. You will **paste the specific files** to Qwen, then **copy Qwen’s output back** into the repo manually.

**Rules for every prompt**
- Qwen has **no repo access**. You must paste required files or snippets.
- Keep prompts **small** (you control the size).
- Ask Qwen to output **only the final code**, **no explanations**.
- If a task affects project files, ask Qwen to list **exact project edits** (e.g., .vcxproj add file entries).

**Output format rule (use in every prompt)**
> Output only the final code or exact patch steps. No explanations.

---

## How to use (fast)
1. Pick **one task** below.
2. Copy the **Prompt** for that task.
3. Paste the **exact file(s)** Qwen needs.
4. Apply the returned code.

---

## Phase A — Build + Entry Flow (Small, deterministic)

### A1 — Main loop structure cleanup
**Prompt**
> I will paste `src/app/Main.cpp`. Update it to enforce: setup → guard clauses → main logic → output sections. Add section headers for any function over 20 lines. Keep behavior identical. Output only the updated file.

### A2 — Add missing module init/shutdown stubs
**Prompt**
> I will paste `src/app/Main.cpp` and any module headers. Add safe `Initialize()` / `Shutdown()` calls for modules that own GPU or external resources. Do not change behavior. Output only the updated `Main.cpp`.

### A3 — Frame timing polish
**Prompt**
> I will paste `src/app/FrameTiming.hpp` and relevant usage. Add a minimal fixed-step helper (accumulator + max steps). No behavior changes unless fixed-step is disabled. Output only updated files.

---

## Phase B — Rendering Core (D3D11, GT610-friendly)

### B1 — Add a minimal per-scene constant buffer
**Prompt**
> I will paste `src/rendering/d3d11/D3D11Renderer.hpp` and `.cpp`. Add a per-scene constant buffer (view/proj, light dir, light color). Bind at slot b1 in VS/PS. Output updated files only.

### B2 — Add a basic directional light
**Prompt**
> I will paste `D3D11Renderer.*` and the main shader pair. Add a simple directional light term in the pixel shader. Keep it low-cost. Output only updated shader and C++ updates.

### B3 — Add a depth-only shadow map pass
**Prompt**
> I will paste renderer files and relevant shader list. Add a minimal depth-only shadow map pass with one light. Use a single shadow map. Output only new/updated files.

### B4 — Add a UI render pass (ImGui already exists)
**Prompt**
> I will paste `Main.cpp` and `ImGuiLayer.*`. Ensure UI rendering is a clearly separated pass after 3D rendering. Keep behavior identical. Output updated files only.

### B5 — Add a “Low” quality preset toggle
**Prompt**
> I will paste current quality/settings config. Add a Low preset that disables extra passes and clamps light counts. Output only updated config and any wiring changes.

---

## Phase C — Shader Set (Minimal commercial baseline)

### C1 — Standard lit shader pair
**Prompt**
> I will paste the shader folder list and an existing shader template. Create a simple lit shader pair `<name>_vs.hlsl` / `<name>_ps.hlsl` using a single directional light and albedo. Output only new shader code.

### C2 — Unlit/UI shader pair
**Prompt**
> I will paste a shader template. Create an unlit shader pair for UI or debug. Output only new shader code.

### C3 — Debug normal-visualization shader
**Prompt**
> I will paste a shader template. Create a debug shader to visualize normals. Output only new shader code.

---

## Phase D — Asset System (Small, safe improvements)

### D1 — Asset load error handling
**Prompt**
> I will paste `src/assets/AssetRegistry.*` and `AssetLoader.*`. Add clear error logs on missing or invalid assets and return fallback IDs. Output updated files only.

### D2 — Simple asset cache
**Prompt**
> I will paste asset loader code. Add a tiny in-memory cache keyed by path or ID. Must avoid duplicates. Output updated files only.

### D3 — Asset validation helper
**Prompt**
> I will paste asset loader code. Add a small `ValidateAsset()` helper used at load time (format/size checks). Output updated files only.

---

## Phase E — Gameplay + Scene

### E1 — RuntimeScene update order clarity
**Prompt**
> I will paste `src/game/RuntimeScene.hpp` and related `.cpp`. Add clear section headers and reorder to `PreUpdate → Update → PostUpdate`. No behavior changes. Output updated files only.

### E2 — Actor base component stub
**Prompt**
> I will paste `src/game/actors/ActorCommon.hpp` and one actor file. Add a tiny component interface (Start/Update) without breaking existing behavior. Output updated files only.

### E3 — Prefab loading safety
**Prompt**
> I will paste `PrefabDef.hpp` and `PrefabLibrary.*`. Add validation with log errors and safe fallback on bad prefab data. Output updated files only.

---

## Phase F — UI + Tools (ImGui panels)

### F1 — Performance overlay panel
**Prompt**
> I will paste `src/ui/ImGuiLayer.*` and any UI panel files. Add a minimal Performance panel (FPS, frame time, draw calls if available). Output updated files only.

### F2 — Asset inspector panel
**Prompt**
> I will paste UI panel code and asset registry. Add a small Asset Inspector panel that lists loaded assets and IDs. Output updated files only.

### F3 — World editor panel cleanup
**Prompt**
> I will paste `src/ui/WorldEditor.*`. Add section headers and split any large function into small helpers without behavior changes. Output updated files only.

---

## Phase G — Audio (Wrapper-based)

### G1 — Audio mixer groups
**Prompt**
> I will paste `ThirdParty/tp_audio.hpp` and audio usage. Add minimal mixer groups: Music, SFX, UI, Ambient. Provide simple volume controls. Output updated files only.

### G2 — Audio streaming safety
**Prompt**
> I will paste audio wrapper and any streaming code. Add guard checks and clear error logs on failure. Output updated files only.

---

## Phase H — Physics + Navigation

### H1 — Simple raycast helpers
**Prompt**
> I will paste `ThirdParty/tp_physics.hpp` usage. Add a minimal raycast helper function (origin, dir, maxDist). Output updated files only.

### H2 — Trigger volume support
**Prompt**
> I will paste physics wrapper usage and any actor collision code. Add a minimal trigger system that reports enter/exit. Output updated files only.

### H3 — Navmesh bake workflow stub
**Prompt**
> I will paste navigation wrapper usage. Add a minimal function that builds/bakes navmesh with placeholder config. Output updated files only.

---

## Phase I — Performance + Stability

### I1 — Fixed GPU resource ownership pattern
**Prompt**
> I will paste a renderer module that owns GPU resources. Add `Initialize(ID3D11Device*)` and `Shutdown()` with clear ownership and safe releases. Output updated files only.

### I2 — Basic CPU profiling zones
**Prompt**
> I will paste `Main.cpp` or hot paths. Add `GR_ZONE_SCOPED_N` zones for major frame steps and `GR_FRAME_MARK`. Output updated files only.

### I3 — Low-spec budgets clamp
**Prompt**
> I will paste quality config and renderer. Add clamps for draw calls, lights, and texture sizes when Low preset is active. Output updated files only.

---

## Phase J — Packaging + Release

### J1 — Version file
**Prompt**
> I will paste any build/version files. Create a small `Version.hpp` with MAJOR/MINOR/PATCH and a string. Wire into app title. Output updated files only.

### J2 — Build output layout
**Prompt**
> I will paste build scripts/tools. Add a minimal output folder layout for Release builds (bin, Content, Shaders, logs). Output updated files only.

---

## Phase K — QA + Logging

### K1 — Log file output
**Prompt**
> I will paste `src/logger/Logger.hpp` and implementation. Add a minimal file sink for Release builds. Output updated files only.

### K2 — Smoke test runner
**Prompt**
> I will paste `src/app/ThirdPartyBootstrap.hpp` and any tests. Add a simple smoke-test runner called from startup. Output updated files only.

---

## Phase L — Legal + Commercial readiness

### L1 — Third-party license aggregation file
**Prompt**
> I will paste the list of third-party folders and any license files. Generate a `THIRD_PARTY_NOTICES.md` that aggregates license texts and attributions. Output only that file.

---

## Universal “Write Code For This File” Prompt
Use this when you already know exactly what change you want.

**Prompt**
> I will paste a single file and a small change request. Apply the change. Output only the full updated file. No explanations.

# Qwen 2.5 7B — **Modular “Lego Block” Code Tasks**

This file is a **complete set of small, standalone coding blocks** to reach **commercial‑release grade**. Each block is meant to be **written independently** by Qwen and then **inserted manually** into the repo. Blocks are **modular** so you can add them one‑by‑one.

**Rules for every prompt**
- Qwen has **no repo access**. You must paste required files/snippets.
- Keep prompts **small** (you control size).
- Ask Qwen to output **only the final code** (no explanations).
- If a task touches project files, ask Qwen to list **exact project edits** (e.g., `.vcxproj` additions).

**Output format rule (use in every prompt)**
> Output only the final code or exact patch steps. No explanations.

---

## How to use (fast)
1. Pick **one block** below.
2. Copy the **Prompt** for that block.
3. Paste the **exact file(s)** Qwen needs.
4. Apply the returned code and move to the next block.

---

# BLOCKS — Core Engine (Must‑Have)

## B‑CORE‑01 — Main loop narrative sections
**Prompt**
> I will paste `src/app/Main.cpp`. Add section headers and enforce the order: setup → guard clauses → main logic → output. Keep behavior identical. Output only the updated file.

## B‑CORE‑02 — Fixed‑step helper
**Prompt**
> I will paste `src/app/FrameTiming.hpp` and its usage. Add a minimal fixed‑step accumulator helper (with max steps). Keep existing behavior unless fixed‑step is enabled. Output updated files only.

## B‑CORE‑03 — Deterministic frame order helpers
**Prompt**
> I will paste `src/app/Main.cpp`. Extract small helper functions for `BeginFrame`, `UpdateFrame`, `RenderFrame`, `EndFrame` without changing behavior. Output only updated file.

## B‑CORE‑04 — Safe init/shutdown wiring
**Prompt**
> I will paste `Main.cpp` and all module headers that own resources. Add explicit `Initialize()` and `Shutdown()` calls in correct order. Output only updated `Main.cpp`.

## B‑CORE‑05 — Crash‑safe startup log
**Prompt**
> I will paste `src/logger/Logger.hpp` and implementation. Add a startup log section that prints version, build type, GPU/driver when available. Output updated files only.

---

# BLOCKS — Rendering (D3D11, Low‑Spec Ready)

## B‑RENDER‑01 — Per‑scene constant buffer
**Prompt**
> I will paste `D3D11Renderer.hpp/.cpp`. Add a per‑scene cbuffer (view/proj, lightDir, lightColor). Bind to slot b1 VS/PS. Output updated files only.

## B‑RENDER‑02 — Standard lit shader pair
**Prompt**
> I will paste a shader template. Create a simple lit shader pair `standard_lit_vs.hlsl` / `standard_lit_ps.hlsl` using a single directional light. Output only shader files.

## B‑RENDER‑03 — Unlit shader pair
**Prompt**
> I will paste a shader template. Create `unlit_vs.hlsl` / `unlit_ps.hlsl` for UI/debug. Output only shader files.

## B‑RENDER‑04 — Debug normals shader
**Prompt**
> I will paste a shader template. Create `debug_normals_vs.hlsl` / `debug_normals_ps.hlsl` to visualize normals. Output only shader files.

## B‑RENDER‑05 — Basic lighting pass wiring
**Prompt**
> I will paste renderer files and shader list. Wire the standard lit shader into the render path with light uniforms. Output updated files only.

## B‑RENDER‑06 — Shadow map pass (single light)
**Prompt**
> I will paste renderer files and shader list. Add a minimal depth‑only shadow map pass using one light and a single shadow map. Output updated/new files only.

## B‑RENDER‑07 — Low‑spec quality preset clamp
**Prompt**
> I will paste quality config and renderer. Add a Low preset that clamps light count, disables extra passes, and reduces shadow resolution. Output updated files only.

## B‑RENDER‑08 — Simple post‑process pass
**Prompt**
> I will paste renderer files. Add one optional post‑process pass (gamma/tonemap). Must be disable‑able. Output updated files only.

---

# BLOCKS — Assets (Commercial‑grade reliability)

## B‑ASSET‑01 — Asset load error logging
**Prompt**
> I will paste `AssetRegistry.*` and `AssetLoader.*`. Add clear error logs and fallback IDs for missing assets. Output updated files only.

## B‑ASSET‑02 — In‑memory asset cache
**Prompt**
> I will paste asset loader code. Add a tiny cache keyed by ID/path to avoid re‑loading. Output updated files only.

## B‑ASSET‑03 — Asset validation helper
**Prompt**
> I will paste asset loader code. Add `ValidateAsset()` (format/size checks). Call it on load. Output updated files only.

## B‑ASSET‑04 — Asset dependency tracking
**Prompt**
> I will paste asset loader/registry. Add a minimal dependency list per asset (texture → source). Output updated files only.

---

# BLOCKS — Gameplay + Scene

## B‑GAME‑01 — RuntimeScene update sections
**Prompt**
> I will paste `RuntimeScene.*`. Add section headers and group into `PreUpdate → Update → PostUpdate`. No behavior change. Output updated files only.

## B‑GAME‑02 — Minimal component interface
**Prompt**
> I will paste `ActorCommon.hpp` and one actor. Add a tiny component interface (Start/Update) without breaking existing behavior. Output updated files only.

## B‑GAME‑03 — Prefab validation
**Prompt**
> I will paste `PrefabDef.hpp` and `PrefabLibrary.*`. Add validation + logs with safe fallback. Output updated files only.

## B‑GAME‑04 — Simple save/load stub
**Prompt**
> I will paste any save/load files or prefab structures. Add a minimal versioned save/load stub (no full serializer). Output updated files only.

---

# BLOCKS — UI + Tools (ImGui)

## B‑UI‑01 — Performance overlay panel
**Prompt**
> I will paste `ImGuiLayer.*` and UI panels. Add a Performance panel (FPS, frame time, draw calls if available). Output updated files only.

## B‑UI‑02 — Asset inspector panel
**Prompt**
> I will paste UI panel code and asset registry. Add an Asset Inspector panel listing loaded assets. Output updated files only.

## B‑UI‑03 — Debug console panel
**Prompt**
> I will paste UI panel code. Add a small debug console with a history buffer. Output updated files only.

---

# BLOCKS — Audio (Wrapper‑based)

## B‑AUDIO‑01 — Mixer groups
**Prompt**
> I will paste `tp_audio.hpp` and usage. Add Music/SFX/UI/Ambient mixer groups with volume controls. Output updated files only.

## B‑AUDIO‑02 — Streaming guard checks
**Prompt**
> I will paste audio streaming code. Add guard checks and logs for load/play failures. Output updated files only.

---

# BLOCKS — Physics + Navigation

## B‑PHYS‑01 — Raycast helper
**Prompt**
> I will paste `tp_physics.hpp` usage. Add a minimal raycast helper (origin, dir, maxDist). Output updated files only.

## B‑PHYS‑02 — Trigger volume system
**Prompt**
> I will paste physics wrapper usage and actor collision. Add trigger enter/exit events. Output updated files only.

## B‑NAV‑01 — Navmesh bake stub
**Prompt**
> I will paste navigation wrapper usage. Add a minimal navmesh bake function with placeholder config. Output updated files only.

---

# BLOCKS — Performance + Stability

## B‑PERF‑01 — GPU resource ownership pattern
**Prompt**
> I will paste a renderer module that owns GPU resources. Add `Initialize(ID3D11Device*)` and `Shutdown()` with safe releases. Output updated files only.

## B‑PERF‑02 — CPU profiling zones
**Prompt**
> I will paste `Main.cpp` or hot paths. Add `GR_ZONE_SCOPED_N` zones and `GR_FRAME_MARK`. Output updated files only.

## B‑PERF‑03 — Low‑spec budgets clamp
**Prompt**
> I will paste quality config and renderer. Clamp draw calls, lights, texture sizes when Low preset is active. Output updated files only.

## B‑PERF‑04 — Safe fallback assets
**Prompt**
> I will paste asset loader and content paths. Add fallback asset IDs for missing textures/meshes. Output updated files only.

---

# BLOCKS — Release Engineering

## B‑REL‑01 — Version header
**Prompt**
> I will paste any version/build files. Create `Version.hpp` with MAJOR/MINOR/PATCH and a string. Wire into app title. Output updated files only.

## B‑REL‑02 — Build output layout
**Prompt**
> I will paste build scripts/tools. Add a minimal Release output layout (bin, Content, Shaders, logs). Output updated files only.

## B‑REL‑03 — Release config sanity
**Prompt**
> I will paste build configs. Ensure Release disables asserts, enables optimizations, and keeps logging. Output updated files only.

---

# BLOCKS — QA + Logging

## B‑QA‑01 — Log file output
**Prompt**
> I will paste `Logger.hpp` and implementation. Add a Release‑build file sink for logs. Output updated files only.

## B‑QA‑02 — Smoke test runner
**Prompt**
> I will paste `ThirdPartyBootstrap.hpp` and any tests. Add a smoke‑test runner on startup. Output updated files only.

---

# BLOCKS — Legal + Commercial Readiness

## B‑LEGAL‑01 — Third‑party notices file
**Prompt**
> I will paste the list of third‑party folders and any license files. Generate `THIRD_PARTY_NOTICES.md` with attributions. Output only that file.

---

# Universal “Write Code For This File” Prompt
**Prompt**
> I will paste a single file and a small change request. Apply the change. Output only the full updated file. No explanations.

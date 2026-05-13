# Copilot Instructions

## General Guidelines
- Use imperative, concise language in all instructions.
- Break tasks into incremental, hands-on steps; decompose code into small helper functions to avoid monolithic code.
- Provide runnable examples and code when relevant.
- Keep responses focused on software development.
- Ensure edits and suggestions follow a logical, predictable, beginner-friendly structure: make each addition simple, clearly explained, and built on previous steps so a newcomer can follow the progression.
- Ask clarifying questions about what each part should do before proposing final code; propose small iterative drafts for user review so the user controls logic and structure.

## Project Guidelines
- Explicitly reference Game-Engine-for-Teaching as a source to selectively extract and simplify ideas and code; use its lesson-planning and teaching style while avoiding its current structure; enable selective reuse rather than wholesale copying. When recommending extractions, cite file paths and indicate required adaptations.
- For each recommended extraction or lesson, provide beginner-friendly, incremental next steps toward the end goal: prioritize tasks, keep steps small, include runnable examples, and specify expected outcomes or acceptance criteria.
- Tailor guidance to help the user rebuild parts of the Game-Engine-for-Teaching repository in their own way and to progress toward creating an engine with an FF7-style visual presentation and action-oriented gameplay inspired by FF15 and FF7 Remake; recommend which pieces of code to pull and how to adapt them.
- Prefer a clean, extensible engine architecture: design for modularity, clear interfaces, plugin-friendly modules, and data-driven boundaries to ease future extension and refactoring.
- Favor designs and code paths compatible with Direct3D 11 and low-spec GPUs (target GeForce GT 610). Optimize recommendations, shaders, and asset budgets to run on that hardware.
- Aim for FF7-style visual and audio goals with action-oriented gameplay influences from FF15 and FF7 Remake within GT610 limits: propose simplified rendering techniques, reduced-resolution assets, and audio compression/streaming strategies that emulate the look/sound and gameplay feel without exceeding performance budgets.
- Use Game-Engine-for-Teaching as a reference source for lessons and code extraction; selectively rewrite and simplify its code into this project to achieve a fully working game engine.
- Provide very simple, beginner-friendly, step-by-step explanations and explain every part plainly as if the user has no experience; refactor explanations and code to be human/child-like understandable.
- Break tasks into small, incremental, focused steps and provide examples and runnable code when relevant.
- Favor a modular, visual-engineering workflow that enables adding game features and content with minimal coding; recommend component-based editors, visual node graphs, hot-reload, small script hooks, and data-driven content pipelines.

## Hardware and Performance Targets
- Target Direct3D 11 as the primary graphics API and ensure code paths and shaders compile cleanly for D3D11.
- Target GeForce GT 610 as the baseline GPU; optimize for low VRAM and limited shader throughput.
- Constrain asset sizes and formats: prefer 512–1024 max texture dimensions for most textures, use compressed texture formats where supported, and provide lower-resolution fallbacks.
- Prefer simple, efficient shaders and forward-rendering techniques; avoid heavy deferred pipelines unless a lightweight fallback exists.
- Minimize draw calls via batching and instancing; reduce overdraw and limit full-screen post-process effects.
- Implement level-of-detail (LOD), mipmapping, and streaming for meshes and textures to keep memory use and frame spikes low.
- Provide configurable quality presets (e.g., Low/Medium/High) that default to the safest Low preset for GT610.
- Validate performance frequently on GT610 and D3D11 to inform safe incremental changes.
- Define explicit GT610 budgets and targets:
  - Target runtime GPU memory footprint budgets: Low ≤ 512 MB, Medium ≤ 768 MB, High ≤ 1024 MB (tune per build).
  - Limit resident high-resolution textures to ≤ 256 MB on Low; prefer 128 MB for safe headroom.
  - Limit on-screen dynamic lights to 4 per object on Low; provide progressive increases for higher presets.
  - Aim for ≤ 100 draw calls in typical scenes for Low, ≤ 200 for Medium.
  - Keep frame-time budget targets explicit: prefer steady 60 FPS (16 ms) where achievable; ensure correct behavior and visual fallbacks at 30 FPS (33 ms).
  - Limit full-screen post-process passes to 1 on Low; cap additional passes per-preset.
  - Target shader instruction simplicity: avoid complex branching, large loops, and excessive texture fetches per pixel on Low.

## Code Organization and Style
- Keep code and project structure neat, orderly, and beginner-readable; write for easy comprehension by average readers, minimize code volume and duplication, and design for maintainability so future changes remain small and safe.
- Keep files small and focused; prefer files under 2000 lines.
- Decompose complex functions into small helper functions to improve readability and reduce monolithic code.
- Assign ownership: make each new feature/module own its shaders and GPU resources; colocate shader files and GPU resource management with the owning module and document lifecycle responsibilities.
- When adding new resources, declare matching member variables in the appropriate header before using them in .cpp to avoid undefined symbol or build errors.
- Minimize overall code volume: prefer small, focused modules and simple APIs; avoid unnecessary layers and abstractions that add cognitive load.
- Favor clear naming, brief comments, and straightforward control flow to aid average readers.
- Design for maintainability: use modular boundaries, explicit interfaces, simple tests, and readable documentation to keep future changes manageable.
- Vendor external dependencies with permissive free licenses suitable for commercial release (e.g., MIT, BSD, Apache-2.0); prefer vendoring (in-repo copies) or pinned submodules, include license files and attribution, and avoid permissive-incompatible dependencies.
- Organize related files into clear folders and name files to convey purpose.
- Use consistent formatting and naming conventions across the project.
- Prefer simple, explicit constructs and an old-school coding style over clever, compact, or highly abstract patterns to aid learning: favor straightforward loops and conditionals, explicit state and control flow, minimal metaprogramming, and clear step-by-step logic.
- Prefer shader code and rendering utilities that are easy to understand and test on D3D11 hardware.
- Prefer explicit configuration for hardware capability checks and fallback paths.
- Structure code changes so each edit is simple, logically ordered, and explicitly documented to help beginners edit, debug, and understand the codebase.

### Naming + Style Rules
- Use simple, purpose-driven names: prefer clarity over cleverness.
- Use PascalCase for types and classes, camelCase for local variables and functions, UPPER_SNAKE for constants, and kebab-case or snake_case for file names depending on platform conventions; keep one consistent pattern per repository.
- Name files to reflect primary contained type/functionality (e.g., renderer_forward.cpp, audio_stream.h).
- Use short, descriptive identifiers: prefer entityPosition over ePos, textureDiffuse over diffTex.
- Keep public API names stable and descriptive; avoid exposing internal abbreviations in public interfaces.
- Limit identifier length but preserve clarity; prefer explicit names for configuration flags and presets (e.g., QualityPreset_Low).
- Document naming exceptions and patterns in a lightweight CONTRIBUTING.md or style file.

### Dependency Governance
- Approve dependencies before adding: require a short justification, license check, and size/complexity review.
- Prefer vendoring or pinned submodules for all runtime dependencies; include license files and attribution in-repo.
- Require permissive licenses (MIT, BSD, Apache-2.0) for bundled code; document any other license with explicit approval and mitigation.
- Pin exact versions in dependency manifests and CI; avoid floating ranges.
- Maintain a minimal approved dependency list; avoid transitive heavy dependencies that pull large runtimes.
- Produce and commit an SBOM (Software Bill of Materials) for releases and CI artifacts.
- Scan dependencies for known vulnerabilities in CI and fail builds on critical issues.
- Prefer small, single-purpose libraries over large frameworks; prefer reimplementing tiny utilities when small footprint and clarity matter.

## Refactoring and Change Process
- Make changes in small, focused, and concise steps.
- Prefer splitting large edits into helper refactors rather than monolithic changes; if safe, group related low-risk edits into larger combined tasks to reduce session usage.
- Preserve the current project structure and existing naming conventions during refactors; avoid renames or moves unless necessary and document any changes with clear migration steps.
- For every change provide exact insertion or replacement locations (repository path plus line numbers or function context), indicate whether the edit is an insertion, replacement, or deletion, and include a short rationale for the change.
- Prefer minimal, non-breaking edits and avoid duplicate instructions across files or documentation.
- Favor isolated edits that add or modify self-contained code blocks or files to reduce merge and review complexity.
- Explain what links where and why: describe dependencies, imports, and how files interact.
- Show before-and-after snippets when relevant and specify exact ranges (file paths and line numbers or function names).
- Recommend minimal, safe edits that preserve learnability and incremental progress.
- Prefer non-destructive edits: use feature branches, small commits, and backups before risky changes.
- Use feature flags, toggles, or conditional compilation to introduce changes safely and revert easily.
- Run quick compatibility checks on D3D11/GT610 after each incremental change and document expected outcomes.
- Add simple automated or manual smoke tests to verify rendering, input, and audio subsystems on low-spec hardware.
- Avoid large-scale refactors in a single change; break refactors into verifiable sub-steps that preserve a working state.

## Reliability and Testing Rules
- Design systems to fail fast in development and degrade gracefully in production.
- Validate inputs and asset integrity at load time; provide clear error messages and fallback assets.
- Implement deterministic update loops and fixed-step simulation where appropriate for reproducible results and easier debugging.
- Add runtime health checks (watchdogs) and simple recovery paths for streaming, asset IO, and audio subsystems.
- Require lightweight automated tests for critical subsystems (renderer smoke, input, audio streaming) and run them in CI.
- Define minimal runtime telemetry and logging (configurable/opt-out) to help diagnose low-spec failures without high overhead.
- Use assertions in development builds; keep error-handling and safe fallbacks in release builds.
- Provide scripted manual QA checklists for GT610: render correctness, audio streaming, input latency, scene streaming stutter.

## Teaching & Explanations
- Explain every concept plainly and sequentially; assume no prior experience.
- Use analogies sparingly and only when they clarify a concrete programming detail.
- Prefer step-by-step instructions with clear expected outcomes for each step.
- Label examples clearly and indicate how to run them locally.
- Structure explanations so each step follows logically from the previous step; verify logical progression and simplicity for beginners.
- Make every new code example or edit simple, clearly explained, and explicitly connected to prior steps to aid learning and debugging.
- Ask what each code part should do before proposing final code; present alternatives and iterative drafts to enable user control over logic, structure, and implementation details.
- Provide beginner-friendly incremental next steps toward the end goal for each topic or recommended extraction: prioritize tasks, keep steps small, and include expected outcomes.

## Project-Specific Rules
- Recommend which parts of Game-Engine-for-Teaching to extract, and provide a simplified/rewritten alternative tailored to this project. When recommending specific extractions, cite source file paths, required adaptations, and licensing notes.
- Prioritize building a fully working engine incrementally: identify minimal viable subsystems (rendering, input, update loop, asset pipeline) and guide their assembly.
- When reusing code, document license-safe copying practices and necessary adaptations (API, naming, simplification).
- Vendor external dependencies with permissive free licenses suitable for commercial release; include license files, clear attribution, and prefer vendoring or pinned submodules to ensure future reproducibility.
- Prioritize safe, low-risk changes: propose the smallest change that achieves the goal and provide an easy rollback path.
- Prefer implementations that degrade gracefully on GT610 (reduced effects, lower resolution assets, simplified shaders).

### Architecture Guardrails for Visual / Audio / Animation
- Decouple core subsystems: rendering, asset streaming, audio, animation, and gameplay logic should communicate via explicit, versioned interfaces.
- Use streaming-first architecture for open-world content: prioritize proximity-based streaming, steady budgets per frame, and prefetch hints.
- Prioritize baked or precomputed lighting (light probes, baked GI, prefiltered environment maps) over full dynamic global illumination on low-spec targets.
- Use a single forward-renderer path with configurable feature toggles rather than multiple heavy pipelines; enable progressive enhancement per quality preset.
- Limit dynamic lights, particle counts, and skeletal bone counts per entity based on preset-defined budgets; enforce budgets at runtime.
- Use animation LOD: simpler rigs, lower blend counts, and lower sampling rates for distant characters.
- Stream audio assets and use compressed formats; prefer streaming music and ambient audio rather than fully resident audio banks.
- Favor baked/cached animation blending where possible; avoid complex runtime IK unless gated by quality presets and CPU budgets.
- Design predictable CPU and GPU work per frame: cap per-frame upload budgets, limit per-frame draw call growth, and provide backpressure to streaming systems.
- Require explicit, testable fallbacks for each expensive feature (e.g., SSAO -> disabled, particles -> reduced, shadow resolution -> lower).
- Keep material/shader permutations small: prefer parameterized materials over many unique shader variants to reduce shader compile/runtime costs.
- Document visual/audio trade-offs and which systems to simplify first when budgets are exceeded.
- Input and camera state:
  - Use a stable, predictable coding structure for camera and input logic.
  - Initialize camera and input state (yaw, pitch, position, velocity, lastInputTimestamp, etc.) outside the main loop.
  - Avoid redeclaring or resetting state variables inside per-frame loops or update callbacks.
  - Update state only by applying input deltas and simulation updates inside the loop.
  - Skip the first-frame input delta (or clamp it to zero) to prevent sudden jumps when capturing initial input.
  - Document and enforce this pattern in code reviews and future changes to maintain clarity and reliability.
 
  - ## Module Map (Source of Truth for Agents)
- App entry point and frame loop: `src/app/Main.cpp`
- Window creation (Win32): `src/platform/win32/`
- D3D11 device, swap chain, draw calls: `src/rendering/d3d11/D3D11Renderer.cpp/hpp`
- D3D11 helper utilities: `src/rendering/d3d11/D3D11RendererHelpers.cpp/hpp`
- HLSL shaders: `Shaders/` — pairs named `<feature>_vs.hlsl` / `<feature>_ps.hlsl`
- Camera + player movement + terrain snap: `src/game/CameraController.cpp/hpp`
- Player actor visual: `src/game/actors/PlayerActor.cpp/hpp`
- Actor shared types: `src/game/actors/ActorCommon.hpp`
- Scene coordinator (owns actors, calls per-frame updates): `src/game/RuntimeScene.hpp`
- Prefab definitions: `src/game/PrefabDef.hpp`
- Prefab registry: `src/game/PrefabLibrary.cpp/hpp`
- Multi-part box primitive renderer: `src/game/PrimitiveRenderer.cpp/hpp`
- Forest/tree instancing: `src/game/Forest.cpp/hpp`
- World grid (cell layout, biomes, terrain): `src/world/WorldGrid.cpp/hpp`
- ImGui context, pause menu, debug overlay: `src/ui/ImGuiLayer.cpp/hpp`
- World editor ImGui panel: `src/ui/WorldEditor.cpp/hpp`
- Asset registry (ID → file path map): `src/assets/AssetRegistry` + `AssetLoader`
- Frame timing: `src/app/FrameTiming.hpp`
- Input edge detection: `src/app/InputEdgeState.hpp`
- Cursor mode management: `src/app/CursorModeController.hpp`
- World editor per-frame ops: `src/app/WorldEditorFrameOps.hpp`
- World reload flow: `src/app/WorldReloadFlow.hpp`
- World runtime refresh: `src/app/WorldRuntimeRefresh.hpp`
- Third-party bootstrap + smoke tests: `src/app/ThirdPartyBootstrap.hpp`
- Logging: `src/logger/Logger.hpp` — macros: `LOG_INFO`, `LOG_WARN`, `LOG_ERROR`

## Third-Party Libraries Available (Do Not Re-Vendor)
All are already vendored and initialized. Use their wrappers — do not call them directly unless a wrapper does not exist yet.
- **ImGui** (`third_party/imgui/`) — UI. Init/shutdown owned by `ImGuiLayer`. Use `ImGui::*` calls inside `imguiLayer.BeginFrame()` / `imguiLayer.EndFrame()`.
- **miniaudio** — Audio. Initialized via `tp::Audio::Init()` in `ThirdPartyBootstrap`. Wrapper surface in `ThirdParty/tp_audio.hpp`.
- **Jolt Physics** — Physics. Initialized via `tp::Physics::Init()`. Wrapper surface in `ThirdParty/tp_physics.hpp`.
- **Recast/Detour** — Navigation. Initialized via `tp::Nav::Init()`. Wrapper in `ThirdParty/tp_navigation.hpp`.
- **DirectXTex** — Texture loading (.dds, .png). Smoke test via `tp::Texture::SmokeTest()`. Wrapper in `ThirdParty/tp_texture.hpp`.
- **stb_image** — Image loading. Wrapper in `ThirdParty/tp_image.hpp`.
- **Tracy** — CPU profiling. Use `GR_ZONE_SCOPED_N("label")` for zones and `GR_FRAME_MARK` at end of frame.

## New Module Checklist
Every new `.cpp/.hpp` pair must follow this checklist:
1. Place files in the correct `src/<subsystem>/` folder matching their concern.
2. Declare all member variables in the `.hpp` before using them in `.cpp`.
3. Add `#pragma once` at the top of every `.hpp`.
4. Use `LOG_INFO` / `LOG_WARN` / `LOG_ERROR` (from `logger/Logger.hpp`) — never `printf` or `OutputDebugStringA` in new code.
5. Add the `.cpp` to `GameRewritten.vcxproj` and `GameRewritten.vcxproj.filters` — agents must include this step or the file will not compile.
6. If the module owns GPU resources, add `Initialize(ID3D11Device*)` and `Shutdown()` methods and call them from `Main.cpp`.
7. If the module has per-frame work, wire it into `Main.cpp` inside the `while (window.ProcessEvents())` loop in the correct order (update before draw).
8. If the module draws ImGui, call it inside the existing `imguiLayer.BeginFrame()` / `imguiLayer.EndFrame()` block in `Main.cpp`.

## Wiring Patterns (How to Hook Into the Frame Loop)
Follow these exact patterns when adding new systems — do not invent new wiring approaches:

**Adding a new actor type:**
- Add files to `src/game/actors/`
- Add an instance to `RuntimeScene.hpp` alongside `PlayerActor`
- Call `Update(dt, renderer)` from `RuntimeScene::BeginFrame()` (or a new `RuntimeScene::Update()`)
- Call `SubmitRuntimeVisual(prefabLibrary, primRenderer)` from `RuntimeScene::SubmitActors()`

**Adding a new ImGui panel:**
- Add files to `src/ui/`
- Construct the panel object in `Main.cpp` before the loop
- Call `panel.Draw(...)` inside the `imguiLayer.BeginFrame()` / `imguiLayer.EndFrame()` block
- Guard with `if (!imguiLayer.IsPauseMenuOpen())` if it should hide when paused

**Adding a new app-layer helper (frame ops, reload flows, etc.):**
- Add a header-only `.hpp` to `src/app/` following the pattern of `WorldEditorFrameOps.hpp`
- Call it from `Main.cpp` at the correct point in the frame (before or after `camController.Update`)

**Adding a new audio call:**
- Use `tp::Audio` via its wrapper in `ThirdParty/tp_audio.hpp`
- Do not call miniaudio directly

**Adding a new constant buffer to a shader:**
- Declare the cbuffer struct in the `.hpp` of the owning renderer class
- Create the D3D11 buffer in `Initialize()`, update it per-frame or on-change, bind it to the correct slot (b0 = per-object, b1 = per-scene/light, b2+ = per-pass)
- Always match the slot number between C++ `VSSetConstantBuffers`/`PSSetConstantBuffers` and the HLSL `register(b#)`

## File Placement Quick Reference
| What you're adding | Where it goes |
|---|---|
| New actor (player, enemy, NPC) | `src/game/actors/` |
| New game mechanic (combat, inventory) | `src/game/` or `src/game/<subsystem>/` |
| New ImGui panel or HUD element | `src/ui/` |
| New asset loader/cache | `src/assets/` |
| New audio wrapper | `src/audio/` |
| New physics/collision helper | `src/game/physics/` |
| New app-layer frame helper | `src/app/` |
| New platform abstraction | `src/platform/win32/` |
| New D3D11 rendering feature | `src/rendering/d3d11/` |
| New HLSL shader pair | `Shaders/` named `<feature>_vs.hlsl` + `<feature>_ps.hlsl` |
| New content/data file | `Content/<type>/` (Textures, Audio, World, Prefabs, etc.) |

## Structure and Placement Rules
- Group semantically related instructions under appropriate headings.
- Place general instructions before specific ones.
- If multiple sections exist, add to the most relevant section.
- Create new sections only when an instruction does not fit existing categories.
- Use bullet lists for instructions and maintain consistent indentation and spacing.

## Merge & Edit Guidance
- Include exact insertion or replacement locations for every edit: repository path plus line numbers or function/context markers.
- Indicate edit type explicitly: insertion, replacement, or deletion.
- Prefer minimal, non-breaking edits over large rewrites.
- Avoid adding instructions that duplicate existing semantics; enhance or consolidate existing instructions instead.
- Favor isolated, self-contained file or code-block edits to reduce merge and review complexity.
- Provide exact patch/diff suggestions when possible and recommend a minimal commit message and branch name.
- Include a short rationale and expected verification steps for each delivered change set.
- Enforce a mandatory four-phase workflow for all substantive changes:
  - Plan: state scope, goals, exact file paths and line ranges, edit types, assumptions, and a short risk assessment.
  - Human-style review: present the plan for review by a human reviewer; collect explicit reviewer comments and requested changes.
  - Revised plan: update the plan to address reviewer feedback and confirm or correct initial assumptions.
  - Final code: produce the final code changes only after reviewer sign-off and explicit confirmation of assumptions.
  - Allow optional extra QA phases for complex or high-risk changes (e.g., extended automated tests, platform-specific validation, staged rollouts).
- Preserve existing error-reduction, placement, and minimal-change rules when applying the four-phase workflow; require exact locations and minimal edits at each phase.
- Prefer conservative edits first and provide optional progressive refinements in subsequent workflow iterations.

## Clarity and Output Requirements
- Keep instructions concise and actionable.
- Use the imperative mood ("Use X", not "You should use X").
- Avoid redundant phrases and preserve existing formatting conventions.
- For every delivered change set, include exact file/area/line context and a short rationale.
- Return the complete merged Markdown content only when asked to produce files or docs; do not add extra meta-commentary.

## AI Prompting & Model Guidance
- When requesting edits or code from LLM workflows, state the target model (e.g., GPT-4.1, GPT-5-mini), desired verbosity, and output format.
- When requesting future project work outputs, prefer guidance and code formatted for GPT-5-mini handoff style: concise implementation steps, explicit inputs/outputs, minimal reproducible context, clear next actions, and verification/acceptance criteria.
- Request incremental drafts and explicit review points to enable small commits and safe iteration.
- Ask for conservative code changes first and optional progressive refinements in later drafts.
- Provide minimal reproducible contexts (file snippets, exact paths, commands to run) to maximize output quality and reduce hallucination risk.
- Prefer explicit examples, unit tests, or smoke-test scripts to validate suggested edits on D3D11/GT610.
- Batch related LLM/agent requests into larger combined tasks when safe to reduce session usage; ensure each combined task still produces small, modular, reviewable edits and includes explicit checkpoints.

## Reliability and Testing Rules
- Design systems to fail fast in development and degrade gracefully in production.
- Validate inputs and asset integrity at load time; provide clear error messages and fallback assets.
- Implement deterministic update loops and fixed-step simulation where appropriate for reproducible results and easier debugging.
- Add runtime health checks (watchdogs) and simple recovery paths for streaming, asset IO, and audio subsystems.
- Require lightweight automated tests for critical subsystems (renderer smoke, input, audio streaming) and run them in CI.
- Define minimal runtime telemetry and logging (configurable/opt-out) to help diagnose low-spec failures without high overhead.
- Use assertions in development builds; keep error-handling and safe fallbacks in release builds.
- Provide scripted manual QA checklists for GT610: render correctness, audio streaming, input latency, scene streaming stutter.

## Structure and Placement Rules (Notes)
- Group semantically related instructions under appropriate headings.
- Place general instructions before specific ones.
- If multiple sections exist, add to the most relevant section.
- Create new sections only when the instruction doesn't fit existing categories.
- Use bullet lists for instructions and maintain consistent indentation and spacing.

## Coding Style — Narrative Code

Every function in this repo must read like a clear set of
instructions. A new developer should be able to read any
function top to bottom in one pass and understand exactly
what it does and why, without jumping to other files.

### The three rules — follow these in every PR

RULE 1 — Each function tells one story.
A function does one job. Its name says what that job is.
If a function is doing two jobs, split it into two functions.
Helper functions are encouraged — name them clearly.

RULE 2 — Code reads top to bottom like instructions.
Each block sets up the next block. Always in this order:
setup → guard clauses → main logic → output.
Never mix unrelated concerns in the same section.
Separate logical steps with one blank line.

RULE 3 — Names tell you what something IS.
Names must be self-describing without needing a comment.
  distanceToPlayer  not  d
  hitBox            not  hb
  enemy             not  e
  lifeRatio         not  t
  TestEnemyHitsAgainstPlayer()  not  CheckHits()
Single-letter names are only allowed for loop counters (i, j).

### Comments — earn every one

A comment STAYS if it explains WHY — why this value, why this
order, why this approach over the obvious alternative.

A comment is REMOVED if it:
- Restates what the next line of code already says clearly
- Describes what a function does when the name already says it
- References a completed task or merged track
- Says "for now" or "temporary" for something permanent

A codebase with fewer accurate comments is better than one
with many comments that cannot be trusted.

### Main loop and large functions — section headers

Any function longer than 20 lines must be divided into
clearly labelled sections with a one-line comment header:
  // --- Step name ---
Each section does one thing. Each flows logically from the one
above it. The section headers together should read like a
summary of the whole function.

### The test

After writing any function, read it top to bottom once as if
you are seeing it for the first time.
If you have to stop and think about what a line does, rename it.
If you have to read ahead to understand the current line, reorder it.
If a comment restates the code, delete the comment.
If a function is doing two things, split it.

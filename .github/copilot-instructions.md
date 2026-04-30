# Copilot Instructions

## General Guidelines
- Use imperative, concise language in all instructions.
- Break tasks into incremental, hands-on steps.
- Provide runnable examples and code when relevant.
- Keep responses focused on software development.

## Project Guidelines
- Use the lesson-planning and teaching style from Game-Engine-for-Teaching while avoiding its current structure; enable selective reuse of code rather than wholesale copying.
- Tailor guidance to help the user rebuild parts of the Game-Engine-for-Teaching repository in their own way and to progress toward creating an FF15-like game/engine; recommend which pieces of code to pull and how to adapt them.
- Favor designs and code paths compatible with Direct3D 11 and low-spec GPUs (target GeForce GT 610). Optimize recommendations, shaders, and asset budgets to run on that hardware.
- Aim for FF15-like visual and audio goals within GT610 limits: propose simplified rendering techniques, reduced-resolution assets, and audio compression/streaming strategies that emulate the look/sound without exceeding performance budgets.
- Use Game-Engine-for-Teaching as a reference source for lessons and code extraction; selectively rewrite and simplify its code into this project to achieve a fully working game engine.
- Provide very simple, beginner-friendly, step-by-step explanations and explain every part plainly as if the user has no experience; refactor explanations and code to be human/child-like understandable.
- Break tasks into small, incremental, focused steps and provide examples and runnable code when relevant.

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
- Minimize overall code volume: prefer small, focused modules and simple APIs; avoid unnecessary layers and abstractions that add cognitive load.
- Favor clear naming, brief comments, and straightforward control flow to aid average readers.
- Design for maintainability: use modular boundaries, explicit interfaces, simple tests, and readable documentation to keep future changes manageable.
- Vendor external dependencies with permissive free licenses suitable for commercial release (e.g., MIT, BSD, Apache-2.0); prefer vendoring (in-repo copies) or pinned submodules, include license files and attribution, and avoid permissive-incompatible dependencies.
- Organize related files into clear folders and name files to convey purpose.
- Use consistent formatting and naming conventions across the project.
- Prefer simple, explicit constructs over clever/compact ones to aid learning.
- Prefer shader code and rendering utilities that are easy to understand and test on D3D11 hardware.
- Prefer explicit configuration for hardware capability checks and fallback paths.

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
- For every change provide exact file, area, and line context plus a brief explanation of why the change was made.
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

## Project-Specific Rules
- Recommend which parts of Game-Engine-for-Teaching to extract, and provide a simplified/rewritten alternative tailored to this project.
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

## Structure and Placement Rules
- Group semantically related instructions under appropriate headings.
- Place general instructions before specific ones.
- If multiple sections exist, add to the most relevant section.
- Create new sections only when an instruction does not fit existing categories.
- Use bullet lists for instructions and maintain consistent indentation and spacing.

## Clarity and Output Requirements
- Keep instructions concise and actionable.
- Use the imperative mood ("Use X", not "You should use X").
- Avoid redundant phrases and preserve existing formatting conventions.
- For every delivered change set, include exact file/area/line context and a short rationale.
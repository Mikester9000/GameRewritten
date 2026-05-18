# Qwen 2.5 7B Prompts (Small, Manual Paste)

Use these **numbered, short prompts** with Qwen. Each prompt assumes **Qwen has zero repo access** and you will paste context manually. Keep every prompt small. Paste only the minimum needed context (file snippets, errors, logs).

**How to use**
- Copy **one prompt at a time** into Qwen.
- Paste only the **exact context** requested by that prompt.
- Manually apply Qwen’s output to the engine codebase.

---

## Phase 0 — Establish Baseline

1. **Prompt:**
   > I will paste the current repo structure and build steps. Reply with a 5–7 step baseline plan to build, run, and verify the current engine without changing code. Ask me for any missing commands or tools.

2. **Prompt:**
   > Here is the current README and build notes. Summarize the minimum build/run steps in 6 bullet points. Ask one clarification if anything is missing.

3. **Prompt:**
   > I will paste the current top-level folder list. Identify the likely entry point and where frame loop, rendering, and input are located. Keep your answer to 8 bullets max.

4. **Prompt:**
   > I will paste the current Main.cpp (or entry file). Identify: init order, per-frame order, shutdown order. Reply with three numbered lists.

---

## Phase 1 — Roadmap from Current State to Commercial Release

5. **Prompt:**
   > Create a concise roadmap from current engine state to commercial release. Use 6 phases max. Each phase: goal + 3–5 deliverables. Assume D3D11 + low-spec GPU target. Keep it short.

6. **Prompt:**
   > For Phase 1 only, create 10 small tasks. Each task should be 1–2 sentences and safe to do incrementally.

7. **Prompt:**
   > For Phase 2 only, create 10 small tasks. Same format as before.

8. **Prompt:**
   > For Phase 3 only, create 10 small tasks. Same format as before.

9. **Prompt:**
   > For Phase 4 only, create 10 small tasks. Same format as before.

10. **Prompt:**
    > For Phase 5 only, create 10 small tasks. Same format as before.

---

## Phase 2 — Architecture + Core Systems

11. **Prompt:**
    > I will paste the current module map / file list. Propose a minimal, modular architecture for: rendering, assets, audio, physics, UI, gameplay, tools. Keep to 8–10 bullets.

12. **Prompt:**
    > I will paste the rendering files. Propose a minimal forward-rendering pipeline with D3D11. List only key steps and data flow.

13. **Prompt:**
    > I will paste the input system code. Suggest small, low-risk improvements for stability and clarity. Provide only 3 changes.

14. **Prompt:**
    > I will paste the asset registry/loader. Propose a small, incremental improvement for caching or error handling. Keep it to one change.

15. **Prompt:**
    > I will paste the camera controller. Identify any state-reset risks and give 2 small fixes.

---

## Phase 3 — Rendering + Visual Targets

16. **Prompt:**
    > I will paste current shader list. Propose 5 minimal shaders needed for a commercial-ready baseline (name + purpose only).

17. **Prompt:**
    > I will paste the D3D11 renderer. Propose a small batch of changes to add: basic lighting, simple shadows, and a UI pass. Keep to 3–5 steps.

18. **Prompt:**
    > I will paste the material system (if any). Propose a minimal material model that supports albedo/normal/roughness and per-quality toggles. Keep to 6 bullets.

19. **Prompt:**
    > Provide a minimal post-processing list suitable for GT610. Max 3 passes. Explain when each can be disabled.

20. **Prompt:**
    > Provide a low-spec visual budget checklist: draw calls, texture sizes, light counts, shadow sizes. Keep to one short table.

---

## Phase 4 — Gameplay Framework + Tools

21. **Prompt:**
    > I will paste the actor/prefab system. Propose a minimal component model with 3–5 components. Keep the change plan small.

22. **Prompt:**
    > I will paste the runtime scene update loop. Suggest a fixed-step simulation plan that is safe and minimal. Provide only a 5-step plan.

23. **Prompt:**
    > I will paste ImGui panels. Suggest 3 essential panels for commercial readiness (debug, performance, content). Keep it short.

24. **Prompt:**
    > Propose a minimal save/load format and versioning scheme for levels/prefabs. 6 bullets max.

25. **Prompt:**
    > Propose a minimal in-engine console/logging command system. 5 bullets max.

---

## Phase 5 — Audio, Physics, Navigation

26. **Prompt:**
    > I will paste the audio wrapper usage. Suggest a minimal audio mixer design: music, SFX, UI, ambient. Keep to 6 bullets.

27. **Prompt:**
    > I will paste the physics wrapper usage. Suggest 3 small physics features to add next (e.g., triggers, raycasts, simple character controller).

28. **Prompt:**
    > I will paste navigation usage. Suggest a minimal navmesh workflow and how to bake it. 6 bullets max.

---

## Phase 6 — Asset Pipeline + Content

29. **Prompt:**
    > Propose a minimal asset pipeline from source → cooked data for textures, meshes, audio. Keep to 8 bullets.

30. **Prompt:**
    > Propose a content folder layout for commercial release with versioned assets and build outputs. Keep it short.

31. **Prompt:**
    > Propose a small set of automated asset validation checks (naming, sizes, formats). 6 bullets max.

---

## Phase 7 — Performance + Stability

32. **Prompt:**
    > Provide a minimal profiling plan for CPU and GPU on low-spec hardware. 8 bullets max.

33. **Prompt:**
    > Propose 5 low-risk performance wins for D3D11 forward rendering.

34. **Prompt:**
    > Propose a crash-safe startup sequence and a safe shutdown sequence. Keep to two numbered lists.

35. **Prompt:**
    > Propose a minimal error-reporting and log file strategy appropriate for a commercial build. 6 bullets max.

---

## Phase 8 — QA + Testing

36. **Prompt:**
    > Propose a minimal smoke-test checklist for rendering, input, audio, physics. 12 bullets max.

37. **Prompt:**
    > Propose minimal automated tests that can run in CI for this engine. 8 bullets max.

38. **Prompt:**
    > Propose a manual QA checklist for low-spec GPU (GT610). Keep it short.

---

## Phase 9 — Release Engineering

39. **Prompt:**
    > Propose a minimal build pipeline for Debug/Release, including symbol generation and asset cooking. 8 bullets max.

40. **Prompt:**
    > Propose a Windows packaging plan (installer, portable zip, dependencies). 6 bullets max.

41. **Prompt:**
    > Propose versioning rules and release notes format. 6 bullets max.

42. **Prompt:**
    > Provide a minimal rollback strategy for releases. 5 bullets max.

---

## Phase 10 — Legal + Commercial Readiness

43. **Prompt:**
    > Provide a checklist for licenses and third-party attributions required for commercial release. 8 bullets max.

44. **Prompt:**
    > Provide a minimal EULA + privacy policy checklist (what sections to include). 8 bullets max.

45. **Prompt:**
    > Provide a minimal security checklist for shipped builds. 8 bullets max.

---

## Phase 11 — Documentation + Support

46. **Prompt:**
    > Provide a minimal user guide outline for the engine/tools. 8 bullets max.

47. **Prompt:**
    > Provide a minimal developer guide outline for contributors. 8 bullets max.

48. **Prompt:**
    > Provide a minimal troubleshooting guide outline. 8 bullets max.

---

## Phase 12 — Task Execution Templates (Small Changes)

49. **Prompt:**
    > I will paste a single file. Identify one safe, minimal improvement. Provide exact edit steps and explain why. Keep it short.

50. **Prompt:**
    > I will paste an error log. Identify likely cause and 3 minimal fixes to try, in priority order.

51. **Prompt:**
    > I will paste a compiler error. Explain it in plain terms and propose the smallest fix.

52. **Prompt:**
    > I will paste a shader. Suggest one small optimization for GT610 and show the changed snippet only.

53. **Prompt:**
    > I will paste a class. Suggest one refactor that reduces complexity without changing behavior. Provide the new version only.

---

## Phase 13 — Final Commercial Release Gate

54. **Prompt:**
    > Provide a go/no-go checklist for commercial release of this engine. 15 bullets max.

55. **Prompt:**
    > Provide a release candidate checklist for bug triage and prioritization. 10 bullets max.

56. **Prompt:**
    > Provide a post-launch support plan (patch cadence, hotfix rules, support channels). 8 bullets max.

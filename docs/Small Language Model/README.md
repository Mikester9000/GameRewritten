# Small Language Model task prompt library

## What this folder is for
This folder is a complete microcoding prompt library for finishing remaining work in `Mikester9000/GameRewritten` using **Qwen2.5 Coder 0.5B Instruct** in chat-only/manual-copy mode.

## How to use with Qwen2.5 Coder 0.5B Instruct (chat-only)
1. Open one phase file from the navigation table below.
2. Pick the next task entry in order.
3. Copy only that entry's prompt into Qwen.
4. Paste the small returned code block into the repo file.
5. Validate immediately before moving to the next entry.

## One-file-at-a-time workflow
- Every micro-task edits exactly one file.
- Do not combine entries.
- If a source task touches multiple files, complete each split entry separately.

## How to paste context
- Prefer **20-100 lines** around the target symbol.
- Use `NEW FILE - no context needed` for file creation steps.
- Never paste whole large files unless required.

## How to copy generated code into the repo
- Copy only the returned code block.
- Paste at the listed anchor/insertion area.
- Save and run the smallest compile/smoke validation available.

## Validation after each micro-step
- Confirm the file still parses/compiles in the current project workflow.
- Run focused local checks/smoke test for changed subsystem.
- Keep changes tiny and reversible.

## Failure handling
- Revert that one micro-step only.
- Re-run the same entry with smaller context.
- Ask Qwen: "smallest compiling version".
- Continue only after successful validation.

## Source docs used to generate this library
- `docs/FULL_TASK_SEQUENCE.md`
- `docs/docs_ORDER_PLAN.md`
- `docs/SYSTEMS.md`
- `docs/CURRENT_STATE.md`
- `docs/LOCAL_AGENT_TASK_TEMPLATE.md`
- `docs/LOCAL_AGENT_QUICKSTART.md`
- `docs/TINY_CONTEXT_PROTOCOL.md`
- `docs/WORST_LLM_MODE.md`
- `docs/llm_instructions.md`
- `docs/PERFORMANCE_GUARDRAILS.md`
- `docs/CODING_STYLE.md`
- `docs/MAIN_CPP_PROTECTION.md`

## Navigation
| Phase/Subphase | File | Remaining micro-entries |
|---|---|---:|
| 1.1 Core Engine & Rendering | [`Phase01_01_Core_Engine_and_Rendering_SLM_TASKS.md`](./Phase01_01_Core_Engine_and_Rendering_SLM_TASKS.md) | 6 |
| 1.3 UI/HUD Core | [`Phase01_03_UI_HUD_Core_SLM_TASKS.md`](./Phase01_03_UI_HUD_Core_SLM_TASKS.md) | 11 |
| 1.4 Inventory & Progression | [`Phase01_04_Inventory_and_Progression_SLM_TASKS.md`](./Phase01_04_Inventory_and_Progression_SLM_TASKS.md) | 30 |
| 1.5 Save/Load & Core Systems | [`Phase01_05_Save_Load_and_Core_Systems_SLM_TASKS.md`](./Phase01_05_Save_Load_and_Core_Systems_SLM_TASKS.md) | 10 |
| 2.1 World Streaming & Structure | [`Phase02_01_World_Streaming_and_Structure_SLM_TASKS.md`](./Phase02_01_World_Streaming_and_Structure_SLM_TASKS.md) | 29 |
| 2.2 Traversal & Movement | [`Phase02_02_Traversal_and_Movement_SLM_TASKS.md`](./Phase02_02_Traversal_and_Movement_SLM_TASKS.md) | 30 |
| 2.3 NPCs & World Life | [`Phase02_03_NPCs_and_World_Life_SLM_TASKS.md`](./Phase02_03_NPCs_and_World_Life_SLM_TASKS.md) | 30 |
| 2.4 Quests & Progression | [`Phase02_04_Quests_and_Progression_SLM_TASKS.md`](./Phase02_04_Quests_and_Progression_SLM_TASKS.md) | 30 |
| 2.5 Weather & Environment | [`Phase02_05_Weather_and_Environment_SLM_TASKS.md`](./Phase02_05_Weather_and_Environment_SLM_TASKS.md) | 30 |
| 3.1 Party & AI Systems | [`Phase03_01_Party_and_AI_Systems_SLM_TASKS.md`](./Phase03_01_Party_and_AI_Systems_SLM_TASKS.md) | 30 |
| 3.2 Advanced Combat Mechanics | [`Phase03_02_Advanced_Combat_Mechanics_SLM_TASKS.md`](./Phase03_02_Advanced_Combat_Mechanics_SLM_TASKS.md) | 30 |
| 3.3 Combat Polish & Boss Systems | [`Phase03_03_Combat_Polish_and_Boss_Systems_SLM_TASKS.md`](./Phase03_03_Combat_Polish_and_Boss_Systems_SLM_TASKS.md) | 40 |
| 4.1 Water & Swimming | [`Phase04_01_Water_and_Swimming_SLM_TASKS.md`](./Phase04_01_Water_and_Swimming_SLM_TASKS.md) | 20 |
| 4.2 Climbing & Traversal | [`Phase04_02_Climbing_and_Traversal_SLM_TASKS.md`](./Phase04_02_Climbing_and_Traversal_SLM_TASKS.md) | 20 |
| 4.3 Minigames & Activities | [`Phase04_03_Minigames_and_Activities_SLM_TASKS.md`](./Phase04_03_Minigames_and_Activities_SLM_TASKS.md) | 30 |
| 4.4 Living World Features | [`Phase04_04_Living_World_Features_SLM_TASKS.md`](./Phase04_04_Living_World_Features_SLM_TASKS.md) | 30 |
| 5.1 Dialogue & Cutscenes | [`Phase05_01_Dialogue_and_Cutscenes_SLM_TASKS.md`](./Phase05_01_Dialogue_and_Cutscenes_SLM_TASKS.md) | 30 |
| 5.2 Audio & Music | [`Phase05_02_Audio_and_Music_SLM_TASKS.md`](./Phase05_02_Audio_and_Music_SLM_TASKS.md) | 14 |
| 6.1 Accessibility Features | [`Phase06_01_Accessibility_Features_SLM_TASKS.md`](./Phase06_01_Accessibility_Features_SLM_TASKS.md) | 30 |
| 6.2 Controller & Input | [`Phase06_02_Controller_and_Input_SLM_TASKS.md`](./Phase06_02_Controller_and_Input_SLM_TASKS.md) | 20 |
| 7.1 New Game Plus & Challenges | [`Phase07_01_New_Game_Plus_and_Challenges_SLM_TASKS.md`](./Phase07_01_New_Game_Plus_and_Challenges_SLM_TASKS.md) | 30 |
| 7.2 FF Tradition & Polish | [`Phase07_02_FF_Tradition_and_Polish_SLM_TASKS.md`](./Phase07_02_FF_Tradition_and_Polish_SLM_TASKS.md) | 20 |
| 8.1 Multi-Language Support | [`Phase08_01_Multi_Language_Support_SLM_TASKS.md`](./Phase08_01_Multi_Language_Support_SLM_TASKS.md) | 20 |
| 8.2 Content Pipeline & Tools | [`Phase08_02_Content_Pipeline_and_Tools_SLM_TASKS.md`](./Phase08_02_Content_Pipeline_and_Tools_SLM_TASKS.md) | 30 |
| 9.1 Release Gates & Final Integration | [`Phase09_01_Release_Gates_and_Final_Integration_SLM_TASKS.md`](./Phase09_01_Release_Gates_and_Final_Integration_SLM_TASKS.md) | 20 |
| 9.2 Final Polish & Documentation | [`Phase09_02_Final_Polish_and_Documentation_SLM_TASKS.md`](./Phase09_02_Final_Polish_and_Documentation_SLM_TASKS.md) | 19 |
| FULL reconciliation | [`Phase00_FULL_TASK_SEQUENCE_Reconciliation_SLM_TASKS.md`](./Phase00_FULL_TASK_SEQUENCE_Reconciliation_SLM_TASKS.md) | 150 |

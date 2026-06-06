# Docs Index

Master map of the `docs/` folder. Use this to quickly open the right file.

## Engine
| File | Purpose | When to open |
|------|---------|---------------|
| START_HERE.md | Session start guide | Every session |
| CURRENT_STATE.md | Snapshot of current implementation state | Session start / before coding |
| SYSTEMS.md | What exists / partial / missing | Before implementing anything |
| Architecture.md | Runtime architecture overview | Before cross-system edits |
| CODING_STYLE.md | Project coding standards | Before writing/editing code |
| PERFORMANCE_GUARDRAILS.md | Performance constraints and targets | Before gameplay/rendering changes |
| KNOWN_ISSUES.md | Current technical risks and fragile areas | When debugging or planning fixes |
| engine/MISSING_SYSTEMS.md | Human-readable prioritized engine gaps | Session planning and prioritization |

## Vision
| File | Purpose | When to open |
|------|---------|---------------|
| FINAL_GOAL.md | End-state game target | High-level alignment checks |
| GAME_VISION_PLAN.md | Consolidated game direction summary | Planning major slices |
| GRAPHICS_VISION.md | Visual target and rendering direction | Graphics and shader work |
| COMBAT_VISION.md | Combat feel and system goals | Combat-related tasks |
| UI_VISION.md | UI/UX target style and behavior | HUD/menu changes |
| UI_PRESENTATION_STYLE.md | Presentation/tone rules for UI | UI polish and consistency passes |
| vision/GAME_DESIGN_BIBLE.md | Merged design principles from small vision files | Broad design reference |
| ANIMATION_FEEL.md | Animation goals and timing feel | Animation tuning |
| ARTISTIC_STYLE.md | Stylization and art direction notes | Asset/shader planning |
| BLOCKOUT_FIRST_POLICY.md | Blockout-first content policy | Early level/system work |
| CHARACTER_VISUAL_STYLE.md | Character look direction | Character art/rig/render tasks |
| COMBAT_PILLARS.md | Core combat pillar definitions | Combat system decisions |
| DESIGN_PHILOSOPHY.md | Core design principles | Tradeoff decisions |
| ENEMY_DESIGN.md | Enemy behavior and presentation direction | Enemy/system implementation |
| ENVIRONMENT_VISUAL_STYLE.md | Environment visual language | World art and lighting |
| EXPLORATION_DESIGN.md | Exploration goals and structure | Open-world flow tasks |
| FINAL_FANTASY_FEEL.md | FF-inspired feel guidance | Tone/style checks |
| LIGHTING_AND_COLOR.md | Lighting and palette guidance | Lighting/post-process work |
| PARTY_SYSTEM_DIRECTION.md | Party system direction | Party and AI work |
| PLAYER_FEEL.md | Player controller and responsiveness goals | Movement/combat feel tweaks |
| PROGRESSION_PHILOSOPHY.md | Progression model guidance | Progression/inventory/leveling tasks |
| QUEST_AND_EVENT_PHILOSOPHY.md | Quest/event design guidance | Quest and narrative systems |
| REGION_IDENTITY_GUIDE.md | Region-level visual/gameplay identity notes | Region content planning |
| STORY_TONE.md | Narrative tone and voice target | Writing/dialog direction |
| WORLD_LORE_DIRECTION.md | Lore constraints and themes | Story/world planning |
| WORLD_STRUCTURE.md | World composition and flow | Map/world-system planning |

## Story
| File | Purpose | When to open |
|------|---------|---------------|
| story/STORY_PLACEHOLDER.md | Generic replaceable story strings for engine testing | When systems need placeholder narrative data |

## Planning
| File | Purpose | When to open |
|------|---------|---------------|
| NEXT_TASK.md | Current task card | Every session |
| FULL_TASK_SEQUENCE.md | Ordered global backlog | When validating task order |
| FEATURE_ROADMAP_STRUCTURE.md | Feature roadmap organization rules | Planning docs maintenance |
| PLANNED_FEATURES.md | Feature backlog summary | Planning scope |
| QUALITY_BAR.md | Quality expectations for shipped work | Before declaring tasks done |
| SUGGESTED_FEATURES.md | Optional feature ideas | Backlog expansion |
| docs_ORDER_PLAN.md | Master order mapping of task IDs | Determining true next dependency |
| ONE_FILE_COMPLETION_PLAN.md | Main one-file plan | Task-level planning |
| ONE_FILE_COMPLETION_PLAN(CON1).md | CON1 addendum plan | CON1 execution |
| ONE_FILE_COMPLETION_PLAN(CON2).md | CON2 addendum plan | CON2 execution |
| ONE_FILE_COMPLETION_PLAN(CON3).md | CON3 addendum plan | CON3 execution |
| docs_ONE_FILE_COMPLETION_PLAN(CON4).md | CON4 addendum plan | CON4 execution |
| docs_ONE_FILE_COMPLETION_PLAN(CON5).md | CON5 addendum plan | CON5 execution |
| docs_ONE_FILE_COMPLETION_PLAN(CON6).md | CON6 addendum plan | CON6 execution |
| docs_ONE_FILE_COMPLETION_PLAN(CON7).md | CON7 addendum plan | CON7 execution |
| docs_ONE_FILE_COMPLETION_PLAN(CON8).md | CON8 addendum plan | CON8 execution |
| Development Roadmap.txt | Legacy roadmap notes | Historical reference |
| Engine Cleanup Checklist.txt | Legacy cleanup list | Refactor planning |

## Reference
| File | Purpose | When to open |
|------|---------|---------------|
| ASSET_PIPELINE.md | Asset import/export pipeline details | Asset pipeline work |
| ASSET_REGISTRY.md | Asset registry conventions and IDs | Asset lookup/registration changes |
| ASSETS.md | Content asset conventions | Asset authoring |
| CODEBASE_GLOSSARY.md | Terms and definitions used in repo | Clarifying terminology |
| CONTENT_CREATION_GUIDE.md | End-to-end content creation workflow | Creating/importing content |
| CONTENT_PIPELINE_GUIDE.md | Pipeline implementation guidance | Pipeline/tooling updates |
| DECISION_DEFAULTS.md | Project default decisions and assumptions | When undecided on common choices |
| DO_NOT_BUILD_YET.md | Deferred systems/features | Scope control |
| MAIN_CPP_PROTECTION.md | Rules for reducing Main.cpp risk | Main.cpp refactors |
| PERFORMANCE_GUARDRAILS.md | Runtime performance limits | Any perf-sensitive change |
| PREFABS_GUIDE.md | Prefab workflow and structure | Prefab implementation/content |
| ROADMAP_VENDORING.md | Third-party vendoring roadmap | Dependency/vendor planning |
| SAFE_REFACTOR_RULES.md | Refactor safety protocol | Refactors touching multiple files |
| SYSTEM_OWNERSHIP.md | Ownership boundaries by subsystem | Routing tasks and reviews |
| THIRD_PARTY.md | Third-party dependencies/licenses | Dependency audits |
| WORLD_EDITOR.md | World editor notes/workflow | World editing tooling |
| Workflow.md | General project workflow conventions | Process refresh |

## Agent
| File | Purpose | When to open |
|------|---------|---------------|
| AGENT_JOB.md | Current agent operation framing | Agent-run setup |
| AGENT_RULES.md | Agent execution constraints | Agent-run setup |
| AGENT_TASK_TEMPLATE.md | Standardized agent task format | Creating new task cards |
| AGENT_WORK_LOG.md | Append-only historical task log | Reviewing completed work |
| AUTOPILOT_WORKFLOW.md | Deterministic local-LLM run loop | Running autonomous sessions |
| LOCAL_AGENT_QUICKSTART.md | Quickstart for local coding agents | Onboarding local agent runs |
| LOCAL_AGENT_TASK_TEMPLATE.md | Local task templating format | Writing local task prompts |
| README_AGENT_DOCS.md | Agent documentation index | Locating agent-specific docs |
| TINY_CONTEXT_PROTOCOL.md | Tiny-context execution protocol | Running weak local LLMs |
| WORST_LLM_MODE.md | Strict no-ambiguity local-LLM mode | Maximum-guardrail sessions |
| llm_instructions.md | Single-file instruction pack for local LLMs | Initial local LLM prompt source |
| Qwen_prompts.md | Prompt snippets for Qwen workflows | Qwen-specific task execution |
| docs_GAMEREWRITTEN_STYLE_TRANSFORMATION_TASK.md | Style transformation task spec | Specialized doc transformation work |
| CHANGELOG.md | Append-only change notes required by guard workflow | Task completion bookkeeping |

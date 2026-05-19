# One-File Commercial Completion Plan (Independent Lego-Block Tasks)

This is the single source document to finish the game track to commercial-readiness handoff.
Each task is independent, prompt-ready, and includes exact file targets, insertion line numbers, and line-modification budgets.

## Hard Rules
1. One task per run.
2. Only edit the files listed in that task card unless compile errors force one extra file.
3. No dependency additions. No file moves. No file renames.
4. Keep D3D11 + GT610-safe defaults.
5. Use append-first edits (add blocks at designated line targets) to keep Lego-style integration.
6. Update required docs after every task:
   - `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`
   - `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`
   - `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`

## Standard Command Loop (Per Task)
```bash
cd /home/runner/work/GameRewritten/GameRewritten
python tools/llm/worst_llm_guard.py doctor
python tools/llm/worst_llm_guard.py start
# implement one task card from this file
python tools/llm/worst_llm_guard.py complete
```

## How to Read Line Targets
- **Insert At Line**: preferred line to add new block (usually EOF + 1 for low-conflict integration).
- **Modify Existing Lines (max)**: hard cap for changed pre-existing lines in this file for the task.
- **Add New Lines (target)**: expected new lines to add for the task in this file.

## Copy-Paste Prompt Skeleton
```text
Implement Task <ID>: <NAME>.

File edit plan:
<paste the File Edit Plan table from the task card>

Rules: one-task-only, no new dependencies, no file moves/renames, GT610-safe defaults, append-first Lego-block edits.

After code edits update:
- /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
- /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
- /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md

Then run: python tools/llm/worst_llm_guard.py complete
```

## Task Cards 001-060

### Task 001: Pressure / stagger integration stub
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 001: Pressure / stagger integration stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 002: Enemy reaction / interrupt-lite
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 002: Enemy reaction / interrupt-lite.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 003: Enemy attack telegraph lite
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 003: Enemy attack telegraph lite.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 004: Screen edge damage flash
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 004: Screen edge damage flash.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 005: Hit pause / hitstop
- **Original scope token(s):** `src/game/RuntimeScene.hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` | yes | 330 | 331 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 005: Hit pause / hitstop.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 006: Stagger meter
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 006: Stagger meter.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 007: Enemy attack telegraph
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 007: Enemy attack telegraph.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 008: Parry / counter window
- **Original scope token(s):** `src/game/actors/PlayerActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp` | yes | 109 | 110 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp` | yes | 36 | 37 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 008: Parry / counter window.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 009: Weak point damage
- **Original scope token(s):** `src/game/combat/CombatSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 009: Weak point damage.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 010: Area name display
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 010: Area name display.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 011: Notification toast system
- **Original scope token(s):** `src/ui/NotificationSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 011: Notification toast system.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 012: Letterbox event bars
- **Original scope token(s):** `src/ui/ImGuiLayer.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` | yes | 566 | 567 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` | yes | 123 | 124 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 012: Letterbox event bars.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 013: Contextual button prompts
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 013: Contextual button prompts.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 014: Level up screen overlay
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 014: Level up screen overlay.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 015: Status screen
- **Original scope token(s):** `src/ui/StatusScreen.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 015: Status screen.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 016: Map screen stub
- **Original scope token(s):** `src/ui/MapScreen.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 016: Map screen stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 017: Tooltip system
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 017: Tooltip system.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 018: Saving indicator
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 018: Saving indicator.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 019: Death / defeat screen
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 019: Death / defeat screen.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 020: Camera shake
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 020: Camera shake.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 021: Combat camera zoom
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 021: Combat camera zoom.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 022: Camera collision avoidance
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 022: Camera collision avoidance.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 023: Target framing adjustment
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 023: Target framing adjustment.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 024: Lock-on camera recovery smoothing
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 024: Lock-on camera recovery smoothing.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 025: Wind effect on trees
- **Original scope token(s):** `Shaders/tree_vs.hlsl`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl` | yes | 39 | 40 | 20 | 35 |

- **Task prompt block (copy exactly):**
```text
Implement Task 025: Wind effect on trees.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 026: Weather system lite
- **Original scope token(s):** `src/world/WeatherSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 026: Weather system lite.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 027: Ambient particles
- **Original scope token(s):** `src/game/ParticleSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 027: Ambient particles.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 028: Day/night cycle
- **Original scope token(s):** `src/world/DayNightCycle.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 028: Day/night cycle.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 029: Biome transition fade
- **Original scope token(s):** `src/world/WorldGrid.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` | yes | 353 | 354 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` | yes | 111 | 112 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 029: Biome transition fade.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 030: Fog of war on minimap
- **Original scope token(s):** `src/ui/Minimap.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp` | yes | 148 | 149 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp` | yes | 27 | 28 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 030: Fog of war on minimap.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 031: World event trigger zones
- **Original scope token(s):** `src/game/world/EventZone.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 031: World event trigger zones.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 032: Interaction hotspot registry stub
- **Original scope token(s):** `src/game/world/InteractionRegistry.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 032: Interaction hotspot registry stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 033: Landmark discovery trigger stub
- **Original scope token(s):** `src/game/world/LandmarkTrigger.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 033: Landmark discovery trigger stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 034: NPC actor
- **Original scope token(s):** `src/game/actors/NpcActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 034: NPC actor.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 035: Quest objective system
- **Original scope token(s):** `src/game/quest/QuestSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 035: Quest objective system.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 036: Treasure chest actor
- **Original scope token(s):** `src/game/actors/ChestActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 036: Treasure chest actor.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 037: Campfire / rest point actor
- **Original scope token(s):** `src/game/actors/RestPointActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 037: Campfire / rest point actor.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 038: NPC interaction prompt routing stub
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`, `src/game/world/InteractionRegistry.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 038: NPC interaction prompt routing stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 039: Quest flag / world-state hook
- **Original scope token(s):** `src/game/quest/QuestFlags.hpp`, `src/game/quest/QuestSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 039: Quest flag / world-state hook.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 040: Spawn composition table stub (solo / pair / pack)
- **Original scope token(s):** `src/world/SpawnTable.hpp`, `src/world/WorldGrid.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` | yes | 353 | 354 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` | yes | 111 | 112 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 040: Spawn composition table stub (solo / pair / pack).
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 041: Inventory system
- **Original scope token(s):** `src/game/inventory/Inventory.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 041: Inventory system.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 042: XP / level system
- **Original scope token(s):** `src/game/actors/PlayerStats.hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 042: XP / level system.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 043: Status effects
- **Original scope token(s):** `src/game/actors/PlayerStats.hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 043: Status effects.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 044: Fast travel stub
- **Original scope token(s):** `src/game/world/FastTravel.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 044: Fast travel stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 045: Save / load system
- **Original scope token(s):** `src/app/SaveSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 045: Save / load system.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 046: Quality preset enforcement
- **Original scope token(s):** `src/app/QualityPreset.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` | no | 0 | 1 | 0 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 046: Quality preset enforcement.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 047: Victory fanfare trigger
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 047: Victory fanfare trigger.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 048: Environmental ambient audio
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 048: Environmental ambient audio.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 049: Looping BGM
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 049: Looping BGM.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 050: Tactical Pause enter / exit SFX
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` | yes | 139 | 140 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` | yes | 28 | 29 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 050: Tactical Pause enter / exit SFX.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 051: Lock-on acquire / break SFX
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/game/combat/Targeting.hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp` | yes | 136 | 137 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 051: Lock-on acquire / break SFX.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 052: Enemy alert bark stub
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 052: Enemy alert bark stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 053: Equipment slot stub
- **Original scope token(s):** `src/game/inventory/Equipment.hpp`, `src/game/actors/PlayerStats.hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 053: Equipment slot stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 054: Ability unlock / progression hook
- **Original scope token(s):** `src/game/progression/AbilityProgression.hpp`, `src/game/actors/PlayerStats.hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 054: Ability unlock / progression hook.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 055: Combat stat modifier pipeline stub
- **Original scope token(s):** `src/game/combat/CombatModifiers.hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 055: Combat stat modifier pipeline stub.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 056: Combat bugfix sweep
- **Original scope token(s):** `src/game/combat/CombatSystem.cpp/hpp`, `src/game/RuntimeScene.hpp`, `src/app/Main.cpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` | yes | 330 | 331 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` | yes | 565 | 566 | 28 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 056: Combat bugfix sweep.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 057: Camera/input bugfix sweep
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`, `src/app/InputActionMap.hpp`, `src/app/Main.cpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp` | yes | 87 | 88 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` | yes | 565 | 566 | 28 | 70 |

- **Task prompt block (copy exactly):**
```text
Implement Task 057: Camera/input bugfix sweep.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 058: UI/HUD polish and bugfix sweep
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` | yes | 566 | 567 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` | yes | 123 | 124 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` | yes | 139 | 140 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` | yes | 28 | 29 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 058: UI/HUD polish and bugfix sweep.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 059: World/runtime stability sweep
- **Original scope token(s):** `src/world/WorldGrid.cpp/hpp`, `src/game/RuntimeScene.cpp/hpp`, `src/game/Forest.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` | yes | 353 | 354 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` | yes | 111 | 112 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.cpp` | yes | 109 | 110 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` | yes | 330 | 331 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.cpp` | yes | 233 | 234 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.hpp` | yes | 48 | 49 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 059: World/runtime stability sweep.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 060: Audio and final quality sweep
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/app/QualityPreset.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Task prompt block (copy exactly):**
```text
Implement Task 060: Audio and final quality sweep.
Use the File Edit Plan table in this task card exactly.
Apply append-first edits at the listed Insert At Line values unless a compile error requires a nearby replacement.
Do not exceed Modify Existing Lines (max) per file. Target Add New Lines counts per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

## Commercial-Readiness Exit Gate (After Task 060)
1. No unchecked tasks in `/home/runner/work/GameRewritten/GameRewritten/docs/FULL_TASK_SEQUENCE.md`.
2. No `❌` systems in `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`.
3. `/home/runner/work/GameRewritten/GameRewritten/docs/NEXT_TASK.md` reports no remaining unchecked tasks.
4. All third-party notices and license attributions are complete and packaged.
5. Low/Medium/High quality presets are validated with safe defaults on low-end hardware target.
6. Save/load, progression, combat loop, and audio state transitions pass smoke checks.
7. Final changelog includes release-readiness summary and unresolved known-issues list.

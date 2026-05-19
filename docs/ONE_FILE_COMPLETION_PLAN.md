# One-File Commercial Completion Plan (Independent Lego-Block Tasks)

This is the single source document to finish the game track to commercial-readiness handoff.
Each task is independent, prompt-ready, and includes exact file targets, insertion lines, modification budgets, copy-ready code blocks, and smaller ordered substeps for Qwen2.5-Coder-1.5B.
This plan assumes the LLM cannot directly edit files: it can only return text that a human copies into files manually.

## Hard Rules
1. One task per run.
2. Each tiny prompt must target exactly one file.
3. Only edit the files listed in that task card unless compile errors force one extra file.
4. No dependency additions. No file moves. No file renames.
5. Keep D3D11 + GT610-safe defaults.
6. Use append-first edits (add blocks at designated line targets) to keep Lego-style integration.
7. Update required docs after every task:
   - `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`
   - `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`
   - `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`

## Read-Minimized Single-File Contract (Required)
1. Every prompt must include `READ_FILE` with an absolute path.
2. Every prompt must include `READ_LINES` as a strict range (for example `190-214`).
3. Read only the listed file and lines before generating output.
4. If the step lists multiple files (usually docs), split into one prompt per file.
5. Never ask the LLM to inspect extra files "for context".

## Manual Copy/Paste Output Contract (Required)
1. The model must never claim it changed files directly.
2. For each step, the model must output only copy-ready text for the target file(s).
3. Every code-edit step output must include:
   - target file absolute path
   - read file path and line range
   - anchor reference from the task card
   - explicit action (`insert-after-anchor` or `replace-range`)
   - one fenced code block containing the exact final text to paste
4. No explanations outside the copy-ready payload unless the prompt explicitly asks for them.
5. Human operator pastes output into files, saves, and only then runs the next step.

## Qwen2.5-Coder-1.5B Mode
1. Use one prompt per step, not one prompt per whole task.
2. Generate output for only one file in each code-edit step.
3. Copy only the current step packet and the matching code context block into the model.
4. Finish all listed code-file steps in order before the docs-update step.
5. Do not merge multiple file edits into one response.
6. Stop after each step, manually paste output into the file, and save before moving to the next step.
7. If a step fails, retry the same step. Do not jump forward.
8. Use the full-task prompt only if the model proves it can handle the entire task safely.

## Standard Command Loop (Per Task)
```bash
cd /home/runner/work/GameRewritten/GameRewritten
python tools/llm/worst_llm_guard.py doctor
python tools/llm/worst_llm_guard.py start
# implement one task card from this file
python tools/llm/worst_llm_guard.py complete
```

## How to Read Task Cards
- **Insert At Line** = preferred insertion line (append-first; usually EOF + 1).
- **Modify Existing Lines (max)** = cap for changed pre-existing lines in that file.
- **Add New Lines (target)** = expected new-line budget in that file.
- **Code Context Blocks** = copy these blocks directly into your LLM prompt.
- **Qwen Step Packets** = use these smaller prompts one at a time when running on Qwen2.5-Coder-1.5B.

## Universal Prompt Template (Full Task)
```text
Implement Task <ID>: <NAME>.

Use the File Edit Plan and Code Context Blocks from this task card exactly.
You cannot edit files directly. Output copy-ready payloads only.
Apply append-first edits at listed Insert At Line values unless compile errors force a nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
Use one prompt per file step.

For each file output this exact format:
FILE: <absolute path>
READ_FILE: <absolute path>
READ_LINES: <start-end from code context block>
ACTION: <insert-after-anchor|replace-range>
ANCHOR: <anchor from task card>
PASTE_BLOCK_START
```<language>
<exact text to paste>
```
PASTE_BLOCK_END

After edits update:
- /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
- /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
- /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md

Then run: python tools/llm/worst_llm_guard.py complete
```

## Universal Prompt Template (Single Step for Qwen2.5-Coder-1.5B)
```text
Execute exactly one step packet from the selected task card.
You cannot edit files directly. Output copy-ready payload only.
Target only the file named in that step packet.
Use only the matching Code Context Block from the same task card.
Do not generate changes for any other file in this step.
Read only the lines specified in the step packet before generating output.
Output this exact shape:
FILE: <absolute path>
READ_FILE: <absolute path>
READ_LINES: <start-end from code context block>
ACTION: <insert-after-anchor|replace-range>
ANCHOR: <anchor from task card>
PASTE_BLOCK_START
```<language>
<exact text to paste>
```
PASTE_BLOCK_END
Stop after finishing this one step.
```

## Task Cards 001-060

### Task 001: Pressure / stagger integration stub
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` and stop so a human can paste them manually.
6. Run docs updates as three one-file prompts only: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
7. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 7: Read task card only
```text
Task 001: Pressure / stagger integration stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` only
```text
Task 001: Pressure / stagger integration stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 215.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` only
```text
Task 001: Pressure / stagger integration stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 96.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` only
```text
Task 001: Pressure / stagger integration stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 167.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` only
```text
Task 001: Pressure / stagger integration stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 72.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 7: Update docs only
```text
Task 001: Pressure / stagger integration stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 7 / 7: Complete task guard
```text
Task 001: Pressure / stagger integration stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
- Anchor lines `190-214` (current file tail before insertion at line `215`):
```cpp
190 |     if (isDead)
191 |         return;
192 | 
193 |     if (!IsHitFlashVisible())
194 |         return;
195 | 
196 |     static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
197 |     const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);
198 |     if (!visualPrefab)
199 |         return;
200 | 
201 |     const float hitFlashScale = (hitFlashTimer > 0.0f) ? kHitFlashScale : 1.0f;
202 |     primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, hitFlashScale);
203 | }
204 | 
205 | bool EnemyActor::IsHitFlashVisible() const
206 | {
207 |     if (hitFlashTimer <= 0.0f)
208 |         return true;
209 | 
210 |     const float elapsedFlashTime = kHitFlashDuration - hitFlashTimer;
211 |     const int blinkPhase = static_cast<int>(elapsedFlashTime / kHitFlashBlinkPeriod);
212 |     // Even elapsed phases are visible so a fresh hit starts visible.
213 |     return (blinkPhase % 2) == 0;
214 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
EDIT MODE: append-first
INSERT AT LINE: 215
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 190-214
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
- Anchor lines `71-95` (current file tail before insertion at line `96`):
```cpp
71 |               float wpAx, float wpAz,
72 |               float wpBx, float wpBz,
73 |               int   startHp = 10);
74 | 
75 |     // Advance state machine, move, snap Y to terrain.
76 |     // playerX/playerZ are the current player world-space XZ position.
77 |     void Update(float dt, D3D11Renderer& renderer,
78 |                 float playerX, float playerZ);
79 | 
80 |     // Apply incoming damage; triggers Hit stagger or Dead transition.
81 |     void OnHit(int damage);
82 | 
83 |     // Expand the enemy visual into the runtime primitive bucket.
84 |     // Reuses the player blockout prefab for enemy visuals.
85 |     // Does nothing when isDead is true.
86 |     void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
87 |                              PrimitiveRenderer&   primitiveRenderer) const;
88 | 
89 | private:
90 |     // Change state immediately and set the state-duration timer.
91 |     void TransitionTo(EnemyState next, float duration);
92 | 
93 |     // Returns whether the visual should be drawn this frame during hit flash.
94 |     bool IsHitFlashVisible() const;
95 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
EDIT MODE: append-first
INSERT AT LINE: 96
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 71-95
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
- Anchor lines `142-166` (current file tail before insertion at line `167`):
```cpp
142 | 
143 |             std::ostringstream ss;
144 |             ss << "CombatSystem: Hit enemy " << i
145 |                << " for " << hitBox.damage << " damage.";
146 |             LOG_INFO(ss.str());
147 | 
148 |             enemy.OnHit(hitBox.damage);
149 | 
150 |             if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
151 |             {
152 |                 EnemyHitRecord& hitRecord = m_recentEnemyHits[m_recentEnemyHitCount++];
153 |                 hitRecord.x = enemy.x;
154 |                 hitRecord.y = enemy.y + DAMAGE_NUMBER_Y_OFFSET;
155 |                 hitRecord.z = enemy.z;
156 |                 hitRecord.damage = hitBox.damage;
157 |             }
158 |         }
159 |     }
160 | 
161 |     // Remove any hitboxes whose lifetime has run out.
162 |     m_activeHitBoxes.erase(
163 |         std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
164 |                        [](const HitBox& hitBox) { return hitBox.framesToLive <= 0; }),
165 |         m_activeHitBoxes.end());
166 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
EDIT MODE: append-first
INSERT AT LINE: 167
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 142-166
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp`
- Anchor lines `47-71` (current file tail before insertion at line `72`):
```cpp
47 |     // apply damage, mark dead enemies, and remove expired hitboxes.
48 |     // Also ticks the combo window timer.
49 |     // Call once per frame from RuntimeScene::BeginFrame.
50 |     void Update(float dt, EnemyActor* enemies, int count);
51 | 
52 |     // Read-only access to active hitboxes for debug visualization.
53 |     const std::vector<HitBox>& GetActiveHitBoxes() const
54 |     { return m_activeHitBoxes; }
55 | 
56 |     // Recent hit records are valid for the current frame only.
57 |     // They are reset at the start of each Update() call.
58 |     // Always pair this pointer with GetRecentEnemyHitCount().
59 |     const EnemyHitRecord* GetRecentEnemyHits() const
60 |     { return m_recentEnemyHits; }
61 | 
62 |     int GetRecentEnemyHitCount() const
63 |     { return m_recentEnemyHitCount; }
64 | 
65 | private:
66 |     static constexpr int   kMaxRecentEnemyHits = 32;
67 | 
68 |     std::vector<HitBox> m_activeHitBoxes;
69 |     EnemyHitRecord m_recentEnemyHits[kMaxRecentEnemyHits]{};
70 |     int m_recentEnemyHitCount = 0;
71 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
EDIT MODE: append-first
INSERT AT LINE: 72
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 47-71
```

- **Task prompt block (copy exactly):**
```text
Implement Task 001: Pressure / stagger integration stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 002: Enemy reaction / interrupt-lite
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` and stop so a human can paste them manually.
6. Run docs updates as three one-file prompts only: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
7. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 7: Read task card only
```text
Task 002: Enemy reaction / interrupt-lite.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` only
```text
Task 002: Enemy reaction / interrupt-lite.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 215.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` only
```text
Task 002: Enemy reaction / interrupt-lite.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 96.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` only
```text
Task 002: Enemy reaction / interrupt-lite.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 167.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` only
```text
Task 002: Enemy reaction / interrupt-lite.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 72.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 7: Update docs only
```text
Task 002: Enemy reaction / interrupt-lite.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 7 / 7: Complete task guard
```text
Task 002: Enemy reaction / interrupt-lite.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
- Anchor lines `190-214` (current file tail before insertion at line `215`):
```cpp
190 |     if (isDead)
191 |         return;
192 | 
193 |     if (!IsHitFlashVisible())
194 |         return;
195 | 
196 |     static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
197 |     const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);
198 |     if (!visualPrefab)
199 |         return;
200 | 
201 |     const float hitFlashScale = (hitFlashTimer > 0.0f) ? kHitFlashScale : 1.0f;
202 |     primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, hitFlashScale);
203 | }
204 | 
205 | bool EnemyActor::IsHitFlashVisible() const
206 | {
207 |     if (hitFlashTimer <= 0.0f)
208 |         return true;
209 | 
210 |     const float elapsedFlashTime = kHitFlashDuration - hitFlashTimer;
211 |     const int blinkPhase = static_cast<int>(elapsedFlashTime / kHitFlashBlinkPeriod);
212 |     // Even elapsed phases are visible so a fresh hit starts visible.
213 |     return (blinkPhase % 2) == 0;
214 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
EDIT MODE: append-first
INSERT AT LINE: 215
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 190-214
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
- Anchor lines `71-95` (current file tail before insertion at line `96`):
```cpp
71 |               float wpAx, float wpAz,
72 |               float wpBx, float wpBz,
73 |               int   startHp = 10);
74 | 
75 |     // Advance state machine, move, snap Y to terrain.
76 |     // playerX/playerZ are the current player world-space XZ position.
77 |     void Update(float dt, D3D11Renderer& renderer,
78 |                 float playerX, float playerZ);
79 | 
80 |     // Apply incoming damage; triggers Hit stagger or Dead transition.
81 |     void OnHit(int damage);
82 | 
83 |     // Expand the enemy visual into the runtime primitive bucket.
84 |     // Reuses the player blockout prefab for enemy visuals.
85 |     // Does nothing when isDead is true.
86 |     void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
87 |                              PrimitiveRenderer&   primitiveRenderer) const;
88 | 
89 | private:
90 |     // Change state immediately and set the state-duration timer.
91 |     void TransitionTo(EnemyState next, float duration);
92 | 
93 |     // Returns whether the visual should be drawn this frame during hit flash.
94 |     bool IsHitFlashVisible() const;
95 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
EDIT MODE: append-first
INSERT AT LINE: 96
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 71-95
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
- Anchor lines `142-166` (current file tail before insertion at line `167`):
```cpp
142 | 
143 |             std::ostringstream ss;
144 |             ss << "CombatSystem: Hit enemy " << i
145 |                << " for " << hitBox.damage << " damage.";
146 |             LOG_INFO(ss.str());
147 | 
148 |             enemy.OnHit(hitBox.damage);
149 | 
150 |             if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
151 |             {
152 |                 EnemyHitRecord& hitRecord = m_recentEnemyHits[m_recentEnemyHitCount++];
153 |                 hitRecord.x = enemy.x;
154 |                 hitRecord.y = enemy.y + DAMAGE_NUMBER_Y_OFFSET;
155 |                 hitRecord.z = enemy.z;
156 |                 hitRecord.damage = hitBox.damage;
157 |             }
158 |         }
159 |     }
160 | 
161 |     // Remove any hitboxes whose lifetime has run out.
162 |     m_activeHitBoxes.erase(
163 |         std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
164 |                        [](const HitBox& hitBox) { return hitBox.framesToLive <= 0; }),
165 |         m_activeHitBoxes.end());
166 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
EDIT MODE: append-first
INSERT AT LINE: 167
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 142-166
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp`
- Anchor lines `47-71` (current file tail before insertion at line `72`):
```cpp
47 |     // apply damage, mark dead enemies, and remove expired hitboxes.
48 |     // Also ticks the combo window timer.
49 |     // Call once per frame from RuntimeScene::BeginFrame.
50 |     void Update(float dt, EnemyActor* enemies, int count);
51 | 
52 |     // Read-only access to active hitboxes for debug visualization.
53 |     const std::vector<HitBox>& GetActiveHitBoxes() const
54 |     { return m_activeHitBoxes; }
55 | 
56 |     // Recent hit records are valid for the current frame only.
57 |     // They are reset at the start of each Update() call.
58 |     // Always pair this pointer with GetRecentEnemyHitCount().
59 |     const EnemyHitRecord* GetRecentEnemyHits() const
60 |     { return m_recentEnemyHits; }
61 | 
62 |     int GetRecentEnemyHitCount() const
63 |     { return m_recentEnemyHitCount; }
64 | 
65 | private:
66 |     static constexpr int   kMaxRecentEnemyHits = 32;
67 | 
68 |     std::vector<HitBox> m_activeHitBoxes;
69 |     EnemyHitRecord m_recentEnemyHits[kMaxRecentEnemyHits]{};
70 |     int m_recentEnemyHitCount = 0;
71 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
EDIT MODE: append-first
INSERT AT LINE: 72
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 47-71
```

- **Task prompt block (copy exactly):**
```text
Implement Task 002: Enemy reaction / interrupt-lite.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 003: Enemy attack telegraph lite
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 003: Enemy attack telegraph lite.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` only
```text
Task 003: Enemy attack telegraph lite.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 215.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` only
```text
Task 003: Enemy attack telegraph lite.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 96.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 003: Enemy attack telegraph lite.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 003: Enemy attack telegraph lite.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
- Anchor lines `190-214` (current file tail before insertion at line `215`):
```cpp
190 |     if (isDead)
191 |         return;
192 | 
193 |     if (!IsHitFlashVisible())
194 |         return;
195 | 
196 |     static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
197 |     const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);
198 |     if (!visualPrefab)
199 |         return;
200 | 
201 |     const float hitFlashScale = (hitFlashTimer > 0.0f) ? kHitFlashScale : 1.0f;
202 |     primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, hitFlashScale);
203 | }
204 | 
205 | bool EnemyActor::IsHitFlashVisible() const
206 | {
207 |     if (hitFlashTimer <= 0.0f)
208 |         return true;
209 | 
210 |     const float elapsedFlashTime = kHitFlashDuration - hitFlashTimer;
211 |     const int blinkPhase = static_cast<int>(elapsedFlashTime / kHitFlashBlinkPeriod);
212 |     // Even elapsed phases are visible so a fresh hit starts visible.
213 |     return (blinkPhase % 2) == 0;
214 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
EDIT MODE: append-first
INSERT AT LINE: 215
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 190-214
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
- Anchor lines `71-95` (current file tail before insertion at line `96`):
```cpp
71 |               float wpAx, float wpAz,
72 |               float wpBx, float wpBz,
73 |               int   startHp = 10);
74 | 
75 |     // Advance state machine, move, snap Y to terrain.
76 |     // playerX/playerZ are the current player world-space XZ position.
77 |     void Update(float dt, D3D11Renderer& renderer,
78 |                 float playerX, float playerZ);
79 | 
80 |     // Apply incoming damage; triggers Hit stagger or Dead transition.
81 |     void OnHit(int damage);
82 | 
83 |     // Expand the enemy visual into the runtime primitive bucket.
84 |     // Reuses the player blockout prefab for enemy visuals.
85 |     // Does nothing when isDead is true.
86 |     void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
87 |                              PrimitiveRenderer&   primitiveRenderer) const;
88 | 
89 | private:
90 |     // Change state immediately and set the state-duration timer.
91 |     void TransitionTo(EnemyState next, float duration);
92 | 
93 |     // Returns whether the visual should be drawn this frame during hit flash.
94 |     bool IsHitFlashVisible() const;
95 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
EDIT MODE: append-first
INSERT AT LINE: 96
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 71-95
```

- **Task prompt block (copy exactly):**
```text
Implement Task 003: Enemy attack telegraph lite.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 004: Screen edge damage flash
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 004: Screen edge damage flash.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 004: Screen edge damage flash.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 004: Screen edge damage flash.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 004: Screen edge damage flash.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 004: Screen edge damage flash.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 004: Screen edge damage flash.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 005: Hit pause / hitstop
- **Original scope token(s):** `src/game/RuntimeScene.hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` | yes | 330 | 331 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` and stop so a human can paste them manually.
3. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
4. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 4: Read task card only
```text
Task 005: Hit pause / hitstop.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 4: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` only
```text
Task 005: Hit pause / hitstop.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 331.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 4: Update docs only
```text
Task 005: Hit pause / hitstop.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 4 / 4: Complete task guard
```text
Task 005: Hit pause / hitstop.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp`
- Anchor lines `306-330` (current file tail before insertion at line `331`):
```cpp
306 |     // m_playerY is the camera eye level; body center is shifted down by kPlayerBodyCenterOffset.
307 |     bool HitBoxOverlapsPlayer(const HitBox& hitBox) const
308 |     {
309 |         float bodyCenterY = m_playerY - kPlayerBodyCenterOffset;
310 |         float distX = fabsf(m_playerX - hitBox.x);
311 |         float distY = fabsf(bodyCenterY - hitBox.y);
312 |         float distZ = fabsf(m_playerZ - hitBox.z);
313 |         return (distX < kPlayerHitHalfX + hitBox.halfX) &&
314 |                (distY < kPlayerHitHalfY + hitBox.halfY) &&
315 |                (distZ < kPlayerHitHalfZ + hitBox.halfZ);
316 |     }
317 | 
318 |     float GetAttackYaw(const CameraController& camController) const
319 |     {
320 |         const EnemyActor* lockedTarget = m_targeting.GetTarget();
321 |         if (!lockedTarget)
322 |             return camController.GetYaw();
323 | 
324 |         const float playerX = camController.GetPlayerX();
325 |         const float playerZ = camController.GetPlayerZ();
326 |         const float deltaX = lockedTarget->x - playerX;
327 |         const float deltaZ = lockedTarget->z - playerZ;
328 |         return atan2f(deltaX, deltaZ);
329 |     }
330 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp
EDIT MODE: append-first
INSERT AT LINE: 331
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 306-330
```

- **Task prompt block (copy exactly):**
```text
Implement Task 005: Hit pause / hitstop.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 006: Stagger meter
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 006: Stagger meter.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` only
```text
Task 006: Stagger meter.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 215.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` only
```text
Task 006: Stagger meter.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 96.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 006: Stagger meter.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 006: Stagger meter.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
- Anchor lines `190-214` (current file tail before insertion at line `215`):
```cpp
190 |     if (isDead)
191 |         return;
192 | 
193 |     if (!IsHitFlashVisible())
194 |         return;
195 | 
196 |     static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
197 |     const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);
198 |     if (!visualPrefab)
199 |         return;
200 | 
201 |     const float hitFlashScale = (hitFlashTimer > 0.0f) ? kHitFlashScale : 1.0f;
202 |     primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, hitFlashScale);
203 | }
204 | 
205 | bool EnemyActor::IsHitFlashVisible() const
206 | {
207 |     if (hitFlashTimer <= 0.0f)
208 |         return true;
209 | 
210 |     const float elapsedFlashTime = kHitFlashDuration - hitFlashTimer;
211 |     const int blinkPhase = static_cast<int>(elapsedFlashTime / kHitFlashBlinkPeriod);
212 |     // Even elapsed phases are visible so a fresh hit starts visible.
213 |     return (blinkPhase % 2) == 0;
214 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
EDIT MODE: append-first
INSERT AT LINE: 215
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 190-214
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
- Anchor lines `71-95` (current file tail before insertion at line `96`):
```cpp
71 |               float wpAx, float wpAz,
72 |               float wpBx, float wpBz,
73 |               int   startHp = 10);
74 | 
75 |     // Advance state machine, move, snap Y to terrain.
76 |     // playerX/playerZ are the current player world-space XZ position.
77 |     void Update(float dt, D3D11Renderer& renderer,
78 |                 float playerX, float playerZ);
79 | 
80 |     // Apply incoming damage; triggers Hit stagger or Dead transition.
81 |     void OnHit(int damage);
82 | 
83 |     // Expand the enemy visual into the runtime primitive bucket.
84 |     // Reuses the player blockout prefab for enemy visuals.
85 |     // Does nothing when isDead is true.
86 |     void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
87 |                              PrimitiveRenderer&   primitiveRenderer) const;
88 | 
89 | private:
90 |     // Change state immediately and set the state-duration timer.
91 |     void TransitionTo(EnemyState next, float duration);
92 | 
93 |     // Returns whether the visual should be drawn this frame during hit flash.
94 |     bool IsHitFlashVisible() const;
95 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
EDIT MODE: append-first
INSERT AT LINE: 96
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 71-95
```

- **Task prompt block (copy exactly):**
```text
Implement Task 006: Stagger meter.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 007: Enemy attack telegraph
- **Original scope token(s):** `src/game/actors/EnemyActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 007: Enemy attack telegraph.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` only
```text
Task 007: Enemy attack telegraph.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 215.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` only
```text
Task 007: Enemy attack telegraph.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 96.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 007: Enemy attack telegraph.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 007: Enemy attack telegraph.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
- Anchor lines `190-214` (current file tail before insertion at line `215`):
```cpp
190 |     if (isDead)
191 |         return;
192 | 
193 |     if (!IsHitFlashVisible())
194 |         return;
195 | 
196 |     static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
197 |     const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);
198 |     if (!visualPrefab)
199 |         return;
200 | 
201 |     const float hitFlashScale = (hitFlashTimer > 0.0f) ? kHitFlashScale : 1.0f;
202 |     primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, hitFlashScale);
203 | }
204 | 
205 | bool EnemyActor::IsHitFlashVisible() const
206 | {
207 |     if (hitFlashTimer <= 0.0f)
208 |         return true;
209 | 
210 |     const float elapsedFlashTime = kHitFlashDuration - hitFlashTimer;
211 |     const int blinkPhase = static_cast<int>(elapsedFlashTime / kHitFlashBlinkPeriod);
212 |     // Even elapsed phases are visible so a fresh hit starts visible.
213 |     return (blinkPhase % 2) == 0;
214 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
EDIT MODE: append-first
INSERT AT LINE: 215
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 190-214
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
- Anchor lines `71-95` (current file tail before insertion at line `96`):
```cpp
71 |               float wpAx, float wpAz,
72 |               float wpBx, float wpBz,
73 |               int   startHp = 10);
74 | 
75 |     // Advance state machine, move, snap Y to terrain.
76 |     // playerX/playerZ are the current player world-space XZ position.
77 |     void Update(float dt, D3D11Renderer& renderer,
78 |                 float playerX, float playerZ);
79 | 
80 |     // Apply incoming damage; triggers Hit stagger or Dead transition.
81 |     void OnHit(int damage);
82 | 
83 |     // Expand the enemy visual into the runtime primitive bucket.
84 |     // Reuses the player blockout prefab for enemy visuals.
85 |     // Does nothing when isDead is true.
86 |     void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
87 |                              PrimitiveRenderer&   primitiveRenderer) const;
88 | 
89 | private:
90 |     // Change state immediately and set the state-duration timer.
91 |     void TransitionTo(EnemyState next, float duration);
92 | 
93 |     // Returns whether the visual should be drawn this frame during hit flash.
94 |     bool IsHitFlashVisible() const;
95 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
EDIT MODE: append-first
INSERT AT LINE: 96
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 71-95
```

- **Task prompt block (copy exactly):**
```text
Implement Task 007: Enemy attack telegraph.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 008: Parry / counter window
- **Original scope token(s):** `src/game/actors/PlayerActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp` | yes | 109 | 110 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp` | yes | 36 | 37 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 008: Parry / counter window.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp` only
```text
Task 008: Parry / counter window.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 110.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp` only
```text
Task 008: Parry / counter window.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 37.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 008: Parry / counter window.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 008: Parry / counter window.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp`
- Anchor lines `85-109` (current file tail before insertion at line `110`):
```cpp
 85 |         break;
 86 |     }
 87 | }
 88 | 
 89 | void PlayerActor::TransitionTo(PlayerActionState next, float duration)
 90 | {
 91 |     state = next;
 92 |     stateTimer = duration;
 93 | }
 94 | 
 95 | void PlayerActor::SubmitRuntimeVisual(const CameraController& cameraController,
 96 |                                       const PrefabLibrary& prefabLibrary,
 97 |                                       PrimitiveRenderer& primitiveRenderer) const
 98 | {
 99 |     static const std::string kPlayerVisualPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
100 |     const PrimitivePrefab* visualPrefab =
101 |         prefabLibrary.GetPrefab(kPlayerVisualPrefabId);
102 |     if (!visualPrefab)
103 |         return;
104 | 
105 |     const ActorCommon::RuntimeActorPose pose = BuildRuntimePose(cameraController);
106 |     primitiveRenderer.AddRuntimeInstance(*visualPrefab,
107 |                                          pose.x, pose.y, pose.z,
108 |                                          pose.yaw, pose.scale);
109 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.cpp
EDIT MODE: append-first
INSERT AT LINE: 110
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 85-109
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp`
- Anchor lines `12-36` (current file tail before insertion at line `37`):
```cpp
12 | #include "PlayerActionState.hpp"
13 | #include "PlayerStats.hpp"
14 | 
15 | class CameraController;
16 | struct InputActionMap;
17 | class PrefabLibrary;
18 | class PrimitiveRenderer;
19 | 
20 | class PlayerActor
21 | {
22 | public:
23 |     PlayerStats stats;
24 |     PlayerActionState state = PlayerActionState::Idle;
25 |     float stateTimer = 0.0f;
26 | 
27 |     void Update(float dt, const InputActionMap& input, bool isGrounded, bool attackPressed);
28 | 
29 |     void SubmitRuntimeVisual(const CameraController& cameraController,
30 |                              const PrefabLibrary& prefabLibrary,
31 |                              PrimitiveRenderer& primitiveRenderer) const;
32 | 
33 | private:
34 |     void TransitionTo(PlayerActionState next, float duration);
35 |     ActorCommon::RuntimeActorPose BuildRuntimePose(const CameraController& cameraController) const;
36 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerActor.hpp
EDIT MODE: append-first
INSERT AT LINE: 37
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 12-36
```

- **Task prompt block (copy exactly):**
```text
Implement Task 008: Parry / counter window.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 009: Weak point damage
- **Original scope token(s):** `src/game/combat/CombatSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 009: Weak point damage.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` only
```text
Task 009: Weak point damage.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 167.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` only
```text
Task 009: Weak point damage.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 72.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 009: Weak point damage.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 009: Weak point damage.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
- Anchor lines `142-166` (current file tail before insertion at line `167`):
```cpp
142 | 
143 |             std::ostringstream ss;
144 |             ss << "CombatSystem: Hit enemy " << i
145 |                << " for " << hitBox.damage << " damage.";
146 |             LOG_INFO(ss.str());
147 | 
148 |             enemy.OnHit(hitBox.damage);
149 | 
150 |             if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
151 |             {
152 |                 EnemyHitRecord& hitRecord = m_recentEnemyHits[m_recentEnemyHitCount++];
153 |                 hitRecord.x = enemy.x;
154 |                 hitRecord.y = enemy.y + DAMAGE_NUMBER_Y_OFFSET;
155 |                 hitRecord.z = enemy.z;
156 |                 hitRecord.damage = hitBox.damage;
157 |             }
158 |         }
159 |     }
160 | 
161 |     // Remove any hitboxes whose lifetime has run out.
162 |     m_activeHitBoxes.erase(
163 |         std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
164 |                        [](const HitBox& hitBox) { return hitBox.framesToLive <= 0; }),
165 |         m_activeHitBoxes.end());
166 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
EDIT MODE: append-first
INSERT AT LINE: 167
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 142-166
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp`
- Anchor lines `47-71` (current file tail before insertion at line `72`):
```cpp
47 |     // apply damage, mark dead enemies, and remove expired hitboxes.
48 |     // Also ticks the combo window timer.
49 |     // Call once per frame from RuntimeScene::BeginFrame.
50 |     void Update(float dt, EnemyActor* enemies, int count);
51 | 
52 |     // Read-only access to active hitboxes for debug visualization.
53 |     const std::vector<HitBox>& GetActiveHitBoxes() const
54 |     { return m_activeHitBoxes; }
55 | 
56 |     // Recent hit records are valid for the current frame only.
57 |     // They are reset at the start of each Update() call.
58 |     // Always pair this pointer with GetRecentEnemyHitCount().
59 |     const EnemyHitRecord* GetRecentEnemyHits() const
60 |     { return m_recentEnemyHits; }
61 | 
62 |     int GetRecentEnemyHitCount() const
63 |     { return m_recentEnemyHitCount; }
64 | 
65 | private:
66 |     static constexpr int   kMaxRecentEnemyHits = 32;
67 | 
68 |     std::vector<HitBox> m_activeHitBoxes;
69 |     EnemyHitRecord m_recentEnemyHits[kMaxRecentEnemyHits]{};
70 |     int m_recentEnemyHitCount = 0;
71 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
EDIT MODE: append-first
INSERT AT LINE: 72
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 47-71
```

- **Task prompt block (copy exactly):**
```text
Implement Task 009: Weak point damage.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 010: Area name display
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 010: Area name display.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 010: Area name display.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 010: Area name display.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 010: Area name display.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 010: Area name display.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 010: Area name display.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 011: Notification toast system
- **Original scope token(s):** `src/ui/NotificationSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 011: Notification toast system.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp` only
```text
Task 011: Notification toast system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp` only
```text
Task 011: Notification toast system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 011: Notification toast system.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 011: Notification toast system.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/NotificationSystem.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 011: Notification toast system.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 012: Letterbox event bars
- **Original scope token(s):** `src/ui/ImGuiLayer.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` | yes | 566 | 567 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` | yes | 123 | 124 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 012: Letterbox event bars.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` only
```text
Task 012: Letterbox event bars.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 567.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` only
```text
Task 012: Letterbox event bars.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 124.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 012: Letterbox event bars.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 012: Letterbox event bars.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp`
- Anchor lines `542-566` (current file tail before insertion at line `567`):
```cpp
542 |     float camX, float camY, float camZ,
543 |     float yaw,  float pitch,
544 |     float vpW,  float vpH)
545 | {
546 |     if (!target || target->isDead)
547 |         return;
548 |     if (!ImGui::GetCurrentContext())
549 |         return;
550 | 
551 |     float sx = 0.0f;
552 |     float sy = 0.0f;
553 |     if (!WorldToScreen(target->x, target->y + kLockMarkerHeightOffset, target->z,
554 |                        camX, camY, camZ, yaw, pitch, vpW, vpH, sx, sy))
555 |     {
556 |         return;
557 |     }
558 | 
559 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
560 |     const ImU32 lockColor = IM_COL32(255, 220, 80, 255);
561 | 
562 |     drawList->AddCircle(ImVec2(sx, sy), kLockMarkerCircleRadius, lockColor,
563 |                         kLockMarkerCircleSegments, kLockMarkerCircleThickness);
564 |     drawList->AddText(ImVec2(sx + kLockMarkerTextOffsetX, sy + kLockMarkerTextOffsetY),
565 |                       lockColor, "LOCK");
566 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp
EDIT MODE: append-first
INSERT AT LINE: 567
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 542-566
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp`
- Anchor lines `99-123` (current file tail before insertion at line `124`):
```cpp
 99 | 
100 | private:
101 |     bool initialized = false;
102 | 
103 |     bool showPauseMenu   = false;
104 |     bool showDebugOverlay = false;
105 | 
106 |     float currentFPS = 0.0f;
107 |     float currentDT  = 0.0f;
108 |     float camX = 0.0f, camY = 0.0f, camZ = 0.0f;
109 |     float camYaw = 0.0f, camPitch = 0.0f;
110 | 
111 |     bool wantsQuit   = false;
112 |     bool wantsResume = false;
113 |     D3D11Renderer* m_renderer = nullptr;
114 |     bool  m_lightUiInitialized = false;
115 |     float m_sunDirX = 0.0f;
116 |     float m_sunDirY = -1.0f;
117 |     float m_sunDirZ = 0.0f;
118 |     float m_ambientStrength = 0.25f;
119 |     AudioManager* m_audioManager = nullptr;
120 | 
121 |     void DrawPauseMenu();
122 |     void DrawDebugOverlay();
123 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp
EDIT MODE: append-first
INSERT AT LINE: 124
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 99-123
```

- **Task prompt block (copy exactly):**
```text
Implement Task 012: Letterbox event bars.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 013: Contextual button prompts
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 013: Contextual button prompts.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 013: Contextual button prompts.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 013: Contextual button prompts.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 013: Contextual button prompts.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 013: Contextual button prompts.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 013: Contextual button prompts.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 014: Level up screen overlay
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 014: Level up screen overlay.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 014: Level up screen overlay.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 014: Level up screen overlay.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 014: Level up screen overlay.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 014: Level up screen overlay.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 014: Level up screen overlay.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 015: Status screen
- **Original scope token(s):** `src/ui/StatusScreen.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 015: Status screen.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp` only
```text
Task 015: Status screen.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp` only
```text
Task 015: Status screen.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 015: Status screen.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 015: Status screen.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/StatusScreen.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 015: Status screen.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 016: Map screen stub
- **Original scope token(s):** `src/ui/MapScreen.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 016: Map screen stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp` only
```text
Task 016: Map screen stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp` only
```text
Task 016: Map screen stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 016: Map screen stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 016: Map screen stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/MapScreen.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 016: Map screen stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 017: Tooltip system
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 017: Tooltip system.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 017: Tooltip system.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 017: Tooltip system.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 017: Tooltip system.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 017: Tooltip system.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 017: Tooltip system.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 018: Saving indicator
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 018: Saving indicator.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 018: Saving indicator.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 018: Saving indicator.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 018: Saving indicator.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 018: Saving indicator.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 018: Saving indicator.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 019: Death / defeat screen
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 019: Death / defeat screen.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 019: Death / defeat screen.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 019: Death / defeat screen.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 019: Death / defeat screen.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 019: Death / defeat screen.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 019: Death / defeat screen.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 020: Camera shake
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 020: Camera shake.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` only
```text
Task 020: Camera shake.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 304.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` only
```text
Task 020: Camera shake.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 130.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 020: Camera shake.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 020: Camera shake.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
- Anchor lines `279-303` (current file tail before insertion at line `304`):
```cpp
279 |         XM_PIDIV4,          // 45-degree vertical FOV (matches DrawTerrainPatch)
280 |         vpW / vpH,
281 |         0.1f, 2000.0f);
282 | 
283 |     // Unproject near and far screen points into world space.
284 |     // XMVector3Unproject arguments: screenPoint, vpX, vpY, vpW, vpH, minZ, maxZ, proj, view, world
285 |     XMVECTOR nearPt = XMVector3Unproject(
286 |         XMVectorSet(mouseX, mouseY, 0.0f, 0.0f),
287 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
288 |         proj, view, XMMatrixIdentity());
289 | 
290 |     XMVECTOR farPt = XMVector3Unproject(
291 |         XMVectorSet(mouseX, mouseY, 1.0f, 0.0f),
292 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
293 |         proj, view, XMMatrixIdentity());
294 | 
295 |     XMVECTOR dir = XMVector3Normalize(farPt - nearPt);
296 | 
297 |     outOriginX = XMVectorGetX(nearPt);
298 |     outOriginY = XMVectorGetY(nearPt);
299 |     outOriginZ = XMVectorGetZ(nearPt);
300 |     outDirX    = XMVectorGetX(dir);
301 |     outDirY    = XMVectorGetY(dir);
302 |     outDirZ    = XMVectorGetZ(dir);
303 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
EDIT MODE: append-first
INSERT AT LINE: 304
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 279-303
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
- Anchor lines `105-129` (current file tail before insertion at line `130`):
```cpp
105 |     float GetCamY()    const { return m_camY; }
106 |     float GetCamZ()    const { return m_camZ; }
107 |     bool  IsDodgeActive() const { return m_dodgeActive; }
108 | 
109 | private:
110 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_X = 0.3f;
111 |     static constexpr float PLAYER_COLLISION_HALF_HEIGHT = 0.9f;
112 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_Z = 0.3f;
113 | 
114 |     float m_playerX = 0.0f, m_playerY = 0.0f, m_playerZ = -3.0f;
115 |     float m_yaw = 0.0f, m_pitch = 0.0f;
116 |     float m_camX = 0.0f, m_camY = 0.0f, m_camZ = 0.0f;
117 |     float m_velocityY  = 0.0f;
118 |     bool  m_isGrounded = true;
119 |     float m_dodgeVelX = 0.0f;
120 |     float m_dodgeVelZ = 0.0f;
121 |     float m_dodgeTimer = 0.0f;
122 |     bool m_dodgeActive = false;
123 |     POINT m_centerPoint = {};
124 |     const InputActionMap* m_inputActionMap = nullptr;
125 |     const CollisionWorld* m_collisionWorld = nullptr;
126 | 
127 |     // Recompute m_camX/Y/Z from player pos + yaw.
128 |     void ComputeCamFromPlayer();
129 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
EDIT MODE: append-first
INSERT AT LINE: 130
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 105-129
```

- **Task prompt block (copy exactly):**
```text
Implement Task 020: Camera shake.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 021: Combat camera zoom
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 021: Combat camera zoom.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` only
```text
Task 021: Combat camera zoom.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 304.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` only
```text
Task 021: Combat camera zoom.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 130.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 021: Combat camera zoom.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 021: Combat camera zoom.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
- Anchor lines `279-303` (current file tail before insertion at line `304`):
```cpp
279 |         XM_PIDIV4,          // 45-degree vertical FOV (matches DrawTerrainPatch)
280 |         vpW / vpH,
281 |         0.1f, 2000.0f);
282 | 
283 |     // Unproject near and far screen points into world space.
284 |     // XMVector3Unproject arguments: screenPoint, vpX, vpY, vpW, vpH, minZ, maxZ, proj, view, world
285 |     XMVECTOR nearPt = XMVector3Unproject(
286 |         XMVectorSet(mouseX, mouseY, 0.0f, 0.0f),
287 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
288 |         proj, view, XMMatrixIdentity());
289 | 
290 |     XMVECTOR farPt = XMVector3Unproject(
291 |         XMVectorSet(mouseX, mouseY, 1.0f, 0.0f),
292 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
293 |         proj, view, XMMatrixIdentity());
294 | 
295 |     XMVECTOR dir = XMVector3Normalize(farPt - nearPt);
296 | 
297 |     outOriginX = XMVectorGetX(nearPt);
298 |     outOriginY = XMVectorGetY(nearPt);
299 |     outOriginZ = XMVectorGetZ(nearPt);
300 |     outDirX    = XMVectorGetX(dir);
301 |     outDirY    = XMVectorGetY(dir);
302 |     outDirZ    = XMVectorGetZ(dir);
303 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
EDIT MODE: append-first
INSERT AT LINE: 304
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 279-303
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
- Anchor lines `105-129` (current file tail before insertion at line `130`):
```cpp
105 |     float GetCamY()    const { return m_camY; }
106 |     float GetCamZ()    const { return m_camZ; }
107 |     bool  IsDodgeActive() const { return m_dodgeActive; }
108 | 
109 | private:
110 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_X = 0.3f;
111 |     static constexpr float PLAYER_COLLISION_HALF_HEIGHT = 0.9f;
112 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_Z = 0.3f;
113 | 
114 |     float m_playerX = 0.0f, m_playerY = 0.0f, m_playerZ = -3.0f;
115 |     float m_yaw = 0.0f, m_pitch = 0.0f;
116 |     float m_camX = 0.0f, m_camY = 0.0f, m_camZ = 0.0f;
117 |     float m_velocityY  = 0.0f;
118 |     bool  m_isGrounded = true;
119 |     float m_dodgeVelX = 0.0f;
120 |     float m_dodgeVelZ = 0.0f;
121 |     float m_dodgeTimer = 0.0f;
122 |     bool m_dodgeActive = false;
123 |     POINT m_centerPoint = {};
124 |     const InputActionMap* m_inputActionMap = nullptr;
125 |     const CollisionWorld* m_collisionWorld = nullptr;
126 | 
127 |     // Recompute m_camX/Y/Z from player pos + yaw.
128 |     void ComputeCamFromPlayer();
129 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
EDIT MODE: append-first
INSERT AT LINE: 130
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 105-129
```

- **Task prompt block (copy exactly):**
```text
Implement Task 021: Combat camera zoom.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 022: Camera collision avoidance
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 022: Camera collision avoidance.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` only
```text
Task 022: Camera collision avoidance.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 304.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` only
```text
Task 022: Camera collision avoidance.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 130.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 022: Camera collision avoidance.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 022: Camera collision avoidance.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
- Anchor lines `279-303` (current file tail before insertion at line `304`):
```cpp
279 |         XM_PIDIV4,          // 45-degree vertical FOV (matches DrawTerrainPatch)
280 |         vpW / vpH,
281 |         0.1f, 2000.0f);
282 | 
283 |     // Unproject near and far screen points into world space.
284 |     // XMVector3Unproject arguments: screenPoint, vpX, vpY, vpW, vpH, minZ, maxZ, proj, view, world
285 |     XMVECTOR nearPt = XMVector3Unproject(
286 |         XMVectorSet(mouseX, mouseY, 0.0f, 0.0f),
287 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
288 |         proj, view, XMMatrixIdentity());
289 | 
290 |     XMVECTOR farPt = XMVector3Unproject(
291 |         XMVectorSet(mouseX, mouseY, 1.0f, 0.0f),
292 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
293 |         proj, view, XMMatrixIdentity());
294 | 
295 |     XMVECTOR dir = XMVector3Normalize(farPt - nearPt);
296 | 
297 |     outOriginX = XMVectorGetX(nearPt);
298 |     outOriginY = XMVectorGetY(nearPt);
299 |     outOriginZ = XMVectorGetZ(nearPt);
300 |     outDirX    = XMVectorGetX(dir);
301 |     outDirY    = XMVectorGetY(dir);
302 |     outDirZ    = XMVectorGetZ(dir);
303 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
EDIT MODE: append-first
INSERT AT LINE: 304
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 279-303
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
- Anchor lines `105-129` (current file tail before insertion at line `130`):
```cpp
105 |     float GetCamY()    const { return m_camY; }
106 |     float GetCamZ()    const { return m_camZ; }
107 |     bool  IsDodgeActive() const { return m_dodgeActive; }
108 | 
109 | private:
110 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_X = 0.3f;
111 |     static constexpr float PLAYER_COLLISION_HALF_HEIGHT = 0.9f;
112 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_Z = 0.3f;
113 | 
114 |     float m_playerX = 0.0f, m_playerY = 0.0f, m_playerZ = -3.0f;
115 |     float m_yaw = 0.0f, m_pitch = 0.0f;
116 |     float m_camX = 0.0f, m_camY = 0.0f, m_camZ = 0.0f;
117 |     float m_velocityY  = 0.0f;
118 |     bool  m_isGrounded = true;
119 |     float m_dodgeVelX = 0.0f;
120 |     float m_dodgeVelZ = 0.0f;
121 |     float m_dodgeTimer = 0.0f;
122 |     bool m_dodgeActive = false;
123 |     POINT m_centerPoint = {};
124 |     const InputActionMap* m_inputActionMap = nullptr;
125 |     const CollisionWorld* m_collisionWorld = nullptr;
126 | 
127 |     // Recompute m_camX/Y/Z from player pos + yaw.
128 |     void ComputeCamFromPlayer();
129 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
EDIT MODE: append-first
INSERT AT LINE: 130
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 105-129
```

- **Task prompt block (copy exactly):**
```text
Implement Task 022: Camera collision avoidance.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 023: Target framing adjustment
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 023: Target framing adjustment.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` only
```text
Task 023: Target framing adjustment.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 304.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` only
```text
Task 023: Target framing adjustment.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 130.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 023: Target framing adjustment.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 023: Target framing adjustment.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
- Anchor lines `279-303` (current file tail before insertion at line `304`):
```cpp
279 |         XM_PIDIV4,          // 45-degree vertical FOV (matches DrawTerrainPatch)
280 |         vpW / vpH,
281 |         0.1f, 2000.0f);
282 | 
283 |     // Unproject near and far screen points into world space.
284 |     // XMVector3Unproject arguments: screenPoint, vpX, vpY, vpW, vpH, minZ, maxZ, proj, view, world
285 |     XMVECTOR nearPt = XMVector3Unproject(
286 |         XMVectorSet(mouseX, mouseY, 0.0f, 0.0f),
287 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
288 |         proj, view, XMMatrixIdentity());
289 | 
290 |     XMVECTOR farPt = XMVector3Unproject(
291 |         XMVectorSet(mouseX, mouseY, 1.0f, 0.0f),
292 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
293 |         proj, view, XMMatrixIdentity());
294 | 
295 |     XMVECTOR dir = XMVector3Normalize(farPt - nearPt);
296 | 
297 |     outOriginX = XMVectorGetX(nearPt);
298 |     outOriginY = XMVectorGetY(nearPt);
299 |     outOriginZ = XMVectorGetZ(nearPt);
300 |     outDirX    = XMVectorGetX(dir);
301 |     outDirY    = XMVectorGetY(dir);
302 |     outDirZ    = XMVectorGetZ(dir);
303 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
EDIT MODE: append-first
INSERT AT LINE: 304
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 279-303
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
- Anchor lines `105-129` (current file tail before insertion at line `130`):
```cpp
105 |     float GetCamY()    const { return m_camY; }
106 |     float GetCamZ()    const { return m_camZ; }
107 |     bool  IsDodgeActive() const { return m_dodgeActive; }
108 | 
109 | private:
110 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_X = 0.3f;
111 |     static constexpr float PLAYER_COLLISION_HALF_HEIGHT = 0.9f;
112 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_Z = 0.3f;
113 | 
114 |     float m_playerX = 0.0f, m_playerY = 0.0f, m_playerZ = -3.0f;
115 |     float m_yaw = 0.0f, m_pitch = 0.0f;
116 |     float m_camX = 0.0f, m_camY = 0.0f, m_camZ = 0.0f;
117 |     float m_velocityY  = 0.0f;
118 |     bool  m_isGrounded = true;
119 |     float m_dodgeVelX = 0.0f;
120 |     float m_dodgeVelZ = 0.0f;
121 |     float m_dodgeTimer = 0.0f;
122 |     bool m_dodgeActive = false;
123 |     POINT m_centerPoint = {};
124 |     const InputActionMap* m_inputActionMap = nullptr;
125 |     const CollisionWorld* m_collisionWorld = nullptr;
126 | 
127 |     // Recompute m_camX/Y/Z from player pos + yaw.
128 |     void ComputeCamFromPlayer();
129 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
EDIT MODE: append-first
INSERT AT LINE: 130
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 105-129
```

- **Task prompt block (copy exactly):**
```text
Implement Task 023: Target framing adjustment.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 024: Lock-on camera recovery smoothing
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 024: Lock-on camera recovery smoothing.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` only
```text
Task 024: Lock-on camera recovery smoothing.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 304.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` only
```text
Task 024: Lock-on camera recovery smoothing.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 130.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 024: Lock-on camera recovery smoothing.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 024: Lock-on camera recovery smoothing.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
- Anchor lines `279-303` (current file tail before insertion at line `304`):
```cpp
279 |         XM_PIDIV4,          // 45-degree vertical FOV (matches DrawTerrainPatch)
280 |         vpW / vpH,
281 |         0.1f, 2000.0f);
282 | 
283 |     // Unproject near and far screen points into world space.
284 |     // XMVector3Unproject arguments: screenPoint, vpX, vpY, vpW, vpH, minZ, maxZ, proj, view, world
285 |     XMVECTOR nearPt = XMVector3Unproject(
286 |         XMVectorSet(mouseX, mouseY, 0.0f, 0.0f),
287 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
288 |         proj, view, XMMatrixIdentity());
289 | 
290 |     XMVECTOR farPt = XMVector3Unproject(
291 |         XMVectorSet(mouseX, mouseY, 1.0f, 0.0f),
292 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
293 |         proj, view, XMMatrixIdentity());
294 | 
295 |     XMVECTOR dir = XMVector3Normalize(farPt - nearPt);
296 | 
297 |     outOriginX = XMVectorGetX(nearPt);
298 |     outOriginY = XMVectorGetY(nearPt);
299 |     outOriginZ = XMVectorGetZ(nearPt);
300 |     outDirX    = XMVectorGetX(dir);
301 |     outDirY    = XMVectorGetY(dir);
302 |     outDirZ    = XMVectorGetZ(dir);
303 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
EDIT MODE: append-first
INSERT AT LINE: 304
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 279-303
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
- Anchor lines `105-129` (current file tail before insertion at line `130`):
```cpp
105 |     float GetCamY()    const { return m_camY; }
106 |     float GetCamZ()    const { return m_camZ; }
107 |     bool  IsDodgeActive() const { return m_dodgeActive; }
108 | 
109 | private:
110 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_X = 0.3f;
111 |     static constexpr float PLAYER_COLLISION_HALF_HEIGHT = 0.9f;
112 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_Z = 0.3f;
113 | 
114 |     float m_playerX = 0.0f, m_playerY = 0.0f, m_playerZ = -3.0f;
115 |     float m_yaw = 0.0f, m_pitch = 0.0f;
116 |     float m_camX = 0.0f, m_camY = 0.0f, m_camZ = 0.0f;
117 |     float m_velocityY  = 0.0f;
118 |     bool  m_isGrounded = true;
119 |     float m_dodgeVelX = 0.0f;
120 |     float m_dodgeVelZ = 0.0f;
121 |     float m_dodgeTimer = 0.0f;
122 |     bool m_dodgeActive = false;
123 |     POINT m_centerPoint = {};
124 |     const InputActionMap* m_inputActionMap = nullptr;
125 |     const CollisionWorld* m_collisionWorld = nullptr;
126 | 
127 |     // Recompute m_camX/Y/Z from player pos + yaw.
128 |     void ComputeCamFromPlayer();
129 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
EDIT MODE: append-first
INSERT AT LINE: 130
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 105-129
```

- **Task prompt block (copy exactly):**
```text
Implement Task 024: Lock-on camera recovery smoothing.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 025: Wind effect on trees
- **Original scope token(s):** `Shaders/tree_vs.hlsl`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl` | yes | 39 | 40 | 20 | 35 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl` and stop so a human can paste them manually.
3. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
4. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 4: Read task card only
```text
Task 025: Wind effect on trees.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 4: Edit `/home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl` only
```text
Task 025: Wind effect on trees.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 40.
Max existing lines to modify: 20.
Target new lines to add: 35.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 4: Update docs only
```text
Task 025: Wind effect on trees.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 4 / 4: Complete task guard
```text
Task 025: Wind effect on trees.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl`
- Anchor lines `15-39` (current file tail before insertion at line `40`):
```hlsl
15 | struct VSIn
16 | {
17 |     float3 pos    : POSITION;
18 |     float3 normal : NORMAL;
19 |     float4 col    : COLOR;
20 | };
21 | 
22 | struct VSOut
23 | {
24 |     float4 svPos     : SV_POSITION;
25 |     float3 worldPos  : TEXCOORD0; // world-space position for gradient
26 |     float3 worldNorm : NORMAL;
27 |     float4 col       : COLOR;
28 | };
29 | 
30 | VSOut main(VSIn input)
31 | {
32 |     VSOut o;
33 |     float4 worldPos4 = mul(float4(input.pos, 1.0f), world);
34 |     o.svPos     = mul(float4(input.pos, 1.0f), mvp);
35 |     o.worldPos  = worldPos4.xyz;
36 |     o.worldNorm = normalize(mul(float4(input.normal, 0.0f), world).xyz);
37 |     o.col       = input.col;
38 |     return o;
39 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/Shaders/tree_vs.hlsl
EDIT MODE: append-first
INSERT AT LINE: 40
MAX EXISTING LINES TO MODIFY: 20
TARGET NEW LINES TO ADD: 35
ANCHOR RANGE: 15-39
```

- **Task prompt block (copy exactly):**
```text
Implement Task 025: Wind effect on trees.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 026: Weather system lite
- **Original scope token(s):** `src/world/WeatherSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 026: Weather system lite.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp` only
```text
Task 026: Weather system lite.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp` only
```text
Task 026: Weather system lite.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 026: Weather system lite.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 026: Weather system lite.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WeatherSystem.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 026: Weather system lite.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 027: Ambient particles
- **Original scope token(s):** `src/game/ParticleSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 027: Ambient particles.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp` only
```text
Task 027: Ambient particles.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp` only
```text
Task 027: Ambient particles.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 027: Ambient particles.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 027: Ambient particles.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/ParticleSystem.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 027: Ambient particles.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 028: Day/night cycle
- **Original scope token(s):** `src/world/DayNightCycle.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 028: Day/night cycle.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp` only
```text
Task 028: Day/night cycle.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp` only
```text
Task 028: Day/night cycle.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 028: Day/night cycle.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 028: Day/night cycle.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/DayNightCycle.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 028: Day/night cycle.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 029: Biome transition fade
- **Original scope token(s):** `src/world/WorldGrid.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` | yes | 353 | 354 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` | yes | 111 | 112 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 029: Biome transition fade.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` only
```text
Task 029: Biome transition fade.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 354.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` only
```text
Task 029: Biome transition fade.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 112.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 029: Biome transition fade.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 029: Biome transition fade.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
- Anchor lines `329-353` (current file tail before insertion at line `354`):
```cpp
329 |     }
330 |     catch (const std::exception& e)
331 |     {
332 |         LOG_ERROR(std::string("WorldGrid::SaveCell: write error: ") + e.what());
333 |         return false;
334 |     }
335 | 
336 |     // std::ofstream write failures typically set failbit/badbit rather than throwing.
337 |     // Always check the stream state after writing, regardless of exceptions.
338 |     if (!out.good())
339 |     {
340 |         std::ostringstream streamErr;
341 |         streamErr << "WorldGrid::SaveCell: stream error after write to '"
342 |                   << cell->filePath
343 |                   << "' (disk full, permission denied, or IO error).";
344 |         LOG_ERROR(streamErr.str());
345 |         return false;
346 |     }
347 | 
348 |     std::ostringstream ss;
349 |     ss << "WorldGrid::SaveCell: saved cell (" << cx << "," << cz << ") to '"
350 |        << cell->filePath << "' with " << cell->instances.size() << " instance(s).";
351 |     LOG_INFO(ss.str());
352 |     return true;
353 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp
EDIT MODE: append-first
INSERT AT LINE: 354
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 329-353
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp`
- Anchor lines `87-111` (current file tail before insertion at line `112`):
```cpp
 87 |     // radius=1 gives a 3x3 block of cells (9 max), radius=0 gives only the player cell.
 88 |     std::vector<WorldCell> GetActiveCells(int playerCX, int playerCZ, int radius = 1) const;
 89 | 
 90 |     // Convert a world-space (X, Z) position into a cell grid coordinate.
 91 |     void WorldToCell(float worldX, float worldZ, int& outCX, int& outCZ) const;
 92 | 
 93 |     float       GetCellSize() const  { return m_cellSize; }
 94 |     const std::string& GetName() const { return m_name; }
 95 |     int         CellCount()  const  { return static_cast<int>(m_cells.size()); }
 96 | 
 97 |     // Returns a mutable pointer to the cell at (cx,cz), or nullptr if not found.
 98 |     WorldCell* FindCell(int cx, int cz);
 99 | 
100 |     // Write the cell at (cx,cz) back to its JSON file (preserving terrain/forest settings).
101 |     // Returns true on success; logs an error and keeps in-memory data on failure.
102 |     bool SaveCell(int cx, int cz);
103 | 
104 | private:
105 |     bool LoadCellFile(const std::string& path, WorldCell& out);
106 | 
107 |     std::string           m_worldJsonPath;
108 |     std::string           m_name;
109 |     float                 m_cellSize = 200.0f;
110 |     std::vector<WorldCell> m_cells;
111 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp
EDIT MODE: append-first
INSERT AT LINE: 112
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 87-111
```

- **Task prompt block (copy exactly):**
```text
Implement Task 029: Biome transition fade.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 030: Fog of war on minimap
- **Original scope token(s):** `src/ui/Minimap.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp` | yes | 148 | 149 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp` | yes | 27 | 28 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 030: Fog of war on minimap.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp` only
```text
Task 030: Fog of war on minimap.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 149.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp` only
```text
Task 030: Fog of war on minimap.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 28.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 030: Fog of war on minimap.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 030: Fog of war on minimap.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp`
- Anchor lines `124-148` (current file tail before insertion at line `149`):
```cpp
124 |     const float cellSize = grid.GetCellSize();
125 |     const float fracX = (playerX - static_cast<float>(playerCX) * cellSize) / cellSize;
126 |     const float fracZ = (playerZ - static_cast<float>(playerCZ) * cellSize) / cellSize;
127 | 
128 |     // Map to pixel coordinates. The player's cell occupies column/row kGridRadius.
129 |     const float playerPxX = origin.x + (static_cast<float>(kGridRadius) + fracX) * kCellPx;
130 |     const float playerPxY = origin.y + (static_cast<float>(kGridRadius) + fracZ) * kCellPx;
131 | 
132 |     // Facing direction: forward = (sin(yaw), cos(yaw)) in world XZ.
133 |     // On the minimap X maps to screen-right, Z maps to screen-down.
134 |     const float arrowLen = kCellPx * 0.45f;
135 |     const float arrowDX  = sinf(playerYaw) * arrowLen;
136 |     const float arrowDY  = cosf(playerYaw) * arrowLen;
137 | 
138 |     // Direction line from player dot toward facing direction.
139 |     draw->AddLine(
140 |         ImVec2(playerPxX, playerPxY),
141 |         ImVec2(playerPxX + arrowDX, playerPxY + arrowDY),
142 |         IM_COL32(255, 255, 255, 255), 2.0f);
143 | 
144 |     // Player position dot drawn on top of the direction line.
145 |     draw->AddCircleFilled(ImVec2(playerPxX, playerPxY), 4.0f, IM_COL32(255, 255, 255, 255));
146 | 
147 |     ImGui::End();
148 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.cpp
EDIT MODE: append-first
INSERT AT LINE: 149
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 124-148
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp`
- Anchor lines `3-27` (current file tail before insertion at line `28`):
```cpp
 3 | // SYSTEM: UI
 4 | // ROLE: HUD, menus, overlays, and editor tool panels
 5 | // DO NOT: Modify unrelated systems or break subsystem boundaries.
 6 | // OWNS: Minimap module behavior and local implementation details.
 7 | // ============================================================
 8 | 
 9 | #pragma once
10 | // Minimap.hpp
11 | // Draws a 160x160 minimap overlay in the top-right corner using ImGui draw lists.
12 | // Shows nearby world cells colored by biome, plus the player position and facing direction.
13 | 
14 | struct ImGuiIO;
15 | class WorldGrid;
16 | 
17 | class Minimap
18 | {
19 | public:
20 |     // Draw the minimap for this frame.
21 |     // Call inside an active ImGui frame (between BeginFrame / EndFrame).
22 |     // playerX, playerZ — world-space player position.
23 |     // playerYaw        — player facing angle in radians (same convention as CameraController::GetYaw()).
24 |     void Draw(const WorldGrid& grid,
25 |               float playerX, float playerZ, float playerYaw,
26 |               const ImGuiIO& io);
27 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/Minimap.hpp
EDIT MODE: append-first
INSERT AT LINE: 28
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 3-27
```

- **Task prompt block (copy exactly):**
```text
Implement Task 030: Fog of war on minimap.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 031: World event trigger zones
- **Original scope token(s):** `src/game/world/EventZone.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 031: World event trigger zones.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp` only
```text
Task 031: World event trigger zones.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp` only
```text
Task 031: World event trigger zones.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 031: World event trigger zones.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 031: World event trigger zones.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/EventZone.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 031: World event trigger zones.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 032: Interaction hotspot registry stub
- **Original scope token(s):** `src/game/world/InteractionRegistry.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 032: Interaction hotspot registry stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` only
```text
Task 032: Interaction hotspot registry stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` only
```text
Task 032: Interaction hotspot registry stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 032: Interaction hotspot registry stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 032: Interaction hotspot registry stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 032: Interaction hotspot registry stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 033: Landmark discovery trigger stub
- **Original scope token(s):** `src/game/world/LandmarkTrigger.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 033: Landmark discovery trigger stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp` only
```text
Task 033: Landmark discovery trigger stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp` only
```text
Task 033: Landmark discovery trigger stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 033: Landmark discovery trigger stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 033: Landmark discovery trigger stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/LandmarkTrigger.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 033: Landmark discovery trigger stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 034: NPC actor
- **Original scope token(s):** `src/game/actors/NpcActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 034: NPC actor.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp` only
```text
Task 034: NPC actor.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp` only
```text
Task 034: NPC actor.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 034: NPC actor.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 034: NPC actor.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/NpcActor.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 034: NPC actor.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 035: Quest objective system
- **Original scope token(s):** `src/game/quest/QuestSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 035: Quest objective system.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` only
```text
Task 035: Quest objective system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` only
```text
Task 035: Quest objective system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 035: Quest objective system.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 035: Quest objective system.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 035: Quest objective system.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 036: Treasure chest actor
- **Original scope token(s):** `src/game/actors/ChestActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 036: Treasure chest actor.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp` only
```text
Task 036: Treasure chest actor.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp` only
```text
Task 036: Treasure chest actor.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 036: Treasure chest actor.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 036: Treasure chest actor.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/ChestActor.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 036: Treasure chest actor.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 037: Campfire / rest point actor
- **Original scope token(s):** `src/game/actors/RestPointActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 037: Campfire / rest point actor.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp` only
```text
Task 037: Campfire / rest point actor.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp` only
```text
Task 037: Campfire / rest point actor.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 037: Campfire / rest point actor.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 037: Campfire / rest point actor.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/RestPointActor.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 037: Campfire / rest point actor.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 038: NPC interaction prompt routing stub
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`, `src/game/world/InteractionRegistry.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` and stop.
5. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` and stop.
6. Run docs updates as three one-file prompts only: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
7. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 7: Read task card only
```text
Task 038: NPC interaction prompt routing stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 038: NPC interaction prompt routing stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 038: NPC interaction prompt routing stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 7: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp` only
```text
Task 038: NPC interaction prompt routing stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 7: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp` only
```text
Task 038: NPC interaction prompt routing stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 7: Update docs only
```text
Task 038: NPC interaction prompt routing stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 7 / 7: Complete task guard
```text
Task 038: NPC interaction prompt routing stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/InteractionRegistry.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 038: NPC interaction prompt routing stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 039: Quest flag / world-state hook
- **Original scope token(s):** `src/game/quest/QuestFlags.hpp`, `src/game/quest/QuestSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` and stop.
4. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` and stop.
5. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
6. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 6: Read task card only
```text
Task 039: Quest flag / world-state hook.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 6: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp` only
```text
Task 039: Quest flag / world-state hook.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 6: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp` only
```text
Task 039: Quest flag / world-state hook.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 6: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp` only
```text
Task 039: Quest flag / world-state hook.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 6: Update docs only
```text
Task 039: Quest flag / world-state hook.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 6 / 6: Complete task guard
```text
Task 039: Quest flag / world-state hook.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestFlags.hpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/quest/QuestSystem.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 039: Quest flag / world-state hook.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 040: Spawn composition table stub (solo / pair / pack)
- **Original scope token(s):** `src/world/SpawnTable.hpp`, `src/world/WorldGrid.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` | yes | 353 | 354 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` | yes | 111 | 112 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp` and stop.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` and stop so a human can paste them manually.
5. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
6. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 6: Read task card only
```text
Task 040: Spawn composition table stub (solo / pair / pack).
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 6: Create `/home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp` only
```text
Task 040: Spawn composition table stub (solo / pair / pack).
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 6: Edit `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` only
```text
Task 040: Spawn composition table stub (solo / pair / pack).
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 354.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 6: Edit `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` only
```text
Task 040: Spawn composition table stub (solo / pair / pack).
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 112.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 6: Update docs only
```text
Task 040: Spawn composition table stub (solo / pair / pack).
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 6 / 6: Complete task guard
```text
Task 040: Spawn composition table stub (solo / pair / pack).
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/SpawnTable.hpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
- Anchor lines `329-353` (current file tail before insertion at line `354`):
```cpp
329 |     }
330 |     catch (const std::exception& e)
331 |     {
332 |         LOG_ERROR(std::string("WorldGrid::SaveCell: write error: ") + e.what());
333 |         return false;
334 |     }
335 | 
336 |     // std::ofstream write failures typically set failbit/badbit rather than throwing.
337 |     // Always check the stream state after writing, regardless of exceptions.
338 |     if (!out.good())
339 |     {
340 |         std::ostringstream streamErr;
341 |         streamErr << "WorldGrid::SaveCell: stream error after write to '"
342 |                   << cell->filePath
343 |                   << "' (disk full, permission denied, or IO error).";
344 |         LOG_ERROR(streamErr.str());
345 |         return false;
346 |     }
347 | 
348 |     std::ostringstream ss;
349 |     ss << "WorldGrid::SaveCell: saved cell (" << cx << "," << cz << ") to '"
350 |        << cell->filePath << "' with " << cell->instances.size() << " instance(s).";
351 |     LOG_INFO(ss.str());
352 |     return true;
353 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp
EDIT MODE: append-first
INSERT AT LINE: 354
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 329-353
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp`
- Anchor lines `87-111` (current file tail before insertion at line `112`):
```cpp
 87 |     // radius=1 gives a 3x3 block of cells (9 max), radius=0 gives only the player cell.
 88 |     std::vector<WorldCell> GetActiveCells(int playerCX, int playerCZ, int radius = 1) const;
 89 | 
 90 |     // Convert a world-space (X, Z) position into a cell grid coordinate.
 91 |     void WorldToCell(float worldX, float worldZ, int& outCX, int& outCZ) const;
 92 | 
 93 |     float       GetCellSize() const  { return m_cellSize; }
 94 |     const std::string& GetName() const { return m_name; }
 95 |     int         CellCount()  const  { return static_cast<int>(m_cells.size()); }
 96 | 
 97 |     // Returns a mutable pointer to the cell at (cx,cz), or nullptr if not found.
 98 |     WorldCell* FindCell(int cx, int cz);
 99 | 
100 |     // Write the cell at (cx,cz) back to its JSON file (preserving terrain/forest settings).
101 |     // Returns true on success; logs an error and keeps in-memory data on failure.
102 |     bool SaveCell(int cx, int cz);
103 | 
104 | private:
105 |     bool LoadCellFile(const std::string& path, WorldCell& out);
106 | 
107 |     std::string           m_worldJsonPath;
108 |     std::string           m_name;
109 |     float                 m_cellSize = 200.0f;
110 |     std::vector<WorldCell> m_cells;
111 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp
EDIT MODE: append-first
INSERT AT LINE: 112
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 87-111
```

- **Task prompt block (copy exactly):**
```text
Implement Task 040: Spawn composition table stub (solo / pair / pack).
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 041: Inventory system
- **Original scope token(s):** `src/game/inventory/Inventory.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 041: Inventory system.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp` only
```text
Task 041: Inventory system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp` only
```text
Task 041: Inventory system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 041: Inventory system.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 041: Inventory system.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Inventory.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 041: Inventory system.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 042: XP / level system
- **Original scope token(s):** `src/game/actors/PlayerStats.hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` and stop so a human can paste them manually.
3. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
4. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 4: Read task card only
```text
Task 042: XP / level system.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 4: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` only
```text
Task 042: XP / level system.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 86.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 4: Update docs only
```text
Task 042: XP / level system.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 4 / 4: Complete task guard
```text
Task 042: XP / level system.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
- Anchor lines `61-85` (current file tail before insertion at line `86`):
```cpp
61 | 
62 |     bool IsLimitReady() const { return limitCharge >= 1.0f; }
63 | 
64 |     // Reduce HP by amount; clamps to zero. Also advances the Limit gauge.
65 |     // Safe to call with zero or positive values only.
66 |     void TakeDamage(int amount)
67 |     {
68 |         if (amount <= 0)
69 |             return;
70 |         hp = std::clamp(hp - static_cast<float>(amount), 0.0f, maxHp);
71 |         AddLimitCharge(kLimitChargePerHit);
72 |     }
73 | 
74 |     bool IsDead() const { return hp <= 0.0f; }
75 | 
76 |     // Restore all combat resources to their full starting values.
77 |     // Call on player defeat / respawn.
78 |     void Reset()
79 |     {
80 |         hp           = maxHp;
81 |         mp           = maxMp;
82 |         surgeCharge  = 0.0f;
83 |         limitCharge  = 0.0f;
84 |     }
85 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
EDIT MODE: append-first
INSERT AT LINE: 86
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 61-85
```

- **Task prompt block (copy exactly):**
```text
Implement Task 042: XP / level system.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 043: Status effects
- **Original scope token(s):** `src/game/actors/PlayerStats.hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` and stop so a human can paste them manually.
3. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
4. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 4: Read task card only
```text
Task 043: Status effects.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 4: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` only
```text
Task 043: Status effects.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 86.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 4: Update docs only
```text
Task 043: Status effects.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 4 / 4: Complete task guard
```text
Task 043: Status effects.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
- Anchor lines `61-85` (current file tail before insertion at line `86`):
```cpp
61 | 
62 |     bool IsLimitReady() const { return limitCharge >= 1.0f; }
63 | 
64 |     // Reduce HP by amount; clamps to zero. Also advances the Limit gauge.
65 |     // Safe to call with zero or positive values only.
66 |     void TakeDamage(int amount)
67 |     {
68 |         if (amount <= 0)
69 |             return;
70 |         hp = std::clamp(hp - static_cast<float>(amount), 0.0f, maxHp);
71 |         AddLimitCharge(kLimitChargePerHit);
72 |     }
73 | 
74 |     bool IsDead() const { return hp <= 0.0f; }
75 | 
76 |     // Restore all combat resources to their full starting values.
77 |     // Call on player defeat / respawn.
78 |     void Reset()
79 |     {
80 |         hp           = maxHp;
81 |         mp           = maxMp;
82 |         surgeCharge  = 0.0f;
83 |         limitCharge  = 0.0f;
84 |     }
85 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
EDIT MODE: append-first
INSERT AT LINE: 86
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 61-85
```

- **Task prompt block (copy exactly):**
```text
Implement Task 043: Status effects.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 044: Fast travel stub
- **Original scope token(s):** `src/game/world/FastTravel.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 044: Fast travel stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp` only
```text
Task 044: Fast travel stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp` only
```text
Task 044: Fast travel stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 044: Fast travel stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 044: Fast travel stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/world/FastTravel.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 044: Fast travel stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 045: Save / load system
- **Original scope token(s):** `src/app/SaveSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 045: Save / load system.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp` only
```text
Task 045: Save / load system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp` only
```text
Task 045: Save / load system.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 045: Save / load system.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 045: Save / load system.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/SaveSystem.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 045: Save / load system.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 046: Quality preset enforcement
- **Original scope token(s):** `src/app/QualityPreset.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` | no | 0 | 1 | 0 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` and stop.
3. Create only `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` and stop.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 046: Quality preset enforcement.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` only
```text
Task 046: Quality preset enforcement.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` only
```text
Task 046: Quality preset enforcement.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 046: Quality preset enforcement.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 046: Quality preset enforcement.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp
Add new code at line 1.
```

- **Task prompt block (copy exactly):**
```text
Implement Task 046: Quality preset enforcement.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 047: Victory fanfare trigger
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 047: Victory fanfare trigger.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` only
```text
Task 047: Victory fanfare trigger.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 104.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` only
```text
Task 047: Victory fanfare trigger.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 39.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 047: Victory fanfare trigger.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 047: Victory fanfare trigger.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
- Anchor lines `79-103` (current file tail before insertion at line `104`):
```cpp
 79 | 
 80 |     if (!tp::Audio::PlayOneShot(path))
 81 |     {
 82 |         LogPlayFailure("SFX", path);
 83 |         return false;
 84 |     }
 85 | 
 86 |     return true;
 87 | }
 88 | 
 89 | void AudioManager::SetBGMVolume(float v)
 90 | {
 91 |     m_bgmVolume = Clamp01(v);
 92 | }
 93 | 
 94 | void AudioManager::SetSFXVolume(float v)
 95 | {
 96 |     m_sfxVolume = Clamp01(v);
 97 | }
 98 | 
 99 | void AudioManager::Shutdown()
100 | {
101 |     if (m_bgmRequested)
102 |         StopBGM();
103 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
EDIT MODE: append-first
INSERT AT LINE: 104
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 79-103
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
- Anchor lines `14-38` (current file tail before insertion at line `39`):
```cpp
14 | {
15 | public:
16 |     // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
17 |     bool PlayBGM(const std::string& path);
18 |     // Clears AudioManager's tracked BGM state.
19 |     // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
20 |     void StopBGM();
21 |     bool PlaySFX(const std::string& path);
22 | 
23 |     void SetBGMVolume(float v);
24 |     void SetSFXVolume(float v);
25 |     float GetBGMVolume() const { return m_bgmVolume; }
26 |     float GetSFXVolume() const { return m_sfxVolume; }
27 | 
28 |     void Shutdown();
29 | 
30 | private:
31 |     static float Clamp01(float v);
32 | 
33 |     float m_bgmVolume = 1.0f;
34 |     float m_sfxVolume = 1.0f;
35 |     bool m_loggedBgmVolumeLimit = false;
36 |     bool m_loggedSfxVolumeLimit = false;
37 |     bool m_bgmRequested = false;
38 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
EDIT MODE: append-first
INSERT AT LINE: 39
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 14-38
```

- **Task prompt block (copy exactly):**
```text
Implement Task 047: Victory fanfare trigger.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 048: Environmental ambient audio
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 048: Environmental ambient audio.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` only
```text
Task 048: Environmental ambient audio.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 104.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` only
```text
Task 048: Environmental ambient audio.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 39.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 048: Environmental ambient audio.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 048: Environmental ambient audio.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
- Anchor lines `79-103` (current file tail before insertion at line `104`):
```cpp
 79 | 
 80 |     if (!tp::Audio::PlayOneShot(path))
 81 |     {
 82 |         LogPlayFailure("SFX", path);
 83 |         return false;
 84 |     }
 85 | 
 86 |     return true;
 87 | }
 88 | 
 89 | void AudioManager::SetBGMVolume(float v)
 90 | {
 91 |     m_bgmVolume = Clamp01(v);
 92 | }
 93 | 
 94 | void AudioManager::SetSFXVolume(float v)
 95 | {
 96 |     m_sfxVolume = Clamp01(v);
 97 | }
 98 | 
 99 | void AudioManager::Shutdown()
100 | {
101 |     if (m_bgmRequested)
102 |         StopBGM();
103 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
EDIT MODE: append-first
INSERT AT LINE: 104
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 79-103
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
- Anchor lines `14-38` (current file tail before insertion at line `39`):
```cpp
14 | {
15 | public:
16 |     // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
17 |     bool PlayBGM(const std::string& path);
18 |     // Clears AudioManager's tracked BGM state.
19 |     // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
20 |     void StopBGM();
21 |     bool PlaySFX(const std::string& path);
22 | 
23 |     void SetBGMVolume(float v);
24 |     void SetSFXVolume(float v);
25 |     float GetBGMVolume() const { return m_bgmVolume; }
26 |     float GetSFXVolume() const { return m_sfxVolume; }
27 | 
28 |     void Shutdown();
29 | 
30 | private:
31 |     static float Clamp01(float v);
32 | 
33 |     float m_bgmVolume = 1.0f;
34 |     float m_sfxVolume = 1.0f;
35 |     bool m_loggedBgmVolumeLimit = false;
36 |     bool m_loggedSfxVolumeLimit = false;
37 |     bool m_bgmRequested = false;
38 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
EDIT MODE: append-first
INSERT AT LINE: 39
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 14-38
```

- **Task prompt block (copy exactly):**
```text
Implement Task 048: Environmental ambient audio.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 049: Looping BGM
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 049: Looping BGM.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` only
```text
Task 049: Looping BGM.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 104.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` only
```text
Task 049: Looping BGM.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 39.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 049: Looping BGM.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 049: Looping BGM.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
- Anchor lines `79-103` (current file tail before insertion at line `104`):
```cpp
 79 | 
 80 |     if (!tp::Audio::PlayOneShot(path))
 81 |     {
 82 |         LogPlayFailure("SFX", path);
 83 |         return false;
 84 |     }
 85 | 
 86 |     return true;
 87 | }
 88 | 
 89 | void AudioManager::SetBGMVolume(float v)
 90 | {
 91 |     m_bgmVolume = Clamp01(v);
 92 | }
 93 | 
 94 | void AudioManager::SetSFXVolume(float v)
 95 | {
 96 |     m_sfxVolume = Clamp01(v);
 97 | }
 98 | 
 99 | void AudioManager::Shutdown()
100 | {
101 |     if (m_bgmRequested)
102 |         StopBGM();
103 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
EDIT MODE: append-first
INSERT AT LINE: 104
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 79-103
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
- Anchor lines `14-38` (current file tail before insertion at line `39`):
```cpp
14 | {
15 | public:
16 |     // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
17 |     bool PlayBGM(const std::string& path);
18 |     // Clears AudioManager's tracked BGM state.
19 |     // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
20 |     void StopBGM();
21 |     bool PlaySFX(const std::string& path);
22 | 
23 |     void SetBGMVolume(float v);
24 |     void SetSFXVolume(float v);
25 |     float GetBGMVolume() const { return m_bgmVolume; }
26 |     float GetSFXVolume() const { return m_sfxVolume; }
27 | 
28 |     void Shutdown();
29 | 
30 | private:
31 |     static float Clamp01(float v);
32 | 
33 |     float m_bgmVolume = 1.0f;
34 |     float m_sfxVolume = 1.0f;
35 |     bool m_loggedBgmVolumeLimit = false;
36 |     bool m_loggedSfxVolumeLimit = false;
37 |     bool m_bgmRequested = false;
38 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
EDIT MODE: append-first
INSERT AT LINE: 39
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 14-38
```

- **Task prompt block (copy exactly):**
```text
Implement Task 049: Looping BGM.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 050: Tactical Pause enter / exit SFX
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` | yes | 139 | 140 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` | yes | 28 | 29 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` and stop so a human can paste them manually.
6. Run docs updates as three one-file prompts only: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
7. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 7: Read task card only
```text
Task 050: Tactical Pause enter / exit SFX.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` only
```text
Task 050: Tactical Pause enter / exit SFX.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 104.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` only
```text
Task 050: Tactical Pause enter / exit SFX.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 39.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` only
```text
Task 050: Tactical Pause enter / exit SFX.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 140.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` only
```text
Task 050: Tactical Pause enter / exit SFX.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 29.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 7: Update docs only
```text
Task 050: Tactical Pause enter / exit SFX.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 7 / 7: Complete task guard
```text
Task 050: Tactical Pause enter / exit SFX.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
- Anchor lines `79-103` (current file tail before insertion at line `104`):
```cpp
 79 | 
 80 |     if (!tp::Audio::PlayOneShot(path))
 81 |     {
 82 |         LogPlayFailure("SFX", path);
 83 |         return false;
 84 |     }
 85 | 
 86 |     return true;
 87 | }
 88 | 
 89 | void AudioManager::SetBGMVolume(float v)
 90 | {
 91 |     m_bgmVolume = Clamp01(v);
 92 | }
 93 | 
 94 | void AudioManager::SetSFXVolume(float v)
 95 | {
 96 |     m_sfxVolume = Clamp01(v);
 97 | }
 98 | 
 99 | void AudioManager::Shutdown()
100 | {
101 |     if (m_bgmRequested)
102 |         StopBGM();
103 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
EDIT MODE: append-first
INSERT AT LINE: 104
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 79-103
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
- Anchor lines `14-38` (current file tail before insertion at line `39`):
```cpp
14 | {
15 | public:
16 |     // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
17 |     bool PlayBGM(const std::string& path);
18 |     // Clears AudioManager's tracked BGM state.
19 |     // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
20 |     void StopBGM();
21 |     bool PlaySFX(const std::string& path);
22 | 
23 |     void SetBGMVolume(float v);
24 |     void SetSFXVolume(float v);
25 |     float GetBGMVolume() const { return m_bgmVolume; }
26 |     float GetSFXVolume() const { return m_sfxVolume; }
27 | 
28 |     void Shutdown();
29 | 
30 | private:
31 |     static float Clamp01(float v);
32 | 
33 |     float m_bgmVolume = 1.0f;
34 |     float m_sfxVolume = 1.0f;
35 |     bool m_loggedBgmVolumeLimit = false;
36 |     bool m_loggedSfxVolumeLimit = false;
37 |     bool m_bgmRequested = false;
38 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
EDIT MODE: append-first
INSERT AT LINE: 39
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 14-38
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp`
- Anchor lines `115-139` (current file tail before insertion at line `140`):
```cpp
115 |             ImGui::PushStyleColor(ImGuiCol_Text, kReadyColor);
116 | 
117 |         if (DrawCommandRow("  Surge Strike", surgeReady, surgeReady ? nullptr : "Need Surge"))
118 |             selectedCommand = TacticalCommand::SurgeStrike;
119 | 
120 |         if (surgeReady)
121 |             ImGui::PopStyleColor();
122 | 
123 |         // Stub commands — reserved for later milestones.
124 |         DrawCommandRow(kMagicLabel, false, "No MP");
125 |         DrawCommandRow(kItemsLabel, false, "Coming soon");
126 |         DrawCommandRow(kAllyLabel,  false, "Coming soon");
127 | 
128 |         ImGui::EndTable();
129 |     }
130 | 
131 |     // --- Footer hint ---
132 |     ImGui::Spacing();
133 |     ImGui::Separator();
134 |     ImGui::Spacing();
135 |     ImGui::TextColored(kHintColor, "Release Tab to resume");
136 | 
137 |     ImGui::End();
138 |     return selectedCommand;
139 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp
EDIT MODE: append-first
INSERT AT LINE: 140
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 115-139
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp`
- Anchor lines `4-28` (current file tail before insertion at line `29`):
```cpp
 4 | // ROLE: HUD, menus, overlays, and editor tool panels
 5 | // DO NOT: Modify unrelated systems or break subsystem boundaries.
 6 | // OWNS: TacticalPauseMenu module behavior and local implementation details.
 7 | // ============================================================
 8 | 
 9 | #pragma once
10 | // TacticalPauseMenu.hpp
11 | // Draws the FF-style Tactical Pause command panel while Tab is held.
12 | // Returns the command activated this frame so Main.cpp can execute it.
13 | 
14 | struct PlayerStats;
15 | struct ImGuiIO;
16 | 
17 | // Commands that can be activated from the Tactical Pause panel.
18 | // None means no command was chosen this frame.
19 | enum class TacticalCommand { None, SurgeStrike };
20 | 
21 | class TacticalPauseMenu
22 | {
23 | public:
24 |     // Draw the command panel for this frame. Returns the selected command (if any).
25 |     // Call inside an active ImGui frame (between BeginFrame / EndFrame).
26 |     // Only call while Tab is held — the caller controls open/close.
27 |     TacticalCommand Draw(const PlayerStats& stats, const ImGuiIO& io);
28 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp
EDIT MODE: append-first
INSERT AT LINE: 29
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 4-28
```

- **Task prompt block (copy exactly):**
```text
Implement Task 050: Tactical Pause enter / exit SFX.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 051: Lock-on acquire / break SFX
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/game/combat/Targeting.hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp` | yes | 136 | 137 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp` and stop so a human can paste them manually.
5. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
6. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 6: Read task card only
```text
Task 051: Lock-on acquire / break SFX.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 6: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` only
```text
Task 051: Lock-on acquire / break SFX.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 104.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 6: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` only
```text
Task 051: Lock-on acquire / break SFX.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 39.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 6: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp` only
```text
Task 051: Lock-on acquire / break SFX.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 137.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 6: Update docs only
```text
Task 051: Lock-on acquire / break SFX.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 6 / 6: Complete task guard
```text
Task 051: Lock-on acquire / break SFX.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
- Anchor lines `79-103` (current file tail before insertion at line `104`):
```cpp
 79 | 
 80 |     if (!tp::Audio::PlayOneShot(path))
 81 |     {
 82 |         LogPlayFailure("SFX", path);
 83 |         return false;
 84 |     }
 85 | 
 86 |     return true;
 87 | }
 88 | 
 89 | void AudioManager::SetBGMVolume(float v)
 90 | {
 91 |     m_bgmVolume = Clamp01(v);
 92 | }
 93 | 
 94 | void AudioManager::SetSFXVolume(float v)
 95 | {
 96 |     m_sfxVolume = Clamp01(v);
 97 | }
 98 | 
 99 | void AudioManager::Shutdown()
100 | {
101 |     if (m_bgmRequested)
102 |         StopBGM();
103 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
EDIT MODE: append-first
INSERT AT LINE: 104
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 79-103
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
- Anchor lines `14-38` (current file tail before insertion at line `39`):
```cpp
14 | {
15 | public:
16 |     // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
17 |     bool PlayBGM(const std::string& path);
18 |     // Clears AudioManager's tracked BGM state.
19 |     // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
20 |     void StopBGM();
21 |     bool PlaySFX(const std::string& path);
22 | 
23 |     void SetBGMVolume(float v);
24 |     void SetSFXVolume(float v);
25 |     float GetBGMVolume() const { return m_bgmVolume; }
26 |     float GetSFXVolume() const { return m_sfxVolume; }
27 | 
28 |     void Shutdown();
29 | 
30 | private:
31 |     static float Clamp01(float v);
32 | 
33 |     float m_bgmVolume = 1.0f;
34 |     float m_sfxVolume = 1.0f;
35 |     bool m_loggedBgmVolumeLimit = false;
36 |     bool m_loggedSfxVolumeLimit = false;
37 |     bool m_bgmRequested = false;
38 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
EDIT MODE: append-first
INSERT AT LINE: 39
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 14-38
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp`
- Anchor lines `112-136` (current file tail before insertion at line `137`):
```cpp
112 |         EnemyActor* bestTarget = nullptr;
113 |         float bestDistanceSq = kLockRadiusSq;
114 | 
115 |         for (int i = 0; i < count; ++i)
116 |         {
117 |             EnemyActor& candidate = enemies[i];
118 |             if (&candidate == excludeTarget)
119 |                 continue;
120 |             if (candidate.isDead)
121 |                 continue;
122 | 
123 |             const float deltaX = candidate.x - playerX;
124 |             const float deltaZ = candidate.z - playerZ;
125 |             const float distanceSq = (deltaX * deltaX) + (deltaZ * deltaZ);
126 | 
127 |             if (distanceSq <= bestDistanceSq)
128 |             {
129 |                 bestDistanceSq = distanceSq;
130 |                 bestTarget = &candidate;
131 |             }
132 |         }
133 | 
134 |         return bestTarget;
135 |     }
136 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/Targeting.hpp
EDIT MODE: append-first
INSERT AT LINE: 137
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 112-136
```

- **Task prompt block (copy exactly):**
```text
Implement Task 051: Lock-on acquire / break SFX.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 052: Enemy alert bark stub
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` | yes | 214 | 215 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` | yes | 95 | 96 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` and stop so a human can paste them manually.
6. Run docs updates as three one-file prompts only: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
7. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 7: Read task card only
```text
Task 052: Enemy alert bark stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` only
```text
Task 052: Enemy alert bark stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 104.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` only
```text
Task 052: Enemy alert bark stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 39.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp` only
```text
Task 052: Enemy alert bark stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 215.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp` only
```text
Task 052: Enemy alert bark stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 96.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 7: Update docs only
```text
Task 052: Enemy alert bark stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 7 / 7: Complete task guard
```text
Task 052: Enemy alert bark stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
- Anchor lines `79-103` (current file tail before insertion at line `104`):
```cpp
 79 | 
 80 |     if (!tp::Audio::PlayOneShot(path))
 81 |     {
 82 |         LogPlayFailure("SFX", path);
 83 |         return false;
 84 |     }
 85 | 
 86 |     return true;
 87 | }
 88 | 
 89 | void AudioManager::SetBGMVolume(float v)
 90 | {
 91 |     m_bgmVolume = Clamp01(v);
 92 | }
 93 | 
 94 | void AudioManager::SetSFXVolume(float v)
 95 | {
 96 |     m_sfxVolume = Clamp01(v);
 97 | }
 98 | 
 99 | void AudioManager::Shutdown()
100 | {
101 |     if (m_bgmRequested)
102 |         StopBGM();
103 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
EDIT MODE: append-first
INSERT AT LINE: 104
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 79-103
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
- Anchor lines `14-38` (current file tail before insertion at line `39`):
```cpp
14 | {
15 | public:
16 |     // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
17 |     bool PlayBGM(const std::string& path);
18 |     // Clears AudioManager's tracked BGM state.
19 |     // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
20 |     void StopBGM();
21 |     bool PlaySFX(const std::string& path);
22 | 
23 |     void SetBGMVolume(float v);
24 |     void SetSFXVolume(float v);
25 |     float GetBGMVolume() const { return m_bgmVolume; }
26 |     float GetSFXVolume() const { return m_sfxVolume; }
27 | 
28 |     void Shutdown();
29 | 
30 | private:
31 |     static float Clamp01(float v);
32 | 
33 |     float m_bgmVolume = 1.0f;
34 |     float m_sfxVolume = 1.0f;
35 |     bool m_loggedBgmVolumeLimit = false;
36 |     bool m_loggedSfxVolumeLimit = false;
37 |     bool m_bgmRequested = false;
38 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
EDIT MODE: append-first
INSERT AT LINE: 39
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 14-38
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp`
- Anchor lines `190-214` (current file tail before insertion at line `215`):
```cpp
190 |     if (isDead)
191 |         return;
192 | 
193 |     if (!IsHitFlashVisible())
194 |         return;
195 | 
196 |     static const std::string kPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
197 |     const PrimitivePrefab* visualPrefab = prefabLibrary.GetPrefab(kPrefabId);
198 |     if (!visualPrefab)
199 |         return;
200 | 
201 |     const float hitFlashScale = (hitFlashTimer > 0.0f) ? kHitFlashScale : 1.0f;
202 |     primitiveRenderer.AddRuntimeInstance(*visualPrefab, x, y, z, yaw, hitFlashScale);
203 | }
204 | 
205 | bool EnemyActor::IsHitFlashVisible() const
206 | {
207 |     if (hitFlashTimer <= 0.0f)
208 |         return true;
209 | 
210 |     const float elapsedFlashTime = kHitFlashDuration - hitFlashTimer;
211 |     const int blinkPhase = static_cast<int>(elapsedFlashTime / kHitFlashBlinkPeriod);
212 |     // Even elapsed phases are visible so a fresh hit starts visible.
213 |     return (blinkPhase % 2) == 0;
214 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.cpp
EDIT MODE: append-first
INSERT AT LINE: 215
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 190-214
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp`
- Anchor lines `71-95` (current file tail before insertion at line `96`):
```cpp
71 |               float wpAx, float wpAz,
72 |               float wpBx, float wpBz,
73 |               int   startHp = 10);
74 | 
75 |     // Advance state machine, move, snap Y to terrain.
76 |     // playerX/playerZ are the current player world-space XZ position.
77 |     void Update(float dt, D3D11Renderer& renderer,
78 |                 float playerX, float playerZ);
79 | 
80 |     // Apply incoming damage; triggers Hit stagger or Dead transition.
81 |     void OnHit(int damage);
82 | 
83 |     // Expand the enemy visual into the runtime primitive bucket.
84 |     // Reuses the player blockout prefab for enemy visuals.
85 |     // Does nothing when isDead is true.
86 |     void SubmitRuntimeVisual(const PrefabLibrary& prefabLibrary,
87 |                              PrimitiveRenderer&   primitiveRenderer) const;
88 | 
89 | private:
90 |     // Change state immediately and set the state-duration timer.
91 |     void TransitionTo(EnemyState next, float duration);
92 | 
93 |     // Returns whether the visual should be drawn this frame during hit flash.
94 |     bool IsHitFlashVisible() const;
95 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/EnemyActor.hpp
EDIT MODE: append-first
INSERT AT LINE: 96
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 71-95
```

- **Task prompt block (copy exactly):**
```text
Implement Task 052: Enemy alert bark stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 053: Equipment slot stub
- **Original scope token(s):** `src/game/inventory/Equipment.hpp`, `src/game/actors/PlayerStats.hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp` and stop.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 053: Equipment slot stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp` only
```text
Task 053: Equipment slot stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` only
```text
Task 053: Equipment slot stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 86.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 053: Equipment slot stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 053: Equipment slot stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/inventory/Equipment.hpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
- Anchor lines `61-85` (current file tail before insertion at line `86`):
```cpp
61 | 
62 |     bool IsLimitReady() const { return limitCharge >= 1.0f; }
63 | 
64 |     // Reduce HP by amount; clamps to zero. Also advances the Limit gauge.
65 |     // Safe to call with zero or positive values only.
66 |     void TakeDamage(int amount)
67 |     {
68 |         if (amount <= 0)
69 |             return;
70 |         hp = std::clamp(hp - static_cast<float>(amount), 0.0f, maxHp);
71 |         AddLimitCharge(kLimitChargePerHit);
72 |     }
73 | 
74 |     bool IsDead() const { return hp <= 0.0f; }
75 | 
76 |     // Restore all combat resources to their full starting values.
77 |     // Call on player defeat / respawn.
78 |     void Reset()
79 |     {
80 |         hp           = maxHp;
81 |         mp           = maxMp;
82 |         surgeCharge  = 0.0f;
83 |         limitCharge  = 0.0f;
84 |     }
85 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
EDIT MODE: append-first
INSERT AT LINE: 86
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 61-85
```

- **Task prompt block (copy exactly):**
```text
Implement Task 053: Equipment slot stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 054: Ability unlock / progression hook
- **Original scope token(s):** `src/game/progression/AbilityProgression.hpp`, `src/game/actors/PlayerStats.hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` | yes | 85 | 86 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp` and stop.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` and stop so a human can paste them manually.
4. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
5. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 5: Read task card only
```text
Task 054: Ability unlock / progression hook.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 5: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp` only
```text
Task 054: Ability unlock / progression hook.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 5: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp` only
```text
Task 054: Ability unlock / progression hook.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 86.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 5: Update docs only
```text
Task 054: Ability unlock / progression hook.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 5 / 5: Complete task guard
```text
Task 054: Ability unlock / progression hook.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/progression/AbilityProgression.hpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp`
- Anchor lines `61-85` (current file tail before insertion at line `86`):
```cpp
61 | 
62 |     bool IsLimitReady() const { return limitCharge >= 1.0f; }
63 | 
64 |     // Reduce HP by amount; clamps to zero. Also advances the Limit gauge.
65 |     // Safe to call with zero or positive values only.
66 |     void TakeDamage(int amount)
67 |     {
68 |         if (amount <= 0)
69 |             return;
70 |         hp = std::clamp(hp - static_cast<float>(amount), 0.0f, maxHp);
71 |         AddLimitCharge(kLimitChargePerHit);
72 |     }
73 | 
74 |     bool IsDead() const { return hp <= 0.0f; }
75 | 
76 |     // Restore all combat resources to their full starting values.
77 |     // Call on player defeat / respawn.
78 |     void Reset()
79 |     {
80 |         hp           = maxHp;
81 |         mp           = maxMp;
82 |         surgeCharge  = 0.0f;
83 |         limitCharge  = 0.0f;
84 |     }
85 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/actors/PlayerStats.hpp
EDIT MODE: append-first
INSERT AT LINE: 86
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 61-85
```

- **Task prompt block (copy exactly):**
```text
Implement Task 054: Ability unlock / progression hook.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 055: Combat stat modifier pipeline stub
- **Original scope token(s):** `src/game/combat/CombatModifiers.hpp`, `src/game/combat/CombatSystem.cpp/hpp`
- **Task goal:** implement smallest viable version in listed files, wire into existing runtime path, keep behavior guarded and reversible.
- **Done when:** feature is visible/usable, `docs/SYSTEMS.md` flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Create only `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp` and stop.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` and stop so a human can paste them manually.
5. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
6. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 6: Read task card only
```text
Task 055: Combat stat modifier pipeline stub.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 6: Create `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp` only
```text
Task 055: Combat stat modifier pipeline stub.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 6: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` only
```text
Task 055: Combat stat modifier pipeline stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 167.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 6: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` only
```text
Task 055: Combat stat modifier pipeline stub.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 72.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 6: Update docs only
```text
Task 055: Combat stat modifier pipeline stub.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 6 / 6: Complete task guard
```text
Task 055: Combat stat modifier pipeline stub.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatModifiers.hpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
- Anchor lines `142-166` (current file tail before insertion at line `167`):
```cpp
142 | 
143 |             std::ostringstream ss;
144 |             ss << "CombatSystem: Hit enemy " << i
145 |                << " for " << hitBox.damage << " damage.";
146 |             LOG_INFO(ss.str());
147 | 
148 |             enemy.OnHit(hitBox.damage);
149 | 
150 |             if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
151 |             {
152 |                 EnemyHitRecord& hitRecord = m_recentEnemyHits[m_recentEnemyHitCount++];
153 |                 hitRecord.x = enemy.x;
154 |                 hitRecord.y = enemy.y + DAMAGE_NUMBER_Y_OFFSET;
155 |                 hitRecord.z = enemy.z;
156 |                 hitRecord.damage = hitBox.damage;
157 |             }
158 |         }
159 |     }
160 | 
161 |     // Remove any hitboxes whose lifetime has run out.
162 |     m_activeHitBoxes.erase(
163 |         std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
164 |                        [](const HitBox& hitBox) { return hitBox.framesToLive <= 0; }),
165 |         m_activeHitBoxes.end());
166 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
EDIT MODE: append-first
INSERT AT LINE: 167
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 142-166
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp`
- Anchor lines `47-71` (current file tail before insertion at line `72`):
```cpp
47 |     // apply damage, mark dead enemies, and remove expired hitboxes.
48 |     // Also ticks the combo window timer.
49 |     // Call once per frame from RuntimeScene::BeginFrame.
50 |     void Update(float dt, EnemyActor* enemies, int count);
51 | 
52 |     // Read-only access to active hitboxes for debug visualization.
53 |     const std::vector<HitBox>& GetActiveHitBoxes() const
54 |     { return m_activeHitBoxes; }
55 | 
56 |     // Recent hit records are valid for the current frame only.
57 |     // They are reset at the start of each Update() call.
58 |     // Always pair this pointer with GetRecentEnemyHitCount().
59 |     const EnemyHitRecord* GetRecentEnemyHits() const
60 |     { return m_recentEnemyHits; }
61 | 
62 |     int GetRecentEnemyHitCount() const
63 |     { return m_recentEnemyHitCount; }
64 | 
65 | private:
66 |     static constexpr int   kMaxRecentEnemyHits = 32;
67 | 
68 |     std::vector<HitBox> m_activeHitBoxes;
69 |     EnemyHitRecord m_recentEnemyHits[kMaxRecentEnemyHits]{};
70 |     int m_recentEnemyHitCount = 0;
71 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
EDIT MODE: append-first
INSERT AT LINE: 72
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 47-71
```

- **Task prompt block (copy exactly):**
```text
Implement Task 055: Combat stat modifier pipeline stub.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 056: Combat bugfix sweep
- **Original scope token(s):** `src/game/combat/CombatSystem.cpp/hpp`, `src/game/RuntimeScene.hpp`, `src/app/Main.cpp`
- **Task goal:** resolve remaining combat regressions and unsafe edge cases using minimal scoped fixes only.
- **Done when:** no known combat blockers remain in `docs/AGENT_WORK_LOG.md`, `docs/SYSTEMS.md` flipped to ✅ where applicable, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` | yes | 166 | 167 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` | yes | 71 | 72 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` | yes | 330 | 331 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` | yes | 565 | 566 | 28 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` and stop so a human can paste them manually.
6. Run docs updates as three one-file prompts only: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
7. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 7: Read task card only
```text
Task 056: Combat bugfix sweep.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp` only
```text
Task 056: Combat bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 167.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp` only
```text
Task 056: Combat bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 72.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` only
```text
Task 056: Combat bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 331.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` only
```text
Task 056: Combat bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 566.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 7: Update docs only
```text
Task 056: Combat bugfix sweep.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 7 / 7: Complete task guard
```text
Task 056: Combat bugfix sweep.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp`
- Anchor lines `142-166` (current file tail before insertion at line `167`):
```cpp
142 | 
143 |             std::ostringstream ss;
144 |             ss << "CombatSystem: Hit enemy " << i
145 |                << " for " << hitBox.damage << " damage.";
146 |             LOG_INFO(ss.str());
147 | 
148 |             enemy.OnHit(hitBox.damage);
149 | 
150 |             if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
151 |             {
152 |                 EnemyHitRecord& hitRecord = m_recentEnemyHits[m_recentEnemyHitCount++];
153 |                 hitRecord.x = enemy.x;
154 |                 hitRecord.y = enemy.y + DAMAGE_NUMBER_Y_OFFSET;
155 |                 hitRecord.z = enemy.z;
156 |                 hitRecord.damage = hitBox.damage;
157 |             }
158 |         }
159 |     }
160 | 
161 |     // Remove any hitboxes whose lifetime has run out.
162 |     m_activeHitBoxes.erase(
163 |         std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
164 |                        [](const HitBox& hitBox) { return hitBox.framesToLive <= 0; }),
165 |         m_activeHitBoxes.end());
166 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.cpp
EDIT MODE: append-first
INSERT AT LINE: 167
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 142-166
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp`
- Anchor lines `47-71` (current file tail before insertion at line `72`):
```cpp
47 |     // apply damage, mark dead enemies, and remove expired hitboxes.
48 |     // Also ticks the combo window timer.
49 |     // Call once per frame from RuntimeScene::BeginFrame.
50 |     void Update(float dt, EnemyActor* enemies, int count);
51 | 
52 |     // Read-only access to active hitboxes for debug visualization.
53 |     const std::vector<HitBox>& GetActiveHitBoxes() const
54 |     { return m_activeHitBoxes; }
55 | 
56 |     // Recent hit records are valid for the current frame only.
57 |     // They are reset at the start of each Update() call.
58 |     // Always pair this pointer with GetRecentEnemyHitCount().
59 |     const EnemyHitRecord* GetRecentEnemyHits() const
60 |     { return m_recentEnemyHits; }
61 | 
62 |     int GetRecentEnemyHitCount() const
63 |     { return m_recentEnemyHitCount; }
64 | 
65 | private:
66 |     static constexpr int   kMaxRecentEnemyHits = 32;
67 | 
68 |     std::vector<HitBox> m_activeHitBoxes;
69 |     EnemyHitRecord m_recentEnemyHits[kMaxRecentEnemyHits]{};
70 |     int m_recentEnemyHitCount = 0;
71 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/combat/CombatSystem.hpp
EDIT MODE: append-first
INSERT AT LINE: 72
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 47-71
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp`
- Anchor lines `306-330` (current file tail before insertion at line `331`):
```cpp
306 |     // m_playerY is the camera eye level; body center is shifted down by kPlayerBodyCenterOffset.
307 |     bool HitBoxOverlapsPlayer(const HitBox& hitBox) const
308 |     {
309 |         float bodyCenterY = m_playerY - kPlayerBodyCenterOffset;
310 |         float distX = fabsf(m_playerX - hitBox.x);
311 |         float distY = fabsf(bodyCenterY - hitBox.y);
312 |         float distZ = fabsf(m_playerZ - hitBox.z);
313 |         return (distX < kPlayerHitHalfX + hitBox.halfX) &&
314 |                (distY < kPlayerHitHalfY + hitBox.halfY) &&
315 |                (distZ < kPlayerHitHalfZ + hitBox.halfZ);
316 |     }
317 | 
318 |     float GetAttackYaw(const CameraController& camController) const
319 |     {
320 |         const EnemyActor* lockedTarget = m_targeting.GetTarget();
321 |         if (!lockedTarget)
322 |             return camController.GetYaw();
323 | 
324 |         const float playerX = camController.GetPlayerX();
325 |         const float playerZ = camController.GetPlayerZ();
326 |         const float deltaX = lockedTarget->x - playerX;
327 |         const float deltaZ = lockedTarget->z - playerZ;
328 |         return atan2f(deltaX, deltaZ);
329 |     }
330 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp
EDIT MODE: append-first
INSERT AT LINE: 331
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 306-330
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
- Anchor lines `541-565` (current file tail before insertion at line `566`):
```cpp
541 |                     camController.GetCamY(),
542 |                     camController.GetCamZ(),
543 |                     camController.GetYaw(),
544 |                     camController.GetPitch(),
545 |                     static_cast<float>(window.GetWidth()),
546 |                     static_cast<float>(window.GetHeight()));
547 |             }
548 |             imguiLayer.EndFrame();
549 | 
550 |             renderer.PresentFrame();
551 |         }
552 | 
553 |         GR_FRAME_MARK;
554 |         Sleep(1); // tiny sleep so we don't peg CPU at 100%
555 |     }
556 |     primRenderer.Shutdown();
557 |     forest.Shutdown();
558 |     imguiLayer.Shutdown();
559 |     audioManager.Shutdown();
560 |     ThirdPartyBootstrap::Shutdown();
561 |     textureCache.ReleaseAll();
562 |     renderer.Shutdown();
563 |     window.Close();
564 |     return 0;
565 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp
EDIT MODE: append-first
INSERT AT LINE: 566
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 541-565
```

- **Task prompt block (copy exactly):**
```text
Implement Task 056: Combat bugfix sweep.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 057: Camera/input bugfix sweep
- **Original scope token(s):** `src/game/CameraController.cpp/hpp`, `src/app/InputActionMap.hpp`, `src/app/Main.cpp`
- **Task goal:** resolve camera/input logic bugs and bad state transitions with minimal safe edits.
- **Done when:** no known camera/input blockers remain in `docs/AGENT_WORK_LOG.md`, relevant systems flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` | yes | 303 | 304 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` | yes | 129 | 130 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp` | yes | 87 | 88 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` | yes | 565 | 566 | 28 | 70 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` and stop so a human can paste them manually.
6. Run docs updates as three one-file prompts only: `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, then `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
7. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 7: Read task card only
```text
Task 057: Camera/input bugfix sweep.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp` only
```text
Task 057: Camera/input bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 304.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp` only
```text
Task 057: Camera/input bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 130.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp` only
```text
Task 057: Camera/input bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 88.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 7: Edit `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp` only
```text
Task 057: Camera/input bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 566.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 7: Update docs only
```text
Task 057: Camera/input bugfix sweep.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 7 / 7: Complete task guard
```text
Task 057: Camera/input bugfix sweep.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp`
- Anchor lines `279-303` (current file tail before insertion at line `304`):
```cpp
279 |         XM_PIDIV4,          // 45-degree vertical FOV (matches DrawTerrainPatch)
280 |         vpW / vpH,
281 |         0.1f, 2000.0f);
282 | 
283 |     // Unproject near and far screen points into world space.
284 |     // XMVector3Unproject arguments: screenPoint, vpX, vpY, vpW, vpH, minZ, maxZ, proj, view, world
285 |     XMVECTOR nearPt = XMVector3Unproject(
286 |         XMVectorSet(mouseX, mouseY, 0.0f, 0.0f),
287 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
288 |         proj, view, XMMatrixIdentity());
289 | 
290 |     XMVECTOR farPt = XMVector3Unproject(
291 |         XMVectorSet(mouseX, mouseY, 1.0f, 0.0f),
292 |         0.0f, 0.0f, vpW, vpH, 0.0f, 1.0f,
293 |         proj, view, XMMatrixIdentity());
294 | 
295 |     XMVECTOR dir = XMVector3Normalize(farPt - nearPt);
296 | 
297 |     outOriginX = XMVectorGetX(nearPt);
298 |     outOriginY = XMVectorGetY(nearPt);
299 |     outOriginZ = XMVectorGetZ(nearPt);
300 |     outDirX    = XMVectorGetX(dir);
301 |     outDirY    = XMVectorGetY(dir);
302 |     outDirZ    = XMVectorGetZ(dir);
303 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.cpp
EDIT MODE: append-first
INSERT AT LINE: 304
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 279-303
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp`
- Anchor lines `105-129` (current file tail before insertion at line `130`):
```cpp
105 |     float GetCamY()    const { return m_camY; }
106 |     float GetCamZ()    const { return m_camZ; }
107 |     bool  IsDodgeActive() const { return m_dodgeActive; }
108 | 
109 | private:
110 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_X = 0.3f;
111 |     static constexpr float PLAYER_COLLISION_HALF_HEIGHT = 0.9f;
112 |     static constexpr float PLAYER_COLLISION_HALF_WIDTH_Z = 0.3f;
113 | 
114 |     float m_playerX = 0.0f, m_playerY = 0.0f, m_playerZ = -3.0f;
115 |     float m_yaw = 0.0f, m_pitch = 0.0f;
116 |     float m_camX = 0.0f, m_camY = 0.0f, m_camZ = 0.0f;
117 |     float m_velocityY  = 0.0f;
118 |     bool  m_isGrounded = true;
119 |     float m_dodgeVelX = 0.0f;
120 |     float m_dodgeVelZ = 0.0f;
121 |     float m_dodgeTimer = 0.0f;
122 |     bool m_dodgeActive = false;
123 |     POINT m_centerPoint = {};
124 |     const InputActionMap* m_inputActionMap = nullptr;
125 |     const CollisionWorld* m_collisionWorld = nullptr;
126 | 
127 |     // Recompute m_camX/Y/Z from player pos + yaw.
128 |     void ComputeCamFromPlayer();
129 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/CameraController.hpp
EDIT MODE: append-first
INSERT AT LINE: 130
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 105-129
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp`
- Anchor lines `63-87` (current file tail before insertion at line `88`):
```cpp
63 |         map.bindings[InputAction::ReloadAssets] = VK_F5;
64 |         return map;
65 |     }
66 | 
67 |     bool IsHeld(InputAction action) const
68 |     {
69 |         const auto it = bindings.find(action);
70 |         if (it == bindings.end())
71 |             return false;
72 |         return (GetAsyncKeyState(it->second) & 0x8000) != 0;
73 |     }
74 | 
75 |     bool IsPressed(InputAction action, bool& wasDown) const
76 |     {
77 |         const bool isDown = IsHeld(action);
78 |         const bool pressed = isDown && !wasDown;
79 |         wasDown = isDown;
80 |         return pressed;
81 |     }
82 | 
83 |     bool IsVirtualKeyHeld(int virtualKey) const
84 |     {
85 |         return (GetAsyncKeyState(virtualKey) & 0x8000) != 0;
86 |     }
87 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/InputActionMap.hpp
EDIT MODE: append-first
INSERT AT LINE: 88
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 63-87
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp`
- Anchor lines `541-565` (current file tail before insertion at line `566`):
```cpp
541 |                     camController.GetCamY(),
542 |                     camController.GetCamZ(),
543 |                     camController.GetYaw(),
544 |                     camController.GetPitch(),
545 |                     static_cast<float>(window.GetWidth()),
546 |                     static_cast<float>(window.GetHeight()));
547 |             }
548 |             imguiLayer.EndFrame();
549 | 
550 |             renderer.PresentFrame();
551 |         }
552 | 
553 |         GR_FRAME_MARK;
554 |         Sleep(1); // tiny sleep so we don't peg CPU at 100%
555 |     }
556 |     primRenderer.Shutdown();
557 |     forest.Shutdown();
558 |     imguiLayer.Shutdown();
559 |     audioManager.Shutdown();
560 |     ThirdPartyBootstrap::Shutdown();
561 |     textureCache.ReleaseAll();
562 |     renderer.Shutdown();
563 |     window.Close();
564 |     return 0;
565 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/Main.cpp
EDIT MODE: append-first
INSERT AT LINE: 566
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 541-565
```

- **Task prompt block (copy exactly):**
```text
Implement Task 057: Camera/input bugfix sweep.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 058: UI/HUD polish and bugfix sweep
- **Original scope token(s):** `src/ui/GameHUD.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
- **Task goal:** fix HUD/UI defects and apply low-risk clarity polish for readability/usability.
- **Done when:** no known UI/HUD blockers remain in `docs/AGENT_WORK_LOG.md`, relevant systems flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` | yes | 566 | 567 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` | yes | 123 | 124 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` | yes | 139 | 140 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` | yes | 28 | 29 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` and stop so a human can paste them manually.
6. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` and stop so a human can paste them manually.
7. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` and stop so a human can paste them manually.
8. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
9. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 9: Read task card only
```text
Task 058: UI/HUD polish and bugfix sweep.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 058: UI/HUD polish and bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 058: UI/HUD polish and bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp` only
```text
Task 058: UI/HUD polish and bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 567.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp` only
```text
Task 058: UI/HUD polish and bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 124.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp` only
```text
Task 058: UI/HUD polish and bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 140.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 7 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp` only
```text
Task 058: UI/HUD polish and bugfix sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 29.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 8 / 9: Update docs only
```text
Task 058: UI/HUD polish and bugfix sweep.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 9 / 9: Complete task guard
```text
Task 058: UI/HUD polish and bugfix sweep.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp`
- Anchor lines `542-566` (current file tail before insertion at line `567`):
```cpp
542 |     float camX, float camY, float camZ,
543 |     float yaw,  float pitch,
544 |     float vpW,  float vpH)
545 | {
546 |     if (!target || target->isDead)
547 |         return;
548 |     if (!ImGui::GetCurrentContext())
549 |         return;
550 | 
551 |     float sx = 0.0f;
552 |     float sy = 0.0f;
553 |     if (!WorldToScreen(target->x, target->y + kLockMarkerHeightOffset, target->z,
554 |                        camX, camY, camZ, yaw, pitch, vpW, vpH, sx, sy))
555 |     {
556 |         return;
557 |     }
558 | 
559 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
560 |     const ImU32 lockColor = IM_COL32(255, 220, 80, 255);
561 | 
562 |     drawList->AddCircle(ImVec2(sx, sy), kLockMarkerCircleRadius, lockColor,
563 |                         kLockMarkerCircleSegments, kLockMarkerCircleThickness);
564 |     drawList->AddText(ImVec2(sx + kLockMarkerTextOffsetX, sy + kLockMarkerTextOffsetY),
565 |                       lockColor, "LOCK");
566 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.cpp
EDIT MODE: append-first
INSERT AT LINE: 567
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 542-566
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp`
- Anchor lines `99-123` (current file tail before insertion at line `124`):
```cpp
 99 | 
100 | private:
101 |     bool initialized = false;
102 | 
103 |     bool showPauseMenu   = false;
104 |     bool showDebugOverlay = false;
105 | 
106 |     float currentFPS = 0.0f;
107 |     float currentDT  = 0.0f;
108 |     float camX = 0.0f, camY = 0.0f, camZ = 0.0f;
109 |     float camYaw = 0.0f, camPitch = 0.0f;
110 | 
111 |     bool wantsQuit   = false;
112 |     bool wantsResume = false;
113 |     D3D11Renderer* m_renderer = nullptr;
114 |     bool  m_lightUiInitialized = false;
115 |     float m_sunDirX = 0.0f;
116 |     float m_sunDirY = -1.0f;
117 |     float m_sunDirZ = 0.0f;
118 |     float m_ambientStrength = 0.25f;
119 |     AudioManager* m_audioManager = nullptr;
120 | 
121 |     void DrawPauseMenu();
122 |     void DrawDebugOverlay();
123 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/ImGuiLayer.hpp
EDIT MODE: append-first
INSERT AT LINE: 124
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 99-123
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp`
- Anchor lines `115-139` (current file tail before insertion at line `140`):
```cpp
115 |             ImGui::PushStyleColor(ImGuiCol_Text, kReadyColor);
116 | 
117 |         if (DrawCommandRow("  Surge Strike", surgeReady, surgeReady ? nullptr : "Need Surge"))
118 |             selectedCommand = TacticalCommand::SurgeStrike;
119 | 
120 |         if (surgeReady)
121 |             ImGui::PopStyleColor();
122 | 
123 |         // Stub commands — reserved for later milestones.
124 |         DrawCommandRow(kMagicLabel, false, "No MP");
125 |         DrawCommandRow(kItemsLabel, false, "Coming soon");
126 |         DrawCommandRow(kAllyLabel,  false, "Coming soon");
127 | 
128 |         ImGui::EndTable();
129 |     }
130 | 
131 |     // --- Footer hint ---
132 |     ImGui::Spacing();
133 |     ImGui::Separator();
134 |     ImGui::Spacing();
135 |     ImGui::TextColored(kHintColor, "Release Tab to resume");
136 | 
137 |     ImGui::End();
138 |     return selectedCommand;
139 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.cpp
EDIT MODE: append-first
INSERT AT LINE: 140
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 115-139
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp`
- Anchor lines `4-28` (current file tail before insertion at line `29`):
```cpp
 4 | // ROLE: HUD, menus, overlays, and editor tool panels
 5 | // DO NOT: Modify unrelated systems or break subsystem boundaries.
 6 | // OWNS: TacticalPauseMenu module behavior and local implementation details.
 7 | // ============================================================
 8 | 
 9 | #pragma once
10 | // TacticalPauseMenu.hpp
11 | // Draws the FF-style Tactical Pause command panel while Tab is held.
12 | // Returns the command activated this frame so Main.cpp can execute it.
13 | 
14 | struct PlayerStats;
15 | struct ImGuiIO;
16 | 
17 | // Commands that can be activated from the Tactical Pause panel.
18 | // None means no command was chosen this frame.
19 | enum class TacticalCommand { None, SurgeStrike };
20 | 
21 | class TacticalPauseMenu
22 | {
23 | public:
24 |     // Draw the command panel for this frame. Returns the selected command (if any).
25 |     // Call inside an active ImGui frame (between BeginFrame / EndFrame).
26 |     // Only call while Tab is held — the caller controls open/close.
27 |     TacticalCommand Draw(const PlayerStats& stats, const ImGuiIO& io);
28 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/TacticalPauseMenu.hpp
EDIT MODE: append-first
INSERT AT LINE: 29
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 4-28
```

- **Task prompt block (copy exactly):**
```text
Implement Task 058: UI/HUD polish and bugfix sweep.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 059: World/runtime stability sweep
- **Original scope token(s):** `src/world/WorldGrid.cpp/hpp`, `src/game/RuntimeScene.cpp/hpp`, `src/game/Forest.cpp/hpp`
- **Task goal:** fix high-impact runtime/world stability issues with smallest safe patches.
- **Done when:** no known world/runtime blockers remain in `docs/AGENT_WORK_LOG.md`, relevant systems flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` | yes | 353 | 354 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` | yes | 111 | 112 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.cpp` | yes | 109 | 110 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` | yes | 330 | 331 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.cpp` | yes | 233 | 234 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.hpp` | yes | 48 | 49 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` and stop so a human can paste them manually.
4. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.cpp` and stop so a human can paste them manually.
5. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` and stop so a human can paste them manually.
6. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.cpp` and stop so a human can paste them manually.
7. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.hpp` and stop so a human can paste them manually.
8. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
9. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 9: Read task card only
```text
Task 059: World/runtime stability sweep.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp` only
```text
Task 059: World/runtime stability sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 354.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp` only
```text
Task 059: World/runtime stability sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 112.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.cpp` only
```text
Task 059: World/runtime stability sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 110.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp` only
```text
Task 059: World/runtime stability sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 331.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.cpp` only
```text
Task 059: World/runtime stability sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/Forest.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 234.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 7 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.hpp` only
```text
Task 059: World/runtime stability sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/game/Forest.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 49.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 8 / 9: Update docs only
```text
Task 059: World/runtime stability sweep.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 9 / 9: Complete task guard
```text
Task 059: World/runtime stability sweep.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp`
- Anchor lines `329-353` (current file tail before insertion at line `354`):
```cpp
329 |     }
330 |     catch (const std::exception& e)
331 |     {
332 |         LOG_ERROR(std::string("WorldGrid::SaveCell: write error: ") + e.what());
333 |         return false;
334 |     }
335 | 
336 |     // std::ofstream write failures typically set failbit/badbit rather than throwing.
337 |     // Always check the stream state after writing, regardless of exceptions.
338 |     if (!out.good())
339 |     {
340 |         std::ostringstream streamErr;
341 |         streamErr << "WorldGrid::SaveCell: stream error after write to '"
342 |                   << cell->filePath
343 |                   << "' (disk full, permission denied, or IO error).";
344 |         LOG_ERROR(streamErr.str());
345 |         return false;
346 |     }
347 | 
348 |     std::ostringstream ss;
349 |     ss << "WorldGrid::SaveCell: saved cell (" << cx << "," << cz << ") to '"
350 |        << cell->filePath << "' with " << cell->instances.size() << " instance(s).";
351 |     LOG_INFO(ss.str());
352 |     return true;
353 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.cpp
EDIT MODE: append-first
INSERT AT LINE: 354
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 329-353
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp`
- Anchor lines `87-111` (current file tail before insertion at line `112`):
```cpp
 87 |     // radius=1 gives a 3x3 block of cells (9 max), radius=0 gives only the player cell.
 88 |     std::vector<WorldCell> GetActiveCells(int playerCX, int playerCZ, int radius = 1) const;
 89 | 
 90 |     // Convert a world-space (X, Z) position into a cell grid coordinate.
 91 |     void WorldToCell(float worldX, float worldZ, int& outCX, int& outCZ) const;
 92 | 
 93 |     float       GetCellSize() const  { return m_cellSize; }
 94 |     const std::string& GetName() const { return m_name; }
 95 |     int         CellCount()  const  { return static_cast<int>(m_cells.size()); }
 96 | 
 97 |     // Returns a mutable pointer to the cell at (cx,cz), or nullptr if not found.
 98 |     WorldCell* FindCell(int cx, int cz);
 99 | 
100 |     // Write the cell at (cx,cz) back to its JSON file (preserving terrain/forest settings).
101 |     // Returns true on success; logs an error and keeps in-memory data on failure.
102 |     bool SaveCell(int cx, int cz);
103 | 
104 | private:
105 |     bool LoadCellFile(const std::string& path, WorldCell& out);
106 | 
107 |     std::string           m_worldJsonPath;
108 |     std::string           m_name;
109 |     float                 m_cellSize = 200.0f;
110 |     std::vector<WorldCell> m_cells;
111 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/world/WorldGrid.hpp
EDIT MODE: append-first
INSERT AT LINE: 112
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 87-111
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.cpp`
- Anchor lines `85-109` (current file tail before insertion at line `110`):
```cpp
 85 | 
 86 |         if (m_player.stats.IsDead())
 87 |         {
 88 |             // Restore all stats and signal Main.cpp to teleport the camera.
 89 |             m_player.stats.Reset();
 90 |             m_player.state      = PlayerActionState::Idle;
 91 |             m_player.stateTimer = 0.0f;
 92 |             m_wantsRespawn      = true;
 93 |             LOG_INFO("RuntimeScene: Player defeated — respawning.");
 94 |         }
 95 |         else
 96 |         {
 97 |             m_player.state      = PlayerActionState::Stunned;
 98 |             m_player.stateTimer = 0.30f;
 99 |             std::string msg = "RuntimeScene: Player hit for ";
100 |             msg += std::to_string(totalDamage);
101 |             msg += " damage (HP ";
102 |             msg += std::to_string(static_cast<int>(m_player.stats.hp));
103 |             msg += " / ";
104 |             msg += std::to_string(static_cast<int>(m_player.stats.maxHp));
105 |             msg += ").";
106 |             LOG_INFO(msg);
107 |         }
108 |     }
109 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.cpp
EDIT MODE: append-first
INSERT AT LINE: 110
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 85-109
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp`
- Anchor lines `306-330` (current file tail before insertion at line `331`):
```cpp
306 |     // m_playerY is the camera eye level; body center is shifted down by kPlayerBodyCenterOffset.
307 |     bool HitBoxOverlapsPlayer(const HitBox& hitBox) const
308 |     {
309 |         float bodyCenterY = m_playerY - kPlayerBodyCenterOffset;
310 |         float distX = fabsf(m_playerX - hitBox.x);
311 |         float distY = fabsf(bodyCenterY - hitBox.y);
312 |         float distZ = fabsf(m_playerZ - hitBox.z);
313 |         return (distX < kPlayerHitHalfX + hitBox.halfX) &&
314 |                (distY < kPlayerHitHalfY + hitBox.halfY) &&
315 |                (distZ < kPlayerHitHalfZ + hitBox.halfZ);
316 |     }
317 | 
318 |     float GetAttackYaw(const CameraController& camController) const
319 |     {
320 |         const EnemyActor* lockedTarget = m_targeting.GetTarget();
321 |         if (!lockedTarget)
322 |             return camController.GetYaw();
323 | 
324 |         const float playerX = camController.GetPlayerX();
325 |         const float playerZ = camController.GetPlayerZ();
326 |         const float deltaX = lockedTarget->x - playerX;
327 |         const float deltaZ = lockedTarget->z - playerZ;
328 |         return atan2f(deltaX, deltaZ);
329 |     }
330 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/RuntimeScene.hpp
EDIT MODE: append-first
INSERT AT LINE: 331
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 306-330
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.cpp`
- Anchor lines `209-233` (current file tail before insertion at line `234`):
```cpp
209 | 
210 |     for (const auto& inst : m_instances)
211 |     {
212 |         // Use stored inst.y (sampled at placement). No per-frame sampling.
213 |         const float trunkNudge = -0.02f; // small downward tweak to ensure contact (tweak if needed)
214 | 
215 |         float halfHeight = inst.scale; // half-height after scaling: 0.5 * (inst.scale*2.0f) == inst.scale
216 |         float transY = inst.y + halfHeight + trunkNudge;
217 | 
218 |         XMMATRIX scaleMat = XMMatrixScaling(inst.scale, inst.scale * 2.0f, inst.scale); // scale
219 |         XMMATRIX transMat = XMMatrixTranslation(inst.x, transY, inst.z);               // translation
220 |         XMMATRIX worldMat = scaleMat * transMat;
221 | 
222 |         // mvp + world
223 |         XMMATRIX mvp = XMMatrixTranspose(worldMat * view * proj);
224 |         XMMATRIX worldT = XMMatrixTranspose(worldMat);
225 |         struct CB { XMFLOAT4X4 mvp; XMFLOAT4X4 world; } cbData;
226 |         XMStoreFloat4x4(&cbData.mvp, mvp);
227 |         XMStoreFloat4x4(&cbData.world, worldT);
228 |         m_context->UpdateSubresource(m_cb, 0, nullptr, &cbData, 0, 0);
229 |         m_context->VSSetConstantBuffers(0, 1, &m_cb);
230 | 
231 |         m_context->DrawIndexed(m_indexCount, 0, 0);
232 |     }
233 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/Forest.cpp
EDIT MODE: append-first
INSERT AT LINE: 234
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 209-233
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/game/Forest.hpp`
- Anchor lines `24-48` (current file tail before insertion at line `49`):
```cpp
24 | 
25 |     // Add a single instance at the given world position (y is snapped to terrain).
26 |     void AddInstance(D3D11Renderer& renderer, float x, float y, float z, float scale = 1.0f);
27 | 
28 |     // Remove all instances (both procedural and authored).
29 |     void ClearInstances();
30 | 
31 |     // How many instances are currently in memory.
32 |     int GetInstanceCount() const { return static_cast<int>(m_instances.size()); }
33 | 
34 | private:
35 |     struct Instance { float x, y, z, scale; };
36 |     std::vector<Instance> m_instances;
37 | 
38 |     // GPU resources owned by Forest
39 |     ID3D11Device* m_device = nullptr;
40 |     ID3D11DeviceContext* m_context = nullptr;
41 |     ID3D11Buffer* m_vb = nullptr;
42 |     ID3D11Buffer* m_ib = nullptr;
43 |     ID3D11Buffer* m_cb = nullptr;
44 |     ID3D11VertexShader* m_vs = nullptr;
45 |     ID3D11PixelShader* m_ps = nullptr;
46 |     ID3D11InputLayout* m_layout = nullptr;
47 |     UINT m_indexCount = 0;
48 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/game/Forest.hpp
EDIT MODE: append-first
INSERT AT LINE: 49
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 24-48
```

- **Task prompt block (copy exactly):**
```text
Implement Task 059: World/runtime stability sweep.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
After code edits update: /home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md, /home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md, /home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Then run: python tools/llm/worst_llm_guard.py complete
```

### Task 060: Audio and final quality sweep
- **Original scope token(s):** `src/audio/AudioManager.cpp/hpp`, `src/app/QualityPreset.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
- **Task goal:** fix remaining audio/quality defects and apply final GT610-safe polish pass.
- **Done when:** final quality blockers are closed in `docs/AGENT_WORK_LOG.md`, relevant systems flipped to ✅, changelog/log updated.
- **File Edit Plan (absolute paths + line targets):**

| File | Exists | Current Lines | Insert At Line | Modify Existing Lines (max) | Add New Lines (target) |
|---|---:|---:|---:|---:|---:|
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` | yes | 103 | 104 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` | yes | 38 | 39 | 18 | 40 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` | no | 0 | 1 | 0 | 110 |
| `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` | no | 0 | 1 | 0 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` | yes | 378 | 379 | 28 | 70 |
| `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` | yes | 40 | 41 | 18 | 40 |

- **Micro-step execution order (Qwen2.5-Coder-1.5B):**

1. Read this task card once. Do not open any other task card.
2. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` and stop so a human can paste them manually.
3. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` and stop so a human can paste them manually.
4. Create only `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` and stop.
5. Create only `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` and stop.
6. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` and stop so a human can paste them manually.
7. Generate copy-ready changes only for `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` and stop so a human can paste them manually.
8. Update only `/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md`, `/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md`, and `/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md`.
9. Run `python tools/llm/worst_llm_guard.py complete` and stop.

- **Qwen Step Packets (copy exactly one at a time):**

#### Step 1 / 9: Read task card only
```text
Task 060: Audio and final quality sweep.
Read this task card only.
Do not generate file changes in this step.
After reading, stop.
```

#### Step 2 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp` only
```text
Task 060: Audio and final quality sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 104.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 3 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp` only
```text
Task 060: Audio and final quality sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 39.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 4 / 9: Create `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp` only
```text
Task 060: Audio and final quality sweep.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 110.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 5 / 9: Create `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp` only
```text
Task 060: Audio and final quality sweep.
Create only this file: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 1.
Max existing lines to modify: 0.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 6 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp` only
```text
Task 060: Audio and final quality sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 379.
Max existing lines to modify: 28.
Target new lines to add: 70.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 7 / 9: Edit `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp` only
```text
Task 060: Audio and final quality sweep.
Target file for this step (the model cannot edit it directly): /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
Do not generate changes for any other file in this step.
Read only the target file path above, limited to the anchor line range shown in the matching Code Context Block.
Set READ_FILE to that absolute path and READ_LINES to that anchor range in your output.
Insert target: line 41.
Max existing lines to modify: 18.
Target new lines to add: 40.
Implement only the smallest part of the task that belongs in this file.
Output copy-ready code blocks for this file only, then stop so a human can paste them manually.
```

#### Step 8 / 9: Update docs only
```text
Task 060: Audio and final quality sweep.
This docs phase is still one-file-per-prompt.
Run this step as separate prompts, one file at a time, using the exact file list below:
For each prompt set READ_FILE to the selected doc path and READ_LINES to 1-EOF for that single file only:
/home/runner/work/GameRewritten/GameRewritten/docs/SYSTEMS.md
/home/runner/work/GameRewritten/GameRewritten/docs/CHANGELOG.md
/home/runner/work/GameRewritten/GameRewritten/docs/AGENT_WORK_LOG.md
Do not generate code-file changes in this step, and do not combine multiple doc files in one prompt.
Update the docs to describe the completed task.
Output copy-ready doc blocks, manually paste them into the listed doc files, save, and stop.
```

#### Step 9 / 9: Complete task guard
```text
Task 060: Audio and final quality sweep.
Do not generate file changes in this step.
Run: python tools/llm/worst_llm_guard.py complete
Stop after the command finishes.
```

- **Code Context Blocks (copy into LLM prompt):**

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp`
- Anchor lines `79-103` (current file tail before insertion at line `104`):
```cpp
 79 | 
 80 |     if (!tp::Audio::PlayOneShot(path))
 81 |     {
 82 |         LogPlayFailure("SFX", path);
 83 |         return false;
 84 |     }
 85 | 
 86 |     return true;
 87 | }
 88 | 
 89 | void AudioManager::SetBGMVolume(float v)
 90 | {
 91 |     m_bgmVolume = Clamp01(v);
 92 | }
 93 | 
 94 | void AudioManager::SetSFXVolume(float v)
 95 | {
 96 |     m_sfxVolume = Clamp01(v);
 97 | }
 98 | 
 99 | void AudioManager::Shutdown()
100 | {
101 |     if (m_bgmRequested)
102 |         StopBGM();
103 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.cpp
EDIT MODE: append-first
INSERT AT LINE: 104
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 79-103
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp`
- Anchor lines `14-38` (current file tail before insertion at line `39`):
```cpp
14 | {
15 | public:
16 |     // Plays BGM via tp::Audio one-shot playback (non-looping in current wrapper).
17 |     bool PlayBGM(const std::string& path);
18 |     // Clears AudioManager's tracked BGM state.
19 |     // Current tp::Audio wrapper does not support stopping an already-playing one-shot.
20 |     void StopBGM();
21 |     bool PlaySFX(const std::string& path);
22 | 
23 |     void SetBGMVolume(float v);
24 |     void SetSFXVolume(float v);
25 |     float GetBGMVolume() const { return m_bgmVolume; }
26 |     float GetSFXVolume() const { return m_sfxVolume; }
27 | 
28 |     void Shutdown();
29 | 
30 | private:
31 |     static float Clamp01(float v);
32 | 
33 |     float m_bgmVolume = 1.0f;
34 |     float m_sfxVolume = 1.0f;
35 |     bool m_loggedBgmVolumeLimit = false;
36 |     bool m_loggedSfxVolumeLimit = false;
37 |     bool m_bgmRequested = false;
38 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/audio/AudioManager.hpp
EDIT MODE: append-first
INSERT AT LINE: 39
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 14-38
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.cpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp`
- File does not exist yet; create this file and follow the line budget from the table above.
```text
CREATE FILE: /home/runner/work/GameRewritten/GameRewritten/src/app/QualityPreset.hpp
Add new code at line 1.
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp`
- Anchor lines `354-378` (current file tail before insertion at line `379`):
```cpp
354 |     const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
355 |     const float edgeScale = std::min(scaleX, scaleY);
356 | 
357 |     const float indicatorX = centerX + dirX * edgeScale;
358 |     const float indicatorY = centerY + dirY * edgeScale;
359 | 
360 |     // --- Step 4: draw subtle lock-on arrow marker ---
361 |     ImDrawList* drawList = ImGui::GetForegroundDrawList();
362 |     if (!drawList)
363 |         return;
364 | 
365 |     const ImVec2 indicatorCenter(indicatorX, indicatorY);
366 |     drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
367 |     drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);
368 | 
369 |     const float perpX = -dirY;
370 |     const float perpY = dirX;
371 |     const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
372 |                      indicatorY + dirY * kOffscreenArrowSize);
373 |     const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
374 |                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
375 |     const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
376 |                        indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
377 |     drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
378 | }
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.cpp
EDIT MODE: append-first
INSERT AT LINE: 379
MAX EXISTING LINES TO MODIFY: 28
TARGET NEW LINES TO ADD: 70
ANCHOR RANGE: 354-378
```

#### `/home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp`
- Anchor lines `16-40` (current file tail before insertion at line `41`):
```cpp
16 | class GameHUD
17 | {
18 | public:
19 |     // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
20 |     void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);
21 | 
22 |     // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
23 |     // Pass nullptr when no enemy is locked on; the panel stays hidden.
24 |     void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
25 | 
26 |     // Draw the active combo step indicator above the target panel.
27 |     // Only visible while the combo window is open (comboTimer > 0).
28 |     // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
29 |     // avoid coupling GameHUD to the combat system header.
30 |     void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);
31 | 
32 |     // Draw a subtle edge indicator when the lock-on target is outside the screen.
33 |     void DrawOffScreenTargetIndicator(const EnemyActor* target,
34 |                                       float camX, float camY, float camZ,
35 |                                       float yaw, float pitch,
36 |                                       float vpW, float vpH) const;
37 | 
38 | private:
39 |     float m_lowHpPulseTime = 0.0f;
40 | };
```
- Copy packet for this file:
```text
FILE: /home/runner/work/GameRewritten/GameRewritten/src/ui/GameHUD.hpp
EDIT MODE: append-first
INSERT AT LINE: 41
MAX EXISTING LINES TO MODIFY: 18
TARGET NEW LINES TO ADD: 40
ANCHOR RANGE: 16-40
```

- **Task prompt block (copy exactly):**
```text
Implement Task 060: Audio and final quality sweep.
Use this task card only (File Edit Plan + Qwen Step Packets + Code Context Blocks).
Apply append-first edits at listed Insert At Line values unless compile errors force nearby replacement.
Do not exceed Modify Existing Lines (max) per file.
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

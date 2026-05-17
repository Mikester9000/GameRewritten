# Task Queue

Tasks are listed smallest-first. The top task is always next after NEXT_TASK.md is done.

When NEXT_TASK.md is complete:
1. Move the top task from this file into NEXT_TASK.md (replace its content).
2. Delete that task from this queue.
3. Add a completion entry to AGENT_WORK_LOG.md.

---

## Task 1 — Hit Pause / Hitstop

**System:** Hit pause / hitstop  
**Status in SYSTEMS.md:** ❌ Not started (line 80)  
**Files to touch:** `src/game/RuntimeScene.hpp` only  
**Scope:** ~15 lines — add a timer and a freeze multiplier

**What it does:**  
When the player's attack lands, gameplay briefly freezes for ~0.08 seconds (hitstop),
making impacts feel punchy. Time scale drops to near zero then snaps back.

**What to add inside `RuntimeScene`:**  
- Private member: `float m_hitStopTimer = 0.0f;`
- In `BeginFrame`: if `m_hitStopTimer > 0`, reduce it by real `dt`, pass 0 for `scaledDt` to all updates; else pass `dt` normally.
- Call `m_hitStopTimer = 0.08f;` wherever an enemy successfully takes damage (look for `enemy.TakeDamage` calls in RuntimeScene.cpp).

**DO NOT:** add new files, change Main.cpp, modify CombatSystem or EnemyActor.

---

## Task 2 — Camera Shake on Player Hit

**System:** Camera shake  
**Status in SYSTEMS.md:** ❌ Not started (line 98)  
**Files to touch:** `src/game/CameraController.hpp`, `src/game/CameraController.cpp`  
**Scope:** ~20 lines

**What it does:**  
When the player takes a hit, the camera shakes for 0.25 seconds with decreasing intensity.

**What to add:**  
- Two private members: `float m_shakeTimer = 0.0f;` and `float m_shakeIntensity = 0.0f;`
- Public method: `void TriggerCameraShake(float durationSec, float intensity);`
- In `Update()`: if `m_shakeTimer > 0`, subtract `dt`, apply a small random or sine offset to the view (1–2 units max) scaled by remaining timer ratio.
- Main.cpp calls `camController.TriggerCameraShake(0.25f, 0.4f);` when player HP drops.

**DO NOT:** add new files, change any other system, increase shake beyond 1 unit on GT610.

---

## Task 3 — Enemy Attack Telegraph Lite

**System:** Enemy attack telegraph lite  
**Status in SYSTEMS.md:** ❌ Not started (line 77)  
**Files to touch:** `src/game/actors/EnemyActor.hpp`, `src/game/actors/EnemyActor.cpp`  
**Scope:** ~15 lines

**What it does:**  
0.25 seconds before an enemy fires its attack hitbox, it visually telegraphs: draw a small
ImGui warning marker above the enemy (exclamation point or color change in the debug overlay).

**What to add:**  
- Private member: `float m_telegraphTimer = 0.0f;`
- In `Update()`: when transitioning to the Attack state, set `m_telegraphTimer = 0.25f;`
- While `m_telegraphTimer > 0`, tick it down; only release the attack hitbox when it reaches zero.
- In `SubmitRuntimeVisual` or existing overlay draw: if timer > 0, draw a small yellow "!" above the enemy using `ImGui::GetForegroundDrawList()`.

**DO NOT:** add new files, add new classes, change CombatSystem.

---

## Task 4 — Area Name Display

**System:** Area name display  
**Status in SYSTEMS.md:** ❌ Not started (line 87)  
**Files to touch:** `src/ui/GameHUD.hpp`, `src/ui/GameHUD.cpp`, `src/app/Main.cpp`  
**Scope:** ~25 lines

**What it does:**  
When the player crosses into a new world cell, show the area name centered on screen for 2.5
seconds, then fade it out over 0.5 seconds. Text is large, styled like FF7.

**What to add:**  
- Members on GameHUD: `float m_areaNameTimer = 0.0f;` and `char m_areaName[64] = {};`
- Public method: `void ShowAreaName(const char* name);` — sets name + resets timer to 3.0f.
- Private method: `void DrawAreaName(float dt);` — draws faded text when timer > 0.
- Call `DrawAreaName(dt)` from `GameHUD::Draw()`.
- Main.cpp calls `gameHud.ShowAreaName(...)` when the world cell changes.

**DO NOT:** add new files, use `std::string` for the area name (use `char[64]`).

---

## Task 5 — Death / Defeat Screen

**System:** Death / defeat screen  
**Status in SYSTEMS.md:** ❌ Not started (line 96)  
**Files to touch:** `src/ui/GameHUD.hpp`, `src/ui/GameHUD.cpp`, `src/app/Main.cpp`  
**Scope:** ~20 lines

**What it does:**  
When the player dies, show a red "DEFEATED" overlay with fade-in for 1.5 seconds before
the respawn teleport. Screen goes dark with text.

**What to add:**  
- Member on GameHUD: `float m_defeatOverlayTimer = 0.0f;`
- Public method: `void TriggerDefeatOverlay();` — sets timer to 1.5f.
- Private method: `void DrawDefeatOverlay(float dt);` — dark full-screen rect + "DEFEATED" text.
- Call `DrawDefeatOverlay(dt)` from `GameHUD::Draw()`.
- Main.cpp calls `gameHud.TriggerDefeatOverlay()` when `runtimeScene.WantsRespawn()` is true.

**DO NOT:** add new files, delay the respawn — still teleport on the same frame.

---

## Task 6 — Looping Background Music

**System:** Looping BGM  
**Status in SYSTEMS.md:** ❌ Not started (line 127)  
**Files to touch:** `src/audio/AudioManager.hpp`, `src/audio/AudioManager.cpp`  
**Scope:** ~20 lines

**What it does:**  
Play a looping background music track from `Content/Audio/` using the existing
`tp::Audio` wrapper. Expose `PlayBGM(const char* path)` and `StopBGM()`.

**What to add:**  
- Private member: `ma_sound m_bgmSound;` and `bool m_bgmLoaded = false;`
- `PlayBGM(const char* path)` — load, set looping flag, and start the sound.
- `StopBGM()` — stop and unload cleanly.
- Call `audioManager.PlayBGM("Content/Audio/battle_theme.wav")` from Main.cpp at startup.

**DO NOT:** add new audio libraries, block the frame loop with synchronous I/O.

---

## Task 7 — Wind Effect on Trees

**System:** Wind effect on trees  
**Status in SYSTEMS.md:** ❌ Not started (line 103)  
**Files to touch:** `Shaders/tree_vs.hlsl`, `src/rendering/d3d11/D3D11Renderer.hpp`, `src/rendering/d3d11/D3D11Renderer.cpp`  
**Scope:** ~15 shader lines + ~10 C++ lines

**What it does:**  
Top vertices of tree geometry sway on a sine wave driven by a time uniform passed to the
vertex shader. Effect is subtle — max sway 0.15 units, 0.8 Hz.

**What to add in shader:**  
- Accept a new constant buffer or extend the existing one: `float g_time;`
- In `tree_vs`, offset top-vertex X by `sin(g_time * 5.0f + worldPos.z) * 0.15 * topFactor`
  where `topFactor` is `saturate(worldPos.y / 4.0)` (only upper vertices sway).

**What to add in C++:**  
- Pass accumulated `totalTime` through the renderer's existing constant buffer path.

**DO NOT:** add a new constant buffer slot — reuse an existing unused float if possible.

---

## Task 8 — Hit Pause + Damage Flash Integration Cleanup

*(Not a new system — consolidation pass.)*  
**Files to touch:** `src/app/Main.cpp` only  
**Scope:** ~10 lines

After Tasks 1 and 2 are complete, consolidate the two `playerActor.stats.hp < prevHp` checks in
Main.cpp into a single `bool tookDamage = ...` flag so both camera shake and damage flash read
from the same check.

**DO NOT:** change any other file.

---

*Add new tasks below this line as the queue grows.*

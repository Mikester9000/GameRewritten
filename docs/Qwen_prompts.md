# Qwen 2.5 7B — **Lego‑Block Code Tasks (Aligned to Repo Docs)**

This file is **strictly aligned** to these docs (source of truth):
- `docs/CURRENT_STATE.md`
- `docs/SYSTEMS.md`
- `docs/FULL_TASK_SEQUENCE.md`
- `docs/GRAPHICS_VISION.md`
- `docs/UI_VISION.md`
- `docs/COMBAT_VISION.md`
- `docs/PERFORMANCE_GUARDRAILS.md`

**Only implement systems marked ❌ in `docs/SYSTEMS.md`**. Do **not** rebuild ✅ systems. Do **not** add new dependencies. Keep GT610 guardrails.

---

## Usage Rules (for every prompt)
- Qwen has **no repo access**. You must paste required files.
- Keep prompts **small** and **single‑purpose**.
- Output **only final code or exact patch steps**. No explanations.
- If adding a new `.cpp`, ask Qwen to list **exact `.vcxproj` + `.vcxproj.filters` edits**.

**Output format rule (use in every prompt)**
> Output only the final code or exact patch steps. No explanations.

---

# LEGO BLOCKS — **Exactly the ❌ items from SYSTEMS.md**

> Use **one block at a time**. Each block maps 1:1 to a SYSTEMS.md ❌ entry and the task order in FULL_TASK_SEQUENCE.md.

---

## PHASE 1 — Combat + HUD foundation (Tasks 001–019)

### BLOCK 001 — Pressure / stagger integration stub
**Files:** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
**Prompt**
> I will paste the listed files. Implement the smallest pressure/stagger stub as described in COMBAT_VISION.md. Keep it reversible and minimal. Output updated files only.

### BLOCK 002 — Enemy reaction / interrupt‑lite
**Files:** `src/game/actors/EnemyActor.cpp/hpp`, `src/game/combat/CombatSystem.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a minimal interrupt‑lite reaction on hit (small flinch/brief state change). Output updated files only.

### BLOCK 003 — Enemy attack telegraph lite
**Files:** `src/game/actors/EnemyActor.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a lightweight telegraph (short wind‑up state + tint). Output updated files only.

### BLOCK 004 — Screen edge damage flash
**Files:** `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a low‑cost red edge flash on player damage using ImGui draw list. Output updated files only.

### BLOCK 005 — Hit pause / hitstop
**Files:** `src/game/RuntimeScene.hpp`
**Prompt**
> I will paste the listed files. Add a minimal hitstop (1–3 frames) on successful hits. Output updated files only.

### BLOCK 006 — Stagger meter
**Files:** `src/game/actors/EnemyActor.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a basic stagger meter that fills on damage and triggers a brief vulnerable state. Output updated files only.

### BLOCK 007 — Enemy attack telegraph (full)
**Files:** `src/game/actors/EnemyActor.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a clearer telegraph phase (timed wind‑up + stronger tint). Output updated files only.

### BLOCK 008 — Parry / counter window
**Files:** `src/game/actors/PlayerActor.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a tiny parry window tied to dodge timing. Output updated files only.

### BLOCK 009 — Weak point damage
**Files:** `src/game/combat/CombatSystem.cpp/hpp`
**Prompt**
> I will paste the listed files. Add behind‑target angle check for bonus damage. Output updated files only.

### BLOCK 010 — Area name display
**Files:** `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files. Add area name fade‑in/out display when entering new cell. Output updated files only.

### BLOCK 011 — Notification toast system
**Files:** `src/ui/NotificationSystem.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a small toast queue system (text + timer) and drawing. Output updated/new files only.

### BLOCK 012 — Letterbox event bars
**Files:** `src/ui/ImGuiLayer.cpp/hpp`
**Prompt**
> I will paste the listed files. Add letterbox bars (top/bottom) toggleable for events. Output updated files only.

### BLOCK 013 — Contextual button prompts
**Files:** `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files. Add simple context prompts (string + key) near player. Output updated files only.

### BLOCK 014 — Level up screen overlay
**Files:** `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a timed “Level Up” overlay with stat deltas. Output updated files only.

### BLOCK 015 — Status screen
**Files:** `src/ui/StatusScreen.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a classic FF‑style status screen using ImGui. Output updated/new files only.

### BLOCK 016 — Map screen stub
**Files:** `src/ui/MapScreen.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a stub map screen using existing minimap data. Output updated/new files only.

### BLOCK 017 — Tooltip system
**Files:** `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a minimal tooltip system (title + body) for UI elements. Output updated files only.

### BLOCK 018 — Saving indicator
**Files:** `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a small “Saving…” indicator that fades in/out. Output updated files only.

### BLOCK 019 — Death / defeat screen
**Files:** `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a full‑screen defeat overlay with respawn prompt. Output updated files only.

---

## PHASE 2 — Camera + visual polish (Tasks 020–030)

### BLOCK 020 — Camera shake
**Files:** `src/game/CameraController.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a simple camera shake (small random offset) on hit events. Output updated files only.

### BLOCK 021 — Combat camera zoom
**Files:** `src/game/CameraController.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a small FOV zoom when lock‑on active (lerp). Output updated files only.

### BLOCK 022 — Camera collision avoidance
**Files:** `src/game/CameraController.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a simple raycast to prevent camera clipping. Output updated files only.

### BLOCK 023 — Target framing adjustment
**Files:** `src/game/CameraController.cpp/hpp`
**Prompt**
> I will paste the listed files. Shift camera framing to keep player + target in view. Output updated files only.

### BLOCK 024 — Lock‑on camera recovery smoothing
**Files:** `src/game/CameraController.cpp/hpp`
**Prompt**
> I will paste the listed files. Add smoothing when exiting lock‑on. Output updated files only.

### BLOCK 025 — Wind effect on trees
**Files:** `Shaders/tree_vs.hlsl`
**Prompt**
> I will paste the shader. Add a cheap sine‑wave vertex sway for tree instances. Output updated shader only.

### BLOCK 026 — Weather system lite
**Files:** `src/world/WeatherSystem.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a minimal weather state (clear/rain/fog) with simple parameters. Output updated/new files only.

### BLOCK 027 — Ambient particles
**Files:** `src/game/ParticleSystem.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a minimal particle system for low‑count ambient particles. Output updated/new files only.

### BLOCK 028 — Day/night cycle
**Files:** `src/world/DayNightCycle.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a simple time‑of‑day lerp for light/ambient colors. Output updated/new files only.

### BLOCK 029 — Biome transition fade
**Files:** `src/world/WorldGrid.cpp/hpp`
**Prompt**
> I will paste the listed files. Add biome transition fade (color lerp). Output updated files only.

### BLOCK 030 — Fog of war on minimap
**Files:** `src/ui/Minimap.cpp/hpp`
**Prompt**
> I will paste the listed files. Add simple fog‑of‑war reveal using visited cells. Output updated files only.

---

## PHASE 3 — World + quest + progression core (Tasks 031–045)

### BLOCK 031 — World event trigger zones
**Files:** `src/game/world/EventZone.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add simple trigger zones with enter/exit callbacks. Output updated/new files only.

### BLOCK 032 — Interaction hotspot registry stub
**Files:** `src/game/world/InteractionRegistry.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a registry for interactable hotspots with IDs and positions. Output updated/new files only.

### BLOCK 033 — Landmark discovery trigger stub
**Files:** `src/game/world/LandmarkTrigger.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a landmark trigger with “discovered” state. Output updated/new files only.

### BLOCK 034 — NPC actor
**Files:** `src/game/actors/NpcActor.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a simple NPC actor with idle + interaction prompt. Output updated/new files only.

### BLOCK 035 — Quest objective system
**Files:** `src/game/quest/QuestSystem.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a minimal quest objective list (id, state). Output updated/new files only.

### BLOCK 036 — Treasure chest actor
**Files:** `src/game/actors/ChestActor.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a chest actor that grants an item once. Output updated/new files only.

### BLOCK 037 — Campfire / rest point actor
**Files:** `src/game/actors/RestPointActor.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a rest point that restores HP/MP and shows a prompt. Output updated/new files only.

### BLOCK 038 — NPC interaction prompt routing stub
**Files:** `src/ui/GameHUD.cpp/hpp`, `src/game/world/InteractionRegistry.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a simple prompt routing from nearby interaction to HUD display. Output updated files only.

### BLOCK 039 — Quest flag / world‑state hook
**Files:** `src/game/quest/QuestFlags.hpp`, `src/game/quest/QuestSystem.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a small quest flag map (string→bool/int). Output updated/new files only.

### BLOCK 040 — Spawn composition table stub
**Files:** `src/world/SpawnTable.hpp`, `src/world/WorldGrid.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a simple spawn table (solo/pair/pack). Output updated/new files only.

### BLOCK 041 — Inventory system
**Files:** `src/game/inventory/Inventory.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a minimal inventory (items list + add/remove). Output updated/new files only.

### BLOCK 042 — XP / level system
**Files:** `src/game/actors/PlayerStats.hpp`
**Prompt**
> I will paste the listed files. Add XP/level fields and simple level‑up rule. Output updated files only.

### BLOCK 043 — Status effects
**Files:** `src/game/actors/PlayerStats.hpp`
**Prompt**
> I will paste the listed files. Add a minimal status effects list (type + duration). Output updated files only.

### BLOCK 044 — Fast travel stub
**Files:** `src/game/world/FastTravel.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a minimal fast‑travel list + trigger stub. Output updated/new files only.

### BLOCK 045 — Save / load system
**Files:** `src/app/SaveSystem.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement a minimal versioned save/load stub (player position + stats). Output updated/new files only.

---

## PHASE 4 — Audio + quality + progression glue (Tasks 046–055)

### BLOCK 046 — Quality preset enforcement
**Files:** `src/app/QualityPreset.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Implement Low/Medium/High preset toggles and apply to renderer paths. Output updated/new files only.

### BLOCK 047 — Victory fanfare trigger
**Files:** `src/audio/AudioManager.cpp/hpp`
**Prompt**
> I will paste the listed files. Play a fanfare sound when enemies are cleared. Output updated files only.

### BLOCK 048 — Environmental ambient audio
**Files:** `src/audio/AudioManager.cpp/hpp`
**Prompt**
> I will paste the listed files. Add looping ambient audio by biome or region. Output updated files only.

### BLOCK 049 — Looping BGM
**Files:** `src/audio/AudioManager.cpp/hpp`
**Prompt**
> I will paste the listed files. Add looping background music with fade in/out. Output updated files only.

### BLOCK 050 — Tactical Pause enter/exit SFX
**Files:** `src/audio/AudioManager.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
**Prompt**
> I will paste the listed files. Add SFX on tactical pause open/close. Output updated files only.

### BLOCK 051 — Lock‑on acquire/break SFX
**Files:** `src/audio/AudioManager.cpp/hpp`, `src/game/combat/Targeting.hpp`
**Prompt**
> I will paste the listed files. Add SFX on lock‑on acquire and break. Output updated files only.

### BLOCK 052 — Enemy alert bark stub
**Files:** `src/audio/AudioManager.cpp/hpp`, `src/game/actors/EnemyActor.cpp/hpp`
**Prompt**
> I will paste the listed files. Add a single alert bark on enemy detect. Output updated files only.

### BLOCK 053 — Equipment slot stub
**Files:** `src/game/inventory/Equipment.hpp`, `src/game/actors/PlayerStats.hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add minimal equipment slots (weapon/armor/accessory). Output updated/new files only.

### BLOCK 054 — Ability unlock / progression hook
**Files:** `src/game/progression/AbilityProgression.hpp`, `src/game/actors/PlayerStats.hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add simple ability unlock tracking (id + unlocked). Output updated/new files only.

### BLOCK 055 — Combat stat modifier pipeline stub
**Files:** `src/game/combat/CombatModifiers.hpp`, `src/game/combat/CombatSystem.cpp/hpp`
**Prompt**
> I will paste the listed files (or empty if new). Add a minimal modifier pipeline (additive/multiplicative). Output updated/new files only.

---

## PHASE 5 — Polish sweeps (Tasks 056–060)

### BLOCK 056 — Combat bugfix sweep
**Files:** `src/game/combat/CombatSystem.cpp/hpp`, `src/game/RuntimeScene.hpp`, `src/app/Main.cpp`
**Prompt**
> I will paste the listed files and known issues. Propose minimal fixes only. Output updated files only.

### BLOCK 057 — Camera/input bugfix sweep
**Files:** `src/game/CameraController.cpp/hpp`, `src/app/InputActionMap.hpp`, `src/app/Main.cpp`
**Prompt**
> I will paste the listed files and known issues. Propose minimal fixes only. Output updated files only.

### BLOCK 058 — UI/HUD polish sweep
**Files:** `src/ui/GameHUD.cpp/hpp`, `src/ui/ImGuiLayer.cpp/hpp`, `src/ui/TacticalPauseMenu.cpp/hpp`
**Prompt**
> I will paste the listed files and known issues. Apply low‑risk UI polish aligned with UI_VISION.md. Output updated files only.

### BLOCK 059 — World/runtime stability sweep
**Files:** `src/world/WorldGrid.cpp/hpp`, `src/game/RuntimeScene.cpp/hpp`, `src/game/Forest.cpp/hpp`
**Prompt**
> I will paste the listed files and known issues. Apply minimal stability fixes only. Output updated files only.

### BLOCK 060 — Audio + quality sweep
**Files:** `src/audio/AudioManager.cpp/hpp`, `src/app/QualityPreset.cpp/hpp`, `src/ui/GameHUD.cpp/hpp`
**Prompt**
> I will paste the listed files and known issues. Apply minimal fixes + GT610 safety pass. Output updated files only.

---

# Notes for Qwen Prompts (alignment reminders)
- **Do not add** new renderers or heavy post‑process. Respect `GRAPHICS_VISION.md`.
- **UI style** must follow `UI_VISION.md` (action HUD vs classic menu windows).
- **Combat** must follow `COMBAT_VISION.md` (simple, readable, no complex FSM).
- **Performance** must follow `PERFORMANCE_GUARDRAILS.md` (Low preset safe).
- **Never rebuild** anything already ✅ in `SYSTEMS.md`.

---

# Universal “Write Code For This File” Prompt
**Prompt**
> I will paste a single file and a small change request. Apply the change. Output only the full updated file. No explanations.

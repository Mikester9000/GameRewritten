# LLM Instructions (Tiny-Context, Single-File Guide)

**Purpose:** This file is the **only** thing the lightweight LLM needs to read first. It provides the current goal, a complete ordered task list to reach a commercially sellable game, and the rules for tiny-context execution.

---

## 0) Non‑Negotiable Constraints (Tiny Context)
- **One task per run.** Stop after completing the task.
- **Read only the files listed in the task.** Do not roam the repo.
- **Keep edits minimal and local.** No refactors unless explicitly required.
- **Do not add new dependencies.**
- **Keep GT 610 / low‑spec performance safe.**
- **Avoid growing `src/app/Main.cpp`.** If you must touch it, keep changes tiny.
- **Do not move/rename files.**
- **Update docs when a task says so.**

If you cannot complete a task within tiny context, **split it into a smaller safe sub‑task**, then stop and report the split.

---

## 1) Current Goal / Milestone (as of 2026‑05‑19)
**Goal:** Finish the remaining systems and polish passes to reach a **commercially sellable** action‑RPG build with FF7 Remake-like gameplay readability, PS2-style cost-aware visuals, and robust audio/event readiness.

**Immediate focus:** Continue the **Autopilot Task Sequence** (see Section 3) through expanded open-world multi-continent scope, gameplay depth, and ship-readiness gates.

---

## 2) Current State Snapshot (Do NOT Rebuild)
Already implemented and working:
- Booting Win32 + D3D11 renderer.
- Playable loop: movement, combat, enemy chase/attack/hit/death, HUD, lock‑on, dodge, combo, Surge/Limit, respawn.
- World grid + runtime actors + UI basics.

**Do not replace:** combat baseline loop, world/editor registry flow, D3D11 core setup, runtime scene ownership.

---

## 3) Master Task List (Ordered, Complete, From Current State → Commercial)
**Rule:** Do tasks in order, one per run. If `docs/NEXT_TASK.md` exists, follow it. Otherwise start at Task 001.

### Phase 1 — Combat + HUD foundation
001 Pressure / stagger integration stub
002 Enemy reaction / interrupt-lite
003 Enemy attack telegraph lite
004 Screen edge damage flash
005 Hit pause / hitstop
006 Stagger meter
007 Enemy attack telegraph
008 Parry / counter window
009 Weak point damage
010 Area name display
011 Notification toast system
012 Letterbox event bars
013 Contextual button prompts
014 Level up screen overlay
015 Status screen
016 Map screen stub
017 Tooltip system
018 Saving indicator
019 Death / defeat screen

### Phase 2 — Camera + visual polish
020 Camera shake
021 Combat camera zoom
022 Camera collision avoidance
023 Target framing adjustment
024 Lock-on camera recovery smoothing
025 Wind effect on trees
026 Weather system lite
027 Ambient particles
028 Day/night cycle
029 Biome transition fade
030 Fog of war on minimap

### Phase 3 — World + quest + progression core
031 World event trigger zones
032 Interaction hotspot registry stub
033 Landmark discovery trigger stub
034 NPC actor
035 Quest objective system
036 Treasure chest actor
037 Campfire / rest point actor
038 NPC interaction prompt routing stub
039 Quest flag / world-state hook
040 Spawn composition table stub (solo / pair / pack)
041 Inventory system
042 XP / level system
043 Status effects
044 Fast travel stub
045 Save / load system

### Phase 4 — Audio + quality + progression glue
046 Quality preset enforcement
047 Victory fanfare trigger
048 Environmental ambient audio
049 Looping BGM
050 Tactical Pause enter / exit SFX
051 Lock-on acquire / break SFX
052 Enemy alert bark stub
053 Equipment slot stub
054 Ability unlock / progression hook
055 Combat stat modifier pipeline stub

### Phase 5 — Mandatory polish + stability sweeps
056 Combat bugfix sweep
057 Camera/input bugfix sweep
058 UI/HUD polish and bugfix sweep
059 World/runtime stability sweep
060 Audio and final quality sweep

### Phase 6 — Open-world scale foundation (multi-continent)
061 World partition + region streaming core
062 Asynchronous chunk IO + prefetch queue
063 Large-world coordinate rebasing
064 Terrain/mesh LOD tier manager
065 Streaming budget governor (CPU/GPU/IO)
066 Far-distance continent impostors
067 Global nav tile streaming bridge
068 Seamless continent transition triggers
069 Traversal mount/vehicle framework stub
070 Traversal verbs: climb/swim/glide base
071 Seamless interior/exterior cell portals
072 World map overlay with continent zoom
073 Discovery journal for landmarks/routes
074 Biome-aware population spawn director
075 World event scheduler (time/weather/region)
076 Region state persistence for streamed world

### Phase 7 — FF7R-style gameplay depth (party/combat/progression)
077 Party member runtime slot + follow AI
078 Command wheel + tactical slow-time commands
079 ATB-style action charge lanes
080 Ability targeting templates (single/cone/aoe)
081 Enemy archetype behavior profiles
082 Enemy squad tactics coordinator
083 Boss phase state machine framework
084 Guard-break / poise combat pipeline
085 Elemental damage/resistance matrix
086 Status ailment counters + immunity windows
087 Equipment progression + socket rules
088 Skill tree graph + unlock prerequisites
089 Loot table tiers + drop weighting
090 Crafting + upgrade station flow
091 Open-world encounter director
092 Combat telemetry + balance debug panel

### Phase 8 — Audio/content pipeline + ship readiness
093 Quest authoring schema + validator
094 Dialogue branching + localization keys
095 Cutscene timeline stub + camera rails
096 Audio event router + mixer bus controls
097 Adaptive music state machine
098 SFX variation + distance/occlusion rules
099 Voice placeholder + subtitle timing pipeline
100 Save versioning + migration compatibility
101 Crash capture + runtime diagnostics pack
102 Full settings menu (graphics/audio/input/accessibility)
103 Input rebinding + controller glyph profiles
104 Performance HUD + auto quality scaler
105 Build packaging + release manifest scripts
106 Legal/credits/third-party attribution pass
107 New game bootstrap + onboarding tutorial
108 Vertical-slice certification and ship checklist

**Definition of done for each task:**
- Smallest viable implementation exists.
- It is wired into runtime flow and visible/usable.
- Low‑spec safe.
- Docs updated if required by the task.

---

## 4) Commercial‑Readiness Checklist (After Task 108)
These are required for a **sellable** build even if not fully specified in code yet. If any item is missing, create the smallest safe stub and document it.

**Release‑critical:**
- **Stability:** no crashers in 30‑minute soak run.
- **Performance:** stable frame time on target low‑spec GPU.
- **Save/Load:** reliable persistence and recovery, including save migration support.
- **Settings:** quality/input/audio/accessibility settings persist and apply correctly.
- **Content Minimum:** at least one complete region loop with combat + NPC interaction + reward.
- **Open World:** multi-continent streaming traversal works without hard loading gates in normal play flow.
- **User Feedback:** readable HUD, clear hit feedback, and meaningful audio cues.
- **Legal:** third‑party license list is accurate (see docs/THIRD_PARTY.md).
- **Packaging:** reproducible Release build steps documented and verifiable.

**Commercial polish (minimum acceptable):**
- Tutorial/onboarding playable start flow.
- Credits/legal screens complete.
- Pause/options menu polish and controller-safe navigation.
- Clean fallback/error handling for missing assets.
- Vertical-slice checklist passes documented in `docs/SHIP_CHECKLIST.md`.

If any of these are not fully implemented, **create a minimal stub** with clear TODO notes and log it in docs.

---

## 5) Tiny‑Context Task Execution Protocol
1) Open this file.
2) Determine next task (prefer `docs/NEXT_TASK.md`).
3) Read only the files listed by the task.
4) Implement smallest viable version.
5) Update required docs if the task demands it.
6) Stop.

**Do not do multiple tasks in one run.**

---

## 6) If You Get Stuck
- **Do not explore.**
- **Stop and report the blocker.**
- Suggest the smallest sub‑task that would unblock progress.

---

## 7) Quick Reference (Source Docs)
These exist for deeper detail, but **do not read them unless the task explicitly requires it**:
- `docs/CURRENT_STATE.md`
- `docs/FINAL_GOAL.md`
- `docs/FULL_TASK_SEQUENCE.md`
- `docs/PLANNED_FEATURES.md`
- `docs/QUALITY_BAR.md`

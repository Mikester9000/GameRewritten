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

## 1) Current Goal / Milestone (as of 2026‑05‑18)
**Goal:** Finish the remaining systems and polish passes to reach a **commercially sellable** action‑RPG build that is stable, readable, and consistent with the FF7‑style presentation target.

**Immediate focus:** Continue the **Autopilot Task Sequence** (see Section 3) to complete combat/HUD foundation, camera/visual polish, world/quest/progression core, audio/quality glue, and final polish sweeps.

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
002 Enemy reaction / interrupt‑lite
003 Enemy attack telegraph lite
004 Screen edge damage flash
005 Hit pause / hitstop
006 Stagger meter
007 Enemy attack telegraph (full)
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
024 Lock‑on camera recovery smoothing
025 Wind effect on trees (shader)
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
039 Quest flag / world‑state hook
040 Spawn composition table stub
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
050 Tactical Pause enter/exit SFX
051 Lock‑on acquire/break SFX
052 Enemy alert bark stub
053 Equipment slot stub
054 Ability unlock / progression hook
055 Combat stat modifier pipeline stub

### Phase 5 — Mandatory polish + stability sweeps
056 Combat bugfix sweep
057 Camera/input bugfix sweep
058 UI/HUD polish + bugfix sweep
059 World/runtime stability sweep
060 Audio + final quality sweep

**Definition of done for each task:**
- Smallest viable implementation exists.
- It is wired into runtime flow and visible/usable.
- Low‑spec safe.
- Docs updated if required by the task.

---

## 4) Commercial‑Readiness Checklist (After Task 060)
These are required for a **sellable** build even if not fully specified in code yet. If any item is missing, create the smallest safe stub and document it.

**Release‑critical:**
- **Stability:** no crashers in 30‑minute soak run.
- **Performance:** stable frame time on target low‑spec GPU.
- **Save/Load:** reliable persistence and recovery.
- **Settings:** quality preset enforcement and basic settings persistence.
- **Content Minimum:** at least one complete region loop with combat + NPC interaction + reward.
- **User Feedback:** readable HUD, clear hit feedback, audio cues.
- **Legal:** third‑party license list is accurate (see docs/THIRD_PARTY.md).
- **Packaging:** reproducible Release build steps documented.

**Commercial polish (minimum acceptable):**
- Tutorial/onboarding stub (even if short).
- Credits screen.
- Basic pause/options menu polish.
- Clean error handling for missing assets.

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

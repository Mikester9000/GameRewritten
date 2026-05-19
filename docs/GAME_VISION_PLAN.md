# Game Vision Plan
**Date:** 2026-05-13

---

## Vision Statement

Build a 3D action RPG that:

- **Plays like FF15 or FF7 Remake** — real-time action combat, lock-on targeting, dodge + combo attacks, Tactical Pause, readable enemy pressure, and an open explorable world.
- **Looks like FF7 (original)** — stylised "blockout" characters built from simple coloured box primitives, flat-shaded palette-driven art, no expensive PBR or physically-based lighting.
- **Targets low-spec hardware** — DirectX 11 / GeForce GT 610, forward rendering, ≤ 200 draw calls on Low quality, ≤ 512 MB GPU memory.

The result is a modern open-world action game that retains the charm of old-school construction techniques while delivering the moment-to-moment feel of a modern JRPG.

---

## Current State Assessment (2026-05-13)

### What is done and working

| Area | Status | Key files |
|------|--------|-----------|
| Win32 window + D3D11 device | ✅ Complete | `src/platform/win32/`, `src/rendering/d3d11/D3D11Renderer.*` |
| Sky, terrain, ground, tree shaders | ✅ Complete | `Shaders/sky_*/ground_*/tree_*/prim_*/basic3d_*` |
| Directional sun lighting (diffuse + ambient) | ✅ Complete | `Shaders/*_ps.hlsl` b1 `LightCBuffer`, `D3D11Renderer.*` |
| Texture cache (DirectXTex, SRV upload) | ✅ Complete | `src/assets/TextureCache.*` |
| World grid + multi-biome terrain | ✅ Complete | `src/world/WorldGrid.*`, `Content/World/` |
| Primitive prefab system (JSON → box parts) | ✅ Complete | `src/game/PrefabDef.hpp`, `PrefabLibrary.*`, `PrimitiveRenderer.*` |
| World editor (place/delete, cell save/reload) | ✅ Complete | `src/ui/WorldEditor.*`, `src/app/WorldEditorFrameOps.*` |
| Biome-aware asset registry (50+ prefabs) | ✅ Complete | `Content/AssetRegistry.json`, `Content/Prefabs/` |
| FF7-style player blockout visual | ✅ Complete | `Content/Prefabs/player_hero_blockout.prefab.json` |
| Player runtime actor (follows camera, submits each frame) | ✅ Complete | `src/game/actors/PlayerActor.*`, `src/game/RuntimeScene.hpp` |
| Player stats: HP / MP / Surge / Limit | ✅ Complete | `src/game/actors/PlayerStats.hpp` |
| Input action map (W/A/S/D, F, Q, Tab, Space …) | ✅ Complete | `src/app/InputActionMap.hpp` |
| AABB prefab collision (push-out on movement) | ✅ Complete | `src/game/physics/CollisionWorld.*`, `CameraController.*` |
| Enemy actor | ✅ Complete | `src/game/actors/EnemyActor.*` |
| Enemy combat states (chase/attack/hit) | ✅ Complete | `src/game/actors/EnemyActor.*`, `src/game/actors/EnemyState.hpp` |
| Combat system | ✅ Complete | `src/game/combat/CombatSystem.*`, `src/game/RuntimeScene.hpp` |
| Player action state machine | ✅ Complete | `src/game/actors/PlayerActionState.hpp`, `src/game/actors/PlayerActor.*` |
| Dodge burst movement | ✅ Complete | `src/game/CameraController.*` |
| 2-step combo chain | ✅ Complete | `src/game/combat/CombatSystem.*`, `src/game/RuntimeScene.hpp` |
| Lock-on targeting | ✅ Complete | `src/game/combat/Targeting.hpp`, `src/game/RuntimeScene.hpp`, `src/game/CameraController.*`, `src/app/Main.cpp` |
| Tactical Pause (time slow + playable command menu) | ✅ Complete | `src/ui/TacticalPauseMenu.*`, `src/app/Main.cpp` |
| Gameplay HUD | ✅ Complete | `src/ui/GameHUD.*` |
| Combat HUD expansion (target info + combo step) | ✅ Complete | `src/ui/GameHUD.*`, `src/app/Main.cpp` |
| Floating damage numbers | ✅ Complete | `src/ui/DamageNumbers.*` |
| Low HP warning pulse | ✅ Complete | `src/ui/GameHUD.*` |
| Enemy awareness radius visualization | ✅ Complete | `src/ui/ImGuiLayer.*` |
| Player damage intake + defeat reset | ✅ Complete | `src/game/actors/PlayerStats.hpp`, `src/game/RuntimeScene.hpp`, `src/game/CameraController.*` |
| Surge Strike | ✅ Complete | `src/game/RuntimeScene.hpp`, `src/game/combat/CombatSystem.cpp` |
| Limit Break gauge + move | ✅ Complete | `src/game/actors/PlayerStats.hpp`, `src/game/RuntimeScene.hpp`, `src/game/combat/CombatSystem.cpp` |
| MP passive regeneration | ✅ Complete | `src/game/actors/PlayerStats.hpp` |
| Dialog box (typewriter reveal) | ✅ Complete | `src/ui/DialogBox.*` |
| Biome minimap overlay | ✅ Complete | `src/ui/Minimap.*` |
| Audio SFX one-shot playback | ✅ Complete | `src/audio/AudioManager.*`, `ThirdParty/src/tp_audio.*` |
| Audio looping BGM / stop / volume | 🔧 Stub | `tp::Audio` exposes only `PlayOneShot`; true loop handle, stop, and runtime volume control are not implemented yet (Milestone 15) |
| Tracy CPU profiling zones | ✅ Complete | `GR_ZONE_SCOPED_N`, `GR_FRAME_MARK` |
| Jolt physics (initialised, raycast API) | 🔧 Stub | `ThirdParty/src/tp_physics.*` — no gameplay body yet |
| Recast/Detour navmesh | 🔧 Stub | `ThirdParty/src/tp_navigation.*` — BuildFromMesh is TODO |
| NPC / interaction actors | ❌ Not started | |
| Mesh loading (cgltf / Assimp) | ❌ Not started | AssetLoader stubs only |
| Skeletal animation | ❌ Not started | |
| Quality preset enforcement (Low/Med/High) | ❌ Not started | |
| Save / load system | ❌ Not started | |
| Area streaming (multiple active cells) | ❌ Not started | single active cell today |

### Documentation drift to fix

- `docs/Development Roadmap.txt` may still lag behind the now-completed Milestone 12 combat baseline.
- `docs/Architecture.md` should be checked for any remaining wording that implies player/enemy/combat systems are still planned.
- `docs/ASSET_REGISTRY.md` describes 200×200 cells; actual `world.json` uses `cell_size: 100`.
- `docs/WORLD_EDITOR.md` says WASD is suspended in placement mode; in reality only mouse-look is suspended.
- Future doc updates should use **Surge** terminology instead of old **ATB** wording except where describing historical migration.

---

## Phased Development Plan

### Milestone 12 — Playable Combat Loop

**Why now:** The foundation is solid. The single biggest gap between "tech demo" and "game" is a combat loop that reads well, feels responsive, and can be won or lost cleanly. Milestone 12 closes that gap while keeping scope modular and GT610-safe.

**Acceptance criteria:**
- Player can attack, dodge, and take damage.
- Enemy can chase, attack, and die.
- A short encounter can be won or lost and then reset.
- Runs at 60 fps on GT610 with two enemies on-screen.
- Basic attacks are always free.
- Surge and Limit Break gauges are functional.
- Tactical Pause slows time and shows command menu.
- Combat readability is improved through lock-on HUD, damage feedback, and low-risk feedback additions.

**Implemented so far:**
- Player action state machine
- Dodge burst movement
- 2-step combo chain
- Enemy chase / attack / hit states
- Player damage intake + defeat reset
- Surge system and Limit Break support
- Lock-on targeting
- Tactical Pause with playable command menu (Attack / Surge Strike / Limit Break)
- Combat HUD expansion (target info + combo step)
- Floating damage numbers
- Low HP warning pulse
- Enemy awareness radius visualization

**Remaining Milestone 12 focus:**
- Lock-on target cycling
- Auto-retarget on target death / range loss
- Tactical Pause command readiness reasons
- Hit flash on enemy
- Screen edge red flash on player damage
- Hit pause / hitstop
- Miss indicator
- Enemy aggro indicator
- Death / defeat screen
- Contextual button prompts
- Off-screen lock-on target indicator
- Enemy reaction / interrupt-lite
- Enemy attack telegraph lite
- Pressure / stagger integration stub
- GT610 budget debug counters

**Implementation rules for safe rollout:**
- Prefer small themed PRs over one large combat closeout PR.
- Add hooks/stubs first when full FF7R-style behavior would otherwise require a rewrite.
- Keep combat-facing additions data-light and renderer-cheap.
- Avoid tightly coupling HUD, combat resolution, and renderer state.

---

#### Remaining Track 12.x recommendations

##### Track 12.9 — Lock-on flow improvements
- Add target cycling while locked on.
- Add auto-retarget when the current target dies or leaves valid range.
- Keep unlock behavior predictable and low-friction.

**Files to change:**
- `src/game/combat/Targeting.hpp`
- `src/game/RuntimeScene.hpp`
- `src/app/Main.cpp`

##### Track 12.10 — Combat readability feedback pass A
- Add enemy hit flash.
- Add miss indicator.
- Add off-screen lock-on target indicator.
- Add Tactical Pause command readiness reasons.

**Files to change:**
- `src/game/actors/EnemyActor.cpp/hpp`
- `src/ui/DamageNumbers.cpp/hpp`
- `src/ui/GameHUD.cpp/hpp`
- `src/ui/TacticalPauseMenu.cpp/hpp`

##### Track 12.11 — Combat readability feedback pass B
- Add screen edge damage flash.
- Add enemy aggro indicator.
- Add enemy attack telegraph lite.
- Add enemy reaction / interrupt-lite.

**Files to change:**
- `src/ui/GameHUD.cpp/hpp`
- `src/ui/ImGuiLayer.cpp/hpp`
- `src/game/actors/EnemyActor.cpp/hpp`
- `src/game/combat/CombatSystem.cpp/hpp`

##### Track 12.12 — Encounter failure + pacing
- Add death / defeat screen.
- Add hit pause / hitstop.
- Add contextual button prompts.
- Add pressure / stagger integration stub for future expansion.

**Files to change:**
- `src/ui/GameHUD.cpp/hpp`
- `src/game/RuntimeScene.hpp`
- `src/game/combat/CombatSystem.cpp/hpp`
- `src/game/actors/EnemyActor.cpp/hpp`

##### Track 12.13 — Performance visibility
- Add GT610 budget counters to the debug overlay.
- Surface only the metrics needed for safe iteration (draw calls, active hitboxes, active enemies, etc.).

**Files to change:**
- `src/ui/ImGuiLayer.cpp/hpp`
- `src/rendering/d3d11/D3D11Renderer.cpp/hpp`
- `src/game/RuntimeScene.hpp`

---

### Milestone 13 — Open-World Feel (streaming + multi-enemy encounters)

Once the combat loop is solid, expand the world feel:

- **Multi-cell streaming**: activate 2–3 surrounding cells simultaneously instead of one.
- **Enemy spawner per cell**: each cell JSON can declare spawn points.
- **More enemy types**: reuse the state machine with different stats, speeds, prefab colors.
- **Interaction actors**: simple NPC with a dialog trigger on `E`.

Additional planned scope:

- **Named NPC actors with name shown above dialog window**
- **NPC wander behavior reusing patrol logic**
- **NPC schedule stub tied to day/night cycle**
- **Quest giver NPC with flag-based quest activation**
- **Simple quest objective system with active objective list**
- **Quest reward delivery (XP + item + dialog acknowledgment)**
- **Dialog branching lite with yes/no choices that set flags**
- **Merchant / shop NPC with classic FF-style shop window**
- **Inn / rest NPC that charges currency to restore HP/MP fully**
- **World event trigger zones (AABB zone check that triggers dialog, spawns enemies, or plays audio)**
- **Treasure chest actor**
- **Campfire / rest point actor**
- **Fog of war on minimap (visited cell tracking)**
- **Enemy respawn timer per spawn point**
- **Enemy group spawning from cell JSON**
- **Interaction hotspot registry stub**
- **Landmark discovery trigger stub**
- **NPC interaction prompt routing stub**
- **Quest flag / world-state hook**
- **Spawn composition table stub (solo / pair / pack)**

---

### Milestone 14 — Visual Polish (FF7-style)

Stay within GT610 constraints using simple per-vertex or low-cost screen techniques:

- **Outline / toon edge**: write depth and compare neighbor pixels in a cheap post-pass (one full-screen pass allowed on Low).
- **Palette-constrained tint**: a small 16-entry 1D texture maps palette IDs to colors per prefab part; this is the "old-school FF7 look" without any texture artist work.
- **Cel-shading step**: quantize the diffuse term to 2–3 bands in the pixel shader.
- **Screen shake**: simple camera offset buffer, applied in vertex shader via a cbuffer nudge.

Additional planned scope:

- **Wind effect on trees (vertex shader sin wave)**
- **Weather system lite (fog depth fade + optional rain overlay)**
- **Ambient particles (billboard dust/leaf quads)**
- **Camera shake on impact**
- **Letterbox bars on scripted events**
- **Area name display on cell enter**
- **Day/night cycle tint lerp**
- **Biome transition fade**
- **Enemy aggro indicator visual**
- **Hit flash on enemy tint**
- **Screen edge red flash on player damage**
- **Lock-on ring / target reticle polish**
- **Directional hit spark / slash effect stub**
- **World prop highlight / interact tint**
- **Lock-on camera recovery smoothing**
- **Tactical Pause panel animation polish**

Example cel-shade HLSL (add to `prim_ps.hlsl`):

```hlsl
// Quantise diffuse into 3 brightness steps (dark / mid / lit)
// Very cheap on GT610 (one floor + one divide); can be toggled off via quality preset.
float steps = 3.0f;
float celDiff = floor(diff * steps) / steps;
float3 litColor = tintColor.rgb * (lightColor * celDiff + ambientStrength.xxx);
```

---

### Milestone 15 — Audio + Narrative Scaffold

- **Looping BGM** — extend `tp::Audio` with `ma_sound` loop handle to support true music playback.
- **Battle music trigger** — `AudioManager` switches tracks when an enemy enters Chase state.
- **NPC voice line stubs** — `DialogBox` already exists; wire it to NPC interaction actors.

Additional planned scope:

- **Environmental ambient audio per biome**
- **UI sound effects for menu navigation**
- **Victory fanfare on encounter clear**
- **Level up audio sting**
- **Footstep audio variation per terrain type**
- **Combo escalation hit sounds**
- **Environmental interaction sounds (chest open, item pickup, area enter)**
- **Dynamic audio volume zones based on biome or indoor/outdoor state**
- **Tactical Pause enter / exit SFX**
- **Lock-on acquire / break SFX**
- **Enemy alert bark stub**

---

### Milestone 16 — Player Progression and World Systems

- XP gain on enemy kill and level system
- Stat growth on level up (HP max, MP max, Surge fill rate)
- Inventory system with item list and counts
- Potion / heal item use with key bind
- Status effects lite (Poisoned HP drain, Slowed move speed) with tint indicator
- Ability / skill hotbar (functional)
- MP cost on special attacks
- Fast travel stub (named location list, no complex map UI)
- Save / load system
- Settings persistence (resolution, volume, quality preset)
- Quality preset enforcement (Low/Med/High changing draw distance, max enemies, effect quality)
- Loading screen for world cell transitions
- Map screen and map fog of war
- Equipment slot stub
- Ability unlock / progression hook
- Combat stat modifier pipeline stub

---

## GT610 Performance Budget (must remain respected every milestone)

| Resource | Low preset budget |
|---|---|
| Draw calls per frame | ≤ 200 |
| GPU memory | ≤ 512 MB |
| Active dynamic lights | ≤ 4 per actor |
| Full-screen post passes | ≤ 1 |
| Active hitboxes | ≤ 8 per frame |
| Active enemies (updating) | ≤ 6 per scene |
| Texture (resident, Hi-Res) | ≤ 256 MB |

---

## Folder ownership map (where each feature belongs)

```text
src/
  game/
    actors/
      PlayerActor.cpp/.hpp       ← player visual + stats
      PlayerActionState.hpp      ← action state enum
      EnemyActor.cpp/.hpp        ← enemy AI + health + future reactions
    combat/
      CombatSystem.cpp/.hpp      ← hitbox pool + damage resolution
      HitBox.hpp                 ← AABB lifetime struct
      Targeting.hpp              ← lock-on selection / future cycling / retargeting
    CameraController.cpp/.hpp    ← movement, terrain snap, lock-on framing
    RuntimeScene.hpp             ← orchestration: update → submit → draw
  ui/
    GameHUD.cpp/.hpp             ← HP/MP/Surge/Limit + target bar + combo step + combat prompts
    TacticalPauseMenu.cpp/.hpp   ← Tactical Pause command UI
    DamageNumbers.cpp/.hpp       ← damage numbers + miss indicator path
    DialogBox.cpp/.hpp           ← NPC/story dialog
    Minimap.cpp/.hpp             ← biome map overlay
    ImGuiLayer.cpp/.hpp          ← frame begin/end, pause menu, debug overlay
  audio/
    AudioManager.cpp/.hpp        ← BGM/SFX, volume controls, combat cues
  app/
    Main.cpp                     ← frame loop orchestration ONLY
    InputActionMap.hpp           ← input bindings
  rendering/
    d3d11/
      D3D11Renderer.cpp/.hpp     ← D3D11 device, constant buffers, draw calls
Shaders/
  prim_vs.hlsl / prim_ps.hlsl    ← box primitive (actors, props)
  tree_vs.hlsl / tree_ps.hlsl    ← tree instancing
  ground_vs.hlsl / ground_ps.hlsl← textured terrain
  sky_vs.hlsl / sky_ps.hlsl      ← simple sky dome
Content/
  Prefabs/                       ← one .prefab.json per object type
  World/                         ← world.json + cell_*.json
  Audio/                         ← BGM .ogg, SFX .wav
  Textures/                      ← biome diffuse maps (≤ 1024×1024 each)
```

---

## Suggested prompt ordering for remaining Milestone 12 work

Work these prompts in order — each one should land cleanly and update docs as it goes.

| # | Prompt scope | Depends on |
|---|---|---|
| 12.9 | Add lock-on target cycling + auto-retarget | 12.8 complete |
| 12.10 | Add hit flash, miss indicator, off-screen target indicator, Tactical Pause readiness reasons | 12.9 |
| 12.11 | Add screen-edge damage flash, aggro indicator, telegraph lite, reaction / interrupt-lite | 12.10 |
| 12.12 | Add defeat screen, hitstop, contextual prompts, pressure / stagger stub | 12.11 |
| 12.13 | Add GT610 budget counters to debug overlay | 12.12 |

---

## Vision Docs Index

| Doc | Focus |
|---|---|
| `docs/GRAPHICS_VISION.md` | FF7-style visuals, GT610 budgets, D3D11 shader/lighting rules |
| `docs/COMBAT_VISION.md` | Action combat feel, lock-on, dodge, combo, enemy pressure, tuning |
| `docs/UI_VISION.md` | Hybrid UI: modern action HUD + classic FF-style menus/dialog |

---

## Quick-start checklist before each PR

1. Read `docs/SYSTEMS.md` — do not re-implement a ✅ system.
2. Read `docs/AGENT_RULES.md` — follow all hard rules.
3. Touch only the files listed in the prompt scope unless the prompt explicitly expands them.
4. After finishing: update `docs/SYSTEMS.md` and add one line to `docs/CHANGELOG.md`.

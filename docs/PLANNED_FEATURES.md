# Planned Features
**Last updated:** 2026-05-13

This file lists all features planned for future milestones but not yet implemented.
Check docs/SYSTEMS.md for current implementation status.
Check docs/GAME_VISION_PLAN.md for milestone context and implementation detail.

---

## How to use this file
- Before implementing a feature, check docs/SYSTEMS.md to confirm it is ❌ Not started.
- After implementing a feature, move it from this list and mark it ✅ in docs/SYSTEMS.md.
- When a new feature idea is agreed, add it here first before prompting for implementation.

---

## Milestone 12 — Playable Combat Loop

### Core combat
- [x] Dodge burst movement
- [x] 2-step combo chain
- [ ] Lock-on targeting
- [x] Enemy combat states (chase / attack / hit)
- [ ] Player damage intake and defeat reset
- [ ] Combat HUD expansion (target HP bar, combo step)
- [ ] GT610 budget debug counters

### Combat resource system
- [ ] Remove ATB gate from basic attacks (always free)
- [ ] Rename ATB to Surge on HUD
- [ ] Surge fills from hits landed, hits taken, skilled dodge, passive time
- [ ] Surge Strike action (F while Surge full — 3x damage)
- [ ] Limit Break gauge (fills from taking damage)
- [ ] Limit Break move (5x damage finisher when gauge full)
- [ ] MP passive regeneration (2.0f per second)
- [ ] Tactical Pause (hold Tab — 15% time scale, command menu)
- [ ] Tactical Pause Magic submenu stub
- [ ] Tactical Pause Items submenu stub
- [ ] Tactical Pause Ally submenu stub
- [ ] Tab input split: tap Tab = Lock-on, hold Tab (>=0.25s) = Tactical Pause

### Combat feedback
- [ ] Floating damage numbers
- [ ] Hit flash on enemy
- [ ] Screen edge red flash on player damage
- [ ] Hit pause / hitstop
- [ ] Miss indicator
- [ ] Combo counter display
- [ ] Enemy aggro indicator
- [ ] Low HP warning pulse
- [ ] Death / defeat screen
- [ ] Contextual button prompts
- [ ] Enemy name display on lock-on

---

## Milestone 13 — Open World Feel

### World
- [ ] Multi-cell streaming
- [ ] Enemy spawner per cell JSON
- [ ] Enemy group spawning
- [ ] Enemy respawn timer
- [ ] World event trigger zones
- [ ] Treasure chest actor
- [ ] Campfire / rest point actor
- [ ] Fog of war on minimap
- [ ] Area name display on cell enter
- [ ] Notification toast system

### NPC and narrative
- [ ] Named NPC actor
- [ ] NPC wander behavior
- [ ] NPC schedule stub (day/night)
- [ ] Quest giver NPC
- [ ] Quest objective system
- [ ] Quest reward delivery
- [ ] Dialog branching lite
- [ ] Merchant / shop NPC
- [ ] Inn / rest NPC

### Enemy variety
- [ ] Multiple enemy types / stat variation
- [ ] Ranged enemy type
- [ ] Elite enemy variant
- [ ] Enemy patrol path variation (3-4 waypoints)
- [ ] Enemy loot drop
- [ ] Enemy tint colour field per enemy type
- [ ] Enemy scale variation (standard 1.0f / elite 1.35f / boss 2.0f+)
- [ ] Pre-combat tension audio sting on first Chase entry per scene

---

## Milestone 14 — Visual Polish

### Combat feedback visuals
- [ ] Stagger meter
- [ ] Enemy attack telegraph
- [ ] Weak point damage
- [ ] Parry / counter window
- [ ] Overkill indicator
- [ ] Attack range indicator
- [x] Enemy awareness radius visualization
- [ ] Block / guard state
- [ ] Hit pause / hitstop (if not done in M12)

### World visuals
- [ ] Wind effect on trees
- [ ] Weather system lite
- [ ] Ambient particles
- [ ] Day/night cycle tint
- [ ] Biome transition fade
- [ ] Landmark props
- [ ] Destructible prop stub

### Camera and presentation
- [ ] Camera shake on impact
- [ ] Combat camera zoom
- [ ] Target framing adjustment
- [ ] Camera collision avoidance
- [ ] Letterbox bars on scripted events
- [ ] Cinematic event camera stub
- [ ] Death camera effect

### UI polish
- [ ] Level up screen overlay
- [ ] Damage type color coding
- [ ] Kill counter / encounter summary
- [ ] Status screen
- [ ] Tooltip system stub
- [ ] Interaction range indicator
- [ ] Pause menu background dim
- [ ] Saving indicator
- [ ] Crosshair / aim indicator
- [ ] Ability / skill hotbar stub (layout reserved)
- [ ] FF7-style chunky custom HUD bars (HP / MP / Surge / Limit)
- [ ] Player tint states (low HP red pulse, stunned white flash, dodge blue)
- [ ] Summon system stub (reserved slot)

---

## Milestone 15 — Audio and Narrative

- [ ] Looping BGM
- [ ] Battle music transition on Chase state
- [ ] Victory fanfare on encounter clear
- [ ] Level up audio sting
- [ ] Environmental ambient audio per biome
- [ ] UI sound effects for menu navigation
- [ ] Footstep audio variation per terrain
- [ ] Combo escalation hit sounds
- [ ] Environmental interaction sounds
- [ ] Dynamic audio volume zones
- [ ] NPC voice line stubs via DialogBox
- [ ] Boss music track slot stub

---

## Milestone 16 — Player Progression and World Systems

- [ ] XP gain on enemy kill
- [ ] Level system and stat growth on level up
- [ ] Inventory system
- [ ] Potion / heal item use
- [ ] Status effects lite (Poisoned, Slowed)
- [ ] MP cost on special attacks
- [ ] Ability / skill hotbar (functional)
- [ ] Fast travel stub
- [ ] Save / load system
- [ ] Settings persistence
- [ ] Quality preset enforcement (Low / Med / High)
- [ ] Loading screen for cell transitions
- [ ] Map screen
- [ ] Map screen fog of war

---

## Unscheduled — Future Consideration

These are agreed ideas not yet assigned to a milestone:

- Boss encounters (requires enemy scripting and event camera)
- Elemental damage type system
- Party member / AI ally
- Skeletal animation
- Mesh loading (cgltf / Assimp)
- Complex IK or blended animation
- Network / multiplayer
- Skill trees or progression systems
- Full inventory grid UI
- Area streaming beyond 3 cells
- Summon cinematic event
- NPC dialogue flag system (lines change after story beats)
- Elemental spell system (Fire / Ice / Thunder / Cure)
- Limit Break escalation tiers per character

---

## Rules for this file
- Do not add features here that conflict with docs/AGENT_RULES.md hard rules.
- Do not add features that require a new third-party library unless explicitly discussed.
- Keep descriptions short — one line per feature.
- Full implementation detail belongs in docs/GAME_VISION_PLAN.md or the relevant vision doc.

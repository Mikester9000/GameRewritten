# Combat Vision Guide
**Date:** 2026-05-11

---

## Vision Statement

Combat should feel like **FF7 Remake or FF15** — real-time, reactive, satisfying — but be implemented in the simplest possible way that achieves that feeling.

No overengineered state machines. No elaborate networking. Just clean, readable, old-school code that produces modern action RPG moment-to-moment feel.

---

## Core Combat Goals

| Goal | What it means in practice |
|---|---|
| Action feel | Player reacts in real-time, not turn-based |
| Lock-on targeting | Player locks onto a single enemy; camera and attacks orient toward it |
| Dodge | Fast directional escape with brief invincibility window |
| Combo chain | 2–3 hit chains gated by timing, not just ATB |
| Enemy pressure | Enemies advance, attack, and punish passivity |
| Readability | Player always understands what is happening and why |

---

## Implementation Philosophy

### Keep it simple
- Prefer small flat structs and explicit state over deep inheritance hierarchies.
- Avoid observer/event bus complexity until it is clearly needed.
- Prefer `if / else if` state checks over large virtual dispatch trees for actor state.
- A system that fits in one file and 200 lines is better than one split across 10 files prematurely.

### Combat loop overview
1. Player is near an enemy.
2. Player presses lock-on — camera shifts to frame the target.
3. Player attacks (F key, always free) — spawns a hitbox 1.5 units forward.
4. Hit registers — enemy takes damage, brief flash feedback.
5. Combo window: player can press F again within 0.6 s to extend the chain (up to 2–3 hits).
6. Enemy retaliates: chases player, attacks on close range.
7. Player dodges (Shift) — brief burst, invincibility frame.
8. Enemy dies: drops to ground, despawns after short delay.
9. Player can be damaged — HP drains, defeat loop triggers at 0 HP.

---

## Systems

### Combat Resource System
- **Attacks are always free** — no resource gates the basic combo chain.
- Three separate independent bars:
  - **HP** — health, restored by potions and rest points
  - **MP** — magic cost, each spell costs MP, regenerates at `2.0f/sec` passively
  - **Surge** — replaces ATB, fills from combat, spent on finishers only
- Surge fill rates:
  - Hit landed on enemy: `+30%`
  - Hit taken from enemy: `+10%`
  - Skilled dodge near attack: `+15%`
  - Passive time fill fallback: `+4% per second`
- Surge is spent on **Surge Strike** (`3x` damage finisher).
- Surge is never spent on magic or items — those use MP and inventory.
- **Limit Break** is a separate gauge, fills only when the player takes damage (`+20% per hit`).
- When full, Limit Break move is available (`5x` damage, screen flash).
- Surge rewards aggression. Limit Break rewards survival. Both are FF7 DNA.

### Tactical Pause
- Hold `Tab` to slow time to `15%` speed and open a command menu:
  - `[ Surge Strike ] [ Magic ▶ ] [ Items ▶ ] [ Ally ▶ ]`
- Surge Strike is greyed out if Surge is not full.
- Magic shows spell list with MP costs (stub until Milestone 16).
- Items shows inventory list (stub until Milestone 16).
- Ally shows party commands (stub until party members are added in Milestone 13+).
- Releasing `Tab` closes the menu and resumes normal speed.
- Style: classic FF command menu look — dark panel, chunky text.

### Hitbox System
- `HitBox`: world-space center (x/y/z) + AABB half-extents (halfX/halfY/halfZ) + damage + `framesToLive`.
- `CombatSystem` owns all active hitboxes; tests overlap each frame.
- Hitboxes are temporary (typically 2 frames). No persistent hitbox actors.
- Current hit detection is AABB only — no sphere or convex hull until explicitly needed.

### Lock-On
- One lock-on target at a time. Press Tab to toggle.
- Camera biases toward target — does not fully snap, just softly pulls.
- Attack direction overrides input direction when locked on.
- Lock-on breaks if target dies or leaves range (~20 units).

### Dodge
- Input: Shift key.
- Move player 4 units in input direction over ~0.35 seconds.
- Brief invincibility window (~0.2 s at start of dodge).
- Cooldown: ~0.8 s before next dodge.
- Gate behind `PlayerActionState::Dodge` to prevent dodge-spam.

### Combo Chain
- 2-step chain: hit → window → hit.
- Combo window: 0.6 s after first hit to land the second.
- Each hit in chain increases hitbox damage slightly (step 1: base, step 2: base × 1.5).
- Visual/audio feedback distinguishes step 1 and step 2 hits.

### Enemy Behaviour
- **Patrol** (current): walk between two waypoints.
- **Chase** (next): enter chase when player is within detection range (~10 units).
- **Attack** (next): lunge / melee when player is within attack range (~2 units), deal damage, back off briefly.
- **Hit** (next): brief stagger animation (colour flash + short freeze) when damaged.
- **Dead**: despawn after 1–2 s.

Use a simple enum `EnemyState { Patrol, Chase, Attack, Hit, Dead }` — no complex FSM framework.

---

## Readability Rules

The player must always understand:
- Whether they can attack (basic attacks are always available).
- Whether Surge Strike or Limit Break is available (Surge / Limit bar state).
- Which enemy is locked on (targeting indicator).
- When they successfully hit (visual + audio feedback).
- When they take damage (HP bar change + screen flash).
- When an enemy is about to attack (wind-up tells — colour change or movement).

If any of these are unclear, fix the feedback before adding new mechanics.

---

## Combat Tuning Targets (GT610-safe)

| Parameter | Value |
|---|---|
| Max enemies on-screen (Low) | 4 |
| Hitbox check rate | Every frame (AABB is cheap) |
| Hitbox lifetime | 1–3 frames |
| Dodge distance | 4 world units |
| Dodge duration | 0.35 s |
| Dodge cooldown | 0.8 s |
| Combo window | 0.6 s |
| Lock-on range | 20 world units |
| Surge gain per hit landed | 30% |
| Surge gain per hit taken | 10% |
| Surge passive fill | 4% per second |
| Surge Strike multiplier | 3x |
| Limit Break gain per hit | 20% |
| Limit Break multiplier | 5x |
| Tactical Pause time scale | 0.15x |
| MP passive regen | 2.0f per second |

Adjust values based on feel during playtesting. Document changes here.

---

## Implementation Order (Milestone 12)

Follow this order to build combat incrementally without breaking existing systems:

1. **Player action state machine** — add `PlayerActionState` enum and wire through `RuntimeScene`.
2. **Lock-on targeting** — add `Targeting` class, Tab key toggle, camera bias.
3. **Dodge burst movement** — extend `CameraController` with dodge velocity and invincibility flag.
4. **2-step combo chain** — extend `CombatSystem` with combo step tracking and window timer.
5. **Enemy chase / attack states** — extend `EnemyActor` with `EnemyState` transitions.
6. **Player damage intake** — add damage reception to `PlayerStats`, defeat loop in `RuntimeScene`.
7. **HUD extensions** — target HP bar, combo step indicator in `GameHUD`.

Each step is independently testable. Do not bundle multiple steps into one PR.

---

## Out of Scope (Do Not Add Yet)

- Party members / AI allies
- Elemental weaknesses / damage type system
- Status effects (burn, stun, etc.) — except basic stagger
- Skill trees or progression systems
- Boss encounters (requires enemy scripting first)
- Complex IK or blended animation
- Network / multiplayer

Add these only after the base Milestone 12 loop is working and tuned.

---

## Long-Term Combat Goal

The final combat should feel like:

- **Player-facing**: fast, readable, satisfying action RPG combat with clear feedback.
- **Implementation**: simple, flat, readable code that any contributor can understand and extend.
- **Performance**: runs at 60 fps on GT610 with up to 4 enemies, within 100 draw calls on Low.

Prefer fun and readable over technically sophisticated.

### Planned Combat Feedback Features

- Floating damage numbers — numbers pop above enemies on hit, float upward, fade out over ~1s; white for normal, yellow for combo hits, red for enemy hits on player, using an ImGui draw list implementation.
- Hit flash on enemy — enemy primitive briefly flashes white/bright on taking damage by overriding tint color for 1-2 frames.
- Screen edge red flash — screen edges pulse red briefly when player takes damage using an ImGui draw list overlay with zero performance cost.
- Hit pause / hitstop — freeze all updates for 1-3 frames on a successful hit to make impacts feel weighty.
- Miss indicator — "Miss" text floats up in gray/white when an attack misses or is dodged by reusing the floating number system.
- Weak point damage — hitting enemy from behind deals bonus damage using a simple angle comparison between player facing and enemy facing.
- Overkill indicator — "Overkill" text briefly appears if the killing blow deals significantly more than remaining HP via a simple threshold check.
- Attack range indicator — subtle ground circle shows player attack range during the attack window and is hidden outside attack state.
- Parry / counter window — very tight dodge timing triggers a parry state with a brief flash indicator and bonus damage on the next attack.
- Stagger meter — hidden or visible float on EnemyActor fills as enemy takes hits, and when full, enemy enters extended vulnerable state (FF7 Remake pressure/stagger lite).
- Block / guard state — enemy occasionally guards an attack, shows a "Blocked" indicator, and applies reduced damage.
- Combo escalation audio — each combo step plays a slightly different or higher pitched hit sound.
- On-hit sound variation — different hit sounds play for normal hit, critical hit, and miss.
- Enemy aggro indicator — exclamation mark style visual appears above enemy head when they detect the player, tied to Chase state entry.
- Enemy loot drop — on death, enemy spawns a pickup actor (potion or currency stub) at its position.
- Elite enemy variant — occasional stronger enemy uses larger prefab scale, higher HP, different tint color, and bonus loot while reusing the same AI.
- Ranged enemy type — enemy fires a simple projectile struct moving in a direction, with AABB check against player each frame.
- Multiple enemy types / stat variation — reuse EnemyActor state machine with different speed, HP, attack range, prefab, and detection radius.
- Enemy respawn timer — after clearing an area, enemies respawn after a configurable delay per spawn point.
- Enemy group spawning — define spawn groups of 2-3 enemies that activate together from a single spawn point in cell JSON.

### Planned Enemy Behaviour Extensions

- Enemy patrol path variation — extend waypoint array to support 3-4 point patrol loops.
- Enemy awareness radius visualization — debug toggle draws detection radius circle on ground plane in debug overlay only and remains hidden in release.

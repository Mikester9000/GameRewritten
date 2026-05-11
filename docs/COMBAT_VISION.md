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
3. Player attacks (F key, ATB gated) — spawns a hitbox 1.5 units forward.
4. Hit registers — enemy takes damage, brief flash feedback.
5. Combo window: player can press F again within 0.6 s to extend the chain (up to 2–3 hits).
6. Enemy retaliates: chases player, attacks on close range.
7. Player dodges (Shift) — brief burst, invincibility frame.
8. Enemy dies: drops to ground, despawns after short delay.
9. Player can be damaged — HP drains, defeat loop triggers at 0 HP.

---

## Systems

### ATB (Active Time Bar)
- Fills passively over time.
- Required for the first hit in a combo.
- Resets on each hit in the combo chain.
- Keep the ATB model simple — do not add multiple ATB bars early.

### Hitbox System
- `HitBox`: position + radius + damage + lifetime (frames or seconds).
- `CombatSystem` owns all active hitboxes; tests overlap each frame.
- Hitboxes are temporary (1–3 frames). No persistent hitbox actors.
- Keep hit detection AABB or sphere only — no convex hull until needed.

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
- 2-step chain: hit → window → hit → ATB reset.
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
- Whether they can attack (ATB bar state).
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
| ATB fill time (full bar) | ~3 s passive |

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

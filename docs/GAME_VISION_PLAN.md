# Game Vision Plan
**Date:** 2026-05-11

---

## Vision Statement

Build a 3D action RPG that:

- **Plays like FF15 or FF7 Remake** — real-time action combat, lock-on targeting, dodge + combo attacks, an open explorable world.
- **Looks like FF7 (original)** — stylised "blockout" characters built from simple coloured box primitives, flat-shaded palette-driven art, no expensive PBR or physically-based lighting.
- **Targets low-spec hardware** — DirectX 11 / GeForce GT 610, forward rendering, ≤ 200 draw calls on Low quality, ≤ 512 MB GPU memory.

The result is a modern open-world action game that retains the charm of old-school construction techniques while delivering the moment-to-moment feel of a modern JRPG.

---

## Current State Assessment (2026-05-11)

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
| Player stats: HP / MP / ATB | ✅ Complete | `src/game/actors/PlayerStats.hpp` |
| Input action map (W/A/S/D, F, E, Space …) | ✅ Complete | `src/app/InputActionMap.hpp` |
| AABB prefab collision (push-out on movement) | ✅ Complete | `src/game/physics/CollisionWorld.*`, `CameraController.*` |
| Patrol enemy actor | ✅ Complete | `src/game/actors/EnemyActor.*` |
| ATB-gated attack + hitbox damage | ✅ Complete | `src/game/combat/CombatSystem.*`, `src/game/RuntimeScene.hpp` |
| Gameplay HUD (HP / MP / ATB bar) | ✅ Complete | `src/ui/GameHUD.*` |
| Dialog box (typewriter reveal) | ✅ Complete | `src/ui/DialogBox.*` |
| Biome minimap overlay | ✅ Complete | `src/ui/Minimap.*` |
| Audio one-shot SFX / BGM stub | ✅ Complete | `src/audio/AudioManager.*`, `ThirdParty/src/tp_audio.*` |
| Tracy CPU profiling zones | ✅ Complete | `GR_ZONE_SCOPED_N`, `GR_FRAME_MARK` |
| Jolt physics (initialised, raycast API) | 🔧 Stub | `ThirdParty/src/tp_physics.*` — no gameplay body yet |
| Recast/Detour navmesh | 🔧 Stub | `ThirdParty/src/tp_navigation.*` — BuildFromMesh is TODO |
| Player action state machine | ❌ Not started | needed for dodge, combo, stunned |
| Dodge / evade | ❌ Not started | |
| Lock-on targeting | ❌ Not started | |
| Combo chain (2–3 step) | ❌ Not started | |
| Enemy combat state (chase/attack/hit) | ❌ Not started | EnemyActor only patrols |
| Player damage intake + defeat loop | ❌ Not started | |
| NPC / interaction actors | ❌ Not started | |
| Mesh loading (cgltf / Assimp) | ❌ Not started | AssetLoader stubs only |
| Skeletal animation | ❌ Not started | |
| Quality preset enforcement (Low/Med/High) | ❌ Not started | |
| Save / load system | ❌ Not started | |
| Area streaming (multiple active cells) | ❌ Not started | single active cell today |

### Documentation drift to fix

- `docs/Development Roadmap.txt` §16–17 still lists primitive split and player blockout as next unchecked tasks — both are already done.
- `docs/Architecture.md` §5 says player/enemy/combat are "planned" — they now exist.
- `docs/ASSET_REGISTRY.md` describes 200×200 cells; actual `world.json` uses `cell_size: 100`.
- `docs/WORLD_EDITOR.md` says WASD is suspended in placement mode; in reality only mouse-look is suspended.
- `docs/SYSTEMS.md` marks Jolt/Audio/DirectXTex as "init only" — Audio does play SFX, DirectXTex uploads real SRVs.

---

## Phased Development Plan

### Milestone 12 — Playable Micro-Encounter (target: first playable combat loop)

**Why now:** The foundation is solid. The single biggest gap between "tech demo" and "game" is a combat loop you can win or lose. This milestone closes that gap without requiring mesh loading or skeletal animation.

**Acceptance criteria:**
- Player can attack, dodge, and take damage.
- Enemy can chase, attack, and die.
- A short encounter can be won or lost and then reset.
- Runs at 60 fps on GT610 with two enemies on-screen.

---

#### Track 12.1 — Player action state machine

**Why first:** Every other combat feature (dodge, combo, stunned, lock-on) hangs off this.

**Files to create / change:**
- `src/game/actors/PlayerActionState.hpp` — new
- `src/game/actors/PlayerActor.hpp` — add `PlayerActionState state`
- `src/game/actors/PlayerActor.cpp` — add `Update(dt, input)` transition logic

**Example code structure:**

```cpp
// src/game/actors/PlayerActionState.hpp
#pragma once

enum class PlayerActionState
{
    Idle,
    Move,
    Jump,
    Fall,
    Attack1,   // first hit in combo
    Attack2,   // second hit
    Dodge,
    Stunned,
    Dead
};
```

```cpp
// src/game/actors/PlayerActor.hpp  (additions)
#pragma once
#include "ActorCommon.hpp"
#include "PlayerStats.hpp"
#include "PlayerActionState.hpp"

class PlayerActor
{
public:
    PlayerStats       stats;
    PlayerActionState state = PlayerActionState::Idle;
    float             stateTimer = 0.0f; // seconds left in timed state

    // Drive state transitions from input + physics
    void Update(float dt, const struct InputActionMap& input, bool isGrounded);

    // ... existing SubmitRuntimeVisual unchanged
};
```

```cpp
// src/game/actors/PlayerActor.cpp  (Update skeleton)
void PlayerActor::Update(float dt, const InputActionMap& input, bool isGrounded)
{
    stateTimer -= dt;
    if (stateTimer < 0.0f) stateTimer = 0.0f;

    switch (state)
    {
        case PlayerActionState::Idle:
        case PlayerActionState::Move:
            if (input.IsHeld(InputAction::Attack) && stats.IsAtbReady())
                TransitionTo(PlayerActionState::Attack1, 0.40f); // 400 ms window
            else if (input.IsHeld(InputAction::Dodge))
                TransitionTo(PlayerActionState::Dodge, 0.35f);
            break;

        case PlayerActionState::Attack1:
            if (stateTimer <= 0.0f)
                TransitionTo(PlayerActionState::Idle, 0.0f);
            break;

        case PlayerActionState::Dodge:
            if (stateTimer <= 0.0f)
                TransitionTo(PlayerActionState::Idle, 0.0f);
            break;

        case PlayerActionState::Stunned:
            if (stateTimer <= 0.0f)
                TransitionTo(stats.hp > 0 ? PlayerActionState::Idle
                                          : PlayerActionState::Dead, 0.0f);
            break;

        default: break;
    }
}

void PlayerActor::TransitionTo(PlayerActionState next, float duration)
{
    state      = next;
    stateTimer = duration;
}
```

---

#### Track 12.2 — Input actions for dodge and lock-on

**Files to change:**
- `src/app/InputActionMap.hpp` — add `Dodge`, `LockOn`

```cpp
// src/app/InputActionMap.hpp  (additions)
enum class InputAction
{
    MoveForward, MoveBack, MoveLeft, MoveRight,
    Jump,
    Attack,
    Dodge,      // NEW — default binding: left Shift
    LockOn,     // NEW — default binding: Tab
    Interact,
    TogglePause,
    ToggleDebug,
    ReloadAssets
};

// In Default():
map.bindings[InputAction::Dodge]  = VK_SHIFT;
map.bindings[InputAction::LockOn] = VK_TAB;
```

---

#### Track 12.3 — Dodge burst movement

Dodge moves the player 4 units in the input direction over 0.35 seconds, ignoring friction. Gate behind `PlayerActionState::Dodge`.

**Files to change:**
- `src/game/CameraController.cpp` — read dodge state and apply burst velocity
- `src/game/RuntimeScene.hpp` — pass `playerActor.state` to camera controller

```cpp
// src/game/CameraController.cpp  (inside Update, simplified sketch)
if (playerState == PlayerActionState::Dodge && dodgeTimer > 0.0f)
{
    const float dodgeSpeed = 4.0f / 0.35f; // covers 4 units in 0.35 s
    m_playerX += dodgeDir.x * dodgeSpeed * dt;
    m_playerZ += dodgeDir.z * dodgeSpeed * dt;
}
```

---

#### Track 12.4 — 2-step combo chain

Replace the single ATB attack with a timed two-hit chain.

**Files to change:**
- `src/game/combat/CombatSystem.hpp` — add combo tracking
- `src/game/RuntimeScene.hpp` — pass combo step to SpawnHitBox

```cpp
// src/game/combat/CombatSystem.hpp  (additions)
class CombatSystem
{
public:
    int  comboStep   = 0;    // 0 = no combo, 1 = first hit, 2 = second hit
    float comboTimer = 0.0f; // seconds left to chain the next hit

    // Call when player presses Attack with ATB ready
    void TriggerAttack(float px, float py, float pz, float yaw, int attackStep);
    void Update(EnemyActor* enemies, int count);

private:
    static constexpr float kComboWindowSec = 0.60f; // time between hits to continue combo
    std::vector<HitBox> m_activeHitBoxes;
};
```

```cpp
// Combo logic in RuntimeScene::TriggerPlayerAttack (sketch)
bool RuntimeScene::TriggerPlayerAttack(const CameraController& cam)
{
    if (!m_player.stats.IsAtbReady())
        return false;

    int step = (m_combatSystem.comboStep % 2) + 1; // cycles 1 → 2 → 1 → 2
    m_combatSystem.TriggerAttack(cam.GetPlayerX(),
                                  cam.GetPlayerGroundY() + 1.0f,
                                  cam.GetPlayerZ(),
                                  cam.GetYaw(), step);

    m_player.stats.atbCharge = 0.0f; // reset ATB after each hit
    return true;
}
```

---

#### Track 12.5 — Enemy combat state machine

Upgrade EnemyActor from patrol-only to a minimal fight-capable actor.

**Files to change:**
- `src/game/actors/EnemyActor.hpp` — add `EnemyState` enum + chase/attack fields
- `src/game/actors/EnemyActor.cpp` — implement state transitions

```cpp
// src/game/actors/EnemyActor.hpp  (additions)
#pragma once
#include "ActorCommon.hpp"

enum class EnemyState { Patrol, Chase, Attack, Hit, Dead };

class EnemyActor
{
public:
    EnemyState state     = EnemyState::Patrol;
    float      stateTimer = 0.0f;

    // Detection radii
    static constexpr float kDetectRadius = 18.0f;
    static constexpr float kAttackRadius =  2.5f;

    // Called each frame with player world position
    void Update(float dt, float playerX, float playerZ, D3D11Renderer& renderer);

    // ... existing fields (x, y, z, hp, waypoints, etc.)
};
```

```cpp
// EnemyActor::Update skeleton
void EnemyActor::Update(float dt, float playerX, float playerZ, D3D11Renderer& renderer)
{
    if (isDead) return;

    float dx = playerX - x;
    float dz = playerZ - z;
    float dist = sqrtf(dx * dx + dz * dz);

    switch (state)
    {
        case EnemyState::Patrol:
            DoPatrol(dt, renderer);
            if (dist < kDetectRadius)
                TransitionTo(EnemyState::Chase, 0.0f);
            break;

        case EnemyState::Chase:
            MoveToward(playerX, playerZ, dt, renderer);
            if (dist < kAttackRadius)
                TransitionTo(EnemyState::Attack, 0.60f);
            else if (dist > kDetectRadius * 1.5f)
                TransitionTo(EnemyState::Patrol, 0.0f);
            break;

        case EnemyState::Attack:
            if (stateTimer <= 0.0f)
            {
                // Emit an enemy hitbox toward the player — dealt in CombatSystem
                m_pendingAttack = true;
                TransitionTo(EnemyState::Chase, 0.0f);
            }
            break;

        case EnemyState::Hit:
            if (stateTimer <= 0.0f)
                TransitionTo(hp > 0 ? EnemyState::Chase : EnemyState::Dead, 0.0f);
            break;

        default: break;
    }

    stateTimer = std::max(0.0f, stateTimer - dt);
}
```

---

#### Track 12.6 — Player damage intake + defeat reset

Add the other side of combat so there is a real win/lose loop.

**Files to change:**
- `src/game/combat/CombatSystem.hpp` / `.cpp` — add enemy hitboxes + player hit resolution
- `src/game/actors/PlayerStats.hpp` — add `TakeDamage(int)`
- `src/game/RuntimeScene.hpp` — check `player.stats.hp <= 0` and trigger reset

```cpp
// src/game/actors/PlayerStats.hpp  (additions)
void TakeDamage(int amount)
{
    hp -= static_cast<float>(amount);
    if (hp < 0.0f) hp = 0.0f;
}

bool IsDead() const { return hp <= 0.0f; }
```

```cpp
// RuntimeScene: simple reset when player dies
if (m_player.stats.IsDead())
{
    m_player.stats.hp  = m_player.stats.maxHp;
    m_player.stats.mp  = m_player.stats.maxMp;
    m_player.state     = PlayerActionState::Idle;
    // teleport player back to spawn — camera controller needs a Reset() method
    LOG_INFO("RuntimeScene: Player defeated — respawning.");
}
```

---

#### Track 12.7 — Lock-on targeting

Select the nearest living enemy in range; camera biases toward that enemy.

**Files to create:**
- `src/game/combat/Targeting.hpp` — new

```cpp
// src/game/combat/Targeting.hpp
#pragma once
#include <cmath>

class EnemyActor;

class Targeting
{
public:
    bool         isLocked  = false;
    EnemyActor*  target    = nullptr;

    static constexpr float kLockRadius = 25.0f;

    // Find and lock the nearest alive enemy within kLockRadius.
    // Call when the player presses LockOn.
    void ToggleLock(EnemyActor* enemies, int count,
                    float playerX, float playerZ)
    {
        if (isLocked) { isLocked = false; target = nullptr; return; }

        float bestDist = kLockRadius;
        for (int i = 0; i < count; ++i)
        {
            if (enemies[i].isDead) continue;
            float dx = enemies[i].x - playerX;
            float dz = enemies[i].z - playerZ;
            float d  = sqrtf(dx * dx + dz * dz);
            if (d < bestDist) { bestDist = d; target = &enemies[i]; }
        }
        isLocked = (target != nullptr);
    }

    // Returns nullptr if not locked or target died.
    const EnemyActor* GetTarget() const
    {
        if (!isLocked || !target || target->isDead) return nullptr;
        return target;
    }
};
```

**Camera framing (CameraController.cpp sketch):**

```cpp
// If locked on, rotate yaw smoothly toward the target instead of free mouse look
if (targeting.GetTarget())
{
    float tx = targeting.GetTarget()->x - m_playerX;
    float tz = targeting.GetTarget()->z - m_playerZ;
    float targetYaw = atan2f(tx, tz);
    m_yaw = LerpAngle(m_yaw, targetYaw, 8.0f * dt); // smooth bias
}
```

---

#### Track 12.8 — Combat HUD expansion

Show the locked target's name and HP bar, and the current combo step.

**Files to change:**
- `src/ui/GameHUD.hpp` / `.cpp` — add `DrawTargetInfo()` and combo indicator

```cpp
// src/ui/GameHUD.hpp  (additions)
class GameHUD
{
public:
    void Draw(const PlayerStats& stats, const ImGuiIO& io);
    void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);
    void DrawComboStep(int step, const ImGuiIO& io);
};
```

```
HUD layout sketch (FF7 Remake-inspired):

┌────────────────────────────────────────────────┐
│  [HP ████████████████░░░░░] 80/100             │
│  [MP ██████░░░░░░░░░░░░░░░] 30/50              │
│  [ATB ████████████████████] READY              │
│                                                │
│            [TARGET: Goblin  HP ██░░]           │
│                  Combo: 1 > 2                  │
└────────────────────────────────────────────────┘
```

---

### Milestone 13 — Open-World Feel (streaming + multi-enemy encounters)

Once the micro-encounter loop is solid, expand the world feel:

- **Multi-cell streaming**: activate 2–3 surrounding cells simultaneously instead of one.
- **Enemy spawner per cell**: each cell JSON can declare spawn points.
- **More enemy types**: reuse the state machine with different stats, speeds, prefab colors.
- **Interaction actors**: simple NPC with a dialog trigger on `E`.

---

### Milestone 14 — Visual Polish (FF7-style)

Stay within GT610 constraints using simple per-vertex techniques:

- **Outline / toon edge**: write depth and compare neighbor pixels in a cheap post-pass (one full-screen pass allowed on Low).
- **Palette-constrained tint**: a small 16-entry 1D texture maps palette IDs to colors per prefab part; this is the "old-school FF7 look" without any texture artist work.
- **Cel-shading step**: quantize the diffuse term to 2–3 bands in the pixel shader.
- **Screen shake**: simple camera offset buffer, applied in vertex shader via a cbuffer nudge.

Example cel-shade HLSL (add to `prim_ps.hlsl`):

```hlsl
// Quantise diffuse into 3 brightness steps (dark / mid / lit)
float steps = 3.0f;
float celDiff = floor(diff * steps) / steps;
float3 litColor = tintColor.rgb * (lightColor * celDiff + ambientStrength.xxx);
```

---

### Milestone 15 — Audio + Narrative Scaffold

- **Looping BGM** — extend `tp::Audio` with `ma_sound` loop handle to support true music playback.
- **Battle music trigger** — `AudioManager` switches tracks when an enemy enters Chase state.
- **NPC voice line stubs** — `DialogBox` already exists; wire it to NPC interaction actors.

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

```
src/
  game/
    actors/
      PlayerActor.cpp/.hpp       ← player visual + stats
      PlayerActionState.hpp      ← NEW state enum
      EnemyActor.cpp/.hpp        ← enemy AI + health
    combat/
      CombatSystem.cpp/.hpp      ← hitbox pool + damage resolution
      HitBox.hpp                 ← AABB lifetime struct
      Targeting.hpp              ← NEW lock-on target selector
    CameraController.cpp/.hpp    ← movement, terrain snap, lock-on framing
    RuntimeScene.hpp             ← orchestration: update → submit → draw
  ui/
    GameHUD.cpp/.hpp             ← HP/MP/ATB + NEW target bar + combo step
    DialogBox.cpp/.hpp           ← NPC/story dialog
    Minimap.cpp/.hpp             ← biome map overlay
    ImGuiLayer.cpp/.hpp          ← frame begin/end, pause menu, debug overlay
  audio/
    AudioManager.cpp/.hpp        ← BGM/SFX, volume controls
  app/
    Main.cpp                     ← frame loop orchestration ONLY
    InputActionMap.hpp           ← input bindings
  rendering/
    d3d11/
      D3D11Renderer.cpp/.hpp     ← D3D11 device, constant buffers, draw calls
Shaders/
  prim_vs.hlsl / prim_ps.hlsl   ← box primitive (actors, props)
  tree_vs.hlsl / tree_ps.hlsl   ← tree instancing
  ground_vs.hlsl / ground_ps.hlsl ← textured terrain
  sky_vs.hlsl / sky_ps.hlsl     ← simple sky dome
Content/
  Prefabs/                       ← one .prefab.json per object type
  World/                         ← world.json + cell_*.json
  Audio/                         ← BGM .ogg, SFX .wav
  Textures/                      ← biome diffuse maps (≤ 1024×1024 each)
```

---

## Agent prompt ordering for Milestone 12

Work these prompts in order — each one depends on the previous completing cleanly.

| # | Prompt scope | Depends on |
|---|---|---|
| 12.1 | Add `PlayerActionState` enum and state machine to `PlayerActor` | none |
| 12.2 | Extend `InputActionMap` with `Dodge` and `LockOn` bindings | 12.1 |
| 12.3 | Implement dodge burst movement in `CameraController` | 12.2 |
| 12.4 | Replace single ATB attack with 2-step combo in `CombatSystem` | 12.1 |
| 12.5 | Add enemy chase / attack / hit states to `EnemyActor` | 12.4 |
| 12.6 | Add player damage intake and defeat / respawn reset | 12.5 |
| 12.7 | Add `Targeting` class and lock-on toggle | 12.6 |
| 12.8 | Add lock-on camera framing bias to `CameraController` | 12.7 |
| 12.9 | Expand `GameHUD` with target HP bar and combo step indicator | 12.7 |
| 12.10 | Add per-frame GT610 budget counters to debug overlay | 12.6 |

---

## Quick-start checklist before each PR

1. Read `docs/SYSTEMS.md` — do not re-implement a ✅ system.
2. Read `docs/AGENT_RULES.md` — follow all hard rules.
3. Touch only the files listed in the prompt scope.
4. After finishing: update `docs/SYSTEMS.md` and add one line to `docs/CHANGELOG.md`.

// ============================================================
// FILE: src/game/actors/PlayerStats.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: PlayerStats module behavior and local implementation details.
// ============================================================

#pragma once

#include <algorithm>

// ── Status Effects ────────────────────────────────────────────────────────
enum class StatusEffect : int
{
    None   = 0,
    Poison = 1, // periodic HP drain
    Burn   = 2, // higher tick damage, shorter duration
    Slow   = 3, // reduces movement/attack speed (combat modifier)
};

struct StatusEffectState
{
    StatusEffect type       = StatusEffect::None;
    float        duration   = 0.0f; // remaining seconds
    float        tickTimer  = 0.0f; // seconds until next damage tick
    float        tickRate   = 1.0f; // seconds between ticks
    int          tickDamage = 0;    // HP lost per tick

    void Apply(StatusEffect se, float dur)
    {
        type = se;
        duration  = dur;
        tickTimer = 0.0f;
        switch (se)
        {
        case StatusEffect::Poison: tickRate = 1.0f; tickDamage = 2; break;
        case StatusEffect::Burn:   tickRate = 0.5f; tickDamage = 4; break;
        case StatusEffect::Slow:   tickRate = 1.0f; tickDamage = 0; break;
        default:                   tickRate = 1.0f; tickDamage = 0; break;
        }
    }

    // Returns HP damage dealt this tick (0 if no tick fired or no damage effect).
    // Call every frame with the gameplay delta time.
    int Update(float dt)
    {
        if (type == StatusEffect::None || duration <= 0.0f)
            return 0;

        duration  -= dt;
        tickTimer += dt;
        if (duration <= 0.0f)
        {
            type      = StatusEffect::None;
            duration  = 0.0f;
            return 0;
        }

        int dmg = 0;
        while (tickTimer >= tickRate)
        {
            tickTimer -= tickRate;
            dmg       += tickDamage;
        }
        return dmg;
    }

    bool IsActive()              const { return type != StatusEffect::None && duration > 0.0f; }
    StatusEffect GetType()       const { return type; }

    const char* GetName() const
    {
        switch (type)
        {
        case StatusEffect::Poison: return "Poison";
        case StatusEffect::Burn:   return "Burn";
        case StatusEffect::Slow:   return "Slow";
        default:                   return "None";
        }
    }
};

// ── XP / Level helpers ────────────────────────────────────────────────────
// XP required to reach the next level scales linearly: base * level.
static constexpr int kXpBasePerLevel  = 100; // XP needed for level 1 → 2
static constexpr int kHpGainPerLevel  = 10;  // maxHp increase each level-up
static constexpr int kMpGainPerLevel  = 5;   // maxMp increase each level-up

struct PlayerStats
{
    float hp  = 100.0f;
    float maxHp = 100.0f;
    float mp  = 50.0f;
    float maxMp = 50.0f;

    // Surge charge in range 0.0 - 1.0. Full bar = ready to spend a Surge Strike.
    // Fills slowly over time (passive) and quickly from landing hits.
    float surgeCharge     = 0.0f;
    float surgeChargeRate = 0.04f; // passive fill per second

    // Limit charge in range 0.0 - 1.0. Fills only when the player takes damage.
    // Full bar unlocks the Limit Break finisher.
    float limitCharge = 0.0f;

    // XP / Level progression.
    int level          = 1;
    int xp             = 0;
    int xpToNextLevel  = kXpBasePerLevel; // scales up each level

    // Active status effect (one slot; new effects overwrite old ones).
    StatusEffectState statusEffect;

    // MP regenerates passively at this rate per second.
    static constexpr float kMpRegenRate = 2.0f;

    // Limit gauge advances by this fraction each time the player takes a hit.
    static constexpr float kLimitChargePerHit = 0.20f;

    // Tick passive Surge fill, MP regeneration, and status effect each frame.
    // Returns the HP damage dealt by status ticks this frame (for HUD feedback).
    int Update(float dt)
    {
        surgeCharge = std::clamp(surgeCharge + surgeChargeRate * dt, 0.0f, 1.0f);
        mp          = std::clamp(mp + kMpRegenRate * dt, 0.0f, maxMp);
        return statusEffect.Update(dt);
    }

    // Add surge from an external source (e.g. landing a hit). Clamps to 1.0.
    void AddSurge(float amount)
    {
        surgeCharge = std::clamp(surgeCharge + amount, 0.0f, 1.0f);
    }

    // Consume the full Surge bar when firing a Surge Strike.
    void SpendSurge() { surgeCharge = 0.0f; }

    bool IsSurgeReady() const { return surgeCharge >= 1.0f; }

    // Add limit charge from taking a hit. Clamps to 1.0.
    void AddLimitCharge(float amount)
    {
        limitCharge = std::clamp(limitCharge + amount, 0.0f, 1.0f);
    }

    // Consume the full Limit bar when firing a Limit Break.
    void SpendLimit() { limitCharge = 0.0f; }

    bool IsLimitReady() const { return limitCharge >= 1.0f; }

    // Reduce HP by amount; clamps to zero. Also advances the Limit gauge.
    // Safe to call with zero or positive values only.
    void TakeDamage(int amount)
    {
        if (amount <= 0)
            return;
        hp = std::clamp(hp - static_cast<float>(amount), 0.0f, maxHp);
        AddLimitCharge(kLimitChargePerHit);
    }

    bool IsDead() const { return hp <= 0.0f; }

    // Grant XP. Returns true if the player levelled up (may be called again
    // if the XP award spans multiple levels, but one level-up per call is
    // the expected steady-state for normal combat rewards).
    bool AddXp(int amount)
    {
        if (amount <= 0)
            return false;
        xp += amount;
        if (xp >= xpToNextLevel)
        {
            xp -= xpToNextLevel;
            ++level;
            xpToNextLevel = kXpBasePerLevel * level;
            // Grow max resources and restore to full on level-up.
            maxHp += static_cast<float>(kHpGainPerLevel);
            maxMp += static_cast<float>(kMpGainPerLevel);
            hp = maxHp;
            mp = maxMp;
            return true;
        }
        return false;
    }

    // Apply a status effect to the player, replacing the current one.
    void ApplyStatus(StatusEffect se, float duration)
    {
        statusEffect.Apply(se, duration);
    }

    // True when the Slow status is active (used by movement and combat code).
    bool IsSlowed() const
    {
        return statusEffect.IsActive() && statusEffect.GetType() == StatusEffect::Slow;
    }

    // Restore all combat resources to their full starting values.
    // Call on player defeat / respawn.
    void Reset()
    {
        hp           = maxHp;
        mp           = maxMp;
        surgeCharge  = 0.0f;
        limitCharge  = 0.0f;
        statusEffect = StatusEffectState{};
    }
};

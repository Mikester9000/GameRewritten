#pragma once

#include <algorithm>

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

    // MP regenerates passively at this rate per second.
    static constexpr float kMpRegenRate = 2.0f;

    // Tick passive Surge fill and MP regeneration each frame.
    void Update(float dt)
    {
        surgeCharge = std::clamp(surgeCharge + surgeChargeRate * dt, 0.0f, 1.0f);
        mp          = std::clamp(mp + kMpRegenRate * dt, 0.0f, maxMp);
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
        AddLimitCharge(0.20f);
    }

    bool IsDead() const { return hp <= 0.0f; }

    // Restore all combat resources to their full starting values.
    // Call on player defeat / respawn.
    void Reset()
    {
        hp           = maxHp;
        mp           = maxMp;
        surgeCharge  = 0.0f;
        limitCharge  = 0.0f;
    }
};

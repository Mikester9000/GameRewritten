#pragma once

struct PlayerStats
{
    float hp = 100.0f;
    float maxHp = 100.0f;
    float mp = 50.0f;
    float maxMp = 50.0f;
    // Surge charge in range 0.0 - 1.0. Full bar = ready to spend.
    // Fills passively each frame. Future: also fills from landing hits.
    float surgeCharge = 0.0f;
    float surgeChargeRate = 0.12f;

    void Update(float dt)
    {
        surgeCharge += surgeChargeRate * dt;
        if (surgeCharge < 0.0f)
            surgeCharge = 0.0f;
        if (surgeCharge > 1.0f)
            surgeCharge = 1.0f;
    }

    bool IsSurgeReady() const { return surgeCharge >= 1.0f; }

    // Reduce HP by amount; clamps to zero. Safe to call with zero or positive values only.
    void TakeDamage(int amount)
    {
        if (amount <= 0)
            return;
        hp -= static_cast<float>(amount);
        if (hp < 0.0f)
            hp = 0.0f;
    }

    bool IsDead() const { return hp <= 0.0f; }
};

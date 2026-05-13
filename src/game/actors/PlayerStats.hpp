#pragma once

struct PlayerStats
{
    float hp = 100.0f;
    float maxHp = 100.0f;
    float mp = 50.0f;
    float maxMp = 50.0f;
    float atbCharge = 0.0f;      // range 0.0f - 1.0f
    float atbChargeRate = 0.12f; // units per second

    void Update(float dt)
    {
        atbCharge += atbChargeRate * dt;
        if (atbCharge < 0.0f)
            atbCharge = 0.0f;
        if (atbCharge > 1.0f)
            atbCharge = 1.0f;
    }

    bool IsAtbReady() const { return atbCharge >= 1.0f; }

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

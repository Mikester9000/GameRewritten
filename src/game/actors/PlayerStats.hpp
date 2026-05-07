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
        if (atbCharge > 1.0f)
            atbCharge = 1.0f;
    }

    bool IsAtbReady() const { return atbCharge >= 1.0f; }
};

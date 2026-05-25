#pragma once

#include <algorithm>

class PoiseSystem
{
public:
    void Reset(float maxPoise = 100.0f)
    {
        m_maxPoise = (maxPoise > 1.0f) ? maxPoise : 1.0f;
        m_poise = m_maxPoise;
        m_breakTimer = 0.0f;
    }

    void Update(float dt)
    {
        if (m_breakTimer > 0.0f)
        {
            m_breakTimer -= dt;
            if (m_breakTimer <= 0.0f)
            {
                m_breakTimer = 0.0f;
                m_poise = m_maxPoise;
            }
        }
    }

    bool ApplyPoiseDamage(float amount)
    {
        if (amount <= 0.0f || IsBroken())
            return false;

        m_poise = std::max(0.0f, m_poise - amount);
        if (m_poise > 0.0f)
            return false;

        m_breakTimer = kBreakWindowSec;
        return true;
    }

    bool IsBroken() const { return m_breakTimer > 0.0f; }
    float GetBreakTimer() const { return m_breakTimer; }
    float GetPoiseRatio() const { return std::clamp(m_poise / m_maxPoise, 0.0f, 1.0f); }
    float GetBreakDamageMultiplier() const { return IsBroken() ? kBreakDamageMultiplier : 1.0f; }

private:
    static constexpr float kBreakWindowSec = 2.2f;
    static constexpr float kBreakDamageMultiplier = 2.2f;

    float m_maxPoise = 100.0f;
    float m_poise = 100.0f;
    float m_breakTimer = 0.0f;
};

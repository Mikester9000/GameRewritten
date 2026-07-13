// AutoQualityScaler.cpp
// Frame-time based automatic quality tier reduction.

#include "AutoQualityScaler.hpp"

void AutoQualityScaler::Init(float targetFps, float cooldownSec)
{
    m_targetFrameTime = 1.0f / targetFps;
    m_cooldown        = cooldownSec;
    m_cooldownTimer   = 0.0f;
    m_slowFrameAccum  = 0.0f;
}

bool AutoQualityScaler::Update(float dt)
{
    if (m_cooldownTimer > 0.0f)
    {
        m_cooldownTimer -= dt;
        m_slowFrameAccum = 0.0f;
        return false;
    }

    // Accumulate slow-frame time.
    if (dt > m_targetFrameTime * 1.5f) m_slowFrameAccum += dt;
    else                               m_slowFrameAccum  = 0.0f;

    // If we've been consistently slow for 2 seconds, drop a tier.
    if (m_slowFrameAccum >= 2.0f && m_tier > 0)
    {
        --m_tier;
        m_cooldownTimer  = m_cooldown;
        m_slowFrameAccum = 0.0f;
        return true;
    }
    return false;
}

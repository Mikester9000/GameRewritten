#include "LimitBreakCamera.hpp"

void LimitBreakCamera::Start()
{
    m_timer = kDurationSec;
}

void LimitBreakCamera::Update(float dt)
{
    if (m_timer <= 0.0f)
        return;

    m_timer -= dt;
    if (m_timer < 0.0f)
        m_timer = 0.0f;
}

float LimitBreakCamera::GetTimeScale() const
{
    if (m_timer <= 0.0f)
        return 1.0f;

    // Early dramatic slow-down then ramp back to normal.
    return (m_timer > (kDurationSec * 0.45f)) ? 0.60f : 0.85f;
}

float LimitBreakCamera::GetSuggestedShakeAmplitude() const
{
    if (m_timer <= 0.0f)
        return 0.0f;
    return (m_timer > (kDurationSec * 0.5f)) ? 0.24f : 0.10f;
}

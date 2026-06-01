#include "autosave_indicator.h"

#include <algorithm>
#include <cmath>

namespace gr
{
void AutoSaveIndicator::SetActive(bool active)
{
    if (!active)
    {
        m_timeSeconds = 0.0f;
    }
    m_active = active;
}

void AutoSaveIndicator::Tick(float deltaSeconds)
{
    if (m_active)
    {
        m_timeSeconds += std::max(deltaSeconds, 0.0f);
    }
}

float AutoSaveIndicator::GetPulseAlpha() const
{
    if (!m_active)
    {
        return 0.0f;
    }
    const float pulse = 0.5f + 0.5f * std::sin(m_timeSeconds * 6.28318530f);
    return 0.35f + pulse * 0.65f;
}
} // namespace gr

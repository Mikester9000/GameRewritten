#include "save_indicator.h"

#include <algorithm>

namespace gr
{
void SaveIndicator::Begin(float visibleSeconds)
{
    m_totalSeconds = std::max(visibleSeconds, 0.1f);
    m_remainingSeconds = m_totalSeconds;
}

void SaveIndicator::Tick(float deltaSeconds)
{
    m_remainingSeconds = std::max(0.0f, m_remainingSeconds - std::max(deltaSeconds, 0.0f));
}

float SaveIndicator::GetAlpha() const
{
    if (m_totalSeconds <= 0.0f)
    {
        return 0.0f;
    }
    return std::clamp(m_remainingSeconds / m_totalSeconds, 0.0f, 1.0f);
}
} // namespace gr

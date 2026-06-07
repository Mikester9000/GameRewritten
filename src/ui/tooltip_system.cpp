#include "tooltip_system.h"

#include <algorithm>

namespace gr
{
void TooltipSystem::ShowTooltip(const std::string& title, const std::string& body, float lifetimeSeconds)
{
    m_state.title = title;
    m_state.body = body;
    m_state.remainingSeconds = std::max(lifetimeSeconds, 0.0f);
}

void TooltipSystem::Clear()
{
    m_state = {};
}

void TooltipSystem::Tick(float deltaSeconds)
{
    m_state.remainingSeconds = std::max(0.0f, m_state.remainingSeconds - std::max(deltaSeconds, 0.0f));
    if (m_state.remainingSeconds <= 0.0f)
    {
        m_state.title.clear();
        m_state.body.clear();
    }
}

bool TooltipSystem::IsVisible() const
{
    return m_state.remainingSeconds > 0.0f && (!m_state.title.empty() || !m_state.body.empty());
}
} // namespace gr

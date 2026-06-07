#include "defeat_screen.h"

#include <algorithm>

namespace gr
{
void DefeatScreen::Show(const std::string& reasonText)
{
    m_visible = true;
    m_visibleSeconds = 0.0f;
    m_reasonText = reasonText.empty() ? "Party defeated" : reasonText;
}

void DefeatScreen::Hide()
{
    m_visible = false;
    m_visibleSeconds = 0.0f;
}

bool DefeatScreen::CanAcceptInput(float minSecondsBeforeInput) const
{
    return m_visible && m_visibleSeconds >= std::max(minSecondsBeforeInput, 0.0f);
}

void DefeatScreen::Tick(float deltaSeconds)
{
    if (m_visible)
    {
        m_visibleSeconds += std::max(deltaSeconds, 0.0f);
    }
}
} // namespace gr

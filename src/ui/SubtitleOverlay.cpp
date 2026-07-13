// SubtitleOverlay.cpp
// Timed subtitle display with speaker-colour differentiation.

#include "SubtitleOverlay.hpp"

#include "../ThirdParty/imgui/imgui.h"

#include <algorithm>

void SubtitleOverlay::Show(const Entry& entry)
{
    m_current = entry;
    m_elapsed = 0.0f;
    m_active  = true;
}

void SubtitleOverlay::Update(float dt, float vpW, float vpH)
{
    if (!m_active) return;

    m_elapsed += dt;
    if (m_elapsed >= m_current.duration) { m_active = false; return; }

    // Fade in for 0.3s, fade out for last 0.3s.
    const float fadeIn  = std::min(1.0f, m_elapsed / 0.3f);
    const float fadeOut = std::min(1.0f, (m_current.duration - m_elapsed) / 0.3f);
    const float alpha   = std::min(fadeIn, fadeOut);

    const ImU32 textCol = IM_COL32(255, 255, 255, static_cast<int>(alpha * 230));
    const ImU32 bgCol   = IM_COL32(0, 0, 0, static_cast<int>(alpha * 140));

    ImDrawList* dl = ImGui::GetForegroundDrawList();

    const float boxH = 42.0f;
    const float boxY = vpH - 80.0f;
    dl->AddRectFilled({ 0.0f, boxY }, { vpW, boxY + boxH }, bgCol);

    if (!m_current.speaker.empty())
    {
        const ImU32 spkCol = IM_COL32(255, 220, 80, static_cast<int>(alpha * 230));
        dl->AddText({ vpW * 0.5f - 60.0f, boxY + 4.0f }, spkCol,
                    m_current.speaker.c_str());
    }
    dl->AddText({ vpW * 0.5f - 120.0f, boxY + 20.0f }, textCol,
                m_current.text.c_str());
}

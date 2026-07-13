// TutorialOverlay.cpp
// Context-sensitive tutorial tips with seen-state suppression.

#include "TutorialOverlay.hpp"

#include "../../third_party/imgui/imgui.h"

#include <algorithm>

void TutorialOverlay::ShowTip(const TutorialTip& tip)
{
    if (m_seen.count(tip.id)) return; // already seen

    m_current = tip;
    m_elapsed = 0.0f;
    m_active  = true;
    m_seen.insert(tip.id);
}

void TutorialOverlay::Update(float dt, float vpW, float vpH)
{
    if (!m_active) return;

    m_elapsed += dt;
    if (m_elapsed >= m_current.duration) { m_active = false; return; }

    const float fadeIn  = std::min(1.0f, m_elapsed / 0.4f);
    const float fadeOut = std::min(1.0f, (m_current.duration - m_elapsed) / 0.4f);
    const float alpha   = std::min(fadeIn, fadeOut);

    ImDrawList* dl = ImGui::GetForegroundDrawList();
    const float w  = 360.0f;
    const float h  = 32.0f;
    const float x  = vpW * 0.5f - w * 0.5f;
    const float y  = vpH * 0.75f;

    dl->AddRectFilled({ x, y }, { x + w, y + h },
        IM_COL32(0, 0, 0, static_cast<int>(140 * alpha)), 6.0f);
    dl->AddText({ x + 8.0f, y + 8.0f },
        IM_COL32(255, 255, 180, static_cast<int>(230 * alpha)),
        m_current.text.c_str());
}

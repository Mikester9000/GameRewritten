// CreditsScreen.cpp
// Scrolling credits using ImGui draw-list text rendering.

#include "CreditsScreen.hpp"

#include "../ThirdParty/imgui/imgui.h"

void CreditsScreen::Open()
{
    m_open   = true;
    m_scroll = 0.0f;
    if (m_entries.empty()) BuildEntries();
}

void CreditsScreen::BuildEntries()
{
    m_entries = {
        { "Game Design & Development", "Mikester9000" },
        { "Engine Architecture", "GameRewritten Contributors" },
        { "Third-Party Libraries", "ImGui, Jolt Physics, Recast/Detour, miniaudio, DirectXTex, Tracy" },
        { "Special Thanks", "Every open-source contributor" },
    };
}

void CreditsScreen::Draw(float dt, float vpW, float vpH)
{
    if (!m_open) return;

    constexpr float kScrollSpeed = 30.0f;
    m_scroll += dt * kScrollSpeed;

    ImDrawList* dl = ImGui::GetForegroundDrawList();
    dl->AddRectFilled({ 0, 0 }, { vpW, vpH }, IM_COL32(0, 0, 0, 210));

    float y = vpH - m_scroll;
    for (const CreditsEntry& e : m_entries)
    {
        dl->AddText({ vpW * 0.5f - 80.0f, y },        IM_COL32(200,200,200,220), e.role.c_str());
        dl->AddText({ vpW * 0.5f - 60.0f, y + 16.0f },IM_COL32(255,255,255,255), e.name.c_str());
        y += 50.0f;
    }

    // Close once all entries have scrolled past the top.
    if (y < 0.0f) m_open = false;
}

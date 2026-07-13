// CombatDebugPanel.cpp
// Rolling DPS display + combat stat panel for designer tuning.

#include "CombatDebugPanel.hpp"

#include "../game/actors/PlayerStats.hpp"
#include "../../third_party/imgui/imgui.h"

void CombatDebugPanel::RecordHit(int damage)
{
    m_accumulated += static_cast<float>(damage);
}

void CombatDebugPanel::Draw(float dt, const PlayerStats* player, const CombatSystem* /*combat*/)
{
    if (!m_open) return;

    // Rolling DPS calculation.
    m_timer += dt;
    if (m_timer >= m_window)
    {
        m_dps         = m_accumulated / m_window;
        m_accumulated = 0.0f;
        m_timer       = 0.0f;
    }

    ImGui::Begin("Combat Debug", &m_open, ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::Text("DPS (%.1fs window): %.1f", m_window, m_dps);
    ImGui::Separator();

    if (player)
    {
        ImGui::Text("HP:    %d / %d", player->hp,    player->maxHp);
        ImGui::Text("MP:    %d / %d", player->mp,    player->maxMp);
        ImGui::Text("Surge: %.2f",    player->surgeCharge);
        ImGui::Text("Limit: %.2f",    player->limitCharge);
    }

    ImGui::End();
}

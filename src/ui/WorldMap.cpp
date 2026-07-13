// WorldMap.cpp
// World map overlay: continent zoom + region zoom + player marker dot.

#include "WorldMap.hpp"

#include "../../third_party/imgui/imgui.h"

namespace
{
// Map is rendered as a coloured rect with a dot for the player position.
// Replace with actual continent texture once assets are authored.
constexpr float kMapSize  = 500.0f;
constexpr float kWorldExtent = 2000.0f; // half-width of the whole world in units

ImVec2 WorldToMap(float wx, float wz, float mapOriginX, float mapOriginY, float scale)
{
    return {
        mapOriginX + (wx / kWorldExtent) * (kMapSize * 0.5f) * scale,
        mapOriginY + (wz / kWorldExtent) * (kMapSize * 0.5f) * scale
    };
}
} // namespace

void WorldMap::Draw(float playerX, float playerZ, float vpW, float vpH)
{
    if (!m_open) return;

    ImGui::SetNextWindowPos({ vpW * 0.5f - kMapSize * 0.5f, vpH * 0.5f - kMapSize * 0.5f });
    ImGui::SetNextWindowSize({ kMapSize, kMapSize });
    ImGui::Begin("World Map", &m_open,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);

    if (m_zoom == 0) DrawContinent(playerX, playerZ, vpW, vpH);
    else             DrawRegion   (playerX, playerZ, vpW, vpH);

    if (ImGui::Button("Zoom In"))  m_zoom = 1;
    ImGui::SameLine();
    if (ImGui::Button("Zoom Out")) m_zoom = 0;

    ImGui::End();
}

void WorldMap::DrawContinent(float playerX, float playerZ, float /*vpW*/, float /*vpH*/)
{
    ImDrawList* dl    = ImGui::GetWindowDrawList();
    const ImVec2 orig = ImGui::GetCursorScreenPos();

    // Background (ocean blue).
    dl->AddRectFilled(orig, { orig.x + kMapSize, orig.y + kMapSize }, IM_COL32(30, 60, 120, 200));
    // Placeholder land mass (green rect).
    dl->AddRectFilled({ orig.x + 80, orig.y + 80 }, { orig.x + 420, orig.y + 420 }, IM_COL32(60, 120, 60, 200));

    // Player dot.
    const ImVec2 dot = WorldToMap(playerX, playerZ, orig.x + kMapSize * 0.5f, orig.y + kMapSize * 0.5f, 1.0f);
    dl->AddCircleFilled(dot, 5.0f, IM_COL32(255, 220, 40, 255));

    ImGui::Dummy({ kMapSize, kMapSize - 40 });
}

void WorldMap::DrawRegion(float playerX, float playerZ, float /*vpW*/, float /*vpH*/)
{
    ImDrawList* dl    = ImGui::GetWindowDrawList();
    const ImVec2 orig = ImGui::GetCursorScreenPos();

    dl->AddRectFilled(orig, { orig.x + kMapSize, orig.y + kMapSize }, IM_COL32(50, 90, 50, 200));

    const ImVec2 dot = WorldToMap(playerX, playerZ, orig.x + kMapSize * 0.5f, orig.y + kMapSize * 0.5f, 4.0f);
    dl->AddCircleFilled(dot, 6.0f, IM_COL32(255, 220, 40, 255));

    ImGui::Dummy({ kMapSize, kMapSize - 40 });
}

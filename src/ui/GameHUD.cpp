#include "GameHUD.hpp"

#include <imgui.h>

#include <algorithm>

namespace
{
constexpr float kHudOffsetX = 20.0f;
constexpr float kHudOffsetBottom = 130.0f;
constexpr float kHudWidth = 220.0f;
constexpr float kHudHeight = 110.0f;
constexpr float kGaugeWidth = 120.0f;
const ImVec2 kGaugeSize(kGaugeWidth, 0.0f);

float NormalizeValue(float value, float maxValue)
{
    if (maxValue <= 0.0f)
        return 0.0f;
    return std::clamp(value / maxValue, 0.0f, 1.0f);
}
}

void GameHUD::Draw(const PlayerStats& stats, const ImGuiIO& io)
{
    ImGui::SetNextWindowPos(ImVec2(kHudOffsetX, io.DisplaySize.y - kHudOffsetBottom), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(kHudWidth, kHudHeight), ImGuiCond_Always);

    const ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoInputs |
        ImGuiWindowFlags_NoNav |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBackground |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    if (!ImGui::Begin("##GameplayHUD", nullptr, flags))
    {
        ImGui::End();
        return;
    }

    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.8f, 0.1f, 0.1f, 1.0f));
    ImGui::ProgressBar(NormalizeValue(stats.hp, stats.maxHp), kGaugeSize, "");
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::Text("HP  %d / %d", static_cast<int>(stats.hp), static_cast<int>(stats.maxHp));

    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.1f, 0.3f, 0.9f, 1.0f));
    ImGui::ProgressBar(NormalizeValue(stats.mp, stats.maxMp), kGaugeSize, "");
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::Text("MP  %d / %d", static_cast<int>(stats.mp), static_cast<int>(stats.maxMp));

    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.9f, 0.8f, 0.1f, 1.0f));
    ImGui::ProgressBar(NormalizeValue(stats.atbCharge, 1.0f), kGaugeSize, "");
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::Text("ATB");
    if (stats.IsAtbReady())
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.1f, 0.9f, 0.2f, 1.0f), "READY");
    }

    ImGui::End();
}

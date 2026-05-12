#include "GameHUD.hpp"

#include <imgui.h>

#include <algorithm>
#include <cmath>

namespace
{
constexpr float kHudOffsetX = 20.0f;
constexpr float kHudBottomMargin = 20.0f;
constexpr float kHudWidth = 220.0f;
constexpr float kHudHeight = 110.0f;
constexpr float kGaugeWidth = 120.0f;
const ImVec2 kGaugeSize(kGaugeWidth, 0.0f);

// HP fraction below which the low-HP warning pulse activates.
constexpr float kLowHpThreshold = 0.25f;
// Pulse frequency in Hz (cycles per second).
constexpr float kPulseFrequency = 3.0f;
// Maximum alpha of the screen-edge pulse overlay (0-255).
constexpr int kPulseMaxAlpha = 140;
// Width of each screen-edge warning bar in pixels.
constexpr float kEdgeBarThickness = 28.0f;

float NormalizeValue(float value, float maxValue)
{
    if (maxValue <= 0.0f)
        return 0.0f;
    return std::clamp(value / maxValue, 0.0f, 1.0f);
}

void DrawLowHpPulse(const ImGuiIO& io, float totalTime)
{
    // Pulse brightness oscillates between 0 and kPulseMaxAlpha.
    float t = 0.5f + 0.5f * sinf(totalTime * kPulseFrequency * 6.28318f);
    int alpha = static_cast<int>(t * static_cast<float>(kPulseMaxAlpha));
    ImU32 color = IM_COL32(200, 20, 20, alpha);

    float screenW = io.DisplaySize.x;
    float screenH = io.DisplaySize.y;
    float th = kEdgeBarThickness;

    ImDrawList* dl = ImGui::GetForegroundDrawList();
    // Top bar
    dl->AddRectFilled(ImVec2(0.0f, 0.0f), ImVec2(screenW, th), color);
    // Bottom bar
    dl->AddRectFilled(ImVec2(0.0f, screenH - th), ImVec2(screenW, screenH), color);
    // Left bar
    dl->AddRectFilled(ImVec2(0.0f, th), ImVec2(th, screenH - th), color);
    // Right bar
    dl->AddRectFilled(ImVec2(screenW - th, th), ImVec2(screenW, screenH - th), color);
}
}

void GameHUD::Draw(const PlayerStats& stats, const ImGuiIO& io, float totalTime)
{
    ImGui::SetNextWindowPos(ImVec2(kHudOffsetX, io.DisplaySize.y - kHudHeight - kHudBottomMargin), ImGuiCond_Always);
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

    // HP bar — flash a brighter red when critically low.
    const float hpFraction = NormalizeValue(stats.hp, stats.maxHp);
    const bool  isLowHp    = (hpFraction < kLowHpThreshold);
    ImVec4 hpColor = isLowHp ? ImVec4(1.0f, 0.1f, 0.1f, 1.0f)
                              : ImVec4(0.8f, 0.1f, 0.1f, 1.0f);

    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, hpColor);
    ImGui::ProgressBar(hpFraction, kGaugeSize, "");
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::Text("HP  %.0f / %.0f", stats.hp, stats.maxHp);

    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.1f, 0.3f, 0.9f, 1.0f));
    ImGui::ProgressBar(NormalizeValue(stats.mp, stats.maxMp), kGaugeSize, "");
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::Text("MP  %.0f / %.0f", stats.mp, stats.maxMp);

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

    // Draw screen-edge danger pulse when HP is critically low.
    if (isLowHp)
        DrawLowHpPulse(io, totalTime);
}

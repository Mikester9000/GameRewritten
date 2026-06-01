// ============================================================
// FILE: src/ui/GameHUD.cpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: GameHUD module behavior and local implementation details.
// ============================================================

#include "GameHUD.hpp"
#include "ScreenProjection.hpp"

#include <imgui.h>
#include <DirectXMath.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cctype>

#include "../game/actors/EnemyActor.hpp"

namespace
{
constexpr float kHudOffsetX = 20.0f;
constexpr float kHudBottomMargin = 20.0f;
constexpr float kHudWidth = 220.0f;
constexpr float kHudHeight = 140.0f; // tall enough for HP / MP / SURGE / LIMIT bars
constexpr float kGaugeWidth = 120.0f;
const ImVec2 kGaugeSize(kGaugeWidth, 0.0f);

// HP fraction below which the low-HP warning pulse activates.
constexpr float kLowHpThreshold = 0.25f;
// Pulse frequency in Hz (cycles per second).
constexpr float kPulseFrequency = 3.0f;
// Full circle in radians (2π).
constexpr float kTwoPi = 6.28318530f;
// Maximum alpha of the screen-edge pulse overlay (0-255).
constexpr int kPulseMaxAlpha = 140;
// Width of each screen-edge warning bar in pixels.
constexpr float kEdgeBarThickness = 28.0f;
// Duration and max alpha of the on-hit damage flash.
constexpr float kDamageFlashDuration = 0.25f;
constexpr int   kDamageFlashMaxAlpha = 180;
constexpr float kAreaBannerDurationSec = 2.8f;
constexpr float kToastDefaultLifeSec = 2.4f;
constexpr int   kToastMaxVisible = 3;
constexpr float kAreaBannerTopMargin = 28.0f;
constexpr float kToastTopMargin = 80.0f;
constexpr float kToastRightMargin = 20.0f;
constexpr float kToastSpacing = 6.0f;
constexpr float kLevelUpOverlayDurationSec = 2.2f;

// --- Target info panel ---
constexpr float kTargetPanelW       = 280.0f;
constexpr float kTargetPanelPadX    =  10.0f;
constexpr float kTargetPanelPadY    =   8.0f;
constexpr float kTargetBarH         =   9.0f;
constexpr float kTargetBarGap       =   4.0f;
// Gap between bottom edge of panel and the screen edge.
constexpr float kTargetMarginBottom =  24.0f;

// --- Combo step indicator ---
constexpr float kComboPanelW      = 150.0f;
constexpr float kComboPanelH      =  28.0f;
constexpr float kComboSquareSize  =  12.0f;
// Extra gap above the target panel so the two panels never overlap.
constexpr float kComboGapAbove    =  10.0f;

// --- Off-screen lock-on target indicator ---
constexpr float kOffscreenIndicatorMargin = 44.0f;
constexpr float kOffscreenIndicatorRadius = 10.0f;
constexpr float kOffscreenArrowSize = 8.0f;
constexpr float kTargetIndicatorHeightOffset = 1.8f;

int ScaleAlpha(int alpha, float opacity)
{
    const float clampedOpacity = std::clamp(opacity, 0.0f, 1.0f);
    return static_cast<int>(std::clamp(alpha * clampedOpacity, 0.0f, 255.0f));
}

ImU32 ApplyOpacity(ImU32 color, float opacity)
{
    const ImVec4 unpacked = ImGui::ColorConvertU32ToFloat4(color);
    return ImGui::ColorConvertFloat4ToU32(
        ImVec4(unpacked.x, unpacked.y, unpacked.z, unpacked.w * std::clamp(opacity, 0.0f, 1.0f)));
}

float NormalizeValue(float value, float maxValue)
{
    if (maxValue <= 0.0f)
        return 0.0f;
    return std::clamp(value / maxValue, 0.0f, 1.0f);
}

std::string HumanizeAreaName(const std::string& rawBiome)
{
    if (rawBiome.empty())
        return "Unknown Area";

    std::string out;
    out.reserve(rawBiome.size());
    bool capitalizeNext = true;
    for (char ch : rawBiome)
    {
        if (ch == '_' || ch == '-')
        {
            out.push_back(' ');
            capitalizeNext = true;
            continue;
        }

        if (capitalizeNext)
        {
            out.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(ch))));
            capitalizeNext = false;
        }
        else
        {
            out.push_back(ch);
        }
    }
    return out;
}

float FadeAlpha(float life, float maxLife)
{
    if (maxLife <= 0.0f || life <= 0.0f)
        return 0.0f;

    const float ratio = std::clamp(life / maxLife, 0.0f, 1.0f);
    return (ratio > 0.25f) ? 1.0f : (ratio / 0.25f);
}

// Returns the pixel height of the target-info panel, derived from the current
// font size. Both DrawTargetInfo and DrawComboIndicator use this so the combo
// panel always sits flush above the target panel even if padding changes.
// Includes rows for: name + HP bar + pressure bar.
float CalcTargetPanelHeight()
{
    return kTargetPanelPadY + ImGui::GetFontSize() + kTargetBarGap + kTargetBarH +
           kTargetBarGap + kTargetBarH + kTargetPanelPadY;
}

void DrawLowHpPulse(const ImGuiIO& io, float pulseTime, float opacity)
{
    // Pulse brightness oscillates between 0 and kPulseMaxAlpha.
    float pulseRatio = 0.5f + 0.5f * sinf(pulseTime * kPulseFrequency * kTwoPi);
    int alpha = ScaleAlpha(static_cast<int>(pulseRatio * static_cast<float>(kPulseMaxAlpha)), opacity);
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

// Brief bright-red screen-edge flash played once when the player takes damage.
// fraction: 1.0 = just triggered, 0.0 = fully faded out.
void DrawDamageFlash(const ImGuiIO& io, float fraction, float opacity)
{
    int alpha = ScaleAlpha(static_cast<int>(fraction * static_cast<float>(kDamageFlashMaxAlpha)), opacity);
    ImU32 color = IM_COL32(255, 40, 40, alpha);

    float screenW = io.DisplaySize.x;
    float screenH = io.DisplaySize.y;
    float th = kEdgeBarThickness * 1.6f; // wider than the low-HP pulse bars

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
} // namespace

void GameHUD::SetOpacity(float opacity)
{
    m_opacity = std::clamp(opacity, 0.0f, 1.0f);
}

void GameHUD::SetAreaName(const std::string& areaName)
{
    const std::string sanitized = HumanizeAreaName(areaName);
    if (sanitized == m_currentAreaName)
        return;

    m_currentAreaName = sanitized;
    m_areaBannerTimer = kAreaBannerDurationSec;

    m_toasts.push_front({ "Entered " + m_currentAreaName, kToastDefaultLifeSec, kToastDefaultLifeSec });
    while (static_cast<int>(m_toasts.size()) > kToastMaxVisible)
        m_toasts.pop_back();
}

void GameHUD::SetContextPrompt(const std::string& prompt, bool visible)
{
    m_contextPrompt = prompt;
    m_contextPromptVisible = visible && !prompt.empty();
}

void GameHUD::TriggerLevelUpOverlay(int newLevel)
{
    m_lastLevelUp = std::max(newLevel, 1);
    m_levelUpOverlayTimer = kLevelUpOverlayDurationSec;
    m_toasts.push_front({ "Level up! Lv." + std::to_string(m_lastLevelUp), kToastDefaultLifeSec, kToastDefaultLifeSec });
    while (static_cast<int>(m_toasts.size()) > kToastMaxVisible)
        m_toasts.pop_back();
}

void GameHUD::Draw(const PlayerStats& stats, const ImGuiIO& io, float dt)
{
    if (m_areaBannerTimer > 0.0f)
        m_areaBannerTimer = std::max(0.0f, m_areaBannerTimer - dt);
    if (m_levelUpOverlayTimer > 0.0f)
        m_levelUpOverlayTimer = std::max(0.0f, m_levelUpOverlayTimer - dt);

    for (auto& toast : m_toasts)
        toast.life = std::max(0.0f, toast.life - dt);
    while (!m_toasts.empty() && m_toasts.back().life <= 0.0f)
        m_toasts.pop_back();

    m_lowHpPulseTime += (dt > 0.0f) ? dt : 0.0f;

    const float hudOffsetX = m_ultrawideLayoutEnabled ? 48.0f : kHudOffsetX;
    const float hudBottomMargin = m_ultrawideLayoutEnabled ? 28.0f : kHudBottomMargin;
    ImGui::SetNextWindowPos(ImVec2(hudOffsetX, io.DisplaySize.y - kHudHeight - hudBottomMargin), ImGuiCond_Always);
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

    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, m_opacity);

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
    ImGui::ProgressBar(NormalizeValue(stats.surgeCharge, 1.0f), kGaugeSize, "");
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::Text("SURGE");
    if (stats.IsSurgeReady())
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.1f, 0.9f, 0.2f, 1.0f), "READY  F");
    }

    // Limit bar — purple fill; shows prompt when full.
    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.6f, 0.1f, 0.9f, 1.0f));
    ImGui::ProgressBar(NormalizeValue(stats.limitCharge, 1.0f), kGaugeSize, "");
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::Text("LIMIT");
    if (stats.IsLimitReady())
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.9f, 0.4f, 1.0f, 1.0f), "READY  Shift+F");
    }

    ImGui::PopStyleVar();
    ImGui::End();

    // Draw screen-edge danger pulse when HP is critically low.
    if (isLowHp)
        DrawLowHpPulse(io, m_lowHpPulseTime, m_opacity);

    // Draw and tick the on-hit damage flash (brief red edge flash when player is struck).
    if (m_damageFlashTimer > 0.0f)
    {
        DrawDamageFlash(io, m_damageFlashTimer / kDamageFlashDuration, m_opacity);
        m_damageFlashTimer -= dt;
        if (m_damageFlashTimer < 0.0f)
            m_damageFlashTimer = 0.0f;
    }

    ImDrawList* dl = ImGui::GetForegroundDrawList();
    if (dl && m_areaBannerTimer > 0.0f)
    {
        const float alpha = FadeAlpha(m_areaBannerTimer, kAreaBannerDurationSec);
        const ImVec2 textSize = ImGui::CalcTextSize(m_currentAreaName.c_str());
        const float boxPadX = 16.0f;
        const float boxPadY = 7.0f;
        const float boxW = textSize.x + boxPadX * 2.0f;
        const float boxH = textSize.y + boxPadY * 2.0f;
        const float boxX = (io.DisplaySize.x - boxW) * 0.5f;
        const float boxY = kAreaBannerTopMargin;
        const float combinedAlpha = std::clamp(alpha * m_opacity, 0.0f, 1.0f);

        dl->AddRectFilled(ImVec2(boxX, boxY), ImVec2(boxX + boxW, boxY + boxH),
                          IM_COL32(6, 8, 24, static_cast<int>(210.0f * combinedAlpha)), 4.0f);
        dl->AddRect(ImVec2(boxX, boxY), ImVec2(boxX + boxW, boxY + boxH),
                    IM_COL32(90, 140, 220, static_cast<int>(255.0f * combinedAlpha)), 4.0f);
        dl->AddText(ImVec2(boxX + boxPadX, boxY + boxPadY),
                    IM_COL32(225, 230, 240, static_cast<int>(255.0f * combinedAlpha)),
                    m_currentAreaName.c_str());
    }

    if (dl)
    {
        float y = kToastTopMargin;
        for (const ToastEntry& toast : m_toasts)
        {
            const float alpha = std::clamp(FadeAlpha(toast.life, toast.maxLife) * m_opacity, 0.0f, 1.0f);
            if (alpha <= 0.0f)
                continue;

            const ImVec2 textSize = ImGui::CalcTextSize(toast.text.c_str());
            const float boxPadX = 11.0f;
            const float boxPadY = 6.0f;
            const float boxW = textSize.x + boxPadX * 2.0f;
            const float boxH = textSize.y + boxPadY * 2.0f;
            const float x = io.DisplaySize.x - kToastRightMargin - boxW;

            dl->AddRectFilled(ImVec2(x, y), ImVec2(x + boxW, y + boxH),
                              IM_COL32(10, 15, 32, static_cast<int>(200.0f * alpha)), 4.0f);
            dl->AddRect(ImVec2(x, y), ImVec2(x + boxW, y + boxH),
                        IM_COL32(90, 155, 255, static_cast<int>(255.0f * alpha)), 4.0f);
            dl->AddText(ImVec2(x + boxPadX, y + boxPadY),
                        IM_COL32(235, 240, 250, static_cast<int>(255.0f * alpha)),
                        toast.text.c_str());
            y += boxH + kToastSpacing;
        }

        if (m_contextPromptVisible)
        {
            const ImVec2 textSize = ImGui::CalcTextSize(m_contextPrompt.c_str());
            const float boxPadX = 12.0f;
            const float boxPadY = 7.0f;
            const float boxW = textSize.x + boxPadX * 2.0f;
            const float boxH = textSize.y + boxPadY * 2.0f;
            const float boxX = (io.DisplaySize.x - boxW) * 0.5f;
            const float boxY = io.DisplaySize.y - boxH - 120.0f;
            dl->AddRectFilled(ImVec2(boxX, boxY), ImVec2(boxX + boxW, boxY + boxH),
                              IM_COL32(12, 15, 30, ScaleAlpha(210, m_opacity)), 4.0f);
            dl->AddRect(ImVec2(boxX, boxY), ImVec2(boxX + boxW, boxY + boxH),
                        IM_COL32(80, 150, 255, ScaleAlpha(255, m_opacity)), 4.0f);
            dl->AddText(ImVec2(boxX + boxPadX, boxY + boxPadY),
                        IM_COL32(240, 245, 255, ScaleAlpha(255, m_opacity)),
                        m_contextPrompt.c_str());
        }

        if (m_levelUpOverlayTimer > 0.0f)
        {
            const float alpha = std::clamp(FadeAlpha(m_levelUpOverlayTimer, kLevelUpOverlayDurationSec) * m_opacity, 0.0f, 1.0f);
            const std::string levelLabel = "LEVEL UP!  Lv." + std::to_string(std::max(m_lastLevelUp, 1));
            const ImVec2 textSize = ImGui::CalcTextSize(levelLabel.c_str());
            const float boxPadX = 24.0f;
            const float boxPadY = 10.0f;
            const float boxW = textSize.x + boxPadX * 2.0f;
            const float boxH = textSize.y + boxPadY * 2.0f;
            const float boxX = (io.DisplaySize.x - boxW) * 0.5f;
            const float boxY = io.DisplaySize.y * 0.18f;
            dl->AddRectFilled(ImVec2(boxX, boxY), ImVec2(boxX + boxW, boxY + boxH),
                              IM_COL32(22, 28, 46, static_cast<int>(220.0f * alpha)), 5.0f);
            dl->AddRect(ImVec2(boxX, boxY), ImVec2(boxX + boxW, boxY + boxH),
                        IM_COL32(255, 205, 70, static_cast<int>(255.0f * alpha)), 5.0f);
            dl->AddText(ImVec2(boxX + boxPadX, boxY + boxPadY),
                        IM_COL32(255, 238, 120, static_cast<int>(255.0f * alpha)),
                        levelLabel.c_str());
        }

        if (m_showStatusScreen)
        {
            const float panelW = 340.0f;
            const float panelH = 240.0f;
            const float x = (io.DisplaySize.x - panelW) * 0.5f;
            const float y = (io.DisplaySize.y - panelH) * 0.5f;
            dl->AddRectFilled(ImVec2(x, y), ImVec2(x + panelW, y + panelH),
                              IM_COL32(6, 10, 25, ScaleAlpha(230, m_opacity)), 6.0f);
            dl->AddRect(ImVec2(x, y), ImVec2(x + panelW, y + panelH),
                        IM_COL32(95, 155, 255, ScaleAlpha(255, m_opacity)), 6.0f);

            const float tx = x + 18.0f;
            float ty = y + 16.0f;
            dl->AddText(ImVec2(tx, ty), IM_COL32(225, 235, 250, ScaleAlpha(255, m_opacity)), "STATUS");
            ty += 34.0f;
            const std::string lv = "Level: " + std::to_string(stats.level);
            dl->AddText(ImVec2(tx, ty), IM_COL32(220, 220, 230, ScaleAlpha(255, m_opacity)), lv.c_str());
            ty += 24.0f;
            char hp[64];
            std::snprintf(hp, sizeof(hp), "HP: %.0f / %.0f", stats.hp, stats.maxHp);
            dl->AddText(ImVec2(tx, ty), IM_COL32(220, 220, 230, ScaleAlpha(255, m_opacity)), hp);
            ty += 24.0f;
            char mp[64];
            std::snprintf(mp, sizeof(mp), "MP: %.0f / %.0f", stats.mp, stats.maxMp);
            dl->AddText(ImVec2(tx, ty), IM_COL32(220, 220, 230, ScaleAlpha(255, m_opacity)), mp);
            ty += 24.0f;
            const std::string xp = "XP: " + std::to_string(stats.xp) + " / " + std::to_string(stats.xpToNextLevel);
            dl->AddText(ImVec2(tx, ty), IM_COL32(220, 220, 230, ScaleAlpha(255, m_opacity)), xp.c_str());
            ty += 24.0f;
            const std::string status = std::string("Status Effect: ") + stats.statusEffect.GetName();
            dl->AddText(ImVec2(tx, ty), IM_COL32(220, 220, 230, ScaleAlpha(255, m_opacity)), status.c_str());
            dl->AddText(ImVec2(tx, y + panelH - 26.0f), IM_COL32(150, 170, 190, ScaleAlpha(255, m_opacity)),
                        "Press C to close");
        }

        if (m_showMapScreen)
        {
            const float panelW = 440.0f;
            const float panelH = 280.0f;
            const float x = (io.DisplaySize.x - panelW) * 0.5f;
            const float y = (io.DisplaySize.y - panelH) * 0.5f;
            dl->AddRectFilled(ImVec2(x, y), ImVec2(x + panelW, y + panelH),
                              IM_COL32(8, 12, 24, ScaleAlpha(235, m_opacity)), 6.0f);
            dl->AddRect(ImVec2(x, y), ImVec2(x + panelW, y + panelH),
                        IM_COL32(110, 180, 255, ScaleAlpha(255, m_opacity)), 6.0f);
            dl->AddText(ImVec2(x + 18.0f, y + 16.0f), IM_COL32(228, 236, 248, ScaleAlpha(255, m_opacity)), "MAP");
            dl->AddText(ImVec2(x + 18.0f, y + 48.0f), IM_COL32(180, 195, 214, ScaleAlpha(255, m_opacity)),
                        "Map screen stub: full world map data hookup pending.");
            dl->AddRectFilled(ImVec2(x + 18.0f, y + 84.0f), ImVec2(x + panelW - 18.0f, y + panelH - 48.0f),
                              IM_COL32(15, 20, 38, ScaleAlpha(255, m_opacity)), 4.0f);
            dl->AddText(ImVec2(x + 30.0f, y + 104.0f), IM_COL32(110, 130, 155, ScaleAlpha(255, m_opacity)),
                        "WORLD MAP PLACEHOLDER");
            dl->AddText(ImVec2(x + 18.0f, y + panelH - 26.0f), IM_COL32(150, 170, 190, ScaleAlpha(255, m_opacity)),
                        "Press M to close");
        }
    }
}

void GameHUD::TriggerDamageFlash()
{
    m_damageFlashTimer = kDamageFlashDuration;
}

void GameHUD::DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io)
{
    if (!target) return;

    // Calculate panel height from the current font size so it scales correctly.
    const float panelH = CalcTargetPanelHeight();
    const float fontH  = ImGui::GetFontSize();
    const float panelW = m_ultrawideLayoutEnabled ? (kTargetPanelW + 40.0f) : kTargetPanelW;
    const float posX   = (io.DisplaySize.x - panelW) * 0.5f;
    const float posY   = io.DisplaySize.y - panelH - (m_ultrawideLayoutEnabled ? 34.0f : kTargetMarginBottom);

    ImDrawList* dl = ImGui::GetForegroundDrawList();

    // Dark navy background — classic FF7R command-panel style.
    dl->AddRectFilled(ImVec2(posX, posY),
                      ImVec2(posX + panelW, posY + panelH),
                      ApplyOpacity(IM_COL32(6, 8, 24, 215), m_opacity), 3.0f);

    // Thin bright-blue accent line at the top of the panel.
    dl->AddRectFilled(ImVec2(posX, posY),
                      ImVec2(posX + panelW, posY + 2.0f),
                      ApplyOpacity(IM_COL32(70, 130, 240, 255), m_opacity));

    // Subtle border so the panel reads cleanly against the scene.
    dl->AddRect(ImVec2(posX, posY),
                ImVec2(posX + panelW, posY + panelH),
                ApplyOpacity(IM_COL32(50, 60, 100, 180), m_opacity), 3.0f);

    // --- Name row ---
    const float nameY = posY + kTargetPanelPadY;
    dl->AddText(ImVec2(posX + kTargetPanelPadX, nameY),
                ApplyOpacity(IM_COL32(220, 220, 230, 255), m_opacity), target->name);

    // HP numbers right-aligned on the same row.
    char hpText[32];
    std::snprintf(hpText, sizeof(hpText), "%d / %d", target->hp, target->maxHp);
    const ImVec2 hpTextSize = ImGui::CalcTextSize(hpText);
    dl->AddText(ImVec2(posX + panelW - kTargetPanelPadX - hpTextSize.x, nameY),
                ApplyOpacity(IM_COL32(190, 195, 210, 255), m_opacity), hpText);

    // --- HP bar ---
    const float barX   = posX + kTargetPanelPadX;
    const float barY   = nameY + fontH + kTargetBarGap;
    const float barW   = panelW - kTargetPanelPadX * 2.0f;
    const float hpFrac = (target->maxHp > 0)
        ? std::clamp(static_cast<float>(target->hp) / static_cast<float>(target->maxHp), 0.0f, 1.0f)
        : 0.0f;
    const float filledW = barW * hpFrac;

    // Color transitions green → orange → red as HP falls (matches FF7R damage feedback).
    ImU32 barColor;
    if      (hpFrac > 0.50f) barColor = IM_COL32( 50, 200,  80, 255);
    else if (hpFrac > 0.25f) barColor = IM_COL32(220, 155,  25, 255);
    else                     barColor = IM_COL32(215,  35,  35, 255);

    // Bar track (dark background).
    dl->AddRectFilled(ImVec2(barX, barY),
                      ImVec2(barX + barW, barY + kTargetBarH),
                      ApplyOpacity(IM_COL32(28, 28, 48, 255), m_opacity), 2.0f);

    // Bar fill.
    if (filledW > 0.0f)
        dl->AddRectFilled(ImVec2(barX, barY),
                          ImVec2(barX + filledW, barY + kTargetBarH),
                          ApplyOpacity(barColor, m_opacity), 2.0f);

    // Bar border.
    dl->AddRect(ImVec2(barX, barY),
                ImVec2(barX + barW, barY + kTargetBarH),
                ApplyOpacity(IM_COL32(70, 75, 110, 200), m_opacity), 2.0f);

    // --- Pressure / stagger bar ---
    const float pressureBarY = barY + kTargetBarH + kTargetBarGap;
    const bool  isStaggered  = target->IsStaggered();
    const float pressureFrac = target->GetPressureGauge();
    const float pressureFillW = isStaggered ? barW : (barW * pressureFrac);

    // Bar track (dark background).
    dl->AddRectFilled(ImVec2(barX, pressureBarY),
                      ImVec2(barX + barW, pressureBarY + kTargetBarH),
                      ApplyOpacity(IM_COL32(28, 28, 48, 255), m_opacity), 2.0f);

    // Filled portion: amber while building, bright cyan when staggered.
    if (pressureFillW > 0.0f)
    {
        ImU32 pressureColor = isStaggered
            ? IM_COL32( 40, 230, 240, 255)  // stagger active: cyan
            : IM_COL32(230, 170,  20, 255); // building: amber/gold
        dl->AddRectFilled(ImVec2(barX, pressureBarY),
                          ImVec2(barX + pressureFillW, pressureBarY + kTargetBarH),
                          ApplyOpacity(pressureColor, m_opacity), 2.0f);
    }

    // "STAGGERED" label centred in the bar when staggered; small "PRES" label otherwise.
    if (isStaggered)
    {
        const char* staggerLabel = "STAGGERED";
        const ImVec2 sz = ImGui::CalcTextSize(staggerLabel);
        dl->AddText(ImVec2(barX + (barW - sz.x) * 0.5f,
                           pressureBarY + (kTargetBarH - sz.y) * 0.5f),
                    ApplyOpacity(IM_COL32(255, 255,  50, 255), m_opacity), staggerLabel);
    }

    // Bar border.
    dl->AddRect(ImVec2(barX, pressureBarY),
                ImVec2(barX + barW, pressureBarY + kTargetBarH),
                ApplyOpacity(IM_COL32(70, 75, 110, 200), m_opacity), 2.0f);
}

void GameHUD::DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io)
{
    // Only show while the combo window is open after the first hit.
    if (comboStep == 0 || comboTimer <= 0.0f) return;

    // Position the combo panel centred and sitting just above the target panel area.
    const float targetH = CalcTargetPanelHeight();
    const float posX    = (io.DisplaySize.x - kComboPanelW) * 0.5f;
    const float comboBottomMargin = m_ultrawideLayoutEnabled ? 34.0f : kTargetMarginBottom;
    const float posY    = io.DisplaySize.y - targetH - comboBottomMargin - kComboGapAbove - kComboPanelH;

    // Fade the panel softly as the combo window runs out.
    const float fade     = (comboWindowSec > 0.0f)
        ? std::clamp(comboTimer / comboWindowSec, 0.0f, 1.0f)
        : 1.0f;
    const int   bgAlpha  = static_cast<int>(190.0f * fade);
    const int   fgAlpha  = static_cast<int>(255.0f * fade);

    ImDrawList* dl = ImGui::GetForegroundDrawList();

    // Background.
    dl->AddRectFilled(ImVec2(posX, posY),
                      ImVec2(posX + kComboPanelW, posY + kComboPanelH),
                      ApplyOpacity(IM_COL32(6, 8, 24, bgAlpha), m_opacity), 3.0f);
    dl->AddRect(ImVec2(posX, posY),
                ImVec2(posX + kComboPanelW, posY + kComboPanelH),
                ApplyOpacity(IM_COL32(50, 60, 100, bgAlpha), m_opacity), 3.0f);

    // Step squares — filled yellow for landed hit, open outline for next available input.
    const float squareY = posY + (kComboPanelH - kComboSquareSize) * 0.5f;
    const float sq1X    = posX + 10.0f;
    const float sq2X    = sq1X + kComboSquareSize + 6.0f;

    // Step 1 filled (already landed).
    dl->AddRectFilled(ImVec2(sq1X, squareY),
                      ImVec2(sq1X + kComboSquareSize, squareY + kComboSquareSize),
                      ApplyOpacity(IM_COL32(255, 200, 40, fgAlpha), m_opacity), 2.0f);

    // Step 2 open outline (next hit available).
    dl->AddRect(ImVec2(sq2X, squareY),
                ImVec2(sq2X + kComboSquareSize, squareY + kComboSquareSize),
                ApplyOpacity(IM_COL32(140, 140, 160, fgAlpha), m_opacity), 2.0f);

    // "COMBO" label to the right of the squares.
    const char* label     = "COMBO";
    const ImVec2 labelSz  = ImGui::CalcTextSize(label);
    dl->AddText(ImVec2(sq2X + kComboSquareSize + 8.0f,
                       posY + (kComboPanelH - labelSz.y) * 0.5f),
                ApplyOpacity(IM_COL32(220, 180, 50, fgAlpha), m_opacity), label);
}

void GameHUD::DrawOffScreenTargetIndicator(const EnemyActor* target,
                                           float camX, float camY, float camZ,
                                           float yaw, float pitch,
                                           float vpW, float vpH) const
{
    if (!target || vpW <= 0.0f || vpH <= 0.0f)
        return;

    // --- Step 1: skip indicator while target is visibly on-screen ---
    DirectX::XMMATRIX viewProj;
    if (!ScreenProjection::BuildViewProj(camX, camY, camZ, yaw, pitch, vpW, vpH, viewProj))
        return;

    float targetScreenX = 0.0f;
    float targetScreenY = 0.0f;
    const bool projectedToScreen = ScreenProjection::WorldToScreenVP(
        target->x, target->y + kTargetIndicatorHeightOffset, target->z,
        viewProj, vpW, vpH,
        targetScreenX, targetScreenY);

    if (projectedToScreen &&
        targetScreenX >= kOffscreenIndicatorMargin &&
        targetScreenX <= vpW - kOffscreenIndicatorMargin &&
        targetScreenY >= kOffscreenIndicatorMargin &&
        targetScreenY <= vpH - kOffscreenIndicatorMargin)
    {
        return;
    }

    // --- Step 2: build 2D direction from camera facing to target ---
    const float toTargetX = target->x - camX;
    const float toTargetZ = target->z - camZ;
    const float toTargetLenSq = (toTargetX * toTargetX) + (toTargetZ * toTargetZ);
    if (toTargetLenSq < 0.0001f)
        return;

    // Camera-space basis in this project:
    // yaw=0 faces +Z, right is +X, and Y is up.
    const float rightX   = cosf(yaw);
    const float rightZ   = -sinf(yaw);
    const float forwardX = sinf(yaw);
    const float forwardZ = cosf(yaw);

    const float localX = (toTargetX * rightX) + (toTargetZ * rightZ);
    const float localZ = (toTargetX * forwardX) + (toTargetZ * forwardZ);

    float dirX = localX;
    float dirY = -localZ;
    const float dirLenSq = (dirX * dirX) + (dirY * dirY);
    if (dirLenSq < 0.0001f)
        return;

    const float invDirLen = 1.0f / sqrtf(dirLenSq);
    dirX *= invDirLen;
    dirY *= invDirLen;

    // --- Step 3: clamp indicator to screen edge margin ---
    const float centerX = vpW * 0.5f;
    const float centerY = vpH * 0.5f;
    const float maxOffsetX = centerX - kOffscreenIndicatorMargin;
    const float maxOffsetY = centerY - kOffscreenIndicatorMargin;

    const float scaleX = (fabsf(dirX) > 0.0001f) ? (maxOffsetX / fabsf(dirX)) : 1000000.0f;
    const float scaleY = (fabsf(dirY) > 0.0001f) ? (maxOffsetY / fabsf(dirY)) : 1000000.0f;
    const float edgeScale = std::min(scaleX, scaleY);

    const float indicatorX = centerX + dirX * edgeScale;
    const float indicatorY = centerY + dirY * edgeScale;

    // --- Step 4: draw subtle lock-on arrow marker ---
    ImDrawList* drawList = ImGui::GetForegroundDrawList();
    if (!drawList)
        return;

    const ImVec2 indicatorCenter(indicatorX, indicatorY);
    drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, ApplyOpacity(IM_COL32(5, 10, 28, 220), m_opacity), 12);
    drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, ApplyOpacity(IM_COL32(90, 155, 255, 220), m_opacity), 12, 1.4f);

    const float perpX = -dirY;
    const float perpY = dirX;
    const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
                     indicatorY + dirY * kOffscreenArrowSize);
    const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
                      indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
    const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
    drawList->AddTriangleFilled(tip, left, right, ApplyOpacity(IM_COL32(200, 225, 255, 255), m_opacity));
}

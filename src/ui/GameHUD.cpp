#include "GameHUD.hpp"
#include "ScreenProjection.hpp"

#include <imgui.h>
#include <DirectXMath.h>

#include <algorithm>
#include <cmath>
#include <cstdio>

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

float NormalizeValue(float value, float maxValue)
{
    if (maxValue <= 0.0f)
        return 0.0f;
    return std::clamp(value / maxValue, 0.0f, 1.0f);
}

// Returns the pixel height of the target-info panel, derived from the current
// font size. Both DrawTargetInfo and DrawComboIndicator use this so the combo
// panel always sits flush above the target panel even if padding changes.
float CalcTargetPanelHeight()
{
    return kTargetPanelPadY + ImGui::GetFontSize() + kTargetBarGap + kTargetBarH + kTargetPanelPadY;
}

void DrawLowHpPulse(const ImGuiIO& io, float pulseTime)
{
    // Pulse brightness oscillates between 0 and kPulseMaxAlpha.
    float pulseRatio = 0.5f + 0.5f * sinf(pulseTime * kPulseFrequency * kTwoPi);
    int alpha = static_cast<int>(pulseRatio * static_cast<float>(kPulseMaxAlpha));
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
} // namespace

void GameHUD::Draw(const PlayerStats& stats, const ImGuiIO& io, float dt)
{
    m_lowHpPulseTime += (dt > 0.0f) ? dt : 0.0f;

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

    ImGui::End();

    // Draw screen-edge danger pulse when HP is critically low.
    if (isLowHp)
        DrawLowHpPulse(io, m_lowHpPulseTime);
}

void GameHUD::DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io)
{
    if (!target) return;

    // Calculate panel height from the current font size so it scales correctly.
    const float panelH = CalcTargetPanelHeight();
    const float fontH  = ImGui::GetFontSize();
    const float posX   = (io.DisplaySize.x - kTargetPanelW) * 0.5f;
    const float posY   = io.DisplaySize.y - panelH - kTargetMarginBottom;

    ImDrawList* dl = ImGui::GetForegroundDrawList();

    // Dark navy background — classic FF7R command-panel style.
    dl->AddRectFilled(ImVec2(posX, posY),
                      ImVec2(posX + kTargetPanelW, posY + panelH),
                      IM_COL32(6, 8, 24, 215), 3.0f);

    // Thin bright-blue accent line at the top of the panel.
    dl->AddRectFilled(ImVec2(posX, posY),
                      ImVec2(posX + kTargetPanelW, posY + 2.0f),
                      IM_COL32(70, 130, 240, 255));

    // Subtle border so the panel reads cleanly against the scene.
    dl->AddRect(ImVec2(posX, posY),
                ImVec2(posX + kTargetPanelW, posY + panelH),
                IM_COL32(50, 60, 100, 180), 3.0f);

    // --- Name row ---
    const float nameY = posY + kTargetPanelPadY;
    dl->AddText(ImVec2(posX + kTargetPanelPadX, nameY),
                IM_COL32(220, 220, 230, 255), target->name);

    // HP numbers right-aligned on the same row.
    char hpText[32];
    std::snprintf(hpText, sizeof(hpText), "%d / %d", target->hp, target->maxHp);
    const ImVec2 hpTextSize = ImGui::CalcTextSize(hpText);
    dl->AddText(ImVec2(posX + kTargetPanelW - kTargetPanelPadX - hpTextSize.x, nameY),
                IM_COL32(190, 195, 210, 255), hpText);

    // --- HP bar ---
    const float barX   = posX + kTargetPanelPadX;
    const float barY   = nameY + fontH + kTargetBarGap;
    const float barW   = kTargetPanelW - kTargetPanelPadX * 2.0f;
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
                      IM_COL32(28, 28, 48, 255), 2.0f);

    // Bar fill.
    if (filledW > 0.0f)
        dl->AddRectFilled(ImVec2(barX, barY),
                          ImVec2(barX + filledW, barY + kTargetBarH),
                          barColor, 2.0f);

    // Bar border.
    dl->AddRect(ImVec2(barX, barY),
                ImVec2(barX + barW, barY + kTargetBarH),
                IM_COL32(70, 75, 110, 200), 2.0f);
}

void GameHUD::DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io)
{
    // Only show while the combo window is open after the first hit.
    if (comboStep == 0 || comboTimer <= 0.0f) return;

    // Position the combo panel centred and sitting just above the target panel area.
    const float targetH = CalcTargetPanelHeight();
    const float posX    = (io.DisplaySize.x - kComboPanelW) * 0.5f;
    const float posY    = io.DisplaySize.y - targetH - kTargetMarginBottom - kComboGapAbove - kComboPanelH;

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
                      IM_COL32(6, 8, 24, bgAlpha), 3.0f);
    dl->AddRect(ImVec2(posX, posY),
                ImVec2(posX + kComboPanelW, posY + kComboPanelH),
                IM_COL32(50, 60, 100, bgAlpha), 3.0f);

    // Step squares — filled yellow for landed hit, open outline for next available input.
    const float squareY = posY + (kComboPanelH - kComboSquareSize) * 0.5f;
    const float sq1X    = posX + 10.0f;
    const float sq2X    = sq1X + kComboSquareSize + 6.0f;

    // Step 1 filled (already landed).
    dl->AddRectFilled(ImVec2(sq1X, squareY),
                      ImVec2(sq1X + kComboSquareSize, squareY + kComboSquareSize),
                      IM_COL32(255, 200, 40, fgAlpha), 2.0f);

    // Step 2 open outline (next hit available).
    dl->AddRect(ImVec2(sq2X, squareY),
                ImVec2(sq2X + kComboSquareSize, squareY + kComboSquareSize),
                IM_COL32(140, 140, 160, fgAlpha), 2.0f);

    // "COMBO" label to the right of the squares.
    const char* label     = "COMBO";
    const ImVec2 labelSz  = ImGui::CalcTextSize(label);
    dl->AddText(ImVec2(sq2X + kComboSquareSize + 8.0f,
                       posY + (kComboPanelH - labelSz.y) * 0.5f),
                IM_COL32(220, 180, 50, fgAlpha), label);
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
        target->x, target->y + 1.8f, target->z,
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
    drawList->AddCircleFilled(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(5, 10, 28, 220), 12);
    drawList->AddCircle(indicatorCenter, kOffscreenIndicatorRadius, IM_COL32(90, 155, 255, 220), 12, 1.4f);

    const float perpX = -dirY;
    const float perpY = dirX;
    const ImVec2 tip(indicatorX + dirX * kOffscreenArrowSize,
                     indicatorY + dirY * kOffscreenArrowSize);
    const ImVec2 left(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) + perpX * (kOffscreenArrowSize * 0.70f),
                      indicatorY - dirY * (kOffscreenArrowSize * 0.55f) + perpY * (kOffscreenArrowSize * 0.70f));
    const ImVec2 right(indicatorX - dirX * (kOffscreenArrowSize * 0.55f) - perpX * (kOffscreenArrowSize * 0.70f),
                       indicatorY - dirY * (kOffscreenArrowSize * 0.55f) - perpY * (kOffscreenArrowSize * 0.70f));
    drawList->AddTriangleFilled(tip, left, right, IM_COL32(200, 225, 255, 255));
}

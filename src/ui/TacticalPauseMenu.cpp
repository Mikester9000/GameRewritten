// TacticalPauseMenu.cpp
// Classic FF-style command panel shown while the player holds Tab.
// Time scale is applied by Main.cpp; this file only handles drawing.

#include "TacticalPauseMenu.hpp"

#include <imgui.h>

#include "../game/actors/PlayerStats.hpp"

namespace
{
// Panel dimensions and position.
constexpr float kPanelWidth  = 280.0f;
constexpr float kPanelHeight = 210.0f;

// Style — deep indigo/dark-blue panel matching Style Family B (classic RPG window).
constexpr ImVec4 kBackgroundColor (0.04f, 0.04f, 0.12f, 0.92f);
constexpr ImVec4 kTitleColor      (1.00f, 0.90f, 0.35f, 1.00f); // gold, matches DialogBox speaker
constexpr ImVec4 kReadyColor      (1.00f, 0.95f, 0.60f, 1.00f); // warm yellow — surge ready
constexpr ImVec4 kHintColor       (0.50f, 0.50f, 0.55f, 1.00f); // muted grey hint text

// UTF-8 encoding of the right-pointing triangle ▶ used in stub menu entries.
constexpr const char* kArrowSymbol  = "\xe2\x96\xb6";
constexpr const char* kMagicLabel   = "  Magic   \xe2\x96\xb6";
constexpr const char* kItemsLabel   = "  Items   \xe2\x96\xb6";
constexpr const char* kAllyLabel    = "  Ally    \xe2\x96\xb6";

// Width passed to Selectable so it fills the panel column.
constexpr float kSelectableWidth = -1.0f;
constexpr float kSelectableHeight = 28.0f;

// Draw one command row.
// label      — display text for the command (e.g. "Surge Strike").
// available  — when false the row is greyed out and non-interactive.
// suffix     — small annotation drawn to the right (e.g. "Surge not full", "Coming soon").
void DrawCommandRow(const char* label, bool available, const char* suffix)
{
    if (!available)
        ImGui::BeginDisabled();

    ImGui::Selectable(label, false, ImGuiSelectableFlags_None,
                      ImVec2(kSelectableWidth, kSelectableHeight));

    if (!available)
        ImGui::EndDisabled();

    if (suffix && suffix[0] != '\0')
    {
        ImGui::SameLine();
        ImGui::TextDisabled("%s", suffix);
    }
}
} // namespace

void TacticalPauseMenu::Draw(const PlayerStats& stats, const ImGuiIO& io)
{
    // --- Position: centred on screen ---
    const float posX = (io.DisplaySize.x - kPanelWidth)  * 0.5f;
    const float posY = (io.DisplaySize.y - kPanelHeight) * 0.5f;

    ImGui::SetNextWindowPos(ImVec2(posX, posY), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(kPanelWidth, kPanelHeight), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, kBackgroundColor);

    const ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoTitleBar           |
        ImGuiWindowFlags_NoResize             |
        ImGuiWindowFlags_NoMove               |
        ImGuiWindowFlags_NoCollapse           |
        ImGuiWindowFlags_NoScrollbar          |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    const bool opened = ImGui::Begin("##TacticalPause", nullptr, flags);
    // Always pop before early return so the colour stack stays balanced.
    ImGui::PopStyleColor();

    if (!opened)
    {
        ImGui::End();
        return;
    }

    // --- Title ---
    ImGui::TextColored(kTitleColor, "- TACTICAL PAUSE -");
    ImGui::Separator();
    ImGui::Spacing();

    // --- Surge Strike ---
    // Enabled only when the Surge gauge is full; otherwise greyed out.
    const bool surgeReady = stats.IsSurgeReady();
    const char* surgeSuffix = surgeReady ? nullptr : "(Surge not full)";
    DrawCommandRow("  Surge Strike", surgeReady, surgeSuffix);

    ImGui::Spacing();

    // --- Stub commands ---
    // Magic, Items, and Ally are reserved for later milestones.
    DrawCommandRow(kMagicLabel, false, "Coming soon");
    DrawCommandRow(kItemsLabel, false, "Coming soon");
    DrawCommandRow(kAllyLabel,  false, "Coming soon");

    // --- Footer hint ---
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::TextColored(kHintColor, "Release Tab to resume");

    ImGui::End();
}

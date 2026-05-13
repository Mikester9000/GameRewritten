// TacticalPauseMenu.cpp
// Classic FF-style command panel shown while the player holds Tab.
// Time scale is applied by Main.cpp; this file only handles drawing.

#include "TacticalPauseMenu.hpp"

#include <imgui.h>

#include "../game/actors/PlayerStats.hpp"

namespace
{
// Panel dimensions and position.
constexpr float kPanelWidth  = 300.0f;
constexpr float kPanelHeight = 215.0f;

// Hint column width (right side of the 2-column command table).
constexpr float kHintColumnWidth  = 115.0f;

// Style — deep indigo/dark-blue panel matching Style Family B (classic RPG window).
constexpr ImVec4 kBackgroundColor (0.04f, 0.04f, 0.12f, 0.92f);
constexpr ImVec4 kTitleColor      (1.00f, 0.90f, 0.35f, 1.00f); // gold, matches DialogBox speaker
constexpr ImVec4 kReadyColor      (1.00f, 0.95f, 0.60f, 1.00f); // warm yellow — tints surge-ready row
constexpr ImVec4 kHintColor       (0.50f, 0.50f, 0.55f, 1.00f); // muted grey hint text

// Labels for stub commands. ▶ (U+25B6) encoded as UTF-8 \xe2\x96\xb6.
constexpr const char* kMagicLabel = "  Magic   \xe2\x96\xb6";
constexpr const char* kItemsLabel = "  Items   \xe2\x96\xb6";
constexpr const char* kAllyLabel  = "  Ally    \xe2\x96\xb6";

constexpr float kSelectableHeight      = 28.0f;
// In ImGui, passing 0.0f as width to Selectable means "stretch to fill the current column".
constexpr float kSelectableStretchWidth = 0.0f;

// Draw one command row inside the active two-column table.
// Column 0: selectable label. Column 1: greyed hint text.
// Returns true if the row was activated (clicked or Enter pressed) this frame.
// available — when false the row is greyed out and non-interactive.
// suffix    — short annotation in the hint column (pass nullptr for none).
bool DrawCommandRow(const char* label, bool available, const char* suffix)
{
    ImGui::TableNextRow(ImGuiTableRowFlags_None, kSelectableHeight);
    ImGui::TableSetColumnIndex(0);

    if (!available)
        ImGui::BeginDisabled();

    const bool activated = ImGui::Selectable(label, false, ImGuiSelectableFlags_None,
                                             ImVec2(kSelectableStretchWidth, kSelectableHeight));

    if (!available)
        ImGui::EndDisabled();

    ImGui::TableSetColumnIndex(1);
    if (suffix && suffix[0] != '\0')
        ImGui::TextDisabled("%s", suffix);

    return activated;
}
} // namespace

TacticalCommand TacticalPauseMenu::Draw(const PlayerStats& stats, const ImGuiIO& io)
{
    TacticalCommand selectedCommand = TacticalCommand::None;

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
        return selectedCommand;
    }

    // --- Title ---
    ImGui::TextColored(kTitleColor, "- TACTICAL PAUSE -");
    ImGui::Separator();
    ImGui::Spacing();

    // --- Command table: two columns so label and hint never overlap ---
    // Column 0 stretches to fill available space; column 1 is fixed for hints.
    if (ImGui::BeginTable("##cmds", 2, ImGuiTableFlags_None))
    {
        ImGui::TableSetupColumn("##label", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("##hint",  ImGuiTableColumnFlags_WidthFixed, kHintColumnWidth);

        // Surge Strike — tinted warm yellow when ready to signal interactivity.
        const bool surgeReady = stats.IsSurgeReady();
        if (surgeReady)
            ImGui::PushStyleColor(ImGuiCol_Text, kReadyColor);

        if (DrawCommandRow("  Surge Strike", surgeReady, surgeReady ? nullptr : "Need Surge"))
            selectedCommand = TacticalCommand::SurgeStrike;

        if (surgeReady)
            ImGui::PopStyleColor();

        // Stub commands — reserved for later milestones.
        DrawCommandRow(kMagicLabel, false, "No MP");
        DrawCommandRow(kItemsLabel, false, "Coming soon");
        DrawCommandRow(kAllyLabel,  false, "Coming soon");

        ImGui::EndTable();
    }

    // --- Footer hint ---
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::TextColored(kHintColor, "Release Tab to resume");

    ImGui::End();
    return selectedCommand;
}

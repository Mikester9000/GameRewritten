#pragma once
// TacticalPauseMenu.hpp
// Draws the FF-style Tactical Pause command panel while Tab is held.
// Returns the command activated this frame so Main.cpp can execute it.

struct PlayerStats;
struct ImGuiIO;

// Commands that can be activated from the Tactical Pause panel.
// None means no command was chosen this frame.
enum class TacticalCommand { None, SurgeStrike };

class TacticalPauseMenu
{
public:
    // Draw the command panel for this frame. Returns the selected command (if any).
    // Call inside an active ImGui frame (between BeginFrame / EndFrame).
    // Only call while Tab is held — the caller controls open/close.
    TacticalCommand Draw(const PlayerStats& stats, const ImGuiIO& io);
};

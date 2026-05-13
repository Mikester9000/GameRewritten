#pragma once
// TacticalPauseMenu.hpp
// Draws the FF-style Tactical Pause command panel while Tab is held.
// Slows gameplay to 0.15x speed and presents four commands:
//   Surge Strike (active when Surge is full), Magic, Items, Ally (stubs).

struct PlayerStats;
struct ImGuiIO;

class TacticalPauseMenu
{
public:
    // Draw the command panel for this frame.
    // Call inside an active ImGui frame (between BeginFrame / EndFrame).
    // Only call while Tab is held — the caller controls open/close.
    void Draw(const PlayerStats& stats, const ImGuiIO& io);
};

// ============================================================
// FILE: src/ui/Minimap.hpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: Minimap module behavior and local implementation details.
// ============================================================

#pragma once
// Minimap.hpp
// Draws a 160x160 minimap overlay in the top-right corner using ImGui draw lists.
// Shows nearby world cells colored by biome, plus the player position and facing direction.

struct ImGuiIO;
class WorldGrid;

class Minimap
{
public:
    // Draw the minimap for this frame.
    // Call inside an active ImGui frame (between BeginFrame / EndFrame).
    // playerX, playerZ — world-space player position.
    // playerYaw        — player facing angle in radians (same convention as CameraController::GetYaw()).
    void Draw(const WorldGrid& grid,
              float playerX, float playerZ, float playerYaw,
              const ImGuiIO& io);
};

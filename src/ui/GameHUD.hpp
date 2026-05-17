// ============================================================
// FILE: src/ui/GameHUD.hpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: GameHUD module behavior and local implementation details.
// ============================================================

#pragma once

#include "../game/actors/PlayerStats.hpp"

class EnemyActor; // forward declaration — only pointer used in DrawTargetInfo
struct ImGuiIO;

class GameHUD
{
public:
    // Draw the player stats panel (HP / MP / Surge / Limit) at the bottom-left.
    void Draw(const PlayerStats& stats, const ImGuiIO& io, float dt);

    // Draw the locked-target info panel (name + HP bar) at the bottom-centre.
    // Pass nullptr when no enemy is locked on; the panel stays hidden.
    void DrawTargetInfo(const EnemyActor* target, const ImGuiIO& io);

    // Draw the active combo step indicator above the target panel.
    // Only visible while the combo window is open (comboTimer > 0).
    // comboWindowSec should be CombatSystem::kComboWindowSec — passed in to
    // avoid coupling GameHUD to the combat system header.
    void DrawComboIndicator(int comboStep, float comboTimer, float comboWindowSec, const ImGuiIO& io);

    // Draw a subtle edge indicator when the lock-on target is outside the screen.
    void DrawOffScreenTargetIndicator(const EnemyActor* target,
                                      float camX, float camY, float camZ,
                                      float yaw, float pitch,
                                      float vpW, float vpH) const;

private:
    float m_lowHpPulseTime = 0.0f;
};

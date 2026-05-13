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

private:
    float m_lowHpPulseTime = 0.0f;
};

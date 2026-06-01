// ============================================================
// FILE: src/ui/GameHUD.hpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: GameHUD module behavior and local implementation details.
// ============================================================

#pragma once

#include "../game/actors/PlayerStats.hpp"
#include <deque>
#include <string>

class EnemyActor; // forward declaration — only pointer used in DrawTargetInfo
struct ImGuiIO;

class GameHUD
{
public:
    void SetOpacity(float opacity);
    void SetUltrawideLayoutEnabled(bool enabled) { m_ultrawideLayoutEnabled = enabled; }
    void SetAreaName(const std::string& areaName);
    void SetContextPrompt(const std::string& prompt, bool visible);
    void SetStatusScreenOpen(bool open) { m_showStatusScreen = open; }
    void SetMapScreenOpen(bool open) { m_showMapScreen = open; }
    void TriggerLevelUpOverlay(int newLevel);

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

    // Trigger a brief red screen-edge flash when the player takes damage.
    // Call once per frame when a hit lands (e.g., from RuntimeScene::ConsumePlayerHitFlash()).
    void TriggerDamageFlash();

private:
    struct ToastEntry
    {
        std::string text;
        float life = 0.0f;
        float maxLife = 0.0f;
    };

    float m_lowHpPulseTime   = 0.0f;
    float m_damageFlashTimer = 0.0f;
    float m_opacity = 0.80f;
    bool m_ultrawideLayoutEnabled = false;
    std::string m_currentAreaName = "Unknown Area";
    float m_areaBannerTimer = 0.0f;
    std::deque<ToastEntry> m_toasts;
    std::string m_contextPrompt;
    bool m_contextPromptVisible = false;
    float m_levelUpOverlayTimer = 0.0f;
    int m_lastLevelUp = 0;
    bool m_showStatusScreen = false;
    bool m_showMapScreen = false;
};

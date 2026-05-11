#pragma once
// CombatSystem.hpp
// Manages active hitboxes, ticks their lifetime, and resolves hits against enemies.
// Player damage is ignored in this first pass. No knockback or animations yet.

#include "HitBox.hpp"
#include <vector>

class EnemyActor; // forward declare — full definition only needed in CombatSystem.cpp

class CombatSystem
{
public:
    // Combo state — 0 = no active combo, 1 = first hit landed (window open).
    int   comboStep  = 0;
    // Seconds remaining to chain the next combo hit.
    float comboTimer = 0.0f;

    // Add a new hitbox to the active pool. It will live for hitbox.framesToLive frames.
    void SpawnHitBox(const HitBox& hitbox);

    // Spawn a hitbox appropriate for the given combo step (1 or 2).
    // Positions the hitbox 1.5 units in front of the player using yaw.
    // Updates comboStep and comboTimer accordingly.
    void TriggerAttack(float px, float py, float pz, float yaw, int attackStep);

    // Decrement lifetime of all active hitboxes, test them against enemies,
    // apply damage, mark dead enemies, and remove expired hitboxes.
    // Also ticks the combo window timer.
    // Call once per frame from RuntimeScene::BeginFrame.
    void Update(float dt, EnemyActor* enemies, int count);

private:
    static constexpr float kComboWindowSec = 0.60f;

    std::vector<HitBox> m_activeHitBoxes;
};

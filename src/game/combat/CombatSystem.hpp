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
    struct EnemyHitRecord
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        int   damage = 0;
    };

    // Combo state — 0 = no active combo, 1 = step 1 triggered (window open).
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

    // Read-only access to active hitboxes for debug visualization.
    const std::vector<HitBox>& GetActiveHitBoxes() const
    { return m_activeHitBoxes; }

    // Recent hit records are valid for the current frame only.
    // They are reset at the start of each Update() call.
    // Always pair this pointer with GetRecentEnemyHitCount().
    const EnemyHitRecord* GetRecentEnemyHits() const
    { return m_recentEnemyHits; }

    int GetRecentEnemyHitCount() const
    { return m_recentEnemyHitCount; }

private:
    static constexpr float kComboWindowSec = 0.60f;
    static constexpr int   kMaxRecentEnemyHits = 32;

    std::vector<HitBox> m_activeHitBoxes;
    EnemyHitRecord m_recentEnemyHits[kMaxRecentEnemyHits]{};
    int m_recentEnemyHitCount = 0;
};

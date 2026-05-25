// ============================================================
// FILE: src/game/combat/CombatSystem.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: CombatSystem module behavior and local implementation details.
// ============================================================

#pragma once
// CombatSystem.hpp
// Manages active hitboxes, ticks their lifetime, and resolves hits against enemies.

#include "HitBox.hpp"
#include "PoiseSystem.hpp"
#include "StatusAilmentSystem.hpp"
#include "ElementalWeaknessBonus.hpp"
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

    // Combo window duration in seconds — exposed so callers can normalise the
    // timer without coupling to a magic number.
    static constexpr float kComboWindowSec = 0.60f;

    // Combo state — 0 = no active combo, 1 = step 1 triggered (window open).
    int   comboStep  = 0;
    // Seconds remaining to chain the next combo hit.
    float comboTimer = 0.0f;

    // Add a new hitbox to the active pool. It will live for hitbox.framesToLive frames.
    // If a counter-bonus multiplier was set via SetNextHitMultiplier(), it is applied
    // to the damage of this hitbox and then reset to 1.0.
    void SpawnHitBox(const HitBox& hitbox);

    // Set a one-shot damage multiplier applied to the very next hitbox spawned via
    // SpawnHitBox or TriggerAttack.  Resets to 1.0 after consumption.
    // Use from RuntimeScene when a parry counter is active.
    void SetNextHitMultiplier(float mult) { m_nextHitMultiplier = mult; }

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

    float GetEnemyPoiseRatio(int enemyIndex) const;
    bool IsEnemyBroken(int enemyIndex) const;
    bool IsEnemyAilmentActive(int enemyIndex) const;

private:
    static constexpr int   kMaxRecentEnemyHits = 32;
    static constexpr int   kMaxTrackedEnemies = 16;

    std::vector<HitBox> m_activeHitBoxes;
    EnemyHitRecord m_recentEnemyHits[kMaxRecentEnemyHits]{};
    int m_recentEnemyHitCount = 0;
    PoiseSystem m_enemyPoise[kMaxTrackedEnemies]{};
    StatusAilmentSystem m_enemyAilments[kMaxTrackedEnemies]{};
    ElementalWeaknessBonus m_weaknessBonus;
    bool m_trackedEnemiesInitialized = false;
    int m_trackedEnemyCount = 0;

    // One-shot multiplier for the next spawned hitbox damage (parry counter bonus).
    float m_nextHitMultiplier = 1.0f;
};

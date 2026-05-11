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
    // Add a new hitbox to the active pool. It will live for hitbox.framesToLive frames.
    void SpawnHitBox(const HitBox& hitbox);

    // Decrement lifetime of all active hitboxes, test them against enemies,
    // apply damage, mark dead enemies, and remove expired hitboxes.
    // Call once per frame from RuntimeScene::BeginFrame.
    void Update(EnemyActor* enemies, int count);

private:
    std::vector<HitBox> m_activeHitBoxes;
};

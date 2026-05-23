// ============================================================
// FILE: src/game/combat/CombatSystem.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: CombatSystem module behavior and local implementation details.
// ============================================================

// CombatSystem.cpp
// Implements hitbox lifetime ticking, AABB overlap testing against enemies,
// hp reduction, and death detection. Player damage is not handled here yet.

#include "CombatSystem.hpp"
#include "../actors/EnemyActor.hpp"
#include <logger/Logger.hpp>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>

// Half-extents used for the enemy body AABB when resolving hits.
// Matches the approximate size of the enemy blockout prefab.
static constexpr float ENEMY_HALF_X = 0.5f;
static constexpr float ENEMY_HALF_Y = 1.0f;
static constexpr float ENEMY_HALF_Z = 0.5f;
static constexpr float DAMAGE_NUMBER_Y_OFFSET = 2.2f; // spawn above enemy head

static bool HitBoxOverlapsEnemy(const HitBox& hitBox, const EnemyActor& enemy)
{
    float distX = fabsf(enemy.x - hitBox.x);
    float distY = fabsf(enemy.y - hitBox.y);
    float distZ = fabsf(enemy.z - hitBox.z);
    return (distX < hitBox.halfX + ENEMY_HALF_X) &&
           (distY < hitBox.halfY + ENEMY_HALF_Y) &&
           (distZ < hitBox.halfZ + ENEMY_HALF_Z);
}

void CombatSystem::SpawnHitBox(const HitBox& hitbox)
{
    m_activeHitBoxes.push_back(hitbox);
}

void CombatSystem::TriggerAttack(float px, float py, float pz, float yaw, int attackStep)
{
    if (attackStep < 1 || attackStep > 4)
    {
        LOG_WARN("CombatSystem: TriggerAttack called with unsupported attackStep " + std::to_string(attackStep) + " — ignored.");
        return;
    }

    HitBox hitBox;
    hitBox.halfY = 1.0f;

    if (attackStep == 1)
    {
        // Light combo opener — small hitbox, 1.5 units forward.
        hitBox.x = px + 1.5f * sinf(yaw);
        hitBox.z = pz + 1.5f * cosf(yaw);
        hitBox.halfX = 0.75f;
        hitBox.halfZ = 0.75f;
        hitBox.damage = 3;
        hitBox.framesToLive = 2;
        comboStep  = 1;
        comboTimer = kComboWindowSec;
        LOG_INFO("CombatSystem: Combo step 1 triggered.");
    }
    else if (attackStep == 2)
    {
        // Heavy combo finisher — wider hitbox, 1.5 units forward.
        hitBox.x = px + 1.5f * sinf(yaw);
        hitBox.z = pz + 1.5f * cosf(yaw);
        hitBox.halfX = 0.90f;
        hitBox.halfZ = 0.90f;
        hitBox.damage = 5;
        hitBox.framesToLive = 2;
        comboStep  = 0;
        comboTimer = 0.0f;
        LOG_INFO("CombatSystem: Combo step 2 triggered — combo complete.");
    }
    else if (attackStep == 3)
    {
        // Surge Strike — larger hitbox, 2.0 units forward, resets combo.
        hitBox.x = px + 2.0f * sinf(yaw);
        hitBox.z = pz + 2.0f * cosf(yaw);
        hitBox.halfX = 1.0f;
        hitBox.halfZ = 1.0f;
        hitBox.damage = 15;
        hitBox.framesToLive = 3;
        comboStep  = 0;
        comboTimer = 0.0f;
        LOG_INFO("CombatSystem: Surge Strike triggered.");
    }
    else if (attackStep == 4)
    {
        // Limit Break — biggest hitbox, 2.5 units forward, resets combo.
        hitBox.x = px + 2.5f * sinf(yaw);
        hitBox.z = pz + 2.5f * cosf(yaw);
        hitBox.halfX = 1.2f;
        hitBox.halfZ = 1.2f;
        hitBox.damage = 25;
        hitBox.framesToLive = 4;
        comboStep  = 0;
        comboTimer = 0.0f;
        LOG_INFO("CombatSystem: Limit Break triggered.");
    }

    hitBox.y = py;
    SpawnHitBox(hitBox);
}

void CombatSystem::Update(float dt, EnemyActor* enemies, int count)
{
    m_recentEnemyHitCount = 0;

    // Tick combo window timer.
    if (comboTimer > 0.0f)
    {
        comboTimer -= dt;
        if (comboTimer <= 0.0f)
        {
            comboTimer = 0.0f;
            comboStep  = 0;
            LOG_INFO("CombatSystem: Combo window expired.");
        }
    }

    for (HitBox& hitBox : m_activeHitBoxes)
    {
        --hitBox.framesToLive;

        // Skip damage for expired hitboxes (guards against zero/negative framesToLive at spawn).
        if (hitBox.framesToLive <= 0)
            continue;

        for (int i = 0; i < count; ++i)
        {
            EnemyActor& enemy = enemies[i];
            if (enemy.isDead)
                continue;
            if (!HitBoxOverlapsEnemy(hitBox, enemy))
                continue;

            // Apply stagger bonus damage multiplier when the enemy is staggered.
            int actualDamage = hitBox.damage;
            if (enemy.IsStaggered())
                actualDamage = static_cast<int>(actualDamage * EnemyActor::kStaggerBonusMult + 0.5f);

            std::ostringstream ss;
            ss << "CombatSystem: Hit enemy " << i
               << " for " << actualDamage << " damage"
               << (enemy.IsStaggered() ? " (STAGGER BONUS)" : "") << ".";
            LOG_INFO(ss.str());

            enemy.OnHit(actualDamage);

            if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
            {
                EnemyHitRecord& hitRecord = m_recentEnemyHits[m_recentEnemyHitCount++];
                hitRecord.x = enemy.x;
                hitRecord.y = enemy.y + DAMAGE_NUMBER_Y_OFFSET;
                hitRecord.z = enemy.z;
                hitRecord.damage = actualDamage;
            }
        }
    }

    // Remove any hitboxes whose lifetime has run out.
    m_activeHitBoxes.erase(
        std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
                       [](const HitBox& hitBox) { return hitBox.framesToLive <= 0; }),
        m_activeHitBoxes.end());
}

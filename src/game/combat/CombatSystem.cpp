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

static bool HitBoxOverlapsEnemy(const HitBox& hb, const EnemyActor& enemy)
{
    float dx = fabsf(enemy.x - hb.x);
    float dy = fabsf(enemy.y - hb.y);
    float dz = fabsf(enemy.z - hb.z);
    return (dx < hb.halfX + ENEMY_HALF_X) &&
           (dy < hb.halfY + ENEMY_HALF_Y) &&
           (dz < hb.halfZ + ENEMY_HALF_Z);
}

void CombatSystem::SpawnHitBox(const HitBox& hitbox)
{
    m_activeHitBoxes.push_back(hitbox);
}

void CombatSystem::Update(EnemyActor* enemies, int count)
{
    for (HitBox& hb : m_activeHitBoxes)
    {
        --hb.framesToLive;

        // Skip damage for expired hitboxes (guards against zero/negative framesToLive at spawn).
        if (hb.framesToLive <= 0)
            continue;

        for (int i = 0; i < count; ++i)
        {
            EnemyActor& enemy = enemies[i];
            if (enemy.isDead)
                continue;
            if (!HitBoxOverlapsEnemy(hb, enemy))
                continue;

            enemy.hp -= hb.damage;

            std::ostringstream ss;
            ss << "CombatSystem: Hit enemy " << i
               << " for " << hb.damage
               << " damage. HP remaining: " << enemy.hp;
            LOG_INFO(ss.str());

            if (enemy.hp <= 0)
            {
                enemy.isDead = true;
                LOG_INFO("CombatSystem: Enemy " + std::to_string(i) + " defeated.");
            }
        }
    }

    // Remove any hitboxes whose lifetime has run out.
    m_activeHitBoxes.erase(
        std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
                       [](const HitBox& hb) { return hb.framesToLive <= 0; }),
        m_activeHitBoxes.end());
}

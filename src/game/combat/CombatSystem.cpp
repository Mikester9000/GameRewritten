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
static constexpr float DAMAGE_NUMBER_Y_OFFSET = 5.2f; // spawn above enemy head

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

void CombatSystem::TriggerAttack(float px, float py, float pz, float yaw, int attackStep)
{
    if (attackStep != 1 && attackStep != 2)
    {
        LOG_WARN("CombatSystem: TriggerAttack called with unsupported attackStep " + std::to_string(attackStep) + " — ignored.");
        return;
    }

    HitBox hb;
    hb.x = px + 1.5f * sinf(yaw);
    hb.y = py;
    hb.z = pz + 1.5f * cosf(yaw);
    hb.halfY       = 1.0f;
    hb.framesToLive = 2;

    if (attackStep == 1)
    {
        hb.halfX   = 0.75f;
        hb.halfZ   = 0.75f;
        hb.damage  = 3;
        comboStep  = 1;
        comboTimer = kComboWindowSec;
        LOG_INFO("CombatSystem: Combo step 1 triggered.");
    }
    else if (attackStep == 2)
    {
        hb.halfX   = 0.90f;
        hb.halfZ   = 0.90f;
        hb.damage  = 5;
        comboStep  = 0;
        comboTimer = 0.0f;
        LOG_INFO("CombatSystem: Combo step 2 triggered — combo complete.");
    }

    SpawnHitBox(hb);
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

            std::ostringstream ss;
            ss << "CombatSystem: Hit enemy " << i
               << " for " << hb.damage << " damage.";
            LOG_INFO(ss.str());

            enemy.OnHit(hb.damage);

            if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
            {
                EnemyHitRecord& hit = m_recentEnemyHits[m_recentEnemyHitCount++];
                hit.x = enemy.x;
                hit.y = enemy.y + DAMAGE_NUMBER_Y_OFFSET;
                hit.z = enemy.z;
                hit.damage = hb.damage;
            }
        }
    }

    // Remove any hitboxes whose lifetime has run out.
    m_activeHitBoxes.erase(
        std::remove_if(m_activeHitBoxes.begin(), m_activeHitBoxes.end(),
                       [](const HitBox& hb) { return hb.framesToLive <= 0; }),
        m_activeHitBoxes.end());
}

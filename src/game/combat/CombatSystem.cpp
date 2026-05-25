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
static constexpr float kWeakPointDotThreshold = 0.5f;
static constexpr float kWeakPointDamageMult   = 1.5f;

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
    HitBox h = hitbox;
    if (m_nextHitMultiplier != 1.0f)
    {
        h.damage = static_cast<int>(h.damage * m_nextHitMultiplier + 0.5f);
        m_nextHitMultiplier = 1.0f;
    }
    m_activeHitBoxes.push_back(h);
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
        hitBox.attackElement = Element::Physical;
        hitBox.statusAilment = HitBox::HitAilment::Poison;
        hitBox.statusBuildUp = 0.35f;
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
        hitBox.attackElement = Element::Fire;
        hitBox.statusAilment = HitBox::HitAilment::Burn;
        hitBox.statusBuildUp = 0.60f;
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
        hitBox.attackElement = Element::Lightning;
        hitBox.statusAilment = HitBox::HitAilment::Shock;
        hitBox.statusBuildUp = 0.90f;
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
        hitBox.attackElement = Element::Ice;
        hitBox.statusAilment = HitBox::HitAilment::Burn;
        hitBox.statusBuildUp = 1.15f;
        comboStep  = 0;
        comboTimer = 0.0f;
        LOG_INFO("CombatSystem: Limit Break triggered.");
    }

    hitBox.y = py;
    hitBox.attackerYaw = yaw;
    SpawnHitBox(hitBox);
}

void CombatSystem::Update(float dt, EnemyActor* enemies, int count)
{
    m_recentEnemyHitCount = 0;
    if (!enemies || count <= 0)
        return;

    const int trackedCount = (count < kMaxTrackedEnemies) ? count : kMaxTrackedEnemies;
    if (!m_trackedEnemiesInitialized || m_trackedEnemyCount != trackedCount)
    {
        for (int i = 0; i < trackedCount; ++i)
            m_enemyPoise[i].Reset(100.0f);
        m_trackedEnemiesInitialized = true;
        m_trackedEnemyCount = trackedCount;
    }

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

    // Tick secondary combat systems.
    for (int i = 0; i < trackedCount; ++i)
    {
        m_enemyPoise[i].Update(dt);
        m_enemyAilments[i].Update(dt);
        if (m_enemyAilments[i].IsActive())
        {
            const int dotDamage = m_enemyAilments[i].ConsumeTickDamage();
            if (dotDamage > 0 && !enemies[i].isDead)
            {
                enemies[i].OnHit(dotDamage);
                if (m_recentEnemyHitCount < kMaxRecentEnemyHits)
                {
                    EnemyHitRecord& hitRecord = m_recentEnemyHits[m_recentEnemyHitCount++];
                    hitRecord.x = enemies[i].x;
                    hitRecord.y = enemies[i].y + DAMAGE_NUMBER_Y_OFFSET;
                    hitRecord.z = enemies[i].z;
                    hitRecord.damage = dotDamage;
                }
            }
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
            if (hitBox.hitEnemyMask & (1u << i))
                continue;
            if (!HitBoxOverlapsEnemy(hitBox, enemy))
                continue;

            const ElementResolveResult elementResolved =
                ResolveElementalDamage(hitBox.damage, hitBox.attackElement, enemy.elementProfile);

            // Apply stagger bonus damage multiplier when the enemy is staggered.
            int actualDamage = hitBox.damage;
            actualDamage = elementResolved.damage;
            if (enemy.IsStaggered())
                actualDamage = static_cast<int>(actualDamage * EnemyActor::kStaggerBonusMult + 0.5f);
            const float dotProduct = cosf(hitBox.attackerYaw - enemy.yaw);
            const bool isWeakPoint = (dotProduct > kWeakPointDotThreshold);
            if (isWeakPoint)
                actualDamage = static_cast<int>(actualDamage * kWeakPointDamageMult + 0.5f);
            actualDamage = m_weaknessBonus.ApplyBonus(actualDamage, elementResolved.isWeakness, isWeakPoint);

            if (i < trackedCount && m_enemyPoise[i].IsBroken())
                actualDamage = static_cast<int>(actualDamage * m_enemyPoise[i].GetBreakDamageMultiplier() + 0.5f);

            std::ostringstream ss;
            ss << "CombatSystem: Hit enemy " << i
               << " for " << actualDamage << " damage"
               << (enemy.IsStaggered() ? " (STAGGER BONUS)" : "")
               << (isWeakPoint ? " (WEAK POINT)" : "")
               << (elementResolved.isWeakness ? " (WEAKNESS)" : "")
               << (elementResolved.isResistance ? " (RESIST)" : "")
               << ((i < trackedCount && m_enemyPoise[i].IsBroken()) ? " (BREAK BONUS)" : "")
               << ".";
            LOG_INFO(ss.str());

            enemy.OnHit(actualDamage);
            hitBox.hitEnemyMask |= (1u << i);

            if (i < trackedCount)
            {
                const bool broke = m_enemyPoise[i].ApplyPoiseDamage(static_cast<float>(actualDamage) * 4.0f);
                if (broke)
                    LOG_INFO("CombatSystem: Guard break / poise break triggered.");
                m_enemyAilments[i].TryApply(hitBox.statusAilment, hitBox.statusBuildUp);
            }

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

float CombatSystem::GetEnemyPoiseRatio(int enemyIndex) const
{
    if (enemyIndex < 0 || enemyIndex >= m_trackedEnemyCount)
        return 1.0f;
    return m_enemyPoise[enemyIndex].GetPoiseRatio();
}

bool CombatSystem::IsEnemyBroken(int enemyIndex) const
{
    if (enemyIndex < 0 || enemyIndex >= m_trackedEnemyCount)
        return false;
    return m_enemyPoise[enemyIndex].IsBroken();
}

bool CombatSystem::IsEnemyAilmentActive(int enemyIndex) const
{
    if (enemyIndex < 0 || enemyIndex >= m_trackedEnemyCount)
        return false;
    return m_enemyAilments[enemyIndex].IsActive();
}

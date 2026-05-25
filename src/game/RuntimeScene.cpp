// ============================================================
// FILE: src/game/RuntimeScene.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: RuntimeScene module behavior and local implementation details.
// ============================================================

// RuntimeScene.cpp
// BeginFrame implementation for RuntimeScene.

#define NOMINMAX
#include "RuntimeScene.hpp"
#include <windows.h>

#include <string>

void RuntimeScene::BeginFrame(float dt, D3D11Renderer& renderer,
                               float playerX, float playerY, float playerZ)
{
    // Reset per-frame flags before any combat logic runs.
    m_playerWasHitThisFrame  = false;
    m_enemyDiedThisFrame     = false;
    m_enemyAlertedThisFrame  = false;
    m_lockOnChangedThisFrame = false;
    m_parryThisFrame         = false;

    // Cache the up-to-date player position for enemy AI and AABB checks.
    m_playerX = playerX;
    m_playerY = playerY;
    m_playerZ = playerZ;

    m_primRenderer.ClearRuntimeInstances();

    // Snapshot enemy states before update so we can detect transitions.
    EnemyState prevStates[kEnemyCount];
    bool        prevAlive[kEnemyCount];
    for (int i = 0; i < kEnemyCount; ++i)
    {
        prevStates[i] = m_enemies[i].state;
        prevAlive[i]  = (m_enemies[i].hp > 0);
    }

    for (EnemyActor& enemy : m_enemies)
        enemy.Update(dt, renderer, m_playerX, m_playerZ);

    // Detect enemy deaths and alert transitions after the update.
    for (int i = 0; i < kEnemyCount; ++i)
    {
        const bool nowAlive = (m_enemies[i].hp > 0);
        if (prevAlive[i] && !nowAlive)
            m_enemyDiedThisFrame = true;

        // Idle → Chase means the enemy just spotted the player.
        if (prevStates[i] == EnemyState::Idle && m_enemies[i].state == EnemyState::Chase)
            m_enemyAlertedThisFrame = true;
    }

    // Snapshot lock-on target before refresh.
    const EnemyActor* prevTarget = m_targeting.GetTarget();

    m_combatSystem.Update(dt, m_enemies, kEnemyCount);
    m_limitBreakCamera.Update(dt);
    m_targeting.RefreshLock(m_playerX, m_playerZ);

    // Detect lock-on target changes.
    const EnemyActor* newTarget = m_targeting.GetTarget();
    if (prevTarget != newTarget)
    {
        m_lockOnChangedThisFrame = true;
        m_lockOnHasTarget        = (newTarget != nullptr);
    }

    // Fill Surge from hits landed this frame and spawn floating damage numbers.
    // Heavy hits (damage >= 5, i.e. combo step 2 or Surge Strike level) reward more Surge
    // than light jabs so skilled play builds the bar faster.
    const CombatSystem::EnemyHitRecord* hitRecords = m_combatSystem.GetRecentEnemyHits();
    int hitCount = m_combatSystem.GetRecentEnemyHitCount();
    float hitStopSec = 0.0f;
    float shakeAmplitude = 0.0f;
    float shakeDuration = 0.0f;
    for (int i = 0; i < hitCount; ++i)
    {
        const float surgeGain = (hitRecords[i].damage >= 5) ? 0.40f : 0.30f;
        m_player.stats.AddSurge(surgeGain);
        damageNumbers.Spawn(hitRecords[i].damage, hitRecords[i].x, hitRecords[i].y, hitRecords[i].z);

        if (hitRecords[i].damage >= 15)
        {
            hitStopSec = 0.065f;
            shakeAmplitude = 0.22f;
            shakeDuration = 0.18f;
        }
        else if (hitRecords[i].damage >= 5)
        {
            hitStopSec = std::max(hitStopSec, 0.050f);
            shakeAmplitude = std::max(shakeAmplitude, 0.16f);
            shakeDuration = std::max(shakeDuration, 0.15f);
        }
        else
        {
            hitStopSec = std::max(hitStopSec, 0.035f);
            shakeAmplitude = std::max(shakeAmplitude, 0.10f);
            shakeDuration = std::max(shakeDuration, 0.11f);
        }
    }

    if (hitStopSec > 0.0f)
        QueueImpactFeedback(hitStopSec, shakeAmplitude, shakeDuration);

    // Check for enemy attack hitboxes spawned this frame.
    // Test each hitbox against the player AABB before accumulating damage.
    for (EnemyActor& enemy : m_enemies)
    {
        if (!enemy.pendingAttack)
            continue;

        HitBox& hitBox = enemy.pendingAttackHitBox;
        if (hitBox.framesToLive <= 0)
        {
            hitBox.x = enemy.x;
            hitBox.y = enemy.y + 1.0f;
            hitBox.z = enemy.z;
            hitBox.halfX = kEnemyAttackHalfX;
            hitBox.halfY = kEnemyAttackHalfY;
            hitBox.halfZ = kEnemyAttackHalfZ;
            hitBox.damage = kEnemyAttackDamage;
            hitBox.framesToLive = 2;
            hitBox.hasHitPlayer = false;
        }

        if (!hitBox.hasHitPlayer && HitBoxOverlapsPlayer(hitBox))
        {
            if (m_player.IsParryActive())
            {
                // Early-dodge parry: absorb the hit and grant the player a counter bonus.
                m_player.counterBonusActive = true;
                hitBox.hasHitPlayer = true;
                m_parryThisFrame = true;
                LOG_INFO("RuntimeScene: Player PARRIED enemy attack — counter bonus ready.");
            }
            else if (m_player.IsInvulnerable())
            {
                hitBox.hasHitPlayer = true;
                if (m_player.ConsumePerfectDodgeTriggered())
                {
                    QueueImpactFeedback(0.030f, 0.08f, 0.10f);
                    m_player.counterBonusActive = true;
                    LOG_INFO("RuntimeScene: Perfect dodge triggered.");
                }
            }
            else
            {
                m_pendingEnemyDamage += hitBox.damage;
                hitBox.hasHitPlayer = true;
            }
        }

        --hitBox.framesToLive;
        if (hitBox.framesToLive <= 0 || hitBox.hasHitPlayer)
            enemy.pendingAttack = false;
    }

    // Apply accumulated enemy damage to the player.
    int totalDamage = m_pendingEnemyDamage;
    m_pendingEnemyDamage = 0;

    if (totalDamage > 0 &&
        m_player.state != PlayerActionState::Dead &&
        !m_player.IsInvulnerable())
    {
        m_playerWasHitThisFrame = true;
        QueueImpactFeedback(0.045f, 0.18f, 0.16f);
        m_player.stats.TakeDamage(totalDamage);

        if (m_player.stats.IsDead())
        {
            // Restore all stats and signal Main.cpp to teleport the camera.
            m_player.stats.Reset();
            m_player.state      = PlayerActionState::Idle;
            m_player.stateTimer = 0.0f;
            m_wantsRespawn      = true;
            LOG_INFO("RuntimeScene: Player defeated — respawning.");
        }
        else
        {
            m_player.state      = PlayerActionState::Stunned;
            m_player.stateTimer = 0.30f;
            std::string msg = "RuntimeScene: Player hit for ";
            msg += std::to_string(totalDamage);
            msg += " damage (HP ";
            msg += std::to_string(static_cast<int>(m_player.stats.hp));
            msg += " / ";
            msg += std::to_string(static_cast<int>(m_player.stats.maxHp));
            msg += ").";
            LOG_INFO(msg);
        }
    }

    // Consume buffered combo input as soon as attack state is cancel-ready.
    if (m_comboSystem.ConsumeBufferedAttack())
    {
        if (m_combatSystem.comboStep == 1 && m_combatSystem.comboTimer > 0.0f &&
            m_player.state == PlayerActionState::Attack1 && m_player.stateTimer <= 0.16f)
        {
            float yaw = 0.0f;
            if (const EnemyActor* lockedTarget = m_targeting.GetTarget())
            {
                const float dx = lockedTarget->x - m_playerX;
                const float dz = lockedTarget->z - m_playerZ;
                yaw = atan2f(dx, dz);
            }
            m_combatSystem.TriggerAttack(m_playerX, m_playerY - 0.5f, m_playerZ, yaw, 2);
            m_player.state = PlayerActionState::Attack2;
            m_player.stateTimer = 0.40f;
        }
    }

    if (m_limitBreakCamera.IsActive())
        QueueImpactFeedback(0.0f, m_limitBreakCamera.GetSuggestedShakeAmplitude(), 0.08f);
}

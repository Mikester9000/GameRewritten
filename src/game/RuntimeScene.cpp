// RuntimeScene.cpp
// BeginFrame implementation for RuntimeScene.

#include "RuntimeScene.hpp"

#include <string>

void RuntimeScene::BeginFrame(float dt, D3D11Renderer& renderer,
                               float playerX, float playerY, float playerZ)
{
    // Cache the up-to-date player position for enemy AI and AABB checks.
    m_playerX = playerX;
    m_playerY = playerY;
    m_playerZ = playerZ;

    m_primRenderer.ClearRuntimeInstances();

    for (EnemyActor& enemy : m_enemies)
        enemy.Update(dt, renderer, m_playerX, m_playerZ);

    m_combatSystem.Update(dt, m_enemies, kEnemyCount);

    // Spawn floating damage numbers for player hits on enemies this frame.
    const CombatSystem::EnemyHitRecord* hitRecords = m_combatSystem.GetRecentEnemyHits();
    int hitCount = m_combatSystem.GetRecentEnemyHitCount();
    for (int i = 0; i < hitCount; ++i)
        damageNumbers.Spawn(hitRecords[i].damage, hitRecords[i].x, hitRecords[i].y, hitRecords[i].z);

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
            m_pendingEnemyDamage += hitBox.damage;
            hitBox.hasHitPlayer = true;
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
        m_player.state != PlayerActionState::Dodge) // dodge grants invincibility
    {
        m_player.stats.TakeDamage(totalDamage);

        if (m_player.stats.IsDead())
        {
            // Restore stats and signal Main.cpp to teleport the camera.
            m_player.stats.hp        = m_player.stats.maxHp;
            m_player.stats.mp        = m_player.stats.maxMp;
            m_player.stats.surgeCharge = 0.0f;
            m_player.state           = PlayerActionState::Idle;
            m_player.stateTimer      = 0.0f;
            m_wantsRespawn           = true;
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
}

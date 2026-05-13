// RuntimeScene.cpp
// BeginFrame implementation for RuntimeScene.
// Separated from RuntimeScene.hpp to avoid pulling UI headers (DamageNumbers)
// into every translation unit that includes RuntimeScene.hpp.

#include "RuntimeScene.hpp"

#include "../ui/DamageNumbers.hpp"

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
    if (m_damageNumbers)
    {
        const CombatSystem::EnemyHitRecord* hits = m_combatSystem.GetRecentEnemyHits();
        int hitCount = m_combatSystem.GetRecentEnemyHitCount();
        for (int i = 0; i < hitCount; ++i)
            m_damageNumbers->Spawn(hits[i].damage, hits[i].x, hits[i].y, hits[i].z);
    }

    // Check for enemy attack hitboxes spawned this frame.
    // Test each hitbox against the player AABB before accumulating damage.
    for (EnemyActor& enemy : m_enemies)
    {
        if (!enemy.pendingAttack)
            continue;

        enemy.pendingAttack = false;

        HitBox hb;
        hb.x      = enemy.x;
        hb.y      = enemy.y + 1.0f;
        hb.z      = enemy.z;
        hb.halfX  = kEnemyAttackHalfX;
        hb.halfY  = kEnemyAttackHalfY;
        hb.halfZ  = kEnemyAttackHalfZ;
        hb.damage = kEnemyAttackDamage;
        // framesToLive not set — this hitbox is tested immediately and discarded.

        if (HitBoxOverlapsPlayer(hb))
            m_pendingEnemyDamage += hb.damage;
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
            m_player.stats.atbCharge = 0.0f;
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

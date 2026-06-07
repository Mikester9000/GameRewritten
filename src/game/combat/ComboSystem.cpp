#include "ComboSystem.hpp"

void ComboSystem::Update(float dt)
{
    if (!m_bufferedAttack)
        return;

    m_bufferTimer -= dt;
    if (m_bufferTimer <= 0.0f)
    {
        m_bufferedAttack = false;
        m_bufferTimer = 0.0f;
    }
}

void ComboSystem::BufferAttackInput()
{
    m_bufferedAttack = true;
    m_bufferTimer = kInputBufferWindowSec;
}

bool ComboSystem::ConsumeBufferedAttack()
{
    if (!m_bufferedAttack)
        return false;

    m_bufferedAttack = false;
    m_bufferTimer = 0.0f;
    return true;
}

bool ComboSystem::CanCancelFromState(PlayerActionState state, float stateTimer) const
{
    if (state == PlayerActionState::Attack1 || state == PlayerActionState::Attack2)
        return stateTimer <= 0.16f;
    return false;
}

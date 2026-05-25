#pragma once

#include "../actors/PlayerActionState.hpp"

class ComboSystem
{
public:
    void Update(float dt);
    void BufferAttackInput();
    bool ConsumeBufferedAttack();

    bool CanCancelFromState(PlayerActionState state, float stateTimer) const;

private:
    bool m_bufferedAttack = false;
    float m_bufferTimer = 0.0f;
    static constexpr float kInputBufferWindowSec = 0.20f;
};

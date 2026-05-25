#pragma once

#include <algorithm>
#include "HitBox.hpp"

class StatusAilmentSystem
{
public:
    void Update(float dt);
    bool TryApply(HitBox::HitAilment ailment, float buildup);

    bool IsActive() const { return m_activeAilment != HitBox::HitAilment::None && m_activeTimer > 0.0f; }
    HitBox::HitAilment GetActiveAilment() const { return m_activeAilment; }
    float GetImmunityTimer() const { return m_immunityTimer; }
    int ConsumeTickDamage();

private:
    void Activate(HitBox::HitAilment ailment);

    HitBox::HitAilment m_activeAilment = HitBox::HitAilment::None;
    float m_activeTimer = 0.0f;
    float m_tickTimer = 0.0f;
    float m_immunityTimer = 0.0f;
    float m_buildupPoison = 0.0f;
    float m_buildupBurn = 0.0f;
    float m_buildupShock = 0.0f;
    int m_pendingTickDamage = 0;
};

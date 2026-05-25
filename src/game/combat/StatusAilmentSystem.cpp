#include "StatusAilmentSystem.hpp"

namespace
{
constexpr float kThresholdPoison = 1.0f;
constexpr float kThresholdBurn = 1.0f;
constexpr float kThresholdShock = 1.0f;
constexpr float kImmunityWindowSec = 2.0f;
}

void StatusAilmentSystem::Update(float dt)
{
    if (m_immunityTimer > 0.0f)
    {
        m_immunityTimer -= dt;
        if (m_immunityTimer < 0.0f)
            m_immunityTimer = 0.0f;
    }

    if (!IsActive())
        return;

    m_activeTimer -= dt;
    m_tickTimer += dt;

    float tickPeriod = 1.0f;
    int tickDamage = 0;
    if (m_activeAilment == HitBox::HitAilment::Poison)
    {
        tickPeriod = 1.0f;
        tickDamage = 1;
    }
    else if (m_activeAilment == HitBox::HitAilment::Burn)
    {
        tickPeriod = 0.6f;
        tickDamage = 2;
    }

    while (tickDamage > 0 && m_tickTimer >= tickPeriod)
    {
        m_tickTimer -= tickPeriod;
        m_pendingTickDamage += tickDamage;
    }

    if (m_activeTimer <= 0.0f)
    {
        m_activeAilment = HitBox::HitAilment::None;
        m_activeTimer = 0.0f;
        m_tickTimer = 0.0f;
        m_immunityTimer = kImmunityWindowSec;
        m_buildupPoison = 0.0f;
        m_buildupBurn = 0.0f;
        m_buildupShock = 0.0f;
    }
}

bool StatusAilmentSystem::TryApply(HitBox::HitAilment ailment, float buildup)
{
    if (ailment == HitBox::HitAilment::None || buildup <= 0.0f)
        return false;

    if (m_immunityTimer > 0.0f)
        return false;

    if (IsActive())
        return false;

    if (ailment == HitBox::HitAilment::Poison)
    {
        m_buildupPoison += buildup;
        if (m_buildupPoison >= kThresholdPoison)
        {
            Activate(ailment);
            return true;
        }
    }
    else if (ailment == HitBox::HitAilment::Burn)
    {
        m_buildupBurn += buildup;
        if (m_buildupBurn >= kThresholdBurn)
        {
            Activate(ailment);
            return true;
        }
    }
    else if (ailment == HitBox::HitAilment::Shock)
    {
        m_buildupShock += buildup;
        if (m_buildupShock >= kThresholdShock)
        {
            Activate(ailment);
            return true;
        }
    }

    return false;
}

int StatusAilmentSystem::ConsumeTickDamage()
{
    const int damage = m_pendingTickDamage;
    m_pendingTickDamage = 0;
    return damage;
}

void StatusAilmentSystem::Activate(HitBox::HitAilment ailment)
{
    m_activeAilment = ailment;
    m_tickTimer = 0.0f;

    switch (ailment)
    {
    case HitBox::HitAilment::Poison: m_activeTimer = 6.0f; break;
    case HitBox::HitAilment::Burn:   m_activeTimer = 4.0f; break;
    case HitBox::HitAilment::Shock:  m_activeTimer = 2.5f; break;
    case HitBox::HitAilment::None:
    default:                 m_activeTimer = 0.0f; break;
    }
}

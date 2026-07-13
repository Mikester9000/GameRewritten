// TraversalMount.cpp
// Mount movement override — overrides WASD speed while mounted.

#include "TraversalMount.hpp"

#include <cmath>

bool TraversalMount::Mount(const MountDef& def)
{
    if (m_mounted) return false;
    m_def     = def;
    m_mounted = true;
    return true;
}

void TraversalMount::Dismount()
{
    m_mounted = false;
}

void TraversalMount::Update(float dt, float stickX, float stickZ,
                            float& posX, float& posZ, float& yaw)
{
    if (!m_mounted) return;

    // Rotate toward input direction.
    if (stickX != 0.0f || stickZ != 0.0f)
    {
        const float targetYaw = std::atan2(stickX, stickZ);
        const float diff      = targetYaw - yaw;
        const float delta     = std::fmax(-m_def.turnRate * dt,
                                          std::fmin(m_def.turnRate * dt, diff));
        yaw   += delta;
        posX  += std::sin(yaw) * m_def.speed * dt;
        posZ  += std::cos(yaw) * m_def.speed * dt;
    }
}

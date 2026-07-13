// TraversalController.cpp
// Climb / swim / glide traversal verb parameters.

#include "TraversalController.hpp"

void TraversalController::GetFrameParams(float /*dt*/, float forwardSpeed,
                                          float& outVerticalVelocity,
                                          float& outSpeedScale) const
{
    switch (m_mode)
    {
    case TraversalMode::Climb:
        outSpeedScale       = m_cfg.climbSpeed / 6.0f; // relative to walk speed 6
        outVerticalVelocity = m_cfg.climbSpeed;
        break;

    case TraversalMode::Swim:
        outSpeedScale       = m_cfg.swimSpeed / 6.0f;
        outVerticalVelocity = 0.0f; // stays at water surface unless diving
        break;

    case TraversalMode::Glide:
        outSpeedScale       = 1.0f;
        outVerticalVelocity = m_cfg.glideGravity + forwardSpeed * m_cfg.glideLift;
        break;

    default: // Walk
        outSpeedScale       = 1.0f;
        outVerticalVelocity = 0.0f;
        break;
    }
}

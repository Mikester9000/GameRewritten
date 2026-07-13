#pragma once
// TraversalController.hpp
// Extended traversal verbs: climb, swim, glide.
// Each verb is activated by a state flag and drives CameraController via
// overridden speed / gravity / input handling each frame.

enum class TraversalMode { Walk, Climb, Swim, Glide };

struct TraversalConfig
{
    float climbSpeed  = 3.0f;
    float swimSpeed   = 5.0f;
    float glideGravity = -2.0f; // slow-fall gravity while gliding
    float glideLift   = 0.5f;   // lift per forward-speed unit
};

class TraversalController
{
public:
    void Init(const TraversalConfig& cfg) { m_cfg = cfg; }

    void SetMode(TraversalMode mode) { m_mode = mode; }
    TraversalMode GetMode() const    { return m_mode; }

    // Returns effective vertical velocity and horizontal speed scale for the
    // current mode; caller applies these values to CameraController each frame.
    void GetFrameParams(float dt, float forwardSpeed,
                        float& outVerticalVelocity,
                        float& outSpeedScale) const;

private:
    TraversalConfig m_cfg;
    TraversalMode   m_mode = TraversalMode::Walk;
};

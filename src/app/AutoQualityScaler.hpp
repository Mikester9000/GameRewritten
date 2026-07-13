#pragma once
// AutoQualityScaler.hpp
// Monitors frame time and automatically lowers the quality preset when the
// GPU can no longer sustain the target frame rate.

class AutoQualityScaler
{
public:
    // targetFps: desired frame rate (e.g. 60).
    // cooldownSec: seconds to wait after a change before allowing another.
    void Init(float targetFps = 60.0f, float cooldownSec = 8.0f);

    // Call each frame with the current frame time in seconds.
    // Returns true if a quality downgrade was recommended this frame.
    bool Update(float dt);

    // Returns the recommended quality tier [0=Low, 1=Med, 2=High, 3=Ultra].
    int  RecommendedTier() const { return m_tier; }

    void SetTier(int tier) { m_tier = tier; }

private:
    float m_targetFrameTime = 1.0f / 60.0f;
    float m_cooldown        = 8.0f;
    float m_cooldownTimer   = 0.0f;
    float m_slowFrameAccum  = 0.0f;
    int   m_tier            = 2; // start at High
};

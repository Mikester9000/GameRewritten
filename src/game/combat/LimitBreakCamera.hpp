#pragma once

class LimitBreakCamera
{
public:
    void Start();
    void Update(float dt);

    bool IsActive() const { return m_timer > 0.0f; }
    float GetTimeScale() const;
    float GetSuggestedShakeAmplitude() const;

private:
    float m_timer = 0.0f;
    static constexpr float kDurationSec = 0.75f;
};

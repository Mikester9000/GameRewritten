#pragma once

namespace gr
{
class SaveIndicator
{
public:
    void Begin(float visibleSeconds = 1.25f);
    void Tick(float deltaSeconds);
    bool IsVisible() const { return m_remainingSeconds > 0.0f; }
    float GetAlpha() const;

private:
    float m_remainingSeconds = 0.0f;
    float m_totalSeconds = 1.25f;
};
} // namespace gr

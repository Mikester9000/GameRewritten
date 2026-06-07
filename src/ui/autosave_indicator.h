#pragma once

namespace gr
{
class AutoSaveIndicator
{
public:
    void SetActive(bool active);
    void Tick(float deltaSeconds);
    bool IsActive() const { return m_active; }
    float GetPulseAlpha() const;

private:
    bool m_active = false;
    float m_timeSeconds = 0.0f;
};
} // namespace gr

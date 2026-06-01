#pragma once

namespace gr
{
class CameraSensitivityController
{
public:
    void SetHorizontal(float value);
    void SetVertical(float value);
    float GetHorizontal() const { return m_horizontal; }
    float GetVertical() const { return m_vertical; }
    float ApplyHorizontal(float rawInputDelta) const;
    float ApplyVertical(float rawInputDelta) const;

private:
    static float ClampSensitivity(float value);

    float m_horizontal = 1.0f;
    float m_vertical = 1.0f;
};
} // namespace gr

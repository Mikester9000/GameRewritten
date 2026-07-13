// ============================================================
// FILE: src/camera/sensitivity_controller.h
// SYSTEM: Camera
// ROLE: input sensitivity scaling for camera look
// DO NOT: read raw input here; only scale deltas passed in.
// OWNS: horizontal/vertical sensitivity state.
// ============================================================
//
// [LEGO BLOCK: CAMERA SENSITIVITY]
// -----------------------------------------------------------------
// What it does: clamps and applies per-axis mouse sensitivity.
//
// EXTEND: add an invert-Y flag, zoom sensitivity, or aim-assist
//   scaling by adding new members + matching Set/Apply methods.
//
// EXAMPLE — wire into CameraController:
//   #include "camera/sensitivity_controller.h"
//   gr::CameraSensitivityController m_sensitivity;
//   m_sensitivity.SetHorizontal(settings.mouseSensH);
//   float scaledDeltaX = m_sensitivity.ApplyHorizontal(rawDX);
// -----------------------------------------------------------------

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

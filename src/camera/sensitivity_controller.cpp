#include "sensitivity_controller.h"

#include <algorithm>

namespace gr
{
float CameraSensitivityController::ClampSensitivity(float value)
{
    return std::clamp(value, 0.1f, 5.0f);
}

void CameraSensitivityController::SetHorizontal(float value)
{
    m_horizontal = ClampSensitivity(value);
}

void CameraSensitivityController::SetVertical(float value)
{
    m_vertical = ClampSensitivity(value);
}

float CameraSensitivityController::ApplyHorizontal(float rawInputDelta) const
{
    return rawInputDelta * m_horizontal;
}

float CameraSensitivityController::ApplyVertical(float rawInputDelta) const
{
    return rawInputDelta * m_vertical;
}
} // namespace gr

#include "CombatSpeedSlider.hpp"

namespace
{
constexpr float kScales[CombatSpeedSlider::kOptionCount] = { 0.5f, 0.75f, 1.0f, 1.25f, 1.5f };
constexpr const char* kLabels[CombatSpeedSlider::kOptionCount] = { "0.5x", "0.75x", "1.0x", "1.25x", "1.5x" };
}

void CombatSpeedSlider::SetIndex(int index)
{
    if (index < 0) index = 0;
    if (index >= kOptionCount) index = kOptionCount - 1;
    m_index = index;
}

float CombatSpeedSlider::GetScale() const
{
    return kScales[m_index];
}

const char* CombatSpeedSlider::GetLabel() const
{
    return kLabels[m_index];
}

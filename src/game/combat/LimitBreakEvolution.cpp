#include "LimitBreakEvolution.hpp"

void LimitBreakEvolution::RecordUse()
{
    ++m_useCount;
    if (m_useCount >= 18)
        m_level = 4;
    else if (m_useCount >= 10)
        m_level = 3;
    else if (m_useCount >= 4)
        m_level = 2;
    else
        m_level = 1;
}

const char* LimitBreakEvolution::GetCurrentLimitName() const
{
    switch (m_level)
    {
    case 1: return "Braver";
    case 2: return "Cross-Slash";
    case 3: return "Blade Beam";
    case 4:
    default:
        return "Omnislash";
    }
}

float LimitBreakEvolution::GetDamageMultiplier() const
{
    switch (m_level)
    {
    case 1: return 1.00f;
    case 2: return 1.15f;
    case 3: return 1.30f;
    case 4:
    default:
        return 1.50f;
    }
}

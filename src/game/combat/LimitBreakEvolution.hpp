#pragma once

class LimitBreakEvolution
{
public:
    void RecordUse();
    int GetLevel() const { return m_level; }
    int GetUseCount() const { return m_useCount; }

    const char* GetCurrentLimitName() const;
    float GetDamageMultiplier() const;

private:
    int m_useCount = 0;
    int m_level = 1;
};

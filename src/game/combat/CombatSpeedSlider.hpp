#pragma once

class CombatSpeedSlider
{
public:
    static constexpr int kOptionCount = 5;

    void SetIndex(int index);
    int GetIndex() const { return m_index; }

    float GetScale() const;
    const char* GetLabel() const;

private:
    int m_index = 2; // default 1.0x
};

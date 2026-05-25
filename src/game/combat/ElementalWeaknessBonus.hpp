#pragma once

class ElementalWeaknessBonus
{
public:
    int ApplyBonus(int damage, bool elementalWeaknessHit, bool weakPointHit) const;

private:
    static constexpr float kWeaknessBonusMult = 2.0f;
    static constexpr float kWeakPointSynergyBonusMult = 2.25f;
};

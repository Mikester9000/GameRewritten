#include "ElementalWeaknessBonus.hpp"

int ElementalWeaknessBonus::ApplyBonus(int damage, bool elementalWeaknessHit, bool weakPointHit) const
{
    if (!elementalWeaknessHit)
        return damage;

    const float bonus = weakPointHit ? kWeakPointSynergyBonusMult : kWeaknessBonusMult;
    return static_cast<int>(damage * bonus + 0.5f);
}

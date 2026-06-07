
#define NOMINMAX

#pragma once

#include <algorithm>
#include <windows.h>

// Damage elements used by combat attacks.
enum class Element : int
{
    Physical = 0,
    Fire,
    Ice,
    Lightning
};

// Per-enemy resistance profile (1.0 = neutral, >1 weak, <1 resist).
struct ElementProfile
{
    float fire = 1.0f;
    float ice = 1.0f;
    float lightning = 1.0f;
};

struct ElementResolveResult
{
    int damage = 0;
    float multiplier = 1.0f;
    bool isWeakness = false;
    bool isResistance = false;
};

inline float ElementMultiplier(Element element, const ElementProfile& profile)
{
    switch (element)
    {
    case Element::Fire: return profile.fire;
    case Element::Ice: return profile.ice;
    case Element::Lightning: return profile.lightning;
    case Element::Physical:
    default:
        return 1.0f;
    }
}

inline ElementResolveResult ResolveElementalDamage(int baseDamage, Element element, const ElementProfile& profile)
{
    ElementResolveResult result;
    result.multiplier = ElementMultiplier(element, profile);
    result.isWeakness = (result.multiplier >= 1.25f);
    result.isResistance = (result.multiplier <= 0.85f);
    result.damage = static_cast<int>((std::max)(1.0f, baseDamage * result.multiplier));
    return result;
}

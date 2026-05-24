// ============================================================
// FILE: src/game/combat/CombatModifiers.hpp
// SYSTEM: Combat
// ROLE: runtime combat stat modifier pipeline stub
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: CombatModifier / CombatModifierStack definitions.
// ============================================================

#pragma once

#include <algorithm>
#include <array>

// Types of combat modifiers supported by the modifier pipeline.
enum class CombatModifierType : int
{
    DamageMultiplier = 0, // scales outgoing damage (multiplicative)
    SpeedMultiplier  = 1, // scales movement / attack speed
    DefenseMultiplier = 2, // scales incoming damage reduction
};

struct CombatModifier
{
    CombatModifierType type     = CombatModifierType::DamageMultiplier;
    float              value    = 1.0f;  // multiplier (1.0 = no change)
    float              duration = 0.0f;  // remaining seconds; 0 = expired

    bool IsActive() const { return duration > 0.0f; }
};

// Fixed-capacity stack of combat modifiers; avoids dynamic allocation.
// Supports up to kMaxModifiers simultaneous active modifiers.
class CombatModifierStack
{
public:
    static constexpr int kMaxModifiers = 8;

    // Add a modifier to the stack, overwriting the oldest expired slot.
    // If all slots are occupied, the modifier with the shortest remaining
    // duration of the same type is replaced (graceful overflow).
    void Apply(CombatModifierType type, float value, float duration)
    {
        // Try to find a free slot first.
        for (auto& m : m_modifiers)
        {
            if (!m.IsActive())
            {
                m = { type, value, duration };
                return;
            }
        }
        // All slots occupied — evict the one of the same type with least time.
        CombatModifier* best = nullptr;
        for (auto& m : m_modifiers)
        {
            if (m.type == type)
            {
                if (best == nullptr || m.duration < best->duration)
                    best = &m;
            }
        }
        if (best)
        {
            *best = { type, value, duration };
            return;
        }
        // Last resort: evict the modifier with the shortest duration overall.
        CombatModifier* soonest = &m_modifiers[0];
        for (auto& m : m_modifiers)
            if (m.duration < soonest->duration)
                soonest = &m;
        *soonest = { type, value, duration };
    }

    // Tick all active modifiers down by dt seconds.
    void Update(float dt)
    {
        for (auto& m : m_modifiers)
            if (m.IsActive())
                m.duration = std::max(0.0f, m.duration - dt);
    }

    // Returns the product of all active DamageMultiplier modifiers.
    // Returns 1.0 when no modifiers are active.
    float GetTotalDamageMultiplier() const
    {
        return GetTotalMultiplier(CombatModifierType::DamageMultiplier);
    }

    // Returns the product of all active SpeedMultiplier modifiers.
    float GetTotalSpeedMultiplier() const
    {
        return GetTotalMultiplier(CombatModifierType::SpeedMultiplier);
    }

    // Returns the product of all active DefenseMultiplier modifiers.
    float GetTotalDefenseMultiplier() const
    {
        return GetTotalMultiplier(CombatModifierType::DefenseMultiplier);
    }

    // Remove all modifiers immediately (e.g. on respawn).
    void Clear()
    {
        for (auto& m : m_modifiers)
            m = CombatModifier{};
    }

private:
    std::array<CombatModifier, kMaxModifiers> m_modifiers{};

    float GetTotalMultiplier(CombatModifierType type) const
    {
        float product = 1.0f;
        for (const auto& m : m_modifiers)
            if (m.IsActive() && m.type == type)
                product *= m.value;
        return product;
    }
};

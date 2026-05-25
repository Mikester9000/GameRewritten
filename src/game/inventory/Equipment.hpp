#pragma once
// Equipment.hpp — Task 053 (ORDER 48): Equipment slot stub
// Defines EquipSlot enum and Equipment struct with per-slot stat bonuses.
// Stub only — not yet wired into PlayerStats at runtime.

#include <string>
#include <array>

namespace gr {

// ── Slot definitions ──────────────────────────────────────────────────────────
enum class EquipSlot : int
{
    Weapon  = 0,
    Armor   = 1,
    Helmet  = 2,
    Accessory = 3,
    Count   = 4
};

// ── Per-item data ─────────────────────────────────────────────────────────────
struct Equipment
{
    std::string name;       // display name
    EquipSlot   slot  = EquipSlot::Weapon;

    // Flat stat bonuses applied while equipped.
    int   atkBonus   = 0;   // added to base attack damage
    int   defBonus   = 0;   // reduces incoming damage (subtracted from hit)
    int   hpBonus    = 0;   // added to maxHp
    int   mpBonus    = 0;   // added to maxMp
    float speedBonus = 0.0f; // movement / action speed multiplier delta

    // Returns true if this slot is occupied.
    bool IsValid() const { return !name.empty(); }
};

// ── Loadout: one item per slot ────────────────────────────────────────────────
struct EquipmentLoadout
{
    static constexpr int kSlotCount = static_cast<int>(EquipSlot::Count);
    std::array<Equipment, kSlotCount> slots{};

    // Equip an item; returns false if slot mismatch.
    bool Equip(const Equipment& item)
    {
        int idx = static_cast<int>(item.slot);
        if (idx < 0 || idx >= kSlotCount) return false;
        slots[idx] = item;
        return true;
    }

    // Unequip a slot; leaves an empty Equipment in its place.
    void Unequip(EquipSlot s)
    {
        int idx = static_cast<int>(s);
        if (idx >= 0 && idx < kSlotCount)
            slots[idx] = Equipment{};
    }

    // Aggregate helpers — call once per frame to get net bonuses.
    int   TotalAtkBonus()   const { int t=0; for (auto& e:slots) t+=e.atkBonus;  return t; }
    int   TotalDefBonus()   const { int t=0; for (auto& e:slots) t+=e.defBonus;  return t; }
    int   TotalHpBonus()    const { int t=0; for (auto& e:slots) t+=e.hpBonus;   return t; }
    int   TotalMpBonus()    const { int t=0; for (auto& e:slots) t+=e.mpBonus;   return t; }
    float TotalSpeedBonus() const { float t=0.0f; for (auto& e:slots) t+=e.speedBonus; return t; }

    // Returns slot reference for read-only display.
    const Equipment& Get(EquipSlot s) const
    {
        return slots[static_cast<int>(s)];
    }
};

} // namespace gr

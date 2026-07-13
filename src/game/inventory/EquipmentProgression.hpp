#pragma once
// EquipmentProgression.hpp
// Tracks upgrade tiers for each equipment item and manages socket slots
// that accept materia / augment crystals.

#include "Equipment.hpp"

#include <string>
#include <vector>

namespace gr {

struct AugmentSocket
{
    std::string materialId; // empty = empty socket
    int         tier = 0;   // 0 = base, 1/2/3 = upgraded
};

struct EquipmentRecord
{
    Equipment                   item;
    int                         upgradeTier = 0;       // 0–3
    std::vector<AugmentSocket>  sockets;               // size set at creation

    // Returns stat bonus scaled by upgrade tier.
    int ScaledAtkBonus() const { return item.atkBonus * (1 + upgradeTier); }
    int ScaledDefBonus() const { return item.defBonus * (1 + upgradeTier); }
};

class EquipmentProgression
{
public:
    // Register an item with a given socket count; returns its record index.
    int  Register(const Equipment& item, int socketCount = 0);

    // Upgrade an item by one tier (max 3); returns false if already max.
    bool Upgrade(int recordIndex);

    // Insert a material id into a socket; returns false if slot is occupied or OOB.
    bool Augment(int recordIndex, int socketIndex, const std::string& materialId);

    const std::vector<EquipmentRecord>& GetAll() const { return m_records; }

private:
    std::vector<EquipmentRecord> m_records;
};

} // namespace gr

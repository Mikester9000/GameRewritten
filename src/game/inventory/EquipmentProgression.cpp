// EquipmentProgression.cpp
// Equipment upgrade tier + augment socket management.

#include "EquipmentProgression.hpp"

namespace gr {

int EquipmentProgression::Register(const Equipment& item, int socketCount)
{
    EquipmentRecord rec;
    rec.item   = item;
    rec.sockets.resize(socketCount);
    m_records.push_back(rec);
    return static_cast<int>(m_records.size()) - 1;
}

bool EquipmentProgression::Upgrade(int idx)
{
    static constexpr int kMaxTier = 3;
    if (idx < 0 || idx >= static_cast<int>(m_records.size())) return false;
    if (m_records[idx].upgradeTier >= kMaxTier) return false;
    ++m_records[idx].upgradeTier;
    return true;
}

bool EquipmentProgression::Augment(int idx, int socketIdx, const std::string& materialId)
{
    if (idx < 0 || idx >= static_cast<int>(m_records.size())) return false;
    auto& sockets = m_records[idx].sockets;
    if (socketIdx < 0 || socketIdx >= static_cast<int>(sockets.size())) return false;
    if (!sockets[socketIdx].materialId.empty()) return false; // occupied
    sockets[socketIdx].materialId = materialId;
    return true;
}

} // namespace gr

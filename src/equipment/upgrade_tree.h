#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace gr
{
struct UpgradeNode
{
    std::string nodeId;
    std::vector<std::string> prerequisites;
    bool unlocked = false;
};

class EquipmentUpgradeTree
{
public:
    void SetNodes(const std::vector<UpgradeNode>& nodes);
    bool Unlock(const std::string& nodeId);
    bool IsUnlocked(const std::string& nodeId) const;
    bool CanUnlock(const std::string& nodeId) const;

private:
    std::unordered_map<std::string, UpgradeNode> m_nodes;
};
} // namespace gr

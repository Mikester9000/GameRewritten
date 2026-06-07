#include "upgrade_tree.h"

namespace gr
{
void EquipmentUpgradeTree::SetNodes(const std::vector<UpgradeNode>& nodes)
{
    m_nodes.clear();
    for (const UpgradeNode& node : nodes)
    {
        if (!node.nodeId.empty())
        {
            m_nodes[node.nodeId] = node;
        }
    }
}

bool EquipmentUpgradeTree::IsUnlocked(const std::string& nodeId) const
{
    const auto it = m_nodes.find(nodeId);
    return it != m_nodes.end() && it->second.unlocked;
}

bool EquipmentUpgradeTree::CanUnlock(const std::string& nodeId) const
{
    const auto it = m_nodes.find(nodeId);
    if (it == m_nodes.end() || it->second.unlocked)
    {
        return false;
    }

    for (const std::string& req : it->second.prerequisites)
    {
        if (!IsUnlocked(req))
        {
            return false;
        }
    }
    return true;
}

bool EquipmentUpgradeTree::Unlock(const std::string& nodeId)
{
    if (!CanUnlock(nodeId))
    {
        return false;
    }
    m_nodes[nodeId].unlocked = true;
    return true;
}
} // namespace gr

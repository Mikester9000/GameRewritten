#include "skill_tree.h"

namespace gr
{
void SkillTree::SetNodes(const std::vector<SkillNode>& nodes)
{
    m_nodes.clear();
    for (const SkillNode& node : nodes)
    {
        if (!node.nodeId.empty())
        {
            m_nodes[node.nodeId] = node;
        }
    }
}

bool SkillTree::IsUnlocked(const std::string& nodeId) const
{
    const auto it = m_nodes.find(nodeId);
    return it != m_nodes.end() && it->second.unlocked;
}

bool SkillTree::DependenciesMet(const SkillNode& node) const
{
    for (const std::string& dependency : node.dependencies)
    {
        if (!IsUnlocked(dependency))
        {
            return false;
        }
    }
    return true;
}

bool SkillTree::Unlock(const std::string& nodeId)
{
    auto it = m_nodes.find(nodeId);
    if (it == m_nodes.end() || it->second.unlocked)
    {
        return false;
    }

    SkillNode& node = it->second;
    if (node.pointCost > m_availablePoints || !DependenciesMet(node))
    {
        return false;
    }

    m_availablePoints -= node.pointCost;
    node.unlocked = true;
    return true;
}
} // namespace gr

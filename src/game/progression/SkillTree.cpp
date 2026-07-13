// SkillTree.cpp
// DAG skill tree: prerequisite-gated, SP-cost node unlocking.

#include "SkillTree.hpp"

int SkillTree::AddNode(const std::string& abilityId,
                       const std::string& displayName,
                       int spCost,
                       const std::vector<int>& prereqs)
{
    SkillNode n;
    n.id          = m_nextId++;
    n.abilityId   = abilityId;
    n.displayName = displayName;
    n.spCost      = spCost;
    n.requires    = prereqs;
    m_nodes.push_back(n);
    return n.id;
}

const SkillNode* SkillTree::FindNode(int id) const
{
    for (const SkillNode& n : m_nodes)
        if (n.id == id) return &n;
    return nullptr;
}

bool SkillTree::IsUnlocked(int nodeId) const
{
    const SkillNode* n = FindNode(nodeId);
    return n && n->unlocked;
}

bool SkillTree::Unlock(int nodeId, int& availableSP)
{
    SkillNode* n = const_cast<SkillNode*>(FindNode(nodeId));
    if (!n || n->unlocked) return false;
    if (availableSP < n->spCost) return false;

    for (int req : n->requires)
        if (!IsUnlocked(req)) return false;

    availableSP -= n->spCost;
    n->unlocked  = true;
    return true;
}

#pragma once
// SkillTree.hpp
// Directed acyclic skill tree with prerequisite checks and SP cost tracking.
// Each node unlocks an ability from AbilityProgression.

#include <string>
#include <vector>

struct SkillNode
{
    int         id            = 0;
    std::string abilityId;      // matches AbilityProgression ability id
    std::string displayName;
    int         spCost        = 1;
    std::vector<int> requires; // prerequisite node ids (all must be unlocked)
    bool        unlocked      = false;
};

class SkillTree
{
public:
    // Add a node; returns its id.
    int  AddNode(const std::string& abilityId,
                 const std::string& displayName,
                 int spCost,
                 const std::vector<int>& prereqs = {});

    // Attempt to unlock a node using availableSP.
    // Returns false if prerequisites are missing or SP is insufficient.
    bool Unlock(int nodeId, int& availableSP);

    bool IsUnlocked(int nodeId) const;

    const std::vector<SkillNode>& GetAll() const { return m_nodes; }

private:
    std::vector<SkillNode> m_nodes;
    int                    m_nextId = 1;

    SkillNode* FindNode(int id);
    const SkillNode* FindNode(int id) const;
};

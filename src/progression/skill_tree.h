// ============================================================
// FILE: src/progression/skill_tree.h
// SYSTEM: Progression
// ROLE: FF10 sphere-grid style skill unlock tree
// DO NOT: apply skill effects here; return unlock state to caller.
// OWNS: node map, dependency graph, and available-point counter.
// ============================================================
//
// [LEGO BLOCK: SKILL TREE]
// -----------------------------------------------------------------
// What it does: a prerequisite-gated skill graph where each node
//   costs skill points and can only be unlocked once its
//   dependencies are satisfied. Inspired by the FF10 Sphere Grid.
//
// EXTEND: add skill categories (e.g. "magic", "physical") by
//   adding a category string to SkillNode and filtering GetAll
//   by category in the UI.
//
// EXAMPLE — level up grants skill points, then player picks:
//   #include "progression/skill_tree.h"
//   gr::SkillTree m_skillTree;
//   m_skillTree.SetNodes(loadedNodes);
//   m_skillTree.SetAvailablePoints(m_skillTree.GetAvailablePoints() + 3);
//   if (m_skillTree.Unlock("firaga"))
//       stats.ApplySkillBonus("firaga");
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace gr
{
struct SkillNode
{
    std::string nodeId;
    int pointCost = 1;
    std::vector<std::string> dependencies;
    bool unlocked = false;
};

class SkillTree
{
public:
    void SetAvailablePoints(int points) { m_availablePoints = points < 0 ? 0 : points; }
    int GetAvailablePoints() const { return m_availablePoints; }
    void SetNodes(const std::vector<SkillNode>& nodes);
    bool Unlock(const std::string& nodeId);
    bool IsUnlocked(const std::string& nodeId) const;

private:
    bool DependenciesMet(const SkillNode& node) const;

    int m_availablePoints = 0;
    std::unordered_map<std::string, SkillNode> m_nodes;
};
} // namespace gr

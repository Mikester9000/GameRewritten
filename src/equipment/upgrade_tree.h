// ============================================================
// FILE: src/equipment/upgrade_tree.h
// SYSTEM: Equipment
// ROLE: prerequisite-gated equipment upgrade progression
// DO NOT: store visual or stat data here; just unlock state.
// OWNS: upgrade node map and prerequisite-check logic.
// ============================================================
//
// [LEGO BLOCK: EQUIPMENT UPGRADE TREE]
// -----------------------------------------------------------------
// What it does: manages a directed-acyclic-graph of upgrade nodes
//   where each node can only be unlocked if its prerequisites are
//   already unlocked (like the FF10 sphere grid, but per weapon).
//
// EXTEND: add node data fields (e.g. statBonus, materialCost) by
//   adding them to UpgradeNode and reading them in the caller.
//   Load node definitions from JSON and call SetNodes().
//
// EXAMPLE — unlock an upgrade after crafting check:
//   #include "equipment/upgrade_tree.h"
//   gr::EquipmentUpgradeTree m_upgradeTree;
//   m_upgradeTree.SetNodes(weaponNodes);
//   if (m_upgradeTree.CanUnlock("blade_sharpening_2"))
//       m_upgradeTree.Unlock("blade_sharpening_2");
// -----------------------------------------------------------------

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

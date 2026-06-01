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

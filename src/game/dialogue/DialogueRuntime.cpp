// DialogueRuntime.cpp
// Branching dialogue graph execution with QuestFlag-gated choices.

#include "DialogueRuntime.hpp"
#include "../quest/QuestFlags.hpp"

void DialogueRuntime::LoadGraph(const std::vector<DialogueNode>& nodes)
{
    m_nodes = nodes;
}

void DialogueRuntime::Start(int startNodeId, QuestFlags& flags)
{
    m_currentId = startNodeId;
    m_running   = FindNode(startNodeId) != nullptr;

    if (m_running)
    {
        const DialogueNode* node = FindNode(startNodeId);
        if (node && !node->setFlagOnEnter.empty())
            flags.Set(node->setFlagOnEnter);
    }
}

const DialogueNode* DialogueRuntime::Current() const
{
    return FindNode(m_currentId);
}

std::vector<const DialogueChoice*> DialogueRuntime::GetAvailableChoices(const QuestFlags& flags) const
{
    std::vector<const DialogueChoice*> out;
    const DialogueNode* node = FindNode(m_currentId);
    if (!node) return out;

    for (const DialogueChoice& c : node->choices)
    {
        if (c.requiredFlag.empty() || flags.Get(c.requiredFlag))
            out.push_back(&c);
    }
    return out;
}

void DialogueRuntime::Choose(int choiceIndex, QuestFlags& flags)
{
    auto available = GetAvailableChoices(flags);
    if (choiceIndex < 0 || choiceIndex >= static_cast<int>(available.size()))
        { m_running = false; return; }

    const int nextId = available[choiceIndex]->nextNodeId;
    if (nextId < 0) { m_running = false; return; }

    m_currentId = nextId;
    const DialogueNode* next = FindNode(nextId);
    if (next && !next->setFlagOnEnter.empty())
        flags.Set(next->setFlagOnEnter);
}

void DialogueRuntime::Advance()
{
    const DialogueNode* node = FindNode(m_currentId);
    if (!node || node->choices.empty()) { m_running = false; return; }
    // If choices exist, caller must use Choose().
}

const DialogueNode* DialogueRuntime::FindNode(int id) const
{
    for (const DialogueNode& n : m_nodes)
        if (n.id == id) return &n;
    return nullptr;
}

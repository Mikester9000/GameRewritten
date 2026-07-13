#pragma once
// DialogueRuntime.hpp
// Branching dialogue execution: runs a node graph, evaluates conditions via
// QuestFlags, and exposes the current line + choice set to the UI layer.

#include <functional>
#include <string>
#include <vector>

struct DialogueChoice
{
    std::string text;
    int         nextNodeId = -1; // -1 = end of conversation
    std::string requiredFlag;    // must be set in QuestFlags to show this choice
};

struct DialogueNode
{
    int                       id = 0;
    std::string               speakerName;
    std::string               line;
    std::vector<DialogueChoice> choices;   // empty = auto-advance after display
    std::string               setFlagOnEnter; // optional QuestFlag to set
};

class QuestFlags; // forward

class DialogueRuntime
{
public:
    void LoadGraph(const std::vector<DialogueNode>& nodes);
    void Start(int startNodeId, QuestFlags& flags);

    bool        IsRunning()       const { return m_running; }
    const DialogueNode* Current() const;

    // Returns choices that satisfy QuestFlags conditions.
    std::vector<const DialogueChoice*> GetAvailableChoices(const QuestFlags& flags) const;

    // Advance to the target node of choice at choiceIndex; -1 = end.
    void Choose(int choiceIndex, QuestFlags& flags);

    // Auto-advance (no choices); ends dialogue if no next node.
    void Advance();

private:
    std::vector<DialogueNode> m_nodes;
    int                       m_currentId = -1;
    bool                      m_running   = false;

    const DialogueNode* FindNode(int id) const;
};

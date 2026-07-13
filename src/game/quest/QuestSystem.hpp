#pragma once
// QuestSystem.hpp
// Minimal quest tracking: register quests with ordered objectives, advance
// them from game code, and query status for HUD / save integration.

#include <functional>
#include <string>
#include <vector>

enum class ObjectiveState { Pending, Active, Complete, Failed };

struct QuestObjective
{
    std::string    description;
    ObjectiveState state = ObjectiveState::Pending;
};

struct Quest
{
    int                         id = 0;
    std::string                 title;
    std::vector<QuestObjective> objectives;
    bool                        complete = false;
    bool                        failed   = false;

    // Returns the index of the first non-complete objective, or -1 if done.
    int ActiveObjectiveIndex() const;
};

class QuestSystem
{
public:
    // Register a new quest; returns its assigned id.
    int AddQuest(const std::string& title,
                 const std::vector<std::string>& objectiveDescs);

    // Advance the current objective for questId to Complete, then activate
    // the next objective.  Fires onQuestComplete if all objectives are done.
    void AdvanceObjective(int questId,
                          const std::function<void(const Quest&)>& onQuestComplete = {});

    void FailQuest(int questId);

    const Quest* Find(int questId) const;
    const std::vector<Quest>& GetAll() const { return m_quests; }

private:
    std::vector<Quest> m_quests;
    int                m_nextId = 1;
};

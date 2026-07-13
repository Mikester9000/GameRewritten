// QuestSystem.cpp
// Minimal ordered-objective quest tracking.

#include "QuestSystem.hpp"

int Quest::ActiveObjectiveIndex() const
{
    for (int i = 0; i < static_cast<int>(objectives.size()); ++i)
        if (objectives[i].state != ObjectiveState::Complete) return i;
    return -1;
}

int QuestSystem::AddQuest(const std::string& title,
                          const std::vector<std::string>& objectiveDescs)
{
    Quest q;
    q.id    = m_nextId++;
    q.title = title;
    for (const auto& desc : objectiveDescs)
    {
        QuestObjective obj;
        obj.description = desc;
        obj.state       = q.objectives.empty() ? ObjectiveState::Active
                                               : ObjectiveState::Pending;
        q.objectives.push_back(obj);
    }
    m_quests.push_back(std::move(q));
    return m_quests.back().id;
}

void QuestSystem::AdvanceObjective(int questId,
                                   const std::function<void(const Quest&)>& onQuestComplete)
{
    for (Quest& q : m_quests)
    {
        if (q.id != questId || q.complete || q.failed) continue;

        const int idx = q.ActiveObjectiveIndex();
        if (idx < 0) return;

        q.objectives[idx].state = ObjectiveState::Complete;

        // Activate the next objective if one exists.
        const int next = idx + 1;
        if (next < static_cast<int>(q.objectives.size()))
            q.objectives[next].state = ObjectiveState::Active;
        else
        {
            q.complete = true;
            if (onQuestComplete) onQuestComplete(q);
        }
        return;
    }
}

void QuestSystem::FailQuest(int questId)
{
    for (Quest& q : m_quests)
        if (q.id == questId) { q.failed = true; return; }
}

const Quest* QuestSystem::Find(int questId) const
{
    for (const Quest& q : m_quests)
        if (q.id == questId) return &q;
    return nullptr;
}

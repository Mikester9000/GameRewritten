#pragma once
// QuestSchema.hpp
// Data contract for quest authoring.  All quest definition files must conform
// to this schema so the validator can catch missing/malformed data at load time.

#include <string>
#include <vector>

struct QuestObjectiveSchema
{
    std::string description;   // required, non-empty
    std::string flagOnComplete; // optional: QuestFlag key to set on completion
};

struct QuestSchema
{
    std::string id;             // unique quest identifier (required)
    std::string title;          // display title (required)
    std::string giver;          // NPC name or "world" for world-triggered quests
    std::vector<QuestObjectiveSchema> objectives; // at least one required

    // Validate returns an empty string on success or a diagnostic message.
    std::string Validate() const
    {
        if (id.empty())         return "QuestSchema: 'id' is empty";
        if (title.empty())      return "QuestSchema: 'title' is empty";
        if (objectives.empty()) return "QuestSchema '" + id + "': no objectives";
        for (const auto& obj : objectives)
            if (obj.description.empty())
                return "QuestSchema '" + id + "': objective has empty description";
        return {}; // valid
    }
};

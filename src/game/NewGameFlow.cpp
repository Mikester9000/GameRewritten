// NewGameFlow.cpp
// New-game bootstrap: default flags, starter quest, starter inventory.

#include "NewGameFlow.hpp"

#include "quest/QuestFlags.hpp"
#include "quest/QuestSystem.hpp"
#include "inventory/Inventory.hpp"

void NewGameFlow::Start(QuestFlags& flags, QuestSystem& quests, Inventory& inventory)
{
    m_step     = 0;
    m_timer    = 0.0f;
    m_complete = false;

    // Seed default world state.
    flags.Clear();
    flags.Set("new_game", true);

    // Register the opening quest.
    quests.AddQuest("Awakening",
        { "Reach the campfire", "Speak to the guide NPC" });

    // Give starting items.
    inventory.Add("Potion", 3);
    inventory.Add("Phoenix Down", 1);
}

bool NewGameFlow::Update(float /*dt*/)
{
    // Minimal stub: complete immediately after Start().
    // A real implementation would play the opening cutscene here.
    m_complete = true;
    return m_complete;
}

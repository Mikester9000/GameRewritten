#pragma once
// NewGameFlow.hpp
// Bootstraps a fresh game: applies default world state, shows the opening
// cutscene entry point, and seeds starting inventory / quest flags.

class QuestFlags;     // forward
class QuestSystem;    // forward
class Inventory;      // forward

class NewGameFlow
{
public:
    // Returns true once the bootstrap sequence is complete.
    bool IsComplete() const { return m_complete; }

    // Call once after all systems are initialised to begin the new-game flow.
    void Start(QuestFlags& flags, QuestSystem& quests, Inventory& inventory);

    // Advance the flow state machine each frame; returns true when done.
    bool Update(float dt);

private:
    bool  m_complete = false;
    float m_timer    = 0.0f;
    int   m_step     = 0;
};

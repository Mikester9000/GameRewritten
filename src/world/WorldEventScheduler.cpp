// WorldEventScheduler.cpp
// Hour-based world event activation / deactivation.

#include "WorldEventScheduler.hpp"

int WorldEventScheduler::AddEvent(const std::string& name, float startHour, float endHour)
{
    ScheduledEvent e;
    e.id        = m_nextId++;
    e.name      = name;
    e.startHour = startHour;
    e.endHour   = endHour;
    m_events.push_back(e);
    return e.id;
}

void WorldEventScheduler::Clear()
{
    m_events.clear();
    m_nextId = 1;
}

void WorldEventScheduler::Update(
    float currentHour,
    const std::function<void(const ScheduledEvent&)>& onActivate,
    const std::function<void(const ScheduledEvent&)>& onDeactivate)
{
    for (ScheduledEvent& e : m_events)
    {
        const bool shouldBeActive = currentHour >= e.startHour && currentHour < e.endHour;

        if (shouldBeActive && !e.active)
        {
            e.active = true;
            if (onActivate) onActivate(e);
        }
        else if (!shouldBeActive && e.active)
        {
            e.active = false;
            if (onDeactivate) onDeactivate(e);
        }
    }
}

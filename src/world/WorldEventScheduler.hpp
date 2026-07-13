#pragma once
// WorldEventScheduler.hpp
// Time- and weather-triggered world events (market days, storms, festivals).
// The scheduler fires callbacks when conditions are met each in-game day.

#include <functional>
#include <string>
#include <vector>

struct ScheduledEvent
{
    int         id        = 0;
    std::string name;
    float       startHour = 8.0f;   // in-game hour [0,24)
    float       endHour   = 20.0f;
    bool        active    = false;
};

class WorldEventScheduler
{
public:
    int  AddEvent(const std::string& name, float startHour, float endHour);
    void Clear();

    // Pass current in-game hour [0,24).  Fires onActivate / onDeactivate
    // whenever an event transitions.
    void Update(float currentHour,
                const std::function<void(const ScheduledEvent&)>& onActivate,
                const std::function<void(const ScheduledEvent&)>& onDeactivate);

    const std::vector<ScheduledEvent>& GetAll() const { return m_events; }

private:
    std::vector<ScheduledEvent> m_events;
    int                         m_nextId = 1;
};

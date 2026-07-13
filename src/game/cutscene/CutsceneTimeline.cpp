// CutsceneTimeline.cpp
// Timed-event playback for scripted cutscenes.

#include "CutsceneTimeline.hpp"

#include <algorithm>

void CutsceneTimeline::Load(const std::vector<TimelineEvent>& events)
{
    m_events = events;
    std::sort(m_events.begin(), m_events.end(),
              [](const TimelineEvent& a, const TimelineEvent& b){ return a.time < b.time; });
}

void CutsceneTimeline::Play()
{
    m_time    = 0.0f;
    m_nextIdx = 0;
    m_playing = true;
}

void CutsceneTimeline::Stop()
{
    m_playing = false;
}

float CutsceneTimeline::Duration() const
{
    return m_events.empty() ? 0.0f : m_events.back().time;
}

void CutsceneTimeline::Update(float dt,
                               const std::function<void(const TimelineEvent&)>& onEvent)
{
    if (!m_playing) return;

    m_time += dt;

    while (m_nextIdx < static_cast<int>(m_events.size()) &&
           m_events[m_nextIdx].time <= m_time)
    {
        if (onEvent) onEvent(m_events[m_nextIdx]);
        ++m_nextIdx;
    }

    if (m_time >= Duration()) m_playing = false;
}

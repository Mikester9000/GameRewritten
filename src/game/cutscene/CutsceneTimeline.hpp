#pragma once
// CutsceneTimeline.hpp
// Plays back a sequence of timed events: camera moves, dialogue lines,
// actor animations, and flag sets.  Camera rails are specified as world-
// space keyframes interpolated over a given duration.

#include <DirectXMath.h>
#include <functional>
#include <string>
#include <vector>

struct TimelineEvent
{
    float       time = 0.0f;  // seconds from cutscene start
    std::string type;          // "dialog", "camera", "flag", "sfx"
    std::string data;          // payload: dialog text / flag key / sfx id
    DirectX::XMFLOAT3 cameraPos{};
    DirectX::XMFLOAT3 cameraTarget{};
};

class CutsceneTimeline
{
public:
    void Load(const std::vector<TimelineEvent>& events);

    void Play();
    void Stop();
    bool IsPlaying() const { return m_playing; }

    // Advance playhead by dt.  Fires onEvent for each event whose time is
    // reached this tick.
    void Update(float dt, const std::function<void(const TimelineEvent&)>& onEvent);

    float CurrentTime() const { return m_time; }
    float Duration()    const;

private:
    std::vector<TimelineEvent> m_events;
    float                      m_time    = 0.0f;
    bool                       m_playing = false;
    int                        m_nextIdx = 0;
};

#pragma once
// TutorialOverlay.hpp
// Context-sensitive tutorial reminders shown in the first few minutes of
// gameplay.  Tracks which tips have been seen and suppresses repeats.

#include <string>
#include <unordered_set>

struct TutorialTip
{
    std::string id;       // unique key, used to track seen state
    std::string text;     // short one-line hint
    float       duration = 4.0f; // seconds to display
};

class TutorialOverlay
{
public:
    // Queue a tip; ignored if it was already shown this session.
    void ShowTip(const TutorialTip& tip);

    // Returns true if a tip is currently visible.
    bool IsVisible() const { return m_active; }

    // Advance timer and draw current tip using ImGui draw-list.
    void Update(float dt, float vpW, float vpH);

private:
    TutorialTip              m_current{};
    float                    m_elapsed = 0.0f;
    bool                     m_active  = false;
    std::unordered_set<std::string> m_seen;
};

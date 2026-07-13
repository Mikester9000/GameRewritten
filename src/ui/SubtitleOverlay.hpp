#pragma once
// SubtitleOverlay.hpp
// Displays timed subtitle text below the screen during voiced lines and
// cutscenes.  Text fades in and out and supports multiple speaker colours.

#include <string>

class SubtitleOverlay
{
public:
    struct Entry
    {
        std::string text;
        std::string speaker;    // used to choose colour; empty = white
        float       duration;   // seconds to display
    };

    // Show a subtitle line; replaces any current line immediately.
    void Show(const Entry& entry);
    void Clear() { m_active = false; }

    bool IsActive() const { return m_active; }

    // Advance timer and draw if active.  Call inside an active ImGui frame.
    void Update(float dt, float vpW, float vpH);

private:
    Entry m_current{};
    float m_elapsed  = 0.0f;
    bool  m_active   = false;
};

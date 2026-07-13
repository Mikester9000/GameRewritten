#pragma once
// CommandWheel.hpp
// Radial command wheel shown during tactical slow-time.
// Displays up to 8 action slots; the caller selects with directional input
// and confirms with a button press.

#include <functional>
#include <string>
#include <vector>

struct WheelSlot
{
    std::string label;
    bool        available = true;    // grayed out when false
};

class CommandWheel
{
public:
    static constexpr int kMaxSlots = 8;

    void Open();
    void Close();
    bool IsOpen() const { return m_open; }

    void SetSlots(const std::vector<WheelSlot>& slots);

    // Navigate with directional input (-1 / 0 / +1 per axis).
    void Navigate(int dx, int dy);

    int  SelectedIndex() const { return m_selected; }

    // Draw the wheel using ImGui draw-list primitives.
    // Returns the confirmed slot index (0-based) or -1 if no selection was made.
    int  Draw(float centerX, float centerY, float radius);

private:
    bool                   m_open     = false;
    int                    m_selected = 0;
    std::vector<WheelSlot> m_slots;
};

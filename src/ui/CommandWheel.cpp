// CommandWheel.cpp
// Radial command wheel rendered with ImGui draw-list primitives.

#include "CommandWheel.hpp"

#include "../../third_party/imgui/imgui.h"

#include <cmath>

static constexpr float kPi = 3.14159265f;

void CommandWheel::Open()  { m_open = true;  m_selected = 0; }
void CommandWheel::Close() { m_open = false; }

void CommandWheel::SetSlots(const std::vector<WheelSlot>& slots)
{
    m_slots    = slots;
    m_selected = 0;
}

void CommandWheel::Navigate(int dx, int /*dy*/)
{
    if (m_slots.empty()) return;
    m_selected = (m_selected + dx + static_cast<int>(m_slots.size()))
                 % static_cast<int>(m_slots.size());
}

int CommandWheel::Draw(float centerX, float centerY, float radius)
{
    if (!m_open || m_slots.empty()) return -1;

    ImDrawList* dl = ImGui::GetForegroundDrawList();
    const int   n  = static_cast<int>(m_slots.size());

    // Background circle.
    dl->AddCircleFilled({ centerX, centerY }, radius, IM_COL32(0, 0, 0, 160), 32);

    for (int i = 0; i < n; ++i)
    {
        const float angle = (kPi * 2.0f / n) * i - kPi * 0.5f;
        const float lx    = centerX + std::cos(angle) * radius * 0.7f;
        const float ly    = centerY + std::sin(angle) * radius * 0.7f;

        const bool  sel   = (i == m_selected);
        const ImU32 col   = m_slots[i].available
                            ? (sel ? IM_COL32(255, 220, 40, 255) : IM_COL32(200, 200, 200, 200))
                            : IM_COL32(80, 80, 80, 160);

        dl->AddCircleFilled({ lx, ly }, 18.0f, sel ? IM_COL32(60, 60, 0, 200) : IM_COL32(40, 40, 40, 200));
        dl->AddText({ lx - 12, ly - 7 }, col, m_slots[i].label.c_str());
    }

    // Confirm check (caller polls IsOpen() + SelectedIndex() and handles confirm).
    return -1; // caller confirms explicitly
}

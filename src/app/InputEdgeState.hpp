// ============================================================
// FILE: src/app/InputEdgeState.hpp
// SYSTEM: App
// ROLE: app startup/shutdown wiring and frame orchestration
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: InputEdgeState module behavior and local implementation details.
// ============================================================

#pragma once
// InputEdgeState.hpp
// Tracks edge-trigger key/button inputs so actions fire once per press.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

namespace InputEdge
{
struct State
{
    bool wasTDown       = false;
    bool wasGDown       = false;
    bool wasEscDown     = false;
    bool wasF1Down      = false;
    bool wasF5Down      = false;
    bool wasLButtonDown = false;
};

inline bool IsDown(int keyCode)
{
    return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}

inline bool PollEdgeAndUpdate(bool isDown, bool& wasDown)
{
    bool pressed = isDown && !wasDown;
    wasDown = isDown;
    return pressed;
}

inline bool PollEscapePressed(State& state)
{
    return PollEdgeAndUpdate(IsDown(VK_ESCAPE), state.wasEscDown);
}

inline bool PollF1Pressed(State& state)
{
    return PollEdgeAndUpdate(IsDown(VK_F1), state.wasF1Down);
}

inline bool PollF5Pressed(State& state)
{
    return PollEdgeAndUpdate(IsDown(VK_F5), state.wasF5Down);
}

inline bool PollTPressed(State& state)
{
    return PollEdgeAndUpdate(IsDown('T'), state.wasTDown);
}

inline bool PollGPressed(State& state)
{
    return PollEdgeAndUpdate(IsDown('G'), state.wasGDown);
}

inline bool PollLeftButtonClicked(State& state)
{
    return PollEdgeAndUpdate(IsDown(VK_LBUTTON), state.wasLButtonDown);
}
}

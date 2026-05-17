// ============================================================
// FILE: src/app/CursorModeController.hpp
// SYSTEM: CursorModeController.hpp
// SYSTEM: app startup/shutdown wiring and frame orchestration

#pragma once
// CursorModeController.hpp
// Owns cursor visibility state and placement-mode mouse recenter transitions.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

namespace CursorMode
{
struct State
{
    bool cursorVisible    = false;
    bool prevMouseLookEnabled = false;
};

inline void ApplyCursorVisibility(State& state, bool wantCursorVisible)
{
    if (wantCursorVisible == state.cursorVisible)
        return;

    if (wantCursorVisible)
    {
        // Ensure visible regardless of current internal ShowCursor counter.
        while (ShowCursor(TRUE) < 0) {}
    }
    else
    {
        // Ensure hidden regardless of current internal ShowCursor counter.
        while (ShowCursor(FALSE) >= 0) {}
    }

    state.cursorVisible = wantCursorVisible;
}

inline void HandleMouseLookTransition(State& state,
    bool allowMouseLook,
    const POINT& centerPoint,
    bool& inOutFirstFrame)
{
    // Detect the moment mouse-look turns ON again so the old cursor position
    // does not create one large camera delta.
    if (!state.prevMouseLookEnabled && allowMouseLook)
    {
        SetCursorPos(centerPoint.x, centerPoint.y);
        inOutFirstFrame = true;
    }

    state.prevMouseLookEnabled = allowMouseLook;
}
}

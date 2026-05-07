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
    bool prevEditorActive = false;
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

inline void HandlePlacementModeTransition(State& state,
                                          bool editorActive,
                                          const POINT& centerPoint,
                                          bool& inOutFirstFrame)
{
    // Detect the moment Placement Mode turns OFF so we can reset mouse baseline.
    if (state.prevEditorActive && !editorActive)
    {
        // Re-center cursor and skip the first mouse-look delta to avoid a jump.
        SetCursorPos(centerPoint.x, centerPoint.y);
        inOutFirstFrame = true;
    }
    state.prevEditorActive = editorActive;
}
}

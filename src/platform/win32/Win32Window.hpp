#pragma once
#include <windows.h>

// A simple class for creating and managing a Windows window.
class Win32Window
{
public:
    // Optional hook so subsystems (e.g. ImGui) can receive Win32 messages.
    // Set this before the message loop starts.  If the hook returns non-zero
    // the message is considered consumed and the default handler is skipped.
    using WndProcHook = LRESULT(*)(HWND, UINT, WPARAM, LPARAM);

    Win32Window();
    bool Create(int width, int height, const wchar_t* windowTitle);
    void Close();
    bool ProcessEvents();
    HWND GetHandle() const;
    int GetWidth() const;
    int GetHeight() const;

    // Register an optional message hook (e.g. ImGuiLayer::WndProcHook).
    void SetWndProcHook(WndProcHook fn) { wndProcHook = fn; }

private:
    static LRESULT CALLBACK SetupWindowProc(HWND, UINT, WPARAM, LPARAM);
    static LRESULT CALLBACK MainWindowProc(HWND, UINT, WPARAM, LPARAM);
    LRESULT HandleMessage(HWND, UINT, WPARAM, LPARAM);

    HWND windowHandle;
    int windowWidth;
    int windowHeight;
    WndProcHook wndProcHook = nullptr;
};
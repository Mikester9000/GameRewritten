#pragma once
#include <windows.h>

// A simple class for creating and managing a Windows window.
class Win32Window
{
public:
    Win32Window();
    bool Create(int width, int height, const wchar_t* windowTitle);
    void Close();
    bool ProcessEvents();
    HWND GetHandle() const;
    int GetWidth() const;
    int GetHeight() const;

private:
    static LRESULT CALLBACK SetupWindowProc(HWND, UINT, WPARAM, LPARAM);
    static LRESULT CALLBACK MainWindowProc(HWND, UINT, WPARAM, LPARAM);
    LRESULT HandleMessage(HWND, UINT, WPARAM, LPARAM);

    HWND windowHandle;
    int windowWidth;
    int windowHeight;
};
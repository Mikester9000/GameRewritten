#include "Win32Window.hpp"

Win32Window::Win32Window()
    : windowHandle(nullptr), windowWidth(0), windowHeight(0) {
}

bool Win32Window::Create(int width, int height, const wchar_t* windowTitle)
{
    windowWidth = width;
    windowHeight = height;

    HINSTANCE appInstance = GetModuleHandleW(nullptr);

    WNDCLASSW windowClass{};
    windowClass.lpfnWndProc = &Win32Window::SetupWindowProc;
    windowClass.hInstance = appInstance;
    windowClass.lpszClassName = L"Win32WindowClass";
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);

    if (!RegisterClassW(&windowClass))
        return false;

    RECT area{ 0, 0, width, height };
    AdjustWindowRect(&area, WS_OVERLAPPEDWINDOW, FALSE);

    windowHandle = CreateWindowExW(
        0,
        windowClass.lpszClassName,
        windowTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        area.right - area.left, area.bottom - area.top,
        nullptr,
        nullptr,
        appInstance,
        this
    );

    if (!windowHandle)
        return false;

    ShowWindow(windowHandle, SW_SHOW);
    UpdateWindow(windowHandle);
    return true;
}

void Win32Window::Close()
{
    if (windowHandle)
    {
        DestroyWindow(windowHandle);
        windowHandle = nullptr;
    }
}

bool Win32Window::ProcessEvents()
{
    MSG message{};
    while (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE))
    {
        if (message.message == WM_QUIT)
            return false;

        TranslateMessage(&message);
        DispatchMessageW(&message);
    }
    return true;
}

HWND Win32Window::GetHandle() const { return windowHandle; }
int Win32Window::GetWidth() const { return windowWidth; }
int Win32Window::GetHeight() const { return windowHeight; }

LRESULT CALLBACK Win32Window::SetupWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    if (msg == WM_NCCREATE)
    {
        const CREATESTRUCTW* createInfo = reinterpret_cast<const CREATESTRUCTW*>(lparam);
        Win32Window* window = reinterpret_cast<Win32Window*>(createInfo->lpCreateParams);

        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
        SetWindowLongPtrW(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32Window::MainWindowProc));

        window->windowHandle = hwnd;
        return window->HandleMessage(hwnd, msg, wparam, lparam);
    }
    return DefWindowProcW(hwnd, msg, wparam, lparam);
}

LRESULT CALLBACK Win32Window::MainWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    Win32Window* window = reinterpret_cast<Win32Window*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
    return window->HandleMessage(hwnd, msg, wparam, lparam);
}

LRESULT Win32Window::HandleMessage(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    // Give the registered hook (e.g. ImGui) first chance to consume the message.
    if (wndProcHook)
    {
        LRESULT hookResult = wndProcHook(hwnd, msg, wparam, lparam);
        if (hookResult)
            return hookResult;
    }

    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProcW(hwnd, msg, wparam, lparam);
    }
}
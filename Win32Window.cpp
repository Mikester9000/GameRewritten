// Win32Window.cpp
// A tiny wrapper around a Win32 window.
// For beginners: this code creates a window and processes Windows messages.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <cstdint>

class Win32Window
{
public:
    Win32Window() = default;

    bool Create(int width, int height, const wchar_t* title)
    {
        m_width = width;
        m_height = height;

        HINSTANCE instance = GetModuleHandleW(nullptr);

        WNDCLASSW wc{};
        wc.lpfnWndProc = &Win32Window::WndProcSetup;
        wc.hInstance = instance;
        wc.lpszClassName = L"MyEngineSeedWindowClass";
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

        if (!RegisterClassW(&wc))
        {
            // RegisterClassW can fail if you run twice in some debugging scenarios,
            // but typically it will succeed on first run.
            return false;
        }

        // Adjust window size so the *client area* matches width/height.
        RECT r{ 0, 0, width, height };
        AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, FALSE);

        m_hwnd = CreateWindowExW(
            0,
            wc.lpszClassName,
            title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            r.right - r.left, r.bottom - r.top,
            nullptr,
            nullptr,
            instance,
            this // pass 'this' pointer so we can store it in the window later
        );

        if (!m_hwnd)
            return false;

        ShowWindow(m_hwnd, SW_SHOW);
        UpdateWindow(m_hwnd);
        return true;
    }

    void Destroy()
    {
        if (m_hwnd)
        {
            DestroyWindow(m_hwnd);
            m_hwnd = nullptr;
        }
    }

    // Returns false when the user closes the window.
    bool PumpMessages()
    {
        MSG msg{};
        while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                return false;

            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
        return true;
    }

    HWND Handle() const { return m_hwnd; }
    int  Width()  const { return m_width; }
    int  Height() const { return m_height; }

private:
    // Step 1: During WM_NCCREATE, Windows calls this proc.
    // We use it to attach our C++ object pointer to the HWND.
    static LRESULT CALLBACK WndProcSetup(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        if (msg == WM_NCCREATE)
        {
            const CREATESTRUCTW* cs = reinterpret_cast<const CREATESTRUCTW*>(lparam);
            Win32Window* window = reinterpret_cast<Win32Window*>(cs->lpCreateParams);

            // Store pointer on the window so future messages can get it.
            SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
            SetWindowLongPtrW(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32Window::WndProcThunk));

            window->m_hwnd = hwnd;
            return window->WndProc(hwnd, msg, wparam, lparam);
        }

        return DefWindowProcW(hwnd, msg, wparam, lparam);
    }

    // Step 2: After setup, all messages go through this thunk.
    static LRESULT CALLBACK WndProcThunk(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        Win32Window* window = reinterpret_cast<Win32Window*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
        return window->WndProc(hwnd, msg, wparam, lparam);
    }

    // Step 3: Instance method handles messages.
    LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

            // (Optional) If you want to handle resizing later, you’d catch WM_SIZE here.
        default:
            return DefWindowProcW(hwnd, msg, wparam, lparam);
        }
    }

private:
    HWND m_hwnd = nullptr;
    int  m_width = 0;
    int  m_height = 0;
};
// main.cpp
// Creates the window, initializes D3D11, runs a simple game loop that clears the screen.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cmath>
#include <cstdint>

// We defined the classes in the other .cpp files.
// For this beginner seed, the simplest way is to forward-declare them here
// and rely on the linker. (Later we will convert to headers.)
class Win32Window;
class D3D11Renderer;

// Tell the compiler these classes exist somewhere else.
extern "C" __declspec(dllimport) int __stdcall MessageBoxW(HWND, LPCWSTR, LPCWSTR, unsigned int);

// --- Hacky but simple approach for day 1 ---
// We include the .cpp files to avoid headers for now.
// This is NOT how big projects do it, but it's a good beginner stepping stone.
#include "Win32Window.cpp"
#include "D3D11Renderer.cpp"

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    Win32Window window;
    if (!window.Create(1280, 720, L"My Engine Seed (D3D11)"))
    {
        MessageBoxW(nullptr, L"Failed to create window.", L"Error", 0);
        return 1;
    }

    D3D11Renderer renderer;
    if (!renderer.Init(window.Handle(), window.Width(), window.Height()))
    {
        MessageBoxW(nullptr, L"Failed to initialize D3D11.", L"Error", 0);
        return 1;
    }

    // Simple loop: process messages + render frames.
    float t = 0.0f;
    while (window.PumpMessages())
    {
        // Animate the clear color so you can see it is updating.
        t += 0.01f;
        float r = 0.2f + 0.2f * sinf(t);
        float g = 0.2f + 0.2f * sinf(t * 1.7f);
        float b = 0.3f + 0.2f * sinf(t * 2.3f);

        renderer.Clear(r, g, b, 1.0f);
        renderer.DrawTriangle();
        renderer.Present();
        Sleep(1); // tiny sleep so we don't peg CPU at 100%
    }

    renderer.Shutdown();
    window.Destroy();
    return 0;
}
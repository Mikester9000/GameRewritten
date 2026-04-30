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
#include "C:\Users\m_man\source\repos\GameRewritten\src\platform\win32\Win32Window.hpp"
#include "C:\Users\m_man\source\repos\GameRewritten\src\rendering\d3d11\D3D11Renderer.hpp"

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    Win32Window window;
    if (!window.Create(1280, 720, L"My Engine Seed (D3D11)"))
    {
        MessageBoxW(nullptr, L"Failed to create window.", L"Error", 0);
        return 1;
    }

    D3D11Renderer renderer;
    if (!renderer.Initialize(window.GetHandle(), window.GetWidth(), window.GetHeight()))
    {
        MessageBoxW(nullptr, L"Failed to initialize D3D11.", L"Error", 0);
        return 1;
    }

    // Simple loop: process messages + render frames.
    float t = 0.0f;
    float yaw = 0.0f, pitch = 0.0f;
    renderer.SetCameraPosition(0.0f, 0.0f, -3.0f);
    renderer.SetCameraRotation(0.0f, 0.0f);
    // Center the mouse before the loop
    RECT windowRect;
    GetClientRect(window.GetHandle(), &windowRect);
    POINT centerPoint{ (windowRect.right - windowRect.left) / 2, (windowRect.bottom - windowRect.top) / 2 };
    ClientToScreen(window.GetHandle(), &centerPoint);
    SetCursorPos(centerPoint.x, centerPoint.y);

    bool firstFrame = true;

    while (window.ProcessEvents())
    {
        // Check if the window is active
        if (GetForegroundWindow() != window.GetHandle()) {
            continue; // Skip the loop if the window is not active
        }

        // Exit the program when ESC is pressed
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break; // Exit the main loop
        }

       
        // Animate the clear color so you can see it is updating.
        t += 0.01f;
        float r = 0.2f + 0.2f * sinf(t);
        float g = 0.2f + 0.2f * sinf(t * 1.7f);
        float b = 0.3f + 0.2f * sinf(t * 2.3f);

        // Mouse look
        int mouseDeltaX = 0, mouseDeltaY = 0;
        POINT mouse;
        GetCursorPos(&mouse);

        if (!firstFrame) {
            mouseDeltaX = mouse.x - centerPoint.x;
            mouseDeltaY = mouse.y - centerPoint.y;
            yaw += mouseDeltaX * 0.005f;
            pitch -= mouseDeltaY * 0.005f;
            if (pitch > 1.5f) pitch = 1.5f;
            if (pitch < -1.5f) pitch = -1.5f;
        }
        SetCursorPos(centerPoint.x, centerPoint.y);
        firstFrame = false;

        renderer.SetCameraRotation(yaw, pitch);
        

        // Camera movement
        float x, y, z;
        renderer.GetCameraPosition(x, y, z);

        float forwardX = sinf(yaw);
        float forwardZ = cosf(yaw);
        float rightX = cosf(yaw);
        float rightZ = -sinf(yaw);

        // Move the camera based on input
        if (GetAsyncKeyState('W') & 0x8000) renderer.SetCameraPosition(x + forwardX * 0.05f, y, z + forwardZ * 0.05f); // Move forward
        if (GetAsyncKeyState('S') & 0x8000) renderer.SetCameraPosition(x - forwardX * 0.05f, y, z - forwardZ * 0.05f); // Move backward
        if (GetAsyncKeyState('A') & 0x8000) renderer.SetCameraPosition(x - rightX * 0.05f, y, z - rightZ * 0.05f); // Move left
        if (GetAsyncKeyState('D') & 0x8000) renderer.SetCameraPosition(x + rightX * 0.05f, y, z + rightZ * 0.05f); // Move right

        // Gravity and jumping
        if (!renderer.GetIsGrounded()) {
            renderer.SetCameraVelocityY(renderer.GetCameraVelocityY() - 0.01f); // Apply gravity
        }
        else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            renderer.SetCameraVelocityY(0.2f); // Jump when on the ground
            renderer.SetIsGrounded(false);
        }
        // Limit falling speed (terminal velocity)
        if (renderer.GetCameraVelocityY() < -0.2f) {
            renderer.SetCameraVelocityY(-0.2f); // Max falling speed
        }
        // Update the camera's Y position
        renderer.GetCameraPosition(x, y, z);
        y += renderer.GetCameraVelocityY();

        // Check if the camera is on the ground
        if (y <= 0.0f) {
            y = 0.0f; // Keep the camera on the ground
            renderer.SetCameraVelocityY(-0.05f);
            renderer.SetIsGrounded(true);
        }

        renderer.SetCameraPosition(x, y, z);
        renderer.ClearScreen(r, g, b, 1.0f);
        renderer.DrawRotatingTriangle();
        renderer.PresentFrame();
        Sleep(1); // tiny sleep so we don't peg CPU at 100%
    }

    renderer.Shutdown();
    window.Close();
    return 0;
}
// ============================================================
// FILE: src/ui/ImGuiLayer.hpp
// SYSTEM: ImGuiLayer.hpp
// SYSTEM: HUD, menus, overlays, and editor tool panels

#pragma once
// ImGuiLayer.hpp
// Wraps Dear ImGui context creation, Win32 + D3D11 backend init/shutdown,
// and per-frame begin/end calls.  All menu state (pause, debug) lives here.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>

class D3D11Renderer;
class AudioManager;

class ImGuiLayer
{
public:
    ImGuiLayer();

    // Call once after D3D11 device and swap chain are ready.
    bool Initialize(HWND hwnd,
                    ID3D11Device*        device,
                    ID3D11DeviceContext* context);

    // Forward Win32 messages so ImGui can handle mouse/keyboard.
    // Returns true if ImGui consumed the message (caller should skip its own handling).
    bool HandleMessage(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

    // Call at the start of each frame (before any ImGui::* calls).
    void BeginFrame();

    // Call after all ImGui::* drawing calls, before Present.
    void EndFrame();

    // Call before renderer shutdown.
    void Shutdown();

    // Toggle helpers (called from the game loop key handling).
    void TogglePauseMenu()  { showPauseMenu  = !showPauseMenu;  }
    void ToggleDebugOverlay(){ showDebugOverlay = !showDebugOverlay; }

    bool IsPauseMenuOpen()  const { return showPauseMenu; }
    bool IsDebugOverlayOpen() const { return showDebugOverlay; }

    // The game loop sets these each frame so the debug overlay can display them.
    void SetFrameStats(float fps, float dt) { currentFPS = fps; currentDT = dt; }
    void SetRendererRef(D3D11Renderer* renderer)
    {
        if (m_renderer != renderer)
            m_lightUiInitialized = false;
        m_renderer = renderer;
    }
    void SetCameraInfo(float x, float y, float z, float yaw, float pitch)
    {
        camX = x; camY = y; camZ = z; camYaw = yaw; camPitch = pitch;
    }
    void SetAudioManager(AudioManager* audioManager) { m_audioManager = audioManager; }

    // Returns true when the user chose "Quit" from the pause menu.
    bool WantsQuit() const { return wantsQuit; }

    // Returns true when the user chose "Resume" or dismissed the pause menu.
    bool WantsResume() const { return wantsResume; }

    // Reset transient flags — call once after reading them each frame.
    void ClearFrameFlags() { wantsQuit = false; wantsResume = false; }

    // Draw hitbox AABBs, enemy detection/attack radii, and state labels as
    // a screen-space overlay using ImGui's foreground draw list.
    // Call inside the ImGui frame (between BeginFrame and EndFrame).
    // Does nothing when showCombatDebug is false.
    void DrawCombatDebug(
        const class CombatSystem& combatSystem,
        const class EnemyActor*   enemies,
        int                       enemyCount,
        float camX,    float camY,    float camZ,
        float yaw,     float pitch,
        float vpW,     float vpH);

    void DrawLockOnMarker(
        const class EnemyActor* target,
        float camX, float camY, float camZ,
        float yaw,  float pitch,
        float vpW,  float vpH);

    // Toggled by the checkbox inside DrawDebugOverlay.
    bool showCombatDebug = false;

    // Static WndProc hook — pass to Win32Window::SetWndProcHook() after Initialize().
    // This forwards Win32 messages to the ImGui Win32 backend so ImGui receives
    // mouse clicks, keyboard input, etc.
    static LRESULT CALLBACK WndProcHook(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:
    bool initialized = false;

    bool showPauseMenu   = false;
    bool showDebugOverlay = false;

    float currentFPS = 0.0f;
    float currentDT  = 0.0f;
    float camX = 0.0f, camY = 0.0f, camZ = 0.0f;
    float camYaw = 0.0f, camPitch = 0.0f;

    bool wantsQuit   = false;
    bool wantsResume = false;
    D3D11Renderer* m_renderer = nullptr;
    bool  m_lightUiInitialized = false;
    float m_sunDirX = 0.0f;
    float m_sunDirY = -1.0f;
    float m_sunDirZ = 0.0f;
    float m_ambientStrength = 0.25f;
    AudioManager* m_audioManager = nullptr;

    void DrawPauseMenu();
    void DrawDebugOverlay();
};

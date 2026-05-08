// ImGuiLayer.cpp
// Manages Dear ImGui context, Win32 + D3D11 backends, and draws the in-game UI.
// Esc  → toggle pause menu (Resume / Options / Quit)
// F1   → toggle debug overlay (FPS, dt, camera)

#include "ImGuiLayer.hpp"
#include <Windows.h>
#include "../rendering/d3d11/D3D11Renderer.hpp"

// ImGui core + backends (vendored under third_party/)
#include "../../third_party/imgui/imgui.h"
#include "../../third_party/imgui/backends/imgui_impl_win32.h"
#include "../../third_party/imgui/backends/imgui_impl_dx11.h"


#include "logger/Logger.hpp"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
    HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
ImGuiLayer::ImGuiLayer() = default;

bool ImGuiLayer::Initialize(HWND hwnd,
                             ID3D11Device*        device,
                             ID3D11DeviceContext* context)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    // Enable keyboard navigation; disable INI file so we don't write to disk.
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.IniFilename = nullptr;

    // Dark theme — feels more "game-like".
    ImGui::StyleColorsDark();

    // Scale UI slightly for readability on 1080p.
    ImGui::GetStyle().ScaleAllSizes(1.1f);

    if (!ImGui_ImplWin32_Init(hwnd))
    {
        LOG_ERROR("ImGuiLayer: ImGui_ImplWin32_Init failed.");
        ImGui::DestroyContext();
        return false;
    }

    if (!ImGui_ImplDX11_Init(device, context))
    {
        LOG_ERROR("ImGuiLayer: ImGui_ImplDX11_Init failed.");
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();
        return false;
    }

    initialized = true;
    LOG_INFO("ImGuiLayer initialized.");
    return true;
}

bool ImGuiLayer::HandleMessage(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    if (!initialized)
        return false;

    // Let the Win32 backend process the message.
    if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam))
        return true;

    // If the pause menu is open, capture mouse/keyboard so they don't affect
    // game input (the game loop already skips movement when IsPauseMenuOpen()).
    ImGuiIO& io = ImGui::GetIO();
    if (showPauseMenu && (io.WantCaptureMouse || io.WantCaptureKeyboard))
        return true;

    return false;
}

void ImGuiLayer::BeginFrame()
{
    if (!initialized)
        return;

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::EndFrame()
{
    if (!initialized)
        return;

    if (showPauseMenu)
        DrawPauseMenu();

    if (showDebugOverlay)
        DrawDebugOverlay();

    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::Shutdown()
{
    if (!initialized)
        return;

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    initialized = false;
    LOG_INFO("ImGuiLayer shut down.");
}

// static
LRESULT CALLBACK ImGuiLayer::WndProcHook(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    return ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
}

// ---------------------------------------------------------------------------
// Private UI drawing helpers
// ---------------------------------------------------------------------------

void ImGuiLayer::DrawPauseMenu()
{
    // Centre the window on screen.
    ImGuiIO& io = ImGui::GetIO();
    float winW = 260.0f, winH = 160.0f;
    ImGui::SetNextWindowPos(
        ImVec2((io.DisplaySize.x - winW) * 0.5f,
               (io.DisplaySize.y - winH) * 0.5f),
        ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(winW, winH), ImGuiCond_Always);

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize    |
        ImGuiWindowFlags_NoMove      |
        ImGuiWindowFlags_NoCollapse  |
        ImGuiWindowFlags_NoTitleBar;

    if (ImGui::Begin("## PauseMenu", nullptr, flags))
    {
        // Title text — centred manually.
        float textW = ImGui::CalcTextSize("PAUSED").x;
        ImGui::SetCursorPosX((winW - textW) * 0.5f);
        ImGui::Text("PAUSED");
        ImGui::Separator();
        ImGui::Spacing();

        // Buttons — full width inside the window.
        if (ImGui::Button("Resume", ImVec2(-1.0f, 0.0f)))
        {
            showPauseMenu = false;
            wantsResume   = true;
        }

        ImGui::Spacing();

        // Simple inline options (placeholder).
        static bool showOptions = false;
        if (ImGui::Button("Options", ImVec2(-1.0f, 0.0f)))
            showOptions = !showOptions;

        if (showOptions)
        {
            ImGui::Indent();
            static float mouseSpeed = 1.0f;
            ImGui::SliderFloat("Mouse Speed", &mouseSpeed, 0.1f, 5.0f);
            ImGui::Unindent();
        }

        ImGui::Spacing();

        if (ImGui::Button("Quit", ImVec2(-1.0f, 0.0f)))
            wantsQuit = true;
    }
    ImGui::End();
}

void ImGuiLayer::DrawDebugOverlay()
{
    // Small semi-transparent overlay in the top-left corner.
    ImGui::SetNextWindowPos(ImVec2(10.0f, 10.0f), ImGuiCond_Always);
    ImGui::SetNextWindowBgAlpha(0.55f);

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration      |
        ImGuiWindowFlags_AlwaysAutoResize  |
        ImGuiWindowFlags_NoSavedSettings   |
        ImGuiWindowFlags_NoFocusOnAppearing|
        ImGuiWindowFlags_NoNav             |
        ImGuiWindowFlags_NoMove;

    if (ImGui::Begin("## DebugOverlay", nullptr, flags))
    {
        ImGui::Text("FPS  : %.1f", currentFPS);
        ImGui::Text("dt   : %.4f s", currentDT);
        ImGui::Separator();
        ImGui::Text("Camera");
        ImGui::Text("  pos  (%.2f, %.2f, %.2f)", camX, camY, camZ);
        ImGui::Text("  yaw  %.3f  pitch %.3f", camYaw, camPitch);
        if (m_renderer)
        {
            if (!m_lightUiInitialized)
            {
                m_renderer->GetSunDirection(m_sunDirX, m_sunDirY, m_sunDirZ);
                m_ambientStrength = m_renderer->GetAmbientStrength();
                m_lightUiInitialized = true;
            }

            ImGui::Separator();
            ImGui::Text("Sun Light");
            bool sunChanged = false;
            sunChanged |= ImGui::SliderFloat("Sun Dir X", &m_sunDirX, -1.0f, 1.0f);
            sunChanged |= ImGui::SliderFloat("Sun Dir Y", &m_sunDirY, -1.0f, 1.0f);
            sunChanged |= ImGui::SliderFloat("Sun Dir Z", &m_sunDirZ, -1.0f, 1.0f);
            if (sunChanged)
            {
                m_renderer->SetSunDirection(m_sunDirX, m_sunDirY, m_sunDirZ);
                m_renderer->GetSunDirection(m_sunDirX, m_sunDirY, m_sunDirZ);
            }

            if (ImGui::SliderFloat("Ambient", &m_ambientStrength, 0.0f, 1.0f))
                m_renderer->SetAmbientStrength(m_ambientStrength);
        }
        ImGui::Separator();
        ImGui::TextDisabled("[F1] hide overlay");
    }
    ImGui::End();
}

// ImGuiLayer.cpp
// Manages Dear ImGui context, Win32 + D3D11 backends, and draws the in-game UI.
// Esc  → toggle pause menu (Resume / Options / Quit)
// F1   → toggle debug overlay (FPS, dt, camera, combat debug toggle)

#include "ImGuiLayer.hpp"
#include <Windows.h>
#include "../audio/AudioManager.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../game/actors/EnemyActor.hpp"
#include "../game/actors/EnemyState.hpp"
#include "../game/combat/CombatSystem.hpp"

// ImGui core + backends (vendored under third_party/)
#include "../../third_party/imgui/imgui.h"
#include "../../third_party/imgui/backends/imgui_impl_win32.h"
#include "../../third_party/imgui/backends/imgui_impl_dx11.h"

#include "logger/Logger.hpp"
#include <cmath>
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
    HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// ---------------------------------------------------------------------------
// World-to-screen projection helper for debug overlays.
// Mirrors the renderer's view transform (yaw then pitch, 45-degree FOV).
// Returns false if the point is behind the camera.
// ---------------------------------------------------------------------------
static bool WorldToScreen(
    float wx, float wy, float wz,
    float camX, float camY, float camZ,
    float yaw, float pitch,
    float vpW, float vpH,
    float& outSx, float& outSy)
{
    // Translate relative to camera.
    float dx = wx - camX;
    float dy = wy - camY;
    float dz = wz - camZ;

    // Rotate by yaw (Y axis).
    float cosY = cosf(-yaw);
    float sinY = sinf(-yaw);
    float rx =  dx * cosY + dz * sinY;
    float ry =  dy;
    float rz = -dx * sinY + dz * cosY;

    // Rotate by pitch (X axis).
    float cosP = cosf(-pitch);
    float sinP = sinf(-pitch);
    float fx = rx;
    float fy =  ry * cosP - rz * sinP;
    float fz =  ry * sinP + rz * cosP;

    // Clip anything behind the near plane.
    if (fz <= 0.1f)
        return false;

    // Project — matches the 45-degree FOV used by the renderer.
    static constexpr float kPi = 3.14159265f;
    float fovScale = 1.0f / tanf(kPi / 8.0f); // tan(FOV/2) for 45 deg
    outSx = (vpW * 0.5f) + (fx / fz) * fovScale * (vpH * 0.5f);
    outSy = (vpH * 0.5f) - (fy / fz) * fovScale * (vpH * 0.5f);
    return true;
}

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
            if (m_audioManager)
            {
                float bgmVolume = m_audioManager->GetBGMVolume();
                if (ImGui::SliderFloat("BGM Volume (next play)", &bgmVolume, 0.0f, 1.0f))
                    m_audioManager->SetBGMVolume(bgmVolume);
                ImGui::TextDisabled("tp::Audio BGM is one-shot for now.");
            }
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
        ImGui::Checkbox("Show Combat Debug", &showCombatDebug);
        ImGui::Separator();
        ImGui::TextDisabled("[F1] hide overlay");
    }
    ImGui::End();
}

// ---------------------------------------------------------------------------
// DrawCombatDebug — screen-space debug overlay for hitboxes, enemy radii,
// and enemy combat state labels.  Uses ImGui foreground draw list so it
// renders on top of everything with zero GPU overhead when off.
// ---------------------------------------------------------------------------
void ImGuiLayer::DrawCombatDebug(
    const CombatSystem& combatSystem,
    const EnemyActor*   enemies,
    int                 enemyCount,
    float playerX, float playerY, float playerZ,
    float camX,    float camY,    float camZ,
    float yaw,     float pitch,
    float vpW,     float vpH)
{
    if (!showCombatDebug)
        return;
    if (!ImGui::GetCurrentContext())
        return;

    ImDrawList* dl = ImGui::GetForegroundDrawList();

    // --- Active player hitboxes (red outlined rectangles) ---
    for (const HitBox& hb : combatSystem.GetActiveHitBoxes())
    {
        float sx, sy;
        if (!WorldToScreen(hb.x, hb.y, hb.z, camX, camY, camZ, yaw, pitch, vpW, vpH, sx, sy))
            continue;

        // Estimate screen half-extents by projecting offset points.
        // We project a right-edge and a top-edge point, then measure horizontal
        // and vertical distances from center.  The cross-axis components
        // (rightEdgeScreenY and topEdgeScreenX) are byproducts of the projection
        // and not needed for the width/height calculation.
        float srx;
        [[maybe_unused]] float rightEdgeScreenY;
        [[maybe_unused]] float topEdgeScreenX;
        float sty;
        bool hasRight = WorldToScreen(hb.x + hb.halfX, hb.y, hb.z,
                                      camX, camY, camZ, yaw, pitch, vpW, vpH,
                                      srx, rightEdgeScreenY);
        bool hasTop   = WorldToScreen(hb.x, hb.y + hb.halfY, hb.z,
                                      camX, camY, camZ, yaw, pitch, vpW, vpH,
                                      topEdgeScreenX, sty);
        float hw = hasRight ? fabsf(srx - sx) : 18.0f;
        float hh = hasTop   ? fabsf(sty - sy) : 28.0f;

        dl->AddRect(ImVec2(sx - hw, sy - hh), ImVec2(sx + hw, sy + hh),
                    IM_COL32(255, 50, 50, 220), 0.0f, 0, 2.0f);
        dl->AddText(ImVec2(sx - 10.0f, sy - hh - 16.0f),
                    IM_COL32(255, 50, 50, 255), "ATK");
    }

    // --- Per-enemy overlays ---
    static constexpr int kCirclePoints = 8;
    static constexpr float kTwoPi = 6.28318f;

    for (int i = 0; i < enemyCount; ++i)
    {
        const EnemyActor& e = enemies[i];

        // Skip dead enemies — they have no relevant radii or state to show.
        if (e.isDead)
            continue;

        // Project enemy position for state label and "!" indicator.
        float ex, ey;
        const bool enemyVisible = WorldToScreen(e.x, e.y + 2.2f, e.z,
                                                camX, camY, camZ,
                                                yaw, pitch, vpW, vpH, ex, ey);

        // --- Detection radius — yellow circle approximation ---
        {
            float prevSx = 0.0f, prevSy = 0.0f;
            bool prevVisible = false;
            for (int p = 0; p <= kCirclePoints; ++p)
            {
                float angle = (p % kCirclePoints) * kTwoPi / kCirclePoints;
                float px2   = e.x + EnemyActor::kDetectRadius * sinf(angle);
                float pz2   = e.z + EnemyActor::kDetectRadius * cosf(angle);
                float sx2, sy2;
                bool vis = WorldToScreen(px2, e.y, pz2,
                                         camX, camY, camZ,
                                         yaw, pitch, vpW, vpH, sx2, sy2);
                if (p > 0 && prevVisible && vis)
                {
                    dl->AddLine(ImVec2(prevSx, prevSy), ImVec2(sx2, sy2),
                                IM_COL32(230, 220, 30, 160), 1.0f);
                }
                prevSx      = sx2;
                prevSy      = sy2;
                prevVisible = vis;
            }
        }

        // "DETECT" label above enemy.
        if (enemyVisible)
        {
            dl->AddText(ImVec2(ex - 22.0f, ey - 32.0f),
                        IM_COL32(230, 220, 30, 200), "DETECT");
        }

        // --- Attack radius — orange circle approximation ---
        {
            float prevSx = 0.0f, prevSy = 0.0f;
            bool prevVisible = false;
            for (int p = 0; p <= kCirclePoints; ++p)
            {
                float angle = (p % kCirclePoints) * kTwoPi / kCirclePoints;
                float px2   = e.x + EnemyActor::kAttackRadius * sinf(angle);
                float pz2   = e.z + EnemyActor::kAttackRadius * cosf(angle);
                float sx2, sy2;
                bool vis = WorldToScreen(px2, e.y, pz2,
                                         camX, camY, camZ,
                                         yaw, pitch, vpW, vpH, sx2, sy2);
                if (p > 0 && prevVisible && vis)
                {
                    dl->AddLine(ImVec2(prevSx, prevSy), ImVec2(sx2, sy2),
                                IM_COL32(255, 160, 40, 180), 1.5f);
                }
                prevSx      = sx2;
                prevSy      = sy2;
                prevVisible = vis;
            }
        }

        if (!enemyVisible)
            continue;

        // --- State label ---
        const char* stateStr  = "PATROL";
        ImU32       stateCol  = IM_COL32(255, 255, 255, 240);

        switch (e.state)
        {
            case EnemyState::Patrol: stateStr = "PATROL"; stateCol = IM_COL32(255, 255, 255, 240); break;
            case EnemyState::Chase:  stateStr = "CHASE";  stateCol = IM_COL32(230, 220, 30,  240); break;
            case EnemyState::Attack: stateStr = "ATTACK"; stateCol = IM_COL32(255, 160, 40,  240); break;
            case EnemyState::Hit:    stateStr = "HIT";    stateCol = IM_COL32(255, 80,  80,  240); break;
            case EnemyState::Dead:   stateStr = "DEAD";   stateCol = IM_COL32(150, 150, 150, 200); break;
        }

        dl->AddText(ImVec2(ex - 18.0f, ey), stateCol, stateStr);

        // --- Pending attack indicator ---
        if (e.pendingAttack)
        {
            float bsx, bsy;
            if (WorldToScreen(e.x, e.y + 3.0f, e.z,
                              camX, camY, camZ, yaw, pitch, vpW, vpH, bsx, bsy))
            {
                dl->AddText(ImVec2(bsx - 4.0f, bsy),
                            IM_COL32(255, 30, 30, 255), "!");
            }
        }
    }
}

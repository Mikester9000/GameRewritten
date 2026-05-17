// ============================================================
// FILE: src/ui/ImGuiLayer.cpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: ImGuiLayer module behavior and local implementation details.
// ============================================================

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
#include <DirectXMath.h>

namespace
{
// Visual tuning for lock marker readability at 720p/1080p:
// marker is placed above enemy torso/head and "LOCK" is centered above it.
constexpr float kLockMarkerHeightOffset = 2.8f;
constexpr float kLockMarkerCircleRadius = 14.0f;
constexpr int   kLockMarkerCircleSegments = 24;
constexpr float kLockMarkerCircleThickness = 2.0f;
constexpr float kLockMarkerTextOffsetX = -22.0f;
constexpr float kLockMarkerTextOffsetY = -30.0f;
}

static bool WorldToScreen(
    float wx, float wy, float wz,
    float camX, float camY, float camZ,
    float yaw, float pitch,
    float vpW, float vpH,
    float& outSx, float& outSy)
{
    // Build the exact same look direction the renderer uses
    float lookDirX = cosf(pitch) * sinf(yaw);
    float lookDirY = sinf(pitch);
    float lookDirZ = cosf(pitch) * cosf(yaw);

    DirectX::XMVECTOR camPos = DirectX::XMVectorSet(camX, camY, camZ, 1.0f);
    DirectX::XMVECTOR camTarget = DirectX::XMVectorSet(camX + lookDirX,
        camY + lookDirY,
        camZ + lookDirZ, 1.0f);
    DirectX::XMVECTOR camUp = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    // Match renderer exactly — LookAtLH, 45 degree FOV, near 0.1, far 2000
    DirectX::XMMATRIX view = DirectX::XMMatrixLookAtLH(camPos, camTarget, camUp);
    DirectX::XMMATRIX proj = DirectX::XMMatrixPerspectiveFovLH(
        DirectX::XM_PIDIV4,
        vpW / vpH,
        0.1f, 2000.0f);

    // DirectXMath uses row vectors: clip = worldPos * view * proj
    // XMMatrixMultiply(A,B) = A*B, XMVector4Transform(v,M) = v*M
    // NO transpose needed here
    DirectX::XMMATRIX viewProj = DirectX::XMMatrixMultiply(view, proj);

    DirectX::XMVECTOR worldPos = DirectX::XMVectorSet(wx, wy, wz, 1.0f);
    DirectX::XMVECTOR clip = DirectX::XMVector4Transform(worldPos, viewProj);

    // W check — behind camera
    float w = DirectX::XMVectorGetW(clip);
    if (w <= 0.0f)
        return false;

    // Perspective divide to NDC
    float ndcX = DirectX::XMVectorGetX(clip) / w;
    float ndcY = DirectX::XMVectorGetY(clip) / w;

    // NDC to screen pixels
    outSx = (ndcX + 1.0f) * 0.5f * vpW;
    outSy = (1.0f - ndcY) * 0.5f * vpH;

    // Cull if off screen
    if (outSx < -50.0f || outSx > vpW + 50.0f) return false;
    if (outSy < -50.0f || outSy > vpH + 50.0f) return false;

    return true;
}
static void DrawProjectedAabb(
    ImDrawList* dl,
    float centerX, float centerY, float centerZ,
    float halfX, float halfY, float halfZ,
    float camX, float camY, float camZ,
    float yaw, float pitch,
    float vpW, float vpH,
    ImU32 color,
    float thickness)
{
    struct ScreenPoint
    {
        float x = 0.0f;
        float y = 0.0f;
        bool  visible = false;
    };

    ScreenPoint pts[8];

    const float minX = centerX - halfX;
    const float maxX = centerX + halfX;
    const float minY = centerY - halfY;
    const float maxY = centerY + halfY;
    const float minZ = centerZ - halfZ;
    const float maxZ = centerZ + halfZ;

    pts[0].visible = WorldToScreen(minX, minY, minZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[0].x, pts[0].y);
    pts[1].visible = WorldToScreen(maxX, minY, minZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[1].x, pts[1].y);
    pts[2].visible = WorldToScreen(maxX, maxY, minZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[2].x, pts[2].y);
    pts[3].visible = WorldToScreen(minX, maxY, minZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[3].x, pts[3].y);

    pts[4].visible = WorldToScreen(minX, minY, maxZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[4].x, pts[4].y);
    pts[5].visible = WorldToScreen(maxX, minY, maxZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[5].x, pts[5].y);
    pts[6].visible = WorldToScreen(maxX, maxY, maxZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[6].x, pts[6].y);
    pts[7].visible = WorldToScreen(minX, maxY, maxZ, camX, camY, camZ, yaw, pitch, vpW, vpH, pts[7].x, pts[7].y);

    const int edges[][2] =
    {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };

    for (const auto& edge : edges)
    {
        const int a = edge[0];
        const int b = edge[1];
        if (!pts[a].visible || !pts[b].visible)
            continue;

        dl->AddLine(
            ImVec2(pts[a].x, pts[a].y),
            ImVec2(pts[b].x, pts[b].y),
            color,
            thickness);
    }
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
                ImGui::TextDisabled("tp::Audio BGM playback is one-shot.");
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
    float camX,    float camY,    float camZ,
    float yaw,     float pitch,
    float vpW,     float vpH)
{
    if (!showCombatDebug)
        return;
    if (!ImGui::GetCurrentContext())
        return;

    ImDrawList* dl = ImGui::GetForegroundDrawList();

    // --- Active player hitboxes (red projected wire boxes) ---
    for (const HitBox& hb : combatSystem.GetActiveHitBoxes())
    {
        DrawProjectedAabb(
            dl,
            hb.x, hb.y, hb.z,
            hb.halfX, hb.halfY, hb.halfZ,
            camX, camY, camZ,
            yaw, pitch,
            vpW, vpH,
            IM_COL32(255, 50, 50, 220),
            2.0f);

        float sx, sy;
        if (WorldToScreen(hb.x, hb.y + hb.halfY + 0.2f, hb.z,
            camX, camY, camZ, yaw, pitch, vpW, vpH, sx, sy))
        {
            dl->AddText(ImVec2(sx - 10.0f, sy - 16.0f),
                IM_COL32(255, 50, 50, 255), "ATK");
        }
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

        // Draw a projected world-space body box so the enemy feels anchored in the world.
        DrawProjectedAabb(
            dl,
            e.x, e.y + 1.0f, e.z,
            0.6f, 1.0f, 0.6f,
            camX, camY, camZ,
            yaw, pitch,
            vpW, vpH,
            IM_COL32(80, 200, 255, 180),
            1.5f);

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
                float px2 = e.x + EnemyActor::kDetectRadius * sinf(angle);
                float pz2 = e.z + EnemyActor::kDetectRadius * cosf(angle);
                float sx2, sy2;
                bool vis = WorldToScreen(px2, e.y, pz2,
                    camX, camY, camZ,
                    yaw, pitch, vpW, vpH, sx2, sy2);
                if (p > 0 && prevVisible && vis)
                {
                    dl->AddLine(ImVec2(prevSx, prevSy), ImVec2(sx2, sy2),
                        IM_COL32(230, 220, 30, 160), 1.0f);
                }
                prevSx = sx2;
                prevSy = sy2;
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
                float px2 = e.x + EnemyActor::kAttackRadius * sinf(angle);
                float pz2 = e.z + EnemyActor::kAttackRadius * cosf(angle);
                float sx2, sy2;
                bool vis = WorldToScreen(px2, e.y, pz2,
                    camX, camY, camZ,
                    yaw, pitch, vpW, vpH, sx2, sy2);
                if (p > 0 && prevVisible && vis)
                {
                    dl->AddLine(ImVec2(prevSx, prevSy), ImVec2(sx2, sy2),
                        IM_COL32(255, 160, 40, 180), 1.5f);
                }
                prevSx = sx2;
                prevSy = sy2;
                prevVisible = vis;
            }
        }

        if (!enemyVisible)
            continue;

        // --- State label ---
        const char* stateStr = "PATROL";
        ImU32       stateCol = IM_COL32(255, 255, 255, 240);

        switch (e.state)
        {
        case EnemyState::Patrol: stateStr = "PATROL"; stateCol = IM_COL32(255, 255, 255, 240); break;
        case EnemyState::Chase:  stateStr = "CHASE";  stateCol = IM_COL32(230, 220, 30, 240); break;
        case EnemyState::Attack: stateStr = "ATTACK"; stateCol = IM_COL32(255, 160, 40, 240); break;
        case EnemyState::Hit:    stateStr = "HIT";    stateCol = IM_COL32(255, 80, 80, 240); break;
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

void ImGuiLayer::DrawLockOnMarker(
    const EnemyActor* target,
    float camX, float camY, float camZ,
    float yaw,  float pitch,
    float vpW,  float vpH)
{
    if (!target || target->isDead)
        return;
    if (!ImGui::GetCurrentContext())
        return;

    float sx = 0.0f;
    float sy = 0.0f;
    if (!WorldToScreen(target->x, target->y + kLockMarkerHeightOffset, target->z,
                       camX, camY, camZ, yaw, pitch, vpW, vpH, sx, sy))
    {
        return;
    }

    ImDrawList* drawList = ImGui::GetForegroundDrawList();
    const ImU32 lockColor = IM_COL32(255, 220, 80, 255);

    drawList->AddCircle(ImVec2(sx, sy), kLockMarkerCircleRadius, lockColor,
                        kLockMarkerCircleSegments, kLockMarkerCircleThickness);
    drawList->AddText(ImVec2(sx + kLockMarkerTextOffsetX, sy + kLockMarkerTextOffsetY),
                      lockColor, "LOCK");
}

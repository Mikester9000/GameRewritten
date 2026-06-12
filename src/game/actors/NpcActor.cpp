// ============================================================
// FILE: src/game/actors/NpcActor.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: NpcActor module behavior and local implementation details.
// ============================================================

// NpcActor.cpp
// Stationary NPC: colored box visual + ImGui world-to-screen name tag + E-to-talk.

#include "NpcActor.hpp"

#include "../PrimitiveRenderer.hpp"
#include "../PrefabDef.hpp"
#include "../../ui/ScreenProjection.hpp"
// DialogBox.hpp must be included after any headers that pull in windows.h so
// its internal #undef DialogBox runs last and keeps the class name clean.
#include "../../ui/DialogBox.hpp"

#include <cmath>
#include <string>

// Undefine the Win32 DialogBox macro before including ImGui so there's no clash.
#ifdef DialogBox
#undef DialogBox
#endif
#include <imgui.h>

namespace
{
// Build a simple two-part (body + head) prefab inline so NpcActor has no
// dependency on the asset registry.  Cyan body, dark-cyan head.
PrimitivePrefab BuildNpcPrefab()
{
    PrimitivePrefab p;
    p.name     = "_npc_blockout";
    p.category = "prop";

    // Body
    PrimitivePart body;
    body.offsetX = 0.0f; body.offsetY = 0.8f; body.offsetZ = 0.0f;
    body.scaleX  = 0.5f; body.scaleY  = 1.2f; body.scaleZ  = 0.5f;
    body.r = 0.0f; body.g = 0.70f; body.b = 0.75f; body.a = 1.0f;
    p.parts.push_back(body);

    // Head
    PrimitivePart head;
    head.offsetX = 0.0f; head.offsetY = 1.75f; head.offsetZ = 0.0f;
    head.scaleX  = 0.4f; head.scaleY  = 0.40f; head.scaleZ  = 0.4f;
    head.r = 0.0f; head.g = 0.50f; head.b = 0.55f; head.a = 1.0f;
    p.parts.push_back(head);

    return p;
}

// Shared prefab instance — built once on first NPC visual submission.
const PrimitivePrefab& NpcVisualPrefab()
{
    static const PrimitivePrefab kPrefab = BuildNpcPrefab();
    return kPrefab;
}
} // anonymous namespace

void NpcActor::Init(float startX, float startZ,
                    const char* npcName,
                    const char* dialog,
                    float radius)
{
    x = startX;
    y = 0.0f;
    z = startZ;
    name          = npcName;
    dialogLine    = dialog;
    interactRadius = radius;
    m_playerInRange = false;
}

void NpcActor::Update(float playerX, float playerZ,
                      bool interactPressed,
                      DialogBox& dialogBox)
{
    // --- Proximity check ---
    const float dx = playerX - x;
    const float dz = playerZ - z;
    const float distanceSq = dx * dx + dz * dz;
    const float radiusSq   = interactRadius * interactRadius;
    m_playerInRange = (distanceSq <= radiusSq);

    // --- Open dialog on E press while in range ---
    if (m_playerInRange && interactPressed && !dialogBox.IsOpen())
        dialogBox.Show(name, dialogLine);
}

void NpcActor::SubmitVisual(PrimitiveRenderer& pr) const
{
    pr.AddRuntimeInstance(NpcVisualPrefab(), x, y, z, 0.0f, 1.0f, false);
}

void NpcActor::DrawNameTag(float camX, float camY, float camZ,
                           float yaw, float pitch,
                           float vpW, float vpH) const
{
    // Project the position 2 units above the NPC's feet.
    float sx = 0.0f;
    float sy = 0.0f;
    const bool visible = ScreenProjection::WorldToScreen(
        x, y + 2.2f, z,
        camX, camY, camZ,
        yaw, pitch,
        vpW, vpH,
        sx, sy);

    if (!visible)
        return;

    // Draw a centred name tag using ImGui foreground draw list.
    ImDrawList* dl = ImGui::GetForegroundDrawList();
    const std::string label = "[" + name + "]";
    const ImVec2 textSize   = ImGui::CalcTextSize(label.c_str());
    const float  textX      = sx - textSize.x * 0.5f;
    const float  textY      = sy - textSize.y;

    // Dark shadow then bright text for readability over any background.
    dl->AddText(ImVec2(textX + 1.0f, textY + 1.0f), IM_COL32(0, 0, 0, 200), label.c_str());
    dl->AddText(ImVec2(textX, textY),               IM_COL32(0, 220, 230, 255), label.c_str());

    // Show the interact prompt only when the player is close.
    if (m_playerInRange)
    {
        const char* prompt = "E: Talk";
        const ImVec2 promptSize = ImGui::CalcTextSize(prompt);
        const float  promptX    = sx - promptSize.x * 0.5f;
        const float  promptY    = textY + textSize.y + 2.0f;
        dl->AddText(ImVec2(promptX + 1.0f, promptY + 1.0f), IM_COL32(0, 0, 0, 160), prompt);
        dl->AddText(ImVec2(promptX, promptY),               IM_COL32(255, 255, 180, 220), prompt);
    }
}

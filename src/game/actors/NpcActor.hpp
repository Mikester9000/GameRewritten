// ============================================================
// FILE: src/game/actors/NpcActor.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: NpcActor module behavior and local implementation details.
// ============================================================

#pragma once
// NpcActor.hpp
// A stationary NPC that shows a dialog line when the player presses E nearby.

#include <string>

class PrimitiveRenderer;
class DialogBox;

class NpcActor
{
public:
    // World-space position (Y is terrain-snapped externally or left as 0).
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    std::string name;
    std::string dialogLine;
    float interactRadius = 3.0f;

    // Set initial position and dialog content.
    void Init(float startX, float startZ,
              const char* npcName,
              const char* dialog,
              float radius = 3.0f);

    // Check player proximity and E-press; open dialog box when both conditions met.
    // interactPressed must be a one-shot edge-detected value from the caller.
    void Update(float playerX, float playerZ,
                bool interactPressed,
                DialogBox& dialogBox);

    // Submit a colored box primitive representing the NPC.
    void SubmitVisual(PrimitiveRenderer& pr) const;

    // Draw the NPC's name tag using ImGui world-to-screen projection.
    // Must be called inside an active ImGui frame.
    void DrawNameTag(float camX, float camY, float camZ,
                     float yaw, float pitch,
                     float vpW, float vpH) const;

private:
    bool m_playerInRange = false; // true while player is within interactRadius
};

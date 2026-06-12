// ============================================================
// FILE: src/game/actors/RestPointActor.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: RestPointActor module behavior and local implementation details.
// ============================================================

#pragma once
// RestPointActor.hpp
// A campfire / rest point that fully restores player HP and MP on first use.
// The usedThisVisit flag resets once the player moves far enough away.

class PrimitiveRenderer;
struct PlayerStats;

class RestPointActor
{
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    float radius        = 4.0f;
    bool  usedThisVisit = false;

    // Set the campfire world position and interaction radius.
    void Init(float startX, float startZ, float interactRadius = 4.0f);

    // Check player proximity, display the rest prompt, and heal the player.
    // Returns true the moment the player successfully rests (use to show toast).
    // interactPressed must be a one-shot edge-detected value.
    bool Update(float playerX, float playerZ,
                bool interactPressed,
                PlayerStats& stats);

    // Submit an orange box primitive for the campfire.
    void SubmitVisual(PrimitiveRenderer& pr) const;
};

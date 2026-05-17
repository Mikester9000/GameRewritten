// ============================================================
// FILE: src/game/actors/ActorCommon.hpp
// SYSTEM: ActorCommon.hpp
// SYSTEM: gameplay systems, actors, combat, and runtime state

#pragma once

namespace ActorCommon
{
// Asset Registry ID for the player's first runtime blockout prefab.
inline constexpr const char* PLAYER_VISUAL_PREFAB_ID = "prefabs.player_hero_blockout";

struct RuntimeActorPose
{
    // Runtime world-space pose for one actor visual submission.
    // Position is in world units and yaw is in radians around +Y.
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float yaw = 0.0f;
    float scale = 1.0f;
};
}

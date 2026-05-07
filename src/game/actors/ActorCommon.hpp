#pragma once

namespace ActorCommon
{
// Asset Registry ID for the player's first runtime blockout prefab.
inline constexpr const char* PLAYER_VISUAL_PREFAB_ID = "prefabs.player_hero_blockout";

struct RuntimeActorPose
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float yaw = 0.0f;
    float scale = 1.0f;
};
}

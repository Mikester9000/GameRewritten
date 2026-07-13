// ============================================================
// FILE: src/game/actors/ActorCommon.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: ActorCommon module behavior and local implementation details.
// ============================================================

#pragma once

namespace ActorCommon
{
    // Asset Registry ID for the player's first runtime blockout prefab.
    
        inline constexpr const char* PLAYERVISUALPREFABID = "prefabs.player_hero_blockout";
        inline constexpr const char* ENEMYVISUALPREFABID = "prefabs.goblin_blockout"; // Or whatever your prefab name is
        // ...
    

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

#include "PlayerActor.hpp"

#include "../CameraController.hpp"
#include "../PrefabLibrary.hpp"
#include "../PrimitiveRenderer.hpp"

#include <string>

ActorCommon::RuntimeActorPose PlayerActor::BuildRuntimePose(const CameraController& cameraController) const
{
    ActorCommon::RuntimeActorPose pose;
    pose.x = cameraController.GetPlayerX();
    pose.y = cameraController.GetPlayerGroundY();
    pose.z = cameraController.GetPlayerZ();
    pose.yaw = cameraController.GetYaw();
    pose.scale = 1.0f;
    return pose;
}

void PlayerActor::SubmitRuntimeVisual(const CameraController& cameraController,
                                      const PrefabLibrary& prefabLibrary,
                                      PrimitiveRenderer& primitiveRenderer) const
{
    static const std::string kPlayerVisualPrefabId = ActorCommon::PLAYER_VISUAL_PREFAB_ID;
    const PrimitivePrefab* visualPrefab =
        prefabLibrary.GetPrefab(kPlayerVisualPrefabId);
    if (!visualPrefab)
        return;

    const ActorCommon::RuntimeActorPose pose = BuildRuntimePose(cameraController);
    primitiveRenderer.AddRuntimeInstance(*visualPrefab,
                                         pose.x, pose.y, pose.z,
                                         pose.yaw, pose.scale);
}

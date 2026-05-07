#include "PlayerActor.hpp"

#include "../CameraController.hpp"
#include "../PrefabLibrary.hpp"
#include "../PrimitiveRenderer.hpp"

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
    const PrimitivePrefab* playerVisualPrefab =
        prefabLibrary.GetPrefab(ActorCommon::PLAYER_VISUAL_PREFAB_ID);
    if (!playerVisualPrefab)
        return;

    const ActorCommon::RuntimeActorPose pose = BuildRuntimePose(cameraController);
    primitiveRenderer.AddRuntimeInstance(*playerVisualPrefab,
                                         pose.x, pose.y, pose.z,
                                         pose.yaw, pose.scale);
}

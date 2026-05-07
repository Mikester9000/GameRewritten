#pragma once

#include "ActorCommon.hpp"
#include "PlayerStats.hpp"

class CameraController;
class PrefabLibrary;
class PrimitiveRenderer;

class PlayerActor
{
public:
    PlayerStats stats;

    void SubmitRuntimeVisual(const CameraController& cameraController,
                             const PrefabLibrary& prefabLibrary,
                             PrimitiveRenderer& primitiveRenderer) const;

private:
    ActorCommon::RuntimeActorPose BuildRuntimePose(const CameraController& cameraController) const;
};

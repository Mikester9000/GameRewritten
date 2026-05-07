#pragma once

#include "ActorCommon.hpp"

class CameraController;
class PrefabLibrary;
class PrimitiveRenderer;

class PlayerActor
{
public:
    void SubmitRuntimeVisual(const CameraController& cameraController,
                             const PrefabLibrary& prefabLibrary,
                             PrimitiveRenderer& primitiveRenderer) const;

private:
    ActorCommon::RuntimeActorPose BuildRuntimePose(const CameraController& cameraController) const;
};

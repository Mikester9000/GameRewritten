// ============================================================
// FILE: src/app/ThirdPartyBootstrap.hpp
// SYSTEM: App
// ROLE: app startup/shutdown wiring and frame orchestration
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: ThirdPartyBootstrap module behavior and local implementation details.
// ============================================================

#pragma once
// ThirdPartyBootstrap.hpp
// App-layer startup/shutdown wrapper for third-party subsystem smoke tests.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include "tp_audio.hpp"
#include "tp_physics.hpp"
#include "tp_navigation.hpp"
#include "tp_image.hpp"
#include "tp_texture.hpp"
#include "tp_tracy.hpp"

namespace ThirdPartyBootstrap
{
inline void InitializeAndRunSmokeTests()
{
    // Audio: initialize the miniaudio engine (opens the default audio device).
    tp::Audio::Init();

    // Physics: initialize Jolt and run a quick one-step smoke test.
    if (tp::Physics::Init())
    {
        // Ground is created as a fixed reference body for the dynamic sphere smoke step.
        // The returned ground id is intentionally ignored in this one-shot smoke test.
        tp::Physics::AddStaticGround(0.0f);
        tp::PhysicsBodyId dynamicSphereId = tp::Physics::AddDynamicSphere(0.0f, 5.0f, 0.0f, 0.5f, 1.0f);

        // Take one physics step so we know integration runs without crashing.
        {
            GR_ZONE_SCOPED_N("Physics Step");
            tp::Physics::Step(1.0f / 60.0f);
        }

        float sx = 0.0f, sy = 0.0f, sz = 0.0f;
        tp::Physics::GetBodyPosition(dynamicSphereId, sx, sy, sz);
        OutputDebugStringA("[Game] Physics smoke test: sphere stepped OK.\n");
    }

    // Navigation: init (navmesh build is deferred until level geometry is ready).
    tp::Nav::Init();

    // Image: attempt to load Content/Textures/placeholder.png (may not exist yet).
    {
        tp::Image img;
        tp::Image::Load("Content/Textures/placeholder.png", img);
        img.Free(); // safe to call even if load failed
    }

    // DirectXTex smoke test: load placeholder.png via DirectXTex and log metadata.
    tp::Texture::SmokeTest();
}

inline void Shutdown()
{
    tp::Nav::Shutdown();
    tp::Physics::Shutdown();
    tp::Audio::Shutdown();
}
}

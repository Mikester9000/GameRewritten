#pragma once
// tp_physics.hpp — Physics world wrapper using Jolt Physics v5.3.0 (MIT).
// Provides minimal init/shutdown, a ground plane, and dynamic rigid bodies.
//
// Usage:
//   tp::Physics::Init();
//   tp::PhysicsBodyId sphere = tp::Physics::AddDynamicSphere({0,5,0}, 0.5f, 1.0f);
//   // per frame:
//   tp::Physics::Step(deltaTime);
//   float px, py, pz;
//   tp::Physics::GetBodyPosition(sphere, px, py, pz);
//   // cleanup:
//   tp::Physics::Shutdown();

#include <cstdint>

namespace tp
{

// Opaque handle to a physics body (wraps Jolt body ID).
struct PhysicsBodyId
{
    uint32_t id = 0xFFFFFFFF;
    bool IsValid() const { return id != 0xFFFFFFFF; }
};

class Physics
{
public:
    // Initialize Jolt and create the physics world.
    // maxBodies: max simultaneously active bodies (keep low on GT610 targets).
    static bool Init(unsigned int maxBodies = 1024,
                     unsigned int maxBodyPairs = 4096,
                     unsigned int maxContactConstraints = 2048);

    // Advance the physics simulation by deltaTime seconds.
    // Pass a fixed step (e.g. 1/60) for determinism, or your frame delta.
    static void Step(float deltaTime, int subSteps = 1);

    // Release all physics resources.
    static void Shutdown();

    // Returns true if Init() succeeded.
    static bool IsInitialized();

    // Add a static infinite ground plane at Y = groundY.
    static PhysicsBodyId AddStaticGround(float groundY = 0.0f);

    // Add a dynamic sphere body at position (x, y, z) with given radius and mass.
    static PhysicsBodyId AddDynamicSphere(float x, float y, float z,
                                          float radius = 0.5f,
                                          float mass   = 1.0f);

    // Add a dynamic capsule body (oriented along Y axis).
    static PhysicsBodyId AddDynamicCapsule(float x, float y, float z,
                                           float halfHeight = 0.9f,
                                           float radius     = 0.3f,
                                           float mass       = 80.0f);

    // Read back world-space position of a body.  Returns false if id is invalid.
    static bool GetBodyPosition(PhysicsBodyId id, float& outX, float& outY, float& outZ);

    // Remove and destroy a body by id.
    static void RemoveBody(PhysicsBodyId id);

    // Cast a ray and return the first hit.
    // ox/oy/oz  = ray origin.
    // dx/dy/dz  = normalised ray direction (unit vector pointing into the scene).
    // maxDist   = how far to cast; the direction is scaled by maxDist internally
    //             so Jolt knows where the ray ends.
    // Check RayHit::hit before using the position fields.
    struct RayHit { float x, y, z; float fraction; bool hit; };
    static RayHit CastRay(float ox, float oy, float oz,
                           float dx, float dy, float dz,
                           float maxDist = 1000.0f);

private:
    Physics() = delete;
};

} // namespace tp

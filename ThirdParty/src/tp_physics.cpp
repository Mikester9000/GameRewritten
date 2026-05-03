// tp_physics.cpp — Physics world wrapper (Jolt Physics v5.3.0, MIT).
//
// Jolt setup reference: https://jrouwe.github.io/JoltPhysics/
// Minimal setup for a single-threaded game loop targeting GT610-class hardware.

// ── Jolt required defines (must come before any Jolt include) ──────────────
// Disable AVX/SSE4 for GT610 compatibility; use SSE2 baseline.
#define JPH_USE_SSE4_2 0
#define JPH_USE_SSE4_1 0
#define JPH_USE_AVX    0
#define JPH_USE_AVX2   0
#define JPH_USE_AVX512 0
#define JPH_USE_LZCNT  0
#define JPH_USE_TZCNT  0
#define JPH_USE_F16C   0
#define JPH_USE_FMADD  0

#include <Jolt/Jolt.h>
#include <Jolt/RegisterTypes.h>
#include <Jolt/Core/Factory.h>
#include <Jolt/Core/TempAllocator.h>
#include <Jolt/Core/JobSystemSingleThreaded.h>
#include <Jolt/Physics/PhysicsSettings.h>
#include <Jolt/Physics/PhysicsSystem.h>
#include <Jolt/Physics/Collision/Shape/BoxShape.h>
#include <Jolt/Physics/Collision/Shape/SphereShape.h>
#include <Jolt/Physics/Collision/Shape/CapsuleShape.h>
#include <Jolt/Physics/Collision/RayCast.h>
#include <Jolt/Physics/Collision/CastResult.h>
#include <Jolt/Physics/Body/BodyCreationSettings.h>
#include <Jolt/Physics/Body/BodyActivationListener.h>

#include "tp_physics.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// ── Layer definitions ────────────────────────────────────────────────────────
namespace Layers
{
    static constexpr JPH::ObjectLayer NON_MOVING = 0;
    static constexpr JPH::ObjectLayer MOVING     = 1;
    static constexpr JPH::uint        NUM_LAYERS = 2;
}

namespace BPLayers
{
    static constexpr JPH::BroadPhaseLayer NON_MOVING(0);
    static constexpr JPH::BroadPhaseLayer MOVING(1);
    static constexpr JPH::uint            NUM_LAYERS = 2;
}

// Maps object layers to broad-phase layers.
class BPLayerInterfaceImpl final : public JPH::BroadPhaseLayerInterface
{
public:
    BPLayerInterfaceImpl()
    {
        mObjectToBroadPhase[Layers::NON_MOVING] = BPLayers::NON_MOVING;
        mObjectToBroadPhase[Layers::MOVING]     = BPLayers::MOVING;
    }
    JPH::uint GetNumBroadPhaseLayers() const override { return BPLayers::NUM_LAYERS; }
    JPH::BroadPhaseLayer GetBroadPhaseLayer(JPH::ObjectLayer layer) const override
    {
        return mObjectToBroadPhase[layer];
    }
#if defined(JPH_EXTERNAL_PROFILE) || defined(JPH_PROFILE_ENABLED)
    const char* GetBroadPhaseLayerName(JPH::BroadPhaseLayer layer) const override
    {
        switch ((JPH::BroadPhaseLayer::Type)layer)
        {
            case (JPH::BroadPhaseLayer::Type)BPLayers::NON_MOVING: return "NON_MOVING";
            case (JPH::BroadPhaseLayer::Type)BPLayers::MOVING:     return "MOVING";
            default: return "UNKNOWN";
        }
    }
#endif
private:
    JPH::BroadPhaseLayer mObjectToBroadPhase[Layers::NUM_LAYERS];
};

class ObjectVsBroadPhaseLayerFilterImpl final : public JPH::ObjectVsBroadPhaseLayerFilter
{
public:
    bool ShouldCollide(JPH::ObjectLayer layer, JPH::BroadPhaseLayer bpLayer) const override
    {
        switch (layer)
        {
            case Layers::NON_MOVING: return bpLayer == BPLayers::MOVING;
            case Layers::MOVING:     return true;
            default:                 return false;
        }
    }
};

class ObjectLayerPairFilterImpl final : public JPH::ObjectLayerPairFilter
{
public:
    bool ShouldCollide(JPH::ObjectLayer a, JPH::ObjectLayer b) const override
    {
        switch (a)
        {
            case Layers::NON_MOVING: return b == Layers::MOVING;
            case Layers::MOVING:     return true;
            default:                 return false;
        }
    }
};

// ── Internal state ───────────────────────────────────────────────────────────
namespace tp { namespace detail {

static bool                             g_initialized = false;
static JPH::TempAllocatorImpl*          g_tempAlloc   = nullptr;
static JPH::JobSystemSingleThreaded*    g_jobSystem   = nullptr;
static BPLayerInterfaceImpl             g_bpLayerInterface;
static ObjectVsBroadPhaseLayerFilterImpl g_objVsBPFilter;
static ObjectLayerPairFilterImpl        g_objLayerPairFilter;
static JPH::PhysicsSystem*              g_physicsSystem = nullptr;

}} // namespace tp::detail

// ── Public API ───────────────────────────────────────────────────────────────
namespace tp
{

bool Physics::Init(unsigned int maxBodies, unsigned int maxBodyPairs, unsigned int maxContactConstraints)
{
    if (detail::g_initialized)
        return true;

    // Register all Jolt types
    JPH::RegisterDefaultAllocator();
    JPH::Factory::sInstance = new JPH::Factory();
    JPH::RegisterTypes();

    // Temp allocator: 10 MB is enough for a simple scene
    detail::g_tempAlloc = new JPH::TempAllocatorImpl(10 * 1024 * 1024);

    // Single-threaded job system (safe for GT610-era single/dual-core)
    detail::g_jobSystem = new JPH::JobSystemSingleThreaded(JPH::cMaxPhysicsJobs);

    // Create the physics world
    detail::g_physicsSystem = new JPH::PhysicsSystem();
    detail::g_physicsSystem->Init(
        maxBodies, 0 /*auto mutexes*/, maxBodyPairs, maxContactConstraints,
        detail::g_bpLayerInterface,
        detail::g_objVsBPFilter,
        detail::g_objLayerPairFilter);

    detail::g_initialized = true;
    OutputDebugStringA("[ThirdParty][Physics] Jolt initialized.\n");
    return true;
}

void Physics::Step(float deltaTime, int subSteps)
{
    if (!detail::g_initialized || !detail::g_physicsSystem)
        return;

    // Clamp to avoid huge integration steps
    if (deltaTime > 0.05f) deltaTime = 0.05f;

    detail::g_physicsSystem->Update(
        deltaTime, subSteps,
        detail::g_tempAlloc, detail::g_jobSystem);
}

void Physics::Shutdown()
{
    if (!detail::g_initialized)
        return;

    delete detail::g_physicsSystem;
    detail::g_physicsSystem = nullptr;

    delete detail::g_jobSystem;
    detail::g_jobSystem = nullptr;

    delete detail::g_tempAlloc;
    detail::g_tempAlloc = nullptr;

    JPH::UnregisterTypes();

    delete JPH::Factory::sInstance;
    JPH::Factory::sInstance = nullptr;

    detail::g_initialized = false;
    OutputDebugStringA("[ThirdParty][Physics] Shutdown.\n");
}

bool Physics::IsInitialized()
{
    return detail::g_initialized;
}

PhysicsBodyId Physics::AddStaticGround(float groundY)
{
    if (!detail::g_initialized) return {};

    JPH::BodyInterface& bi = detail::g_physicsSystem->GetBodyInterface();

    JPH::BoxShapeSettings groundShape(JPH::Vec3(1000.0f, 1.0f, 1000.0f));
    groundShape.SetEmbedded();

    JPH::BodyCreationSettings settings(
        &groundShape,
        JPH::RVec3(0.0f, groundY - 1.0f, 0.0f),
        JPH::Quat::sIdentity(),
        JPH::EMotionType::Static,
        Layers::NON_MOVING);

    JPH::Body* body = bi.CreateBody(settings);
    if (!body) return {};
    bi.AddBody(body->GetID(), JPH::EActivation::DontActivate);

    PhysicsBodyId result;
    result.id = body->GetID().GetIndexAndSequenceNumber();
    OutputDebugStringA("[ThirdParty][Physics] Added static ground.\n");
    return result;
}

PhysicsBodyId Physics::AddDynamicSphere(float x, float y, float z, float radius, float mass)
{
    if (!detail::g_initialized) return {};

    JPH::BodyInterface& bi = detail::g_physicsSystem->GetBodyInterface();

    JPH::SphereShapeSettings sphereShape(radius);
    sphereShape.SetEmbedded();
    // Set density so Jolt computes the correct mass automatically
    float volume = (4.0f / 3.0f) * 3.14159f * radius * radius * radius;
    sphereShape.mDensity = (volume > 0.0f) ? (mass / volume) : 1000.0f;

    JPH::BodyCreationSettings settings(
        &sphereShape,
        JPH::RVec3(x, y, z),
        JPH::Quat::sIdentity(),
        JPH::EMotionType::Dynamic,
        Layers::MOVING);

    JPH::Body* body = bi.CreateBody(settings);
    if (!body) return {};
    bi.AddBody(body->GetID(), JPH::EActivation::Activate);

    PhysicsBodyId result;
    result.id = body->GetID().GetIndexAndSequenceNumber();
    return result;
}

PhysicsBodyId Physics::AddDynamicCapsule(float x, float y, float z,
                                          float halfHeight, float radius, float mass)
{
    if (!detail::g_initialized) return {};

    JPH::BodyInterface& bi = detail::g_physicsSystem->GetBodyInterface();

    JPH::CapsuleShapeSettings capsuleShape(halfHeight, radius);
    capsuleShape.SetEmbedded();

    JPH::BodyCreationSettings settings(
        &capsuleShape,
        JPH::RVec3(x, y, z),
        JPH::Quat::sIdentity(),
        JPH::EMotionType::Dynamic,
        Layers::MOVING);

    JPH::Body* body = bi.CreateBody(settings);
    if (!body) return {};
    bi.AddBody(body->GetID(), JPH::EActivation::Activate);

    PhysicsBodyId result;
    result.id = body->GetID().GetIndexAndSequenceNumber();
    return result;
}

bool Physics::GetBodyPosition(PhysicsBodyId id, float& outX, float& outY, float& outZ)
{
    if (!detail::g_initialized || !id.IsValid())
        return false;

    JPH::BodyInterface& bi = detail::g_physicsSystem->GetBodyInterface();
    JPH::BodyID jphId(id.id);
    JPH::RVec3 pos = bi.GetPosition(jphId);
    outX = (float)pos.GetX();
    outY = (float)pos.GetY();
    outZ = (float)pos.GetZ();
    return true;
}

void Physics::RemoveBody(PhysicsBodyId id)
{
    if (!detail::g_initialized || !id.IsValid())
        return;

    JPH::BodyInterface& bi = detail::g_physicsSystem->GetBodyInterface();
    JPH::BodyID jphId(id.id);
    bi.RemoveBody(jphId);
    bi.DestroyBody(jphId);
}

Physics::RayHit Physics::CastRay(float ox, float oy, float oz,
                                   float dx, float dy, float dz,
                                   float maxDist)
{
    RayHit result{};
    if (!detail::g_initialized || !detail::g_physicsSystem)
        return result;

    JPH::RRayCast ray;
    ray.mOrigin    = JPH::RVec3(static_cast<double>(ox),
                                 static_cast<double>(oy),
                                 static_cast<double>(oz));
    ray.mDirection = JPH::Vec3(dx * maxDist, dy * maxDist, dz * maxDist);

    JPH::RayCastResult hit;
    bool didHit = detail::g_physicsSystem->GetNarrowPhaseQuery().CastRay(
        ray, hit,
        JPH::BroadPhaseLayerFilter{},
        JPH::ObjectLayerFilter{},
        JPH::BodyFilter{});

    if (didHit)
    {
        result.fraction = hit.mFraction;
        result.x = ox + dx * maxDist * hit.mFraction;
        result.y = oy + dy * maxDist * hit.mFraction;
        result.z = oz + dz * maxDist * hit.mFraction;
        result.hit = true;
    }
    return result;
}

} // namespace tp

#pragma once
// TraversalMount.hpp
// Mount / vehicle framework stub.  Manages mounting state, movement overrides,
// and camera mode so the rest of the runtime sees a single interface.

#include <DirectXMath.h>
#include <string>

struct MountDef
{
    std::string id;
    float       speed       = 12.0f;  // units per second while mounted
    float       turnRate    = 2.5f;   // radians per second
    float       jumpImpulse = 0.0f;   // 0 = can't jump while mounted
};

class TraversalMount
{
public:
    // Attempt to mount using definition.  Returns false if already mounted.
    bool Mount(const MountDef& def);

    // Dismount immediately; resets to on-foot movement.
    void Dismount();

    bool IsMounted() const { return m_mounted; }
    const MountDef& GetDef() const { return m_def; }

    // Apply mount movement to position + yaw given stick input each frame.
    void Update(float dt, float stickX, float stickZ, float& posX, float& posZ, float& yaw);

private:
    MountDef m_def;
    bool     m_mounted = false;
};

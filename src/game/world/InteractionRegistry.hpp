#pragma once
// InteractionRegistry.hpp
// Registers world-space interaction hotspots (NPCs, chests, rest points).
// The player update loop calls Query() each frame to find the nearest active
// hotspot within reach; the HUD then displays the appropriate prompt.

#include <DirectXMath.h>
#include <functional>
#include <string>
#include <vector>

struct Hotspot
{
    int         id           = 0;
    std::string label;          // prompt text shown in HUD, e.g. "[E] Talk"
    DirectX::XMFLOAT3 pos{};
    float       radius       = 2.5f;
    bool        active       = true;
};

class InteractionRegistry
{
public:
    // Register a hotspot; returns its assigned id.
    int  Add(const Hotspot& hs);

    // Enable / disable a hotspot by id (e.g. after a chest is opened).
    void SetActive(int id, bool active);

    void Clear();

    // Returns the nearest active hotspot within radius of playerPos,
    // or nullptr when none is in range.
    const Hotspot* Query(const DirectX::XMFLOAT3& playerPos) const;

    // Fires callback for every active hotspot (used by WorldEditor preview).
    void ForEach(const std::function<void(const Hotspot&)>& fn) const;

private:
    std::vector<Hotspot> m_hotspots;
    int                  m_nextId = 1;
};

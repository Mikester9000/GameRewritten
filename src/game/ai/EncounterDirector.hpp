#pragma once
// EncounterDirector.hpp
// Open-world encounter spawning: driven by PopulationDirector tables and
// player proximity.  Limits active encounter count to keep GT610 overhead low.

#include <DirectXMath.h>
#include <functional>
#include <vector>

struct EncounterSlot
{
    int   id         = 0;
    float spawnX     = 0.0f;
    float spawnZ     = 0.0f;
    float radius     = 40.0f;  // radius in which the encounter activates
    bool  active     = false;
    int   enemyCount = 0;
};

class EncounterDirector
{
public:
    static constexpr int kMaxActiveEncounters = 4;

    // Register a potential encounter point.
    int  AddSlot(float x, float z, float radius, int enemyCount);

    // Call each frame.  Fires onActivate when a slot enters player range
    // and has capacity.
    void Update(const DirectX::XMFLOAT3& playerPos,
                const std::function<void(const EncounterSlot&)>& onActivate);

    // Mark a slot's encounter as cleared (all enemies defeated).
    void NotifyClear(int slotId);

private:
    std::vector<EncounterSlot> m_slots;
    int                        m_nextId = 1;
    int ActiveCount() const;
};

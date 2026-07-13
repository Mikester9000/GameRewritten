#pragma once
// LandmarkTrigger.hpp
// One-shot proximity triggers that mark a named landmark as discovered,
// fire a HUD toast, and optionally update the discovery journal.

#include <DirectXMath.h>
#include <functional>
#include <string>
#include <vector>

struct Landmark
{
    int         id        = 0;
    std::string name;           // e.g. "Midgar Ruins"
    DirectX::XMFLOAT3 pos{};
    float       radius    = 8.0f;
    bool        discovered = false;
};

class LandmarkTriggerSystem
{
public:
    // Add a landmark; returns its id.
    int  Add(const Landmark& lm);
    void Clear();

    // Call once per frame.  Fires onDiscover(landmark) the first time the
    // player enters a landmark radius.
    void Update(const DirectX::XMFLOAT3& playerPos,
                const std::function<void(const Landmark&)>& onDiscover);

    const std::vector<Landmark>& GetAll() const { return m_landmarks; }
    bool SetDiscovered(const std::string& name, bool discovered);
    void SetAllDiscovered(bool discovered);

private:
    std::vector<Landmark> m_landmarks;
    int                   m_nextId = 1;
};

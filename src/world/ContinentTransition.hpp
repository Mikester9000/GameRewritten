#pragma once
// ContinentTransition.hpp
// Detects when the player crosses a continent boundary and orchestrates
// the streaming swap (pause updates → unload old continent → load new → resume).

#include <DirectXMath.h>
#include <functional>
#include <string>

struct ContinentBound
{
    std::string fromContinent;
    std::string toContinent;
    float       boundaryX = 0.0f; // world-space X dividing the two continents
};

class ContinentTransition
{
public:
    void Init(const ContinentBound& bound);

    // Call once per frame.  Fires onTransition(from, to) when the player
    // crosses the boundary for the first time in that direction.
    void Update(const DirectX::XMFLOAT3& playerPos,
                const std::function<void(const std::string& from,
                                         const std::string& to)>& onTransition);

    const std::string& CurrentContinent() const { return m_current; }

private:
    ContinentBound m_bound;
    std::string    m_current;
    bool           m_initialized = false;
};

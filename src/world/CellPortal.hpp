#pragma once
// CellPortal.hpp
// Links an interior cell to an exterior cell (or another interior).
// When the player crosses a portal trigger the active streaming cell
// swaps to the target, allowing seamless indoor/outdoor transitions.

#include <DirectXMath.h>
#include <functional>
#include <string>
#include <vector>

struct CellPortal
{
    int               id          = 0;
    std::string       fromCell;
    std::string       toCell;
    DirectX::XMFLOAT3 triggerPos{};
    float             triggerRadius = 2.0f;
    bool              oneWay      = false; // if true, toCell cannot return via this portal
};

class CellPortalSystem
{
public:
    int  AddPortal(const CellPortal& portal);
    void Clear();

    // Call each frame.  Fires onEnter(portal) when the player enters a
    // portal trigger while inside fromCell.
    void Update(const DirectX::XMFLOAT3& playerPos,
                const std::string& currentCell,
                const std::function<void(const CellPortal&)>& onEnter);

private:
    std::vector<CellPortal> m_portals;
    int                     m_nextId = 1;
};

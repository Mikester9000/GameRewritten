#pragma once
// FastTravel.hpp
// Register named fast-travel nodes (discovered landmarks, rest points).
// The player can warp to any unlocked node; the actual teleport sets
// the CameraController spawn position from Main.

#include <DirectXMath.h>
#include <string>
#include <vector>

struct FastTravelNode
{
    int               id         = 0;
    std::string       name;
    DirectX::XMFLOAT3 pos{};
    bool              unlocked   = false;
};

class FastTravelSystem
{
public:
    // Register a node (locked by default); returns its id.
    int  AddNode(const std::string& name, const DirectX::XMFLOAT3& pos);

    // Unlock a node (called when landmark is discovered / rest point used).
    void Unlock(int id);

    // Returns the node to warp to, or nullptr if id unknown / locked.
    const FastTravelNode* GetNode(int id) const;

    const std::vector<FastTravelNode>& GetAll() const { return m_nodes; }

private:
    std::vector<FastTravelNode> m_nodes;
    int                         m_nextId = 1;
};

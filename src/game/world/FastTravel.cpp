// FastTravel.cpp
// Named warp node registry.

#include "FastTravel.hpp"

int FastTravelSystem::AddNode(const std::string& name, const DirectX::XMFLOAT3& pos)
{
    FastTravelNode node;
    node.id       = m_nextId++;
    node.name     = name;
    node.pos      = pos;
    node.unlocked = false;
    m_nodes.push_back(node);
    return node.id;
}

void FastTravelSystem::Unlock(int id)
{
    for (FastTravelNode& n : m_nodes)
        if (n.id == id) { n.unlocked = true; return; }
}

const FastTravelNode* FastTravelSystem::GetNode(int id) const
{
    for (const FastTravelNode& n : m_nodes)
        if (n.id == id && n.unlocked) return &n;
    return nullptr;
}

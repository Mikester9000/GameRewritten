// NavTileStream.cpp
// Nav tile load/unload bridge (stub implementation — full Recast wiring
// happens when nav tiles are authored; streaming hooks are in place).

#include "NavTileStream.hpp"

#include <cmath>

int NavTileStream::CellKey(const DirectX::XMFLOAT3& pos)
{
    const int cx = static_cast<int>(std::floor(pos.x / kCellSize));
    const int cz = static_cast<int>(std::floor(pos.z / kCellSize));
    return (cx & 0xFFFF) << 16 | (cz & 0xFFFF);
}

void NavTileStream::Init(dtNavMesh* navMesh)
{
    m_navMesh = navMesh;
    m_loadedTiles.clear();
}

void NavTileStream::LoadTile(const DirectX::XMFLOAT3& worldPos)
{
    const int key = CellKey(worldPos);
    m_loadedTiles.insert(key);
    // TODO: when Recast tile data is authored, call dtNavMesh::addTile here.
}

void NavTileStream::UnloadTile(const DirectX::XMFLOAT3& worldPos)
{
    m_loadedTiles.erase(CellKey(worldPos));
    // TODO: call dtNavMesh::removeTile here.
}

bool NavTileStream::HasTile(const DirectX::XMFLOAT3& worldPos) const
{
    return m_loadedTiles.count(CellKey(worldPos)) > 0;
}

void NavTileStream::Clear()
{
    m_loadedTiles.clear();
}

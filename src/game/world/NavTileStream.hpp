#pragma once
// NavTileStream.hpp
// Bridges the Recast/Detour nav-mesh tile system with the world streaming
// pipeline.  Tiles are loaded and unloaded as world cells stream in/out.

#include <DirectXMath.h>
#include <unordered_set>

struct dtNavMesh; // forward from Recast

class NavTileStream
{
public:
    // Attach to the shared dtNavMesh built by ThirdParty nav init.
    void Init(dtNavMesh* navMesh);

    // Load nav tile for the cell that contains worldPos.
    // No-op if the tile is already loaded.
    void LoadTile(const DirectX::XMFLOAT3& worldPos);

    // Unload the tile for worldPos (called when a cell streams out).
    void UnloadTile(const DirectX::XMFLOAT3& worldPos);

    // Returns true if a nav tile is loaded at worldPos.
    bool HasTile(const DirectX::XMFLOAT3& worldPos) const;

    void Clear();

private:
    dtNavMesh* m_navMesh = nullptr;

    // Packed cell key: (cellX << 16) | cellZ  (using 50-unit cells).
    static constexpr float kCellSize = 50.0f;
    static int CellKey(const DirectX::XMFLOAT3& pos);

    std::unordered_set<int> m_loadedTiles;
};

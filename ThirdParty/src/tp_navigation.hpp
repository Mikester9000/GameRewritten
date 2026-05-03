#pragma once
// tp_navigation.hpp — Navmesh / pathfinding wrapper using Recast & Detour (zlib).
// Provides stubs for building a navmesh from geometry and querying paths.
//
// TODO: Full implementation requires passing vertex/triangle geometry from the
// loaded level mesh.  These stubs compile and let callers add nav queries
// without crashing; the implementation is marked TODO for future work.
//
// Usage (stub — no actual paths yet):
//   tp::Nav::Init();
//   // Feed geometry when level is loaded:
//   // tp::Nav::BuildFromMesh(verts, vertCount, tris, triCount);
//   float startPos[3] = {0,0,0}, endPos[3] = {10,0,10};
//   float path[3 * 64];
//   int   pathLen = 0;
//   tp::Nav::FindPath(startPos, endPos, path, pathLen, 64);
//   tp::Nav::Shutdown();

#include <cstdint>

namespace tp
{

class Nav
{
public:
    // Initialize Recast/Detour resources.
    static bool Init();

    // Build a navmesh from raw triangle geometry.
    // verts:     flat array of float[3] positions (x,y,z per vertex)
    // vertCount: number of vertices
    // tris:      flat array of int[3] triangle indices
    // triCount:  number of triangles
    // Returns false and logs if build fails.
    static bool BuildFromMesh(const float* verts, int vertCount,
                               const int*   tris,  int triCount);

    // Find a path from startPos[3] to endPos[3].
    // outPath:       caller-allocated buffer, float[3] per waypoint
    // outPathLength: number of waypoints written
    // maxPathLength: capacity of outPath in waypoints
    // Returns false if no path was found or the navmesh isn't built.
    static bool FindPath(const float* startPos, const float* endPos,
                         float* outPath, int& outPathLength, int maxPathLength);

    // Release navmesh and query objects.
    static void Shutdown();

    // Returns true if a navmesh has been built.
    static bool IsNavmeshReady();

private:
    Nav() = delete;
};

} // namespace tp

// tp_navigation.cpp — Navmesh wrapper (Recast & Detour v1.6.0, zlib).
//
// Current state: Init and Shutdown are implemented.
// BuildFromMesh and FindPath are stubbed with TODOs.
// Recast build pipeline requires passing level geometry and configuring
// agent radius, height, cell size, etc.  Add those details once your
// level mesh loading pipeline is in place.

#include "tp_navigation.hpp"

// Recast
#include "../../third_party/recast/Recast/Include/Recast.h"
#include "../../third_party/recast/Recast/Include/RecastAlloc.h"

// Detour
#include "../../third_party/recast/Detour/Include/DetourNavMesh.h"
#include "../../third_party/recast/Detour/Include/DetourNavMeshBuilder.h"
#include "../../third_party/recast/Detour/Include/DetourNavMeshQuery.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstring>

namespace tp
{

// ── Internal state ────────────────────────────────────────────────────────
namespace detail
{
    static bool           g_initialized  = false;
    static dtNavMesh*     g_navMesh      = nullptr;
    static dtNavMeshQuery* g_navQuery    = nullptr;
}

bool Nav::Init()
{
    if (detail::g_initialized)
        return true;

    detail::g_initialized = true;
    OutputDebugStringA("[ThirdParty][Nav] Initialized (navmesh not yet built).\n");
    return true;
}

bool Nav::BuildFromMesh(const float* /*verts*/, int /*vertCount*/,
                         const int*   /*tris*/,  int /*triCount*/)
{
    if (!detail::g_initialized)
        return false;

    // TODO: Set up rcConfig (cell size, agent radius/height, climb height, etc.)
    // TODO: Allocate rcHeightfield, rcCompactHeightfield, rcContourSet, rcPolyMesh
    // TODO: Run rcBuildHeightfield, rcBuildCompactHeightfield, etc.
    // TODO: Create dtNavMesh from rcPolyMesh via dtCreateNavMeshData
    // TODO: Create dtNavMeshQuery and call init()
    //
    // Stub: log and return false until geometry pipeline is ready.
    OutputDebugStringA("[ThirdParty][Nav] BuildFromMesh — TODO: feed level geometry here.\n");
    return false;
}

bool Nav::FindPath(const float* startPos, const float* endPos,
                   float* outPath, int& outPathLength, int /*maxPathLength*/)
{
    outPathLength = 0;
    if (!detail::g_navMesh || !detail::g_navQuery)
    {
        OutputDebugStringA("[ThirdParty][Nav] FindPath called but no navmesh built yet.\n");
        return false;
    }

    // TODO: Implement using dtNavMeshQuery::findPath + findStraightPath
    // Example skeleton (fill in when navmesh is ready):
    //   dtQueryFilter filter;
    //   dtPolyRef startRef, endRef;
    //   g_navQuery->findNearestPoly(startPos, extents, &filter, &startRef, nullptr);
    //   g_navQuery->findNearestPoly(endPos,   extents, &filter, &endRef,   nullptr);
    //   dtPolyRef polys[64]; int polyCount = 0;
    //   g_navQuery->findPath(startRef, endRef, startPos, endPos, &filter, polys, &polyCount, 64);
    //   float straightPath[64*3]; int straightPathLen = 0;
    //   unsigned char flags[64]; dtPolyRef refs[64];
    //   g_navQuery->findStraightPath(startPos, endPos, polys, polyCount,
    //                                straightPath, flags, refs, &straightPathLen, maxPathLength);
    //   memcpy(outPath, straightPath, straightPathLen * 3 * sizeof(float));
    //   outPathLength = straightPathLen;
    //   return polyCount > 0;

    return false;
}

void Nav::Shutdown()
{
    if (!detail::g_initialized)
        return;

    if (detail::g_navQuery)
    {
        dtFreeNavMeshQuery(detail::g_navQuery);
        detail::g_navQuery = nullptr;
    }
    if (detail::g_navMesh)
    {
        dtFreeNavMesh(detail::g_navMesh);
        detail::g_navMesh = nullptr;
    }

    detail::g_initialized = false;
    OutputDebugStringA("[ThirdParty][Nav] Shutdown.\n");
}

bool Nav::IsNavmeshReady()
{
    return detail::g_navMesh != nullptr;
}

} // namespace tp

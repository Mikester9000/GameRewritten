// ============================================================
// FILE: src/game/physics/AABB.hpp
// SYSTEM: AABB.hpp
// SYSTEM: gameplay systems, actors, combat, and runtime state

#pragma once

struct AABB
{
    float minX = 0.0f;
    float minY = 0.0f;
    float minZ = 0.0f;
    float maxX = 0.0f;
    float maxY = 0.0f;
    float maxZ = 0.0f;

    bool Overlaps(const AABB& other) const
    {
        return minX < other.maxX && maxX > other.minX
            && minY < other.maxY && maxY > other.minY
            && minZ < other.maxZ && maxZ > other.minZ;
    }

    static AABB FromCenter(float cx, float cy, float cz, float hw, float hh, float hd)
    {
        AABB box;
        box.minX = cx - hw; box.maxX = cx + hw;
        box.minY = cy - hh; box.maxY = cy + hh;
        box.minZ = cz - hd; box.maxZ = cz + hd;
        return box;
    }
};

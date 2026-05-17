// ============================================================
// FILE: src/game/physics/CollisionWorld.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: CollisionWorld module behavior and local implementation details.
// ============================================================

#pragma once

#include "AABB.hpp"

#include <vector>

class CollisionWorld
{
public:
    void AddBox(float cx, float cy, float cz, float hw, float hh, float hd);
    void Clear();
    void ResolveMovement(float& x, float& y, float& z, float hw, float hh, float hd) const;

private:
    std::vector<AABB> m_staticBlockers;
};

// ============================================================
// FILE: src/game/PrefabDef.hpp
// SYSTEM: PrefabDef.hpp
// SYSTEM: gameplay systems, actors, combat, and runtime state

#pragma once
// PrefabDef.hpp
// Data structures for primitive-part prefab definitions.
//
// A PrimitivePrefab is a named collection of box parts. Each part has its own
// local offset, non-uniform scale, and RGBA vertex color. When an instance is
// placed in the world the parts are expanded and drawn as separate unit cubes.
//
// Example JSON that maps to this struct:
//   {
//     "name": "tree_oak",
//     "category": "tree",
//     "parts": [
//       { "shape": "box", "offset": [0, 0.8, 0], "scale": [0.25, 1.6, 0.25], "color": [0.4, 0.25, 0.1, 1.0] },
//       { "shape": "box", "offset": [0, 2.1, 0], "scale": [1.2, 1.0, 1.2],   "color": [0.1, 0.60, 0.1, 1.0] }
//     ]
//   }

#include <string>
#include <vector>

struct PrimitivePart
{
    // Only "box" is supported in this version.
    std::string shape = "box";

    // Local offset from the prefab's world origin (x, y, z).
    float offsetX = 0.0f, offsetY = 0.0f, offsetZ = 0.0f;

    // Non-uniform scale: width (x), height (y), depth (z).
    float scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;

    // RGBA color in 0-1 range.
    float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f;
};

struct PrimitivePrefab
{
    std::string name;      // e.g. "tree_oak"
    std::string category;  // e.g. "tree", "rock", "prop" — selects which shader is used

    std::vector<PrimitivePart> parts;
};

# Vendoring Roadmap

Tracks desired third-party libraries that are not yet vendored,
recommended integration order, and rationale.

---

## Already vendored

| Library | Version | Purpose |
|---------|---------|---------|
| Dear ImGui | v1.91.9b | In-game UI, debug overlay |
| nlohmann/json | v3.11.3 | JSON scene/prefab/material loading |
| stb_image | latest master | PNG/JPG/TGA image loading |
| stb_image_write | latest master | PNG/BMP image saving |
| miniaudio | v0.11.25 | Audio playback (WAV, MP3, OGG, FLAC) |
| Jolt Physics | v5.3.0 | Rigid body physics |
| Recast & Detour | v1.6.0 | Navmesh generation and pathfinding |

---

## Planned — High Priority (needed for FF15-like gameplay)

### 1. Assimp — Model import
- **URL:** https://github.com/assimp/assimp
- **License:** BSD 3-Clause
- **Purpose:** Import FBX, OBJ, glTF, Collada, and many other 3D model formats.
  Required for loading character meshes, world props, and vegetation assets.
- **Why deferred:** Assimp has a CMake-heavy build system and many optional
  compile flags. It needs a dedicated setup step.
- **Recommended approach:**
  1. Download a source release.
  2. Disable unneeded importers via `ASSIMP_BUILD_NO_*` defines in a custom
     `assimp_config.h` to reduce compile time and binary size.
  3. Add a unity build or list only the needed importer .cpp files.
  4. Create a `ThirdParty/src/tp_mesh.hpp` wrapper that returns raw vertex/index
     data ready to upload to D3D11 buffers.
- **Acceptance criteria:** Can load an OBJ or glTF file and log vertex count.

### 2. DirectXTex — DDS / texture compression pipeline
- **URL:** https://github.com/microsoft/DirectXTex
- **License:** MIT
- **Purpose:** Load DDS textures, generate mipmaps, convert/compress to
  BC1/BC3/BC7 at content-cook time. Significant VRAM savings on GT610.
- **Recommended approach:**
  1. Vendor just the `DirectXTex/` core source folder.
  2. Use it in a command-line "cooker" tool (separate project) that converts
     PNG to BC1 DDS as a pre-build step.
  3. At runtime, load DDS directly with the existing D3D11 renderer.

### 3. cgltf — Lightweight glTF 2.0 loader
- **URL:** https://github.com/jnsmalm/cgltf (or KhronosGroup reference)
- **License:** MIT
- **Purpose:** Single-header glTF 2.0 loader, lighter than Assimp for glTF-only
  pipelines. Useful once the asset standard is locked to glTF.
- **Recommended approach:** Add `cgltf.h` to `third_party/cgltf/` and enable
  via `#define CGLTF_IMPLEMENTATION` in `tp_mesh.cpp`.

---

## Planned — Medium Priority

### 4. EnTT — Entity Component System
- **URL:** https://github.com/skypjack/entt
- **License:** MIT
- **Purpose:** Data-driven entity system for game objects. Replaces ad-hoc
  array-of-struct patterns. Required for open-world scale entity management.
- **Recommended approach:** Header-only; add `entt/entt.hpp` to
  `third_party/entt/`.

### 5. sol2 + Lua — Scripting
- **URL:** https://github.com/ThePhD/sol2 (bindings) + https://lua.org (Lua 5.4)
- **License:** MIT (sol2), MIT (Lua)
- **Purpose:** Hot-reload gameplay logic, quest scripts, NPC behavior trees.
  Reduces recompile cycles for designers.
- **Recommended approach:** Vendor Lua source (single amalgamation build), then
  add sol2 as a header-only binding layer.

### 6. stb_truetype — World-space text rendering
- **URL:** https://github.com/nothings/stb
- **License:** Public Domain / MIT dual
- **Purpose:** Bake TrueType fonts into textures for in-world floating labels,
  damage numbers, etc. (ImGui handles UI text already.)
- **Recommended approach:** Header-only; add alongside `stb_image.h`.

---

## Planned — Lower Priority / Future

| Library | License | Purpose |
|---------|---------|---------|
| Tracy Profiler | MIT | CPU/GPU frame profiling, zone markers |
| OpenFBX | MIT | Lightweight FBX importer if Assimp is too heavy |
| KTX-Software | Apache 2.0 | KTX2/BasisU GPU texture compression pipeline |
| Ozz Animation | MIT | Skeletal animation runtime (blend trees, IK) |
| ImGuizmo | MIT | Scene editor gizmos (translate/rotate/scale handles) |
| ImPlot | MIT | In-editor graphs and profiling charts |

---

## Notes on Assimp

Assimp is intentionally deferred because:
1. It uses a CMake superbuild with many conditional importers.
2. Compiling all importers adds several minutes to build time.
3. Some importers (FBX) use LGPL sub-components; check per-importer licenses.

The safest path is to build Assimp once as a prebuilt DLL/static lib outside
the solution, then add just the include directory and the `.lib` file.
A future PR can add a `scripts/build_assimp.bat` that handles this.

# Asset Pipeline — Current State and Roadmap

## What is implemented now

| Feature | Status |
|---------|--------|
| `Content/` folder layout | ✅ Committed |
| `Content/Materials/*.material.json` | ✅ Placeholder + loader stub |
| `Content/Prefabs/*.prefab.json` | ✅ Placeholder + loader stub |
| `Content/Scenes/*.scene.json` | ✅ Placeholder + loader stub |
| `src/assets/AssetLoader` (JSON parse + log) | ✅ Stub — parses and logs, no GPU resources yet |
| nlohmann/json (MIT) vendored | ✅ `third_party/nlohmann/json.hpp` |
| Dear ImGui (MIT) vendored | ✅ `third_party/imgui/` Win32 + DX11 backends |

## Mesh / model formats

### Current state
No mesh loader is included yet.  The forest trees are generated procedurally in code (`src/game/Forest.cpp`).

### Recommended next step: cgltf (single-file glTF 2.0 loader)

**cgltf** is a single-file C library (MIT licence) that loads glTF 2.0 and GLB files.  It has no external dependencies and is small enough to vendor directly.

To add it:
1. Download `cgltf.h` from https://github.com/jkuhlmann/cgltf (MIT licence).
2. Place it at `third_party/cgltf/cgltf.h` and commit the licence.
3. In **one** `.cpp` file add:
   ```cpp
   #define CGLTF_IMPLEMENTATION
   #include "../../third_party/cgltf/cgltf.h"
   ```
4. Add a `src/assets/GltfLoader.hpp/.cpp` stub that calls `cgltf_load_buffers` and logs node names.
5. Later: walk the mesh primitives and upload vertex/index data to D3D11 buffers.

### Assimp (full mesh importer)

Assimp supports ~40 formats (FBX, OBJ, GLTF, Collada, …) but is a large dependency (~6 MB headers + libs).  Not vendored in this PR.

**Recommended approach:**
- Install via **vcpkg**: `vcpkg install assimp:x64-windows`
- Or download a prebuilt release from https://github.com/assimp/assimp/releases (MIT licence, LGPL2.1 for some importers — check individual importer licences).
- Add `assimp/include` to the VC++ include path and link `assimp-vc143-mt.lib`.

## Content folder layout

```
Content/
  Shaders/        HLSL source files (future: hot-reload from here)
  Textures/       PNG / TGA / DDS textures for materials
  Models/         .obj / .gltf / .glb meshes
  Materials/      *.material.json  (shader + texture binding)
  Prefabs/        *.prefab.json    (mesh + material + default transform)
  Scenes/         *.scene.json     (list of prefab instances)
```

## JSON formats

### Material
```json
{
  "name": "tree_bark",
  "shader": "Shaders/basic3d",
  "textures": { "albedo": "Textures/bark.png", "normal": "Textures/bark_n.png" },
  "params":   { "roughness": 0.8, "metallic": 0.0 }
}
```

### Prefab
```json
{
  "name": "tree_oak",
  "mesh": "Models/tree_oak.obj",
  "material": "Materials/tree_bark.material.json",
  "defaults": { "scale": [1,1,1] }
}
```

### Scene
```json
{
  "name": "forest",
  "version": 1,
  "instances": [
    { "prefab": "Prefabs/tree_oak.prefab.json", "pos": [10,0,20], "yaw": 0.0, "scale": [1,1,1] }
  ]
}
```

## AI-assisted asset creation tips

- **Textures** — Generate albedo / normal / roughness maps with AI tools (e.g. Stable Diffusion + ControlNet), export as PNG at 512×512 or 1024×1024.
- **Meshes** — Use AI tools (Meshy, Tripo3D) to generate low-poly OBJ / GLTF, keep under 5 000 triangles per LOD0 for GT610.
- **JSON files** — Paste the format above into an AI chat and ask it to fill in values; the loader will parse them automatically.
- **Scenes** — Hand-place instances in `test.scene.json` or build a future ImGui "place tool" that writes scene JSON.

## Performance targets (GT610 / D3D11)

| Metric | Low preset |
|--------|-----------|
| Resident textures | ≤ 128 MB |
| Triangles per scene | ≤ 200 000 |
| Draw calls | ≤ 100 |
| Dynamic lights | ≤ 4 |
| Post-process passes | ≤ 1 |

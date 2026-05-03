# Third-Party Libraries

This document describes every vendored third-party library in `third_party/`,
how to update them, and the license policy for this project.

---

## License policy

All vendored code **must** use a permissive license suitable for a commercial
game release.  Accepted licenses:

| License        | Notes |
|----------------|-------|
| MIT            | ✅ Accepted |
| Public Domain  | ✅ Accepted (Unlicense / CC0 / stb-style) |
| MIT-0          | ✅ Accepted (attribution-free MIT variant) |
| Apache 2.0     | ✅ Accepted (patent grant included) |
| zlib           | ✅ Accepted (attribution in docs, not binary) |
| BSD 2-Clause   | ✅ Accepted |
| BSD 3-Clause   | ✅ Accepted |
| LGPL           | ⚠️ Avoid unless dynamically linked |
| GPL            | ❌ Not permitted |

Include a `LICENSE.txt` file **inside** each vendor folder.

---

## Vendored libraries

### `third_party/imgui/` — Dear ImGui v1.91.9b
- **License:** MIT (`third_party/imgui/LICENSE.txt`)
- **Purpose:** In-game UI (pause menu, debug overlay, future editor panels)
- **Files compiled:** `imgui.cpp`, `imgui_draw.cpp`, `imgui_tables.cpp`,
  `imgui_widgets.cpp`, `backends/imgui_impl_win32.cpp`,
  `backends/imgui_impl_dx11.cpp`
- **Home page:** https://github.com/ocornut/imgui
- **Update:** Download the release archive, replace the files listed above.
  Check `BACKENDS/imgui_impl_dx11.cpp` API for breaking changes.

### `third_party/nlohmann/json.hpp` — nlohmann/json v3.11.3
- **License:** MIT (`third_party/nlohmann/LICENSE.txt`)
- **Purpose:** JSON parsing for `.material.json`, `.prefab.json`, `.scene.json`
- **Files compiled:** header-only (included where needed)
- **Home page:** https://github.com/nlohmann/json
- **Update:** Download the single-header release from the GitHub releases page
  and replace `json.hpp`.

### `third_party/stb/` — stb_image / stb_image_write
- **License:** Public Domain / MIT dual (`third_party/stb/LICENSE.txt`)
- **Purpose:** Load PNG, JPG, TGA, BMP, HDR images into CPU memory.
  Used by `ThirdParty/src/tp_image.cpp`.
- **Files compiled:** header-only via `#define STB_IMAGE_IMPLEMENTATION`
  in `tp_image.cpp`.
- **Home page:** https://github.com/nothings/stb
- **Update:** Download `stb_image.h` and `stb_image_write.h` from the `master`
  branch and replace the files.

### `third_party/miniaudio/` — miniaudio v0.11.25
- **License:** Public Domain / MIT-0 dual (`third_party/miniaudio/LICENSE.txt`)
- **Purpose:** Audio playback (WAV, MP3, FLAC, OGG).
  Used by `ThirdParty/src/tp_audio.cpp`.
- **Files compiled:** header-only via `#define MINIAUDIO_IMPLEMENTATION`
  in `tp_audio.cpp`.
- **Home page:** https://github.com/mackron/miniaudio
- **Update:** Download `miniaudio.h` from the `master` branch and replace the
  file.  Check for API breaking changes in `CHANGES.md`.

### `third_party/jolt/` — Jolt Physics v5.3.0
- **License:** MIT (`third_party/jolt/LICENSE.txt`)
- **Purpose:** Rigid body physics simulation (ground, spheres, capsules,
  constraints).  Used by `ThirdParty/src/tp_physics.cpp`.
- **Build approach:** Individual `.cpp` files listed in `ThirdParty.vcxproj`.
  (`jolt_all.cpp` is kept as a reference but is **not** compiled; the unity
  build caused C2084 duplicate-definition errors in MSVC when `Character.cpp`
  and `Ragdoll.cpp` were in the same translation unit.)
- **MSVC flags:** SSE2 baseline only (GT610 compatible).
  No AVX/AVX2/SSE4.x enabled.  `JPH_DEBUG_RENDERER_OFF` is set via project
  preprocessor definitions (not in source).
- **Home page:** https://github.com/jrouwe/JoltPhysics
- **Update:**
  1. Download the new release archive.
  2. Replace `third_party/jolt/Jolt/` with the new `Jolt/` directory.
  3. Update the Jolt `<ClCompile>` entries in `ThirdParty.vcxproj` to match
     any `.cpp` files added or removed in the new release.
  4. Check the Jolt changelog for API breaking changes.

### `third_party/recast/` — Recast & Detour v1.6.0
- **License:** zlib (`third_party/recast/LICENSE.txt`)
- **Purpose:** Navmesh generation (Recast) and pathfinding queries (Detour).
  Used by `ThirdParty/src/tp_navigation.cpp`.
- **Files compiled:** All `.cpp` files from `Recast/Source/`,
  `Detour/Source/`, `DetourCrowd/Source/`, `DetourTileCache/Source/`
  (listed in `ThirdParty.vcxproj`).
- **Home page:** https://github.com/recastnavigation/recastnavigation
- **Update:**
  1. Download the new release archive.
  2. Replace the four subdirectories in `third_party/recast/`.
  3. Update `ThirdParty.vcxproj` if any `.cpp` files were added or removed.

---

## Verification checklist

When updating a vendored library, verify:

1. ✅ License file is still present and license type unchanged.
2. ✅ Build succeeds in Debug x64 and Release x64.
3. ✅ Existing wrapper API (`tp_*.hpp`) still compiles cleanly.
4. ✅ Run the game and check `OutputDebugString` log for `[ThirdParty]` init
   messages (audio, physics, nav should all say "Initialized" or similar).
5. ✅ No new warnings at `/W3` level in game project or ThirdParty project.

---

## Adding a new library

1. Create `third_party/<name>/` and copy the source.
2. Add a `LICENSE.txt` in that folder.
3. Add a wrapper under `ThirdParty/src/tp_<name>.hpp/.cpp`.
4. Add the source files to `ThirdParty/ThirdParty.vcxproj`.
5. Update this document.
6. Update `docs/ROADMAP_VENDORING.md` (move from planned → done).

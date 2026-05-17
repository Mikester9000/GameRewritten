# GameRewritten

A beginner-friendly Direct3D 11 game engine seed targeting Windows / GT 610.

---

## Building

Open `GameRewritten.slnx` in Visual Studio 2022 and build **Debug | x64** or
**Release | x64**.  Both configurations build the `ThirdParty` static library
first, then the game executable.

---

## Tracy Profiler (Debug only)

[Tracy](https://github.com/wolfpld/tracy) is a low-overhead CPU frame
profiler.  It is **automatically enabled in Debug builds** via the
`GR_ENABLE_TRACY` and `TRACY_ENABLE` preprocessor macros defined in both
`ThirdParty.vcxproj` and `GameRewritten.vcxproj`.

**Release builds include no Tracy client code** — the macros are not defined,
so all zone markers expand to nothing.

### How to use Tracy zones in game code

```cpp
#include "tp_tracy.hpp"   // from ThirdParty/src/

// Mark the end of every rendered frame:
GR_FRAME_MARK;

// Wrap any code block with a named profiling zone:
{ GR_ZONE_SCOPED_N("My Zone"); doExpensiveWork(); }
```

### Connecting the profiler UI

1. Download the Tracy profiler UI from the
   [Tracy releases page](https://github.com/wolfpld/tracy/releases)
   (look for `Tracy-*.zip`).
2. Run `Tracy.exe`.
3. Start a **Debug** build of the game.
4. The profiler connects automatically on `localhost` and displays a
   real-time frame timeline.

Zones currently instrumented:

| Zone name | Location |
|-----------|----------|
| `Asset Load` | `Main.cpp` — content asset loading block |
| `Physics Step` | `Main.cpp` — Jolt one-step smoke test |
| `Renderer Frame` | `Main.cpp` — ClearScreen → PresentFrame |
| FrameMark | `Main.cpp` — end of each game-loop iteration |

---

## DirectXTex — Runtime Texture Loading

[DirectXTex](https://github.com/microsoft/DirectXTex) is vendored under
`third_party/DirectXTex/` and compiled into `ThirdParty.lib` for **all**
configurations (Debug and Release).

The wrapper is `ThirdParty/src/tp_texture.hpp` / `tp_texture.cpp`.

### API

```cpp
#include "tp_texture.hpp"

// Load any supported format (PNG/JPG/BMP/TIFF via WIC, DDS, TGA, HDR):
tp::TextureInfo info;
if (tp::Texture::LoadFromFile(L"Content/Textures/diffuse.dds", info))
{
    // info.width, info.height, info.format (DXGI_FORMAT), info.mipLevels
}

// Narrow-string overload:
tp::Texture::LoadFromFile("Content/Textures/diffuse.png", info);

// Startup smoke test (called once in Main.cpp):
tp::Texture::SmokeTest();   // logs result of loading placeholder.png
```

stb_image (`tp::Image`) is **not replaced** — both coexist.
DirectXTex adds DDS / BCn decode support that stb_image lacks.

### Future offline DDS/BCn pipeline

A command-line converter tool stub can live at `tools/TextureCooker/`.
It would reuse the same vendored `third_party/DirectXTex/` sources (no
duplication) and call:

```
LoadFromWICFile(src)  →  Compress(BC1 / BC3 / BC7)  →  SaveToDDSFile(dst)
```

This keeps the offline pipeline isolated from the runtime loader and lets
artists convert PNG assets to compressed DDS as a pre-build step for
significant VRAM savings on GT 610.  See `docs/ROADMAP_VENDORING.md` for
the planned implementation approach.

---

## Third-party libraries

See `docs/THIRD_PARTY.md` for a full list of vendored libraries, their
licenses, and update instructions.

See `docs/ROADMAP_VENDORING.md` for planned future dependencies.

---

## Autonomous local-LLM workflow

For underpowered local LLM execution, use:
- `docs/AUTOPILOT_WORKFLOW.md` (run loop)
- `docs/WORST_LLM_MODE.md` (strictest mode, lowest reasoning load)
- `docs/NEXT_TASK.md` (single active task)
- `docs/FULL_TASK_SEQUENCE.md` (complete ordered project path)
- `python tools/llm/advance_next_task.py` (auto-generate task card)
- `python tools/llm/worst_llm_guard.py start|complete` (guarded start/finish commands)

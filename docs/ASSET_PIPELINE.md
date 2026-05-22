# Asset Pipeline Integration

This document describes how the three external tool repositories feed
content into GameRewritten.

---

## Tool Repositories (git submodules)

| Engine | Submodule path | Purpose |
|---|---|---|
| Audio Engine | `tools/engines/audio-engine` | Generates all audio files |
| Animation Engine | `tools/engines/animation-engine` | Generates animation clips and skeletons |
| Creation Engine | `tools/engines/creation-engine` | Generates textures, meshes, maps, and all other assets |

Clone with submodules:
```
git clone --recurse-submodules https://github.com/Mikester9000/GameRewritten.git
```

Update all submodules to latest:
```
git submodule update --remote --merge
```

---

## Audio Engine → `Content/Audio/`

**Repo:** `Mikester9000/Audio-Engine`
**Submodule:** `tools/engines/audio-engine`

### What it produces
- Background music tracks (`.ogg`)
- Sound effects (`.wav`)
- DSP-processed audio exports

### Workflow
1. `cd tools/engines/audio-engine`
2. Follow setup steps in `WINDOWS_QUICKSTART.md` or `README.md`
3. Author / export audio assets
4. Copy exported files to `Content/Audio/`
5. Update `Content/AssetRegistry.json` with new audio entries

---

## Animation Engine → `Content/Animations/`

**Repo:** `Mikester9000/Animation-Engine`
**Submodule:** `tools/engines/animation-engine`

### What it produces
- Animation clips (`.anim`)
- Skeleton definitions (`.skel`)

### Workflow
1. `cd tools/engines/animation-engine`
2. Install dependencies: `pip install -r requirements.txt`
3. Author / export animation clips
4. Copy exported files to `Content/Animations/`
5. Update `Content/AssetRegistry.json` with new animation entries

---

## Creation Engine → `Content/Textures/`, `Content/Models/`, `Content/Materials/`, `Content/World/`

**Repo:** `Mikester9000/Creation-Engine`
**Submodule:** `tools/engines/creation-engine`

### What it produces
- Textures (`.png`, `.dds`)
- 3-D meshes / models
- World/map data
- Material definitions

### Workflow
1. `cd tools/engines/creation-engine`
2. Build or install the engine (see `README.md` / `CMakeLists.txt`)
3. Author assets using the Creation Engine editor
4. Run the GameRewritten bundle exporter:
   ```
   python creation_engine/game_rewritten_bundle.py --output ../../Content/
   ```
5. Exported files land automatically in the correct `Content/` subdirectories
6. Update `Content/AssetRegistry.json` if new assets were added

---

## Content Directory Map

```
Content/
  Audio/          ← Audio Engine exports
  Animations/     ← Animation Engine exports
  Textures/       ← Creation Engine exports
  Models/         ← Creation Engine exports
  Materials/      ← Creation Engine exports
  World/          ← Creation Engine exports
  Scenes/
  Prefabs/
  Shaders/
  AssetRegistry.json
```

---

## AssetRegistry.json

All content loaded at runtime is indexed in `Content/AssetRegistry.json`.
After exporting from any engine, add new entries following the existing format.

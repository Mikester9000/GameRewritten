# Asset Pipeline Integration

The three external engine repositories are **standalone tools** — they are not
embedded in this repo.  You clone and run each engine separately, export files,
then place the output in the appropriate `Content/` subdirectory.

Use `tools/import_assets.py` to copy outputs and update `Content/AssetRegistry.json`
automatically (see bottom of this document).

---

## Engine Summary

| Engine repo | Produces | Destination |
|---|---|---|
| `Mikester9000/Audio-Engine` | `.wav`, `.ogg` | `Content/Audio/` |
| `Mikester9000/Animation-Engine` | `.anim` (JSON), `.gltf`+`.bin` | `Content/Animations/` |
| `Mikester9000/Creation-Engine` | `.png` (textures), `.obj`+`.mtl` (meshes), `.json` (maps/manifests) | `Content/Textures/`, `Content/Models/`, `Content/Materials/`, `Content/World/`, `Content/UI/` |

---

## Audio Engine → `Content/Audio/`

**Repo:** `https://github.com/Mikester9000/Audio-Engine`

### Export formats

| Extension | Format | Notes |
|---|---|---|
| `.wav` | 16-bit signed PCM, 44 100 Hz, mono or stereo | Default; no extra Python deps |
| `.ogg` | Vorbis-compressed | Requires `soundfile` extra |

### GameRewritten compatibility

`tp::Audio::PlayOneShot` (via **miniaudio**) natively accepts `.wav`, `.ogg`,
`.mp3`, and `.flac`.  Both Audio Engine output formats load directly — no
conversion step needed.

### Setup

```
git clone https://github.com/Mikester9000/Audio-Engine
cd Audio-Engine
pip install -e ".[soundfile]"   # soundfile optional for .ogg output
```

### Export commands

Generate the complete game audio library (BGM + SFX + voice):
```
audio-engine generate-game-assets --output-dir ./audio_export
```

Generate a single BGM track:
```
audio-engine generate-music --prompt "dark ambient dungeon 90 BPM" --duration 60 --output ./audio_export/bgm_dungeon.ogg
```

Generate a single SFX:
```
audio-engine generate-sfx --prompt "sword slash swoosh" --duration 0.4 --output ./audio_export/sfx_attack.wav
```

Validate all exported WAV files:
```
audio-engine qa-batch --input-dir ./audio_export
```

### Copy to GameRewritten

Manual:
```
cp audio_export/*.wav  GameRewritten/Content/Audio/
cp audio_export/*.ogg  GameRewritten/Content/Audio/
```

Or use the import helper:
```
python GameRewritten/tools/import_assets.py --engine audio --src ./audio_export
```

### Expected files (referenced in source)

| File | Used by |
|---|---|
| `Content/Audio/bgm_field.ogg` | `Main.cpp:209` `audioManager.PlayBGM(...)` |
| `Content/Audio/sfx_attack.wav` | `Main.cpp:83` `audioManager.PlaySFX(...)` |

---

## Animation Engine → `Content/Animations/`

**Repo:** `https://github.com/Mikester9000/Animation-Engine`

### Export formats

| Extension | Format | Notes |
|---|---|---|
| `.anim` | AnimEngine JSON 1.0 — contains model, skeleton, clips, morph tracks in one file | Native format; human-readable |
| `.gltf` + `.bin` | glTF 2.0 — industry-standard skinned mesh + animation | Supported by Blender, Unreal, Unity |

**`.anim` JSON structure:**
```json
{
  "format": "AnimEngine",
  "version": "1.0",
  "model":  { ... },
  "clips":  [ { "name": "attack", "fps": 30, "keyframes": [...] }, ... ],
  "morph_tracks": [ ... ]
}
```

### GameRewritten compatibility

GameRewritten's C++ runtime does not yet have an animation loader.
`.anim` is pure JSON (readable with any JSON parser) and `.gltf` is the
industry standard.  Both are the correct formats to store in `Content/Animations/`
until the C++ loader is implemented.

Animation clips include gameplay semantic metadata already tagged for this
game: `idle`, `walk`, `run`, `attack`, `attack_combo_1/2/3`, `heavy_attack`,
`dodge`, `roll`, `parry`, `hit_react`, `death`, etc., each with root-motion
policy and interaction tags (`hit_window`, `cancel_window`, `invincibility_window`).

### Setup

```
git clone https://github.com/Mikester9000/Animation-Engine
cd Animation-Engine
pip install -r requirements.txt
```

### Export commands

Generate a full animation pack from a skeleton source:
```
animation-engine generate-pack \
  --skeleton-anim ./skeletons/player.anim \
  --output-dir ./anim_export \
  --profile default
```

Export to glTF 2.0 (Python API):
```python
from animation_engine.io import GltfExporter
exporter = GltfExporter()
exporter.export(model, clips, "anim_export/player.gltf")
```

Validate clips before copying:
```
animation-engine validate-clip --input ./anim_export/player.anim
animation-engine check-loop    --input ./anim_export/player.anim
```

### Copy to GameRewritten

```
cp anim_export/*.anim  GameRewritten/Content/Animations/
cp anim_export/*.gltf  GameRewritten/Content/Animations/
cp anim_export/*.bin   GameRewritten/Content/Animations/
```

Or use the import helper:
```
python GameRewritten/tools/import_assets.py --engine animation --src ./anim_export
```

---

## Creation Engine → `Content/Textures/`, `Content/Models/`, `Content/Materials/`, `Content/World/`, `Content/UI/`

**Repo:** `https://github.com/Mikester9000/Creation-Engine`

The Creation Engine was built specifically for GameRewritten — its exporter
`content_target` fields are already hard-coded to the correct `Content/`
subdirectories.

### Export formats

| Type | Extension | Destination |
|---|---|---|
| PBR texture maps (`albedo`, `metallic`, `roughness`, `normal`, `occlusion`) | `{name}_{channel}.png` | `Content/Textures/` |
| Asset manifests (per-asset metadata) | `{name}.json` | alongside the asset |
| 3-D meshes | `{name}.obj` + `{name}.mtl` | `Content/Models/` |
| World tilemaps | `{name}.json` | `Content/World/` |
| UI icons / panels / portraits | `.png` | `Content/UI/` |
| Full bundle | all of the above | `Content/` (routed automatically) |

### GameRewritten compatibility

- **Textures:** `tp::Image::Load` (stb_image) natively reads `.png` — no conversion needed.
- **Meshes:** `.obj` is a plain-text triangulated mesh (vertices, normals, UVs, faces).
  The C++ rendering layer currently uses procedural geometry; a model loader is needed
  to consume `.obj` files at runtime.
- **World maps:** `.json` tilemap files are read by the `WorldGrid` system.

Terrain texture filenames referenced by the renderer:

| File | Engine key |
|---|---|
| `Content/Textures/Grassland1.png` | `textures.grassland` |
| `Content/Textures/Desert1.png` | `textures.desert` |
| `Content/Textures/Mountain1.png` | `textures.mountain` |
| `Content/Textures/Snowy1.png` | `textures.snowy` |

These exact filenames are hard-coded in `src/rendering/d3d11/D3D11Renderer.cpp:27-30`.

### Setup

```
git clone https://github.com/Mikester9000/Creation-Engine
cd Creation-Engine
pip install -e .
```

### Export commands

**Full GameRewritten bundle** (all asset types, all packs):
```
creation-engine full-bundle --output ./creation_export --seed 42
```

**Individual exports:**
```
creation-engine texture --prompt "ps2 jrpg forest ground" --output ./creation_export --name Grassland1
creation-engine mesh    --prompt "ps2 jrpg stone pillar"  --output ./creation_export --name pillar
creation-engine map     --prompt "ps2 jrpg overworld"     --output ./creation_export --name world
```

**Validate before copying:**
```
creation-engine quality-check --output ./creation_export
```

### Copy to GameRewritten

The easiest method is the import helper — it reads `content_target` from each
manifest and routes every file to the correct directory automatically:
```
python GameRewritten/tools/import_assets.py --engine creation --src ./creation_export
```

Manual copy:
```
cp creation_export/*_albedo.png    GameRewritten/Content/Textures/
cp creation_export/*.obj           GameRewritten/Content/Models/
cp creation_export/*.mtl           GameRewritten/Content/Materials/
cp creation_export/world*.json     GameRewritten/Content/World/
```

---

## Content Directory Map

```
Content/
  Audio/          ← Audio Engine:     .wav, .ogg
  Animations/     ← Animation Engine: .anim, .gltf, .bin
  Textures/       ← Creation Engine:  {name}_albedo.png, {name}_normal.png, …
  Models/         ← Creation Engine:  {name}.obj, {name}.mtl
  Materials/      ← Creation Engine:  {name}.json manifests (shader/material metadata)
  World/          ← Creation Engine:  {name}.json tilemaps
  UI/             ← Creation Engine:  UI icons, panels, portraits (.png)
  Bundles/        ← Creation Engine:  full-bundle output packages
  Scenes/         — hand-authored scene files
  Prefabs/        — hand-authored prefab files
  Shaders/        — HLSL shader files
  AssetRegistry.json
```

---

## Import Helper: `tools/import_assets.py`

`tools/import_assets.py` automates copying files from an engine's export
directory into the correct `Content/` subdirectory and updates
`Content/AssetRegistry.json`.

```
# Copy audio output
python tools/import_assets.py --engine audio --src /path/to/audio_export

# Copy animation output
python tools/import_assets.py --engine animation --src /path/to/anim_export

# Copy creation engine output (reads content_target from manifests)
python tools/import_assets.py --engine creation --src /path/to/creation_export

# Dry-run (print what would be copied without actually copying)
python tools/import_assets.py --engine creation --src ./creation_export --dry-run
```

---

## AssetRegistry.json

All content loaded at runtime is indexed in `Content/AssetRegistry.json`.
Keys follow the pattern `<type>.<name>`, e.g. `textures.grassland` or
`audio.bgm_field`.

After any import, new entries are appended automatically by `import_assets.py`.
To add entries manually, follow the existing format:
```json
"audio.bgm_field":    "Content/Audio/bgm_field.ogg",
"audio.sfx_attack":   "Content/Audio/sfx_attack.wav",
"textures.grassland": "Content/Textures/Grassland1.png"
```

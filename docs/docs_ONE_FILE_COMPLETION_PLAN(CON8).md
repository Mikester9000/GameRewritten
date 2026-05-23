# docs_ONE_FILE_COMPLETION_PLAN(CON8).md

Continuation/addendum 8 for **external engine asset compatibility**: loading and integrating exported files from `Mikester9000/Animation-Engine` (`.anim` packs + `pack_manifest.json`), `Mikester9000/Audio-Engine` (`audio_plan.*.json` + WAV/OGG assets), and `Mikester9000/Creation-Engine` (material JSON v1.1, PBR PNGs, tilemap JSON v1.0, OBJ meshes).
Every task uses fields **0-8** and is formatted for manual copy/paste workflows.

---

## Verification Summary
- Base file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN.md`
- CON1 file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON1).md`
- CON2 file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON2).md`
- CON3 file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/ONE_FILE_COMPLETION_PLAN(CON3).md`
- CON4 file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/docs_ONE_FILE_COMPLETION_PLAN(CON4).md`
- CON5 file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/docs_ONE_FILE_COMPLETION_PLAN(CON5).md`
- CON6 file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/docs_ONE_FILE_COMPLETION_PLAN(CON6).md`
- CON7 file reviewed: `/tmp/workspace/Mikester9000/GameRewritten/docs/docs_ONE_FILE_COMPLETION_PLAN(CON7).md`
- Base plan task count: **108** primary tasks (001-108) + **93** header companions (001H-107H).
- CON1 task count: **246** open-world/graphics tasks.
- CON2 task count: **90** AAA modern systems tasks.
- CON3 task count: **52** PS2 handmade polish tasks.
- CON4 task count: **44** animation fluidity/combat juice/FF tradition tasks (311-354).
- CON5 task count: **72** FF signature systems/progression/social/minigames tasks (335-370).
- CON6 task count: **14** localization/weather/audio-camera/journal/zone tasks (371-377).
- CON7 task count: **20** PC release essentials tasks (383-392).
- CON8 purpose: this file integrates external engine exports — Animation-Engine `.anim` packs, Audio-Engine `audio_plan` manifests + WAV/OGG assets, Creation-Engine material JSON/PBR textures/tilemap JSON/OBJ meshes — so GameRewritten can load and use all generated content at runtime without manual hand-coding assets.
- Tasks in this addendum: **32** total — **16** implementation `.cpp` tasks (393-408) + **16** header `.hpp` companions (393H-408H).

---

## External Engine Export Contracts (READ BEFORE ANY TASK)

### Animation-Engine (`Mikester9000/Animation-Engine`)
- **Pack manifest:** `Content/Animations/<character>/pack_manifest.json`
  - Fields: `format:"AnimEngine"`, `version:"1.0"`, `style_profile`, `visual_target`, `gameplay_target`, `reference_titles[]`, `ordered_files[]` (list of `.anim` paths in playback order)
  - Required clips by name: `idle`, `walk`, `run`, `attack`, `defend`, `cast`, `hit_react`, `dodge`, `jump_start`, `jump_loop`, `jump_land`, `victory`
- **Clip file:** `Content/Animations/<character>/<clip_name>.anim` (JSON)
  - Top-level fields: `format`, `version`, `model` (name, meshes[], materials[], skeleton{bones[], inverse_bind[]}), `clips[]`, `morph_tracks[]`, `metadata`
  - Each `clip` entry: `name`, `fps`, `loop` (bool), `duration_sec`, `channels[]`
  - Each `channel`: `bone_name`, `target` (`translation`|`rotation`|`scale`), `interpolation` (`STEP`|`LINEAR`|`CUBIC`), `keyframes[]` (`{ "time": float, "value": [x,y,z] or [x,y,z,w] }`)
  - `root_motion`: `enabled` (bool), `channel_index` (int)
  - `events[]`: `{ "time": float, "type": "footstep"|"contact"|"hit"|"cancel"|"cast_release", "bone": string, "data": {} }`
- **C++ bridge header:** `Animation-Engine/compat/GameEngineCompat.hpp` (header-only, C++17)
  - `AnimLoader::Load(path)` → `AE_AnimPackage`
  - Types: `AE_AnimPackage`, `AE_Clip`, `AE_Channel`, `AE_Keyframe`, `AE_Event`
  - Components: `AnimationComponent`, `SkinnedSpriteComponent`, `MorphWeightComponent`
  - System: `AnimationSystem` — call `AnimationSystem::Advance(dt, components)` per frame
- **Include path:** Add `path/to/Animation-Engine` to `GameRewritten.vcxproj` include path so `#include "compat/GameEngineCompat.hpp"` resolves.
- **Validation gate:** Run `animation-engine validate-pack --manifest <path>` before any runtime import. Non-zero exit = hard stop.

### Audio-Engine (`Mikester9000/Audio-Engine`)
- **Music manifest:** `Content/Audio/music/audio_plan.music.json`
  - Top-level: `version`, `assetGroups[]`
  - Each group: `groupId`, `category` (`exploration`|`battle`|`boss`|`cinematic`|`memorial`|`fanfare`|`ending`), `requests[]`
  - Each request: `requestId`, `assetId`, `prompt`, `seed`, `targetPath` (WAV/OGG relative to Content/), `durationSec`, `loop` (bool), `tags[]`
- **SFX manifest:** `Content/Audio/sfx/audio_plan.sfx.json`
  - Same schema but category = `combat`|`traversal`|`spell`|`interaction`|`ui`
- **Asset files:** WAV (music, SFX) and OGG (long-form music) at `targetPath` relative to the Content root.
- **C++ integration header:** `Audio-Engine/audio_engine/integration/cpp/AudioSystem.hpp`
  - `AudioSystem::Init()`, `AudioSystem::Shutdown()`
  - `AudioSystem::PlayMusic(assetId, fadeInSec)` — starts looping BGM
  - `AudioSystem::StopMusic(fadeOutSec)` — fades out current BGM
  - `AudioSystem::CrossfadeTo(assetId, crossfadeSec)` — smooth BGM transition
  - `AudioSystem::PlayOneShot(assetId)` — fires SFX without loop handle
  - `AudioSystem::OnStateChange(newState)` — drives automatic BGM switching
  - Game states: `AudioState::Exploration`, `AudioState::Battle`, `AudioState::Boss`, `AudioState::Cinematic`, `AudioState::Camp`, `AudioState::Shop`
- **Existing gap:** `tp::Audio` only supports `PlayOneShot`/`Init`/`Shutdown`/`IsInitialized`. Tasks 399-403 fill this gap with managed looping and state routing layered on top.
- **Validation gate:** `audio-engine quality-check` then `audio-engine bundle-audit` must both pass before import.

### Creation-Engine (`Mikester9000/Creation-Engine`)
- **Material manifest:** `Content/Materials/<name>.json`
  - Schema v1.1: `{ "version":"1.1", "name":string, "shader":"Shaders/basic3d", "params":{ "color":[R,G,B,A], "roughness":float, "metallic":float, "ao":float, "emissive":[R,G,B] }, "textures":{ "albedo":string, "normal":string, "roughness":string, "metallic":string, "ao":string, "emissive":string } }`
  - Legacy back-compat: also emits `params.baseColor` (same value as `params.color`).
  - All texture paths are relative to `Content/`.
- **PBR textures:** PNG files at the paths listed in `textures` map. Six channels: albedo, normal, roughness, metallic, AO, emissive.
- **Tilemap manifest:** `Content/Tilemaps/<name>.json`
  - Schema v1.0: `{ "version":"1.0", "width":int, "height":int, "tileSize":int, "tileset":string, "tiles":[int …], "props":[ {"type":string, "x":int, "y":int, "label":string} ] }`
  - Tile IDs 0–15 map to the `TileType` enum in WorldGrid.
  - `props[]` entries are spawnable objects placed in the world.
- **Mesh:** OBJ file + MTL + manifest JSON (`style_profile`, `content_target`, mesh file paths).
- **Bundle command:** `creation-engine full-bundle --seed <N> --output Content`
- **Validation gates:** `creation-engine quality-check` (checks `style_profile`, `content_target`, referenced file presence) then `creation-engine bundle-audit` (FF aesthetic compliance check). Both must pass before runtime import.
- **AssetRegistry.json IDs:** Use lower-case scoped IDs (e.g., `"materials.grassland_road"`) that must be registered in `Content/AssetRegistry.json` so existing asset pipeline can resolve them.

---

## Execution Rule (No Thinking Required)
1. Read this addendum plus all previous CON files and the base one-file plan.
2. Execute **one task** per run.
3. Use absolute paths only.
4. Output copy-ready payload only.
5. Update required docs for each completed task.
6. Stop after one task.

## Message Visibility Fallback (If outputs are not appearing)
1. Print `STATUS: START Task ###` first.
2. Print one file payload at a time.
3. Split long output and label:
   - `STATUS: CHUNK 1/N`
   - `STATUS: CHUNK 2/N`
4. End with `STATUS: DONE Task ###`.

## Mandatory micro-steps per task
1. Read listed file once using listed line range.
2. Make only minimum edits.
3. Keep edits inside the listed file.
4. Do not rename/move files.
5. Do not add dependencies beyond what this file specifies.
6. Keep GT610-safe defaults.
7. Return copy-ready output only.

## Global Constraints
- One task per run.
- Never touch files outside the listed file for a task.
- All new `.cpp` files must start with the standard file header (FILE / SYSTEM / ROLE / DO NOT / OWNS lines).
- All new `.hpp` files must use `#pragma once` and the standard file header.
- GT610-safe: no compute shaders, no tessellation, no DX12 features.
- PBR textures: bind as `ID3D11ShaderResourceView*` using existing texture-load infrastructure (see `ThirdParty/src/tp_texture.hpp`).
- JSON parsing: use `nlohmann/json` if already in the project, otherwise use `std::ifstream` + manual string parsing — do NOT add a new JSON library.
- `.anim` and material JSON files may be large. Read them once, cache in a static map keyed by assetId string.

## Full-System Policy
- Animation tasks (393-398): complete before Audio tasks (399-403).
- Audio tasks (399-403): complete before Creation tasks (404-408).
- All three groups must pass their respective validation gates before the release gate (Task 120 in CON1) can be signed off.
- Do not modify `tp::Audio` internals — layer the managed player on top.

## Task Ownership Matrix
| Task Range | System              | Source Repo                        |
|------------|---------------------|------------------------------------|
| 393-398    | Animation-Engine    | Mikester9000/Animation-Engine      |
| 399-403    | Audio-Engine        | Mikester9000/Audio-Engine          |
| 404-408    | Creation-Engine     | Mikester9000/Creation-Engine       |

## Completion Target
All 32 tasks done = GameRewritten can load, validate, and render/play assets exported by all three companion engine tools without any hand-coded asset data.

## Required Output Contract
Every task output must be a complete, copy-paste-ready file payload.
Format:
```
// ─── PASTE_BLOCK START ── Task NNN ────────────────────────
<full file content — never a diff>
// ─── PASTE_BLOCK END ─────────────────────────────────────
```

---

## ═══════════════════════════════════════════════════
## SECTION A — ANIMATION-ENGINE INTEGRATION (Tasks 393-398H)
## ═══════════════════════════════════════════════════

---

### Task 393 — AnimPackManifestLoader.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimPackManifestLoader.cpp` (new file — 0 lines before edit).

**1. Task Name:** AnimPackManifestLoader — reads `pack_manifest.json`, validates required clips, returns ordered `.anim` file path list.

**2. What it does:**
- Opens `Content/Animations/<character>/pack_manifest.json` with `std::ifstream`.
- Parses JSON fields: `format`, `version`, `style_profile`, `visual_target`, `gameplay_target`, `ordered_files[]`.
- Validates `format == "AnimEngine"` and `version == "1.0"`. Logs error and returns empty vector on mismatch.
- Validates that every required clip name (`idle`, `walk`, `run`, `attack`, `defend`, `cast`, `hit_react`, `dodge`, `jump_start`, `jump_loop`, `jump_land`, `victory`) appears in `ordered_files` as a substring. Logs warning for any missing clip.
- Returns `std::vector<std::string>` of absolute file paths (prepends `Content/Animations/<character>/` to each entry in `ordered_files`).
- Stores `style_profile`, `visual_target`, `gameplay_target` in a static manifest-info struct accessible via `AnimPackManifestLoader::GetManifestInfo(characterName)`.

**3. Narrative logic:** Before any `.anim` file is loaded, the manifest must be read and its clip inventory validated. If a required clip is missing the player or enemy animation state machine will crash trying to look it up. Validate once at startup, fail loud.

**4. Game design target:** PS2-era JRPG character animations with all 12 required gameplay states confirmed present at load time.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/game/animation/AnimPackManifestLoader.cpp
```

**6. Where in file:** New file. Start at line 1 with standard file header.

**7. Additional information:**
- READ_FILE: `src/app/Main.cpp` READ_LINES: 1-7 (for standard header format reference).
- READ_FILE: `Content/AssetRegistry.json` READ_LINES: 1-30 (for path convention reference).
- JSON parsing without extra library: use `std::ifstream` line-by-line + `std::string::find` for key extraction, or wrap a minimal hand-rolled JSON reader. Do NOT add nlohmann/json unless it is already `#include`-able from existing headers.
- LINE_BUDGET: 120 lines maximum.

**8. Copy-ready completion rule:** Output the full file as one PASTE_BLOCK. No diff format. Header included.

---

### Task 393H — Header companion for Task 393 (AnimPackManifestLoader)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimPackManifestLoader.hpp` (new file).

**1. Task Name:** AnimPackManifestLoader.hpp — declares `AnimPackManifestLoader` class and `AnimPackManifestInfo` struct.

**2. What it does:**
- `#pragma once` + standard file header.
- Declares `struct AnimPackManifestInfo { std::string styleProfile; std::string visualTarget; std::string gameplayTarget; };`
- Declares `class AnimPackManifestLoader` with:
  - `static std::vector<std::string> Load(const std::string& characterName);`
  - `static AnimPackManifestInfo GetManifestInfo(const std::string& characterName);`
- All includes: `<string>`, `<vector>`.

**3–7.** See Task 393.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 394 — AnimClipLoader.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimClipLoader.cpp` (new file).

**1. Task Name:** AnimClipLoader — reads a single `.anim` JSON file, returns a populated `LoadedAnimClip` struct.

**2. What it does:**
- Opens the file at the given absolute path with `std::ifstream`.
- Parses top-level fields: `format`, `version`, `clips[]`, `root_motion`, `events[]`.
- For each entry in `clips[]`, reads: `name`, `fps`, `loop`, `duration_sec`, `channels[]`.
- For each `channel`, reads: `bone_name`, `target`, `interpolation`, `keyframes[]`.
- For each `keyframe`, reads `time` (float) and `value` (float array of 3 or 4 elements).
- Reads `events[]`: `time`, `type`, `bone`, `data` (ignored for now — store `type` and `time` only).
- Reads `root_motion.enabled` (bool) and `root_motion.channel_index` (int).
- Returns a `LoadedAnimClip` struct (declared in header) containing all parsed data.
- Logs error and returns empty struct on file-not-found or parse failure.

**3. Narrative logic:** Each `.anim` file is one character's animation pack clip (idle, attack, etc.). The loader reads it once and stores the keyframe arrays in memory for the AnimationSystem to sample each frame.

**4. Game design target:** GT610-safe CPU-side keyframe sampling — no GPU skinning required. Float interpolation only.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/game/animation/AnimClipLoader.cpp
```

**6. Where in file:** New file. Start at line 1.

**7. Additional information:**
- READ_FILE: `src/game/animation/AnimPackManifestLoader.hpp` READ_LINES: 1-30 (for struct/include style reference).
- JSON parsing: same strategy as Task 393 — use `std::ifstream` + `std::string::find`.
- The `value` array for `rotation` channels has 4 floats (quaternion xyzw). For `translation` and `scale`, 3 floats.
- LINE_BUDGET: 180 lines maximum.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 394H — Header companion for Task 394 (AnimClipLoader)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimClipLoader.hpp` (new file).

**1. Task Name:** AnimClipLoader.hpp — declares `AnimKeyframe`, `AnimChannel`, `AnimEvent`, `LoadedAnimClip`, `AnimClipLoader`.

**2. What it does:**
- `#pragma once` + standard header.
- `struct AnimKeyframe { float time; float value[4]; };`
- `struct AnimChannel { std::string boneName; std::string target; std::string interpolation; std::vector<AnimKeyframe> keyframes; };`
- `struct AnimEvent { float time; std::string type; std::string bone; };`
- `struct LoadedAnimClip { std::string name; float fps; bool loop; float durationSec; std::vector<AnimChannel> channels; std::vector<AnimEvent> events; bool rootMotionEnabled; int rootMotionChannelIndex; };`
- `class AnimClipLoader { public: static LoadedAnimClip Load(const std::string& path); };`
- Includes: `<string>`, `<vector>`.

**3–7.** See Task 394.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 395 — AnimationComponent.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimationComponent.cpp` (new file).

**1. Task Name:** AnimationComponent — ECS component that stores the active clip reference and playback state for one actor.

**2. What it does:**
- Defines `AnimationComponent` (not a full ECS component class — a plain struct stored per actor).
- Fields: `const LoadedAnimClip* activeClip` (pointer, not owned), `const LoadedAnimClip* nextClip` (for blending), `float playbackTime`, `float blendAlpha`, `float blendDuration`, `bool playing`.
- `void Update(float dt)`:
  - Advances `playbackTime += dt`.
  - If `playbackTime >= activeClip->durationSec` and `activeClip->loop`, wraps: `playbackTime = fmod(playbackTime, activeClip->durationSec)`.
  - If `playbackTime >= activeClip->durationSec` and `!activeClip->loop`, clamps to `durationSec` and sets `playing = false`.
  - If `nextClip != nullptr`, advances `blendAlpha += dt / blendDuration`. When `blendAlpha >= 1.0f`, completes transition: `activeClip = nextClip; nextClip = nullptr; blendAlpha = 0.0f; playbackTime = 0.0f; playing = true;`.
- `void TransitionTo(const LoadedAnimClip* clip, float crossfadeSec)`:
  - Sets `nextClip = clip; blendDuration = crossfadeSec; blendAlpha = 0.0f;`.
- `std::vector<AnimEvent> GetFiredEvents(float prevTime, float curTime)`:
  - Returns all events in `activeClip->events` where `event.time > prevTime && event.time <= curTime`. Used by AnimEventDispatch.

**3. Narrative logic:** Every actor (player and enemy) has one AnimationComponent. The component drives itself forward per frame and handles crossfade blending between states without the caller needing to manage time.

**4. Game design target:** Smooth 0.15–0.30 second crossfades between idle/walk/run/attack states. Matches FF7R feel.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/game/animation/AnimationComponent.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/game/animation/AnimClipLoader.hpp` READ_LINES: 1-40 (for `LoadedAnimClip` and `AnimEvent` types).
- Include `<cmath>` for `fmod`.
- LINE_BUDGET: 100 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 395H — Header companion for Task 395 (AnimationComponent)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimationComponent.hpp` (new file).

**1. Task Name:** AnimationComponent.hpp — declares the `AnimationComponent` struct.

**2. What it does:**
- `#pragma once` + standard header.
- `#include "AnimClipLoader.hpp"`.
- `#include <vector>`.
- Declares `struct AnimationComponent` with all fields and methods listed in Task 395.

**3–7.** See Task 395.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 396 — AnimationSystem.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimationSystem.cpp` (new file).

**1. Task Name:** AnimationSystem — per-frame system that advances all AnimationComponents and samples bone transforms for the renderer.

**2. What it does:**
- `AnimationSystem::Advance(float dt, std::vector<AnimationComponent>& components)`:
  - For each `AnimationComponent` in `components`, calls `component.Update(dt)`.
  - For each component, calls `SampleClip(*component.activeClip, component.playbackTime, outTransforms)` to produce per-bone transform arrays.
  - If `component.nextClip != nullptr`, also samples `*component.nextClip` at `component.playbackTime * (component.nextClip->durationSec / component.activeClip->durationSec)` and lerps results using `component.blendAlpha`.
  - Writes sampled float3 positions and float4 quaternions into a flat `BoneTransformBuffer` struct (declared in header).
- `float3 SampleChannel(const AnimChannel& ch, float t)`:
  - Finds surrounding keyframes by `time` for `t`.
  - For `STEP`: returns the value of the earlier keyframe.
  - For `LINEAR`: linearly interpolates between surrounding keyframes.
  - For `CUBIC`: use linear as fallback (cubic requires tangents not yet in the format — safe fallback).
  - Returns `float3` for translation/scale channels, quaternion stored as `float4` for rotation.
- Root motion: if `activeClip->rootMotionEnabled`, extract the root bone delta (current sample minus previous frame sample) and store in `BoneTransformBuffer.rootMotionDelta`.

**3. Narrative logic:** The system is the central per-frame engine that keeps all actor animations in sync. Sampling is done on the CPU; results are uploaded to the renderer's constant buffer for VS-level bone offsetting.

**4. Game design target:** GT610-safe — no compute shaders. CPU sample at 60 FPS per actor. Max 64 bones per character.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/game/animation/AnimationSystem.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/game/animation/AnimationComponent.hpp` READ_LINES: 1-40.
- READ_FILE: `src/game/animation/AnimClipLoader.hpp` READ_LINES: 1-40.
- `float3` and `float4` may be aliased from `DirectXMath` as `XMFLOAT3` / `XMFLOAT4`. Use those types.
- `XMQuaternionSlerp` from DirectXMath for rotation blending.
- `XMVectorLerp` for position/scale blending.
- LINE_BUDGET: 200 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 396H — Header companion for Task 396 (AnimationSystem)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimationSystem.hpp` (new file).

**1. Task Name:** AnimationSystem.hpp — declares `BoneTransformBuffer` and `AnimationSystem`.

**2. What it does:**
- `#pragma once` + standard header.
- `#include "AnimationComponent.hpp"`.
- `#include <DirectXMath.h>` and `<vector>`.
- `struct BoneTransform { DirectX::XMFLOAT3 position; DirectX::XMFLOAT4 rotation; DirectX::XMFLOAT3 scale; };`
- `struct BoneTransformBuffer { BoneTransform bones[64]; DirectX::XMFLOAT3 rootMotionDelta; };`
- `class AnimationSystem { public: static void Advance(float dt, std::vector<AnimationComponent>& components, std::vector<BoneTransformBuffer>& outBuffers); private: static DirectX::XMFLOAT3 SampleTranslation(const AnimChannel& ch, float t); static DirectX::XMFLOAT4 SampleRotation(const AnimChannel& ch, float t); };`

**3–7.** See Task 396.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 397 — PlayerAnimBridge.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/PlayerAnimBridge.cpp` (new file).

**1. Task Name:** PlayerAnimBridge — maps `PlayerActionState` enum values to named clips from the loaded animation pack and calls `TransitionTo`.

**2. What it does:**
- `PlayerAnimBridge::Update(PlayerActionState state, AnimationComponent& animComp, const std::unordered_map<std::string, LoadedAnimClip>& clipLibrary)`:
  - Uses a `static PlayerActionState lastState` to detect state changes.
  - On state change, maps the new `PlayerActionState` to a clip name string:
    - `Idle` → `"idle"`, `Walking` → `"walk"`, `Running` → `"run"`,
    - `Attacking` → `"attack"`, `Defending` → `"defend"`, `Casting` → `"cast"`,
    - `HitReacting` → `"hit_react"`, `Dodging` → `"dodge"`,
    - `JumpStart` → `"jump_start"`, `JumpLoop` → `"jump_loop"`, `JumpLand` → `"jump_land"`,
    - `Victory` → `"victory"`.
    - Any unmapped state → `"idle"` (safe fallback).
  - Looks up clip by name in `clipLibrary`. If found, calls `animComp.TransitionTo(&clip, 0.20f)` (20 ms crossfade for action clips) or `0.30f` for idle/walk/run.
  - If clip name not found in library, logs warning and does not change active clip.

**3. Narrative logic:** The bridge is a pure translation layer. It decouples the game-state enum (which the player movement code owns) from the animation clip names (which Animation-Engine exports). If clip names change in the pack, only this file changes.

**4. Game design target:** FF7R-style instant attack responsiveness — crossfade ≤ 0.20 seconds for attack/dodge/cast transitions.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/game/animation/PlayerAnimBridge.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/game/actors/PlayerActor.hpp` READ_LINES: 1-60 (to find `PlayerActionState` enum definition and member names).
- READ_FILE: `src/game/animation/AnimationComponent.hpp` READ_LINES: 1-40.
- Use `std::unordered_map<std::string, LoadedAnimClip>` as the clip library type. This map is built by the caller (Main.cpp) after all clips are loaded.
- LINE_BUDGET: 80 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 397H — Header companion for Task 397 (PlayerAnimBridge)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/PlayerAnimBridge.hpp` (new file).

**1. Task Name:** PlayerAnimBridge.hpp — declares `PlayerAnimBridge::Update`.

**2. What it does:**
- `#pragma once` + standard header.
- Forward-includes or includes `AnimationComponent.hpp`, `AnimClipLoader.hpp`, and the `PlayerActionState` enum header.
- `#include <unordered_map>` and `<string>`.
- `class PlayerAnimBridge { public: static void Update(PlayerActionState state, AnimationComponent& animComp, const std::unordered_map<std::string, LoadedAnimClip>& clipLibrary); };`

**3–7.** See Task 397.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 398 — AnimEventDispatch.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimEventDispatch.cpp` (new file).

**1. Task Name:** AnimEventDispatch — polls fired animation events from AnimationComponent and routes them to audio and combat systems.

**2. What it does:**
- `AnimEventDispatch::Dispatch(AnimationComponent& animComp, float prevTime, CombatSystem& combat, float dt)`:
  - Calls `animComp.GetFiredEvents(prevTime, animComp.playbackTime)` to get events fired this frame.
  - For each `AnimEvent`:
    - `type == "footstep"` → calls `tp::Audio::PlayOneShot("sfx_footstep")` (placeholder assetId — replaced by Task 402).
    - `type == "contact"` → calls `tp::Audio::PlayOneShot("sfx_impact")`.
    - `type == "hit"` → calls `combat.RegisterHitFrame()` (marks that the attack hitbox is active this frame).
    - `type == "cancel"` → calls `combat.RegisterCancelWindow()` (opens combo cancel window).
    - `type == "cast_release"` → calls `combat.RegisterCastRelease()` (fires queued spell).
  - Unknown types are silently ignored.
- All `CombatSystem` methods called here must already exist or be stubbed as no-ops in `CombatSystem.hpp`. Do NOT add new CombatSystem methods in this file.

**3. Narrative logic:** Animation events are the timeline-synced triggers that connect visual actions to game logic. A sword swing calls `hit` at frame 12, opening the hitbox. Cancel windows open exactly when the animator says. This is how FF7R-style reactive combat feels tight.

**4. Game design target:** Frame-accurate hitbox activation. Combo cancel window opens ≤ 1 frame after the animation event fires.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/game/animation/AnimEventDispatch.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/game/combat/CombatSystem.hpp` READ_LINES: 1-50 (to find existing public method names — only call methods that already exist).
- READ_FILE: `ThirdParty/src/tp_audio.hpp` READ_LINES: 19-31 (for `tp::Audio::PlayOneShot` signature).
- READ_FILE: `src/game/animation/AnimationComponent.hpp` READ_LINES: 1-40.
- If `CombatSystem` does not expose `RegisterHitFrame`, `RegisterCancelWindow`, or `RegisterCastRelease`, replace those calls with a `// TODO: wire to CombatSystem` comment instead of adding new code to CombatSystem.
- LINE_BUDGET: 80 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 398H — Header companion for Task 398 (AnimEventDispatch)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/game/animation/AnimEventDispatch.hpp` (new file).

**1. Task Name:** AnimEventDispatch.hpp — declares `AnimEventDispatch::Dispatch`.

**2. What it does:**
- `#pragma once` + standard header.
- Forward-declares `CombatSystem`.
- `#include "AnimationComponent.hpp"`.
- `class AnimEventDispatch { public: static void Dispatch(AnimationComponent& animComp, float prevTime, CombatSystem& combat, float dt); };`

**3–7.** See Task 398.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

## ═══════════════════════════════════════════════════
## SECTION B — AUDIO-ENGINE INTEGRATION (Tasks 399-403H)
## ═══════════════════════════════════════════════════

---

### Task 399 — AudioManifestLoader.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/AudioManifestLoader.cpp` (new file).

**1. Task Name:** AudioManifestLoader — reads `audio_plan.music.json` and `audio_plan.sfx.json`, builds `assetId → AudioAssetInfo` map.

**2. What it does:**
- `AudioManifestLoader::LoadManifest(const std::string& manifestPath)`:
  - Opens JSON file with `std::ifstream`.
  - Parses `assetGroups[]`. For each group, parses `groupId`, `category`, and `requests[]`.
  - For each request, parses: `requestId`, `assetId`, `targetPath`, `durationSec`, `loop` (bool).
  - Inserts into a `static std::unordered_map<std::string, AudioAssetInfo>` keyed by `assetId`.
  - `targetPath` is stored as-is (relative to `Content/`). The caller prepends `Content/`.
- `AudioManifestLoader::GetAsset(const std::string& assetId)` → returns `const AudioAssetInfo*` (nullptr if not found).
- `AudioManifestLoader::GetAllByCategory(const std::string& category)` → returns `std::vector<AudioAssetInfo>` filtered by `category`.
- Logs warning if `assetId` is empty or `targetPath` is empty.

**3. Narrative logic:** The manifest is the lookup table that maps human-readable assetId strings (like `"bgm.world_map"`) to actual file paths. Every audio play call goes through this table — no hardcoded paths.

**4. Game design target:** All music categories loaded: exploration, battle, boss, cinematic, memorial, fanfare, ending. All SFX categories loaded: combat, traversal, spell, interaction, ui.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/audio/AudioManifestLoader.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/app/Main.cpp` READ_LINES: 1-7 (for standard file header).
- READ_FILE: `ThirdParty/src/tp_audio.hpp` READ_LINES: 19-31 (for reference on existing audio API shape).
- JSON parsing: use `std::ifstream` + string-find approach. Do NOT add a JSON library.
- LINE_BUDGET: 130 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 399H — Header companion for Task 399 (AudioManifestLoader)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/AudioManifestLoader.hpp` (new file).

**1. Task Name:** AudioManifestLoader.hpp — declares `AudioAssetInfo` and `AudioManifestLoader`.

**2. What it does:**
- `#pragma once` + standard header.
- `struct AudioAssetInfo { std::string assetId; std::string category; std::string targetPath; float durationSec; bool loop; };`
- `class AudioManifestLoader { public: static void LoadManifest(const std::string& manifestPath); static const AudioAssetInfo* GetAsset(const std::string& assetId); static std::vector<AudioAssetInfo> GetAllByCategory(const std::string& category); };`
- Includes: `<string>`, `<vector>`.

**3–7.** See Task 399.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 400 — ManagedMusicPlayer.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/ManagedMusicPlayer.cpp` (new file).

**1. Task Name:** ManagedMusicPlayer — loop-safe BGM player with fade-in, fade-out, and crossfade built on top of `tp::Audio`.

**2. What it does:**
- Maintains `static std::string s_currentAssetId`, `static std::string s_nextAssetId`, `static float s_fadeVolume`, `static float s_fadeDir` (+1 = fade in, -1 = fade out), `static float s_fadeDuration`.
- `ManagedMusicPlayer::PlayMusic(const std::string& assetId, float fadeInSec)`:
  - If `assetId == s_currentAssetId`, does nothing (already playing).
  - Otherwise: fades out current track (sets `s_fadeDir = -1`, `s_fadeDuration = fadeInSec * 0.5f`) and queues `s_nextAssetId = assetId`.
- `ManagedMusicPlayer::StopMusic(float fadeOutSec)`:
  - Sets `s_fadeDir = -1`, `s_fadeDuration = fadeOutSec`, clears `s_nextAssetId`.
- `ManagedMusicPlayer::CrossfadeTo(const std::string& assetId, float crossfadeSec)`:
  - Sets `s_nextAssetId = assetId`, `s_fadeDir = -1`, `s_fadeDuration = crossfadeSec`.
- `ManagedMusicPlayer::Update(float dt)`:
  - Advances `s_fadeVolume` toward 0.0f or 1.0f based on `s_fadeDir` and `s_fadeDuration`.
  - When fade-out completes (volume = 0) and `s_nextAssetId` is set: looks up `AudioAssetInfo` via `AudioManifestLoader::GetAsset(s_nextAssetId)`, calls `tp::Audio::PlayOneShot(assetInfo->targetPath.c_str())` (placeholder until full loop API exists), sets `s_currentAssetId = s_nextAssetId`, clears `s_nextAssetId`, sets `s_fadeDir = +1`.
  - Volume is emulated via a static float — actual volume control not yet supported by `tp::Audio`; this is a structural stub ready for when `tp::Audio` gains a volume API.
  - Clamps `s_fadeVolume` to [0.0f, 1.0f].

**3. Narrative logic:** The current `tp::Audio` can only fire one-shots. This managed player wraps it and tracks fade state so the caller can say `CrossfadeTo("bgm.battle", 1.5f)` without caring about the underlying one-shot limitation. When a full loop API is added later, only this file needs updating.

**4. Game design target:** Smooth 1.0–1.5 second crossfade between exploration and battle BGM. No abrupt cuts.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/audio/ManagedMusicPlayer.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `ThirdParty/src/tp_audio.hpp` READ_LINES: 19-31 (for `tp::Audio` API signatures).
- READ_FILE: `src/audio/AudioManifestLoader.hpp` READ_LINES: 1-20.
- Do NOT modify `tp_audio.hpp`. Layer on top only.
- LINE_BUDGET: 120 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 400H — Header companion for Task 400 (ManagedMusicPlayer)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/ManagedMusicPlayer.hpp` (new file).

**1. Task Name:** ManagedMusicPlayer.hpp — declares `ManagedMusicPlayer`.

**2. What it does:**
- `#pragma once` + standard header.
- `#include <string>`.
- `class ManagedMusicPlayer { public: static void PlayMusic(const std::string& assetId, float fadeInSec = 1.0f); static void StopMusic(float fadeOutSec = 1.0f); static void CrossfadeTo(const std::string& assetId, float crossfadeSec = 1.5f); static void Update(float dt); };`

**3–7.** See Task 400.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 401 — AudioStateRouter.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/AudioStateRouter.cpp` (new file).

**1. Task Name:** AudioStateRouter — maps game state transitions to BGM crossfade calls on `ManagedMusicPlayer`.

**2. What it does:**
- Defines `enum class AudioState { Exploration, Battle, Boss, Cinematic, Camp, Shop, MainMenu }`.
- `static AudioState s_currentState = AudioState::Exploration`.
- `AudioStateRouter::OnStateChange(AudioState newState)`:
  - If `newState == s_currentState`, returns immediately.
  - Updates `s_currentState = newState`.
  - Maps `newState` to a category string and selects the first asset of that category from `AudioManifestLoader::GetAllByCategory(...)`.
  - Calls `ManagedMusicPlayer::CrossfadeTo(selectedAsset.assetId, crossfadeSec)` with:
    - `Battle`/`Boss` → crossfade 0.8f seconds.
    - `Exploration`/`Camp`/`Shop` → crossfade 2.0f seconds.
    - `Cinematic` → crossfade 1.5f seconds.
    - `MainMenu` → crossfade 1.0f seconds.
  - If no asset found for the category, logs warning and does not change music.
- `AudioStateRouter::Update(float dt)`:
  - Calls `ManagedMusicPlayer::Update(dt)`. Called once per frame from `Main.cpp`.

**3. Narrative logic:** The router is the single place where game-world state (entering battle, returning to overworld) triggers the correct BGM. No game-logic code needs to know assetIds — they ask the router to change state and it picks the right track.

**4. Game design target:** Under 1 second battle-entry sting + BGM swap. Classic FF feel.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/audio/AudioStateRouter.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/audio/ManagedMusicPlayer.hpp` READ_LINES: 1-20.
- READ_FILE: `src/audio/AudioManifestLoader.hpp` READ_LINES: 1-20.
- Audio-Engine category strings to use: `"exploration"`, `"battle"`, `"boss"`, `"cinematic"`, `"memorial"`, `"fanfare"`, `"ending"`.
- When multiple assets match a category, always pick `assets[0]` (first in the vector) — no randomisation needed.
- LINE_BUDGET: 100 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 401H — Header companion for Task 401 (AudioStateRouter)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/AudioStateRouter.hpp` (new file).

**1. Task Name:** AudioStateRouter.hpp — declares `AudioState` enum and `AudioStateRouter`.

**2. What it does:**
- `#pragma once` + standard header.
- `enum class AudioState { Exploration, Battle, Boss, Cinematic, Camp, Shop, MainMenu };`
- `class AudioStateRouter { public: static void OnStateChange(AudioState newState); static void Update(float dt); };`

**3–7.** See Task 401.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 402 — SfxManifestBinder.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/SfxManifestBinder.cpp` (new file).

**1. Task Name:** SfxManifestBinder — resolves SFX assetId strings to file paths from the loaded manifest and calls `tp::Audio::PlayOneShot`.

**2. What it does:**
- `SfxManifestBinder::Play(const std::string& assetId)`:
  - Calls `AudioManifestLoader::GetAsset(assetId)`.
  - If found, calls `tp::Audio::PlayOneShot(asset->targetPath.c_str())`.
  - If not found, logs warning with `assetId` and returns.
- `SfxManifestBinder::PlayCategory(const std::string& category)`:
  - Gets all assets for `category` via `AudioManifestLoader::GetAllByCategory(category)`.
  - Plays the first asset found (or logs warning if empty).
- Provides named constants for common SFX trigger points:
  - `static constexpr const char* SFX_FOOTSTEP   = "sfx.footstep.grass";`
  - `static constexpr const char* SFX_IMPACT      = "sfx.impact.melee";`
  - `static constexpr const char* SFX_SPELL_CAST  = "sfx.spell.cast";`
  - `static constexpr const char* SFX_DODGE       = "sfx.dodge.whoosh";`
  - `static constexpr const char* SFX_UI_CONFIRM  = "sfx.ui.confirm";`
  - `static constexpr const char* SFX_UI_CANCEL   = "sfx.ui.cancel";`
- These constants are the canonical assetId strings that Audio-Engine's manifest should provide.

**3. Narrative logic:** AnimEventDispatch (Task 398) fires events like `"footstep"`. This binder translates those event types to the correct manifest assetId and plays the sound. It also provides the named constants so no magic strings appear in combat or UI code.

**4. Game design target:** Combat SFX plays ≤ 1 frame after the animation event fires (deterministic one-shot).

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/audio/SfxManifestBinder.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `ThirdParty/src/tp_audio.hpp` READ_LINES: 19-31.
- READ_FILE: `src/audio/AudioManifestLoader.hpp` READ_LINES: 1-20.
- LINE_BUDGET: 80 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 402H — Header companion for Task 402 (SfxManifestBinder)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/SfxManifestBinder.hpp` (new file).

**1. Task Name:** SfxManifestBinder.hpp — declares `SfxManifestBinder` and its named SFX constants.

**2. What it does:**
- `#pragma once` + standard header.
- `#include <string>`.
- `class SfxManifestBinder { public: static void Play(const std::string& assetId); static void PlayCategory(const std::string& category); static constexpr const char* SFX_FOOTSTEP  = "sfx.footstep.grass"; static constexpr const char* SFX_IMPACT     = "sfx.impact.melee"; static constexpr const char* SFX_SPELL_CAST = "sfx.spell.cast"; static constexpr const char* SFX_DODGE      = "sfx.dodge.whoosh"; static constexpr const char* SFX_UI_CONFIRM = "sfx.ui.confirm"; static constexpr const char* SFX_UI_CANCEL  = "sfx.ui.cancel"; };`

**3–7.** See Task 402.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 403 — AudioAmbienceZone.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/AudioAmbienceZone.cpp` (new file).

**1. Task Name:** AudioAmbienceZone — plays regional ambient audio loops based on the current WorldGrid zone string.

**2. What it does:**
- `static std::string s_currentZone`.
- `AudioAmbienceZone::OnZoneEnter(const std::string& zoneId)`:
  - If `zoneId == s_currentZone`, returns (already playing zone ambience).
  - Updates `s_currentZone = zoneId`.
  - Constructs assetId: `"ambient." + zoneId` (e.g., `"ambient.grassland"`, `"ambient.cave"`, `"ambient.city"`).
  - Calls `AudioManifestLoader::GetAsset(assetId)`. If found, calls `tp::Audio::PlayOneShot(asset->targetPath.c_str())`.
  - If not found, logs warning: `"[AudioAmbienceZone] No ambient asset for zone: " + zoneId`.
- `AudioAmbienceZone::OnZoneLeave()`:
  - Sets `s_currentZone = ""`.
  - (Future: fade out ambient loop. Not implemented until tp::Audio gains volume/stop API.)

**3. Narrative logic:** Each world zone has a distinct ambient soundscape (wind for grassland, drips for caves, crowd chatter for cities). The zone ambient system fires automatically when the player crosses a WorldGrid zone boundary, providing environmental immersion without any manual trigger code in the game loop.

**4. Game design target:** Seamless ambient transitions matching the world zone IDs in WorldGrid.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/audio/AudioAmbienceZone.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/world/WorldGrid.hpp` READ_LINES: 1-40 (to find zone-identifier member or string type).
- READ_FILE: `ThirdParty/src/tp_audio.hpp` READ_LINES: 19-31.
- READ_FILE: `src/audio/AudioManifestLoader.hpp` READ_LINES: 1-20.
- LINE_BUDGET: 80 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 403H — Header companion for Task 403 (AudioAmbienceZone)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/audio/AudioAmbienceZone.hpp` (new file).

**1. Task Name:** AudioAmbienceZone.hpp — declares `AudioAmbienceZone`.

**2. What it does:**
- `#pragma once` + standard header.
- `#include <string>`.
- `class AudioAmbienceZone { public: static void OnZoneEnter(const std::string& zoneId); static void OnZoneLeave(); };`

**3–7.** See Task 403.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

## ═══════════════════════════════════════════════════
## SECTION C — CREATION-ENGINE INTEGRATION (Tasks 404-408H)
## ═══════════════════════════════════════════════════

---

### Task 404 — CreationMaterialLoader.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/assets/CreationMaterialLoader.cpp` (new file).

**1. Task Name:** CreationMaterialLoader — reads a Creation-Engine material JSON v1.1 file and returns a `CreationMaterial` struct.

**2. What it does:**
- Opens `<path>.json` with `std::ifstream`.
- Parses: `version`, `name`, `shader`, `params.color[4]`, `params.roughness`, `params.metallic`, `params.ao`, `params.emissive[3]`.
- Parses `textures`: `albedo`, `normal`, `roughness`, `metallic`, `ao`, `emissive` (all relative-to-Content paths).
- Validates `version == "1.1"`. On mismatch, checks for legacy `params.baseColor[4]` field and maps it to `color` (back-compat).
- Validates `shader == "Shaders/basic3d"` or logs a warning if different (shader mismatch may cause rendering artifacts).
- Stores results in `CreationMaterial` struct.
- Returns empty struct with `valid = false` on error.
- `CreationMaterialLoader::LoadDir(const std::string& dirPath)` → iterates the given directory for all `*.json` files, calls `Load` on each, inserts into a `static std::unordered_map<std::string, CreationMaterial>` keyed by `material.name`.
- `CreationMaterialLoader::Get(const std::string& name)` → returns `const CreationMaterial*` (nullptr if not found).

**3. Narrative logic:** Creation-Engine generates one JSON per material. Each JSON drives the D3D11 shader parameters and names the PBR texture files. This loader reads them at startup, so the renderer can look up any material by name without hardcoded values.

**4. Game design target:** PBR materials with albedo, normal, roughness, metallic, AO, emissive — matching Creation-Engine FF aesthetic targets.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/assets/CreationMaterialLoader.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/app/Main.cpp` READ_LINES: 1-7 (header format).
- READ_FILE: `Content/AssetRegistry.json` READ_LINES: 1-30 (path convention: `Content/` prefix required for textures).
- Directory iteration: use `std::filesystem::directory_iterator` (C++17). If `std::filesystem` is not available, iterate a manually maintained list instead.
- LINE_BUDGET: 150 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 404H — Header companion for Task 404 (CreationMaterialLoader)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/assets/CreationMaterialLoader.hpp` (new file).

**1. Task Name:** CreationMaterialLoader.hpp — declares `CreationMaterial` and `CreationMaterialLoader`.

**2. What it does:**
- `#pragma once` + standard header.
- `#include <string>`, `#include <vector>`.
- `struct CreationMaterial { bool valid; std::string name; std::string shader; float color[4]; float roughness; float metallic; float ao; float emissive[3]; std::string texAlbedo; std::string texNormal; std::string texRoughness; std::string texMetallic; std::string texAO; std::string texEmissive; };`
- `class CreationMaterialLoader { public: static CreationMaterial Load(const std::string& jsonPath); static void LoadDir(const std::string& dirPath); static const CreationMaterial* Get(const std::string& name); };`

**3–7.** See Task 404.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 405 — PbrTextureChannelBinder.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/rendering/d3d11/PbrTextureChannelBinder.cpp` (new file).

**1. Task Name:** PbrTextureChannelBinder — loads PBR PNG channels from a `CreationMaterial` and binds them to D3D11 shader resource view slots.

**2. What it does:**
- `PbrTextureChannelBinder::Bind(ID3D11DeviceContext* ctx, const CreationMaterial& mat)`:
  - For each channel (albedo, normal, roughness, metallic, ao, emissive):
    - If the path is not empty, loads the texture using `tp::Texture::Load(path, device)` (or equivalent existing texture-load call — do NOT add a new loader).
    - Binds the resulting `ID3D11ShaderResourceView*` to the pixel shader slot:
      - Slot 0: albedo, Slot 1: normal, Slot 2: roughness, Slot 3: metallic, Slot 4: AO, Slot 5: emissive.
    - If path is empty, binds `nullptr` to that slot.
  - Sets the material constant buffer with `mat.color`, `mat.roughness`, `mat.metallic`, `mat.ao`, `mat.emissive` via an existing `ID3D11Buffer* g_materialCB` (must already exist — do NOT create new CB in this file; use whatever CB is already in the D3D11 renderer).
- `PbrTextureChannelBinder::Unbind(ID3D11DeviceContext* ctx)`:
  - Sets SRV slots 0–5 to `nullptr`.

**3. Narrative logic:** The six PBR channels are the visual foundation of every Creation-Engine material. This binder maps the JSON-specified file paths to GPU slots every draw call, so the basic3d shader can read the correct textures without any per-object hardcoding.

**4. Game design target:** GT610-compatible PBR — pixel shader reads 6 SRV slots. No tessellation or compute required.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/rendering/d3d11/PbrTextureChannelBinder.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/rendering/d3d11/` directory listing (to find existing D3D11 files for context and CB variable names).
- READ_FILE: `ThirdParty/src/tp_texture.hpp` READ_LINES: 1-40 (for existing texture load signature).
- READ_FILE: `src/assets/CreationMaterialLoader.hpp` READ_LINES: 1-30.
- If `g_materialCB` or equivalent does not exist, add a comment `// TODO: bind to existing material constant buffer` and skip the CB call. Do NOT add a new D3D11 buffer creation.
- LINE_BUDGET: 120 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 405H — Header companion for Task 405 (PbrTextureChannelBinder)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/rendering/d3d11/PbrTextureChannelBinder.hpp` (new file).

**1. Task Name:** PbrTextureChannelBinder.hpp — declares `PbrTextureChannelBinder`.

**2. What it does:**
- `#pragma once` + standard header.
- `#include <d3d11.h>`.
- `#include "../../assets/CreationMaterialLoader.hpp"`.
- `class PbrTextureChannelBinder { public: static void Bind(ID3D11DeviceContext* ctx, const CreationMaterial& mat); static void Unbind(ID3D11DeviceContext* ctx); };`

**3–7.** See Task 405.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 406 — TilemapJsonLoader.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/world/TilemapJsonLoader.cpp` (new file).

**1. Task Name:** TilemapJsonLoader — reads a Creation-Engine tilemap JSON v1.0 and populates WorldGrid tile data.

**2. What it does:**
- `TilemapJsonLoader::Load(const std::string& jsonPath, WorldGrid& grid)`:
  - Opens file with `std::ifstream`.
  - Parses: `version` (validates `"1.0"`), `width`, `height`, `tileSize`, `tileset`, `tiles[]` (flat int array), `props[]`.
  - Calls `grid.Resize(width, height)` (or equivalent WorldGrid API — read WorldGrid.hpp to find correct method).
  - For each tile ID in `tiles[]` (row-major order, top-left to bottom-right):
    - Calls `grid.SetTile(x, y, static_cast<TileType>(tileId))`.
    - `x = index % width`, `y = index / width`.
    - Clamps tileId to [0, 15] range.
  - For each entry in `props[]`:
    - Reads `type`, `x`, `y`, `label`.
    - Calls `grid.AddProp(x, y, type, label)` (if that method exists; otherwise logs `// TODO: wire props to WorldGrid`).
  - Returns `true` on success, `false` on file-not-found or version mismatch.

**3. Narrative logic:** Every world map area in the game is built from a tilemap JSON exported by Creation-Engine. This loader is the bridge that converts those static JSON tile arrays into live WorldGrid cells that the pathfinding and rendering systems already know how to read.

**4. Game design target:** Tile IDs 0–15 match the `TileType` enum in WorldGrid (as per Creation-Engine spec). Grid resize without memory leak.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/world/TilemapJsonLoader.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/world/WorldGrid.hpp` READ_LINES: 1-60 (for `WorldGrid` API: Resize, SetTile, TileType enum, AddProp if it exists).
- READ_FILE: `src/app/Main.cpp` READ_LINES: 1-7 (header format).
- JSON parsing: `std::ifstream` + string-find. The `tiles` array is a flat JSON array of integers.
- LINE_BUDGET: 130 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 406H — Header companion for Task 406 (TilemapJsonLoader)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/world/TilemapJsonLoader.hpp` (new file).

**1. Task Name:** TilemapJsonLoader.hpp — declares `TilemapJsonLoader`.

**2. What it does:**
- `#pragma once` + standard header.
- Forward-declare or include `WorldGrid`.
- `#include <string>`.
- `class TilemapJsonLoader { public: static bool Load(const std::string& jsonPath, WorldGrid& grid); };`

**3–7.** See Task 406.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 407 — StaticMeshObjLoader.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/assets/StaticMeshObjLoader.cpp` (new file).

**1. Task Name:** StaticMeshObjLoader — loads an OBJ + manifest generated by Creation-Engine for static world props.

**2. What it does:**
- `StaticMeshObjLoader::Load(const std::string& manifestPath)` → returns `StaticMeshData`:
  - Reads manifest JSON: `mesh_file` (path to OBJ), `material` (material name string), `style_profile`, `content_target`.
  - Opens OBJ file, parses `v` (vertex positions), `vt` (UVs), `vn` (normals), `f` (face indices).
  - Builds interleaved vertex buffer: `position (XMFLOAT3), normal (XMFLOAT3), uv (XMFLOAT2)`.
  - Builds index buffer (int32 indices).
  - Sets `StaticMeshData.materialName = manifest["material"]`.
  - Returns `StaticMeshData` with vertex and index arrays populated.
  - Logs error and returns empty struct on file-not-found.
- OBJ parsing only handles triangle faces (`f a/b/c d/e/f g/h/i` format). Quads are not supported — Creation-Engine exports triangulated meshes only.
- Does NOT create D3D11 buffers. Buffer creation is done by the existing mesh renderer.

**3. Narrative logic:** World prop meshes (barrels, crates, trees, rocks) are generated by Creation-Engine as OBJ files. This loader reads them into CPU memory so the renderer can upload them to the GPU. Only triangulated OBJ is supported — Creation-Engine guarantees this.

**4. Game design target:** GT610-safe static mesh import. No skinning. Props up to ~2000 triangles each.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/assets/StaticMeshObjLoader.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/app/Main.cpp` READ_LINES: 1-7.
- OBJ face lines may have the form `f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3`. Split on `/` and space. All indices are 1-based in OBJ — subtract 1 before storing.
- LINE_BUDGET: 180 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 407H — Header companion for Task 407 (StaticMeshObjLoader)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/assets/StaticMeshObjLoader.hpp` (new file).

**1. Task Name:** StaticMeshObjLoader.hpp — declares `StaticMeshVertex`, `StaticMeshData`, and `StaticMeshObjLoader`.

**2. What it does:**
- `#pragma once` + standard header.
- `#include <DirectXMath.h>`, `#include <string>`, `#include <vector>`.
- `struct StaticMeshVertex { DirectX::XMFLOAT3 position; DirectX::XMFLOAT3 normal; DirectX::XMFLOAT2 uv; };`
- `struct StaticMeshData { bool valid; std::string materialName; std::string styleProfile; std::string contentTarget; std::vector<StaticMeshVertex> vertices; std::vector<int> indices; };`
- `class StaticMeshObjLoader { public: static StaticMeshData Load(const std::string& manifestPath); };`

**3–7.** See Task 407.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 408 — CreationBundleValidator.cpp
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/assets/CreationBundleValidator.cpp` (new file).

**1. Task Name:** CreationBundleValidator — validates a Creation-Engine content bundle before runtime import by checking required fields and referenced file presence.

**2. What it does:**
- `CreationBundleValidator::Validate(const std::string& contentDir)` → returns `bool`:
  - Iterates all `*.json` files under `contentDir/Materials/`.
  - For each material JSON, checks:
    - `style_profile` field is non-empty (required by Creation-Engine quality-check).
    - `content_target` field is non-empty.
    - Every file path listed in `textures` block exists on disk (`std::filesystem::exists` or `std::ifstream` probe).
  - Iterates all `*.json` files under `contentDir/Tilemaps/`.
  - For each tilemap JSON, checks:
    - `version == "1.0"`.
    - `width > 0`, `height > 0`, `tileSize > 0`.
    - `tiles` array length equals `width * height`.
  - Iterates all `*.json` files under `contentDir/Meshes/`.
  - For each mesh manifest, checks:
    - `mesh_file` path exists on disk.
  - Returns `true` if all checks pass. Returns `false` and logs every individual failure.
- `CreationBundleValidator::ValidateFile(const std::string& jsonPath)` → per-file convenience overload, same logic for one file.

**3. Narrative logic:** Creation-Engine's CLI `quality-check` validates during generation. This in-engine validator runs at game startup to catch cases where generated files are stale, moved, or have missing textures. It fails loud so a bad bundle never reaches the renderer.

**4. Game design target:** Zero silent failures. Every missing texture or empty field is logged with file path before the game enters its main loop.

**5. File to edit:**
```
/tmp/workspace/Mikester9000/GameRewritten/src/assets/CreationBundleValidator.cpp
```

**6. Where in file:** New file.

**7. Additional information:**
- READ_FILE: `src/assets/CreationMaterialLoader.hpp` READ_LINES: 1-30.
- READ_FILE: `Content/AssetRegistry.json` READ_LINES: 1-30 (for Content root path convention).
- `std::filesystem::exists` requires C++17 and the linker flag for `stdc++fs` on some compilers. If unavailable, use `std::ifstream probe(path); return probe.good();` instead.
- LINE_BUDGET: 140 lines.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

### Task 408H — Header companion for Task 408 (CreationBundleValidator)
**EXECUTOR:** Qwen2.5-Coder-1.5B | **ONE FILE EDIT**

**0. Single-file edit:** `src/assets/CreationBundleValidator.hpp` (new file).

**1. Task Name:** CreationBundleValidator.hpp — declares `CreationBundleValidator`.

**2. What it does:**
- `#pragma once` + standard header.
- `#include <string>`.
- `class CreationBundleValidator { public: static bool Validate(const std::string& contentDir); static bool ValidateFile(const std::string& jsonPath); };`

**3–7.** See Task 408.

**8. Copy-ready completion rule:** Output full file as one PASTE_BLOCK.

---

## ═══════════════════════════════════════════════════
## CROSS-ENGINE RELEASE GATE (Addendum to Task 120 in CON1)
## ═══════════════════════════════════════════════════

> **Note:** Task 120 in CON1 is the final ship-signoff manifest gate. The following acceptance criteria are additional requirements that must be appended to `docs/SHIP_CHECKLIST.md` (or Task 120's checklist) before the release gate is considered complete.

### Three-Engine Asset Handoff Checklist
All commands listed below must exit 0 before the ship gate is signed off.

#### Animation-Engine Acceptance
```
animation-engine validate-pack --manifest Content/Animations/noctis/pack_manifest.json
animation-engine validate-pack --manifest Content/Animations/enemy_*/pack_manifest.json
```
- Confirmed clips present: `idle`, `walk`, `run`, `attack`, `defend`, `cast`, `hit_react`, `dodge`, `jump_start`, `jump_loop`, `jump_land`, `victory`.
- `format == "AnimEngine"` and `version == "1.0"` in every manifest.

#### Audio-Engine Acceptance
```
audio-engine quality-check --manifest Content/Audio/music/audio_plan.music.json
audio-engine quality-check --manifest Content/Audio/sfx/audio_plan.sfx.json
audio-engine bundle-audit   --content Content/Audio/
```
- All required categories present: `exploration`, `battle`, `boss`, `cinematic`, `memorial`, `fanfare`, `ending` (music); `combat`, `traversal`, `spell`, `interaction`, `ui` (SFX).
- All `targetPath` files exist on disk.

#### Creation-Engine Acceptance
```
creation-engine quality-check --content Content/
creation-engine bundle-audit  --content Content/
```
- Every material JSON has non-empty `style_profile` and `content_target`.
- All texture file references exist on disk.
- All tilemap JSON files have valid `width * height == tiles.length`.
- All mesh manifests reference existing OBJ files.

#### In-Engine Startup Validation (already covered by Tasks 393-408)
- `AnimPackManifestLoader::Load` returns non-empty vector for all characters.
- `AudioManifestLoader::LoadManifest` loads both music and SFX manifests without errors.
- `CreationBundleValidator::Validate("Content/")` returns `true`.

---

*End of docs_ONE_FILE_COMPLETION_PLAN(CON8).md — 32 tasks (393-408 + H companions) + cross-engine release gate addendum.*

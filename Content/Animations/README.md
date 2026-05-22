# Animations Content

Animation clips and skeleton files exported from the Animation Engine (`Mikester9000/Animation-Engine`).
See `docs/ASSET_PIPELINE.md` for export commands and format details.

## Formats

- `.anim` — AnimEngine JSON 1.0 (model + skeleton + clips + morph tracks in one file)
- `.gltf` + `.bin` — glTF 2.0 skinned mesh + animation (industry standard)

## Clip library

The pipeline generates clips for: idle, idle_alt, idle_combat, walk, run, run_start/stop,
sprint, strafe, crouch, jump, roll, vault, climb, attack, attack_combo_1/2/3, heavy_attack,
aerial_attack, cast, defend, block, parry, dodge, hit_react, stagger, knockdown, get_up,
death, interact, pickup, victory.

## To import after exporting

    python tools/import_assets.py --engine animation --src /path/to/anim_export

# Animations Content

Runtime animation files exported from the Animation Engine.

## Source
Repository: `Mikester9000/Animation-Engine` (`tools/engines/animation-engine`)

## Expected Files
- `*.anim` — compiled animation clips (idle, walk, run, attack, dodge, etc.)
- `*.skel` — skeleton definition files

## Workflow
1. Author animations in `tools/engines/animation-engine`
2. Run the export command (see Animation Engine README)
3. Place exported files in this directory
4. Update `Content/AssetRegistry.json` with new animation entries

# Ship Checklist

Complete every item before tagging a release.

## Gameplay
- [ ] Player can start a new game and reach the first campfire without crashing
- [ ] Combat loop (attack / dodge / lock-on / Surge / Limit) is fully playable
- [ ] At least one quest completes end-to-end (objective shown → completed → reward)
- [ ] Fast travel unlocks after discovering a landmark and warps correctly
- [ ] Save / load round-trip preserves HP, flags, and landmark discovery state
- [ ] Death screen appears and retry returns player to respawn point

## UI/HUD
- [ ] HUD shows HP, MP, Surge, Limit bars correctly
- [ ] Minimap fog-of-war fills as player explores
- [ ] World map opens and shows player position
- [ ] Settings menu applies audio volume changes live
- [ ] Credits screen scrolls without crashing

## Performance (GT610 target)
- [ ] Sustained 30+ FPS during normal exploration
- [ ] No GPU hitches > 100 ms during combat on Low quality preset
- [ ] AutoQualityScaler downgrades preset when frame time budget is exceeded

## Stability
- [ ] No crash on 30-minute session traversing multiple biomes
- [ ] No memory leak observed in Task Manager over 1-hour session
- [ ] CrashDiagnostics writes a log on forced assert failure

## Content
- [ ] At least 3 distinct biomes spawn correctly
- [ ] At least 2 NPC actors with dialog present in the world
- [ ] Chest actors open and emit loot notifications

## Legal / Build
- [ ] `docs/THIRD_PARTY.md` lists all third-party libraries with licence info
- [ ] `tools/release/PackageBuild.ps1` produces a complete `dist/` folder
- [ ] `release_manifest.json` is present and version matches tag

# Release Build Guide

## Overview
Run `tools/release/PackageBuild.ps1` from PowerShell to package a release build.

## Prerequisites
- Visual Studio 2022 (or Build Tools) installed
- Build the solution in **Release | x64** configuration first via Visual Studio or `msbuild`

## Usage
```powershell
# From repository root:
.\tools\release\PackageBuild.ps1 -Config Release -OutDir dist -Version 0.1.0
```

## Output
The script creates `dist/` containing:
- `GameRewritten.exe`
- `Content/` — world data and prefabs
- `Shaders/` — compiled HLSL shaders
- `Audio/` — BGM and SFX files
- `release_manifest.json` — version + file list for verification

## Manual steps before release
1. Build in Release mode and confirm no warnings.
2. Run the vertical-slice checklist in `docs/SHIP_CHECKLIST.md`.
3. Run `PackageBuild.ps1`.
4. Smoke-test the packaged build from `dist/`.
5. Tag the release commit: `git tag v0.1.0`.

#!/usr/bin/env python3
"""
tools/import_assets.py
======================
Copy exported engine files into the correct Content/ subdirectory and
update Content/AssetRegistry.json.

Usage
-----
  python tools/import_assets.py --engine audio      --src ./audio_export
  python tools/import_assets.py --engine animation  --src ./anim_export
  python tools/import_assets.py --engine creation   --src ./creation_export
  python tools/import_assets.py --engine creation   --src ./creation_export --dry-run

See docs/ASSET_PIPELINE.md for the full pipeline reference.
"""

from __future__ import annotations

import argparse
import json
import shutil
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Repo root anchoring
# ---------------------------------------------------------------------------
REPO_ROOT = Path(__file__).resolve().parent.parent
CONTENT_DIR = REPO_ROOT / "Content"
REGISTRY_PATH = CONTENT_DIR / "AssetRegistry.json"

# ---------------------------------------------------------------------------
# Static routing tables (used when no manifest is present)
# ---------------------------------------------------------------------------

AUDIO_EXTENSIONS = {".wav", ".ogg", ".mp3", ".flac"}
ANIMATION_EXTENSIONS = {".anim", ".gltf", ".bin"}

# Creation Engine: map suffix/name patterns to Content/ subdirectory.
# The manifest's content_target field overrides these when present.
CREATION_ROUTING: list[tuple[str, str]] = [
    # PBR channel textures  (name ends with _albedo / _normal / etc.)
    ("_albedo.png",   "Content/Textures"),
    ("_normal.png",   "Content/Textures"),
    ("_metallic.png", "Content/Textures"),
    ("_roughness.png","Content/Textures"),
    ("_occlusion.png","Content/Textures"),
    # Generic PNG → Textures
    (".png",          "Content/Textures"),
    # Meshes
    (".obj",          "Content/Models"),
    (".mtl",          "Content/Materials"),
    # glTF (produced by Animation Engine but may appear here too)
    (".gltf",         "Content/Animations"),
    (".bin",          "Content/Animations"),
]


# ---------------------------------------------------------------------------
# Registry helpers
# ---------------------------------------------------------------------------

def _load_registry() -> dict:
    if REGISTRY_PATH.exists():
        with REGISTRY_PATH.open(encoding="utf-8") as fh:
            return json.load(fh)
    return {"version": 1, "assets": {}}


def _save_registry(reg: dict) -> None:
    with REGISTRY_PATH.open("w", encoding="utf-8") as fh:
        json.dump(reg, fh, indent=4)


def _registry_key(dest: Path) -> str:
    """Turn a Content/ path into a dotted registry key.

    Examples
    --------
    Content/Audio/bgm_field.ogg        -> audio.bgm_field
    Content/Textures/Grassland1.png    -> textures.Grassland1
    Content/Animations/player.anim     -> animations.player
    """
    try:
        rel = dest.relative_to(CONTENT_DIR)
    except ValueError:
        return dest.stem
    parts = list(rel.parts)
    folder = parts[0].lower().rstrip("s")  # "Textures" -> "texture"
    # Re-add the plural for known plurals that differ from stem+s
    folder_map = {
        "animation": "animations",
        "audio": "audio",
        "texture": "textures",
        "model": "models",
        "material": "materials",
        "world": "worlds",
        "prefab": "prefabs",
        "shader": "shaders",
        "scene": "scenes",
        "bundle": "bundles",
        "ui": "ui",
    }
    folder = folder_map.get(folder, folder)
    stem = Path(parts[-1]).stem
    return f"{folder}.{stem}"


# ---------------------------------------------------------------------------
# Engine-specific import functions
# ---------------------------------------------------------------------------

def _import_audio(src: Path, dry_run: bool) -> list[tuple[str, str]]:
    """Copy .wav/.ogg files to Content/Audio/."""
    dest_dir = CONTENT_DIR / "Audio"
    added: list[tuple[str, str]] = []
    for f in sorted(src.rglob("*")):
        if f.suffix.lower() not in AUDIO_EXTENSIONS:
            continue
        dest = dest_dir / f.name
        key = _registry_key(dest)
        rel_dest = str(dest.relative_to(REPO_ROOT))
        if dry_run:
            print(f"[dry-run] COPY  {f}  →  {dest}")
        else:
            dest_dir.mkdir(parents=True, exist_ok=True)
            shutil.copy2(f, dest)
            print(f"COPY  {f.name}  →  {rel_dest}")
        added.append((key, rel_dest))
    return added


def _import_animation(src: Path, dry_run: bool) -> list[tuple[str, str]]:
    """Copy .anim / .gltf / .bin files to Content/Animations/."""
    dest_dir = CONTENT_DIR / "Animations"
    added: list[tuple[str, str]] = []
    for f in sorted(src.rglob("*")):
        if f.suffix.lower() not in ANIMATION_EXTENSIONS:
            continue
        dest = dest_dir / f.name
        key = _registry_key(dest)
        rel_dest = str(dest.relative_to(REPO_ROOT))
        if dry_run:
            print(f"[dry-run] COPY  {f}  →  {dest}")
        else:
            dest_dir.mkdir(parents=True, exist_ok=True)
            shutil.copy2(f, dest)
            print(f"COPY  {f.name}  →  {rel_dest}")
        added.append((key, rel_dest))
    return added


def _resolve_creation_dest(file: Path, manifest: dict | None) -> Path | None:
    """Return the destination Content/ path for a Creation Engine file.

    Priority:
    1. content_target field in the companion manifest
    2. Static routing table (CREATION_ROUTING)
    3. Skip file (return None)
    """
    name_lower = file.name.lower()

    # Skip manifest JSON and MTL (MTL lives alongside OBJ, not in Materials)
    if file.suffix.lower() == ".json":
        # Only copy world/tilemap JSONs (they contain a "tiles" key)
        if manifest and "tiles" in manifest:
            return CONTENT_DIR / "World" / file.name
        # Creation Engine manifest companion — skip the manifest itself
        return None

    # Use content_target from manifest if available
    if manifest:
        targets: dict = manifest.get("content_target", {})
        # Find the first target that matches the file type
        for _kind, target_dir in targets.items():
            for suffix_pattern, _ in CREATION_ROUTING:
                if name_lower.endswith(suffix_pattern):
                    return REPO_ROOT / target_dir / file.name

    # Static fallback
    for suffix_pattern, target_dir in CREATION_ROUTING:
        if name_lower.endswith(suffix_pattern):
            return REPO_ROOT / target_dir / file.name

    return None  # unknown type — skip


def _import_creation(src: Path, dry_run: bool) -> list[tuple[str, str]]:
    """Route Creation Engine files to the correct Content/ subdirectory."""
    added: list[tuple[str, str]] = []

    for f in sorted(src.rglob("*")):
        if not f.is_file():
            continue

        # Try to load companion manifest (same stem, .json extension)
        manifest_path = f.with_suffix(".json")
        manifest: dict | None = None
        if manifest_path.exists() and manifest_path != f:
            try:
                with manifest_path.open(encoding="utf-8") as mh:
                    manifest = json.load(mh)
            except (json.JSONDecodeError, OSError):
                pass

        # Special case: if this IS a JSON, load it as its own manifest
        if f.suffix.lower() == ".json":
            try:
                with f.open(encoding="utf-8") as mh:
                    manifest = json.load(mh)
            except (json.JSONDecodeError, OSError):
                continue

        dest = _resolve_creation_dest(f, manifest)
        if dest is None:
            continue

        key = _registry_key(dest)
        rel_dest = str(dest.relative_to(REPO_ROOT))
        if dry_run:
            print(f"[dry-run] COPY  {f.name}  →  {rel_dest}")
        else:
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(f, dest)
            print(f"COPY  {f.name}  →  {rel_dest}")
        added.append((key, rel_dest))

    return added


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        description="Import engine exports into GameRewritten Content/ and update AssetRegistry.json"
    )
    parser.add_argument(
        "--engine",
        required=True,
        choices=["audio", "animation", "creation"],
        help="Which engine produced the source files",
    )
    parser.add_argument(
        "--src",
        required=True,
        type=Path,
        help="Path to the engine's export output directory",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Print what would happen without copying or modifying files",
    )
    args = parser.parse_args(argv)

    src = args.src.resolve()
    if not src.is_dir():
        print(f"ERROR: Source directory not found: {src}", file=sys.stderr)
        return 1

    print(f"Importing {args.engine} assets from: {src}")
    print(f"Repo root: {REPO_ROOT}")
    if args.dry_run:
        print("[dry-run mode — no files will be written]\n")

    if args.engine == "audio":
        added = _import_audio(src, args.dry_run)
    elif args.engine == "animation":
        added = _import_animation(src, args.dry_run)
    else:
        added = _import_creation(src, args.dry_run)

    if not added:
        print("No files matched. Nothing imported.")
        return 0

    # Update AssetRegistry.json
    if not args.dry_run:
        reg = _load_registry()
        assets: dict = reg.setdefault("assets", {})
        new_count = 0
        for key, rel_path in added:
            if key not in assets:
                assets[key] = rel_path
                new_count += 1
            else:
                assets[key] = rel_path  # update path even if key exists
        _save_registry(reg)
        print(f"\nAssetRegistry.json updated: {new_count} new entries ({len(added)} total).")
    else:
        print(f"\n[dry-run] Would add/update {len(added)} entries in AssetRegistry.json.")

    return 0


if __name__ == "__main__":
    sys.exit(main())

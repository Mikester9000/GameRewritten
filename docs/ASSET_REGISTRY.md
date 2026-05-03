# Asset Registry & World Grid — Beginner Guide

## What this system does

The Asset Registry keeps a list of every file your game uses.
Instead of writing the full file path every time (which is easy to get wrong),
you give each file a short "scoped name" and look it up by that name.

Example: instead of `"Content/Textures/placeholder.png"` everywhere in code,
you use the name `"textures.placeholder"` and let the registry find the real path.

This makes it easy to:
- Move files without breaking anything (just update the JSON, not the code).
- See every asset the game uses in one place.
- Press **F5** to reload the list while the game is running.

---

## How scoped names work

A scoped name has two parts joined by a dot:

```
category.specific_name
```

Examples:

| Scoped name               | What it points to                              |
|---------------------------|------------------------------------------------|
| `textures.placeholder`    | `Content/Textures/placeholder.png`             |
| `materials.default`       | `Content/Materials/default.material.json`      |
| `prefabs.tree`            | `Content/Prefabs/tree.prefab.json`             |
| `scenes.test`             | `Content/Scenes/test.scene.json`               |
| `worlds.overworld`        | `Content/World/world.json`                     |

---

## How to add a new asset

1. Copy your file into the appropriate `Content/` sub-folder.  
   (e.g. `Content/Textures/rock.png`)

2. Open `Content/AssetRegistry.json` and add one line inside `"assets"`:

   ```json
   {
       "version": 1,
       "assets": {
           "textures.placeholder":  "Content/Textures/placeholder.png",
           "textures.rock":         "Content/Textures/rock.png"
       }
   }
   ```

3. Press **F5** in the running game — the registry reloads instantly.

4. In code, look it up like this:

   ```cpp
   std::string path = registry.GetPath("textures.rock");
   // path == "Content/Textures/rock.png"
   ```

   If the id doesn't exist, `GetPath` returns an empty string and logs an error —
   the game keeps running and nothing crashes.

---

## How to press F5 to reload

While the game window is in focus, press **F5**.

What happens:
1. `Content/AssetRegistry.json` is read from disk again.
2. `Content/World/world.json` (and all its referenced `cell_X_Z.json` files) is read from disk again.
3. If the world grid reloaded successfully, the forest is **repopulated** from the updated cell data (so changes to `tree_count` / `radius` in a cell file take effect immediately).
4. The Output window logs success or failure for each step separately.
5. If either file has a JSON error, the **old data is kept** — no crash.

This means you can:
- Edit `Content/AssetRegistry.json` in a text editor while the game runs.
- Edit `Content/World/world.json` or any `cell_X_Z.json` file (e.g. change `tree_count`).
- Press F5 — the registry and world grid are reloaded, and the forest reflects any changes.
- If you make a typo, the game logs an error and keeps the old data.

> **Note:** F5 currently reloads the asset registry and world/cell JSON, and repopulates
> the forest. It does not yet reload GPU resources (textures, shaders) or
> rebuild navmesh/physics — those require a full restart for now.

---

## How the world grid works

The world is divided into square **cells** (chunks).
Each cell is a 200×200 unit area of the game world.

```
  cell (0,0)      cell (1,0)
  x: 0–200        x: 200–400
  z: 0–200        z: 0–200

  cell (0,1)      cell (1,1)
  x: 0–200        x: 200–400
  z: 200–400      z: 200–400
```

### world.json — the world map

`Content/World/world.json` lists every cell:

```json
{
    "name": "overworld",
    "version": 1,
    "cell_size": 200.0,
    "cells": [
        { "cx": 0, "cz": 0, "file": "Content/World/cell_0_0.json" }
    ]
}
```

- `cell_size` — how many world units each cell covers (200 = 200×200).
- `cells` — the list of cells; `cx`/`cz` are the grid coordinates.
- `file` — path to a separate JSON file with the cell's detail settings.

### cell_X_Z.json — one cell's settings

`Content/World/cell_0_0.json`:

```json
{
    "cx": 0,
    "cz": 0,
    "terrain": {
        "enabled": true,
        "height_scale": 8.0
    },
    "forest": {
        "enabled": true,
        "tree_count": 80,
        "radius": 50.0
    }
}
```

- `terrain.enabled` — whether this cell has a height-map terrain.
- `terrain.height_scale` — how high the hills are.
- `forest.enabled` — whether trees are placed in this cell.
- `forest.tree_count` — how many trees to scatter.
- `forest.radius` — scatter radius around the cell centre.

### How to add a new cell

1. Create `Content/World/cell_1_0.json`:
   ```json
   {
       "cx": 1,
       "cz": 0,
       "terrain": { "enabled": true, "height_scale": 5.0 },
       "forest":  { "enabled": false }
   }
   ```

2. Add it to `world.json`:
   ```json
   "cells": [
       { "cx": 0, "cz": 0, "file": "Content/World/cell_0_0.json" },
       { "cx": 1, "cz": 0, "file": "Content/World/cell_1_0.json" }
   ]
   ```

3. Press **F5** — the world grid reloads. The new cell is now active when the
   player moves into that grid coordinate (x 200–400, z 0–200).

---

## Upgrading later

This system is intentionally minimal:
- The registry is a plain JSON file — you can add an editor or hot-importer later.
- The world grid is synchronous — you can swap it for async streaming later.
- Cell files are separate — you can add LOD, NavMesh, spawn lists, etc. later
  by just adding more fields to the cell JSON.

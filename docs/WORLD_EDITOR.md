# World Editor

The **World Editor** is an in-engine ImGui panel that lets you click directly on the ground to place prefab instances into the world—no C++ recompile needed.

---

## How to enable Placement Mode

1. Run the game (Debug x64).
2. Press **Esc** to open the pause menu, then **Resume** to return to gameplay.
3. The **"World Editor"** panel appears in the top-left area of the screen.
4. Tick the **"Placement Mode"** checkbox.
5. The cursor becomes visible and the *(ACTIVE)* label appears next to the checkbox.

While Placement Mode is on, WASD / mouse look are suspended so you can freely aim and click.

---

## How to add prefabs to AssetRegistry

Open `Content/AssetRegistry.json` and add an entry whose key starts with `"prefabs."`:

```json
{
  "version": 1,
  "assets": {
    "prefabs.tree":  "Content/Prefabs/tree.prefab.json",
    "prefabs.rock":  "Content/Prefabs/rock.prefab.json"
  }
}
```

Press **F5** in-game to reload the registry.  
The World Editor's prefab list will refresh automatically and show the new ID.

---

## How click placement works

1. Enable **Placement Mode** in the World Editor panel.
2. Move your cursor over the terrain.
3. **Left-click** on the ground.

Internally:

- A world-space ray is built from the mouse screen coordinates using the camera's view + projection matrices.
- The ray is cast against the physics world (Jolt) to find the ground collision point.
- If Jolt finds no hit, the system falls back to a Y = 0 ground-plane intersection.
- The Y position is snapped to the terrain height sampler.
- A `CellInstance` record is added to the **active cell** (the cell the player is currently standing in).
- The instance is immediately spawned into the forest renderer so it appears visually.

Only **"prefabs.*"** scoped IDs registered in `AssetRegistry.json` appear in the picker list.

---

## How to save and reload

### Saving

Click **"Save Cell"** in the World Editor panel.  
The cell's JSON file (e.g. `Content/World/cell_0_0.json`) is rewritten with an updated `"instances"` array:

```json
{
  "cx": 0,
  "cz": 0,
  "terrain": { "enabled": true, "height_scale": 8.0 },
  "forest":  { "enabled": true, "tree_count": 80, "radius": 50.0 },
  "instances": [
    { "prefab": "prefabs.tree", "x": 12.5, "y": 0.0, "z": -8.3, "yaw": 0.0, "scale": 1.0 }
  ]
}
```

If the save fails (e.g. permission error), the error is logged and in-memory instances are kept intact.

### Reloading

- **Restart the game** — instances are loaded from the cell file on startup and spawned automatically.
- **Press F5** while running — reloads both the Asset Registry and the World Grid, then re-spawns procedural trees **and** authored instances.

### Clearing

Click **"Clear Instances"** to remove all authored instances from the active cell and repopulate with procedural trees only.  
Remember to click **"Save Cell"** afterwards if you want the cleared state to persist.

---

## Cell JSON instance format

| Field    | Type   | Default | Description                          |
|----------|--------|---------|--------------------------------------|
| `prefab` | string | —       | Scoped asset ID, e.g. `"prefabs.tree"` |
| `x`      | float  | 0.0     | World X position                     |
| `y`      | float  | 0.0     | World Y position (terrain-snapped on spawn) |
| `z`      | float  | 0.0     | World Z position                     |
| `yaw`    | float  | 0.0     | Rotation around Y axis (radians)     |
| `scale`  | float  | 1.0     | Uniform scale                        |

---

## Keyboard reference

| Key   | Action                              |
|-------|-------------------------------------|
| F5    | Reload Asset Registry + World Grid  |
| Esc   | Open/close pause menu               |
| F1    | Toggle debug overlay                |
| LMB   | Place instance (Placement Mode on)  |

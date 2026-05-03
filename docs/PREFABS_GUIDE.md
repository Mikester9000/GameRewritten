# Prefabs Guide

This guide explains how to create new primitive prefabs, register them in the Asset Registry, reload them at runtime, place them in the world using the World Editor, and verify they persist.

---

## What is a primitive prefab?

A **primitive prefab** is a JSON file that defines a game object as a list of coloured box parts. Because every part is a plain box, there are no 3D model files to worry about — you just describe the shape numerically. This is what gives the game its retro, low-poly, PS2-era look.

Each part has:
| Field    | What it does |
|----------|-------------|
| `shape`  | Always `"box"` for now |
| `offset` | `[x, y, z]` local position from the prefab's origin |
| `scale`  | `[width, height, depth]` in world units |
| `color`  | `[r, g, b, a]` each value from 0.0 to 1.0 |

---

## Step 1 — Create the prefab JSON file

Create a new file in `Content/Prefabs/`. Name it `<something>.prefab.json`.

Here is the minimum required format:

```json
{
    "name": "my_rock",
    "category": "rock",
    "parts": [
        {
            "shape": "box",
            "offset": [0.0, 0.4, 0.0],
            "scale":  [1.0, 0.8, 0.9],
            "color":  [0.38, 0.36, 0.36, 1.0]
        }
    ]
}
```

### The `category` field selects the shader

| Category value | Shader used | Effect |
|----------------|-------------|--------|
| `"tree"` | `tree_ps.hlsl` | Vertical colour gradient + per-location variation |
| Anything else (`"rock"`, `"prop"`, `"ruin"`, …) | `prim_ps.hlsl` | Flat directional light + ambient |

### Tips for building good shapes

- Start with `offset: [0, 0.5, 0]` for a box that sits neatly on the ground (because the unit cube goes from -0.5 to +0.5 in Y, so offsetting by half its height puts the bottom at Y=0).
- Stack parts vertically: trunks go first, canopies go on top.
- Use a slightly different `color` value between adjacent parts to break up the silhouette.

---

## Step 2 — Register it in `Content/AssetRegistry.json`

Open `Content/AssetRegistry.json` and add a new line inside the `"assets"` object:

```json
"prefabs.my_rock": "Content/Prefabs/my_rock.prefab.json"
```

The key **must** start with `prefabs.` — that is how the World Editor discovers prefabs.

Your full entry will look something like this:

```json
{
    "version": 1,
    "assets": {
        ...
        "prefabs.my_rock": "Content/Prefabs/my_rock.prefab.json"
    }
}
```

---

## Step 3 — Press F5 to reload

While the game is running, press **F5**.

This reloads:
1. The Asset Registry (picks up your new entry).
2. The World Grid (re-reads cell files).
3. The Prefab Library (parses every `prefabs.*` JSON file and caches it).
4. The World Editor prefab list (updates the dropdown).

If everything went well you will see your new ID in the **World Editor** panel on the left side of the screen.

---

## Step 4 — Place it with the World Editor

1. Open the **World Editor** panel (it appears by default in the top-left area).
2. Tick **Placement Mode** (or press the checkbox). A green `(ACTIVE)` label appears.
3. Select your prefab ID from the list (scroll if needed).
4. Left-click anywhere on the terrain. Your prefab's coloured boxes will appear at that location.

> **Note:** while Placement Mode is active you can still walk with **WASD** and jump with **Space**. Only mouse-look is paused so your cursor stays free for clicking.

---

## Step 5 — Save the cell and verify persistence

1. Click **Save Cell** in the World Editor panel.  
   This writes the placed instances back to `Content/World/cell_X_Z.json`.
2. Close and reopen the game (or press F5).  
   The instances are loaded from the cell file and appear in the same positions.

---

## Complete example prefabs

### Example 1 — Oak Tree (two-part: trunk + canopy)

```json
{
    "name": "tree_oak",
    "category": "tree",
    "parts": [
        {
            "shape": "box",
            "offset": [0.0, 0.8, 0.0],
            "scale":  [0.28, 1.6, 0.28],
            "color":  [0.40, 0.25, 0.10, 1.0]
        },
        {
            "shape": "box",
            "offset": [0.0, 2.0, 0.0],
            "scale":  [1.30, 1.10, 1.30],
            "color":  [0.12, 0.55, 0.12, 1.0]
        },
        {
            "shape": "box",
            "offset": [0.0, 2.9, 0.0],
            "scale":  [0.80, 0.70, 0.80],
            "color":  [0.10, 0.50, 0.10, 1.0]
        }
    ]
}
```

**What each part is:**
- Part 1 (brown, narrow, tall): the trunk
- Part 2 (green, wide): the main canopy
- Part 3 (green, smaller): the upper canopy taper

Because `category` is `"tree"`, the tree shader adds a vertical colour gradient and subtle per-location variation so a forest of oak trees doesn't look copy-pasted.

**Asset Registry entry:**
```json
"prefabs.tree_oak": "Content/Prefabs/tree_oak.prefab.json"
```

---

### Example 2 — Medium Rock (three-part cluster)

```json
{
    "name": "rock_medium",
    "category": "rock",
    "parts": [
        {
            "shape": "box",
            "offset": [ 0.0, 0.40,  0.0],
            "scale":  [1.20, 0.80, 1.00],
            "color":  [0.38, 0.36, 0.36, 1.0]
        },
        {
            "shape": "box",
            "offset": [ 0.3, 0.75,  0.2],
            "scale":  [0.60, 0.55, 0.50],
            "color":  [0.40, 0.38, 0.38, 1.0]
        },
        {
            "shape": "box",
            "offset": [-0.3, 0.65, -0.1],
            "scale":  [0.50, 0.45, 0.40],
            "color":  [0.35, 0.33, 0.33, 1.0]
        }
    ]
}
```

**What each part is:**
- Part 1 (large, grey, low): the main boulder
- Part 2 (medium, slightly lighter): a secondary boulder offset to the right
- Part 3 (smaller, slightly darker): a tertiary boulder offset to the left

The three-box composition gives the silhouette more visual interest than a single box.

**Asset Registry entry:**
```json
"prefabs.rock_medium": "Content/Prefabs/rock_medium.prefab.json"
```

---

## Quick-reference: all built-in prefabs

### Generic prefabs (no biome prefix)

| Asset ID | Name | Category |
|----------|------|----------|
| `prefabs.tree` | tree_oak | tree |
| `prefabs.tree_oak` | tree_oak | tree |
| `prefabs.tree_pine` | tree_pine | tree |
| `prefabs.tree_birch` | tree_birch | tree |
| `prefabs.tree_dead` | tree_dead | tree |
| `prefabs.bush_small` | bush_small | tree |
| `prefabs.bush_dense` | bush_dense | tree |
| `prefabs.rock_small` | rock_small | rock |
| `prefabs.rock_medium` | rock_medium | rock |
| `prefabs.rock_large` | rock_large | rock |
| `prefabs.rock_cluster` | rock_cluster | rock |
| `prefabs.rock_mossy` | rock_mossy | rock |
| `prefabs.signpost` | signpost | prop |
| `prefabs.fence_segment` | fence_segment | prop |
| `prefabs.marker_stone` | marker_stone | prop |
| `prefabs.crate` | crate | prop |
| `prefabs.barrel` | barrel | prop |
| `prefabs.campfire_ring` | campfire_ring | prop |
| `prefabs.tent_blockout` | tent_blockout | prop |
| `prefabs.pillar` | pillar | ruin |
| `prefabs.pillar_broken` | pillar_broken | ruin |
| `prefabs.low_wall` | low_wall | ruin |
| `prefabs.arch_blockout` | arch_blockout | ruin |
| `prefabs.well` | well | prop |
| `prefabs.flower_patch` | flower_patch | prop |
| `prefabs.grass_tuft` | grass_tuft | tree |
| `prefabs.hill_marker` | hill_marker | prop |
| `prefabs.crystal_formation` | crystal_formation | prop |
| `prefabs.fallen_log` | fallen_log | prop |
| `prefabs.mushroom_ring` | mushroom_ring | prop |

### Biome-prefixed prefabs

#### Grassland (`prefabs.grass.*`)

| Asset ID | Description | Category |
|----------|-------------|----------|
| `prefabs.grass.tree_oak_a` | Oak tree variant A (3 parts) | tree |
| `prefabs.grass.tree_oak_b` | Oak tree variant B (4 parts) | tree |
| `prefabs.grass.tree_willow` | Drooping willow-style tree | tree |
| `prefabs.grass.bush_a` | Small bush | tree |
| `prefabs.grass.bush_b` | Large bush | tree |
| `prefabs.grass.rock_mossy` | Mossy boulder cluster | rock |
| `prefabs.grass.rock_small` | Small grey rock | rock |
| `prefabs.grass.log_fallen` | Fallen log | prop |
| `prefabs.grass.fence_post` | Wooden fence segment | prop |
| `prefabs.grass.well` | Stone well | prop |
| `prefabs.grass.signpost` | Directional signpost | prop |
| `prefabs.grass.campfire` | Campfire with rocks | prop |
| `prefabs.grass.flower_patch` | Colourful flower cluster | prop |

#### Desert (`prefabs.desert.*`)

| Asset ID | Description | Category |
|----------|-------------|----------|
| `prefabs.desert.cactus_tall` | Tall branching cactus | prop |
| `prefabs.desert.cactus_squat` | Short stubby cactus | prop |
| `prefabs.desert.dead_shrub` | Dried-out twig shrub | prop |
| `prefabs.desert.sand_rock_a` | Sandy sandstone formation A | rock |
| `prefabs.desert.sand_rock_b` | Sandy sandstone cluster B | rock |
| `prefabs.desert.ruins_wall` | Crumbling sandstone wall | ruin |
| `prefabs.desert.ruins_pillar` | Standing stone pillar | ruin |
| `prefabs.desert.tent` | Desert shelter tent | prop |
| `prefabs.desert.dune_marker` | Striped dune waymarker | prop |
| `prefabs.desert.crate_weathered` | Sun-bleached crate | prop |
| `prefabs.desert.obelisk` | Tall ancient obelisk | ruin |

#### Rocky (`prefabs.rocky.*`)

| Asset ID | Description | Category |
|----------|-------------|----------|
| `prefabs.rocky.boulder_a` | Large multi-chunk boulder | rock |
| `prefabs.rocky.boulder_b` | Medium boulder pair | rock |
| `prefabs.rocky.cliff_chunk` | Tall cliff fragment | rock |
| `prefabs.rocky.rubble_pile` | Scattered rock debris | rock |
| `prefabs.rocky.pillar` | Smooth stone pillar | ruin |
| `prefabs.rocky.pillar_broken` | Shattered pillar stump | ruin |
| `prefabs.rocky.ruins_arch` | Stone arch gateway | ruin |
| `prefabs.rocky.ruins_wall` | Broken stone wall | ruin |
| `prefabs.rocky.dead_tree` | Bare leafless tree | tree |
| `prefabs.rocky.waymarker` | Stacked stone waypoint | prop |

#### Snow (`prefabs.snow.*`)

| Asset ID | Description | Category |
|----------|-------------|----------|
| `prefabs.snow.pine_a` | Snow-capped tall pine | tree |
| `prefabs.snow.pine_b` | Snow-capped short pine | tree |
| `prefabs.snow.dead_tree` | Frost-covered dead tree | tree |
| `prefabs.snow.boulder` | Snow-topped boulder | rock |
| `prefabs.snow.ice_shard` | Crystalline ice spire | prop |
| `prefabs.snow.mound` | Rounded snow mound | prop |
| `prefabs.snow.ruins_pillar` | Snow-dusted stone pillar | ruin |
| `prefabs.snow.ruins_wall` | Snow-covered crumbling wall | ruin |
| `prefabs.snow.dead_shrub` | Frozen twig shrub | prop |
| `prefabs.snow.camp_marker` | Snow-capped stone marker | prop |

### Vehicles (`prefabs.props.*`)

| Asset ID | Description | Category |
|----------|-------------|----------|
| `prefabs.props.vehicle_car` | PS2-style blocky car | prop |
| `prefabs.props.vehicle_truck` | PS2-style box truck | prop |
| `prefabs.props.vehicle_motorcycle` | PS2-style motorcycle | prop |

---

## Biomes and terrain cell JSON

### How biomes work

Each world cell has a `terrain.biome` setting that controls the height-map noise pattern and vertex-color gradient used when the cell's terrain mesh is built. There is **no blending** — walking across a cell boundary immediately switches terrain (hard biome border). This gives a clear, retro feel.

| Biome | Ground colors | Terrain character |
|-------|---------------|-------------------|
| `grassland` | Green lowlands → brown rock tops | Moderate rolling hills |
| `desert` | Sandy tan lowlands → pale rock tops | Smooth, wide dunes |
| `rocky` | Dark grey stone → lighter grey | Sharp, jagged peaks |
| `snow` | Blue-grey stone → near-white snow | Cold, craggy mountains |

### Cell JSON fields

Each `Content/World/cell_X_Z.json` supports the following terrain keys:

```json
{
    "cx": 0,
    "cz": 0,
    "terrain": {
        "enabled": true,
        "biome": "grassland",
        "seed": 12345,
        "height_scale": 8.0,
        "noise_freq": 0.08,
        "noise_freq2": 0.03
    },
    "forest": { ... },
    "instances": [ ... ]
}
```

| Field | Type | Default | Description |
|-------|------|---------|-------------|
| `enabled` | bool | `true` | Whether the terrain mesh is generated for this cell |
| `biome` | string | `"grassland"` | One of `"grassland"`, `"desert"`, `"rocky"`, `"snow"` |
| `seed` | int | `12345` | Shifts the noise sample coordinates so every cell has a unique shape |
| `height_scale` | float | `8.0` | Vertical amplitude of hills in world units |
| `noise_freq` | float | `0.08` | Primary noise frequency (higher = more detail) |
| `noise_freq2` | float | `0.03` | Secondary noise frequency for large-scale variation |

### World grid layout (3×3 test grid)

The starter world uses a 3×3 grid of 400×400-unit cells:

```
(-1,1) snow    (0,1) rocky    (1,1) grassland
(-1,0) snow    (0,0) grassland (1,0) desert
(-1,-1) rocky  (0,-1) desert  (1,-1) rocky
```

The player starts in cell (0,-1) (just south of the grassland centre) and can walk in any direction to cross into a neighboring biome. Terrain rebuilds instantly with no loading screen.

### Adding a new cell

1. Create `Content/World/cell_X_Z.json` with the desired biome + seed.
2. Add an entry to `Content/World/world.json` in the `"cells"` array:
   ```json
   { "cx": 2, "cz": 0, "file": "Content/World/cell_2_0.json" }
   ```
3. Press **F5** in-game to reload the world grid and rebuild the active cell's terrain.

---

## Troubleshooting

| Problem | What to check |
|---------|---------------|
| Prefab not in list after F5 | Make sure the asset ID starts with `prefabs.` |
| Placement Mode checkbox is greyed out | No `prefabs.*` entries are registered — check `AssetRegistry.json` |
| Object not visible after placing | Check the `Output` window in Visual Studio for JSON parse errors in the prefab file |
| Object appears at wrong height | The engine snaps Y to terrain automatically; verify terrain is enabled in the cell JSON |
| Camera jumps when leaving Placement Mode | Fixed — the engine resets the mouse baseline (re-centres the cursor and skips the first mouse-look delta) when Placement Mode is turned off. Ensure you are running the latest version of the code. |

- 2026-05-07: Added `TextureCache` (DirectXTex-backed, SRV cache) and wired into `D3D11Renderer` terrain/ground draw paths.
- 2026-05-07: Added header-only `PlayerStats` and wired per-frame passive ATB charge updates through `RuntimeScene`.
- 2026-05-07: Added gameplay HUD overlay showing player HP/MP/ATB (with ATB READY indicator) and wired it into the ImGui frame path.
- 2026-05-07: Added single directional sun lighting (diffuse + ambient) with live debug-overlay sliders and shader updates for ground/basic3d/tree.
- 2026-05-08: Added header-only `InputActionMap` and migrated camera movement/jump plus Main.cpp Escape/F1/F5 edge polling to action-based bindings.
- 2026-05-08: Added simple custom static AABB collision (prefab-part blockers + camera movement pushout) to prevent player clipping through placed prefab geometry.
- 2026-05-08: Added basic EnemyActor with two-waypoint patrol, terrain-snap Y, and player-blockout visual; wired into RuntimeScene and Main.

- 2026-05-08: Added ImGui dialog box UI with typewriter text reveal, E-to-continue dismiss behavior, and main-loop wiring.

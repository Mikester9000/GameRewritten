# ORDER_PLAN.md

**Execution order for all 739 tasks across 8 plan files**  
Format: `Number -> Task Name -> Plan File -> Task Number in That Plan`

---

## EXECUTION PHILOSOPHY

Tasks are ordered by **dependency chains** and **logical build progression**:

1. **Foundation Layer** (Core engine, rendering, input)
2. **Combat Core** (Battle systems before world systems)
3. **World Systems** (Open-world after combat works)
4. **Content Pipeline** (Authoring tools after runtime works)
5. **Polish & Features** (Advanced systems after basics)
6. **Accessibility & Settings** (UX refinement)
7. **Final Release** (Platform integration, localization)

Within each layer, **headers come before implementations** where needed.

---

## PHASE 1: FOUNDATION & CORE SYSTEMS (Tasks 1-150)

### 1.1 Core Engine & Rendering (1-30)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 1 | Hit pause / hitstop | BASE | 005 |
| 2 | Camera shake | BASE | 020 |
| 3 | Combat camera zoom | BASE | 021 |
| 4 | Camera collision avoidance | BASE | 022 |
| 5 | Target framing adjustment | BASE | 023 |
| 6 | Lock-on camera recovery smoothing | BASE | 024 |
| 7 | Wind effect on trees | BASE | 025 |
| 8 | Weather system lite | BASE | 026 |
| 9 | Ambient particles | BASE | 027 |
| 10 | Day/night cycle | BASE | 028 |
| 11 | Biome transition fade | BASE | 029 |
| 12 | Quality preset enforcement | BASE | 046 |
| 13 | Large-world coordinate rebasing | BASE | 063 |
| 14 | Terrain/mesh LOD tier manager | BASE | 064 |
| 15 | Streaming budget governor (CPU/GPU/IO) | BASE | 065 |
| 16 | Far-distance continent impostors | BASE | 066 |
| 17 | World partition + region streaming core | BASE | 061 |
| 18 | Asynchronous chunk IO + prefetch queue | BASE | 062 |
| 19 | Graphics settings preset system (Low/Med/High/Ultra) | CON7 | 383 |
| 20 | Graphics settings preset system header | CON7 | 383H |
| 21 | V-sync + FPS limiter system | CON7 | 384 |
| 22 | V-sync + FPS limiter header | CON7 | 384H |
| 23 | Anti-aliasing options system | CON7 | 385 |
| 24 | Anti-aliasing options header | CON7 | 385H |
| 25 | Ultrawide monitor support system | CON7 | 389 |
| 26 | Ultrawide monitor support header | CON7 | 389H |
| 27 | Post-process effect toggle system | CON7 | 390 |
| 28 | Post-process effect toggle header | CON7 | 390H |
| 29 | HUD opacity slider | CON7 | 391 |
| 30 | HUD opacity slider header | CON7 | 391H |

### 1.2 Combat Foundation (31-80)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 31 | Pressure / stagger integration stub | BASE | 001 |
| 32 | Pressure / stagger integration header | BASE | 001H |
| 33 | Enemy reaction / interrupt-lite | BASE | 002 |
| 34 | Enemy reaction header | BASE | 002H |
| 35 | Enemy attack telegraph lite | BASE | 003 |
| 36 | Enemy attack telegraph header | BASE | 003H |
| 37 | Stagger meter | BASE | 006 |
| 38 | Stagger meter header | BASE | 006H |
| 39 | Enemy attack telegraph | BASE | 007 |
| 40 | Parry / counter window | BASE | 008 |
| 41 | Parry / counter header | BASE | 008H |
| 42 | Weak point damage | BASE | 009 |
| 43 | Weak point damage header | BASE | 009H |
| 44 | XP / level system | BASE | 042 |
| 45 | XP / level system header | BASE | 042H |
| 46 | Status effects | BASE | 043 |
| 47 | Status effects header | BASE | 043H |
| 48 | Equipment slot stub | BASE | 053 |
| 49 | Equipment slot header | BASE | 053H |
| 50 | Ability unlock / progression hook | BASE | 054 |
| 51 | Ability unlock header | BASE | 054H |
| 52 | Combat stat modifier pipeline stub | BASE | 055 |
| 53 | Combat stat modifier header | BASE | 055H |
| 54 | Elemental damage/resistance matrix | BASE | 085 |
| 55 | Elemental damage header | BASE | 085H |
| 56 | Status ailment counters + immunity windows | BASE | 086 |
| 57 | Status ailment counters header | BASE | 086H |
| 58 | Guard-break / poise combat pipeline | BASE | 084 |
| 59 | Guard-break header | BASE | 084H |
| 60 | Enemy stagger/break gauge UI (FF7 Remake) | CON5 | 336 |
| 61 | Enemy stagger gauge UI header | CON5 | 336H |
| 62 | Combat speed slider (FF7R-style) | CON7 | 392 |
| 63 | Combat speed slider header | CON7 | 392H |
| 64 | Combo cancel system | CON2 | 247 |
| 65 | Combo cancel header | CON2 | 247H |
| 66 | Perfect dodge i-frames | CON2 | 249 |
| 67 | Perfect dodge header | CON2 | 249H |
| 68 | Break-state vulnerability window | CON2 | 250 |
| 69 | Break-state header | CON2 | 250H |
| 70 | Weak-point targeting UI overlay | CON2 | 251 |
| 71 | Weak-point targeting header | CON2 | 251H |
| 72 | Limit break cinematic camera | CON2 | 252 |
| 73 | Limit break cinematic header | CON2 | 252H |
| 74 | Enemy stagger damage multiplier | CON2 | 253 |
| 75 | Enemy stagger multiplier header | CON2 | 253H |
| 76 | Limit break evolution/leveling system | CON5 | 337 |
| 77 | Limit break evolution header | CON5 | 337H |
| 78 | Elemental weakness exploitation bonus | CON5 | 343 |
| 79 | Elemental weakness bonus header | CON5 | 343H |
| 80 | Combat bugfix sweep | BASE | 056 |

### 1.3 UI/HUD Core (81-110)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 81 | Screen edge damage flash | BASE | 004 |
| 82 | Screen edge damage header | BASE | 004H |
| 83 | Area name display | BASE | 010 |
| 84 | Area name display header | BASE | 010H |
| 85 | Notification toast system | BASE | 011 |
| 86 | Notification toast header | BASE | 011H |
| 87 | Letterbox event bars | BASE | 012 |
| 88 | Letterbox event header | BASE | 012H |
| 89 | Contextual button prompts | BASE | 013 |
| 90 | Contextual prompts header | BASE | 013H |
| 91 | Level up screen overlay | BASE | 014 |
| 92 | Level up screen header | BASE | 014H |
| 93 | Status screen | BASE | 015 |
| 94 | Status screen header | BASE | 015H |
| 95 | Map screen stub | BASE | 016 |
| 96 | Map screen header | BASE | 016H |
| 97 | Tooltip system | BASE | 017 |
| 98 | Tooltip system header | BASE | 017H |
| 99 | Saving indicator | BASE | 018 |
| 100 | Saving indicator header | BASE | 018H |
| 101 | Death / defeat screen | BASE | 019 |
| 102 | Death screen header | BASE | 019H |
| 103 | Auto-save indicator icon | CON6 | 361 |
| 104 | Auto-save indicator header | CON6 | 361H |
| 105 | Compass direction overlay | CON6 | 362 |
| 106 | Compass overlay header | CON6 | 362H |
| 107 | Quest waypoint distance display | CON6 | 363 |
| 108 | Quest waypoint distance header | CON6 | 363H |
| 109 | Tutorial/control reminder pause menu | CON6 | 364 |
| 110 | Tutorial reminder header | CON6 | 364H |

### 1.4 Inventory & Progression (111-140)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 111 | Inventory system | BASE | 041 |
| 112 | Inventory system header | BASE | 041H |
| 113 | Equipment visual change system | CON2 | 254 |
| 114 | Equipment visual change header | CON2 | 254H |
| 115 | Materia/gem socket system (FF7 core) | CON5 | 335 |
| 116 | Materia socket system header | CON5 | 335H |
| 117 | Weapon/armor upgrade tree system | CON5 | 340 |
| 118 | Weapon upgrade tree header | CON5 | 340H |
| 119 | Passive skill tree/sphere grid | CON5 | 341 |
| 120 | Passive skill tree header | CON5 | 341H |
| 121 | Character job/class system | CON5 | 342 |
| 122 | Job/class system header | CON5 | 342H |
| 123 | Status effect crafting system | CON5 | 344 |
| 124 | Status effect crafting header | CON5 | 344H |
| 125 | Summon materia collection system | CON5 | 338 |
| 126 | Summon materia collection header | CON5 | 338H |
| 127 | Weapon ability unlock via use | CON5 | 339 |
| 128 | Weapon ability proficiency header | CON5 | 339H |
| 129 | Transmog/glamour cosmetic system | CON4 | 333 |
| 130 | Transmog system header | CON4 | 333H |
| 131 | Item comparison tooltip (stat diff) | CON3 | 290 |
| 132 | Item comparison tooltip header | CON3 | 290H |
| 133 | Inventory sorting/filtering system | CON3 | 291 |
| 134 | Inventory sorting header | CON3 | 291H |
| 135 | Crafting recipe discovery system | CON2 | 265 |
| 136 | Crafting recipe discovery header | CON2 | 265H |
| 137 | Item rarity color-coding system | CON2 | 266 |
| 138 | Item rarity color-coding header | CON2 | 266H |
| 139 | Equipment loadout presets | CON2 | 255 |
| 140 | Equipment loadout presets header | CON2 | 255H |

### 1.5 Save/Load & Core Systems (141-150)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 141 | Save / load system | BASE | 045 |
| 142 | Save / load system header | BASE | 045H |
| 143 | Manual save slot naming system | CON7 | 388 |
| 144 | Manual save naming header | CON7 | 388H |
| 145 | Quick save/quick load hotkey system | CON7 | 387 |
| 146 | Quick save/load header | CON7 | 387H |
| 147 | Audio channel volume controller | CON7 | 377 |
| 148 | Audio channel controller header | CON7 | 377H |
| 149 | Camera sensitivity controller | CON7 | 378 |
| 150 | Camera sensitivity header | CON7 | 378H |

---

## PHASE 2: WORLD SYSTEMS & EXPLORATION (Tasks 151-300)

### 2.1 World Streaming & Structure (151-180)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 151 | Fog of war on minimap | BASE | 030 |
| 152 | Fog of war header | BASE | 030H |
| 153 | World event trigger zones | BASE | 031 |
| 154 | World event trigger header | BASE | 031H |
| 155 | Interaction hotspot registry stub | BASE | 032 |
| 156 | Interaction hotspot header | BASE | 032H |
| 157 | Landmark discovery trigger stub | BASE | 033 |
| 158 | Landmark discovery header | BASE | 033H |
| 159 | Global nav tile streaming bridge | BASE | 067 |
| 160 | Global nav tile header | BASE | 067H |
| 161 | Seamless continent transition triggers | BASE | 068 |
| 162 | Seamless continent header | BASE | 068H |
| 163 | Seamless interior/exterior cell portals | BASE | 071 |
| 164 | Cell portal header | BASE | 071H |
| 165 | World map overlay with continent zoom | BASE | 072 |
| 166 | World map overlay header | BASE | 072H |
| 167 | Discovery journal for landmarks/routes | BASE | 073 |
| 168 | Discovery journal header | BASE | 073H |
| 169 | Biome-aware population spawn director | BASE | 074 |
| 170 | Biome spawn director header | BASE | 074H |
| 171 | World event scheduler (time/weather/region) | BASE | 075 |
| 172 | World event scheduler header | BASE | 075H |
| 173 | Region state persistence for streamed world | BASE | 076 |
| 174 | Region state persistence header | BASE | 076H |
| 175 | Zone difficulty tier system | CON6 | 381 |
| 176 | Zone difficulty tier header | CON6 | 381H |
| 177 | Enemy spawn level mapper | CON6 | 382 |
| 178 | Enemy spawn level mapper header | CON6 | 382H |
| 179 | Spawn composition table stub (solo/pair/pack) | BASE | 040 |
| 180 | Spawn composition header | BASE | 040H |

### 2.2 Traversal & Movement (181-210)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 181 | Traversal mount/vehicle framework stub | BASE | 069 |
| 182 | Traversal mount header | BASE | 069H |
| 183 | Traversal verbs: climb/swim/glide base | BASE | 070 |
| 184 | Traversal controller header | BASE | 070H |
| 185 | Fast travel stub | BASE | 044 |
| 186 | Fast travel header | BASE | 044H |
| 187 | Fast travel unlock-on-discovery | CON3 | 292 |
| 188 | Fast travel unlock header | CON3 | 292H |
| 189 | Landmark discovery fanfare | CON3 | 293 |
| 190 | Landmark discovery fanfare header | CON3 | 293H |
| 191 | Ground vehicle (car/buggy) base | CON1 | 161 |
| 192 | Ground vehicle header | CON1 | 161H |
| 193 | Flying vehicle (airship) base | CON1 | 162 |
| 194 | Flying vehicle header | CON1 | 162H |
| 195 | Water vehicle (boat) base | CON1 | 163 |
| 196 | Water vehicle header | CON1 | 163H |
| 197 | Chocobo mount system | CON1 | 164 |
| 198 | Chocobo mount header | CON1 | 164H |
| 199 | Vehicle speed boost/drift | CON1 | 165 |
| 200 | Vehicle boost header | CON1 | 165H |
| 201 | Vehicle upgrade system | CON1 | 166 |
| 202 | Vehicle upgrade header | CON1 | 166H |
| 203 | Vehicle fuel/stamina system | CON1 | 167 |
| 204 | Vehicle fuel header | CON1 | 167H |
| 205 | Roads & traffic AI system | CON1 | 168 |
| 206 | Roads & traffic header | CON1 | 168H |
| 207 | Road pathfinding for AI | CON1 | 169 |
| 208 | Road pathfinding header | CON1 | 169H |
| 209 | Vehicle collision & physics | CON1 | 170 |
| 210 | Vehicle collision header | CON1 | 170H |

### 2.3 NPCs & World Life (211-240)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 211 | NPC actor | BASE | 034 |
| 212 | NPC actor header | BASE | 034H |
| 213 | NPC interaction prompt routing stub | BASE | 038 |
| 214 | NPC interaction header | BASE | 038H |
| 215 | NPC day/night schedule system | CON1 | 184 |
| 216 | NPC schedule header | CON1 | 184H |
| 217 | NPC idle behavior animations | CON1 | 185 |
| 218 | NPC idle behavior header | CON1 | 185H |
| 219 | NPC conversation system | CON1 | 186 |
| 220 | NPC conversation header | CON1 | 186H |
| 221 | Shop vendor system | CON1 | 187 |
| 222 | Shop vendor header | CON1 | 187H |
| 223 | Inn/tavern rest system | CON1 | 188 |
| 224 | Inn/tavern rest header | CON1 | 188H |
| 225 | Random NPC chatter system | CON2 | 267 |
| 226 | Random NPC chatter header | CON2 | 267H |
| 227 | NPC relationship memory system | CON2 | 268 |
| 228 | NPC relationship memory header | CON2 | 268H |
| 229 | Dynamic NPC reactions to player actions | CON2 | 269 |
| 230 | Dynamic NPC reactions header | CON2 | 269H |
| 231 | Gift-giving affinity system | CON5 | 345 |
| 232 | Gift affinity system header | CON5 | 345H |
| 233 | NPC memory/relationship tracking | CON5 | 346 |
| 234 | NPC memory system header | CON5 | 346H |
| 235 | Inn/tavern rumors board | CON5 | 347 |
| 236 | Inn rumors board header | CON5 | 347H |
| 237 | Street performer/musician ambient system | CON5 | 348 |
| 238 | Street performer system header | CON5 | 348H |
| 239 | Romance system with dating scenes | CON5 | 349 |
| 240 | Romance system header | CON5 | 349H |

### 2.4 Quests & Progression (241-270)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 241 | Quest objective system | BASE | 035 |
| 242 | Quest objective header | BASE | 035H |
| 243 | Quest flag / world-state hook | BASE | 039 |
| 244 | Quest flag header | BASE | 039H |
| 245 | Treasure chest actor | BASE | 036 |
| 246 | Treasure chest header | BASE | 036H |
| 247 | Campfire / rest point actor | BASE | 037 |
| 248 | Rest point actor header | BASE | 037H |
| 249 | Side quest discovery system | CON1 | 189 |
| 250 | Side quest discovery header | CON1 | 189H |
| 251 | Quest tracker HUD | CON3 | 294 |
| 252 | Quest tracker HUD header | CON3 | 294H |
| 253 | Minimap with rotation toggle | CON3 | 295 |
| 254 | Minimap rotation header | CON3 | 295H |
| 255 | Collectibles tracker system | CON1 | 215 |
| 256 | Collectibles tracker header | CON1 | 215H |
| 257 | Bounty hunt board system | CON1 | 216 |
| 258 | Bounty hunt board header | CON1 | 216H |
| 259 | Party member loyalty missions | CON5 | 350 |
| 260 | Loyalty missions header | CON5 | 350H |
| 261 | Point-of-no-return warning system | CON5 | 357 |
| 262 | Point-of-no-return header | CON5 | 357H |
| 263 | Missable content notification system | CON5 | 358 |
| 264 | Missable content alert header | CON5 | 358H |
| 265 | World state change system after story beats | CON5 | 359 |
| 266 | World state change header | CON5 | 359H |
| 267 | NPC reaction dialogue to story progress | CON5 | 360 |
| 268 | NPC story reactions header | CON5 | 360H |
| 269 | Scripted world event trigger system | CON5 | 356 |
| 270 | Scripted world events header | CON5 | 356H |

### 2.5 Weather & Environment (271-300)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 271 | Rain terrain modifier system | CON6 | 375 |
| 272 | Rain terrain modifier header | CON6 | 375H |
| 273 | Snow/ice terrain modifier system | CON6 | 376 |
| 274 | Snow/ice terrain modifier header | CON6 | 376H |
| 275 | Dynamic weather system (rain/snow/fog) | CON1 | 177 |
| 276 | Dynamic weather header | CON1 | 177H |
| 277 | Weather transitions | CON1 | 178 |
| 278 | Weather transitions header | CON1 | 178H |
| 279 | Time-of-day lighting system | CON1 | 179 |
| 280 | Time-of-day lighting header | CON1 | 179H |
| 281 | Atmospheric fog system | CON1 | 180 |
| 282 | Atmospheric fog header | CON1 | 180H |
| 283 | Wind system for foliage | CON1 | 181 |
| 284 | Wind system header | CON1 | 181H |
| 285 | Lightning strikes during storms | CON1 | 182 |
| 286 | Lightning strikes header | CON1 | 182H |
| 287 | Volumetric cloud system | CON1 | 183 |
| 288 | Volumetric cloud header | CON1 | 183H |
| 289 | PS2-era texture filtering | CON1 | 131 |
| 290 | PS2-era texture filtering header | CON1 | 131H |
| 291 | Pre-baked lightmaps | CON1 | 132 |
| 292 | Pre-baked lightmaps header | CON1 | 132H |
| 293 | Vertex color ambient occlusion | CON1 | 133 |
| 294 | Vertex color AO header | CON1 | 133H |
| 295 | FF7-style pre-rendered backgrounds | CON1 | 134 |
| 296 | Pre-rendered backgrounds header | CON1 | 134H |
| 297 | Billboard impostor LODs | CON1 | 135 |
| 298 | Billboard impostor header | CON1 | 135H |
| 299 | Handmade asset placement tools | CON1 | 136 |
| 300 | Handmade asset placement header | CON1 | 136H |

---

## PHASE 3: COMBAT DEPTH & PARTY (Tasks 301-400)

### 3.1 Party & AI Systems (301-330)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 301 | Party member runtime slot + follow AI | BASE | 077 |
| 302 | Party runtime header | BASE | 077H |
| 303 | Command wheel + tactical slow-time commands | BASE | 078 |
| 304 | Command wheel header | BASE | 078H |
| 305 | ATB-style action charge lanes | BASE | 079 |
| 306 | ATB system header | BASE | 079H |
| 307 | Ability targeting templates (single/cone/aoe) | BASE | 080 |
| 308 | Ability targeting header | BASE | 080H |
| 309 | Enemy archetype behavior profiles | BASE | 081 |
| 310 | Enemy archetype header | BASE | 081H |
| 311 | Enemy squad tactics coordinator | BASE | 082 |
| 312 | Squad coordinator header | BASE | 082H |
| 313 | Boss phase state machine framework | BASE | 083 |
| 314 | Boss phase state machine header | BASE | 083H |
| 315 | Party synergy combos | CON2 | 248 |
| 316 | Party synergy combos header | CON2 | 248H |
| 317 | Companion AI tactics presets | CON2 | 256 |
| 318 | Companion AI tactics header | CON2 | 256H |
| 319 | Enemy alert AI state machine | CON2 | 257 |
| 320 | Enemy alert AI header | CON2 | 257H |
| 321 | Aggro range & line-of-sight | CON2 | 258 |
| 322 | Aggro range header | CON2 | 258H |
| 323 | Enemy patrol routes | CON2 | 259 |
| 324 | Enemy patrol routes header | CON2 | 259H |
| 325 | Stealth detection cone | CON2 | 260 |
| 326 | Stealth detection header | CON2 | 260H |
| 327 | Backstab damage multiplier | CON2 | 261 |
| 328 | Backstab damage header | CON2 | 261H |
| 329 | Enemy reinforcements system | CON2 | 262 |
| 330 | Enemy reinforcements header | CON2 | 262H |

### 3.2 Advanced Combat Mechanics (331-360)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 331 | Animation layering/blending system | CON4 | 313 |
| 332 | Animation layering header | CON4 | 313H |
| 333 | Weapon-specific attack animation sets | CON4 | 314 |
| 334 | Weapon animation sets header | CON4 | 314H |
| 335 | Hit-reaction directional animation system | CON4 | 315 |
| 336 | Hit-reaction system header | CON4 | 315H |
| 337 | Weapon trail VFX renderer | CON4 | 316 |
| 338 | Weapon trail renderer header | CON4 | 316H |
| 339 | Combat stance transition system | CON4 | 317 |
| 340 | Combat stance transition header | CON4 | 317H |
| 341 | Animation root motion system | CON4 | 318 |
| 342 | Root motion system header | CON4 | 318H |
| 343 | Screen shake on heavy impacts | CON4 | 319 |
| 344 | Camera shake system header | CON4 | 319H |
| 345 | Slow-motion killing blow camera | CON4 | 320 |
| 346 | Killing blow camera header | CON4 | 320H |
| 347 | Hit-stop/freeze frames on impact | CON4 | 321 |
| 348 | Hit-stop system header | CON4 | 321H |
| 349 | Damage number customization UI | CON4 | 322 |
| 350 | Damage number settings header | CON4 | 322H |
| 351 | Critical hit VFX burst system | CON4 | 323 |
| 352 | Critical hit VFX header | CON4 | 323H |
| 353 | Guard-break & parry counter timing window | CON4 | 324 |
| 354 | Parry counter system header | CON4 | 324H |
| 355 | Controller vibration/rumble system | CON4 | 325 |
| 356 | Controller vibration header | CON4 | 325H |
| 357 | Elemental hit effect sprites | CON4 | 326 |
| 358 | Elemental hit effects header | CON4 | 326H |
| 359 | Chain attack/burst meter system | CON5 | 351 |
| 360 | Chain attack system header | CON5 | 351H |

### 3.3 Combat Polish & Boss Systems (361-400)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 361 | Knockback/launch physics | CON5 | 352 |
| 362 | Knockback physics header | CON5 | 352H |
| 363 | Ambush/surprise encounter system | CON5 | 353 |
| 364 | Ambush encounter header | CON5 | 353H |
| 365 | Combat log/damage breakdown UI | CON5 | 354 |
| 366 | Combat log UI header | CON5 | 354H |
| 367 | Target lock-on system | CON5 | 355 |
| 368 | Target lock-on header | CON5 | 355H |
| 369 | Boss intro cutscene system | CON2 | 263 |
| 370 | Boss intro cutscene header | CON2 | 263H |
| 371 | Boss health bar UI | CON2 | 264 |
| 372 | Boss health bar header | CON2 | 264H |
| 373 | Difficulty scaling options | CON1 | 210 |
| 374 | Difficulty scaling header | CON1 | 210H |
| 375 | Hard mode toggle | CON1 | 211 |
| 376 | Hard mode toggle header | CON1 | 211H |
| 377 | Permadeath mode | CON1 | 212 |
| 378 | Permadeath mode header | CON1 | 212H |
| 379 | Boss rush challenge mode | CON4 | 334 |
| 380 | Boss rush mode header | CON4 | 334H |
| 381 | Battle victory fanfare + pose system | CON4 | 327 |
| 382 | Victory fanfare system header | CON4 | 327H |
| 383 | Boss phase music transition system | CON4 | 328 |
| 384 | Boss phase music header | CON4 | 328H |
| 385 | Character-specific victory poses | CON4 | 331 |
| 386 | Character victory poses header | CON4 | 331H |
| 387 | Summon cinematic camera system | CON4 | 332 |
| 388 | Summon cinematic camera header | CON4 | 332H |
| 389 | Camera/input bugfix sweep | BASE | 057 |
| 390 | UI/HUD polish and bugfix sweep | BASE | 058 |
| 391 | World/runtime stability sweep | BASE | 059 |
| 392 | Audio and final quality sweep | BASE | 060 |
| 393 | Combat bugfix sweep (repeat check) | BASE | 056 |
| 394 | Equipment durability system | CON2 | 270 |
| 395 | Equipment durability header | CON2 | 270H |
| 396 | Weapon sharpening/repair | CON2 | 271 |
| 397 | Weapon repair header | CON2 | 271H |
| 398 | Food buff system | CON2 | 272 |
| 399 | Food buff header | CON2 | 272H |
| 400 | Cooking minigame | CON2 | 273 |

---

## PHASE 4: WORLD CONTENT & ACTIVITIES (Tasks 401-500)

### 4.1 Water & Swimming (401-420)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 401 | Water plane rendering | CON1 | 137 |
| 402 | Water plane header | CON1 | 137H |
| 403 | Water reflection system | CON1 | 138 |
| 404 | Water reflection header | CON1 | 138H |
| 405 | Water caustics (underwater light) | CON1 | 139 |
| 406 | Water caustics header | CON1 | 139H |
| 407 | Underwater fog/visibility | CON1 | 140 |
| 408 | Underwater fog header | CON1 | 140H |
| 409 | Swimming controls | CON1 | 141 |
| 410 | Swimming controls header | CON1 | 141H |
| 411 | Underwater breathing meter | CON1 | 142 |
| 412 | Breathing meter header | CON1 | 142H |
| 413 | Underwater enemies | CON1 | 143 |
| 414 | Underwater enemies header | CON1 | 143H |
| 415 | Underwater treasure chests | CON1 | 144 |
| 416 | Underwater treasure header | CON1 | 144H |
| 417 | Diving animation | CON1 | 145 |
| 418 | Diving animation header | CON1 | 145H |
| 419 | Surface breaking animation | CON1 | 146 |
| 420 | Surface breaking header | CON1 | 146H |

### 4.2 Climbing & Traversal (421-440)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 421 | Climbable surface tagging | CON1 | 147 |
| 422 | Climbable surface header | CON1 | 147H |
| 423 | Climbing animation state machine | CON1 | 148 |
| 424 | Climbing animation header | CON1 | 148H |
| 425 | Stamina depletion while climbing | CON1 | 149 |
| 426 | Climbing stamina header | CON1 | 149H |
| 427 | Ledge grab detection | CON1 | 150 |
| 428 | Ledge grab header | CON1 | 150H |
| 429 | Ledge shimmy movement | CON1 | 151 |
| 430 | Ledge shimmy header | CON1 | 151H |
| 431 | Climb speed variation by surface | CON1 | 152 |
| 432 | Climb speed variation header | CON1 | 152H |
| 433 | Gliding controls | CON1 | 153 |
| 434 | Gliding controls header | CON1 | 153H |
| 435 | Gliding stamina drain | CON1 | 154 |
| 436 | Gliding stamina header | CON1 | 154H |
| 437 | Wind updrafts for gliding | CON1 | 155 |
| 438 | Wind updrafts header | CON1 | 155H |
| 439 | Glide landing animation | CON1 | 156 |
| 440 | Glide landing header | CON1 | 156H |

### 4.3 Minigames & Activities (441-470)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 441 | Fishing minigame | CON1 | 157 |
| 442 | Fishing minigame header | CON1 | 157H |
| 443 | Fish types & rarity | CON1 | 158 |
| 444 | Fish types header | CON1 | 158H |
| 445 | Fishing rod upgrade system | CON1 | 159 |
| 446 | Fishing rod upgrade header | CON1 | 159H |
| 447 | Bait selection system | CON1 | 160 |
| 448 | Bait selection header | CON1 | 160H |
| 449 | Card game minigame system | CON5 | 366 |
| 450 | Card game minigame header | CON5 | 366H |
| 451 | Chocobo/vehicle racing minigame | CON5 | 367 |
| 452 | Chocobo racing minigame header | CON5 | 367H |
| 453 | Shooting gallery minigame | CON5 | 368 |
| 454 | Shooting gallery minigame header | CON5 | 368H |
| 455 | Slot machine/gambling hall minigame | CON5 | 369 |
| 456 | Slot machine minigame header | CON5 | 369H |
| 457 | Monster arena betting system | CON5 | 370 |
| 458 | Monster arena betting header | CON5 | 370H |
| 459 | Photo mode base | CON1 | 171 |
| 460 | Photo mode header | CON1 | 171H |
| 461 | Photo mode filters | CON1 | 172 |
| 462 | Photo mode filters header | CON1 | 172H |
| 463 | Photo mode pose system | CON1 | 173 |
| 464 | Photo mode pose header | CON1 | 173H |
| 465 | Photo mode frame borders | CON1 | 174 |
| 466 | Photo mode frames header | CON1 | 174H |
| 467 | Photo gallery save system | CON1 | 175 |
| 468 | Photo gallery header | CON1 | 175H |
| 469 | Screenshot share integration | CON1 | 176 |
| 470 | Screenshot share header | CON1 | 176H |

### 4.4 Living World Features (471-500)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 471 | Reputation/faction system | CON1 | 195 |
| 472 | Reputation system header | CON1 | 195H |
| 473 | Faction vendor discounts | CON1 | 196 |
| 474 | Faction vendor header | CON1 | 196H |
| 475 | Crime & wanted system | CON1 | 197 |
| 476 | Crime & wanted header | CON1 | 197H |
| 477 | Guard response AI | CON1 | 198 |
| 478 | Guard response header | CON1 | 198H |
| 479 | Bounty payment system | CON1 | 199 |
| 480 | Bounty payment header | CON1 | 199H |
| 481 | Dynamic world events | CON1 | 200 |
| 482 | Dynamic world events header | CON1 | 200H |
| 483 | Monster horde spawns | CON1 | 201 |
| 484 | Monster horde header | CON1 | 201H |
| 485 | Traveling merchant spawns | CON1 | 202 |
| 486 | Traveling merchant header | CON1 | 202H |
| 487 | Camp/outpost system | CON1 | 203 |
| 488 | Camp/outpost header | CON1 | 203H |
| 489 | Campfire crafting stations | CON1 | 204 |
| 490 | Campfire crafting header | CON1 | 204H |
| 491 | Companion banter runtime | CON1 | 205 |
| 492 | Companion banter header | CON1 | 205H |
| 493 | Context-sensitive party dialogue | CON1 | 206 |
| 494 | Context-sensitive dialogue header | CON1 | 206H |
| 495 | Ambient wildlife spawns | CON2 | 274 |
| 496 | Ambient wildlife header | CON2 | 274H |
| 497 | Hunting/gathering system | CON3 | 296 |
| 498 | Hunting/gathering header | CON3 | 296H |
| 499 | Animal behavior AI | CON3 | 297 |
| 500 | Animal behavior header | CON3 | 297H |

---

## PHASE 5: NARRATIVE & CINEMATICS (Tasks 501-550)

### 5.1 Dialogue & Cutscenes (501-530)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 501 | Dialogue tree system | CON2 | 275 |
| 502 | Dialogue tree header | CON2 | 275H |
| 503 | Branching choices tracker | CON2 | 276 |
| 504 | Branching choices header | CON2 | 276H |
| 505 | Cutscene timeline player | CON2 | 277 |
| 506 | Cutscene timeline header | CON2 | 277H |
| 507 | Cutscene camera paths | CON2 | 278 |
| 508 | Cutscene camera header | CON2 | 278H |
| 509 | Subtitle sync system | CON2 | 279 |
| 510 | Subtitle sync header | CON2 | 279H |
| 511 | Voice-over audio playback | CON2 | 280 |
| 512 | Voice-over playback header | CON2 | 280H |
| 513 | Facial animation sync | CON2 | 281 |
| 514 | Facial animation header | CON2 | 281H |
| 515 | Character flashback sequences | CON3 | 298 |
| 516 | Character flashback header | CON3 | 298H |
| 517 | Branching narrative endings | CON3 | 299 |
| 518 | Branching endings header | CON3 | 299H |
| 519 | Ending credits sequence | CON3 | 300 |
| 520 | Ending credits header | CON3 | 300H |
| 521 | In-game cinematic letterbox | CON3 | 301 |
| 522 | Cinematic letterbox header | CON3 | 301H |
| 523 | Skip cutscene prompt | CON3 | 302 |
| 524 | Skip cutscene header | CON3 | 302H |
| 525 | Dialogue history log | CON3 | 303 |
| 526 | Dialogue history header | CON3 | 303H |
| 527 | Codex entry database | CON6 | 379 |
| 528 | Codex entry database header | CON6 | 379H |
| 529 | Journal UI viewer | CON6 | 380 |
| 530 | Journal UI viewer header | CON6 | 380H |

### 5.2 Audio & Music (531-550)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 531 | Victory fanfare trigger | BASE | 047 |
| 532 | Victory fanfare header | BASE | 047H |
| 533 | Environmental ambient audio | BASE | 048 |
| 534 | Environmental audio header | BASE | 048H |
| 535 | Looping BGM | BASE | 049 |
| 536 | Looping BGM header | BASE | 049H |
| 537 | Tactical Pause enter / exit SFX | BASE | 050 |
| 538 | Tactical Pause SFX header | BASE | 050H |
| 539 | Lock-on acquire / break SFX | BASE | 051 |
| 540 | Lock-on SFX header | BASE | 051H |
| 541 | Enemy alert bark stub | BASE | 052 |
| 542 | Enemy alert bark header | BASE | 052H |
| 543 | Music system with dynamic layers | CON2 | 295 |
| 544 | Music system header | CON2 | 295H |
| 545 | Biome-specific ambient audio | CON2 | 296 |
| 546 | Biome ambient audio header | CON2 | 296H |
| 547 | Footstep audio variation by surface | CON2 | 297 |
| 548 | Footstep audio header | CON2 | 297H |
| 549 | Audio occlusion system | CON2 | 298 |
| 550 | Audio occlusion header | CON2 | 298H |

---

## PHASE 6: ACCESSIBILITY & SETTINGS (Tasks 551-600)

### 6.1 Accessibility Features (551-580)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 551 | Colorblind mode presets | CON2 | 282 |
| 552 | Colorblind mode header | CON2 | 282H |
| 553 | Subtitle size options | CON2 | 283 |
| 554 | Subtitle size header | CON2 | 283H |
| 555 | High contrast mode | CON2 | 284 |
| 556 | High contrast header | CON2 | 284H |
| 557 | Text-to-speech for UI | CON2 | 285 |
| 558 | Text-to-speech header | CON2 | 285H |
| 559 | Reduced motion mode | CON2 | 286 |
| 560 | Reduced motion header | CON2 | 286H |
| 561 | Button remapping system | CON2 | 287 |
| 562 | Button remapping header | CON2 | 287H |
| 563 | Auto-aim assist toggle | CON2 | 288 |
| 564 | Auto-aim assist header | CON2 | 288H |
| 565 | Gameplay speed adjustment | CON2 | 289 |
| 566 | Gameplay speed header | CON2 | 289H |
| 567 | Achievement system | CON3 | 304 |
| 568 | Achievement system header | CON3 | 304H |
| 569 | Trophy/achievement notifications | CON3 | 305 |
| 570 | Trophy notifications header | CON3 | 305H |
| 571 | Statistics screen (total kills/distance) | CON3 | 306 |
| 572 | Statistics screen header | CON3 | 306H |
| 573 | Gameplay hints toggle | CON3 | 307 |
| 574 | Gameplay hints header | CON3 | 307H |
| 575 | Objective marker size options | CON3 | 308 |
| 576 | Objective marker size header | CON3 | 308H |
| 577 | Cursor size options | CON3 | 309 |
| 578 | Cursor size header | CON3 | 309H |
| 579 | Loading screen gameplay tips | CON6 | 365 |
| 580 | Loading screen tips header | CON6 | 365H |

### 6.2 Controller & Input (581-600)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 581 | Controller button prompt auto-detect | CON7 | 386 |
| 582 | Controller prompt auto-detect header | CON7 | 386H |
| 583 | Vibration intensity slider | CON3 | 310 |
| 584 | Vibration intensity header | CON3 | 310H |
| 585 | Button hold confirmation toggle | CON3 | 311 |
| 586 | Button hold confirmation header | CON3 | 311H |
| 587 | Double-tap toggle option | CON3 | 312 |
| 588 | Double-tap toggle header | CON3 | 312H |
| 589 | Invert Y-axis option | CON3 | 287 |
| 590 | Invert Y-axis header | CON3 | 287H |
| 591 | Camera sensitivity X/Y separate | CON3 | 288 |
| 592 | Camera sensitivity XY header | CON3 | 288H |
| 593 | Dead zone calibration | CON3 | 289 |
| 594 | Dead zone calibration header | CON3 | 289H |
| 595 | Gyro aiming toggle | CON1 | 213 |
| 596 | Gyro aiming header | CON1 | 213H |
| 597 | Adaptive triggers (DualSense) | CON1 | 214 |
| 598 | Adaptive triggers header | CON1 | 214H |
| 599 | Haptic feedback (DualSense) | CON1 | 214 |
| 600 | Haptic feedback header | CON1 | 214H |

---

## PHASE 7: ENDGAME & REPLAYABILITY (Tasks 601-650)

### 7.1 New Game Plus & Challenges (601-630)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 601 | New Game Plus system | CON1 | 217 |
| 602 | New Game Plus header | CON1 | 217H |
| 603 | NG+ carry-over items | CON1 | 218 |
| 604 | NG+ carry-over header | CON1 | 218H |
| 605 | NG+ increased difficulty | CON1 | 219 |
| 606 | NG+ difficulty header | CON1 | 219H |
| 607 | Endgame trial challenges | CON1 | 220 |
| 608 | Endgame trial header | CON1 | 220H |
| 609 | Time attack mode | CON1 | 221 |
| 610 | Time attack header | CON1 | 221H |
| 611 | Survival arena mode | CON2 | 290 |
| 612 | Survival arena header | CON2 | 290H |
| 613 | Wave-based enemy spawns | CON2 | 291 |
| 614 | Wave-based spawns header | CON2 | 291H |
| 615 | Arena leaderboards (local) | CON2 | 292 |
| 616 | Arena leaderboards header | CON2 | 292H |
| 617 | Superboss encounters | CON2 | 293 |
| 618 | Superboss encounters header | CON2 | 293H |
| 619 | Legendary weapon quests | CON2 | 294 |
| 620 | Legendary weapon header | CON2 | 294H |
| 621 | Completion percentage tracker | CON3 | 304 |
| 622 | Completion tracker header | CON3 | 304H |
| 623 | Bestiary completion | CON3 | 287 |
| 624 | Bestiary completion header | CON3 | 287H |
| 625 | Item collection checklist | CON3 | 288 |
| 626 | Item checklist header | CON3 | 288H |
| 627 | Location discovery checklist | CON3 | 289 |
| 628 | Location checklist header | CON3 | 289H |
| 629 | FF nostalgia Easter eggs | CON1 | 190 |
| 630 | FF Easter eggs header | CON1 | 190H |

### 7.2 FF Tradition & Polish (631-650)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 631 | Moogle save points | CON1 | 191 |
| 632 | Moogle save points header | CON1 | 191H |
| 633 | Cactuar hidden collectibles | CON1 | 192 |
| 634 | Cactuar collectibles header | CON1 | 192H |
| 635 | Tonberry encounters | CON1 | 193 |
| 636 | Tonberry encounters header | CON1 | 193H |
| 637 | Crystal theme world aesthetics | CON1 | 194 |
| 638 | Crystal theme header | CON1 | 194H |
| 639 | Save point crystal pillar VFX | CON4 | 329 |
| 640 | Save point crystal VFX header | CON4 | 329H |
| 641 | Chocobo theme music variants | CON4 | 330 |
| 642 | Chocobo theme variants header | CON4 | 330H |
| 643 | Urban district design (FF7 Midgar) | CON3 | 287 |
| 644 | Urban district header | CON3 | 287H |
| 645 | Industrial zone design (FF7 reactors) | CON3 | 288 |
| 646 | Industrial zone header | CON3 | 288H |
| 647 | Slum/lower city districts | CON3 | 289 |
| 648 | Slum districts header | CON3 | 289H |
| 649 | Upper city/rich districts | CON3 | 290 |
| 650 | Upper city header | CON3 | 290H |

---

## PHASE 8: LOCALIZATION & PLATFORM (Tasks 651-700)

### 8.1 Multi-Language Support (651-670)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 651 | String table localization loader | CON6 | 371 |
| 652 | String table loader header | CON6 | 371H |
| 653 | Unicode font renderer | CON6 | 372 |
| 654 | Unicode font renderer header | CON6 | 372H |
| 655 | Language selector UI | CON6 | 373 |
| 656 | Language selector UI header | CON6 | 373H |
| 657 | Runtime text hot-swap system | CON6 | 374 |
| 658 | Runtime text hot-swap header | CON6 | 374H |
| 659 | Subtitle background opacity | CON3 | 311 |
| 660 | Subtitle background header | CON3 | 311H |
| 661 | Text speed adjustment | CON3 | 312 |
| 662 | Text speed header | CON3 | 312H |
| 663 | Font size options | CON3 | 287 |
| 664 | Font size options header | CON3 | 287H |
| 665 | Character limit per text box | CON3 | 288 |
| 666 | Character limit header | CON3 | 288H |
| 667 | Right-to-left text support | CON3 | 289 |
| 668 | RTL text support header | CON3 | 289H |
| 669 | Japanese vertical text layout | CON3 | 290 |
| 670 | Vertical text layout header | CON3 | 290H |

### 8.2 Content Pipeline & Tools (671-700)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 671 | Build wiring & content pipeline | CON1 | 121 |
| 672 | Build wiring header | CON1 | 121H |
| 673 | Asset import toolchain | CON1 | 122 |
| 674 | Asset import header | CON1 | 122H |
| 675 | Texture compression pipeline | CON1 | 123 |
| 676 | Texture compression header | CON1 | 123H |
| 677 | Audio compression pipeline | CON1 | 124 |
| 678 | Audio compression header | CON1 | 124H |
| 679 | Mesh optimization tool | CON1 | 125 |
| 680 | Mesh optimization header | CON1 | 125H |
| 681 | WorldEditor base framework | CON1 | 207 |
| 682 | WorldEditor base header | CON1 | 207H |
| 683 | Terrain sculpting tools | CON1 | 208 |
| 684 | Terrain sculpting header | CON1 | 208H |
| 685 | Entity placement editor | CON1 | 209 |
| 686 | Entity placement header | CON1 | 209H |
| 687 | Content authoring templates | CON1 | 223 |
| 688 | Authoring templates header | CON1 | 223H |
| 689 | NPC behavior scripting | CON1 | 224 |
| 690 | NPC behavior scripting header | CON1 | 224H |
| 691 | Quest authoring template | CON1 | 225 |
| 692 | Quest authoring header | CON1 | 225H |
| 693 | Dialogue tree editor | CON1 | 226 |
| 694 | Dialogue tree editor header | CON1 | 226H |
| 695 | Encounter design template | CON1 | 227 |
| 696 | Encounter design header | CON1 | 227H |
| 697 | Loot table generator | CON1 | 228 |
| 698 | Loot table generator header | CON1 | 228H |
| 699 | Area transition editor | CON1 | 229 |
| 700 | Area transition header | CON1 | 229H |

---

## PHASE 9: FINAL INTEGRATION & RELEASE (Tasks 701-739)

### 9.1 Release Gates & Final Integration (701-720)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 701 | H01: Plan file maintenance | CON1 | H01 |
| 702 | H02: SYSTEMS.md sync | CON1 | H02 |
| 703 | H03: FULL_TASK_SEQUENCE.md update | CON1 | H03 |
| 704 | H04: Cross-reference verification | CON1 | H04 |
| 705 | H05: Task number collision check | CON1 | H05 |
| 706 | H06: Completion percentage calculation | CON1 | H06 |
| 707 | H07: Release note generation | CON1 | H07 |
| 708 | H08: Plan document consolidation | CON1 | H08 |
| 709 | Task 109: Core combat playable | CON1 | 109 |
| 710 | Task 110: World traversal working | CON1 | 110 |
| 711 | Task 111: Save/load resilient | CON1 | 111 |
| 712 | Task 112: Performance verified GT610 | CON1 | 112 |
| 713 | Task 113: Audio fully integrated | CON1 | 113 |
| 714 | Task 114: UI accessibility complete | CON1 | 114 |
| 715 | Task 115: Content pipeline ready | CON1 | 115 |
| 716 | Task 116: First playable milestone | CON1 | 116 |
| 717 | Task 117: Alpha build gate | CON1 | 117 |
| 718 | Task 118: Beta build gate | CON1 | 118 |
| 719 | Task 119: Release candidate | CON1 | 119 |
| 720 | Task 120: Gold master | CON1 | 120 |

### 9.2 Final Polish & Documentation (721-739)

| Order | Task Name | Plan | Task # |
|-------|-----------|------|--------|
| 721 | Final integration sweep 1 | CON1 | 230 |
| 722 | Final integration sweep 1 header | CON1 | 230H |
| 723 | Final integration sweep 2 | CON1 | 231 |
| 724 | Final integration sweep 2 header | CON1 | 231H |
| 725 | Regression test suite | CON1 | 232 |
| 726 | Regression test header | CON1 | 232H |
| 727 | Performance profiling pass | CON1 | 233 |
| 728 | Performance profiling header | CON1 | 233H |
| 729 | Memory leak detection | CON1 | 234 |
| 730 | Memory leak detection header | CON1 | 234H |
| 731 | Save-backup resilience | CON1 | 235 |
| 732 | Save-backup header | CON1 | 235H |
| 733 | World-building documentation | CON1 | 236 |
| 734 | World-building docs header | CON1 | 236H |
| 735 | Lore consistency guide | CON1 | 237 |
| 736 | Lore consistency header | CON1 | 237H |
| 737 | Character bio reference | CON1 | 238 |
| 738 | Character bio header | CON1 | 238H |
| 739 | Location atlas documentation | CON1 | 239 |

---

## COMPLETION SUMMARY

**Total Tasks: 739**

**By Plan File:**
- BASE: 201 tasks (001-108 + headers)
- CON1: 246 tasks (H01-H08 + 109-246)
- CON2: 90 tasks (247-336 with headers)
- CON3: 52 tasks (287-338 with headers)
- CON4: 44 tasks (313-370 with headers)
- CON5: 72 tasks (335-406 with headers)
- CON6: 14 tasks (371-384 with headers)
- CON7: 20 tasks (383-392 with headers)

**By Phase:**
- Phase 1 (Foundation): 150 tasks
- Phase 2 (World Systems): 150 tasks
- Phase 3 (Combat Depth): 100 tasks
- Phase 4 (World Content): 100 tasks
- Phase 5 (Narrative): 50 tasks
- Phase 6 (Accessibility): 50 tasks
- Phase 7 (Endgame): 50 tasks
- Phase 8 (Localization): 50 tasks
- Phase 9 (Release): 39 tasks

**Execution Strategy:**
1. Start with Phase 1 (Foundation) - core systems must work first
2. Move to Phase 2 (World) - exploration comes after combat basics
3. Complete Phase 3 (Combat Depth) - polish combat before content
4. Build Phase 4 (Content) - activities and minigames
5. Implement Phase 5 (Narrative) - story systems
6. Add Phase 6 (Accessibility) - UX refinement
7. Polish Phase 7 (Endgame) - replayability features
8. Finalize Phase 8 (Localization) - multi-language support
9. Close Phase 9 (Release) - final integration and shipping

**This order ensures dependencies are met and minimizes rework.** 🎮✨
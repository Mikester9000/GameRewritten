# GAME DESIGN BIBLE

Merged reference of core vision docs for easier human reading. Originals are intentionally kept in place.

## Animation Feel
## Core feel goals
- Responsive input-to-action.
- Clear anticipation and readable attack intent.
- Impact weight on hits.
- Dodge that feels decisive and controlled.
## Combat readability goals
- Enemy telegraphs readable before impact.
- Hit reactions communicate outcome clearly.
- Cinematic flavor must not reduce player control clarity.
## Low-fidelity early implementation rule
- Even with primitive visuals:
- keep timing readable
- keep action transitions consistent
- keep hit/dodge feedback unmistakable
## Avoid
- Sluggish attack start without readable intent.
- Overlong lockout states that feel unresponsive.
- Camera/effect noise that hides animation timing.

## Artistic Style
## Visual target
- Stylized realism blend (low-poly clarity + grounded mood).
- FF7/8/10-inspired emotional readability.
- Bold shapes and clear silhouettes over noisy detail.
## Scene readability
- Player, enemies, interactables must separate clearly by value/color/shape.
- Use contrast and composition, not micro-detail density.
## Acceptable visual complexity
- Controlled, deliberate detail near focal points.
- Low-cost materials and straightforward shading.
## Avoid
- Hyper-real texture noise.
- Overly dense scene clutter.
- Effects-heavy visuals that hide gameplay readability.
## Practical style test
A frame is on target if:
- you can identify combat actors instantly,
- region mood is clear,
- visual drama exists without expensive rendering dependence.

## Blockout First Policy
## Core rule
Start systems and content as blockouts first.
## Why
- Proves gameplay and readability quickly.
- Prevents over-polish on unstable design.
- Keeps iteration cheap and reversible.
## What blockout means here
- Simple visuals are acceptable.
- Placeholder assets are acceptable.
- Core feel/readability must already be testable.
## Replace blockouts when
- Core loop behavior is proven.
- Ownership boundaries are stable.
- Performance cost is understood.
## Must be proven before polish
- Control feel
- Combat readability
- Traversal readability
- Content pipeline stability

## Character Visual Style
## Core rules
- Heroic silhouettes, readable at distance.
- Exaggerated but grounded proportions.
- Outfit layers should read as major shape blocks first.
## Weapon/readability rules
- Weapons should read clearly in silhouette.
- Weapon role should be obvious even at medium distance.
## Hair/clothing shape language
- Big primary shapes first, smaller accents second.
- Avoid tiny noisy detail as identity carrier.
## Party visual contrast
- Party members should differ by:
- silhouette
- color family
- motion profile
- weapon profile
## Enemy silhouette distinctness
- Enemy role should be recognizable from shape alone where possible.
## Distance readability
Must remain readable at gameplay camera distance:
- head/torso/weapon direction
- attack wind-up shape
- major status posture changes
## Blockout-first rule
- Start all characters with low-cost blockout.
- Prove gameplay readability first.
- Add polish after controls/combat feel are stable.

## Combat Pillars
See also: [COMBAT_VISION.md](./COMBAT_VISION.md), [PLAYER_FEEL.md](./PLAYER_FEEL.md), [ENEMY_DESIGN.md](./ENEMY_DESIGN.md).
## Pillar 1: Immediate control
- Inputs should translate quickly to action.
- Basic attack/dodge/lock-on must feel reliable.
## Pillar 2: Readable pressure
- Enemy threat is readable.
- Player has clear windows to respond.
## Pillar 3: Spacing and target priority
- Positioning matters.
- Lock-on supports focus decisions without forcing tunnel vision.
## Pillar 4: Strong baseline loop
- Basic attacks + dodge + lock-on + specials should already feel good before complexity.
## Pillar 5: Party-ready future, solo-safe present
- Current implementation can stay solo-first.
- Future party systems must preserve combat readability.
## Implementation guidance
- Keep implementation simple and maintainable.
- Build feel first, then layer depth.

## Design Philosophy
## Core principles
- Readability first.
- Small safe iteration.
- Simple systems before layered complexity.
- Gameplay clarity over mechanical bloat.
- Extensibility without overengineering.
## Milestone behavior
- Every milestone must be playable/testable.
- Prefer vertical slices over broad unfinished scaffolding.
## Feature creep control
- Add only what supports current milestone goals.
- Defer future systems intentionally (see `DO_NOT_BUILD_YET.md`).
## Fun and feel over cleverness
- If a simpler design feels better in play, choose it.
- If a complex design adds little practical gain, defer it.
## Practical decision rule
- Ask: “Does this improve player feel and team clarity now?”
- If no, reduce scope.

## Enemy Design
## Enemy purpose
- Create readable pressure and tactical decisions.
- Encourage movement, spacing, and timing.
## Readability rules
- Telegraph attacks clearly.
- Distinct enemy role silhouette/behavior.
- Keep active enemy count readable in scene.
## Role types (simple first)
- Chaser/melee pressure
- Ranged harassment (future)
- Heavy/elite timing checks (future)
## Pattern complexity
- Start with simple, legible patterns.
- Add depth only after baseline fun is proven.
## Fun over annoyance
- Avoid unfair tracking/spam behavior.
- Give consistent punish/read windows.
## Low-enemy-count readability
- Prefer fewer clearer enemies over many noisy enemies.

## Environment Visual Style
## Place feel goals
- **Towns:** readable hubs, warm identity, clear navigation.
- **Fields:** breathable traversal spaces with route cues.
- **Ruins:** mystery/history anchors, strong landmark value.
- **Roads/paths:** reinforce travel direction and story pacing.
## Biome readability
- Each region needs clear color/value silhouette identity.
- Transitions should feel intentional, not random noise.
## Traversal readability
- Landmarks should guide movement naturally.
- Route choices should be visible and meaningful.
## Mood variation by region
- Regions should differ in tone and atmosphere.
- Keep a cohesive world language across all regions.
## Simplicity vs grandeur
- Use composition scale and landmark placement for grandeur.
- Do not depend on heavy rendering complexity.
## Avoid clutter
- Avoid dense prop spam that harms navigation readability.
- Avoid large empty spaces with no purpose or identity.

## Exploration Design
## Exploration philosophy
- Fully explorable world with meaningful route identity.
- Discovery should produce wonder and anticipation.
## Landmark-first navigation
- Use strong landmarks as navigation memory anchors.
- Avoid relying only on minimap awareness.
## Region-to-field coherence
- Regions should connect logically via roads/terrain/story cues.
- Fields should feel like intentional travel spaces.
## Rewarding discovery
- Discovery should expose:
- lore hints
- gameplay opportunities
- visual mood shifts
- Avoid giant spaces with little purpose.
## Open-world spirit, simpler execution
- Keep FF15-style journey spirit.
- Implement with readable, low-spec-safe structure.

## Final Fantasy Feel
## Emotional tone
- Sincere, dramatic, hopeful.
- Wonder + melancholy + momentum.
- Serious stakes without becoming grimdark.
## World tone
- Memorable places with identity.
- Mix of intimacy (small character moments) and spectacle (big vistas/events).
## Sense of journey
- Travel should feel like progress between meaningful regions.
- Landmarks and routes should create anticipation.
## Party/adventure feeling
- Even in solo-first implementation, world and systems should leave room for party energy.
- Future party direction must preserve readability and role clarity.
## Stylization balance
- Readable, iconic, dramatic.
- Avoid generic realism and avoid cartoon parody extremes.
## Spectacle vs intimacy
- Use spectacle as punctuation, not constant noise.
- Keep moment-to-moment control clarity first.
## Presentation rule
- Dramatic but readable in combat, UI, and scene composition.
## “FF energy” without copying
- Capture mood, cadence, silhouette, and emotional sincerity.
- Do not copy names, exact characters, or direct scene recreations.
## Avoid so it does not feel generic
- Bland biome design.
- UI clutter.
- Combat effects that obscure decisions.
- Contentless large spaces.

## Lighting and Color
## Mood-first lighting
- Lighting should support emotional tone before technical complexity.
- Keep scenes readable in motion and combat.
## Gameplay readability lighting
- Preserve clear value separation for player/enemy/environment.
- Avoid low-contrast muddy frames.
## Region color identity
- Give each region a dominant mood palette.
- Maintain shared world palette discipline.
## Time-of-day mood goals
- Distinct mood states (day/evening/night-like) with simple safe transitions.
- Keep gameplay readability stable in all states.
## Low-spec-friendly lighting rules
- Prefer single directional + ambient baseline.
- Keep dynamic lights minimal.
- Avoid heavy shadowing systems by default.
## Post-effects limits
- Use little to no full-screen effects on Low.
- Any post effect must have cheap fallback/off switch.
## Avoid
- Excessive bloom, blur, or grading that reduces clarity.
- Color palettes that collapse actor/background contrast.

## Party System Direction
## Current practicality
- Solo-first implementation is correct right now.
- Party complexity is deferred until core combat is stable.
## Future direction
- Add party roles with clear readability.
- Preserve active combat clarity during party interactions.
## Possible future mechanics
- Controlled character switch
- Support commands
- Lightweight synergy windows
## Hard requirement
- Any party system must remain understandable in motion.
- No unreadable command overload.
## Defer until
- Core combat loop is consistently fun and stable.
- Enemy readability and camera behavior are solid.

## Player Feel
## Movement feel
- Agile, readable, controllable.
- Acceleration/deceleration should support quick decisions.
## Camera relationship
- Camera should support movement and target readability.
- Lock-on adjustments should aid framing, not fight input.
## Dodge feel
- Fast, confident repositioning.
- Clear start and recovery timing.
- Never vague whether dodge triggered.
## Target switching feel
- Predictable and low-friction.
- No confusing target jumps.
## Attack responsiveness
- Attacks should feel immediate and intentional.
- Hit feedback should confirm outcome clearly.
## Must never feel
- Sluggish controls.
- Ambiguous lock-on target state.
- Confusing camera behavior in active combat.

## Progression Philosophy
## Combat growth
- Growth should improve expression and readability.
- New options should be understandable in live combat.
## Upgrade direction
- Prioritize clear, testable upgrades over layered complexity.
- Keep early progression lightweight and practical.
## Equipment/materia/ability inspiration
- Inspired by FF-style expression systems, but adapt simply.
- Introduce in stages, not all at once.
## Anti-bloat rule
- Do not stack multiple progression systems before baseline combat clarity is stable.
## Core test
A progression addition is good if it:
- expands player choice,
- keeps combat readable,
- does not force heavy architecture early.

## Quest and Event Philosophy
## Story events
- Focus on authored moments with clear emotional tone.
- Keep event presentation readable and paced.
## Optional content
- Side content should deepen world identity, not checklist noise.
## Quest structure strategy
- Start with simple robust structures.
- Expand branching/complexity later.
## Avoid checklist bloat
- Avoid generic repetitive objective spam.
- Prefer fewer meaningful tasks.
## Interaction quality
- Interactions should feel authored and place-aware.
- Tie quest beats to region identity and traversal context.
## Narrative pacing
- Alternate intensity and breathing room.
- Preserve journey rhythm.

## Region Identity Guide
## Each region must define
- **Biome identity:** dominant terrain/vegetation language.
- **Culture/tone:** settlement vibe, social feel, music mood direction.
- **Visual memory hooks:** one or two iconic landmarks.
- **Traversal identity:** how movement feels there.
- **Gameplay identity:** encounter/exploration flavor.
## Distinctness rules
- Players should recognize region from silhouette + palette quickly.
- Avoid “same region, different tint” design.
## Practical checklist per region
- [ ] Landmark that orients player.
- [ ] Readable route logic.
- [ ] Distinct mood profile.
- [ ] At least one authored discovery point.

## Story Tone
## Emotional blend
- Serious stakes with stylized charm.
- Wonder, melancholy, hope, and mystery.
## Not this
- Not pure grimdark.
- Not parody/comedy-first tone.
## Journey tone
- Epic travel arc with intimate character stakes.
- Personal moments should matter as much as big events.
## Dialogue/world voice
- Plain, sincere, intentional.
- Avoid generic fantasy exposition walls.

## World Lore Direction
## Core lore feel
- Ancient mystery under the present world.
- History visible through ruins, relics, and region identity.
## Modern/fantasy blend
- Allow selective tech/fantasy coexistence where it supports tone.
- Keep style coherent and region-aware.
## Technology vs nature
- Tension between systems and landscape should shape atmosphere.
- Use this to support exploration mood.
## Lore supports exploration
- Lore should reward movement and observation.
- Place clues in world structure, not only dialogue.
## Avoid
- Generic lore dumps with weak place identity.
- Exposition disconnected from traversal or gameplay context.

## World Structure
## Core relationship
- Overworld concept → regions → fields → towns/dungeons.
- Each layer should have clear identity and gameplay purpose.
## Region identity
- Every region needs:
- visual signature
- traversal style
- mood/story role
## Travel feel
- Travel should feel like progression, not filler distance.
- Routes should build anticipation toward landmarks and settlements.
## Content density rule
- “Fully explorable” means meaningful traversal space, not infinite empty area.
- Density should vary deliberately: hubs dense, roads readable, wilds purposeful.
## How to avoid overbuilding early
- Prove one strong region loop first.
- Expand breadth only after local quality is stable.

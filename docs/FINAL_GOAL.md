# Final Goal (Target Direction)

## What this game is becoming
- A stylized action RPG with:
  - emotional and visual memory of FF7/8/10
  - active readable combat closer to FF7 Remake feel
  - broad explorable world spirit inspired by FF15
- Not a direct clone of any one game.

## Final player experience target
- Journey feels large and memorable.
- Combat feels immediate, dramatic, readable.
- World invites travel, discovery, and return.
- UI feels elegant and clear under pressure.

## Desired engine structure
- Modular and beginner-readable.
- Strong ownership boundaries (`app/game/world/rendering/ui/assets`).
- Data-driven content flow (prefabs/registry/world cells).
- Safe to extend without rewriting core systems.

## “Done enough to feel real”
- Stable playable loop from exploration → encounter → outcome.
- Distinct regions with memorable landmarks and mood shifts.
- Consistent combat readability and feedback.
- Core content pipeline usable by non-expert contributors.

## Prioritize over flashy tech
- Readability, responsiveness, maintainability.
- Performance consistency on low-spec target hardware.
- Small testable milestones.

## What should never dominate this project
- Hyper-realism race.
- Overengineered architecture before gameplay proof.
- Massive systems added before core loops are solid.

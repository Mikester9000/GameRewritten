# UI Vision Guide
**Date:** 2026-05-11

---

## Core UI Direction

The UI should blend two complementary styles:

1. **Modern action-RPG HUD design** for real-time gameplay
2. **Classic Final Fantasy-style window design** for slower interaction screens

The goal is to support a **modern action gameplay loop** while preserving the charm and readability of **older JRPG menu presentation**.

This means:

- **Combat / gameplay UI** should feel closer to **FF15 / FF7 Remake**
- **Menus / dialog / management UI** should feel closer to **FF7 / FF8 / PS1-era Final Fantasy**
- Both styles must still feel like they belong to the same game through shared colors, typography, spacing, and visual identity

---

## Primary Rule

Use the UI style that matches the speed of the interaction:

- **If the player must react quickly**, use a **modern minimal action UI**
- **If the player is reading, choosing, or managing**, use a **classic framed RPG window UI**

---

## Style Family A — Modern Action UI

This style is for all **fast-response gameplay elements**.

### Use for:
- Gameplay HUD
- HP / MP / ATB bars
- Lock-on indicators
- Enemy target info
- Dodge / cooldown indicators
- Interaction prompts
- Minimap
- Objective reminders
- Combat notifications

### Visual goals:
- Low clutter
- Fast readability
- Semi-transparent panels
- Thin framing or no heavy frame at all
- Screen-edge anchored layout
- Minimal decoration
- Strong contrast
- Small but readable labels
- Clean bars and icons

### Inspiration:
- FF15
- FF7 Remake
- Kingdom Hearts
- Modern action JRPG combat HUDs

### Design notes:
- The player should be able to read this UI in less than 1 second
- It should never block the center of the action unless necessary
- Important combat states should be readable at a glance
- Panels should feel integrated into gameplay, not like large menu boxes

---

## Style Family B — Classic RPG Window UI

This style is for all **slower interaction and menu-heavy screens**.

### Use for:
- Dialog windows
- Pause menu
- Inventory
- Quest log
- Save / load
- Shop menus
- NPC interaction choices
- Party / status screens
- System menus

### Visual goals:
- Framed window presentation
- More decorative than gameplay HUD
- Comfortable to read
- Strong panel identity
- Slightly nostalgic JRPG feel
- Clear section grouping
- Better use of headers, inner panels, and menu lists

### Inspiration:
- FF7
- FF8
- PS1 / PS2-era Final Fantasy menus
- Classic JRPG dialog and menu windows

### Design notes:
- These screens can use larger panels and more visible framing
- Decorative window styling is welcome here
- Text readability and layout comfort matter more than minimalism
- This UI should feel iconic and deliberate, not like a debug tool

---

## Shared Identity Rules

Even though the UI has two style families, everything must still feel like one game.

Keep these shared elements consistent:

- Same font family
- Same text sizing hierarchy
- Same accent color family
- Same border language
- Same spacing / padding rules
- Same icon style
- Same overall color mood

The difference between UI families should be **functional**, not disconnected.

---

## Color Direction

Use a shared palette family with two applications:

### Combat / gameplay UI palette
- Dark charcoal / black translucent backgrounds
- Blue / teal / cyan accents
- White primary text
- Yellow for ATB / readiness / highlight states
- Red for damage / danger / low HP
- Green only for specific positive indicators

### Menu / dialog UI palette
- Deep blue / teal / indigo panel backgrounds
- Subtle gradient fills
- White body text
- Gold / pale yellow header and selection accents
- Muted border highlights
- Slightly richer saturation than gameplay HUD

### General palette rule
Avoid overly bright neon colors.
The UI should feel:
- readable
- slightly dramatic
- elegant
- game-like, not app-like

---

## Typography Goals

Typography should feel:
- clean
- readable
- slightly stylized if possible
- not futuristic sci-fi
- not overly ornate

### Rules:
- Primary text must always be clear at gameplay distance
- Headers should be slightly brighter or more accented than body text
- Menu options should have strong selection readability
- Dialog text should prioritize comfort and readability
- Avoid tiny font sizes except in debug-only overlays

---

## Panel / Window Rules

### Gameplay panels
- Light background opacity
- Thin borders or subtle edge treatment
- Small corner radius only if it matches the game
- Compact layout
- Avoid heavy gradients unless very subtle

### Menu/dialog windows
- Stronger panel framing
- Optional gradient fill
- Decorative border treatment allowed
- Slightly thicker edge treatment
- More generous internal padding
- Can use nested panels/sub-sections

---

## Layout Philosophy

### Combat UI
- Prefer corners and edges of the screen
- Avoid covering the center
- Keep target information near top-center or near target
- Keep player status in stable screen locations
- Keep prompts short and unobtrusive

### Menu/dialog UI
- Larger dedicated windows are acceptable
- Centered and bottom-anchored windows are both valid depending on context
- Group related information cleanly
- Use visual hierarchy clearly

---

## Interaction Readability Rules

### Combat
The player must instantly understand:
- health state
- ATB / action readiness
- current target
- whether an interaction is possible
- major combat feedback

### Menu/dialog
The player must instantly understand:
- what window they are in
- which option is selected
- what text is important
- how to proceed / confirm / cancel

---

## ImGui Implementation Guidance

The current UI implementation uses ImGui and should remain lightweight.

### Recommended approach:
- Keep ImGui as the base UI system
- Build reusable helper functions for custom panel drawing
- Use `ImGui::GetWindowDrawList()` for:
  - panel backgrounds
  - gradient fills
  - border decoration
  - title strips
  - selection highlights

### Do not do:
- full UI framework rewrite
- overengineered theme system too early
- excessive texture-heavy menu skinning
- unnecessary retained-mode custom UI system

### Prefer:
- simple reusable helper functions
- modular style application
- low-risk visual improvements
- consistent screen-by-screen upgrades

---

## Immediate UI Priorities

### Near-term goals
1. Keep current gameplay HUD functional and readable
2. Improve dialog box presentation to feel more classic JRPG
3. Improve pause/options menu presentation to feel less debug-like
4. Add cleaner combat target UI as lock-on/combat evolves
5. Keep debug UI separate from player-facing UI styling

### Recommended order
1. Define shared color/style rules
2. Build reusable panel helpers
3. Restyle dialog box
4. Restyle pause/options menu
5. Upgrade combat HUD styling
6. Extend style to future inventory/quest/save screens

---

## Long-Term UI Goal

The final UI should feel like:

- a **modern action RPG interface during gameplay**
- a **classic Final Fantasy-inspired interface during reading and menu navigation**
- one consistent visual identity overall

The UI should support:
- fast action combat readability
- nostalgic JRPG menu comfort
- low-spec rendering constraints
- simple implementation and iteration inside the current codebase

---

## Summary Statement

**Use modern low-clutter action UI for real-time gameplay, and classic Final Fantasy-style framed windows for dialog, menus, and management screens.**

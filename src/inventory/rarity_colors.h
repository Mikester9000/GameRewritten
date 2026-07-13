// ============================================================
// FILE: src/inventory/rarity_colors.h
// SYSTEM: Inventory
// ROLE: canonical RGBA colors for item rarity tiers
// DO NOT: store item data here; this is purely a color lookup.
// OWNS: ItemRarity enum and RgbaColor struct + mapping.
// ============================================================
//
// [LEGO BLOCK: ITEM RARITY COLORS]
// -----------------------------------------------------------------
// What it does: maps ItemRarity enum values to RGBA colors so that
//   all UI code uses consistent FF-style item tier coloring.
//   Common = grey, Uncommon = green, Rare = blue,
//   Epic = purple, Legendary = orange.
//
// EXTEND: add new rarity tiers by appending to the ItemRarity enum
//   and adding a matching case in GetColor() in the .cpp.
//
// EXAMPLE — color an inventory slot tooltip:
//   #include "inventory/rarity_colors.h"
//   gr::RgbaColor c = gr::ItemRarityColors::GetColor(gr::ItemRarity::Legendary);
//   ImGui::TextColored({ c.r, c.g, c.b, c.a }, "Excalibur");
// -----------------------------------------------------------------

#pragma once

namespace gr
{
enum class ItemRarity
{
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

struct RgbaColor
{
    float r = 1.0f;
    float g = 1.0f;
    float b = 1.0f;
    float a = 1.0f;
};

class ItemRarityColors
{
public:
    static RgbaColor GetColor(ItemRarity rarity);
};
} // namespace gr

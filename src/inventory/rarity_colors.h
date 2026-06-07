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

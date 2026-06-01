#include "rarity_colors.h"

namespace gr
{
RgbaColor ItemRarityColors::GetColor(ItemRarity rarity)
{
    switch (rarity)
    {
    case ItemRarity::Common: return { 0.82f, 0.82f, 0.82f, 1.0f };
    case ItemRarity::Uncommon: return { 0.30f, 0.90f, 0.30f, 1.0f };
    case ItemRarity::Rare: return { 0.35f, 0.60f, 1.0f, 1.0f };
    case ItemRarity::Epic: return { 0.80f, 0.40f, 1.0f, 1.0f };
    case ItemRarity::Legendary: return { 1.0f, 0.70f, 0.20f, 1.0f };
    }
    return { 1.0f, 1.0f, 1.0f, 1.0f };
}
} // namespace gr

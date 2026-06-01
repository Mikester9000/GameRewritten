#include "sorting_filtering.h"

#include <algorithm>

namespace gr
{
std::vector<InventoryItemStack> InventorySortingFiltering::FilterByCategory(const std::vector<InventoryItemStack>& stacks,
                                                                            const std::string& category) const
{
    if (category.empty())
    {
        return stacks;
    }

    std::vector<InventoryItemStack> filtered;
    for (const InventoryItemStack& stack : stacks)
    {
        if (stack.category == category)
        {
            filtered.push_back(stack);
        }
    }
    return filtered;
}

void InventorySortingFiltering::Sort(std::vector<InventoryItemStack>& stacks, InventorySortMode mode, bool ascending) const
{
    auto keyLess = [mode](const InventoryItemStack& a, const InventoryItemStack& b)
    {
        switch (mode)
        {
        case InventorySortMode::Name: return a.itemId < b.itemId;
        case InventorySortMode::Category: return a.category < b.category;
        case InventorySortMode::Quantity: return a.quantity < b.quantity;
        }
        return false;
    };

    if (ascending)
    {
        std::stable_sort(stacks.begin(), stacks.end(), keyLess);
    }
    else
    {
        std::stable_sort(stacks.begin(), stacks.end(), [keyLess](const InventoryItemStack& a, const InventoryItemStack& b)
        {
            return keyLess(b, a);
        });
    }
}
} // namespace gr

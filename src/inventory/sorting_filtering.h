#pragma once

#include "inventory_system.h"

#include <string>
#include <vector>

namespace gr
{
enum class InventorySortMode
{
    Name,
    Category,
    Quantity
};

class InventorySortingFiltering
{
public:
    std::vector<InventoryItemStack> FilterByCategory(const std::vector<InventoryItemStack>& stacks,
                                                     const std::string& category) const;
    void Sort(std::vector<InventoryItemStack>& stacks, InventorySortMode mode, bool ascending) const;
};
} // namespace gr

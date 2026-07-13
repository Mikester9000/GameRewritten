// ============================================================
// FILE: src/inventory/sorting_filtering.h
// SYSTEM: Inventory
// ROLE: sorting and category-filtering for inventory views
// DO NOT: mutate item data here; always operate on copies.
// OWNS: sort/filter logic; InventoryItemStack defined in inventory_system.h.
// ============================================================
//
// [LEGO BLOCK: INVENTORY SORTING & FILTERING]
// -----------------------------------------------------------------
// What it does: provides stateless helpers to filter a stack list
//   by category string, and to sort it by name, category, or quantity.
//
// EXTEND: add a SortByRarity mode by including rarity_colors.h and
//   comparing ItemRarity values stored in InventoryItemStack.
//
// EXAMPLE — show filtered weapon tab in UI:
//   #include "inventory/sorting_filtering.h"
//   gr::InventorySortingFiltering m_sorter;
//   auto weapons = m_sorter.FilterByCategory(m_inventory.GetStacks(), "weapon");
//   m_sorter.Sort(weapons, gr::InventorySortMode::Name, true);
// -----------------------------------------------------------------

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

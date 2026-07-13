// ============================================================
// FILE: src/inventory/inventory_system.h
// SYSTEM: Inventory
// ROLE: stackable item storage with capacity limits
// DO NOT: hold item definitions or stats here; use AssetRegistry.
// OWNS: item stack list and slot-count tracking.
// ============================================================
//
// [LEGO BLOCK: INVENTORY SYSTEM]
// -----------------------------------------------------------------
// What it does: manages a list of InventoryItemStack entries.
//   Automatically merges stacks up to maxStack before creating
//   a new slot, and refuses adds when at capacity.
//
// EXTEND: add a "hotbar" subset view, item locking, or favourite
//   flagging by adding a field to InventoryItemStack.
//
// EXAMPLE — pick up a dropped item:
//   #include "inventory/inventory_system.h"
//   gr::InventorySystem m_inventory;
//   m_inventory.SetCapacity(80);
//   bool added = m_inventory.AddItem("health_herb", "consumable", 3);
//   int count = m_inventory.CountItem("health_herb"); // 3
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <vector>

namespace gr
{
struct InventoryItemStack
{
    std::string itemId;
    std::string category;
    int quantity = 0;
    int maxStack = 99;
};

class InventorySystem
{
public:
    void SetCapacity(int slots);
    int GetCapacity() const { return m_capacity; }
    bool AddItem(const std::string& itemId, const std::string& category, int quantity, int maxStack = 99);
    bool RemoveItem(const std::string& itemId, int quantity);
    int CountItem(const std::string& itemId) const;
    int UsedSlots() const { return static_cast<int>(m_stacks.size()); }
    const std::vector<InventoryItemStack>& GetStacks() const { return m_stacks; }

private:
    int FindStack(const std::string& itemId, int maxStack) const;

    int m_capacity = 120;
    std::vector<InventoryItemStack> m_stacks;
};
} // namespace gr

#pragma once
// Inventory.hpp
// A flat item bag with stack-based add/remove and quantity queries.
// Shared by the player and chest/loot drop flows.

#include <string>
#include <vector>

struct ItemStack
{
    std::string name;
    int         quantity = 0;
};

class Inventory
{
public:
    static constexpr int kMaxSlots = 64;

    // Add qty of itemName.  Returns false if the bag is full (no existing stack).
    bool Add(const std::string& itemName, int qty = 1);

    // Remove qty of itemName.  Returns false if insufficient quantity.
    bool Remove(const std::string& itemName, int qty = 1);

    // Returns the current quantity of itemName (0 if not present).
    int  Count(const std::string& itemName) const;

    bool IsEmpty() const { return m_items.empty(); }
    void Clear()         { m_items.clear(); }

    const std::vector<ItemStack>& GetItems() const { return m_items; }

private:
    std::vector<ItemStack> m_items;

    ItemStack* FindStack(const std::string& name);
};

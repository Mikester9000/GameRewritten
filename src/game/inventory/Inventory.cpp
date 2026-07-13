// Inventory.cpp
// Stack-based flat item bag.

#include "Inventory.hpp"

#include <algorithm>

ItemStack* Inventory::FindStack(const std::string& name)
{
    for (ItemStack& s : m_items)
        if (s.name == name) return &s;
    return nullptr;
}

bool Inventory::Add(const std::string& itemName, int qty)
{
    ItemStack* existing = FindStack(itemName);
    if (existing)
    {
        existing->quantity += qty;
        return true;
    }

    if (static_cast<int>(m_items.size()) >= kMaxSlots)
        return false; // bag full

    m_items.push_back({ itemName, qty });
    return true;
}

bool Inventory::Remove(const std::string& itemName, int qty)
{
    ItemStack* s = FindStack(itemName);
    if (!s || s->quantity < qty) return false;

    s->quantity -= qty;
    if (s->quantity <= 0)
        m_items.erase(std::remove_if(m_items.begin(), m_items.end(),
                      [&](const ItemStack& x){ return x.name == itemName; }),
                      m_items.end());
    return true;
}

int Inventory::Count(const std::string& itemName) const
{
    for (const ItemStack& s : m_items)
        if (s.name == itemName) return s.quantity;
    return 0;
}

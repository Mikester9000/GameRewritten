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

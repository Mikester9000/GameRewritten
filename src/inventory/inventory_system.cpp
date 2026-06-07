#include "inventory_system.h"

#include <algorithm>

namespace gr
{
void InventorySystem::SetCapacity(int slots)
{
    m_capacity = std::max(slots, 1);
}

int InventorySystem::FindStack(const std::string& itemId, int maxStack) const
{
    for (std::size_t i = 0; i < m_stacks.size(); ++i)
    {
        const InventoryItemStack& stack = m_stacks[i];
        if (stack.itemId == itemId && stack.maxStack == maxStack && stack.quantity < stack.maxStack)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool InventorySystem::AddItem(const std::string& itemId, const std::string& category, int quantity, int maxStack)
{
    if (itemId.empty() || quantity <= 0 || maxStack <= 0)
    {
        return false;
    }

    int remaining = quantity;
    while (remaining > 0)
    {
        const int stackIndex = FindStack(itemId, maxStack);
        if (stackIndex >= 0)
        {
            InventoryItemStack& stack = m_stacks[stackIndex];
            const int canAdd = std::min(remaining, stack.maxStack - stack.quantity);
            stack.quantity += canAdd;
            remaining -= canAdd;
            continue;
        }

        if (UsedSlots() >= m_capacity)
        {
            return false;
        }

        const int addCount = std::min(remaining, maxStack);
        m_stacks.push_back({ itemId, category, addCount, maxStack });
        remaining -= addCount;
    }

    return true;
}

bool InventorySystem::RemoveItem(const std::string& itemId, int quantity)
{
    if (itemId.empty() || quantity <= 0)
    {
        return false;
    }

    int remaining = quantity;
    for (InventoryItemStack& stack : m_stacks)
    {
        if (stack.itemId != itemId || remaining <= 0)
        {
            continue;
        }
        const int removed = std::min(stack.quantity, remaining);
        stack.quantity -= removed;
        remaining -= removed;
    }

    m_stacks.erase(std::remove_if(m_stacks.begin(), m_stacks.end(), [](const InventoryItemStack& stack)
    {
        return stack.quantity <= 0;
    }), m_stacks.end());

    return remaining == 0;
}

int InventorySystem::CountItem(const std::string& itemId) const
{
    int total = 0;
    for (const InventoryItemStack& stack : m_stacks)
    {
        if (stack.itemId == itemId)
        {
            total += stack.quantity;
        }
    }
    return total;
}
} // namespace gr

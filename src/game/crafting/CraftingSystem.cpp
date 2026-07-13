// CraftingSystem.cpp
// Recipe crafting: ingredient check + consume + produce.

#include "CraftingSystem.hpp"
#include "../inventory/Inventory.hpp"

int CraftingSystem::AddRecipe(const std::string& resultItem, int qty,
                              const std::vector<CraftingIngredient>& ingredients)
{
    CraftingRecipe r;
    r.id             = m_nextId++;
    r.resultItem     = resultItem;
    r.resultQuantity = qty;
    r.ingredients    = ingredients;
    m_recipes.push_back(r);
    return r.id;
}

bool CraftingSystem::HasIngredients(const CraftingRecipe& r, const Inventory& inv) const
{
    for (const auto& ing : r.ingredients)
        if (inv.Count(ing.itemName) < ing.quantity) return false;
    return true;
}

bool CraftingSystem::Craft(int recipeId, Inventory& inventory)
{
    for (const CraftingRecipe& r : m_recipes)
    {
        if (r.id != recipeId) continue;
        if (!HasIngredients(r, inventory)) return false;

        for (const auto& ing : r.ingredients)
            inventory.Remove(ing.itemName, ing.quantity);
        inventory.Add(r.resultItem, r.resultQuantity);
        return true;
    }
    return false;
}

std::vector<const CraftingRecipe*> CraftingSystem::GetAvailable(const Inventory& inventory) const
{
    std::vector<const CraftingRecipe*> out;
    for (const CraftingRecipe& r : m_recipes)
        if (HasIngredients(r, inventory)) out.push_back(&r);
    return out;
}

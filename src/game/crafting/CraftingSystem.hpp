#pragma once
// CraftingSystem.hpp
// Recipe-based crafting: combine inventory items to produce new items.
// Recipes are registered at startup; the player crafts at rest points or
// upgrade stations.

#include <string>
#include <vector>

struct CraftingIngredient
{
    std::string itemName;
    int         quantity = 1;
};

struct CraftingRecipe
{
    int                           id = 0;
    std::string                   resultItem;
    int                           resultQuantity = 1;
    std::vector<CraftingIngredient> ingredients;
};

class Inventory; // forward

class CraftingSystem
{
public:
    // Register a recipe; returns its id.
    int  AddRecipe(const std::string& resultItem, int qty,
                   const std::vector<CraftingIngredient>& ingredients);

    // Attempt to craft recipe with id, consuming items from inventory.
    // Returns false if materials are missing.
    bool Craft(int recipeId, Inventory& inventory);

    // Returns all recipes whose ingredients are fully available.
    std::vector<const CraftingRecipe*> GetAvailable(const Inventory& inventory) const;

    const std::vector<CraftingRecipe>& GetAll() const { return m_recipes; }

private:
    std::vector<CraftingRecipe> m_recipes;
    int                         m_nextId = 1;

    bool HasIngredients(const CraftingRecipe& r, const Inventory& inv) const;
};

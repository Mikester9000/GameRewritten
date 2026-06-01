#include "status_effect_crafting.h"

namespace gr
{
void StatusEffectCrafting::SetRecipes(const std::vector<StatusRecipe>& recipes)
{
    m_recipes.clear();
    for (const StatusRecipe& recipe : recipes)
    {
        if (!recipe.recipeId.empty())
        {
            m_recipes[recipe.recipeId] = recipe;
        }
    }
}

bool StatusEffectCrafting::CanCraft(const std::string& recipeId, const std::unordered_map<std::string, int>& inventory) const
{
    const auto it = m_recipes.find(recipeId);
    if (it == m_recipes.end())
    {
        return false;
    }

    for (const std::string& ingredient : it->second.ingredientIds)
    {
        auto invIt = inventory.find(ingredient);
        if (invIt == inventory.end() || invIt->second <= 0)
        {
            return false;
        }
    }
    return true;
}

std::string StatusEffectCrafting::Craft(const std::string& recipeId, std::unordered_map<std::string, int>& inventory) const
{
    if (!CanCraft(recipeId, inventory))
    {
        return {};
    }

    const StatusRecipe& recipe = m_recipes.at(recipeId);
    for (const std::string& ingredient : recipe.ingredientIds)
    {
        --inventory[ingredient];
    }
    return recipe.statusEffectId;
}
} // namespace gr

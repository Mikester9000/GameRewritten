#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace gr
{
struct StatusRecipe
{
    std::string recipeId;
    std::vector<std::string> ingredientIds;
    std::string statusEffectId;
};

class StatusEffectCrafting
{
public:
    void SetRecipes(const std::vector<StatusRecipe>& recipes);
    bool CanCraft(const std::string& recipeId, const std::unordered_map<std::string, int>& inventory) const;
    std::string Craft(const std::string& recipeId, std::unordered_map<std::string, int>& inventory) const;

private:
    std::unordered_map<std::string, StatusRecipe> m_recipes;
};
} // namespace gr

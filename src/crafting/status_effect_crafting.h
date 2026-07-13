// ============================================================
// FILE: src/crafting/status_effect_crafting.h
// SYSTEM: Crafting
// ROLE: recipe definitions and crafting logic for status-effect items
// DO NOT: apply status effects here; return the result ID and let
//         the StatusAilmentSystem handle application.
// OWNS: recipe table and ingredient-consumption logic.
// ============================================================
//
// [LEGO BLOCK: STATUS EFFECT CRAFTING]
// -----------------------------------------------------------------
// What it does: holds a map of StatusRecipe definitions and lets
//   you query CanCraft() before consuming ingredients with Craft().
//
// EXTEND: add new recipes by loading them from JSON and calling
//   SetRecipes() — no code changes needed here.
//   To add a new recipe type (passive buff, area effect, etc.)
//   add a new field to StatusRecipe and handle it in the caller.
//
// EXAMPLE — craft from a crafting-menu selection:
//   #include "crafting/status_effect_crafting.h"
//   gr::StatusEffectCrafting m_crafting;
//   m_crafting.SetRecipes(loadedRecipes);
//   if (m_crafting.CanCraft("venom_blade", playerInventory))
//   {
//       std::string effectId = m_crafting.Craft("venom_blade", playerInventory);
//       statusSystem.Apply(effectId, targetEnemy);
//   }
// -----------------------------------------------------------------

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

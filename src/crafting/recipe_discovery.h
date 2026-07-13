// ============================================================
// FILE: src/crafting/recipe_discovery.h
// SYSTEM: Crafting
// ROLE: track which crafting recipes the player has discovered
// DO NOT: hold recipe ingredient data here; see status_effect_crafting.h.
// OWNS: the discovered-recipe set.
// ============================================================
//
// [LEGO BLOCK: RECIPE DISCOVERY]
// -----------------------------------------------------------------
// What it does: stores which recipe IDs the player has unlocked.
//   Called when the player picks up a new ingredient or examines
//   a crafting book — just pass the recipe string ID.
//
// EXTEND: add a callback/delegate to fire a "new recipe" UI toast.
//
// EXAMPLE — trigger discovery on item pickup:
//   #include "crafting/recipe_discovery.h"
//   gr::RecipeDiscovery m_recipeDiscovery;
//   if (m_recipeDiscovery.Discover("potion_of_fire"))
//       hud.ShowNewRecipeToast("Potion of Fire");
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_set>

namespace gr
{
class RecipeDiscovery
{
public:
    bool Discover(const std::string& recipeId);
    bool IsDiscovered(const std::string& recipeId) const;

private:
    std::unordered_set<std::string> m_discoveredRecipes;
};
} // namespace gr

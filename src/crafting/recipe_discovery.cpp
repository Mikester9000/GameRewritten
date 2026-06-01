#include "recipe_discovery.h"

namespace gr
{
bool RecipeDiscovery::Discover(const std::string& recipeId)
{
    if (recipeId.empty())
    {
        return false;
    }
    return m_discoveredRecipes.insert(recipeId).second;
}

bool RecipeDiscovery::IsDiscovered(const std::string& recipeId) const
{
    return m_discoveredRecipes.find(recipeId) != m_discoveredRecipes.end();
}
} // namespace gr

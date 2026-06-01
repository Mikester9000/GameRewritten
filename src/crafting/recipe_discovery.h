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

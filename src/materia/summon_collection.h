#pragma once

#include <string>
#include <unordered_set>
#include <vector>

namespace gr
{
class SummonCollection
{
public:
    bool Discover(const std::string& summonId);
    bool HasSummon(const std::string& summonId) const;
    std::vector<std::string> GetAll() const;

private:
    std::unordered_set<std::string> m_discovered;
};
} // namespace gr

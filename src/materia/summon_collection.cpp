#include "summon_collection.h"

namespace gr
{
bool SummonCollection::Discover(const std::string& summonId)
{
    if (summonId.empty())
    {
        return false;
    }
    return m_discovered.insert(summonId).second;
}

bool SummonCollection::HasSummon(const std::string& summonId) const
{
    return m_discovered.find(summonId) != m_discovered.end();
}

std::vector<std::string> SummonCollection::GetAll() const
{
    return { m_discovered.begin(), m_discovered.end() };
}
} // namespace gr

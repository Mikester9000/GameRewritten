// DiscoveryJournal.cpp
// Landmark / route discovery tracking.

#include "DiscoveryJournal.hpp"

int DiscoveryJournal::Add(const std::string& name, const std::string& category)
{
    JournalEntry e;
    e.id       = m_nextId++;
    e.name     = name;
    e.category = category;
    m_entries.push_back(e);
    return e.id;
}

void DiscoveryJournal::MarkVisited(int id)
{
    for (JournalEntry& e : m_entries)
        if (e.id == id) { e.visited = true; return; }
}

void DiscoveryJournal::MarkVisited(const std::string& name)
{
    for (JournalEntry& e : m_entries)
        if (e.name == name) { e.visited = true; return; }
}

int DiscoveryJournal::VisitedCount() const
{
    int n = 0;
    for (const JournalEntry& e : m_entries)
        if (e.visited) ++n;
    return n;
}

#pragma once
// DiscoveryJournal.hpp
// Tracks all discovered landmarks and routes; feeds the world map legend
// and completion-percentage HUD element.

#include <string>
#include <vector>

struct JournalEntry
{
    int         id        = 0;
    std::string name;
    std::string category; // "Landmark", "Route", "Secret", etc.
    bool        visited   = false;
};

class DiscoveryJournal
{
public:
    // Add a trackable location.  Returns its id.
    int  Add(const std::string& name, const std::string& category);

    // Mark a location as visited (called by LandmarkTrigger callback).
    void MarkVisited(int id);
    void MarkVisited(const std::string& name); // convenience overload

    int  TotalCount()   const { return static_cast<int>(m_entries.size()); }
    int  VisitedCount() const;

    const std::vector<JournalEntry>& GetAll() const { return m_entries; }

private:
    std::vector<JournalEntry> m_entries;
    int                       m_nextId = 1;
};

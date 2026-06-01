#pragma once

#include <string>
#include <vector>

namespace gr
{
class TutorialReminder
{
public:
    void SetEntries(const std::vector<std::string>& entries);
    const std::vector<std::string>& GetEntries() const { return m_entries; }
    std::string GetCurrentEntry() const;
    void Next();
    void Previous();
    bool Empty() const { return m_entries.empty(); }

private:
    std::vector<std::string> m_entries;
    std::size_t m_selectedIndex = 0;
};
} // namespace gr

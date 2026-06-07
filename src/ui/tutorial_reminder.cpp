#include "tutorial_reminder.h"

namespace gr
{
void TutorialReminder::SetEntries(const std::vector<std::string>& entries)
{
    m_entries = entries;
    if (m_selectedIndex >= m_entries.size())
    {
        m_selectedIndex = 0;
    }
}

std::string TutorialReminder::GetCurrentEntry() const
{
    if (m_entries.empty())
    {
        return {};
    }
    return m_entries[m_selectedIndex];
}

void TutorialReminder::Next()
{
    if (m_entries.empty())
    {
        return;
    }
    m_selectedIndex = (m_selectedIndex + 1) % m_entries.size();
}

void TutorialReminder::Previous()
{
    if (m_entries.empty())
    {
        return;
    }
    m_selectedIndex = (m_selectedIndex == 0) ? (m_entries.size() - 1) : (m_selectedIndex - 1);
}
} // namespace gr

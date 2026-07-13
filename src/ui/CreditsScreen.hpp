#pragma once
// CreditsScreen.hpp
// Scrolling credits overlay shown on game completion or from the main menu.

#include <string>
#include <vector>

struct CreditsEntry
{
    std::string role;   // e.g. "Lead Developer"
    std::string name;   // e.g. "Mikester9000"
};

class CreditsScreen
{
public:
    void Open();
    void Close() { m_open = false; }
    bool IsOpen() const { return m_open; }

    // Draw scrolling credits inside an active ImGui frame.
    // Call each frame while IsOpen() is true.
    void Draw(float dt, float vpW, float vpH);

private:
    bool                       m_open    = false;
    float                      m_scroll  = 0.0f;
    std::vector<CreditsEntry>  m_entries;

    void BuildEntries();
};

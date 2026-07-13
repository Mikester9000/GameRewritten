#pragma once
// QuestFlags.hpp
// A flat key/value store for persistent world-state booleans used by quests,
// dialogue conditions, and spawn rules.  Intentionally header-only and cheap.

#include <string>
#include <unordered_map>

class QuestFlags
{
public:
    // Set a flag.  Creates it if it does not exist.
    void Set(const std::string& key, bool value = true) { m_flags[key] = value; }

    // Returns the flag value, or false if the flag was never set.
    bool Get(const std::string& key) const
    {
        auto it = m_flags.find(key);
        return it != m_flags.end() && it->second;
    }

    // Toggle: flips an existing flag or sets it to true if absent.
    void Toggle(const std::string& key) { m_flags[key] = !Get(key); }

    void Clear() { m_flags.clear(); }

    const std::unordered_map<std::string, bool>& GetAll() const { return m_flags; }

private:
    std::unordered_map<std::string, bool> m_flags;
};

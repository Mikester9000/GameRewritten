#pragma once
// InputBindingProfile.hpp
// Stores key/button bindings per action.  Allows runtime rebinding and
// exposes glyph hint strings for the HUD prompt system.

#include <string>
#include <unordered_map>

class InputBindingProfile
{
public:
    // Map an action name to a virtual key code (Win32 VK_* value).
    void Bind(const std::string& action, int vkCode);

    // Returns the VK code for an action, or 0 if not bound.
    int  GetKey(const std::string& action) const;

    // Returns a glyph hint string for the action, e.g. "[E]" or "[LB]".
    std::string GetHint(const std::string& action) const;

    void LoadDefaults();
    void Clear() { m_bindings.clear(); }

    const std::unordered_map<std::string, int>& GetAll() const { return m_bindings; }

private:
    std::unordered_map<std::string, int> m_bindings;
};

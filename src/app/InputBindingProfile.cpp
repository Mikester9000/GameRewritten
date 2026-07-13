// InputBindingProfile.cpp
// Per-action key binding store with HUD hint strings.

#include "InputBindingProfile.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void InputBindingProfile::Bind(const std::string& action, int vkCode)
{
    m_bindings[action] = vkCode;
}

int InputBindingProfile::GetKey(const std::string& action) const
{
    auto it = m_bindings.find(action);
    return it != m_bindings.end() ? it->second : 0;
}

std::string InputBindingProfile::GetHint(const std::string& action) const
{
    const int vk = GetKey(action);
    if (vk == 0) return "[?]";

    // Map a few common keys to readable labels.
    switch (vk)
    {
#ifdef _WIN32
    case VK_RETURN: return "[Enter]";
    case VK_SPACE:  return "[Space]";
    case VK_ESCAPE: return "[Esc]";
    case VK_TAB:    return "[Tab]";
    case VK_SHIFT:  return "[Shift]";
    case VK_CONTROL:return "[Ctrl]";
#endif
    default: break;
    }

    // Single ASCII printable character.
    if (vk >= 0x20 && vk <= 0x7E)
    {
        char c = static_cast<char>(vk);
        return std::string("[") + c + "]";
    }
    return "[Key" + std::to_string(vk) + "]";
}

void InputBindingProfile::LoadDefaults()
{
    Clear();
#ifdef _WIN32
    Bind("Attack",       'F');
    Bind("Interact",     'E');
    Bind("Dodge",        VK_SPACE);
    Bind("LockOn",       'Q');
    Bind("TacticalPause",VK_TAB);
    Bind("SurgeStrike",  'F');  // held Surge + F
    Bind("LimitBreak",   VK_SHIFT);
    Bind("Jump",         VK_SPACE);
    Bind("Map",          'M');
    Bind("Pause",        VK_ESCAPE);
#endif
}

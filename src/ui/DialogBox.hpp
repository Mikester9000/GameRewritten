// ============================================================
// FILE: src/ui/DialogBox.hpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: DialogBox module behavior and local implementation details.
// ============================================================

#pragma once

#include <string>


struct ImGuiIO;
#ifdef DialogBox
#undef DialogBox
#endif
class DialogBox
{
public:
    void Show(const std::string& speaker, const std::string& text);
    void Dismiss();
    bool IsOpen() const;
    void Update(float dt);
    void Draw(const ImGuiIO& io);

private:
    std::string m_speakerName;
    std::string m_fullText;
    std::string m_visibleText;
    float m_charTimer = 0.0f;
    float m_charInterval = 0.03f;
    bool m_isOpen = false;
    bool m_isComplete = false;
};

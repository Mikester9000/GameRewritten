#pragma once

#include <string>

namespace gr
{
class DefeatScreen
{
public:
    void Show(const std::string& reasonText);
    void Hide();
    bool IsVisible() const { return m_visible; }
    bool CanAcceptInput(float minSecondsBeforeInput = 0.35f) const;
    void Tick(float deltaSeconds);
    const std::string& GetReasonText() const { return m_reasonText; }

private:
    bool m_visible = false;
    float m_visibleSeconds = 0.0f;
    std::string m_reasonText = "Party defeated";
};
} // namespace gr

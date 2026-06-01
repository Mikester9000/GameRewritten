#pragma once

#include <string>

namespace gr
{
struct TooltipState
{
    std::string title;
    std::string body;
    float remainingSeconds = 0.0f;
};

class TooltipSystem
{
public:
    void ShowTooltip(const std::string& title, const std::string& body, float lifetimeSeconds);
    void Clear();
    void Tick(float deltaSeconds);
    bool IsVisible() const;
    const TooltipState& GetState() const { return m_state; }

private:
    TooltipState m_state;
};
} // namespace gr

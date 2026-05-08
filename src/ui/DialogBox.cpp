#include "DialogBox.hpp"

#include <imgui.h>

#include <algorithm>

void DialogBox::Show(const std::string& speaker, const std::string& text)
{
    m_speakerName = speaker;
    m_fullText = text;
    m_visibleText.clear();
    m_charTimer = 0.0f;
    m_isOpen = true;
    m_isComplete = m_fullText.empty();
    if (m_isComplete)
        m_visibleText = m_fullText;
}

void DialogBox::Dismiss()
{
    if (!m_isOpen)
        return;

    if (!m_isComplete)
    {
        m_visibleText = m_fullText;
        m_isComplete = true;
        return;
    }

    m_isOpen = false;
}

bool DialogBox::IsOpen() const
{
    return m_isOpen;
}

void DialogBox::Update(float dt)
{
    if (!m_isOpen || m_isComplete)
        return;

    if (dt <= 0.0f)
        return;

    m_charTimer += dt;
    while (m_charTimer >= m_charInterval && m_visibleText.size() < m_fullText.size())
    {
        m_visibleText.push_back(m_fullText[m_visibleText.size()]);
        m_charTimer -= m_charInterval;
    }

    if (m_visibleText.size() >= m_fullText.size())
    {
        m_visibleText = m_fullText;
        m_isComplete = true;
        m_charTimer = 0.0f;
    }
}

void DialogBox::Draw(const ImGuiIO& io)
{
    if (!m_isOpen)
        return;

    const float width = std::clamp(io.DisplaySize.x * 0.7f, 460.0f, 980.0f);
    const float height = 170.0f;
    const float x = (io.DisplaySize.x - width) * 0.5f;
    const float y = io.DisplaySize.y - height - 24.0f;

    ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.05f, 0.05f, 0.08f, 0.82f));

    const ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse;

    if (ImGui::Begin("##DialogBox", nullptr, flags))
    {
        ImGui::TextColored(ImVec4(1.0f, 0.9f, 0.35f, 1.0f), "%s", m_speakerName.c_str());
        ImGui::Separator();

        ImGui::PushTextWrapPos(0.0f);
        ImGui::TextUnformatted(m_visibleText.c_str());
        ImGui::PopTextWrapPos();

        if (m_isComplete)
        {
            ImGui::Spacing();
            ImGui::TextDisabled("[Press E to continue]");
        }
    }
    ImGui::End();

    ImGui::PopStyleColor();
}

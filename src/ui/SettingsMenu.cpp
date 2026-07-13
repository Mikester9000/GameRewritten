// SettingsMenu.cpp
// Full settings menu: graphics / audio / input / accessibility.

#include "SettingsMenu.hpp"

#include "../audio/AudioManager.hpp"
#include "../../third_party/imgui/imgui.h"

void SettingsMenu::Draw(void* /*preset*/, AudioManager* audio)
{
    if (!m_open) return;

    ImGui::SetNextWindowSize({ 480, 360 }, ImGuiCond_FirstUseEver);
    ImGui::Begin("Settings", &m_open);

    const char* tabs[] = { "Graphics", "Audio", "Input", "Accessibility" };
    for (int i = 0; i < 4; ++i)
    {
        if (i > 0) ImGui::SameLine();
        if (ImGui::Button(tabs[i])) m_activeTab = i;
    }
    ImGui::Separator();

    switch (m_activeTab)
    {
    case 0: DrawGraphicsTab();    break;
    case 1: DrawAudioTab(audio);  break;
    case 2: DrawInputTab();       break;
    case 3: DrawAccessibilityTab(); break;
    }

    ImGui::End();
}

void SettingsMenu::DrawGraphicsTab()
{
    const char* levels[] = { "Low", "Medium", "High", "Ultra" };
    ImGui::Combo("Quality Preset", &m_qualityTier, levels, 4);
    ImGui::Checkbox("VSync",       &m_vsync);
    ImGui::Checkbox("Cel Shading", &m_celShading);
    ImGui::TextDisabled("(Apply changes via QualityPresetEnforcer at startup)");
}

void SettingsMenu::DrawAudioTab(AudioManager* audio)
{
    if (!audio) { ImGui::TextDisabled("(no audio manager)"); return; }
    float bgm = audio->GetBGMVolume();
    float sfx = audio->GetSFXVolume();
    if (ImGui::SliderFloat("BGM Volume", &bgm, 0.0f, 1.0f)) audio->SetBGMVolume(bgm);
    if (ImGui::SliderFloat("SFX Volume", &sfx, 0.0f, 1.0f)) audio->SetSFXVolume(sfx);
}

void SettingsMenu::DrawInputTab()
{
    ImGui::TextDisabled("Input rebinding — see InputBindingProfile.");
}

void SettingsMenu::DrawAccessibilityTab()
{
    ImGui::TextDisabled("Accessibility options — coming soon.");
}

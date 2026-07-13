#pragma once
// SettingsMenu.hpp
// Full settings menu: graphics, audio, input, and accessibility tabs.
// Wraps QualityPreset and AudioManager options in a single ImGui window.

class AudioManager; // forward

class SettingsMenu
{
public:
    void Open()    { m_open = true; }
    void Close()   { m_open = false; }
    void Toggle()  { m_open = !m_open; }
    bool IsOpen()  const { return m_open; }

    // Draw the settings window.  Call inside an active ImGui frame.
    // Changes are applied immediately; pass nullptr for unavailable pointers.
    void Draw(void* /*preset*/, AudioManager* audio);

    // Expose local mirror values so caller can read back changed settings.
    int  GetQualityTier() const { return m_qualityTier; }
    bool GetVSync()       const { return m_vsync; }
    bool GetCelShading()  const { return m_celShading; }

private:
    bool m_open       = false;
    int  m_activeTab  = 0;      // 0=Graphics, 1=Audio, 2=Input, 3=Accessibility
    int  m_qualityTier = 1;     // 0=Low…3=Ultra
    bool m_vsync      = true;
    bool m_celShading = true;

    void DrawGraphicsTab();
    void DrawAudioTab   (AudioManager* audio);
    void DrawInputTab   ();
    void DrawAccessibilityTab();
};

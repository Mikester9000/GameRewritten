#pragma once
// CombatDebugPanel.hpp
// ImGui overlay for combat telemetry: shows per-hit damage, DPS, gauge
// values, and per-enemy state so designers can tune numbers in-play.

struct CombatSystem;  // forward
struct PlayerStats;   // forward

class CombatDebugPanel
{
public:
    void Open()    { m_open = true;  }
    void Close()   { m_open = false; }
    void Toggle()  { m_open = !m_open; }
    bool IsOpen()  const { return m_open; }

    // Accumulate a damage event for the rolling DPS display.
    void RecordHit(int damage);

    // Draw the panel.  Call inside an active ImGui frame.
    // Pass null for unavailable pointers; the panel omits those sections.
    void Draw(float dt,
              const PlayerStats* player,
              const CombatSystem* combat);

private:
    bool  m_open   = false;
    float m_dps    = 0.0f;
    float m_window = 3.0f; // seconds over which DPS is averaged
    float m_accumulated = 0.0f;
    float m_timer  = 0.0f;
};

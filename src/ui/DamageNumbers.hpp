// ============================================================
// FILE: src/ui/DamageNumbers.hpp
// SYSTEM: UI
// ROLE: HUD, menus, overlays, and editor tool panels
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: DamageNumbers module behavior and local implementation details.
// ============================================================

#pragma once

class DamageNumbers
{
public:
    void Reset();
    // Negative values are clamped to zero and logged as a warning.
    void Spawn(int damage, float worldX, float worldY, float worldZ);
    void SpawnMiss(float worldX, float worldY, float worldZ);
    void Update(float dt);
    void Draw(float camX, float camY, float camZ,
              float yaw, float pitch,
              float vpW, float vpH) const;

private:
    struct Entry
    {
        enum class Style
        {
            Damage,
            Miss
        };

        bool  active = false;
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        int   damage = 0;
        float ageSec = 0.0f;
        Style style = Style::Damage;
    };

    static constexpr int   kMaxEntries = 64;
    static constexpr float kLifetimeSec = 1.0f;
    static constexpr float kRiseSpeed = 0.8f;

    Entry* AcquireEntrySlot();
    Entry m_entries[kMaxEntries]{};
};

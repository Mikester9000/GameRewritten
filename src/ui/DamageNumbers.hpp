#pragma once

#include <imgui.h>

class DamageNumbers
{
public:
    void Reset();
    // Negative values are clamped to zero and logged as a warning.
    void Spawn(int damage, float worldX, float worldY, float worldZ);
    void Update(float dt);
    void Draw(float camX, float camY, float camZ,
              float yaw, float pitch,
              float vpW, float vpH) const;

private:
    struct Entry
    {
        bool  active = false;
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        int   damage = 0;
        float ageSec = 0.0f;
    };

    static constexpr int   kMaxEntries = 64;
    static constexpr float kLifetimeSec = 1.0f;
    static constexpr float kRiseSpeed = 0.8f;

    Entry m_entries[kMaxEntries]{};
};

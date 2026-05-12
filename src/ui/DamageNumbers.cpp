#include "DamageNumbers.hpp"

#include "ScreenProjection.hpp"

#include <algorithm>
#include <cstdio>

void DamageNumbers::Reset()
{
    for (Entry& entry : m_entries)
        entry = Entry{};
}

void DamageNumbers::Spawn(int damage, float worldX, float worldY, float worldZ)
{
    Entry* slot = nullptr;

    for (Entry& entry : m_entries)
    {
        if (!entry.active)
        {
            slot = &entry;
            break;
        }
    }

    if (!slot)
    {
        slot = &m_entries[0];
        for (Entry& entry : m_entries)
        {
            if (entry.ageSec > slot->ageSec)
                slot = &entry;
        }
    }

    slot->active = true;
    slot->x = worldX;
    slot->y = worldY;
    slot->z = worldZ;
    slot->damage = std::max(0, damage);
    slot->ageSec = 0.0f;
}

void DamageNumbers::Update(float dt)
{
    if (dt <= 0.0f)
        return;

    for (Entry& entry : m_entries)
    {
        if (!entry.active)
            continue;

        entry.ageSec += dt;
        entry.y += kRiseSpeed * dt;

        if (entry.ageSec >= kLifetimeSec)
            entry.active = false;
    }
}

void DamageNumbers::Draw(float camX, float camY, float camZ,
                         float yaw, float pitch,
                         float vpW, float vpH) const
{
    ImDrawList* drawList = ImGui::GetForegroundDrawList();
    if (!drawList)
        return;

    for (const Entry& entry : m_entries)
    {
        if (!entry.active)
            continue;

        float sx = 0.0f;
        float sy = 0.0f;
        if (!WorldToScreen(entry.x, entry.y, entry.z,
                           camX, camY, camZ, yaw, pitch,
                           vpW, vpH, sx, sy))
        {
            continue;
        }

        const float t = std::clamp(entry.ageSec / kLifetimeSec, 0.0f, 1.0f);
        const int alpha = static_cast<int>((1.0f - t) * 255.0f);

        char text[16]{};
        std::snprintf(text, sizeof(text), "%d", entry.damage);

        const ImVec2 textSize = ImGui::CalcTextSize(text);
        drawList->AddText(ImVec2(sx - textSize.x * 0.5f, sy),
                          IM_COL32(255, 255, 255, alpha),
                          text);
    }
}

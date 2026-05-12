#include "DamageNumbers.hpp"

#include "ScreenProjection.hpp"

#include "../../third_party/imgui/imgui.h"
#include <logger/Logger.hpp>
#include <algorithm>
#include <cstdio>
#include <cfloat>

void DamageNumbers::Reset()
{
    for (Entry& entry : m_entries)
        entry = Entry{};
}

void DamageNumbers::Spawn(int damage, float worldX, float worldY, float worldZ)
{
    if (damage < 0)
    {
        LOG_WARN("DamageNumbers: received negative damage value; clamping to zero.");
        damage = 0;
    }

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
    slot->damage = damage;
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
        if (!ScreenProjection::WorldToScreen(entry.x, entry.y, entry.z,
                                             camX, camY, camZ, yaw, pitch,
                                             vpW, vpH, sx, sy))
        {
            continue;
        }

        const float t = std::clamp(entry.ageSec / kLifetimeSec, 0.0f, 1.0f);
        const int alpha = static_cast<int>((1.0f - t) * 255.0f);

        char text[16]{};
        std::snprintf(text, sizeof(text), "%d", entry.damage);

        const float fontSize = 33.0f;
        ImFont* font = ImGui::GetFont();
        const ImVec2 textSize = font->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, text);

        drawList->AddText(
            font,
            fontSize,
            ImVec2(sx - textSize.x * 0.5f, sy),
            IM_COL32(255, 255, 255, alpha),
            text);
    }
}

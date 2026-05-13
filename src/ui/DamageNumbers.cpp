#include "DamageNumbers.hpp"

#include "ScreenProjection.hpp"

#include "../../third_party/imgui/imgui.h"
#include <DirectXMath.h>
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
    slot->style  = Entry::Style::Damage;
}

void DamageNumbers::SpawnMiss(float worldX, float worldY, float worldZ)
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
    slot->damage = 0;
    slot->ageSec = 0.0f;
    slot->style  = Entry::Style::Miss;
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

    // Build the view*projection matrix once for the whole batch instead of
    // rebuilding it for every active entry (up to kMaxEntries per frame).
    DirectX::XMMATRIX viewProj;
    if (!ScreenProjection::BuildViewProj(camX, camY, camZ, yaw, pitch, vpW, vpH, viewProj))
        return;

    for (const Entry& entry : m_entries)
    {
        if (!entry.active)
            continue;

        float sx = 0.0f;
        float sy = 0.0f;
        if (!ScreenProjection::WorldToScreenVP(entry.x, entry.y, entry.z,
                                               viewProj, vpW, vpH, sx, sy))
        {
            continue;
        }

        const float t = std::clamp(entry.ageSec / kLifetimeSec, 0.0f, 1.0f);
        const int alpha = static_cast<int>((1.0f - t) * 255.0f);

        char text[16]{};
        float fontSize = 33.0f;
        ImU32 textColor = IM_COL32(255, 255, 255, alpha);
        if (entry.style == Entry::Style::Miss)
        {
            std::snprintf(text, sizeof(text), "MISS");
            fontSize = 26.0f;
            textColor = IM_COL32(235, 215, 120, alpha);
        }
        else
        {
            std::snprintf(text, sizeof(text), "%d", entry.damage);
        }

        ImFont* font = ImGui::GetFont();
        const ImVec2 textSize = font->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, text);

        drawList->AddText(
            font,
            fontSize,
            ImVec2(sx - textSize.x * 0.5f, sy),
            textColor,
            text);
    }
}

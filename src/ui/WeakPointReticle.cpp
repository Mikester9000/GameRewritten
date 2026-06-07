#include "WeakPointReticle.hpp"

#include "ScreenProjection.hpp"
#include "../game/actors/EnemyActor.hpp"

#include <imgui.h>
#include <cmath>

void WeakPointReticle::Draw(const EnemyActor* target,
                            float camX, float camY, float camZ,
                            float yaw, float pitch,
                            float vpW, float vpH,
                            float opacity) const
{
    if (!target || vpW <= 0.0f || vpH <= 0.0f)
        return;

    DirectX::XMMATRIX viewProj;
    if (!ScreenProjection::BuildViewProj(camX, camY, camZ, yaw, pitch, vpW, vpH, viewProj))
        return;

    float sx = 0.0f;
    float sy = 0.0f;
    if (!ScreenProjection::WorldToScreenVP(target->x, target->y + 1.9f, target->z, viewProj, vpW, vpH, sx, sy))
        return;

    // Back-angle heuristic: camera roughly behind enemy = weak-point opportunity.
    const float toCamX = camX - target->x;
    const float toCamZ = camZ - target->z;
    const float lenSq = toCamX * toCamX + toCamZ * toCamZ;
    if (lenSq < 0.0001f)
        return;

    const float invLen = 1.0f / sqrtf(lenSq);
    const float dirToCamX = toCamX * invLen;
    const float dirToCamZ = toCamZ * invLen;
    const float enemyForwardX = sinf(target->yaw);
    const float enemyForwardZ = cosf(target->yaw);
    const float backDot = (enemyForwardX * dirToCamX) + (enemyForwardZ * dirToCamZ);
    const bool weakWindow = backDot > 0.45f;

    ImDrawList* dl = ImGui::GetForegroundDrawList();
    if (!dl)
        return;

    const int a = static_cast<int>(255.0f * (opacity < 0.0f ? 0.0f : (opacity > 1.0f ? 1.0f : opacity)));
    const ImU32 ringColor = weakWindow ? IM_COL32(255, 200, 60, a) : IM_COL32(120, 150, 180, a);
    const ImU32 textColor = weakWindow ? IM_COL32(255, 235, 120, a) : IM_COL32(190, 210, 235, a);

    dl->AddCircle(ImVec2(sx, sy), 22.0f, ringColor, 24, 2.0f);
    dl->AddCircle(ImVec2(sx, sy), 12.0f, ringColor, 24, 1.2f);

    if (weakWindow)
        dl->AddText(ImVec2(sx - 40.0f, sy - 34.0f), textColor, "WEAK POINT");
}

TASK: [One sentence. What to build.]

FILE: [Exact path. e.g. src/game/combat/CombatSystem.cpp]

STUB (copy exactly, fill body only):
──────────────────────────────────────
[return type] [ClassName]::[FunctionName]([params])
{
    // YOUR CODE GOES HERE
}
──────────────────────────────────────

WHAT IT DOES:
- [Step 1]
- [Step 2]
- [Step 3]

DO NOT:
- [Prohibition 1]
- [Prohibition 2]
- [Prohibition 3]

EXPECTED LENGTH: ~[N] lines inside the function body. If you write more, you are doing too much.

PASTE CONTEXT HERE (existing code the model needs — 20–40 lines max):
──────────────────────────────────────
[Human pastes relevant structs/signatures here]
──────────────────────────────────────

AFTER: Mark ✅ in docs/SYSTEMS.md. Add one line to docs/CHANGELOG.md.

Filled Example:

TASK: Build the HUD screen-edge red flash that fades after player damage.

FILE: src/ui/GameHUD.cpp

STUB (copy exactly, fill body only):
──────────────────────────────────────
void GameHUD::DrawDamageFlash(float dt)
{
    if (flashTimer <= 0.0f) return;
    flashTimer = std::max(0.0f, flashTimer - dt);
    const float alpha = std::clamp(flashTimer / kDamageFlashDurationSec, 0.0f, 1.0f);
    if (alpha <= 0.0f) return;
    ImDrawList* drawList = ImGui::GetForegroundDrawList();
    const ImVec2 size = ImGui::GetIO().DisplaySize;
    const ImU32 color = IM_COL32(255, 40, 40, static_cast<int>(alpha * 180.0f));
    const float edge = 14.0f;
    drawList->AddRectFilled(ImVec2(0, 0), ImVec2(size.x, edge), color);
    drawList->AddRectFilled(ImVec2(0, size.y - edge), ImVec2(size.x, size.y), color);
    drawList->AddRectFilled(ImVec2(0, 0), ImVec2(edge, size.y), color);
    drawList->AddRectFilled(ImVec2(size.x - edge, 0), ImVec2(size.x, size.y), color);
}
──────────────────────────────────────

WHAT IT DOES:
- If `flashTimer` is active, reduce it by `dt` and clamp to zero.
- Convert the remaining timer to alpha strength for the red edge overlay.
- Draw four thin red rectangles at the screen edges using that alpha.

DO NOT:
- Do not change function name, params, or file placement.
- Do not allocate memory or create new classes.
- Do not modify `Main.cpp`.

EXPECTED LENGTH: ~12 lines inside the function body. If you write more, you are doing too much.

PASTE CONTEXT HERE (existing code the model needs — 20–40 lines max):
──────────────────────────────────────
static constexpr float kDamageFlashDurationSec = 0.35f;
float flashTimer = 0.0f;

void GameHUD::TriggerDamageFlash(float durationSec)
{
    flashTimer = std::max(flashTimer, durationSec);
}

void GameHUD::Draw(const PlayerStats& stats, const ImGuiIO& io, float totalTime)
{
    (void)stats;
    (void)totalTime;
    DrawDamageFlash(io.DeltaTime);
}
──────────────────────────────────────

AFTER: Mark ✅ in docs/SYSTEMS.md. Add one line to docs/CHANGELOG.md.

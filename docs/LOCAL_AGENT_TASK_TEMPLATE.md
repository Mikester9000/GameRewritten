# LOCAL AGENT TASK TEMPLATE

Use this card to make the model write only one function body.

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

## Filled Example — Screen edge damage flash

TASK: Build the HUD screen-edge red flash that fades after player damage.

FILE: src/ui/GameHUD.cpp

STUB (copy exactly, fill body only):
──────────────────────────────────────
void GameHUD::DrawDamageFlash(float dt)
{
    // YOUR CODE GOES HERE
}
──────────────────────────────────────

WHAT IT DOES:
- If `flashTimer` is active, reduce it by `dt` and clamp to zero.
- Convert the remaining timer to alpha strength for the red edge overlay.
- Draw four thin red rectangles at screen edges with that alpha.

DO NOT:
- Do not change function name, params, or file placement.
- Do not allocate memory or create new classes.
- Do not modify `Main.cpp`.

EXPECTED LENGTH: ~12 lines inside the function body. If you write more, you are doing too much.

PASTE CONTEXT HERE (existing code the model needs — 20–40 lines max):
──────────────────────────────────────
struct GameHUD
{
    float flashTimer = 0.0f;
    void TriggerDamageFlash(float durationSec);
    void Draw(const PlayerStats& stats, const ImGuiIO& io, float totalTime);
    void DrawDamageFlash(float dt);
};

void GameHUD::Draw(const PlayerStats& stats, const ImGuiIO& io, float totalTime)
{
    (void)stats;
    (void)totalTime;
    DrawDamageFlash(io.DeltaTime);
}
──────────────────────────────────────

AFTER: Mark ✅ in docs/SYSTEMS.md. Add one line to docs/CHANGELOG.md.

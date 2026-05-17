# NEXT TASK (Read This First)

This is your only job right now.
Do not read other task docs until this is done.
Complete exactly what is described here, then stop.

---

## CURRENT TASK: Screen Edge Damage Flash

**System:** Screen edge damage flash  
**Status in SYSTEMS.md:** ❌ Not started (line 79)  
**Scope:** 3 files — `src/ui/GameHUD.hpp`, `src/ui/GameHUD.cpp`, `src/app/Main.cpp`

---

## What it does

When the player takes damage, the screen edges flash red for 0.35 seconds, then fade out.
It is distinct from the low-HP pulse (which already exists and loops while HP is low).

---

## Step 1 — Edit `src/ui/GameHUD.hpp`

**Add to private section** (after `float m_lowHpPulseTime = 0.0f;`):

```cpp
float m_damageFlashTimer = 0.0f;
```

**Add a public method declaration** (after `void DrawOffScreenTargetIndicator(...)`):

```cpp
// Trigger a one-shot red screen-edge flash. Call when the player takes damage.
void TriggerDamageFlash();
```

**Add a private method declaration** (create a `private:` section or add next to existing private methods):

```cpp
void DrawDamageFlash(float dt);
```

---

## Step 2 — Edit `src/ui/GameHUD.cpp`

**Add this function** anywhere in the file before `GameHUD::Draw`:

```cpp
void GameHUD::TriggerDamageFlash()
{
    m_damageFlashTimer = 0.35f;
}

void GameHUD::DrawDamageFlash(float dt)
{
    // Nothing to draw if the timer is not running.
    if (m_damageFlashTimer <= 0.0f)
        return;

    // Tick the timer down and derive fade alpha from remaining time.
    m_damageFlashTimer -= dt;
    if (m_damageFlashTimer < 0.0f)
        m_damageFlashTimer = 0.0f;

    float alpha = m_damageFlashTimer / 0.35f;
    ImU32 color = IM_COL32(220, 0, 0, static_cast<int>(alpha * 180.0f));

    // Draw four thin red rectangles along the screen edges.
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    float w  = ImGui::GetIO().DisplaySize.x;
    float h  = ImGui::GetIO().DisplaySize.y;
    float th = kEdgeBarThickness;

    draw->AddRectFilled(ImVec2(0.0f, 0.0f),      ImVec2(w, th),      color); // top
    draw->AddRectFilled(ImVec2(0.0f, h - th),    ImVec2(w, h),       color); // bottom
    draw->AddRectFilled(ImVec2(0.0f, th),         ImVec2(th, h - th), color); // left
    draw->AddRectFilled(ImVec2(w - th, th),       ImVec2(w, h - th),  color); // right
}
```

**In `GameHUD::Draw()`** — add this call at the very beginning of the function body
(before `m_lowHpPulseTime += ...`):

```cpp
DrawDamageFlash(dt);
```

---

## Step 3 — Edit `src/app/Main.cpp`

Find the section of the main loop that calls `runtimeScene.BeginFrame(...)`.
Add these two lines around that call:

```cpp
// Capture HP before update so we can detect a hit this frame.
float prevHp = playerActor.stats.hp;

runtimeScene.BeginFrame(scaledDt, renderer, camX, camY, camZ);

// Trigger damage flash if the player lost HP this frame.
if (playerActor.stats.hp < prevHp)
    gameHud.TriggerDamageFlash();
```

**Do not** change any other line in Main.cpp.

---

## DO NOT

- Do not change the function name, file, or parameters.
- Do not allocate memory or add new classes.
- Do not modify the low-HP pulse system.
- Do not touch any other system.

---

## AFTER completing this task

1. Open `docs/SYSTEMS.md`. Find "Screen edge damage flash". Change ❌ to ✅.
2. Open `docs/CHANGELOG.md`. Add one line:
   `[YYYY-MM-DD] Added screen-edge damage flash to GameHUD (TriggerDamageFlash / DrawDamageFlash).`
3. Open `docs/AGENT_WORK_LOG.md`. Add one entry (see format inside that file).
4. Open `docs/TASK_QUEUE.md`. Copy Task 1 from that file into this file to replace the current task.

---

*Last updated: 2026-05-17 — awaiting implementation*

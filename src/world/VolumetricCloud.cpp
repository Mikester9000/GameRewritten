// ============================================================
// FILE: src/world/VolumetricCloud.cpp
// SYSTEM: World / Atmosphere
// ROLE: Implements VolumetricCloud — per-frame cloud parameter management.
//
// FOR QWEN: Implement each function in order.
//   Key: smooth transitions require lerp — see each TODO for the formula.
// ============================================================

#include "VolumetricCloud.hpp"
#include <algorithm>
#include <cmath>

// ============================================================
// CONSTRUCTOR
// ============================================================
VolumetricCloud::VolumetricCloud()
{
    m_params = CloudParams{};
}


// ============================================================
// Initialize
// ============================================================
void VolumetricCloud::Initialize(float windDirectionX, float windDirectionZ,
                                  float baseScrollSpeed)
{
    m_windDirX        = windDirectionX;
    m_windDirZ        = windDirectionZ;
    m_baseScrollSpeed = baseScrollSpeed;
    m_time            = 0.0f;
    m_params          = CloudParams{};
}


// ============================================================
// GetTimeOfDayCloudColor (static)
// Returns cloud base color for the current time of day.
//
// TODO (Qwen): Improve with smooth lerp between all 4 bands.
//   Current: stepwise selection. Add lerp for smooth sunrise/sunset ramp.
// ============================================================
void VolumetricCloud::GetTimeOfDayCloudColor(float t, float& r, float& g, float& b)
{
    if (t >= 0.18f && t <= 0.35f)
    {
        // Dawn: slightly pink tinted
        r = 0.95f; g = 0.85f; b = 0.82f;
    }
    else if (t >= 0.40f && t <= 0.60f)
    {
        // Noon: bright white
        r = 0.96f; g = 0.96f; b = 0.96f;
    }
    else if (t >= 0.68f && t <= 0.85f)
    {
        // Dusk: orange-purple
        r = 0.90f; g = 0.72f; b = 0.65f;
    }
    else
    {
        // Night: dark grey-blue
        r = 0.35f; g = 0.38f; b = 0.45f;
    }
    // TODO (Qwen): Add lerp between bands for smooth sunrise/sunset transitions.
}


// ============================================================
// GetTimeOfDaySunTint (static)
// Returns cloud edge sun highlight color for the current time of day.
// ============================================================
void VolumetricCloud::GetTimeOfDaySunTint(float t, float& r, float& g, float& b)
{
    if (t >= 0.18f && t <= 0.35f)
    {
        // Dawn: warm pink
        r = 1.00f; g = 0.80f; b = 0.70f;
    }
    else if (t >= 0.40f && t <= 0.60f)
    {
        // Noon: warm white
        r = 1.00f; g = 0.97f; b = 0.88f;
    }
    else if (t >= 0.68f && t <= 0.85f)
    {
        // Dusk: flame orange
        r = 1.00f; g = 0.65f; b = 0.35f;
    }
    else
    {
        // Night: cold grey (no sun visible)
        r = 0.30f; g = 0.33f; b = 0.40f;
    }
    // TODO (Qwen): smooth lerp between bands.
}


// ============================================================
// Update
// Advances cloud simulation one frame.
// ============================================================
void VolumetricCloud::Update(float weatherCoverage, float windStrength,
                              float timeOfDay, float dt)
{
    if (!m_enabled) return;

    // Step 1: Advance time
    m_time += dt;

    // Step 2: Smooth coverage transition (clouds build/dissipate slowly)
    // TODO (Qwen): Replace direct assignment with lerp:
    //   float blendSpeed = 0.15f * dt;
    //   m_params.cloudCoverage += (weatherCoverage - m_params.cloudCoverage) * blendSpeed;
    m_params.cloudCoverage = std::clamp(weatherCoverage, 0.0f, 1.0f); // STUB

    // Step 3: Scroll speed from wind
    float scrollSpeed = windStrength * m_baseScrollSpeed;
    m_params.cloudScrollX = m_windDirX * scrollSpeed;
    m_params.cloudScrollZ = m_windDirZ * scrollSpeed;

    // Step 4: Update time uniform
    m_params.cloudTime = m_time;

    // Step 5: Time-of-day cloud color
    GetTimeOfDayCloudColor(timeOfDay,
                           m_params.cloudBaseColor[0],
                           m_params.cloudBaseColor[1],
                           m_params.cloudBaseColor[2]);

    // Step 6: Sun tint
    GetTimeOfDaySunTint(timeOfDay,
                        m_params.cloudSunTint[0],
                        m_params.cloudSunTint[1],
                        m_params.cloudSunTint[2]);

    // Step 7: Shadow strength scales with coverage
    // More overcast = darker undersides
    // TODO (Qwen): lerp: shadowStr = lerp(0.10, 0.50, m_params.cloudCoverage)
    m_params.cloudShadowStr = 0.10f + m_params.cloudCoverage * 0.40f;

    // Edge softness: storm clouds have harder edges, wispy clouds are soft
    // TODO (Qwen): lerp: softness = lerp(0.12, 0.03, m_params.cloudCoverage)
    m_params.cloudEdgeSoftness = 0.12f - m_params.cloudCoverage * 0.09f;
    m_params.cloudEdgeSoftness = std::clamp(m_params.cloudEdgeSoftness, 0.02f, 0.15f);
}

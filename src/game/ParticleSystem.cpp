// ============================================================
// FILE: src/game/ParticleSystem.cpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: ParticleSystem module behavior and local implementation details.
// ============================================================

// ParticleSystem.cpp
// GT610-safe ambient particle system.
// Particles are maintained as CPU data and projected to screen each frame,
// then drawn as small ImGui DrawList dots — no extra GPU draw calls.

#include "ParticleSystem.hpp"

#include <cmath>
#include <algorithm>
#include <imgui.h>
#include <DirectXMath.h>

using namespace DirectX;

// ---------------------------------------------------------------------------
// Internal helpers
// ---------------------------------------------------------------------------
namespace
{
unsigned int g_pseed = 42;
float PRand()
{
    g_pseed = g_pseed * 1664525u + 1013904223u;
    return static_cast<float>(g_pseed & 0xFFFFu) / 65535.0f;
}
float PRandRange(float lo, float hi) { return lo + PRand() * (hi - lo); }

// Project a world-space point to screen space.
// Returns false if the point is behind the camera.
bool WorldToScreen(float wx, float wy, float wz,
                   float camX, float camY, float camZ,
                   float yaw, float pitch,
                   float vpW, float vpH,
                   float& outSX, float& outSY)
{
    constexpr float kPi = XM_PI;
    (void)kPi;

    const float lookX = cosf(pitch) * sinf(yaw);
    const float lookY = sinf(pitch);
    const float lookZ = cosf(pitch) * cosf(yaw);

    XMVECTOR pos    = XMVectorSet(camX, camY, camZ, 1.0f);
    XMVECTOR target = XMVectorSet(camX + lookX, camY + lookY, camZ + lookZ, 1.0f);
    XMVECTOR up     = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtLH(pos, target, up);
    XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, vpW / vpH, 0.1f, 2000.0f);
    XMMATRIX vp   = XMMatrixMultiply(view, proj);

    XMVECTOR world = XMVectorSet(wx, wy, wz, 1.0f);
    XMVECTOR clip  = XMVector4Transform(world, vp);

    const float w = XMVectorGetW(clip);
    if (w <= 0.001f)
        return false;

    const float ndcX = XMVectorGetX(clip) / w;
    const float ndcY = XMVectorGetY(clip) / w;

    if (ndcX < -1.0f || ndcX > 1.0f || ndcY < -1.0f || ndcY > 1.0f)
        return false;

    outSX = (ndcX * 0.5f + 0.5f) * vpW;
    outSY = (1.0f - (ndcY * 0.5f + 0.5f)) * vpH;
    return true;
}
}

// ---------------------------------------------------------------------------
// ParticleSystem
// ---------------------------------------------------------------------------
ParticleSystem::ParticleSystem()
{
    for (int i = 0; i < kMaxParticles; ++i)
        m_particles[i] = {};
}

// ---------------------------------------------------------------------------
// Init — seed all slots with random positions
// ---------------------------------------------------------------------------
void ParticleSystem::Init(float worldX, float worldZ)
{
    m_count      = kMaxParticles;
    m_spawnTimer = 0.0f;

    for (int i = 0; i < kMaxParticles; ++i)
    {
        Particle& p = m_particles[i];
        p.x       = worldX + PRandRange(-18.0f, 18.0f);
        p.y       = PRandRange(0.5f, 4.0f);
        p.z       = worldZ + PRandRange(-18.0f, 18.0f);
        p.vx      = PRandRange(-0.08f, 0.08f);
        p.vy      = PRandRange(-0.02f, 0.06f);
        p.vz      = PRandRange(-0.08f, 0.08f);
        p.maxLife = PRandRange(4.0f, 12.0f);
        p.life    = PRandRange(0.0f, p.maxLife); // stagger so they don't all expire together
        // Colour palette: warm dust (tan), cool leaf (greenish), cold firefly (yellow-green).
        const int type = static_cast<int>(PRandRange(0.0f, 3.0f));
        if (type == 0)       { p.r = 0.80f; p.g = 0.70f; p.b = 0.50f; } // dust
        else if (type == 1)  { p.r = 0.45f; p.g = 0.65f; p.b = 0.30f; } // leaf
        else                 { p.r = 0.85f; p.g = 0.95f; p.b = 0.40f; } // firefly
        p.size = PRandRange(1.5f, 3.5f);
    }
}

// ---------------------------------------------------------------------------
// SpawnOne — reset one dead particle
// ---------------------------------------------------------------------------
void ParticleSystem::SpawnOne(float cx, float cy, float cz, float windStrength)
{
    for (int i = 0; i < kMaxParticles; ++i)
    {
        if (m_particles[i].life > 0.0f)
            continue;

        Particle& p = m_particles[i];
        p.x       = cx + PRandRange(-18.0f, 18.0f);
        p.y       = cy + PRandRange(0.3f, 3.5f);
        p.z       = cz + PRandRange(-18.0f, 18.0f);
        p.vx      = PRandRange(-0.06f, 0.06f) + windStrength * 0.25f;
        p.vy      = PRandRange(-0.01f, 0.05f);
        p.vz      = PRandRange(-0.06f, 0.06f);
        p.maxLife = PRandRange(4.0f, 12.0f);
        p.life    = p.maxLife;
        const int type = static_cast<int>(PRandRange(0.0f, 3.0f));
        if (type == 0)       { p.r = 0.80f; p.g = 0.70f; p.b = 0.50f; }
        else if (type == 1)  { p.r = 0.45f; p.g = 0.65f; p.b = 0.30f; }
        else                 { p.r = 0.85f; p.g = 0.95f; p.b = 0.40f; }
        p.size = PRandRange(1.5f, 3.5f);
        break;
    }
}

// ---------------------------------------------------------------------------
// Update
// ---------------------------------------------------------------------------
void ParticleSystem::Update(float dt, float windStrength,
                            float playerX, float playerY, float playerZ)
{
    if (dt <= 0.0f)
        return;

    // Spawn rate: one new particle every ~0.4 seconds.
    constexpr float kSpawnInterval = 0.4f;
    m_spawnTimer -= dt;
    if (m_spawnTimer <= 0.0f)
    {
        m_spawnTimer = kSpawnInterval;
        SpawnOne(playerX, playerY + 1.5f, playerZ, windStrength);
    }

    for (int i = 0; i < kMaxParticles; ++i)
    {
        Particle& p = m_particles[i];
        if (p.life <= 0.0f)
            continue;

        p.life -= dt;
        p.x    += p.vx * dt;
        p.y    += p.vy * dt;
        p.z    += p.vz * dt;

        // Gentle wind drift on X axis.
        p.vx += windStrength * 0.05f * dt;

        // Soft clamp so particles don't drift too far from the player.
        const float dxp = p.x - playerX;
        const float dzp = p.z - playerZ;
        if ((dxp * dxp + dzp * dzp) > 35.0f * 35.0f)
            p.life = 0.0f; // expire particles that drift out of range
    }
}

// ---------------------------------------------------------------------------
// Draw
// ---------------------------------------------------------------------------
void ParticleSystem::Draw(float camX, float camY, float camZ,
                          float yaw, float pitch,
                          float vpW, float vpH) const
{
    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    if (!dl)
        return;

    for (int i = 0; i < kMaxParticles; ++i)
    {
        const Particle& p = m_particles[i];
        if (p.life <= 0.0f)
            continue;

        float sx, sy;
        if (!WorldToScreen(p.x, p.y, p.z, camX, camY, camZ,
                           yaw, pitch, vpW, vpH, sx, sy))
            continue;

        // Fade alpha based on remaining life.
        const float alpha = std::clamp(p.life / p.maxLife, 0.0f, 1.0f) * 0.55f;
        const ImU32 col = IM_COL32(
            static_cast<int>(p.r * 255),
            static_cast<int>(p.g * 255),
            static_cast<int>(p.b * 255),
            static_cast<int>(alpha * 255));

        dl->AddCircleFilled(ImVec2(sx, sy), p.size, col);
    }
}

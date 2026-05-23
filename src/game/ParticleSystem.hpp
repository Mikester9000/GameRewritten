// ============================================================
// FILE: src/game/ParticleSystem.hpp
// SYSTEM: Game
// ROLE: gameplay systems, actors, combat, and runtime state
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: ParticleSystem module behavior and local implementation details.
// ============================================================

#pragma once
// ParticleSystem.hpp
// GT610-safe ambient particle system (dust motes, leaves, fireflies).
// Maintains a small fixed-size pool of CPU particles and draws them as
// ImGui background-layer dots — zero extra GPU draw calls.
//
// Usage:
//   ParticleSystem particles;
//   particles.Init(playerX, playerZ);
//   // each frame:
//   particles.Update(dt, windStrength, playerX, playerY, playerZ);
//   particles.Draw(camX, camY, camZ, yaw, pitch, vpW, vpH);

struct ImGuiIO; // forward declaration (included by Main via imgui.h)

class ParticleSystem
{
public:
    static constexpr int kMaxParticles = 48;

    ParticleSystem();

    // Seed initial positions centred on worldX/worldZ.
    void Init(float worldX, float worldZ);

    // Advance all particles; re-spawn dead ones near the player.
    // windStrength [0,1] biases particle drift direction.
    void Update(float dt, float windStrength,
                float playerX, float playerY, float playerZ);

    // Project particles to screen and draw as small ImGui dots.
    // vpW/vpH are the render viewport dimensions (not window DPI-adjusted).
    void Draw(float camX, float camY, float camZ,
              float yaw, float pitch,
              float vpW, float vpH) const;

private:
    struct Particle
    {
        float x, y, z;
        float vx, vy, vz;
        float life;     // seconds remaining
        float maxLife;
        float r, g, b;
        float size;     // screen-space radius in pixels
    };

    Particle m_particles[kMaxParticles];
    int      m_count      = 0;
    float    m_spawnTimer = 0.0f;

    void SpawnOne(float centreX, float centreY, float centreZ, float windStrength);
};

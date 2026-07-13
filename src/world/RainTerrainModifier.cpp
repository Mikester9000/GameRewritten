// ============================================================
// FILE: src/world/RainTerrainModifier.cpp
// SYSTEM: World / Weather
// ROLE: Implements RainTerrainModifier — runtime terrain modification
//   driven by weather rain intensity.
//
// FOR QWEN: Implement each TODO in order.
//   1. Initialize() — set state from biome and terrain bounds
//   2. Update()     — smooth wetness transitions with lag
//   3. GetFrictionMultiplier() — biome-aware slip calculation
//   4. GetSurfaceShineBoost()  — wetness → specular multiplier
//   5. GeneratePuddles()       — grid-jitter puddle placement
//   6. GetBiomeSlipFactor()    — biome lookup table
// ============================================================

#include "RainTerrainModifier.hpp"
#include <cmath>
#include <algorithm>

// ============================================================
// CONSTANTS
// ============================================================

// Wetness blend speeds (per second)
static constexpr float kWetUpSpeed   = 0.4f;  // How fast terrain gets wet (rain starts)
static constexpr float kDryOutSpeed  = 0.04f; // How slow terrain dries (hours of real dryout)

// Friction range
static constexpr float kMinFriction  = 0.45f; // Worst case (storm + muddy biome)
static constexpr float kMaxFriction  = 1.0f;  // Completely dry

// Puddle visibility threshold
static constexpr float kPuddleThreshold = 0.30f; // Wetness must exceed this to show puddles

// Number of puddles to generate per terrain cell
static constexpr int kMaxPuddles = 8;


// ============================================================
// CONSTRUCTOR
// ============================================================
RainTerrainModifier::RainTerrainModifier()
{
    m_puddles.reserve(kMaxPuddles);
}


// ============================================================
// Initialize
// ============================================================
void RainTerrainModifier::Initialize(const std::string& biome,
                                      float terrainOriginX, float terrainOriginZ,
                                      float terrainSizeX,   float terrainSizeZ)
{
    m_biome          = biome;
    m_terrainOriginX = terrainOriginX;
    m_terrainOriginZ = terrainOriginZ;
    m_terrainSizeX   = terrainSizeX;
    m_terrainSizeZ   = terrainSizeZ;
    m_wetnessLevel   = 0.0f;
    m_frictionDelay  = 0.0f;
    m_biomeSlipFactor = GetBiomeSlipFactor(biome);
    m_puddles.clear();
}


// ============================================================
// Update
// Advances the wetness simulation one frame.
//
// TODO (Qwen): Implement smooth transitions:
//   - If rainIntensity > m_wetnessLevel: blend up at kWetUpSpeed.
//   - If rainIntensity < m_wetnessLevel: blend down at kDryOutSpeed.
//   - m_frictionDelay: separate lag for friction (ground stays slippery
//     for a while after rain stops; wetness is the visual, friction lags it).
//   - Regenerate puddles when wetness crosses kPuddleThreshold.
// ============================================================
void RainTerrainModifier::Update(float rainIntensity, float dt)
{
    // TODO (Qwen): Replace stub with smooth lerp-based transitions.
    // Wet-up path (fast): if rainIntensity > m_wetnessLevel
    //   m_wetnessLevel = std::min(m_wetnessLevel + kWetUpSpeed * dt, rainIntensity);
    // Dry-out path (slow): else
    //   m_wetnessLevel = std::max(m_wetnessLevel - kDryOutSpeed * dt, rainIntensity);
    // m_wetnessLevel = std::clamp(m_wetnessLevel, 0.0f, 1.0f);

    // STUB: direct assignment (no smoothing)
    m_wetnessLevel = std::clamp(rainIntensity, 0.0f, 1.0f);

    // Update puddles based on current wetness
    if (m_wetnessLevel > kPuddleThreshold)
        GeneratePuddles(m_wetnessLevel);
    else
        m_puddles.clear();

    (void)dt; // suppress warning until lerp is implemented
}


// ============================================================
// GetFrictionMultiplier
// Returns terrain friction [kMinFriction, kMaxFriction].
//
// TODO (Qwen): Implement biome-aware slip:
//   float slip = m_wetnessLevel * 0.5f * m_biomeSlipFactor;
//   return std::clamp(kMaxFriction - slip, kMinFriction, kMaxFriction);
// ============================================================
float RainTerrainModifier::GetFrictionMultiplier() const
{
    // STUB: linear reduction with wetness
    float slip = m_wetnessLevel * 0.5f * m_biomeSlipFactor;
    return std::clamp(kMaxFriction - slip, kMinFriction, kMaxFriction);
}


// ============================================================
// GetSurfaceShineBoost
// Returns specular multiplier for wet terrain: 1.0 → 3.0.
//
// TODO (Qwen): Implement lerp from 1.0 to 3.0 based on wetness:
//   return 1.0f + (m_wetnessLevel * 2.0f);
// ============================================================
float RainTerrainModifier::GetSurfaceShineBoost() const
{
    return 1.0f + (m_wetnessLevel * 2.0f);
}


// ============================================================
// SetBiome
// Updates biome-dependent parameters when the player changes biomes.
// ============================================================
void RainTerrainModifier::SetBiome(const std::string& biome)
{
    m_biome = biome;
    m_biomeSlipFactor = GetBiomeSlipFactor(biome);
    // Regenerate puddle positions for new terrain
    m_puddles.clear();
    if (m_wetnessLevel > kPuddleThreshold)
        GeneratePuddles(m_wetnessLevel);
}


// ============================================================
// GeneratePuddles
// Places kMaxPuddles puddles at grid-jittered positions in the terrain.
// Puddle positions are deterministic per terrain origin (same every rain).
// Puddle radius scales linearly with rain intensity.
//
// TODO (Qwen): Improve placement to prefer low terrain areas.
//   Use TerrainManager::SampleTerrainHeight() to find depressions.
//   For now: distribute uniformly across terrain with jitter.
// ============================================================
void RainTerrainModifier::GeneratePuddles(float intensity)
{
    if (m_puddles.size() == (size_t)kMaxPuddles) {
        // Just update radii on existing puddles
        float targetRadius = 3.0f * intensity;
        for (auto& p : m_puddles)
            p.radius = std::min(p.radius + 0.5f, targetRadius);
        return;
    }

    m_puddles.clear();
    m_puddles.reserve(kMaxPuddles);

    // TODO (Qwen): Use seeded deterministic positions (based on terrain origin hash)
    // For now: regular grid jittered by a simple pseudo-random offset.
    const float gridStep = m_terrainSizeX / (float)(kMaxPuddles / 2);
    int idx = 0;
    for (int gz = 0; gz < 2 && idx < kMaxPuddles; ++gz)
    {
        for (int gx = 0; gx < kMaxPuddles / 2 && idx < kMaxPuddles; ++gx, ++idx)
        {
            // Jitter: simple deterministic offset from grid coord
            float jx = ((gx * 7 + gz * 3) % 10) * (gridStep * 0.08f);
            float jz = ((gz * 11 + gx * 5) % 10) * (gridStep * 0.08f);

            PuddleParams p{};
            p.worldX    = m_terrainOriginX + gx * gridStep + gridStep * 0.3f + jx;
            p.worldZ    = m_terrainOriginZ + gz * (m_terrainSizeZ * 0.5f) + jz;
            p.maxRadius = 3.0f;
            p.radius    = p.maxRadius * intensity;
            m_puddles.push_back(p);
        }
    }
}


// ============================================================
// GetBiomeSlipFactor (static)
// Returns how slippery this biome becomes when wet.
//
// Grassland: very muddy (1.0)
// Sand/Desert: slightly sticky (0.8) — wet sand has grip
// Rocky: less slippery than mud (0.35)
// Snow: handled by SnowTerrainModifier, not here (0.0 rain in snow)
//
// TODO (Qwen): Add more biome types as the world expands.
// ============================================================
float RainTerrainModifier::GetBiomeSlipFactor(const std::string& biome)
{
    if (biome == "grassland") return 1.0f;
    if (biome == "desert")    return 0.8f;
    if (biome == "rocky")     return 0.35f;
    if (biome == "snow")      return 0.0f; // Snow biome uses SnowTerrainModifier
    return 0.6f; // Default for unknown biomes
}

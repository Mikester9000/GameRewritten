// ============================================================
// FILE: src/world/RainTerrainModifier.hpp
// SYSTEM: World / Weather
// ROLE: Applies runtime terrain appearance modifications when it is raining.
//   Drives visual and gameplay effects caused by rain:
//     1. Wet surface shader params (shininess, color darkening) → ground_ps.hlsl
//     2. Puddle texture blending → ground_ps.hlsl wetness factor
//     3. Gameplay terrain modifier: slippery ground (reduce player traction)
//     4. Mud: slow player movement in low terrain (future enhancement)
//
// INTEGRATION POINTS:
//   - WeatherSystem::GetRainIntensity() drives the wet factor [0,1].
//   - D3D11Renderer::SetWetnessFactor() passes wetness to the ground shader.
//   - CharacterController reads GetFrictionMultiplier() to adjust movement.
//   - WaterRenderer::Rebuild() uses puddle data to add small water patches.
//
// RAIN INTENSITY LEVELS (WeatherState):
//   Clear  = 0.0 wet factor → no effect
//   Cloudy = 0.0 wet factor → no effect
//   Rain   = 0.5–0.7 wet factor → moderate wet surface, minor friction loss
//   Storm  = 0.9–1.0 wet factor → very wet, significant friction loss, puddles
//
// WETNESS SHADER FACTOR:
//   Pass to ground_ps.hlsl via a new cbuffer member 'wetnessAmount'.
//   In ground_ps: wet surfaces have higher specular + darker/more saturated base color.
//   Formula: wetColor = lerp(dryColor, dryColor * 0.7, wetnessAmount)
//                     (wet darkens the base ~30% at full wetness)
//            wetSpec  = lerp(drySpec, drySpec * 3.0, wetnessAmount)
//                     (wet is 3× shinier at full wetness)
//
// TODO (Qwen): Implement Update(), GetWetnessFactor(), GetFrictionMultiplier()
// ============================================================

#pragma once
#include <string>

class WeatherSystem; // Forward declare — include WeatherSystem.hpp in .cpp

// ============================================================
// PuddleParams
// Describes a dynamic puddle placed in the terrain during rain.
// Puddles appear in low areas and grow/shrink with rain intensity.
// ============================================================
struct PuddleParams
{
    float worldX = 0.0f;
    float worldZ = 0.0f;
    float radius = 1.5f; // Current puddle radius in world units
    float maxRadius = 3.0f; // Maximum radius at full storm intensity
};


// ============================================================
// RainTerrainModifier
// Updated each frame by the main game loop.
// ============================================================
class RainTerrainModifier
{
public:
    RainTerrainModifier();
    ~RainTerrainModifier() = default;

    // --------------------------------------------------------
    // Initialize
    // Call once at startup. Does not allocate GPU resources —
    // all modifications are passed to other systems via getters.
    //   biome: current biome ("grassland", "desert", etc.) for puddle placement.
    //   terrainOriginX/Z: world origin of terrain for puddle positioning.
    //   terrainSizeX/Z: terrain dimensions for puddle coordinate clamping.
    // --------------------------------------------------------
    void Initialize(const std::string& biome,
                    float terrainOriginX, float terrainOriginZ,
                    float terrainSizeX,   float terrainSizeZ);

    // --------------------------------------------------------
    // Update
    // Call every frame with current rain intensity.
    //   rainIntensity: WeatherSystem::GetRainIntensity() [0,1]
    //   dt: frame delta time in seconds
    //
    // Internal logic:
    //   - Smoothly blend m_wetnessLevel toward rainIntensity using lerp.
    //     Wet-up is fast (rain starts): blend speed 0.3 * dt
    //     Dry-out is slow (rain stops): blend speed 0.05 * dt
    //   - Update puddle radius: lerp toward maxRadius * rainIntensity.
    //   - Friction follows wetness with a lag (ground stays slippery briefly after rain).
    //
    // TODO (Qwen): Implement smooth wet/dry transitions with different speeds.
    // --------------------------------------------------------
    void Update(float rainIntensity, float dt);

    // --------------------------------------------------------
    // GetWetnessFactor
    // Returns current terrain wetness [0,1] for the ground shader.
    // 0 = dry, 1 = fully saturated (storm-level rain).
    // Pass to ground_ps.hlsl as 'wetnessAmount' in a new cbuffer entry.
    // --------------------------------------------------------
    float GetWetnessFactor() const { return m_wetnessLevel; }

    // --------------------------------------------------------
    // GetFrictionMultiplier
    // Returns a movement friction multiplier for the character controller.
    // 1.0 = normal traction, 0.7 = slightly slippery (rain),
    // 0.5 = very slippery (storm — mud/puddles).
    //
    // Formula: 1.0 - (wetnessLevel * 0.5 * biomeSlipFactor)
    //   biomeSlipFactor: 1.0 for grassland (muddy), 0.3 for rocky (less slippery).
    //
    // TODO (Qwen): Implement with biome-aware slip factor.
    // --------------------------------------------------------
    float GetFrictionMultiplier() const;

    // --------------------------------------------------------
    // GetPuddles
    // Returns current active puddles for WaterRenderer to draw as small water patches.
    // Only returns puddles when wetness > 0.3 (visible threshold).
    // --------------------------------------------------------
    const std::vector<PuddleParams>& GetPuddles() const { return m_puddles; }

    // --------------------------------------------------------
    // GetSurfaceShineBoost
    // Multiplier for ground_ps specular contribution.
    // Used by D3D11Renderer to scale terrain shininess on wet surfaces.
    // Range: 1.0 (dry) → 3.0 (fully wet).
    // --------------------------------------------------------
    float GetSurfaceShineBoost() const;

    // --------------------------------------------------------
    // SetBiome
    // Updates biome-dependent slip/puddle parameters.
    // Call when the player crosses into a new biome cell.
    // --------------------------------------------------------
    void SetBiome(const std::string& biome);

private:
    // State
    float       m_wetnessLevel   = 0.0f;  // Current terrain wetness [0,1]
    float       m_frictionDelay  = 0.0f;  // Lag timer — ground stays wet after rain stops
    std::string m_biome          = "grassland";
    float       m_biomeSlipFactor = 1.0f; // Multiplier for how slippery this biome gets

    // Terrain bounds (for puddle coordinate generation)
    float m_terrainOriginX = 0.0f;
    float m_terrainOriginZ = 0.0f;
    float m_terrainSizeX   = 400.0f;
    float m_terrainSizeZ   = 400.0f;

    // Active puddles (updated based on wetness level)
    std::vector<PuddleParams> m_puddles;

    // --------------------------------------------------------
    // GeneratePuddles
    // Places puddles at fixed positions within the terrain.
    // Positions are seeded from terrain origin for determinism.
    // TODO (Qwen): Implement using simple grid-jittered positions in low terrain areas.
    // --------------------------------------------------------
    void GeneratePuddles(float intensity);

    // --------------------------------------------------------
    // GetBiomeSlipFactor
    // Maps biome name to a slip coefficient.
    // grassland=1.0, sand=0.8, rocky=0.3, snow=0.9 (ice is handled separately)
    // TODO (Qwen): implement lookup table.
    // --------------------------------------------------------
    static float GetBiomeSlipFactor(const std::string& biome);
};

// Required for GetPuddles() — include <vector> here
#include <vector>

#pragma once

#include <vector>

struct ContinentImpostor
{
    float centerX = 0.0f;
    float centerZ = 0.0f;
    float visibleDistance = 3000.0f;
    float fadeDistance = 500.0f;
};

class ContinentImpostorSystem
{
public:
    void SetImpostors(const std::vector<ContinentImpostor>& impostors);
    std::vector<float> ComputeVisibility(float playerX, float playerZ) const;

private:
    std::vector<ContinentImpostor> m_impostors;
};

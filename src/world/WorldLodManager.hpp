#pragma once

class WorldLodManager
{
public:
    enum class Tier
    {
        Near,
        Mid,
        Far,
        Impostor
    };

    void SetDistanceScale(float distanceScale);
    Tier ResolveTier(float distanceFromCamera) const;
    float GetDistanceScale() const { return m_distanceScale; }

private:
    float m_distanceScale = 1.0f;
};

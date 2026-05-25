#include "PostProcessToggles.hpp"

void PostProcessToggles::SetAll(bool enabled)
{
    motionBlur = enabled;
    chromaticAberration = enabled;
    filmGrain = enabled;
    depthOfField = enabled;
}

bool PostProcessToggles::AnyEnabled() const
{
    return motionBlur || chromaticAberration || filmGrain || depthOfField;
}

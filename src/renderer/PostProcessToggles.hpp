#pragma once

class PostProcessToggles
{
public:
    bool motionBlur = true;
    bool chromaticAberration = true;
    bool filmGrain = true;
    bool depthOfField = true;

    void SetAll(bool enabled);
    bool AnyEnabled() const;
};

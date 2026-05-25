#pragma once

class StreamingBudget
{
public:
    void SetBudgets(float cpuMs, float gpuMs, float ioMbPerSec)
    {
        m_cpuMs = (cpuMs > 0.0f) ? cpuMs : m_cpuMs;
        m_gpuMs = (gpuMs > 0.0f) ? gpuMs : m_gpuMs;
        m_ioMbPerSec = (ioMbPerSec > 0.0f) ? ioMbPerSec : m_ioMbPerSec;
    }

    float EvaluatePressure(float cpuMsUsed, float gpuMsUsed, float ioMbPerSecUsed) const
    {
        const float cpu = cpuMsUsed / m_cpuMs;
        const float gpu = gpuMsUsed / m_gpuMs;
        const float io = ioMbPerSecUsed / m_ioMbPerSec;
        const float peak = (cpu > gpu) ? cpu : gpu;
        return (peak > io) ? peak : io;
    }

private:
    float m_cpuMs = 4.0f;
    float m_gpuMs = 4.0f;
    float m_ioMbPerSec = 32.0f;
};

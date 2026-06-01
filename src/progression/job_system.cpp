#include "job_system.h"

namespace gr
{
void JobSystem::SetJobs(const std::vector<JobDefinition>& jobs)
{
    m_jobs.clear();
    m_activeJobId.clear();
    for (const JobDefinition& job : jobs)
    {
        if (!job.jobId.empty())
        {
            m_jobs[job.jobId] = job;
        }
    }
}

bool JobSystem::UnlockJob(const std::string& jobId)
{
    auto it = m_jobs.find(jobId);
    if (it == m_jobs.end())
    {
        return false;
    }
    it->second.unlocked = true;
    if (m_activeJobId.empty())
    {
        m_activeJobId = jobId;
    }
    return true;
}

bool JobSystem::SetActiveJob(const std::string& jobId)
{
    auto it = m_jobs.find(jobId);
    if (it == m_jobs.end() || !it->second.unlocked)
    {
        return false;
    }
    m_activeJobId = jobId;
    return true;
}

std::vector<std::string> JobSystem::GetActiveBonuses() const
{
    auto it = m_jobs.find(m_activeJobId);
    if (it == m_jobs.end())
    {
        return {};
    }
    return it->second.passiveBonuses;
}
} // namespace gr

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace gr
{
struct JobDefinition
{
    std::string jobId;
    std::string displayName;
    std::vector<std::string> passiveBonuses;
    bool unlocked = false;
};

class JobSystem
{
public:
    void SetJobs(const std::vector<JobDefinition>& jobs);
    bool UnlockJob(const std::string& jobId);
    bool SetActiveJob(const std::string& jobId);
    std::string GetActiveJob() const { return m_activeJobId; }
    std::vector<std::string> GetActiveBonuses() const;

private:
    std::unordered_map<std::string, JobDefinition> m_jobs;
    std::string m_activeJobId;
};
} // namespace gr

// ============================================================
// FILE: src/progression/job_system.h
// SYSTEM: Progression
// ROLE: FF-style job class system — unlock and switch between jobs
// DO NOT: store ability data here; use AbilityProgression for that.
// OWNS: job definitions, unlock state, and active job selection.
// ============================================================
//
// [LEGO BLOCK: JOB SYSTEM]
// -----------------------------------------------------------------
// What it does: manages a set of job classes (Fighter, Mage, etc.)
//   that the player can unlock and switch between. The active job
//   provides passiveBonuses that the stat system reads each frame.
//
// EXTEND: add new jobs by appending JobDefinition entries to the
//   JSON data file and calling SetJobs() — no code changes here.
//   Add a "level" field to JobDefinition for per-job XP tracking.
//
// EXAMPLE — switch jobs from a menu:
//   #include "progression/job_system.h"
//   gr::JobSystem m_jobSystem;
//   m_jobSystem.SetJobs(loadedJobs);
//   m_jobSystem.UnlockJob("black_mage");
//   m_jobSystem.SetActiveJob("black_mage");
//   for (auto& bonus : m_jobSystem.GetActiveBonuses())
//       stats.ApplyBonus(bonus);
// -----------------------------------------------------------------

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

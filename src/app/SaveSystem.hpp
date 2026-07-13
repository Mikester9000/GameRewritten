#pragma once
// SaveSystem.hpp
// Minimal save/load for player stats, quest flags, and discovered landmarks.
// Writes a plain binary file; no external dependencies required.

#include <string>

struct PlayerStats;
class  QuestFlags;
class  LandmarkTriggerSystem;

class SaveSystem
{
public:
    static constexpr int kSaveVersion = 1;

    // Returns the platform save path (e.g. %APPDATA%\GameRewritten\save.bin).
    static std::string GetSavePath();

    // Persist current world state; returns false on IO error.
    bool Save(const PlayerStats& stats,
              const QuestFlags&  flags,
              const LandmarkTriggerSystem& landmarks);

    // Restore world state from disk; returns false if no save or version
    // mismatch (caller should start a fresh game).
    bool Load(PlayerStats&         stats,
              QuestFlags&          flags,
              LandmarkTriggerSystem& landmarks);

    // True after at least one successful Save() or Load() this session.
    bool HasSave() const { return m_hasSave; }

private:
    bool m_hasSave = false;
};

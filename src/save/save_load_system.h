// ============================================================
// FILE: src/save/save_load_system.h
// SYSTEM: Save
// ROLE: JSON-based save/load for player progress
// DO NOT: store game state here; operate on plain data in/out params.
// OWNS: file I/O and JSON serialization/deserialization.
// ============================================================
//
// [LEGO BLOCK: SAVE / LOAD SYSTEM]
// -----------------------------------------------------------------
// What it does: writes player progress to a JSON file and reads
//   it back. Version-checked to catch incompatible save formats.
//   Currently saves: player name, level, gil.
//
// EXTEND: add new data to the save by adding parameters to Save()
//   and Load(), then updating the JSON payload in the .cpp.
//   To add world-state (cleared zones, discovered cells) pass in
//   a data struct and serialize its fields alongside player data.
//
// EXAMPLE — save on rest-point heal:
//   #include "save/save_load_system.h"
//   gr::SaveLoadSystem m_saveSystem;
//   auto result = m_saveSystem.Save("save0.json", player.name, player.level, player.gil);
//   if (!result.ok) LOG_WARN("Save failed: " + result.message);
// -----------------------------------------------------------------

#pragma once

#include <string>

namespace gr
{
struct SaveLoadResult
{
    bool ok = false;
    std::string message;
};

class SaveLoadSystem
{
public:
    SaveLoadResult Save(const std::string& filePath, const std::string& playerName,
                        int playerLevel, int gil, int saveVersion = 1) const;
    SaveLoadResult Load(const std::string& filePath, std::string& outPlayerName,
                        int& outPlayerLevel, int& outGil, int expectedVersion = 1) const;
};
} // namespace gr

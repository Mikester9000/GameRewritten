#include "save_load_system.h"

#include "../../third_party/nlohmann/json.hpp"

#include <fstream>

namespace gr
{
SaveLoadResult SaveLoadSystem::Save(const std::string& filePath, const std::string& playerName,
                                    int playerLevel, int gil, int saveVersion) const
{
    nlohmann::json payload;
    payload["version"] = saveVersion;
    payload["player"]["name"] = playerName;
    payload["player"]["level"] = playerLevel;
    payload["player"]["gil"] = gil;

    std::ofstream out(filePath, std::ios::trunc);
    if (!out)
    {
        return { false, "Failed to open save file for writing." };
    }

    out << payload.dump(2);
    if (!out.good())
    {
        return { false, "Failed to write save data." };
    }
    return { true, "Save completed." };
}

SaveLoadResult SaveLoadSystem::Load(const std::string& filePath, std::string& outPlayerName,
                                    int& outPlayerLevel, int& outGil, int expectedVersion) const
{
    std::ifstream in(filePath);
    if (!in)
    {
        return { false, "Failed to open save file." };
    }

    nlohmann::json payload;
    try
    {
        in >> payload;
    }
    catch (...)
    {
        return { false, "Save file is corrupted." };
    }

    if (!payload.is_object())
    {
        return { false, "Save file is corrupted." };
    }

    const auto playerIt = payload.find("player");
    if (playerIt == payload.end() || !playerIt->is_object())
    {
        return { false, "Save file is corrupted." };
    }

    int fileVersion = -1;
    std::string loadedPlayerName;
    int loadedPlayerLevel = 1;
    int loadedGil = 0;
    try
    {
        fileVersion = payload.value("version", -1);
        loadedPlayerName = playerIt->value("name", std::string());
        loadedPlayerLevel = playerIt->value("level", 1);
        loadedGil = playerIt->value("gil", 0);
    }
    catch (...)
    {
        return { false, "Save file is corrupted." };
    }

    if (fileVersion != expectedVersion)
    {
        return { false, "Unsupported save version." };
    }

    outPlayerName = loadedPlayerName;
    outPlayerLevel = loadedPlayerLevel;
    outGil = loadedGil;
    return { true, "Load completed." };
}
} // namespace gr

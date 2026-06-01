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

    const int fileVersion = payload.value("version", -1);
    if (fileVersion != expectedVersion)
    {
        return { false, "Unsupported save version." };
    }

    outPlayerName = payload["player"].value("name", std::string());
    outPlayerLevel = payload["player"].value("level", 1);
    outGil = payload["player"].value("gil", 0);
    return { true, "Load completed." };
}
} // namespace gr

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

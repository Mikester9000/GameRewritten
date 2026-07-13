// SaveSystem.cpp
// Binary save/load for player stats, quest flags, and landmark discovery.

#include "SaveSystem.hpp"

#include "../game/actors/PlayerStats.hpp"
#include "../game/quest/QuestFlags.hpp"
#include "../game/world/LandmarkTrigger.hpp"

#include <cstdio>
#include <cstring>
#include <filesystem>
#include <system_error>
#include <utility>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#endif

std::string SaveSystem::GetSavePath()
{
#ifdef _WIN32
    char path[MAX_PATH] = {};
    if (SUCCEEDED(SHGetFolderPathA(nullptr, CSIDL_APPDATA, nullptr, 0, path)))
        return std::string(path) + "\\GameRewritten\\save.bin";
#endif
    return "save.bin";
}

namespace
{
struct SaveHeader { int version = 0; int flagCount = 0; int landmarkCount = 0; };

void WriteStr(FILE* f, const std::string& s)
{
    int len = static_cast<int>(s.size());
    fwrite(&len, sizeof(int), 1, f);
    fwrite(s.data(), 1, len, f);
}

bool ReadStr(FILE* f, std::string& out)
{
    int len = 0;
    if (fread(&len, sizeof(int), 1, f) != 1 || len < 0 || len > 4096) return false;
    out.resize(len);
    return fread(out.data(), 1, len, f) == static_cast<size_t>(len);
}
} // namespace

bool SaveSystem::Save(const PlayerStats& stats,
                      const QuestFlags& flags,
                      const LandmarkTriggerSystem& landmarks)
{
    const std::string savePath = GetSavePath();
#ifdef _WIN32
    std::error_code ec;
    std::filesystem::create_directories(std::filesystem::path(savePath).parent_path(), ec);
#endif
    FILE* f = nullptr;
    if (fopen_s(&f, savePath.c_str(), "wb") != 0 || !f) return false;

    const auto& allFlags     = flags.GetAll();
    const auto& allLandmarks = landmarks.GetAll();

    SaveHeader hdr;
    hdr.version       = kSaveVersion;
    hdr.flagCount     = static_cast<int>(allFlags.size());
    hdr.landmarkCount = static_cast<int>(allLandmarks.size());
    fwrite(&hdr,   sizeof(hdr),   1, f);
    fwrite(&stats, sizeof(stats), 1, f);

    for (const auto& [key, val] : allFlags)
    {
        WriteStr(f, key);
        fwrite(&val, sizeof(bool), 1, f);
    }
    for (const auto& lm : allLandmarks)
    {
        WriteStr(f, lm.name);
        fwrite(&lm.discovered, sizeof(bool), 1, f);
    }

    fclose(f);
    m_hasSave = true;
    return true;
}

bool SaveSystem::Load(PlayerStats& stats,
                      QuestFlags& flags,
                      LandmarkTriggerSystem& landmarks)
{
    FILE* f = nullptr;
    if (fopen_s(&f, GetSavePath().c_str(), "rb") != 0 || !f) return false;

    SaveHeader hdr{};
    if (fread(&hdr, sizeof(hdr), 1, f) != 1 || hdr.version != kSaveVersion)
        { fclose(f); return false; }

    if (fread(&stats, sizeof(stats), 1, f) != 1)
        { fclose(f); return false; }

    std::vector<std::pair<std::string, bool>> loadedFlags;
    loadedFlags.reserve(hdr.flagCount);
    for (int i = 0; i < hdr.flagCount; ++i)
    {
        std::string key; bool val = false;
        if (!ReadStr(f, key) || fread(&val, sizeof(bool), 1, f) != 1)
            { fclose(f); return false; }
        loadedFlags.emplace_back(std::move(key), val);
    }

    std::vector<std::pair<std::string, bool>> loadedLandmarks;
    loadedLandmarks.reserve(hdr.landmarkCount);
    for (int i = 0; i < hdr.landmarkCount; ++i)
    {
        std::string name; bool disc = false;
        if (!ReadStr(f, name) || fread(&disc, sizeof(bool), 1, f) != 1)
            { fclose(f); return false; }
        loadedLandmarks.emplace_back(std::move(name), disc);
    }

    fclose(f);
    flags.Clear();
    for (const auto& [key, val] : loadedFlags)
        flags.Set(key, val);

    landmarks.SetAllDiscovered(false);
    for (const auto& [name, disc] : loadedLandmarks)
        landmarks.SetDiscovered(name, disc);

    m_hasSave = true;
    return true;
}

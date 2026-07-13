// SaveSystem.cpp
// Binary save/load for player stats, quest flags, and landmark discovery.

#include "SaveSystem.hpp"

#include "../game/actors/PlayerStats.hpp"
#include "../game/quest/QuestFlags.hpp"
#include "../game/world/LandmarkTrigger.hpp"

#include <cstdio>
#include <cstring>

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
    FILE* f = fopen(GetSavePath().c_str(), "wb");
    if (!f) return false;

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
    FILE* f = fopen(GetSavePath().c_str(), "rb");
    if (!f) return false;

    SaveHeader hdr{};
    if (fread(&hdr, sizeof(hdr), 1, f) != 1 || hdr.version != kSaveVersion)
        { fclose(f); return false; }

    if (fread(&stats, sizeof(stats), 1, f) != 1)
        { fclose(f); return false; }

    flags.Clear();
    for (int i = 0; i < hdr.flagCount; ++i)
    {
        std::string key; bool val = false;
        if (!ReadStr(f, key) || fread(&val, sizeof(bool), 1, f) != 1) break;
        flags.Set(key, val);
    }

    auto& lms = const_cast<std::vector<Landmark>&>(
        const_cast<const LandmarkTriggerSystem&>(landmarks).GetAll());
    for (int i = 0; i < hdr.landmarkCount && i < static_cast<int>(lms.size()); ++i)
    {
        std::string name; bool disc = false;
        if (!ReadStr(f, name) || fread(&disc, sizeof(bool), 1, f) != 1) break;
        if (lms[i].name == name) lms[i].discovered = disc;
    }

    fclose(f);
    m_hasSave = true;
    return true;
}

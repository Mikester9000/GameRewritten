// SaveMigration.cpp
// Save file version migration stubs.

#include "SaveMigration.hpp"

#include <string>

bool SaveMigration::MigrateIfNeeded(const std::string& path, int fileVersion)
{
    if (fileVersion == 1) return true; // already current

    if (fileVersion == 0) return MigrateV0ToV1(path);

    return false; // unknown or future version — reject
}

bool SaveMigration::MigrateV0ToV1(const std::string& /*path*/)
{
    // V0 had no stats block; V1 adds PlayerStats.
    // For now: silently discard V0 save and start fresh.
    return false;
}

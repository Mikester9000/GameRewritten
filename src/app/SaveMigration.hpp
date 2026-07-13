#pragma once
// SaveMigration.hpp
// Forward-migrates old save files to the current save version.
// Each version bump has a registered migration step.

#include <string>

class SaveSystem; // forward

class SaveMigration
{
public:
    // Returns the highest savefile version this code can migrate from.
    static int MaxSupportedVersion() { return 1; }

    // Attempt to migrate data in path to kSaveVersion.
    // Returns true if the file was migrated successfully or is already current.
    // Returns false if the version is too old to migrate (prompt new game).
    static bool MigrateIfNeeded(const std::string& path, int fileVersion);

private:
    // Per-version migration steps:
    static bool MigrateV0ToV1(const std::string& path);
};

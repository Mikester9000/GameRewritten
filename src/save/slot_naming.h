// ============================================================
// FILE: src/save/slot_naming.h
// SYSTEM: Save
// ROLE: sanitize user-entered save slot names
// DO NOT: perform file I/O or UI rendering here.
// OWNS: name sanitization logic only.
// ============================================================
//
// [LEGO BLOCK: SAVE SLOT NAMING]
// -----------------------------------------------------------------
// What it does: strips unsafe characters from a player-entered
//   save slot name so it is safe to use as a file name component.
//   Keeps: alphanumeric, space, dash, underscore. Trims trailing
//   spaces. Falls back to "Save Slot" if the result is empty.
//
// EXTEND: add a max-length parameter override to the header if
//   different UIs have different display constraints.
//
// EXAMPLE — validate a slot name before saving:
//   #include "save/slot_naming.h"
//   std::string safe = gr::SaveSlotNaming::Sanitize(userInput, 24);
//   saveSystem.Save(safe + ".json", ...);
// -----------------------------------------------------------------

#pragma once

#include <cstddef>
#include <string>

namespace gr
{
class SaveSlotNaming
{
public:
    static std::string Sanitize(const std::string& rawName, std::size_t maxLength = 24);
};
} // namespace gr

// ============================================================
// FILE: src/materia/summon_collection.h
// SYSTEM: Materia
// ROLE: tracks which summon entities the player has obtained
// DO NOT: store summon stats or animations here; use AssetRegistry.
// OWNS: discovered summon set.
// ============================================================
//
// [LEGO BLOCK: SUMMON COLLECTION]
// -----------------------------------------------------------------
// What it does: remembers which summon IDs the player has found
//   (e.g. "ifrit", "shiva", "bahamut"). Query HasSummon() before
//   allowing a summon command in the tactical pause menu.
//
// EXTEND: add summon level or affinity score by changing the
//   discovered set to a map<string, SummonData>.
//
// EXAMPLE — unlock a summon after a boss kill:
//   #include "materia/summon_collection.h"
//   gr::SummonCollection m_summons;
//   m_summons.Discover("ifrit");
//   if (m_summons.HasSummon("ifrit"))
//       tacticalMenu.ShowSummonCommand("Ifrit");
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_set>
#include <vector>

namespace gr
{
class SummonCollection
{
public:
    bool Discover(const std::string& summonId);
    bool HasSummon(const std::string& summonId) const;
    std::vector<std::string> GetAll() const;

private:
    std::unordered_set<std::string> m_discovered;
};
} // namespace gr

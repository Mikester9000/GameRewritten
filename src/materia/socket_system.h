// ============================================================
// FILE: src/materia/socket_system.h
// SYSTEM: Materia
// ROLE: FF7-style socket/gem attachment per equipment piece
// DO NOT: compute stat bonuses here; let the caller read the gem IDs.
// OWNS: socket layout and gem assignment state.
// ============================================================
//
// [LEGO BLOCK: MATERIA SOCKET SYSTEM]
// -----------------------------------------------------------------
// What it does: each piece of equipment can have N sockets. Gems
//   (materia orbs) can be attached/detached from sockets by index.
//   The caller reads gem IDs and resolves their stats separately.
//
// EXTEND: add socket "types" (e.g. red/blue/green materia) by
//   extending SocketEntry with a socketType field and enforcing
//   color-matching in AttachGem().
//
// EXAMPLE — equip a materia orb:
//   #include "materia/socket_system.h"
//   gr::MateriaSocketSystem m_sockets;
//   m_sockets.DefineSockets("buster_sword", 2);
//   m_sockets.AttachGem("buster_sword", 0, "fire_lv2");
//   std::string gem = m_sockets.GetGem("buster_sword", 0); // "fire_lv2"
// -----------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace gr
{
struct SocketEntry
{
    std::string gemId;
};

class MateriaSocketSystem
{
public:
    void DefineSockets(const std::string& equipmentId, int socketCount);
    int GetSocketCount(const std::string& equipmentId) const;
    bool AttachGem(const std::string& equipmentId, int socketIndex, const std::string& gemId);
    bool DetachGem(const std::string& equipmentId, int socketIndex);
    std::string GetGem(const std::string& equipmentId, int socketIndex) const;

private:
    std::unordered_map<std::string, std::vector<SocketEntry>> m_sockets;
};
} // namespace gr

#include "socket_system.h"

#include <algorithm>

namespace gr
{
void MateriaSocketSystem::DefineSockets(const std::string& equipmentId, int socketCount)
{
    if (equipmentId.empty())
    {
        return;
    }
    m_sockets[equipmentId] = std::vector<SocketEntry>(static_cast<std::size_t>(std::max(socketCount, 0)));
}

int MateriaSocketSystem::GetSocketCount(const std::string& equipmentId) const
{
    const auto it = m_sockets.find(equipmentId);
    return it == m_sockets.end() ? 0 : static_cast<int>(it->second.size());
}

bool MateriaSocketSystem::AttachGem(const std::string& equipmentId, int socketIndex, const std::string& gemId)
{
    auto it = m_sockets.find(equipmentId);
    if (it == m_sockets.end() || socketIndex < 0 || socketIndex >= static_cast<int>(it->second.size()) || gemId.empty())
    {
        return false;
    }
    it->second[static_cast<std::size_t>(socketIndex)].gemId = gemId;
    return true;
}

bool MateriaSocketSystem::DetachGem(const std::string& equipmentId, int socketIndex)
{
    auto it = m_sockets.find(equipmentId);
    if (it == m_sockets.end() || socketIndex < 0 || socketIndex >= static_cast<int>(it->second.size()))
    {
        return false;
    }
    it->second[static_cast<std::size_t>(socketIndex)].gemId.clear();
    return true;
}

std::string MateriaSocketSystem::GetGem(const std::string& equipmentId, int socketIndex) const
{
    const auto it = m_sockets.find(equipmentId);
    if (it == m_sockets.end() || socketIndex < 0 || socketIndex >= static_cast<int>(it->second.size()))
    {
        return {};
    }
    return it->second[static_cast<std::size_t>(socketIndex)].gemId;
}
} // namespace gr

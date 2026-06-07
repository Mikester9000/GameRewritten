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
